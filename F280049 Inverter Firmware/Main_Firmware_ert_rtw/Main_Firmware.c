/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware.c
 *
 * Code generated for Simulink model 'Main_Firmware'.
 *
 * Model version                  : 2.32
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
 * C/C++ source code generated on : Sat Jul 12 16:27:19 2025
=======
 * C/C++ source code generated on : Fri Jul 11 14:41:25 2025
>>>>>>> Stashed changes
=======
 * C/C++ source code generated on : Fri Jul 11 14:41:25 2025
>>>>>>> Stashed changes
=======
 * C/C++ source code generated on : Fri Jul 11 14:41:25 2025
>>>>>>> Stashed changes
=======
 * C/C++ source code generated on : Fri Jul 11 14:41:25 2025
>>>>>>> Stashed changes
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Main_Firmware.h"
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
#include <math.h>
>>>>>>> Stashed changes
=======
#include <math.h>
>>>>>>> Stashed changes
=======
#include <math.h>
>>>>>>> Stashed changes
=======
#include <math.h>
>>>>>>> Stashed changes
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "Main_Firmware_private.h"
#include <string.h>

/* Block signals (default storage) */
B_Main_Firmware_T Main_Firmware_B;

/* Block states (default storage) */
DW_Main_Firmware_T Main_Firmware_DW;

/* Real-time model */
static RT_MODEL_Main_Firmware_T Main_Firmware_M_;
RT_MODEL_Main_Firmware_T *const Main_Firmware_M = &Main_Firmware_M_;

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcCInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcAInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcBInitFlag = 0;

#endif

/* Model step function */
void Main_Firmware_step(void)
{
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
  real_T rtb_DCycleB;
  real_T rtb_DCycleC;
>>>>>>> Stashed changes
=======
  real_T rtb_DCycleB;
  real_T rtb_DCycleC;
>>>>>>> Stashed changes
=======
  real_T rtb_DCycleB;
  real_T rtb_DCycleC;
>>>>>>> Stashed changes
=======
  real_T rtb_DCycleB;
  real_T rtb_DCycleC;
>>>>>>> Stashed changes
  real32_T maxV;

  /* S-Function (c2802xadc): '<S4>/ADC2' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdccRegs.ADCSOCFRC1.bit.SOC1 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #32|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    real32_T wait_index;
    for (wait_index= 5; wait_index > 0; wait_index--)
      __mnop();

#endif

    Main_Firmware_B.ADC2 = (AdccResultRegs.ADCRESULT1);
  }

  /* S-Function (c2802xadc): '<S4>/ADC3' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdccRegs.ADCSOCFRC1.bit.SOC2 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #32|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    real32_T wait_index;
    for (wait_index= 5; wait_index > 0; wait_index--)
      __mnop();

#endif

    Main_Firmware_B.ADC3 = (AdccResultRegs.ADCRESULT2);
  }

  /* S-Function (c2802xadc): '<S4>/ADC4' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcaRegs.ADCSOCFRC1.bit.SOC3 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #32|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    real32_T wait_index;
    for (wait_index= 5; wait_index > 0; wait_index--)
      __mnop();

#endif

    Main_Firmware_B.ADC4 = (AdcaResultRegs.ADCRESULT3);
  }

  /* Gain: '<S4>/Gain2' */
  Main_Firmware_B.Gain2[0] = Main_Firmware_P.Gain2_Gain * Main_Firmware_B.ADC2;
  Main_Firmware_B.Gain2[1] = Main_Firmware_P.Gain2_Gain * Main_Firmware_B.ADC3;
  Main_Firmware_B.Gain2[2] = Main_Firmware_P.Gain2_Gain * Main_Firmware_B.ADC4;

  /* Gain: '<S5>/Gain' incorporates:
   *  Bias: '<S5>/Bias1'
   */
  Main_Firmware_B.I_ABC[0] = (Main_Firmware_B.Gain2[0] +
    Main_Firmware_P.Bias1_Bias) * Main_Firmware_P.Gain_Gain;
  Main_Firmware_B.I_ABC[1] = (Main_Firmware_B.Gain2[1] +
    Main_Firmware_P.Bias1_Bias) * Main_Firmware_P.Gain_Gain;
  Main_Firmware_B.I_ABC[2] = (Main_Firmware_B.Gain2[2] +
    Main_Firmware_P.Bias1_Bias) * Main_Firmware_P.Gain_Gain;

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
  /* S-Function (c2802xpwm): '<S2>/AHI' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
=======
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
  /* Sin: '<S2>/Sine Wave1' incorporates:
   *  Sin: '<S2>/Sine Wave2'
   */
  rtb_DCycleB = Main_Firmware_M->Timing.t[0];
  rtb_DCycleC = sin(Main_Firmware_P.SineWave1_Freq * rtb_DCycleB +
                    Main_Firmware_P.SineWave1_Phase) *
    Main_Firmware_P.SineWave1_Amp + Main_Firmware_P.SineWave1_Bias;

  /* Sin: '<S2>/Sine Wave2' */
  rtb_DCycleB = sin(Main_Firmware_P.SineWave2_Freq * rtb_DCycleB +
                    Main_Firmware_P.SineWave2_Phase) *
    Main_Firmware_P.SineWave2_Amp + Main_Firmware_P.SineWave2_Bias;

  /* S-Function (c2802xpwm): '<S2>/A1' incorporates:
   *  Constant: '<S2>/Constant1'
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
   */
  uint16_T tbprdValue1Outputs = (EPwm1Regs.TBPRD + 1);

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)((uint32_T)(EPwm1Regs.TBPRD + 1) *
      Main_Firmware_P.Constant1_Value * 0.01);
  }

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
  EPwm1Regs.AQCSFRC.bit.CSFA = (uint16_T)Main_Firmware_P.Constant2_Value;
