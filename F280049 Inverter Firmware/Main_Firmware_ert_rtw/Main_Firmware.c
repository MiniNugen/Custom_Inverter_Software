/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware.c
 *
 * Code generated for Simulink model 'Main_Firmware'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Feb  1 13:54:01 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Main_Firmware.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include <stdlib.h>
#include <string.h>
#include "Main_Firmware_private.h"

/* Block signals (default storage) */
B_Main_Firmware_T Main_Firmware_B;

/* Block states (default storage) */
DW_Main_Firmware_T Main_Firmware_DW;

/* Real-time model */
static RT_MODEL_Main_Firmware_T Main_Firmware_M_;
RT_MODEL_Main_Firmware_T *const Main_Firmware_M = &Main_Firmware_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Main_Firmware_M->Timing.TaskCounters.TID[2])++;
  if ((Main_Firmware_M->Timing.TaskCounters.TID[2]) >
      (Main_Firmware_M->Timing.CtrlRateNumTicksToNextHit[0]*1-1)) {/* Sample time: [0.001s, -20.0s] */
    Main_Firmware_M->Timing.TaskCounters.TID[2] = 0;
  }

  (Main_Firmware_M->Timing.TaskCounters.TID[3])++;
  if ((Main_Firmware_M->Timing.TaskCounters.TID[3]) >
      (Main_Firmware_M->Timing.CtrlRateNumTicksToNextHit[1]*1-1)) {/* Sample time: [0.001s, -21.0s] */
    Main_Firmware_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/* Model step function */
void Main_Firmware_step(void)
{
  {
    real_T numTicksToNextHit_tmp;

    /* Constant: '<S1>/Constant' */
    Main_Firmware_B.Constant = Main_Firmware_P.PWM_Period;

    /* Sin: '<Root>/Sine Wave' */
    Main_Firmware_B.SineWave = sin(Main_Firmware_P.SineWave_Freq *
      Main_Firmware_M->Timing.t[0] + Main_Firmware_P.SineWave_Phase) *
      Main_Firmware_P.SineWave_Amp + Main_Firmware_P.SineWave_Bias;

    /* VariablePulseGenerator: '<S1>/Variable Pulse Generator' */
    if (Main_Firmware_M->Timing.TaskCounters.TID[2] == 0) {
      numTicksToNextHit_tmp = floor((2.8421709430404007E-14 *
        Main_Firmware_B.SineWave * Main_Firmware_B.Constant +
        Main_Firmware_B.SineWave * Main_Firmware_B.Constant) / 0.001);
      if (rtIsNaN(numTicksToNextHit_tmp) || rtIsInf(numTicksToNextHit_tmp)) {
        numTicksToNextHit_tmp = 0.0;
      } else {
        numTicksToNextHit_tmp = fmod(numTicksToNextHit_tmp, 4.294967296E+9);
      }

      if ((((numTicksToNextHit_tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
             -numTicksToNextHit_tmp : (uint32_T)numTicksToNextHit_tmp) == 0UL) ||
           (Main_Firmware_B.SineWave <= 0.0)) &&
          Main_Firmware_DW.isStartOfNextCycle) {
        /* VariablePulseGenerator: '<S1>/Variable Pulse Generator' */
        Main_Firmware_B.VariablePulseGenerator = 0.0;
        Main_Firmware_DW.nextOutput = false;
      } else {
        /* VariablePulseGenerator: '<S1>/Variable Pulse Generator' */
        Main_Firmware_B.VariablePulseGenerator = Main_Firmware_DW.nextOutput;
      }
    }

    /* End of VariablePulseGenerator: '<S1>/Variable Pulse Generator' */

    /* PropagationDelay: '<S1>/Propagation Delay' */
    if (Main_Firmware_M->Timing.TaskCounters.TID[3] == 0) {
      if (Main_Firmware_DW.Size == 0UL) {
        Main_Firmware_M->Timing.CtrlRateNumTicksToNextHit[1] = (1.0);
      } else {
        /* PropagationDelay: '<S1>/Propagation Delay' */
        Main_Firmware_B.PropagationDelay = *((real_T *)Main_Firmware_DW.YNext +
          Main_Firmware_DW.Head);
        Main_Firmware_DW.Size--;
        Main_Firmware_DW.Head = (Main_Firmware_DW.Head + 1UL) %
          Main_Firmware_DW.BufferCapacity;
        if (Main_Firmware_DW.Size == 0UL) {
          Main_Firmware_M->Timing.CtrlRateNumTicksToNextHit[1] = (1.0);
        } else {
          numTicksToNextHit_tmp = ((Main_Firmware_M->Timing.clockTick1) * 0.001);
          numTicksToNextHit_tmp = floor(((*((real_T *)Main_Firmware_DW.TNext +
            Main_Firmware_DW.Head) - numTicksToNextHit_tmp) +
            numTicksToNextHit_tmp * 2.8421709430404007E-14) / 0.001);
          if (rtIsNaN(numTicksToNextHit_tmp) || rtIsInf(numTicksToNextHit_tmp))
          {
            numTicksToNextHit_tmp = 0.0;
          } else {
            numTicksToNextHit_tmp = fmod(numTicksToNextHit_tmp, 4.294967296E+9);
          }

          Main_Firmware_M->Timing.CtrlRateNumTicksToNextHit[1] = ((real_T)
            (numTicksToNextHit_tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
             -numTicksToNextHit_tmp : (uint32_T)numTicksToNextHit_tmp));
        }
      }
    }

    /* End of PropagationDelay: '<S1>/Propagation Delay' */

    /* S-Function (c280xgpio_do): '<Root>/Digital Output' */
    {
      if (Main_Firmware_B.PropagationDelay) {
        GpioDataRegs.GPASET.bit.GPIO23 = 1U;
      } else {
        GpioDataRegs.GPACLEAR.bit.GPIO23 = 1U;
      }
    }
  }

  {
    real_T dc;
    uint32_T numTicksToNextSampleHit;
    uint32_T totalTicksInPeriod;
    void *tNextTempBuf;

    /* Update for VariablePulseGenerator: '<S1>/Variable Pulse Generator' */
    if (Main_Firmware_M->Timing.TaskCounters.TID[2] == 0) {
      if (Main_Firmware_DW.nextOutput) {
        dc = Main_Firmware_B.SineWave;
        if (Main_Firmware_B.SineWave > 1.0) {
          dc = 1.0;
        } else if (1.0 - Main_Firmware_B.SineWave < 2.8421709430404007E-14) {
          dc = 1.0;
        }

        dc = floor((2.2204460492503131E-16 * dc * Main_Firmware_B.Constant + dc *
                    Main_Firmware_B.Constant) / 0.001);
        if (rtIsNaN(dc) || rtIsInf(dc)) {
          dc = 0.0;
        } else {
          dc = fmod(dc, 4.294967296E+9);
        }

        numTicksToNextSampleHit = dc < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-dc :
          (uint32_T)dc;
        dc = floor((2.2204460492503131E-16 * Main_Firmware_B.Constant +
                    Main_Firmware_B.Constant) / 0.001);
        if (rtIsNaN(dc) || rtIsInf(dc)) {
          dc = 0.0;
        } else {
          dc = fmod(dc, 4.294967296E+9);
        }

        totalTicksInPeriod = dc < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-dc :
          (uint32_T)dc;
        if (numTicksToNextSampleHit < totalTicksInPeriod) {
          Main_Firmware_M->Timing.CtrlRateNumTicksToNextHit[0] = ((real_T)
            numTicksToNextSampleHit);
          Main_Firmware_DW.nextOutput = false;
          Main_Firmware_DW.isStartOfNextCycle = false;
        } else {
          Main_Firmware_M->Timing.CtrlRateNumTicksToNextHit[0] = ((real_T)
            totalTicksInPeriod);
          Main_Firmware_DW.nextOutput = true;
          Main_Firmware_DW.isStartOfNextCycle = true;
        }

        Main_Firmware_DW.startTimeOfNextCycle = totalTicksInPeriod -
          numTicksToNextSampleHit;
      } else {
        if (Main_Firmware_DW.isStartOfNextCycle) {
          dc = floor((2.2204460492503131E-16 * Main_Firmware_B.Constant +
                      Main_Firmware_B.Constant) / 0.001);
          if (rtIsNaN(dc) || rtIsInf(dc)) {
            dc = 0.0;
          } else {
            dc = fmod(dc, 4.294967296E+9);
          }

          Main_Firmware_M->Timing.CtrlRateNumTicksToNextHit[0] = ((real_T)(dc <
            0.0 ? (uint32_T)-(int32_T)(uint32_T)-dc : (uint32_T)dc));
        } else if (Main_Firmware_DW.startTimeOfNextCycle > 0.0) {
          Main_Firmware_M->Timing.CtrlRateNumTicksToNextHit[0] =
            (Main_Firmware_DW.startTimeOfNextCycle);
        }

        Main_Firmware_DW.nextOutput = true;
        Main_Firmware_DW.isStartOfNextCycle = true;
      }
    }

    /* End of Update for VariablePulseGenerator: '<S1>/Variable Pulse Generator' */

    /* Update for PropagationDelay: '<S1>/Propagation Delay' incorporates:
     *  Constant: '<S1>/delay'
     */
    if (((Main_Firmware_B.PropagationDelay !=
          Main_Firmware_B.VariablePulseGenerator) && (Main_Firmware_DW.Size ==
          0UL)) || ((Main_Firmware_DW.Size > 0UL) && (*((Main_Firmware_DW.Tail -
            1UL) % Main_Firmware_DW.BufferCapacity + (real_T *)
           Main_Firmware_DW.YNext) != Main_Firmware_B.VariablePulseGenerator)))
    {
      if (Main_Firmware_DW.Size == 0UL) {
        dc = floor((2.8421709430404007E-14 * Main_Firmware_P.delay_Value +
                    Main_Firmware_P.delay_Value) / 0.001);
        if (rtIsNaN(dc) || rtIsInf(dc)) {
          dc = 0.0;
        } else {
          dc = fmod(dc, 4.294967296E+9);
        }

        Main_Firmware_M->Timing.CtrlRateNumTicksToNextHit[1] = ((real_T)(dc <
          0.0 ? (uint32_T)-(int32_T)(uint32_T)-dc : (uint32_T)dc));
      }

      if (Main_Firmware_DW.Size == Main_Firmware_DW.BufferCapacity) {
        Main_Firmware_DW.BufferCapacity <<= 1U;
        tNextTempBuf = malloc((uint16_T)(Main_Firmware_DW.BufferCapacity *
          (uint32_T)sizeof(real_T)));
        memcpy(tNextTempBuf, Main_Firmware_DW.TNext, (uint16_T)
               (Main_Firmware_DW.Size * (uint32_T)sizeof(real_T)));
        free(Main_Firmware_DW.TNext);
        Main_Firmware_DW.TNext = tNextTempBuf;
        tNextTempBuf = malloc((uint16_T)(Main_Firmware_DW.BufferCapacity *
          (uint32_T)sizeof(real_T)));
        memcpy(tNextTempBuf, Main_Firmware_DW.YNext, (uint16_T)
               (Main_Firmware_DW.Size * (uint32_T)sizeof(real_T)));
        free(Main_Firmware_DW.YNext);
        Main_Firmware_DW.YNext = tNextTempBuf;
        Main_Firmware_DW.Head = 0UL;
        Main_Firmware_DW.Tail = Main_Firmware_DW.Size;
      }

      *((real_T *)Main_Firmware_DW.TNext + Main_Firmware_DW.Tail) =
        ((Main_Firmware_M->Timing.clockTick1) * 0.001) +
        Main_Firmware_P.delay_Value;
      *((real_T *)Main_Firmware_DW.YNext + Main_Firmware_DW.Tail) =
        Main_Firmware_B.VariablePulseGenerator;
      Main_Firmware_DW.Tail = (Main_Firmware_DW.Tail + 1UL) %
        Main_Firmware_DW.BufferCapacity;
      Main_Firmware_DW.Size++;
    }

    /* End of Update for PropagationDelay: '<S1>/Propagation Delay' */
  }

  {                                    /* Sample time: [0.001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Main_Firmware_M->Timing.clockTick1 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (Main_Firmware_M->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.001s, -20.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Main_Firmware_M->Timing.clockTick2 *
        (Main_Firmware_M->Timing.CtrlRateNumTicksToNextHit[0]*1-1)) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(2,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (Main_Firmware_M->Timing.TaskCounters.TID[3] == 0) {/* Sample time: [0.001s, -21.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Main_Firmware_M->Timing.clockTick3 *
        (Main_Firmware_M->Timing.CtrlRateNumTicksToNextHit[1]*1-1)) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(3,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Main_Firmware_M->Timing.t[0] =
    ((time_T)(++Main_Firmware_M->Timing.clockTick0)) *
    Main_Firmware_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Main_Firmware_M->Timing.clockTick1++;
  }

  {
    /* Update absolute timer for sample time: [0.001s, -20.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick2" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Main_Firmware_M->Timing.clockTick2++;
  }

  {
    /* Update absolute timer for sample time: [0.001s, -21.0s] */
    /* The "clockTick3" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick3" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Main_Firmware_M->Timing.clockTick3++;
  }

  rate_scheduler();
}

/* Model initialize function */
void Main_Firmware_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Main_Firmware_M, 0,
                sizeof(RT_MODEL_Main_Firmware_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Main_Firmware_M->solverInfo,
                          &Main_Firmware_M->Timing.simTimeStep);
    rtsiSetTPtr(&Main_Firmware_M->solverInfo, &rtmGetTPtr(Main_Firmware_M));
    rtsiSetStepSizePtr(&Main_Firmware_M->solverInfo,
                       &Main_Firmware_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Main_Firmware_M->solverInfo, (&rtmGetErrorStatus
      (Main_Firmware_M)));
    rtsiSetRTModelPtr(&Main_Firmware_M->solverInfo, Main_Firmware_M);
  }

  rtsiSetSimTimeStep(&Main_Firmware_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Main_Firmware_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&Main_Firmware_M->solverInfo, false);
  rtsiSetSolverName(&Main_Firmware_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Main_Firmware_M, &Main_Firmware_M->Timing.tArray[0]);
  rtmSetTFinal(Main_Firmware_M, -1);
  Main_Firmware_M->Timing.stepSize0 = 0.001;
  Main_Firmware_M->Timing.CtrlRateNumTicksToNextHit[0] = 1;
  Main_Firmware_M->Timing.CtrlRateNumTicksToNextHit[1] = 1;

  /* External mode info */
  Main_Firmware_M->Sizes.checksums[0] = (342038878U);
  Main_Firmware_M->Sizes.checksums[1] = (1044611143U);
  Main_Firmware_M->Sizes.checksums[2] = (2453779054U);
  Main_Firmware_M->Sizes.checksums[3] = (2217308267U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Main_Firmware_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Main_Firmware_M->extModeInfo,
      &Main_Firmware_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Main_Firmware_M->extModeInfo,
                        Main_Firmware_M->Sizes.checksums);
    rteiSetTPtr(Main_Firmware_M->extModeInfo, rtmGetTPtr(Main_Firmware_M));
  }

  /* block I/O */
  (void) memset(((void *) &Main_Firmware_B), 0,
                sizeof(B_Main_Firmware_T));

  /* states (dwork) */
  (void) memset((void *)&Main_Firmware_DW, 0,
                sizeof(DW_Main_Firmware_T));

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xFFFF3FFFU;
  GpioCtrlRegs.GPADIR.all |= 0x800000U;
  EDIS;

  /* InitializeConditions for VariablePulseGenerator: '<S1>/Variable Pulse Generator' */
  Main_Firmware_DW.startTimeOfNextCycle = 0.0;
  Main_Firmware_DW.nextOutput = true;
  Main_Firmware_DW.isStartOfNextCycle = true;

  /* InitializeConditions for PropagationDelay: '<S1>/Propagation Delay' */
  Main_Firmware_DW.TNext = malloc((uint16_T)sizeof(real_T));
  *(real_T *)Main_Firmware_DW.TNext = (rtInf);
  Main_Firmware_DW.YNext = malloc((uint16_T)sizeof(real_T));
  *(real_T *)Main_Firmware_DW.YNext = 0.0;

  /* InitializeConditions for PropagationDelay: '<S1>/Propagation Delay' */
  Main_Firmware_B.PropagationDelay = 0.0;

  /* InitializeConditions for PropagationDelay: '<S1>/Propagation Delay' */
  Main_Firmware_DW.Head = 0UL;
  Main_Firmware_DW.Tail = 0UL;
  Main_Firmware_DW.Size = 0UL;
  Main_Firmware_DW.BufferCapacity = 1UL;

  /* Enable for VariablePulseGenerator: '<S1>/Variable Pulse Generator' */
  Main_Firmware_M->Timing.CtrlRateNumTicksToNextHit[0] = (1.0);

  /* Enable for PropagationDelay: '<S1>/Propagation Delay' */
  Main_Firmware_M->Timing.CtrlRateNumTicksToNextHit[1] = (1.0);
}

/* Model terminate function */
void Main_Firmware_terminate(void)
{
  /* Terminate for PropagationDelay: '<S1>/Propagation Delay' */
  free(Main_Firmware_DW.TNext);
  free(Main_Firmware_DW.YNext);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
