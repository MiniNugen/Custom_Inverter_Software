/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'Main_Firmware'.
 *
 * Model version                  : 2.40
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri Jul 25 03:10:33 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Main_Firmware.h"
#include "rtwtypes.h"
#include "xcp.h"
#include "ext_mode.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[3] = { 0, 0, 0 };

boolean_T need2runFlags[3] = { 0, 0, 0 };

void rt_OneStep(void)
{
  extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;
  boolean_T eventFlags[3];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    executeOverrunService();
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.
   */
  Main_Firmware_SetEventsForThisBaseStep(eventFlags);
  enableTimer0Interrupt();
  currentTime = (extmodeSimulationTime_T) ((Main_Firmware_M->Timing.clockTick0 *
    1) + 0)
    ;
  Main_Firmware_step0();

  /* Get model outputs here */

  /* Trigger External Mode event */
  extmodeEvent(1, currentTime);
  disableTimer0Interrupt();
  isRateRunning[0]--;
  if (eventFlags[2]) {
    if (need2runFlags[2]++) {
      IsrOverrun = 2;
      executeOverrunService();
      need2runFlags[2]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[2]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[2]++;
    enableTimer0Interrupt();

    /* Step the model for subrate "2" */
    switch (2)
    {
     case 2 :
      currentTime = (extmodeSimulationTime_T)
        ((Main_Firmware_M->Timing.clockTick2 * 100) + 0)
        ;
      Main_Firmware_step2();

      /* Get model outputs here */

      /* Trigger External Mode event */
      extmodeEvent(2, currentTime);
      break;

     default :
      break;
    }

    disableTimer0Interrupt();
    need2runFlags[2]--;
    isRateRunning[2]--;
  }
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.0001;
  float systemClock = 100;
  extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  c2000_flash_init();
  init_board();

#if defined(MW_EXEC_PROFILER_ON) || (defined(MW_EXTMODE_RUNNING) && !defined(XCP_TIMESTAMP_BASED_ON_SIMULATION_TIME))

  hardwareTimer1Init();

#endif

  ;
  rtmSetErrorStatus(Main_Firmware_M, 0);

  /* Set Final Simulation Time in Ticks */
  errorCode = extmodeSetFinalSimulationTime((extmodeSimulationTime_T) -1);

  /* Parse External Mode command line arguments */
  errorCode = extmodeParseArgs(0, NULL);
  if (errorCode != EXTMODE_SUCCESS) {
    return (errorCode);
  }

  Main_Firmware_initialize();
  globalInterruptDisable();
  globalInterruptEnable();

  /* External Mode initialization */
  errorCode = extmodeInit(Main_Firmware_M->extModeInfo, (extmodeSimulationTime_T
    *)rteiGetPtrTFinalTicks(Main_Firmware_M->extModeInfo));
  if (errorCode != EXTMODE_SUCCESS) {
    /* Code to handle External Mode initialization errors
       may be added here */
  }

  if (errorCode == EXTMODE_SUCCESS) {
    /* Wait until a Start or Stop Request has been received from the Host */
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(Main_Firmware_M, true);
    }
  }

  globalInterruptDisable();
  configureTimer0(modelBaseRate, systemClock);
  runModel =
    !extmodeSimulationComplete()&& !extmodeStopRequested()&&
    !rtmGetStopRequested(Main_Firmware_M);
  enableTimer0Interrupt();
  config_ePWM_TBSync();
  globalInterruptEnable();
  while (runModel) {
    /* Run External Mode background activities */
    errorCode = extmodeBackgroundRun();
    if (errorCode != EXTMODE_SUCCESS && errorCode != EXTMODE_EMPTY) {
      /* Code to handle External Mode background task errors
         may be added here */
    }

    stopRequested = !(
                      !extmodeSimulationComplete()&& !extmodeStopRequested()&&
                      !rtmGetStopRequested(Main_Firmware_M));
    runModel = !(stopRequested);
    if (stopRequested)
      disableTimer0Interrupt();
  }

  /* Terminate model */
  Main_Firmware_terminate();

  /* External Mode reset */
  extmodeReset();
  globalInterruptDisable();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