=======
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
  /* S-Function (c2802xpwm): '<S2>/B1' */
  uint16_T tbprdValue4Outputs = (EPwm4Regs.TBPRD + 1);

  /*-- Update CMPA value for ePWM4 --*/
  {
    EPwm4Regs.CMPA.bit.CMPA = (uint16_T)((uint32_T)(EPwm4Regs.TBPRD + 1) *
      rtb_DCycleB * 0.01);
  }

  /* S-Function (c2802xpwm): '<S2>/C1' */
  uint16_T tbprdValue2Outputs = (EPwm2Regs.TBPRD + 1);

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.bit.CMPA = (uint16_T)((uint32_T)(EPwm2Regs.TBPRD + 1) *
      rtb_DCycleC * 0.01);
  }
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes

  /* S-Function (c2802xadc): '<S4>/ADC' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcbRegs.ADCSOCFRC1.bit.SOC0 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #32|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    real32_T wait_index;
    for (wait_index= 5; wait_index > 0; wait_index--)
      __mnop();

#endif

    Main_Firmware_B.VCos = (AdcbResultRegs.ADCRESULT0);
  }

  /* S-Function (c2802xadc): '<S4>/ADC1' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcaRegs.ADCSOCFRC1.bit.SOC8 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #32|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    real32_T wait_index;
    for (wait_index= 5; wait_index > 0; wait_index--)
      __mnop();

#endif

    Main_Firmware_B.VSine = (AdcaResultRegs.ADCRESULT8);
  }

  /* Gain: '<S4>/Gain1' */
  Main_Firmware_B.Gain1[0] = Main_Firmware_P.Gain1_Gain * Main_Firmware_B.VCos;
  Main_Firmware_B.Gain1[1] = Main_Firmware_P.Gain1_Gain * Main_Firmware_B.VSine;

  /* DiscretePulseGenerator: '<Root>/LED Heartbeat' */
  Main_Firmware_B.LEDHeartbeat = (Main_Firmware_DW.clockTickCounter <
    Main_Firmware_P.LEDHeartbeat_Duty) && (Main_Firmware_DW.clockTickCounter >=
    0L) ? Main_Firmware_P.LEDHeartbeat_Amp : 0.0;

  /* DiscretePulseGenerator: '<Root>/LED Heartbeat' */
  if (Main_Firmware_DW.clockTickCounter >= Main_Firmware_P.LEDHeartbeat_Period -
      1.0) {
    Main_Firmware_DW.clockTickCounter = 0L;
  } else {
    Main_Firmware_DW.clockTickCounter++;
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output' */
  {
    if (Main_Firmware_B.LEDHeartbeat) {
      GpioDataRegs.GPASET.bit.GPIO23 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO23 = 1U;
    }
  }

  /* MinMax: '<S3>/Max' incorporates:
   *  Gain: '<S5>/Gain'
   */
  if ((Main_Firmware_B.I_ABC[0] >= Main_Firmware_B.I_ABC[1]) || rtIsNaNF
      (Main_Firmware_B.I_ABC[1])) {
    maxV = Main_Firmware_B.I_ABC[0];
  } else {
    maxV = Main_Firmware_B.I_ABC[1];
  }

  if ((!(maxV >= Main_Firmware_B.I_ABC[2])) && (!rtIsNaNF(Main_Firmware_B.I_ABC
        [2]))) {
    maxV = Main_Firmware_B.I_ABC[2];
  }

  /* Logic: '<S3>/AND' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  MinMax: '<S3>/Max'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  Main_Firmware_B.AND = ((maxV <= Main_Firmware_P.CompareToConstant_const) &&
    (Main_Firmware_P.CompareToConstant1_const >= 0.0F) &&
    (Main_Firmware_P.CompareToConstant2_const >= 0.0F) &&
    (Main_Firmware_P.CompareToConstant3_const >= 0.0F) &&
    Main_Firmware_P.Constant_Value);
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes

  {                                    /* Sample time: [0.0001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((Main_Firmware_M->Timing.clockTick1 * 1) + 0);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }
>>>>>>> Stashed changes

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
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.0001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Main_Firmware_M->Timing.clockTick1++;
  }
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
  Main_Firmware_M->Timing.stepSize0 = 0.0001;

  /* External mode info */
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
  Main_Firmware_M->Sizes.checksums[0] = (521920562U);
  Main_Firmware_M->Sizes.checksums[1] = (1565920920U);
  Main_Firmware_M->Sizes.checksums[2] = (2996462942U);
  Main_Firmware_M->Sizes.checksums[3] = (2232810687U);
=======
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
  Main_Firmware_M->Sizes.checksums[0] = (965087358U);
  Main_Firmware_M->Sizes.checksums[1] = (4132334593U);
  Main_Firmware_M->Sizes.checksums[2] = (4182433122U);
  Main_Firmware_M->Sizes.checksums[3] = (22837157U);
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes

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
    rteiSetTFinalTicks(Main_Firmware_M->extModeInfo, -1);
  }

  /* block I/O */
  (void) memset(((void *) &Main_Firmware_B), 0,
                sizeof(B_Main_Firmware_T));

  /* states (dwork) */
  (void) memset((void *)&Main_Firmware_DW, 0,
                sizeof(DW_Main_Firmware_T));

  /* Start for S-Function (c2802xadc): '<S4>/ADC2' */
  if (MW_adcCInitFlag == 0U) {
    InitAdcC();
    MW_adcCInitFlag = 1U;
  }

  config_ADCC_SOC1 ();

  /* Start for S-Function (c2802xadc): '<S4>/ADC3' */
  if (MW_adcCInitFlag == 0U) {
    InitAdcC();
    MW_adcCInitFlag = 1U;
  }

  config_ADCC_SOC2 ();

  /* Start for S-Function (c2802xadc): '<S4>/ADC4' */
  if (MW_adcAInitFlag == 0U) {
    InitAdcA();
    MW_adcAInitFlag = 1U;
  }

  config_ADCA_SOC3 ();

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
  /* Start for S-Function (c2802xpwm): '<S2>/AHI' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
=======
  /* Start for S-Function (c2802xpwm): '<S2>/A1' incorporates:
   *  Constant: '<S2>/Constant1'
>>>>>>> Stashed changes
=======
  /* Start for S-Function (c2802xpwm): '<S2>/A1' incorporates:
   *  Constant: '<S2>/Constant1'
>>>>>>> Stashed changes
=======
  /* Start for S-Function (c2802xpwm): '<S2>/A1' incorporates:
   *  Constant: '<S2>/Constant1'
>>>>>>> Stashed changes
=======
  /* Start for S-Function (c2802xpwm): '<S2>/A1' incorporates:
   *  Constant: '<S2>/Constant1'
>>>>>>> Stashed changes
   */
  real32_T tbprdValue1 = (real32_T)(EPwm1Regs.TBPRD + 1);

  /*** Initialize ePWM1 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 0U;          -- Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 3U;          -- Sync Output Select
       EPwm1Regs.TBCTL2.bit.SYNCOSELX           = 0U;          -- Sync Output Select - additional options

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm1Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          -- Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          -- Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x30U;
    EPwm1Regs.TBCTL2.all = (EPwm1Regs.TBCTL2.all & ~0xF000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 499U;            // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm1Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm1Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm1Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm1Regs.CMPCTL2.all = (EPwm1Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm1Regs.CMPA.bit.CMPA = 0U;      // Counter Compare A Register
    EPwm1Regs.CMPB.bit.CMPB = 32000U;  // Counter Compare B Register
    EPwm1Regs.CMPC = 300U;             // Counter Compare C Register
    EPwm1Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 150U;
                               // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 2070U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 1U;          -- Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x1U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 0U;          -- Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 0;          -- Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm1Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm1Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm1Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm1Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x8FFFU) | 0x0U;
    EPwm1Regs.DBRED.bit.DBRED = (uint16_T)(0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED.bit.DBFED = (uint16_T)(0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCASEL              = 1U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM1SOC Period Select
       EPwm1Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM1SOCB Period Select
       EPwm1Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM1INTn Period Select
       EPwm1Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF7FU) | 0x1101U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm1Regs.ETSOCPS.all = (EPwm1Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm1Regs.ETINTPS.all = (EPwm1Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          -- Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm1Regs.EPWMXLINK.bit.TBPRDLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPALINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPBLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPCLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPDLINK = 0U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm1Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm1Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm1Regs.HRPCTL.all = (EPwm1Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
  /* Start for S-Function (c2802xadc): '<S4>/ADC' */
  if (MW_adcBInitFlag == 0U) {
    InitAdcB();
    MW_adcBInitFlag = 1U;
  }

  config_ADCB_SOC0 ();
