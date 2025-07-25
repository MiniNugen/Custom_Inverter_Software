/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware.c
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
#include "Main_Firmware_private.h"
#include "Main_Firmware_types.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>

/* Block signals (default storage) */
B_Main_Firmware_T Main_Firmware_B;

/* Block states (default storage) */
DW_Main_Firmware_T Main_Firmware_DW;

/* Real-time model */
static RT_MODEL_Main_Firmware_T Main_Firmware_M_;
RT_MODEL_Main_Firmware_T *const Main_Firmware_M = &Main_Firmware_M_;
static void rate_monotonic_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcAInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcBInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcCInitFlag = 0;

#endif

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Main_Firmware_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(Main_Firmware_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (Main_Firmware_M->Timing.TaskCounters.TID[1] == 0) {
    Main_Firmware_M->Timing.RateInteraction.TID1_2 =
      (Main_Firmware_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Main_Firmware_M->Timing.TaskCounters.TID[2])++;
  if ((Main_Firmware_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.01s, 0.0s] */
    Main_Firmware_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* System initialize for atomic system: */
void Main_Fi_LowpassFilter1_Init(DW_LowpassFilter1_Main_Firmwa_T *localDW)
{
  int16_T i;
  static const real32_T tmp[11] = { -0.00547596859F, -0.0178087261F,
    -0.00103627914F, 0.100073069F, 0.257824033F, 0.338187665F, 0.257824033F,
    0.100073069F, -0.00103627914F, -0.0178087261F, -0.00547596859F };

  /* Start for MATLABSystem: '<S6>/Lowpass Filter1' */
  localDW->obj.NumChannels = -1L;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1L;
  if (localDW->obj.NumChannels == -1L) {
    localDW->obj.NumChannels = 1L;
  }

  localDW->obj._pobj0.isInitialized = 0L;

  /* System object Constructor function: dsp.FIRFilter */
  localDW->obj._pobj0.cSFunObject.P0_InitialStates = 0.0F;
  for (i = 0; i < 11; i++) {
    localDW->obj._pobj0.cSFunObject.P1_Coefficients[i] = tmp[i];
  }

  localDW->obj.FilterObj = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;

  /* InitializeConditions for MATLABSystem: '<S6>/Lowpass Filter1' */
  if (localDW->obj.FilterObj->isInitialized == 1L) {
    /* System object Initialization function: dsp.FIRFilter */
    for (i = 0; i < 10; i++) {
      localDW->obj.FilterObj->cSFunObject.W0_states[i] = localDW->
        obj.FilterObj->cSFunObject.P0_InitialStates;
    }
  }

  /* End of InitializeConditions for MATLABSystem: '<S6>/Lowpass Filter1' */
}

/* Output and update for atomic system: */
void Main_Firmwar_LowpassFilter1(real32_T rtu_0, B_LowpassFilter1_Main_Firmwar_T
  *localB, DW_LowpassFilter1_Main_Firmwa_T *localDW)
{
  b_dspcodegen_FIRFilter_Main_F_T *obj;
  int16_T srcIdx;

  /* MATLABSystem: '<S6>/Lowpass Filter1' */
  obj = localDW->obj.FilterObj;
  if (localDW->obj.FilterObj->isInitialized != 1L) {
    localDW->obj.FilterObj->isSetupComplete = false;
    localDW->obj.FilterObj->isInitialized = 1L;
    localDW->obj.FilterObj->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (srcIdx = 0; srcIdx < 10; srcIdx++) {
      localDW->obj.FilterObj->cSFunObject.W0_states[srcIdx] =
        localDW->obj.FilterObj->cSFunObject.P0_InitialStates;
    }
  }

  /* System object Outputs function: dsp.FIRFilter */
  /* Reverse the coefficients */
  for (srcIdx = 0; srcIdx < 11; srcIdx++) {
    obj->cSFunObject.W2_simRevCoeff[(int32_T)(10 - srcIdx)] =
      obj->cSFunObject.P1_Coefficients[(int32_T)srcIdx];
  }

  /* Reverse copy the states from States_Dwork to ContextBuff_Dwork */
  /* Copy the initial part of input to ContextBuff_Dwork */
  for (srcIdx = 0; srcIdx < 10; srcIdx++) {
    obj->cSFunObject.W1_simContextBuf[(int32_T)(9 - srcIdx)] =
      obj->cSFunObject.W0_states[(int32_T)srcIdx];
  }

  obj->cSFunObject.W1_simContextBuf[10L] = rtu_0;
  localB->LowpassFilter1 = 0.0F;
  for (srcIdx = 0; srcIdx < 11; srcIdx++) {
    localB->LowpassFilter1 += obj->cSFunObject.W2_simRevCoeff[(int32_T)srcIdx] *
      obj->cSFunObject.W1_simContextBuf[(int32_T)srcIdx];
  }

  /* store output sample */
  /* Shift state buffer when input buffer is shorter than state buffer */
  for (srcIdx = 8; srcIdx >= 0; srcIdx--) {
    obj->cSFunObject.W0_states[(int32_T)(srcIdx + 1)] =
      obj->cSFunObject.W0_states[(int32_T)srcIdx];
  }

  /* Reverse copy the states from input to States_Dwork */
  obj->cSFunObject.W0_states[0L] = rtu_0;

  /* End of MATLABSystem: '<S6>/Lowpass Filter1' */
}

/* Termination for atomic system: */
void Main_Fi_LowpassFilter1_Term(DW_LowpassFilter1_Main_Firmwa_T *localDW)
{
  /* Terminate for MATLABSystem: '<S6>/Lowpass Filter1' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1L) && localDW->obj.isSetupComplete) {
      if (localDW->obj.FilterObj->isInitialized == 1L) {
        localDW->obj.FilterObj->isInitialized = 2L;
      }

      localDW->obj.NumChannels = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Lowpass Filter1' */
}

/* System initialize for atomic system: */
void Main_Fi_LowpassFilter3_Init(DW_LowpassFilter3_Main_Firmwa_T *localDW)
{
  int16_T i;
  static const real32_T tmp[10] = { 0.00482357386F, 0.0284141693F, 0.0842064545F,
    0.161975205F, 0.220998511F, 0.220998511F, 0.161975205F, 0.0842064545F,
    0.0284141693F, 0.00482357386F };

  /* Start for MATLABSystem: '<S6>/Lowpass Filter3' */
  localDW->obj.NumChannels = -1L;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1L;
  if (localDW->obj.NumChannels == -1L) {
    localDW->obj.NumChannels = 1L;
  }

  localDW->obj._pobj0.isInitialized = 0L;

  /* System object Constructor function: dsp.FIRFilter */
  localDW->obj._pobj0.cSFunObject.P0_InitialStates = 0.0F;
  for (i = 0; i < 10; i++) {
    localDW->obj._pobj0.cSFunObject.P1_Coefficients[i] = tmp[i];
  }

  localDW->obj.FilterObj = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;

  /* InitializeConditions for MATLABSystem: '<S6>/Lowpass Filter3' */
  if (localDW->obj.FilterObj->isInitialized == 1L) {
    /* System object Initialization function: dsp.FIRFilter */
    for (i = 0; i < 9; i++) {
      localDW->obj.FilterObj->cSFunObject.W0_states[i] = localDW->
        obj.FilterObj->cSFunObject.P0_InitialStates;
    }
  }

  /* End of InitializeConditions for MATLABSystem: '<S6>/Lowpass Filter3' */
}

/* Output and update for atomic system: */
void Main_Firmwar_LowpassFilter3(real32_T rtu_0, B_LowpassFilter3_Main_Firmwar_T
  *localB, DW_LowpassFilter3_Main_Firmwa_T *localDW)
{
  b_dspcodegen_FIRFilter_Main_l_T *obj;
  int16_T srcIdx;

  /* MATLABSystem: '<S6>/Lowpass Filter3' */
  obj = localDW->obj.FilterObj;
  if (localDW->obj.FilterObj->isInitialized != 1L) {
    localDW->obj.FilterObj->isSetupComplete = false;
    localDW->obj.FilterObj->isInitialized = 1L;
    localDW->obj.FilterObj->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (srcIdx = 0; srcIdx < 9; srcIdx++) {
      localDW->obj.FilterObj->cSFunObject.W0_states[srcIdx] =
        localDW->obj.FilterObj->cSFunObject.P0_InitialStates;
    }
  }

  /* System object Outputs function: dsp.FIRFilter */
  /* Reverse the coefficients */
  for (srcIdx = 0; srcIdx < 10; srcIdx++) {
    obj->cSFunObject.W2_simRevCoeff[(int32_T)(9 - srcIdx)] =
      obj->cSFunObject.P1_Coefficients[(int32_T)srcIdx];
  }

  /* Reverse copy the states from States_Dwork to ContextBuff_Dwork */
  /* Copy the initial part of input to ContextBuff_Dwork */
  for (srcIdx = 0; srcIdx < 9; srcIdx++) {
    obj->cSFunObject.W1_simContextBuf[(int32_T)(8 - srcIdx)] =
      obj->cSFunObject.W0_states[(int32_T)srcIdx];
  }

  obj->cSFunObject.W1_simContextBuf[9L] = rtu_0;
  localB->LowpassFilter3 = 0.0F;
  for (srcIdx = 0; srcIdx < 10; srcIdx++) {
    localB->LowpassFilter3 += obj->cSFunObject.W2_simRevCoeff[(int32_T)srcIdx] *
      obj->cSFunObject.W1_simContextBuf[(int32_T)srcIdx];
  }

  /* store output sample */
  /* Shift state buffer when input buffer is shorter than state buffer */
  for (srcIdx = 7; srcIdx >= 0; srcIdx--) {
    obj->cSFunObject.W0_states[(int32_T)(srcIdx + 1)] =
      obj->cSFunObject.W0_states[(int32_T)srcIdx];
  }

  /* Reverse copy the states from input to States_Dwork */
  obj->cSFunObject.W0_states[0L] = rtu_0;

  /* End of MATLABSystem: '<S6>/Lowpass Filter3' */
}

/* Termination for atomic system: */
void Main_Fi_LowpassFilter3_Term(DW_LowpassFilter3_Main_Firmwa_T *localDW)
{
  /* Terminate for MATLABSystem: '<S6>/Lowpass Filter3' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1L) && localDW->obj.isSetupComplete) {
      if (localDW->obj.FilterObj->isInitialized == 1L) {
        localDW->obj.FilterObj->isInitialized = 2L;
      }

      localDW->obj.NumChannels = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Lowpass Filter3' */
}

/* Model step function for TID0 */
void Main_Firmware_step0(void)         /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_IntegralGain;
  real32_T rtb_TSamp;
  real32_T rtb_Diff;
  real32_T rtb_FilterCoefficient;
  real32_T rtb_IntegralGain_p;
  real_T rtb_Id_err;
  real_T rtb_Vd;
  real32_T rtb_Bias[2];
  real32_T tmp_0[2];
  real32_T TmpSignalConversionAtGain3Inp_0;
  real32_T TmpSignalConversionAtGain3Inpor;
  real32_T rtb_Filter;
  real32_T rtb_Gain3_idx_0;
  real32_T rtb_Gain3_idx_1;
  real32_T rtb_Iq_error;
  int16_T rtb_Compare;
  boolean_T tmp;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Main_Firmware_DW.SwitchCaseActionSubsystem2_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Main_Firmware_DW.RegenMode_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Main_Firmware_DW.FaultState_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Main_Firmware_DW.Subsystempi2delay_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Main_Firmware_DW.Subsystem1_SubsysRanBC);

  /* Sin: '<S2>/Sine Wave' incorporates:
   *  Sin: '<S2>/Sine Wave1'
   *  Sin: '<S2>/Sine Wave2'
   */
  rtb_Id_err = Main_Firmware_M->Timing.t[0];

  /* Gain: '<S2>/Gain1' incorporates:
   *  Sin: '<S2>/Sine Wave'
   *  Sin: '<S2>/Sine Wave1'
   *  Sin: '<S2>/Sine Wave2'
   */
  Main_Firmware_B.Gain1[0] = (sin(Main_Firmware_P.SineWave_Freq * rtb_Id_err +
    Main_Firmware_P.SineWave_Phase) * Main_Firmware_P.SineWave_Amp +
    Main_Firmware_P.SineWave_Bias) * Main_Firmware_P.Gain1_Gain;
  Main_Firmware_B.Gain1[1] = (sin(Main_Firmware_P.SineWave2_Freq * rtb_Id_err +
    Main_Firmware_P.SineWave2_Phase) * Main_Firmware_P.SineWave2_Amp +
    Main_Firmware_P.SineWave2_Bias) * Main_Firmware_P.Gain1_Gain;
  Main_Firmware_B.Gain1[2] = (sin(Main_Firmware_P.SineWave1_Freq * rtb_Id_err +
    Main_Firmware_P.SineWave1_Phase) * Main_Firmware_P.SineWave1_Amp +
    Main_Firmware_P.SineWave1_Bias) * Main_Firmware_P.Gain1_Gain;

  /* S-Function (c2802xadc): '<S5>/ADC5' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcaRegs.ADCSOCFRC1.bit.SOC5 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #56|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    real32_T wait_index;
    for (wait_index= 9; wait_index > 0; wait_index--)
      __mnop();

#endif

    Main_Firmware_B.ADC5 = (AdcaResultRegs.ADCRESULT5);
  }

  /* S-Function (c2802xadc): '<S5>/ADC6' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcbRegs.ADCSOCFRC1.bit.SOC0 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #88|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    real32_T wait_index;
    for (wait_index= 14; wait_index > 0; wait_index--)
      __mnop();

#endif

    Main_Firmware_B.ADC6 = (AdcbResultRegs.ADCRESULT0);
  }

  /* S-Function (c2802xadc): '<S5>/ADC7' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdccRegs.ADCSOCFRC1.bit.SOC2 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #88|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    real32_T wait_index;
    for (wait_index= 14; wait_index > 0; wait_index--)
      __mnop();

#endif

    Main_Firmware_B.ADC7 = (AdccResultRegs.ADCRESULT2);
  }

  /* Gain: '<S6>/Gain' incorporates:
   *  Bias: '<S6>/Bias1'
   *  Gain: '<S5>/Gain3'
   */
  Main_Firmware_B.I_ABC[0] = (Main_Firmware_P.Gain3_Gain * Main_Firmware_B.ADC5
    + Main_Firmware_P.Bias1_Bias) * Main_Firmware_P.Gain_Gain;
  Main_Firmware_B.I_ABC[1] = (Main_Firmware_P.Gain3_Gain * Main_Firmware_B.ADC6
    + Main_Firmware_P.Bias1_Bias) * Main_Firmware_P.Gain_Gain;
  Main_Firmware_B.I_ABC[2] = (Main_Firmware_P.Gain3_Gain * Main_Firmware_B.ADC7
    + Main_Firmware_P.Bias1_Bias) * Main_Firmware_P.Gain_Gain;
  Main_Firmwar_LowpassFilter1(Main_Firmware_B.I_ABC[0],
    &Main_Firmware_B.LowpassFilter2, &Main_Firmware_DW.LowpassFilter2);

  /* Bias: '<S6>/Bias2' */
  Main_Firmware_B.Bias2 = Main_Firmware_B.LowpassFilter2.LowpassFilter1 +
    Main_Firmware_P.Bias2_Bias;
  Main_Firmwar_LowpassFilter1(Main_Firmware_B.I_ABC[1],
    &Main_Firmware_B.LowpassFilter1, &Main_Firmware_DW.LowpassFilter1);

  /* Bias: '<S6>/Bias3' */
  Main_Firmware_B.Bias3 = Main_Firmware_B.LowpassFilter1.LowpassFilter1 +
    Main_Firmware_P.Bias3_Bias;
  Main_Firmwar_LowpassFilter1(Main_Firmware_B.I_ABC[2],
    &Main_Firmware_B.LowpassFilter5, &Main_Firmware_DW.LowpassFilter5);

  /* Bias: '<S6>/Bias4' */
  Main_Firmware_B.Bias4 = Main_Firmware_B.LowpassFilter5.LowpassFilter1 +
    Main_Firmware_P.Bias4_Bias;

  /* SignalConversion generated from: '<S123>/Gain3' */
  Main_Firmware_B.TmpSignalConversionAtGain3Inpor[0] = Main_Firmware_B.Bias2;
  Main_Firmware_B.TmpSignalConversionAtGain3Inpor[1] = Main_Firmware_B.Bias3;
  Main_Firmware_B.TmpSignalConversionAtGain3Inpor[2] = Main_Firmware_B.Bias4;

  /* Abs: '<S4>/Abs' */
  rtb_Gain3_idx_0 = fabsf(Main_Firmware_B.TmpSignalConversionAtGain3Inpor[0]);
  rtb_Gain3_idx_1 = fabsf(Main_Firmware_B.TmpSignalConversionAtGain3Inpor[1]);

  /* MinMax: '<S4>/Max' incorporates:
   *  Abs: '<S4>/Abs'
   */
  Main_Firmware_B.Max = fabsf(Main_Firmware_B.TmpSignalConversionAtGain3Inpor[2]);
  if ((rtb_Gain3_idx_0 >= rtb_Gain3_idx_1) || rtIsNaNF(rtb_Gain3_idx_1)) {
    rtb_Gain3_idx_1 = rtb_Gain3_idx_0;
  }

  if ((rtb_Gain3_idx_1 >= Main_Firmware_B.Max) || rtIsNaNF(Main_Firmware_B.Max))
  {
    /* MinMax: '<S4>/Max' */
    Main_Firmware_B.Max = rtb_Gain3_idx_1;
  }

  /* End of MinMax: '<S4>/Max' */

  /* RelationalOperator: '<S182>/Compare' incorporates:
   *  Constant: '<S182>/Constant'
   */
  Main_Firmware_B.Compare = (Main_Firmware_B.Max <=
    Main_Firmware_P.CompareToConstant_const_k);

  /* S-Function (c2802xadc): '<S5>/ADC' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcbRegs.ADCSOCFRC1.bit.SOC4 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #56|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    real32_T wait_index;
    for (wait_index= 9; wait_index > 0; wait_index--)
      __mnop();

#endif

    Main_Firmware_B.VCos = (AdcbResultRegs.ADCRESULT4);
  }

  /* S-Function (c2802xadc): '<S5>/ADC1' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcaRegs.ADCSOCFRC1.bit.SOC6 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #56|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    real32_T wait_index;
    for (wait_index= 9; wait_index > 0; wait_index--)
      __mnop();

#endif

    Main_Firmware_B.VSine = (AdcaResultRegs.ADCRESULT6);
  }

  /* Gain: '<S5>/Gain1' */
  Main_Firmware_B.Gain1_p[0] = Main_Firmware_P.Gain1_Gain_n *
    Main_Firmware_B.VCos;
  Main_Firmware_B.Gain1_p[1] = Main_Firmware_P.Gain1_Gain_n *
    Main_Firmware_B.VSine;

  /* Bias: '<S6>/Bias' */
  Main_Firmwar_LowpassFilter3(Main_Firmware_B.Gain1_p[0] +
    Main_Firmware_P.Bias_Bias_j, &Main_Firmware_B.LowpassFilter3,
    &Main_Firmware_DW.LowpassFilter3);
  Main_Firmwar_LowpassFilter3(Main_Firmware_B.Gain1_p[1] +
    Main_Firmware_P.Bias_Bias_j, &Main_Firmware_B.LowpassFilter4,
    &Main_Firmware_DW.LowpassFilter4);

  /* Gain: '<S3>/Gain2' incorporates:
   *  Constant: '<S3>/Const'
   *  Product: '<S6>/Divide'
   *  Sum: '<S3>/Sum'
   *  Trigonometry: '<S6>/Atan'
   */
  rtb_Gain3_idx_1 = ((real32_T)atan(1.0F /
    Main_Firmware_B.LowpassFilter3.LowpassFilter3 *
    Main_Firmware_B.LowpassFilter4.LowpassFilter3) - (real32_T)
                     Main_Firmware_P.Encoder_Offset) * Main_Firmware_P.ppair;

  /* SampleTimeMath: '<S128>/TSamp'
   *
   * About '<S128>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = rtb_Gain3_idx_1 * Main_Firmware_P.TSamp_WtEt;

  /* Sum: '<S128>/Diff' incorporates:
   *  UnitDelay: '<S128>/UD'
   *
   * Block description for '<S128>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S128>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Diff = rtb_TSamp - Main_Firmware_DW.UD_DSTATE;

  /* SignalConversion generated from: '<S129>/Selector1' incorporates:
   *  Delay: '<S129>/Delay1'
   */
  rtb_Bias[0] = rtb_Diff;
  rtb_Bias[1] = Main_Firmware_DW.Delay1_DSTATE;

  /* Abs: '<S129>/Abs1' incorporates:
   *  Delay: '<S129>/Delay2'
   *  Sum: '<S129>/Subtract1'
   */
  rtb_Iq_error = fabsf(rtb_Diff - Main_Firmware_DW.Delay2_DSTATE[0]);

  /* Abs: '<S129>/Abs' incorporates:
   *  Delay: '<S129>/Delay1'
   *  Sum: '<S129>/Subtract'
   */
  rtb_Filter = fabsf(Main_Firmware_DW.Delay1_DSTATE - rtb_Diff);

  /* SignalConversion generated from: '<S129>/Selector1' incorporates:
   *  Delay: '<S129>/Delay1'
   */
  tmp_0[0] = rtb_Diff;
  tmp_0[1] = Main_Firmware_DW.Delay1_DSTATE;

  /* Selector: '<S129>/Selector1' incorporates:
   *  Abs: '<S129>/Abs'
   *  Abs: '<S129>/Abs1'
   *  Bias: '<S129>/Bias'
   *  Constant: '<S129>/Constant'
   *  Constant: '<S129>/Constant1'
   *  Product: '<S129>/Product'
   *  RelationalOperator: '<S129>/GreaterThan'
   *  RelationalOperator: '<S129>/GreaterThan1'
   */
  rtb_Gain3_idx_0 = tmp_0[(int16_T)((rtb_Iq_error >
    Main_Firmware_P.Constant1_Value_b) * (rtb_Filter >
    Main_Firmware_P.Constant_Value_h) + Main_Firmware_P.Bias_Bias) - 1];
  rtb_Iq_error = rtb_Bias[(int16_T)((rtb_Iq_error >
    Main_Firmware_P.Constant1_Value_b) * (rtb_Filter >
    Main_Firmware_P.Constant_Value_h) + Main_Firmware_P.Bias_Bias) - 1];

  /* Gain: '<Root>/Gain' incorporates:
   *  Selector: '<S129>/Selector1'
   */
  Main_Firmware_B.Gain = rtb_Iq_error * Main_Firmware_P.Gain_Gain_n;

  /* Abs: '<S4>/Abs2' */
  Main_Firmware_B.Abs2 = fabsf(Main_Firmware_B.Gain);

  /* RelationalOperator: '<S183>/Compare' incorporates:
   *  Constant: '<S183>/Constant'
   */
  Main_Firmware_B.Compare_l = (Main_Firmware_B.Abs2 <=
    Main_Firmware_P.CompareToConstant1_const_h);

  /* Constant: '<Root>/Constant4' */
  Main_Firmware_B.Constant4 = Main_Firmware_P.Constant4_Value;

  /* Logic: '<S4>/AND' */
  Main_Firmware_B.AND = ((!Main_Firmware_B.Compare) ||
    (!Main_Firmware_B.Compare_l) || (!(Main_Firmware_B.Constant4 != 0.0)));

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  BitConcat: '<S7>/BitConcat2'
   *  Constant: '<Root>/Constant'
   *  DataTypeConversion: '<S2>/Data Type Conversion2'
   */
  Main_Firmware_B.DataTypeConversion = (int16_T)((uint16_T)Main_Firmware_B.AND <<
    1 | (uint16_T)(Main_Firmware_P.Constant_Value != 0.0));

  /* SwitchCase: '<S2>/Switch Case' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  switch ((int32_T)Main_Firmware_B.DataTypeConversion) {
   case 0L:
    /* Outputs for IfAction SubSystem: '<S2>/Switch Case Action Subsystem2' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S10>/Constant1'
     *  Constant: '<S10>/Constant3'
     *  DataTypeConversion: '<S2>/Data Type Conversion3'
     *  SignalConversion generated from: '<S10>/Out1'
     */
    Main_Firmware_B.Merge[0] = (real32_T)Main_Firmware_B.Gain1[0];
    Main_Firmware_B.Merge[1] = (real32_T)Main_Firmware_B.Gain1[1];
    Main_Firmware_B.Merge[2] = (real32_T)Main_Firmware_B.Gain1[2];
    Main_Firmware_B.Merge[3] = Main_Firmware_P.Constant1_Value_f;
    Main_Firmware_B.Merge[4] = Main_Firmware_P.Constant3_Value;

    /* End of Outputs for SubSystem: '<S2>/Switch Case Action Subsystem2' */

    /* Update for IfAction SubSystem: '<S2>/Switch Case Action Subsystem2' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Update for SwitchCase: '<S2>/Switch Case' */
    srUpdateBC(Main_Firmware_DW.SwitchCaseActionSubsystem2_Subs);

    /* End of Update for SubSystem: '<S2>/Switch Case Action Subsystem2' */
    break;

   case 1L:
    /* Outputs for IfAction SubSystem: '<S2>/Regen Mode' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S9>/Constant'
     *  Constant: '<S9>/Constant2'
     *  Constant: '<S9>/Constant5'
     *  SignalConversion generated from: '<S9>/Out1'
     */
    Main_Firmware_B.Merge[0] = Main_Firmware_P.Constant2_Value_h;
    Main_Firmware_B.Merge[1] = Main_Firmware_P.Constant2_Value_h;
    Main_Firmware_B.Merge[2] = Main_Firmware_P.Constant2_Value_h;
    Main_Firmware_B.Merge[3] = Main_Firmware_P.Constant5_Value;
    Main_Firmware_B.Merge[4] = Main_Firmware_P.Constant_Value_c;

    /* End of Outputs for SubSystem: '<S2>/Regen Mode' */

    /* Update for IfAction SubSystem: '<S2>/Regen Mode' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Update for SwitchCase: '<S2>/Switch Case' */
    srUpdateBC(Main_Firmware_DW.RegenMode_SubsysRanBC);

    /* End of Update for SubSystem: '<S2>/Regen Mode' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S2>/Fault State' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S8>/Constant'
     *  Constant: '<S8>/Constant1'
     *  Constant: '<S8>/Constant3'
     *  Constant: '<S8>/Constant4'
     *  Constant: '<S8>/Constant5'
     *  SignalConversion generated from: '<S8>/Out1'
     */
    Main_Firmware_B.Merge[0] = Main_Firmware_P.Constant3_Value_m;
    Main_Firmware_B.Merge[1] = Main_Firmware_P.Constant4_Value_k;
    Main_Firmware_B.Merge[2] = Main_Firmware_P.Constant5_Value_j;
    Main_Firmware_B.Merge[3] = Main_Firmware_P.Constant1_Value_h;
    Main_Firmware_B.Merge[4] = Main_Firmware_P.Constant_Value_l;

    /* End of Outputs for SubSystem: '<S2>/Fault State' */

    /* Update for IfAction SubSystem: '<S2>/Fault State' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Update for SwitchCase: '<S2>/Switch Case' */
    srUpdateBC(Main_Firmware_DW.FaultState_SubsysRanBC);

    /* End of Update for SubSystem: '<S2>/Fault State' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case' */

  /* Saturate: '<S3>/Saturation' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (Main_Firmware_P.Constant1_Value_k > Main_Firmware_P.speed_max) {
    /* Saturate: '<S3>/Saturation' */
    Main_Firmware_B.Saturation = Main_Firmware_P.speed_max;
  } else if (Main_Firmware_P.Constant1_Value_k <
             Main_Firmware_P.Saturation_LowerSat) {
    /* Saturate: '<S3>/Saturation' */
    Main_Firmware_B.Saturation = Main_Firmware_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S3>/Saturation' */
    Main_Firmware_B.Saturation = Main_Firmware_P.Constant1_Value_k;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* SignalConversion generated from: '<Root>/Mux5' */
  Main_Firmware_B.TmpSignalConversionAtTAQSigLogg[0] = Main_Firmware_B.Gain;
  Main_Firmware_B.TmpSignalConversionAtTAQSigLogg[1] =
    Main_Firmware_B.Saturation;

  /* Sum: '<S3>/Sum6' incorporates:
   *  Gain: '<S3>/Gain7'
   */
  rtb_Filter = Main_Firmware_P.ppair * Main_Firmware_B.Saturation - rtb_Iq_error;

  /* Gain: '<S167>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S159>/Filter'
   *  Gain: '<S157>/Derivative Gain'
   *  Sum: '<S159>/SumD'
   */
  rtb_FilterCoefficient = (Main_Firmware_P.SpeedPID1_D * rtb_Filter -
    Main_Firmware_DW.Filter_DSTATE) * Main_Firmware_P.SpeedPID1_N;

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  if (Main_Firmware_P.Constant2_Value > Main_Firmware_P.Switch_Threshold) {
    /* Sum: '<S173>/Sum' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    Main_Firmware_B.Saturation1 = Main_Firmware_P.Constant3_Value_j;
  } else {
    /* Sum: '<S173>/Sum' incorporates:
     *  Gain: '<S169>/Proportional Gain'
     */
    Main_Firmware_B.Saturation1 = Main_Firmware_P.SpeedPID1_P * rtb_Filter +
      rtb_FilterCoefficient;

    /* Saturate: '<S171>/Saturation' */
    if (Main_Firmware_B.Saturation1 > Main_Firmware_P.Torque_max) {
      /* Sum: '<S173>/Sum' */
      Main_Firmware_B.Saturation1 = Main_Firmware_P.Torque_max;
    } else if (Main_Firmware_B.Saturation1 <
               Main_Firmware_P.SpeedPID1_LowerSaturationLimit) {
      /* Sum: '<S173>/Sum' */
      Main_Firmware_B.Saturation1 =
        Main_Firmware_P.SpeedPID1_LowerSaturationLimit;
    }

    /* End of Saturate: '<S171>/Saturation' */
  }

  /* Saturate: '<S3>/Saturation1' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if (Main_Firmware_B.Saturation1 > Main_Firmware_P.Torque_max) {
    /* Sum: '<S173>/Sum' incorporates:
     *  Saturate: '<S3>/Saturation1'
     */
    Main_Firmware_B.Saturation1 = Main_Firmware_P.Torque_max;
  } else if (Main_Firmware_B.Saturation1 < Main_Firmware_P.Saturation1_LowerSat)
  {
    /* Sum: '<S173>/Sum' incorporates:
     *  Saturate: '<S3>/Saturation1'
     */
    Main_Firmware_B.Saturation1 = Main_Firmware_P.Saturation1_LowerSat;
  }

  /* End of Saturate: '<S3>/Saturation1' */

  /* SignalConversion generated from: '<Root>/Mux4' */
  Main_Firmware_B.TmpSignalConversionAtTAQSigLo_m[0] =
    Main_Firmware_B.Saturation1;
  Main_Firmware_B.TmpSignalConversionAtTAQSigLo_m[1] = 0.0F;

  /* Gain: '<S123>/Gain3' */
  rtb_Filter = Main_Firmware_B.TmpSignalConversionAtGain3Inpor[1];
  TmpSignalConversionAtGain3Inpor =
    Main_Firmware_B.TmpSignalConversionAtGain3Inpor[0];
  TmpSignalConversionAtGain3Inp_0 =
    Main_Firmware_B.TmpSignalConversionAtGain3Inpor[2];
  for (rtb_Compare = 0; rtb_Compare < 3; rtb_Compare++) {
    /* Gain: '<S123>/Gain1' incorporates:
     *  Gain: '<S123>/Gain3'
     */
    Main_Firmware_B.Gain1_l[rtb_Compare] =
      ((Main_Firmware_P.Gain3_Gain_m[rtb_Compare + 3] * rtb_Filter +
        Main_Firmware_P.Gain3_Gain_m[rtb_Compare] *
        TmpSignalConversionAtGain3Inpor) +
       Main_Firmware_P.Gain3_Gain_m[rtb_Compare + 6] *
       TmpSignalConversionAtGain3Inp_0) * Main_Firmware_P.Gain1_Gain_i;
  }

  /* End of Gain: '<S123>/Gain3' */

  /* RelationalOperator: '<S124>/Compare' incorporates:
   *  Constant: '<S122>/Constant'
   *  Constant: '<S124>/Constant'
   */
  rtb_Compare = (Main_Firmware_P.AlphaBetaZerotodq0_Alignment ==
                 Main_Firmware_P.CompareToConstant_const);

  /* Outputs for Enabled SubSystem: '<S122>/Subsystem1' incorporates:
   *  EnablePort: '<S127>/Enable'
   */
  /* RelationalOperator: '<S124>/Compare' */
  if (rtb_Compare > 0) {
    /* Fcn: '<S127>/Fcn' incorporates:
     *  Fcn: '<S127>/Fcn1'
     */
    rtb_Filter = (real32_T)sin(rtb_Gain3_idx_1);
    TmpSignalConversionAtGain3Inpor = (real32_T)cos(rtb_Gain3_idx_1);

    /* Fcn: '<S127>/Fcn' */
    Main_Firmware_B.Fcn = Main_Firmware_B.Gain1_l[0] *
      TmpSignalConversionAtGain3Inpor + Main_Firmware_B.Gain1_l[1] * rtb_Filter;

    /* Fcn: '<S127>/Fcn1' */
    Main_Firmware_B.Fcn1 = -Main_Firmware_B.Gain1_l[0] * rtb_Filter +
      Main_Firmware_B.Gain1_l[1] * TmpSignalConversionAtGain3Inpor;
    srUpdateBC(Main_Firmware_DW.Subsystem1_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<S122>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S122>/Subsystem - pi//2 delay' incorporates:
   *  EnablePort: '<S126>/Enable'
   */
  /* RelationalOperator: '<S125>/Compare' incorporates:
   *  Constant: '<S122>/Constant'
   *  Constant: '<S125>/Constant'
   */
  if (Main_Firmware_P.AlphaBetaZerotodq0_Alignment ==
      Main_Firmware_P.CompareToConstant1_const) {
    /* Fcn: '<S126>/Fcn' incorporates:
     *  Fcn: '<S126>/Fcn1'
     */
    rtb_Filter = (real32_T)cos(rtb_Gain3_idx_1);
    TmpSignalConversionAtGain3Inpor = (real32_T)sin(rtb_Gain3_idx_1);

    /* Fcn: '<S126>/Fcn' */
    Main_Firmware_B.Fcn_n = Main_Firmware_B.Gain1_l[0] *
      TmpSignalConversionAtGain3Inpor - Main_Firmware_B.Gain1_l[1] * rtb_Filter;

    /* Fcn: '<S126>/Fcn1' */
    Main_Firmware_B.Fcn1_f = Main_Firmware_B.Gain1_l[0] * rtb_Filter +
      Main_Firmware_B.Gain1_l[1] * TmpSignalConversionAtGain3Inpor;
    srUpdateBC(Main_Firmware_DW.Subsystempi2delay_SubsysRanBC);
  }

  /* End of RelationalOperator: '<S125>/Compare' */
  /* End of Outputs for SubSystem: '<S122>/Subsystem - pi//2 delay' */

  /* Switch: '<S122>/Switch' incorporates:
   *  RelationalOperator: '<S124>/Compare'
   */
  if (rtb_Compare != 0) {
    /* Switch: '<S122>/Switch' */
    Main_Firmware_B.Switch[0] = Main_Firmware_B.Fcn;
    Main_Firmware_B.Switch[1] = Main_Firmware_B.Fcn1;
  } else {
    /* Switch: '<S122>/Switch' */
    Main_Firmware_B.Switch[0] = Main_Firmware_B.Fcn_n;
    Main_Firmware_B.Switch[1] = Main_Firmware_B.Fcn1_f;
  }

  /* End of Switch: '<S122>/Switch' */

  /* SignalConversion generated from: '<S3>/Park Transform' */
  Main_Firmware_B.TmpSignalConversionAtTAQSigLo_j[0] = Main_Firmware_B.Switch[0];
  Main_Firmware_B.TmpSignalConversionAtTAQSigLo_j[1] = Main_Firmware_B.Switch[1];
  Main_Firmware_B.TmpSignalConversionAtTAQSigLo_j[2] = Main_Firmware_B.Gain1_l[2];

  /* RateTransition generated from: '<Root>/Main Scope2' incorporates:
   *  RateTransition generated from: '<S6>/Main Scope2'
   * */
  tmp = Main_Firmware_M->Timing.RateInteraction.TID1_2;
  if (tmp) {
    Main_Firmware_DW.TmpRTBAtMainScope2Inport3_Buffe[0] =
      Main_Firmware_B.TmpSignalConversionAtGain3Inpor[0];
    Main_Firmware_DW.TmpRTBAtMainScope2Inport3_Buffe[1] =
      Main_Firmware_B.TmpSignalConversionAtGain3Inpor[1];
    Main_Firmware_DW.TmpRTBAtMainScope2Inport3_Buffe[2] =
      Main_Firmware_B.TmpSignalConversionAtGain3Inpor[2];

    /* RateTransition generated from: '<S6>/Main Scope2' */
    Main_Firmware_DW.TmpRTBAtMainScope2Inport3_Buf_o[0] =
      Main_Firmware_B.TmpSignalConversionAtGain3Inpor[0];
    Main_Firmware_DW.TmpRTBAtMainScope2Inport3_Buf_o[1] =
      Main_Firmware_B.TmpSignalConversionAtGain3Inpor[1];
    Main_Firmware_DW.TmpRTBAtMainScope2Inport3_Buf_o[2] =
      Main_Firmware_B.TmpSignalConversionAtGain3Inpor[2];
  }

  /* End of RateTransition generated from: '<Root>/Main Scope2' */
  /* RateTransition generated from: '<S6>/Main Scope2' */
  if (tmp) {
    Main_Firmware_DW.I_ABC_Buffer[0] = Main_Firmware_B.I_ABC[0];
    Main_Firmware_DW.I_ABC_Buffer[1] = Main_Firmware_B.I_ABC[1];
    Main_Firmware_DW.I_ABC_Buffer[2] = Main_Firmware_B.I_ABC[2];
  }

  /* Sum: '<S3>/Sum4' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  rtb_Id_err = Main_Firmware_P.Constant1_Value - Main_Firmware_B.Switch[0];

  /* Sum: '<S3>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S52>/Integrator'
   *  Gain: '<S11>/Gain3'
   *  Gain: '<S11>/Gain4'
   *  Gain: '<S57>/Proportional Gain'
   *  Product: '<S11>/Product1'
   *  Sum: '<S11>/Add1'
   *  Sum: '<S61>/Sum'
   */
  rtb_Vd = (rtb_Iq_error * Main_Firmware_P.Ld * Main_Firmware_B.Switch[0] +
            Main_Firmware_P.lambda * rtb_Gain3_idx_0) +
    (Main_Firmware_P.I_dqPID1_P * rtb_Id_err +
     Main_Firmware_DW.Integrator_DSTATE);

  /* Saturate: '<S3>/Limiter 1' */
  if (rtb_Vd > Main_Firmware_P.Limiter1_UpperSat) {
    rtb_Vd = Main_Firmware_P.Limiter1_UpperSat;
  } else if (rtb_Vd < Main_Firmware_P.Limiter1_LowerSat) {
    rtb_Vd = Main_Firmware_P.Limiter1_LowerSat;
  }

  /* End of Saturate: '<S3>/Limiter 1' */

  /* Gain: '<S3>/Gain6' */
  rtb_Iq_error = Main_Firmware_P.Gain6_Gain * Main_Firmware_B.Saturation1;

  /* Saturate: '<S3>/Limiter1' */
  if (rtb_Iq_error > Main_Firmware_P.Current_max) {
    rtb_Iq_error = Main_Firmware_P.Current_max;
  } else if (rtb_Iq_error < Main_Firmware_P.Limiter1_LowerSat_m) {
    rtb_Iq_error = Main_Firmware_P.Limiter1_LowerSat_m;
  }

  /* Sum: '<S3>/Sum3' incorporates:
   *  Saturate: '<S3>/Limiter1'
   */
  rtb_Iq_error -= Main_Firmware_B.Switch[1];

  /* Sum: '<S3>/Sum7' incorporates:
   *  DiscreteIntegrator: '<S104>/Integrator'
   *  Gain: '<S109>/Proportional Gain'
   *  Gain: '<S11>/Gain1'
   *  Product: '<S11>/Product'
   *  Sum: '<S113>/Sum'
   */
  rtb_Gain3_idx_0 = (Main_Firmware_P.I_dqPID2_P * rtb_Iq_error +
                     Main_Firmware_DW.Integrator_DSTATE_i) +
    Main_Firmware_P.Gain1_Gain_k * rtb_Gain3_idx_0 * Main_Firmware_B.Switch[1];

  /* Saturate: '<S3>/Limiter' */
  if (rtb_Gain3_idx_0 > Main_Firmware_P.Limiter_UpperSat) {
    rtb_Gain3_idx_0 = Main_Firmware_P.Limiter_UpperSat;
  } else if (rtb_Gain3_idx_0 < Main_Firmware_P.Limiter_LowerSat) {
    rtb_Gain3_idx_0 = Main_Firmware_P.Limiter_LowerSat;
  }

  /* End of Saturate: '<S3>/Limiter' */

  /* Sum: '<S14>/Add1' incorporates:
   *  Product: '<S14>/Product'
   *  Product: '<S14>/Product1'
   *  Trigonometry: '<S14>/Trigonometric Function'
   *  Trigonometry: '<S14>/Trigonometric Function1'
   */
  Main_Firmware_B.a = (real32_T)(rtb_Vd * (real32_T)cos(rtb_Gain3_idx_1)) -
    (real32_T)sin(rtb_Gain3_idx_1) * rtb_Gain3_idx_0;

  /* Bias: '<S14>/Bias' */
  rtb_Filter = rtb_Gain3_idx_1 + Main_Firmware_P.Bias_Bias_o;

  /* Sum: '<S14>/Add3' incorporates:
   *  Product: '<S14>/Product2'
   *  Product: '<S14>/Product3'
   *  Trigonometry: '<S14>/Trigonometric Function2'
   *  Trigonometry: '<S14>/Trigonometric Function3'
   */
  Main_Firmware_B.b = (real32_T)(rtb_Vd * (real32_T)cos(rtb_Filter)) - (real32_T)
    sin(rtb_Filter) * rtb_Gain3_idx_0;

  /* Bias: '<S14>/Bias1' */
  rtb_Gain3_idx_1 += Main_Firmware_P.Bias1_Bias_c;

  /* Sum: '<S14>/Add2' incorporates:
   *  Product: '<S14>/Product4'
   *  Product: '<S14>/Product5'
   *  Trigonometry: '<S14>/Trigonometric Function4'
   *  Trigonometry: '<S14>/Trigonometric Function5'
   */
  Main_Firmware_B.c = (real32_T)(rtb_Vd * (real32_T)cos(rtb_Gain3_idx_1)) -
    (real32_T)sin(rtb_Gain3_idx_1) * rtb_Gain3_idx_0;

  /* SignalConversion generated from: '<Root>/From17' */
  Main_Firmware_B.TmpSignalConversionAtTAQSigLo_d[0] = Main_Firmware_B.a;
  Main_Firmware_B.TmpSignalConversionAtTAQSigLo_d[1] = Main_Firmware_B.b;
  Main_Firmware_B.TmpSignalConversionAtTAQSigLo_d[2] = Main_Firmware_B.c;

  /* RateTransition generated from: '<Root>/Main Scope2' */
  if (tmp) {
    Main_Firmware_DW.a_Buffer[0] =
      Main_Firmware_B.TmpSignalConversionAtTAQSigLo_d[0];
    Main_Firmware_DW.a_Buffer[1] =
      Main_Firmware_B.TmpSignalConversionAtTAQSigLo_d[1];
    Main_Firmware_DW.a_Buffer[2] =
      Main_Firmware_B.TmpSignalConversionAtTAQSigLo_d[2];
  }

  /* RateTransition generated from: '<Root>/Main Scope2' */
  if (tmp) {
    Main_Firmware_DW.v_SineCos_Buffer[0] = Main_Firmware_B.Gain1_p[0];
    Main_Firmware_DW.v_SineCos_Buffer[1] = Main_Firmware_B.Gain1_p[1];
  }

  /* RateTransition generated from: '<S6>/Main Scope2' */
  if (tmp) {
    Main_Firmware_DW.v_SineCos_Buffer_m[0] = Main_Firmware_B.Gain1_p[0];
    Main_Firmware_DW.v_SineCos_Buffer_m[1] = Main_Firmware_B.Gain1_p[1];
  }

  /* Gain: '<S101>/Integral Gain' */
  rtb_IntegralGain_p = Main_Firmware_P.I_dqPID2_I * rtb_Iq_error;

  /* Gain: '<S49>/Integral Gain' */
  rtb_IntegralGain = Main_Firmware_P.I_dqPID1_I * rtb_Id_err;

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

  /* S-Function (c2802xpwm): '<S2>/AHI' */
  uint16_T tbprdValue1Outputs = (EPwm1Regs.TBPRD + 1);

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)((uint32_T)(EPwm1Regs.TBPRD + 1) *
      Main_Firmware_B.Merge[0] * 0.01);
  }

  EPwm1Regs.AQCSFRC.bit.CSFA = (uint16_T)Main_Firmware_B.Merge[3];
  EPwm1Regs.AQCSFRC.bit.CSFB = (uint16_T)Main_Firmware_B.Merge[4];

  /* S-Function (c2802xpwm): '<S2>/B1' */
  uint16_T tbprdValue4Outputs = (EPwm4Regs.TBPRD + 1);

  /*-- Update CMPA value for ePWM4 --*/
  {
    EPwm4Regs.CMPA.bit.CMPA = (uint16_T)((uint32_T)(EPwm4Regs.TBPRD + 1) *
      Main_Firmware_B.Merge[1] * 0.01);
  }

  EPwm4Regs.AQCSFRC.bit.CSFA = (uint16_T)Main_Firmware_B.Merge[3];
  EPwm4Regs.AQCSFRC.bit.CSFB = (uint16_T)Main_Firmware_B.Merge[4];

  /* S-Function (c2802xpwm): '<S2>/C1' */
  uint16_T tbprdValue2Outputs = (EPwm2Regs.TBPRD + 1);

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.bit.CMPA = (uint16_T)((uint32_T)(EPwm2Regs.TBPRD + 1) *
      Main_Firmware_B.Merge[2] * 0.01);
  }

  EPwm2Regs.AQCSFRC.bit.CSFA = (uint16_T)Main_Firmware_B.Merge[3];
  EPwm2Regs.AQCSFRC.bit.CSFB = (uint16_T)Main_Firmware_B.Merge[4];

  /* S-Function (c280xgpio_do): '<Root>/Digital Output' */
  {
    if (Main_Firmware_B.LEDHeartbeat) {
      GpioDataRegs.GPASET.bit.GPIO23 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO23 = 1U;
    }
  }

  /* Update for UnitDelay: '<S128>/UD'
   *
   * Block description for '<S128>/UD':
   *
   *  Store in Global RAM
   */
  Main_Firmware_DW.UD_DSTATE = rtb_TSamp;

  /* Update for Delay: '<S129>/Delay1' */
  Main_Firmware_DW.Delay1_DSTATE = rtb_Diff;

  /* Update for Delay: '<S129>/Delay2' */
  Main_Firmware_DW.Delay2_DSTATE[0] = Main_Firmware_DW.Delay2_DSTATE[1];
  Main_Firmware_DW.Delay2_DSTATE[1] = rtb_Diff;

  /* Update for DiscreteIntegrator: '<S159>/Filter' */
  Main_Firmware_DW.Filter_DSTATE += Main_Firmware_P.Filter_gainval *
    rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S52>/Integrator' */
  Main_Firmware_DW.Integrator_DSTATE += Main_Firmware_P.Integrator_gainval *
    rtb_IntegralGain;
  if (Main_Firmware_DW.Integrator_DSTATE > Main_Firmware_P.Integrator_UpperSat)
  {
    Main_Firmware_DW.Integrator_DSTATE = Main_Firmware_P.Integrator_UpperSat;
  } else if (Main_Firmware_DW.Integrator_DSTATE <
             Main_Firmware_P.Integrator_LowerSat) {
    Main_Firmware_DW.Integrator_DSTATE = Main_Firmware_P.Integrator_LowerSat;
  }

  /* End of Update for DiscreteIntegrator: '<S52>/Integrator' */

  /* Update for DiscreteIntegrator: '<S104>/Integrator' */
  Main_Firmware_DW.Integrator_DSTATE_i += Main_Firmware_P.Integrator_gainval_p *
    rtb_IntegralGain_p;
  if (Main_Firmware_DW.Integrator_DSTATE_i >
      Main_Firmware_P.Integrator_UpperSat_b) {
    Main_Firmware_DW.Integrator_DSTATE_i = Main_Firmware_P.Integrator_UpperSat_b;
  } else if (Main_Firmware_DW.Integrator_DSTATE_i <
             Main_Firmware_P.I_dqPID2_LowerIntegratorSaturat) {
    Main_Firmware_DW.Integrator_DSTATE_i =
      Main_Firmware_P.I_dqPID2_LowerIntegratorSaturat;
  }

  /* End of Update for DiscreteIntegrator: '<S104>/Integrator' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Main_Firmware_M->Timing.t[0] =
    ((time_T)(++Main_Firmware_M->Timing.clockTick0)) *
    Main_Firmware_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.0001, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Main_Firmware_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void Main_Firmware_step2(void)         /* Sample time: [0.01s, 0.0s] */
{
  /* RateTransition generated from: '<Root>/Main Scope2' */
  Main_Firmware_B.TmpRTBAtMainScope2Inport3[0] =
    Main_Firmware_DW.TmpRTBAtMainScope2Inport3_Buffe[0];

  /* RateTransition generated from: '<S6>/Main Scope2' */
  Main_Firmware_B.I_ABC_a[0] = Main_Firmware_DW.TmpRTBAtMainScope2Inport3_Buf_o
    [0];

  /* RateTransition generated from: '<S6>/Main Scope2' */
  Main_Firmware_B.I_ABC_av[0] = Main_Firmware_DW.I_ABC_Buffer[0];

  /* RateTransition generated from: '<Root>/Main Scope2' */
  Main_Firmware_B.a_l[0] = Main_Firmware_DW.a_Buffer[0];

  /* RateTransition generated from: '<Root>/Main Scope2' */
  Main_Firmware_B.TmpRTBAtMainScope2Inport3[1] =
    Main_Firmware_DW.TmpRTBAtMainScope2Inport3_Buffe[1];

  /* RateTransition generated from: '<S6>/Main Scope2' */
  Main_Firmware_B.I_ABC_a[1] = Main_Firmware_DW.TmpRTBAtMainScope2Inport3_Buf_o
    [1];

  /* RateTransition generated from: '<S6>/Main Scope2' */
  Main_Firmware_B.I_ABC_av[1] = Main_Firmware_DW.I_ABC_Buffer[1];

  /* RateTransition generated from: '<Root>/Main Scope2' */
  Main_Firmware_B.a_l[1] = Main_Firmware_DW.a_Buffer[1];

  /* RateTransition generated from: '<Root>/Main Scope2' */
  Main_Firmware_B.TmpRTBAtMainScope2Inport3[2] =
    Main_Firmware_DW.TmpRTBAtMainScope2Inport3_Buffe[2];

  /* RateTransition generated from: '<S6>/Main Scope2' */
  Main_Firmware_B.I_ABC_a[2] = Main_Firmware_DW.TmpRTBAtMainScope2Inport3_Buf_o
    [2];

  /* RateTransition generated from: '<S6>/Main Scope2' */
  Main_Firmware_B.I_ABC_av[2] = Main_Firmware_DW.I_ABC_Buffer[2];

  /* RateTransition generated from: '<Root>/Main Scope2' */
  Main_Firmware_B.a_l[2] = Main_Firmware_DW.a_Buffer[2];

  /* RateTransition generated from: '<Root>/Main Scope2' */
  Main_Firmware_B.v_SineCos[0] = Main_Firmware_DW.v_SineCos_Buffer[0];

  /* RateTransition generated from: '<S6>/Main Scope2' */
  Main_Firmware_B.SINECOSADC[0] = Main_Firmware_DW.v_SineCos_Buffer_m[0];

  /* RateTransition generated from: '<Root>/Main Scope2' */
  Main_Firmware_B.v_SineCos[1] = Main_Firmware_DW.v_SineCos_Buffer[1];

  /* RateTransition generated from: '<S6>/Main Scope2' */
  Main_Firmware_B.SINECOSADC[1] = Main_Firmware_DW.v_SineCos_Buffer_m[1];

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Main_Firmware_M->Timing.clockTick2++;
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
  Main_Firmware_M->Sizes.checksums[0] = (1059241522U);
  Main_Firmware_M->Sizes.checksums[1] = (1291648666U);
  Main_Firmware_M->Sizes.checksums[2] = (3359022316U);
  Main_Firmware_M->Sizes.checksums[3] = (3291759375U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    Main_Firmware_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&Main_Firmware_DW.FaultState_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&Main_Firmware_DW.RegenMode_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &Main_Firmware_DW.SwitchCaseActionSubsystem2_Subs;
    systemRan[4] = (sysRanDType *)
      &Main_Firmware_DW.Subsystempi2delay_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&Main_Firmware_DW.Subsystem1_SubsysRanBC;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
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

  /* Start for S-Function (c2802xadc): '<S5>/ADC5' */
  if (MW_adcAInitFlag == 0U) {
    InitAdcA();
    MW_adcAInitFlag = 1U;
  }

  config_ADCA_SOC5 ();

  /* Start for S-Function (c2802xadc): '<S5>/ADC6' */
  if (MW_adcBInitFlag == 0U) {
    InitAdcB();
    MW_adcBInitFlag = 1U;
  }

  config_ADCB_SOC0 ();

  /* Start for S-Function (c2802xadc): '<S5>/ADC7' */
  if (MW_adcCInitFlag == 0U) {
    InitAdcC();
    MW_adcCInitFlag = 1U;
  }

  config_ADCC_SOC2 ();

  /* Start for S-Function (c2802xadc): '<S5>/ADC' */
  if (MW_adcBInitFlag == 0U) {
    InitAdcB();
    MW_adcBInitFlag = 1U;
  }

  config_ADCB_SOC4 ();

  /* Start for S-Function (c2802xadc): '<S5>/ADC1' */
  if (MW_adcAInitFlag == 0U) {
    InitAdcA();
    MW_adcAInitFlag = 1U;
  }

  config_ADCA_SOC6 ();

  /* Start for DiscretePulseGenerator: '<Root>/LED Heartbeat' */
  Main_Firmware_DW.clockTickCounter = 0L;

  /* Start for S-Function (c2802xpwm): '<S2>/AHI' */
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
       EPwm1Regs.AQCSFRC.bit.CSFB               = 2U;          -- Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x9U;

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
       EPwm4Regs.AQCSFRC.bit.CSFA               = 1U;          -- Continuous Software Force on output A
       EPwm4Regs.AQCSFRC.bit.CSFB               = 2U;          -- Continuous Software Force on output B
     */
    EPwm4Regs.AQCSFRC.all = (EPwm4Regs.AQCSFRC.all & ~0xFU) | 0x9U;

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

  /*** Initialize ePWM2 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 0U;          -- Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 3U;          -- Sync Output Select
       EPwm2Regs.TBCTL2.bit.SYNCOSELX           = 0U;          -- Sync Output Select - additional options

       EPwm2Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm2Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm2Regs.TBCTL.bit.PHSEN                = 0U;          -- Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 0U;          -- Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFFU) | 0x30U;
    EPwm2Regs.TBCTL2.all = (EPwm2Regs.TBCTL2.all & ~0xF000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 499U;            // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm2Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm2Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm2Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm2Regs.CMPCTL2.all = (EPwm2Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm2Regs.CMPA.bit.CMPA = 0U;      // Counter Compare A Register
    EPwm2Regs.CMPB.bit.CMPB = 32000U;  // Counter Compare B Register
    EPwm2Regs.CMPC = 300U;             // Counter Compare C Register
    EPwm2Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 150U;
                               // Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 2070U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm2Regs.AQCSFRC.bit.CSFA               = 1U;          -- Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB               = 2U;          -- Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xFU) | 0x9U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE             = 0U;          -- Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL               = 0;          -- Polarity Select Control
       EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm2Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm2Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm2Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm2Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x8FFFU) | 0x0U;
    EPwm2Regs.DBRED.bit.DBRED = (uint16_T)(0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED.bit.DBFED = (uint16_T)(0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCASEL              = 1U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM2SOC Period Select
       EPwm2Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM2SOCB Period Select
       EPwm2Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm2Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM2INTn Period Select
       EPwm2Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF7FU) | 0x1101U;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm2Regs.ETSOCPS.all = (EPwm2Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm2Regs.ETINTPS.all = (EPwm2Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM2B
       EPwm2Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM2A action on DCAEVT1
       EPwm2Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM2A action on DCAEVT2
       EPwm2Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM2B action on DCBEVT1
       EPwm2Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM2B action on DCBEVT2
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm2Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          -- Digital Compare A Low COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm2Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm2Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm2Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm2Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm2Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm2Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm2Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm2Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm2Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm2Regs.EPWMXLINK.bit.TBPRDLINK = 0U;
    EPwm2Regs.EPWMXLINK.bit.CMPALINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPBLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPCLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPDLINK = 1U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm2Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm2Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm2Regs.HRPCTL.all = (EPwm2Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xFFFF3FFFU;
  GpioCtrlRegs.GPADIR.all |= 0x800000U;
  EDIS;

  /* InitializeConditions for UnitDelay: '<S128>/UD'
   *
   * Block description for '<S128>/UD':
   *
   *  Store in Global RAM
   */
  Main_Firmware_DW.UD_DSTATE = Main_Firmware_P.DiscreteDerivativecalc2_ICPrevS;

  /* InitializeConditions for Delay: '<S129>/Delay1' */
  Main_Firmware_DW.Delay1_DSTATE = Main_Firmware_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S129>/Delay2' */
  Main_Firmware_DW.Delay2_DSTATE[0] = Main_Firmware_P.Delay2_InitialCondition;
  Main_Firmware_DW.Delay2_DSTATE[1] = Main_Firmware_P.Delay2_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S159>/Filter' */
  Main_Firmware_DW.Filter_DSTATE =
    Main_Firmware_P.SpeedPID1_InitialConditionForFi;

  /* InitializeConditions for DiscreteIntegrator: '<S52>/Integrator' */
  Main_Firmware_DW.Integrator_DSTATE =
    Main_Firmware_P.I_dqPID1_InitialConditionForInt;

  /* InitializeConditions for DiscreteIntegrator: '<S104>/Integrator' */
  Main_Firmware_DW.Integrator_DSTATE_i =
    Main_Firmware_P.I_dqPID2_InitialConditionForInt;
  Main_Fi_LowpassFilter1_Init(&Main_Firmware_DW.LowpassFilter2);
  Main_Fi_LowpassFilter1_Init(&Main_Firmware_DW.LowpassFilter1);
  Main_Fi_LowpassFilter1_Init(&Main_Firmware_DW.LowpassFilter5);
  Main_Fi_LowpassFilter3_Init(&Main_Firmware_DW.LowpassFilter3);
  Main_Fi_LowpassFilter3_Init(&Main_Firmware_DW.LowpassFilter4);

  /* SystemInitialize for Enabled SubSystem: '<S122>/Subsystem1' */
  /* SystemInitialize for Fcn: '<S127>/Fcn' incorporates:
   *  Outport: '<S127>/dq'
   */
  Main_Firmware_B.Fcn = Main_Firmware_P.dq_Y0_c[0];

  /* SystemInitialize for Fcn: '<S127>/Fcn1' incorporates:
   *  Outport: '<S127>/dq'
   */
  Main_Firmware_B.Fcn1 = Main_Firmware_P.dq_Y0_c[1];

  /* End of SystemInitialize for SubSystem: '<S122>/Subsystem1' */

  /* SystemInitialize for Enabled SubSystem: '<S122>/Subsystem - pi//2 delay' */
  /* SystemInitialize for Fcn: '<S126>/Fcn' incorporates:
   *  Outport: '<S126>/dq'
   */
  Main_Firmware_B.Fcn_n = Main_Firmware_P.dq_Y0[0];

  /* SystemInitialize for Fcn: '<S126>/Fcn1' incorporates:
   *  Outport: '<S126>/dq'
   */
  Main_Firmware_B.Fcn1_f = Main_Firmware_P.dq_Y0[1];

  /* End of SystemInitialize for SubSystem: '<S122>/Subsystem - pi//2 delay' */
}

/* Model terminate function */
void Main_Firmware_terminate(void)
{
  Main_Fi_LowpassFilter1_Term(&Main_Firmware_DW.LowpassFilter2);
  Main_Fi_LowpassFilter1_Term(&Main_Firmware_DW.LowpassFilter1);
  Main_Fi_LowpassFilter1_Term(&Main_Firmware_DW.LowpassFilter5);
  Main_Fi_LowpassFilter3_Term(&Main_Firmware_DW.LowpassFilter3);
  Main_Fi_LowpassFilter3_Term(&Main_Firmware_DW.LowpassFilter4);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