=======
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
  /* Start for S-Function (c2802xpwm): '<S2>/B1' */
  real32_T tbprdValue4 = (real32_T)(EPwm4Regs.TBPRD + 1);

  /*** Initialize ePWM4 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm4Regs.TBCTL.bit.CTRMODE              = 0U;          -- Counter Mode
       EPwm4Regs.TBCTL.bit.SYNCOSEL             = 3U;          -- Sync Output Select
       EPwm4Regs.TBCTL2.bit.SYNCOSELX           = 0U;          -- Sync Output Select - additional options

       EPwm4Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm4Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm4Regs.TBCTL.bit.PHSEN                = 0U;          -- Phase Load Enable
       EPwm4Regs.TBCTL.bit.PHSDIR               = 0U;          -- Phase Direction Bit
       EPwm4Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm4Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm4Regs.TBCTL.all = (EPwm4Regs.TBCTL.all & ~0x3FFFU) | 0x30U;
    EPwm4Regs.TBCTL2.all = (EPwm4Regs.TBCTL2.all & ~0xF000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm4Regs.TBPRD = 499U;            // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm4Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm4Regs.TBPHS.all = (EPwm4Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm4Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm4Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm4Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm4Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm4Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm4Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm4Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm4Regs.CMPCTL.all = (EPwm4Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm4Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm4Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm4Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm4Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm4Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm4Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm4Regs.CMPCTL2.all = (EPwm4Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm4Regs.CMPA.bit.CMPA = 0U;      // Counter Compare A Register
    EPwm4Regs.CMPB.bit.CMPB = 32000U;  // Counter Compare B Register
    EPwm4Regs.CMPC = 300U;             // Counter Compare C Register
    EPwm4Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm4Regs.AQCTLA.all = 150U;
                               // Action Qualifier Control Register For Output A
    EPwm4Regs.AQCTLB.all = 2070U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm4Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm4Regs.AQSFRC.all = (EPwm4Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm4Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm4Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm4Regs.AQCSFRC.all = (EPwm4Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm4Regs.DBCTL.bit.OUT_MODE             = 0U;          -- Dead Band Output Mode Control
       EPwm4Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm4Regs.DBCTL.bit.POLSEL               = 0;          -- Polarity Select Control
       EPwm4Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm4Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm4Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm4Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm4Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm4Regs.DBCTL.all = (EPwm4Regs.DBCTL.all & ~0x8FFFU) | 0x0U;
    EPwm4Regs.DBRED.bit.DBRED = (uint16_T)(0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm4Regs.DBFED.bit.DBFED = (uint16_T)(0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm4Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm4Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm4Regs.ETSEL.bit.SOCASEL              = 1U;          -- Start of Conversion A Select
       EPwm4Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM4SOC Period Select
       EPwm4Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm4Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm4Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm4Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm4Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM4SOCB Period Select
       EPwm4Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm4Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM4INTn Enable
       EPwm4Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm4Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm4Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM4INTn Period Select
       EPwm4Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm4Regs.ETSEL.all = (EPwm4Regs.ETSEL.all & ~0xFF7FU) | 0x1101U;
    EPwm4Regs.ETPS.all = (EPwm4Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm4Regs.ETSOCPS.all = (EPwm4Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm4Regs.ETINTPS.all = (EPwm4Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm4Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm4Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm4Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm4Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm4Regs.PCCTL.all = (EPwm4Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm4Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm4Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM4A
       EPwm4Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM4B
       EPwm4Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM4A action on DCAEVT1
       EPwm4Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM4A action on DCAEVT2
       EPwm4Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM4B action on DCBEVT1
       EPwm4Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM4B action on DCBEVT2
     */
    EPwm4Regs.TZCTL.all = (EPwm4Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm4Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm4Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm4Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm4Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm4Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm4Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm4Regs.TZEINT.all = (EPwm4Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm4Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm4Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm4Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm4Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm4Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm4Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm4Regs.DCACTL.all = (EPwm4Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm4Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm4Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm4Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm4Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm4Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm4Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm4Regs.DCBCTL.all = (EPwm4Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm4Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm4Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          -- Digital Compare A Low COMP Input Select
       EPwm4Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm4Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm4Regs.DCTRIPSEL.all = (EPwm4Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm4Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm4Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm4Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm4Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm4Regs.TZDCSEL.all = (EPwm4Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm4Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm4Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm4Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm4Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm4Regs.DCFCTL.all = (EPwm4Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm4Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm4Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm4Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm4Regs.DCCAPCTL.all = (EPwm4Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm4Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm4Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm4Regs.HRCNFG.all = (EPwm4Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm4Regs.EPWMXLINK.bit.TBPRDLINK = 0U;
    EPwm4Regs.EPWMXLINK.bit.CMPALINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPBLINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPCLINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPDLINK = 3U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm4Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm4Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm4Regs.HRPCTL.all = (EPwm4Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S2>/C1' */
  real32_T tbprdValue2 = (real32_T)(EPwm2Regs.TBPRD + 1);
>>>>>>> Stashed changes

  /* Start for S-Function (c2802xadc): '<S4>/ADC1' */
  if (MW_adcAInitFlag == 0U) {
    InitAdcA();
    MW_adcAInitFlag = 1U;
  }

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
  /* Start for S-Function (c2802xadc): '<S4>/ADC' */
  if (MW_adcBInitFlag == 0U) {
    InitAdcB();
    MW_adcBInitFlag = 1U;
  }

  config_ADCB_SOC0 ();

  /* Start for S-Function (c2802xadc): '<S4>/ADC1' */
  if (MW_adcAInitFlag == 0U) {
    InitAdcA();
    MW_adcAInitFlag = 1U;
  }

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
  config_ADCA_SOC8 ();

  /* Start for DiscretePulseGenerator: '<Root>/LED Heartbeat' */
  Main_Firmware_DW.clockTickCounter = 0L;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xFFFF3FFFU;
  GpioCtrlRegs.GPADIR.all |= 0x800000U;
  EDIS;
}

/* Model terminate function */
void Main_Firmware_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
