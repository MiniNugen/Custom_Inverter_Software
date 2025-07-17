/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware.c
 *
 * Code generated for Simulink model 'Main_Firmware'.
 *
 * Model version                  : 2.37
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Jul 17 17:20:37 2025
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
  real_T rtb_Id_err;
  int32_T rtb_Bias_i_tmp;
  real32_T rtb_Bias[2];
  real32_T rtb_Diff_0[2];
  real32_T rtb_Abs1_idx_2;
  real32_T rtb_Abs2;
  real32_T rtb_Abs_idx_0;
  real32_T rtb_Abs_idx_1;
  real32_T rtb_Abs_idx_2;
  real32_T rtb_Diff;
  real32_T rtb_Electricalspeed;
  real32_T rtb_Filter;
  real32_T rtb_FilterCoefficient;
  real32_T rtb_TSamp;
  real32_T rtb_Vd;
  real32_T rtb_Vq;
  real32_T rtb_a;
  real32_T rtb_b;
  int16_T rtb_Compare;

  /* Reset subsysRan breadcrumbs */
  srClearBC(Main_Firmware_DW.Subsystempi2delay_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Main_Firmware_DW.Subsystem1_SubsysRanBC);

  /* Saturate: '<S1>/Saturation' incorporates:
   *  Delay: '<S1>/Sampling Delay'
   */
  if (Main_Firmware_DW.SamplingDelay_DSTATE[0] >
      Main_Firmware_P.Saturation_UpperSat) {
    rtb_Id_err = Main_Firmware_P.Saturation_UpperSat;
  } else if (Main_Firmware_DW.SamplingDelay_DSTATE[0] <
             Main_Firmware_P.Saturation_LowerSat) {
    rtb_Id_err = Main_Firmware_P.Saturation_LowerSat;
  } else {
    rtb_Id_err = Main_Firmware_DW.SamplingDelay_DSTATE[0];
  }

  /* Gain: '<S2>/Gain1' incorporates:
   *  Saturate: '<S1>/Saturation'
   */
  Main_Firmware_B.Gain1[0] = Main_Firmware_P.Gain1_Gain * (real32_T)rtb_Id_err;

  /* Saturate: '<S1>/Saturation' incorporates:
   *  Delay: '<S1>/Sampling Delay'
   */
  if (Main_Firmware_DW.SamplingDelay_DSTATE[1] >
      Main_Firmware_P.Saturation_UpperSat) {
    rtb_Id_err = Main_Firmware_P.Saturation_UpperSat;
  } else if (Main_Firmware_DW.SamplingDelay_DSTATE[1] <
             Main_Firmware_P.Saturation_LowerSat) {
    rtb_Id_err = Main_Firmware_P.Saturation_LowerSat;
  } else {
    rtb_Id_err = Main_Firmware_DW.SamplingDelay_DSTATE[1];
  }

  /* Gain: '<S2>/Gain1' incorporates:
   *  Saturate: '<S1>/Saturation'
   */
  Main_Firmware_B.Gain1[1] = Main_Firmware_P.Gain1_Gain * (real32_T)rtb_Id_err;

  /* Saturate: '<S1>/Saturation' incorporates:
   *  Delay: '<S1>/Sampling Delay'
   */
  if (Main_Firmware_DW.SamplingDelay_DSTATE[2] >
      Main_Firmware_P.Saturation_UpperSat) {
    rtb_Id_err = Main_Firmware_P.Saturation_UpperSat;
  } else if (Main_Firmware_DW.SamplingDelay_DSTATE[2] <
             Main_Firmware_P.Saturation_LowerSat) {
    rtb_Id_err = Main_Firmware_P.Saturation_LowerSat;
  } else {
    rtb_Id_err = Main_Firmware_DW.SamplingDelay_DSTATE[2];
  }

  /* Gain: '<S2>/Gain1' incorporates:
   *  Saturate: '<S1>/Saturation'
   */
  Main_Firmware_B.Gain1[2] = Main_Firmware_P.Gain1_Gain * (real32_T)rtb_Id_err;

  /* S-Function (c2802xadc): '<S5>/ADC2' */
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

  /* S-Function (c2802xadc): '<S5>/ADC3' */
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

  /* S-Function (c2802xadc): '<S5>/ADC4' */
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

  /* Gain: '<S5>/Gain2' */
  Main_Firmware_B.Gain2[0] = Main_Firmware_P.Gain2_Gain * Main_Firmware_B.ADC2;
  Main_Firmware_B.Gain2[1] = Main_Firmware_P.Gain2_Gain * Main_Firmware_B.ADC3;
  Main_Firmware_B.Gain2[2] = Main_Firmware_P.Gain2_Gain * Main_Firmware_B.ADC4;

  /* Gain: '<S6>/Gain' incorporates:
   *  Bias: '<S6>/Bias1'
   */
  Main_Firmware_B.I_ABC[0] = (Main_Firmware_B.Gain2[0] +
    Main_Firmware_P.Bias1_Bias) * Main_Firmware_P.Gain_Gain;
  Main_Firmware_B.I_ABC[1] = (Main_Firmware_B.Gain2[1] +
    Main_Firmware_P.Bias1_Bias) * Main_Firmware_P.Gain_Gain;
  Main_Firmware_B.I_ABC[2] = (Main_Firmware_B.Gain2[2] +
    Main_Firmware_P.Bias1_Bias) * Main_Firmware_P.Gain_Gain;

  /* Gain: '<S119>/Gain3' */
  rtb_Electricalspeed = Main_Firmware_B.I_ABC[1];
  rtb_Abs_idx_0 = Main_Firmware_B.I_ABC[0];
  rtb_Abs_idx_1 = Main_Firmware_B.I_ABC[2];
  for (rtb_Compare = 0; rtb_Compare < 3; rtb_Compare++) {
    /* Gain: '<S119>/Gain1' incorporates:
     *  Gain: '<S119>/Gain3'
     */
    Main_Firmware_B.Gain1_f[rtb_Compare] =
      ((Main_Firmware_P.Gain3_Gain[rtb_Compare + 3] * rtb_Electricalspeed +
        Main_Firmware_P.Gain3_Gain[rtb_Compare] * rtb_Abs_idx_0) +
       Main_Firmware_P.Gain3_Gain[rtb_Compare + 6] * rtb_Abs_idx_1) *
      Main_Firmware_P.Gain1_Gain_l;
  }

  /* End of Gain: '<S119>/Gain3' */

  /* RelationalOperator: '<S120>/Compare' incorporates:
   *  Constant: '<S118>/Constant'
   *  Constant: '<S120>/Constant'
   */
  rtb_Compare = (Main_Firmware_P.AlphaBetaZerotodq0_Alignment ==
                 Main_Firmware_P.CompareToConstant_const);

  /* S-Function (c2802xadc): '<S5>/ADC' */
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

  /* S-Function (c2802xadc): '<S5>/ADC1' */
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

  /* Gain: '<S5>/Gain1' */
  Main_Firmware_B.Gain1_g[0] = Main_Firmware_P.Gain1_Gain_a *
    Main_Firmware_B.VCos;
  Main_Firmware_B.Gain1_g[1] = Main_Firmware_P.Gain1_Gain_a *
    Main_Firmware_B.VSine;

  /* Gain: '<S3>/Gain2' incorporates:
   *  Bias: '<S6>/Bias'
   *  Constant: '<S3>/Const'
   *  Product: '<S6>/Divide'
   *  Sum: '<S3>/Sum'
   *  Trigonometry: '<S6>/Atan'
   */
  rtb_Electricalspeed = ((real32_T)atan((Main_Firmware_B.Gain1_g[0] +
    Main_Firmware_P.Bias_Bias_g) / (Main_Firmware_B.Gain1_g[1] +
    Main_Firmware_P.Bias_Bias_g)) - (real32_T)Main_Firmware_P.Encoder_Offset) *
    Main_Firmware_P.ppair;

  /* Outputs for Enabled SubSystem: '<S118>/Subsystem1' incorporates:
   *  EnablePort: '<S123>/Enable'
   */
  /* RelationalOperator: '<S120>/Compare' */
  if (rtb_Compare > 0) {
    /* Fcn: '<S123>/Fcn' incorporates:
     *  Fcn: '<S123>/Fcn1'
     */
    rtb_Abs_idx_0 = (real32_T)sin(rtb_Electricalspeed);
    rtb_Abs_idx_1 = (real32_T)cos(rtb_Electricalspeed);

    /* Fcn: '<S123>/Fcn' */
    Main_Firmware_B.Fcn = Main_Firmware_B.Gain1_f[0] * rtb_Abs_idx_1 +
      Main_Firmware_B.Gain1_f[1] * rtb_Abs_idx_0;

    /* Fcn: '<S123>/Fcn1' */
    Main_Firmware_B.Fcn1 = -Main_Firmware_B.Gain1_f[0] * rtb_Abs_idx_0 +
      Main_Firmware_B.Gain1_f[1] * rtb_Abs_idx_1;
    srUpdateBC(Main_Firmware_DW.Subsystem1_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<S118>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S118>/Subsystem - pi//2 delay' incorporates:
   *  EnablePort: '<S122>/Enable'
   */
  /* RelationalOperator: '<S121>/Compare' incorporates:
   *  Constant: '<S118>/Constant'
   *  Constant: '<S121>/Constant'
   */
  if (Main_Firmware_P.AlphaBetaZerotodq0_Alignment ==
      Main_Firmware_P.CompareToConstant1_const) {
    /* Fcn: '<S122>/Fcn' incorporates:
     *  Fcn: '<S122>/Fcn1'
     */
    rtb_Abs_idx_0 = (real32_T)cos(rtb_Electricalspeed);
    rtb_Abs_idx_1 = (real32_T)sin(rtb_Electricalspeed);

    /* Fcn: '<S122>/Fcn' */
    Main_Firmware_B.Fcn_j = Main_Firmware_B.Gain1_f[0] * rtb_Abs_idx_1 -
      Main_Firmware_B.Gain1_f[1] * rtb_Abs_idx_0;

    /* Fcn: '<S122>/Fcn1' */
    Main_Firmware_B.Fcn1_e = Main_Firmware_B.Gain1_f[0] * rtb_Abs_idx_0 +
      Main_Firmware_B.Gain1_f[1] * rtb_Abs_idx_1;
    srUpdateBC(Main_Firmware_DW.Subsystempi2delay_SubsysRanBC);
  }

  /* End of RelationalOperator: '<S121>/Compare' */
  /* End of Outputs for SubSystem: '<S118>/Subsystem - pi//2 delay' */

  /* Switch: '<S118>/Switch' incorporates:
   *  RelationalOperator: '<S120>/Compare'
   */
  if (rtb_Compare != 0) {
    /* Switch: '<S118>/Switch' */
    Main_Firmware_B.Switch[0] = Main_Firmware_B.Fcn;
    Main_Firmware_B.Switch[1] = Main_Firmware_B.Fcn1;
  } else {
    /* Switch: '<S118>/Switch' */
    Main_Firmware_B.Switch[0] = Main_Firmware_B.Fcn_j;
    Main_Firmware_B.Switch[1] = Main_Firmware_B.Fcn1_e;
  }

  /* End of Switch: '<S118>/Switch' */

  /* SignalConversion generated from: '<S3>/Park Transform' */
  Main_Firmware_B.TmpSignalConversionAtTAQSigLogg[0] = Main_Firmware_B.Switch[0];
  Main_Firmware_B.TmpSignalConversionAtTAQSigLogg[1] = Main_Firmware_B.Switch[1];
  Main_Firmware_B.TmpSignalConversionAtTAQSigLogg[2] = Main_Firmware_B.Gain1_f[2];

  /* Abs: '<S4>/Abs' */
  rtb_Abs_idx_0 = fabsf(Main_Firmware_B.I_ABC[0]);
  rtb_Abs_idx_1 = fabsf(Main_Firmware_B.I_ABC[1]);
  rtb_Abs_idx_2 = fabsf(Main_Firmware_B.I_ABC[2]);

  /* Sum: '<S3>/Sum4' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  rtb_Id_err = Main_Firmware_P.Constant1_Value - Main_Firmware_B.Switch[0];

  /* SampleTimeMath: '<S124>/TSamp'
   *
   * About '<S124>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = rtb_Electricalspeed * Main_Firmware_P.TSamp_WtEt;

  /* Sum: '<S124>/Diff' incorporates:
   *  UnitDelay: '<S124>/UD'
   *
   * Block description for '<S124>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S124>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Diff = rtb_TSamp - Main_Firmware_DW.UD_DSTATE;

  /* SignalConversion generated from: '<S125>/Selector1' incorporates:
   *  Delay: '<S125>/Delay1'
   */
  rtb_Bias[0] = rtb_Diff;
  rtb_Bias[1] = Main_Firmware_DW.Delay1_DSTATE;

  /* Bias: '<S125>/Bias' incorporates:
   *  Abs: '<S125>/Abs'
   *  Abs: '<S125>/Abs1'
   *  Constant: '<S125>/Constant'
   *  Constant: '<S125>/Constant1'
   *  Delay: '<S125>/Delay1'
   *  Delay: '<S125>/Delay2'
   *  Product: '<S125>/Product'
   *  RelationalOperator: '<S125>/GreaterThan'
   *  RelationalOperator: '<S125>/GreaterThan1'
   *  Sum: '<S125>/Subtract'
   *  Sum: '<S125>/Subtract1'
   */
  rtb_Bias_i_tmp = (fabsf(rtb_Diff - Main_Firmware_DW.Delay2_DSTATE[0]) >
                    Main_Firmware_P.Constant1_Value_i) * (fabsf
    (Main_Firmware_DW.Delay1_DSTATE - rtb_Diff) >
    Main_Firmware_P.Constant_Value_f) + Main_Firmware_P.Bias_Bias;

  /* SignalConversion generated from: '<S125>/Selector1' incorporates:
   *  Delay: '<S125>/Delay1'
   */
  rtb_Diff_0[0] = rtb_Diff;
  rtb_Diff_0[1] = Main_Firmware_DW.Delay1_DSTATE;

  /* Selector: '<S125>/Selector1' */
  rtb_Abs2 = rtb_Diff_0[(int16_T)rtb_Bias_i_tmp - 1];

  /* Sum: '<S57>/Sum' incorporates:
   *  DiscreteIntegrator: '<S48>/Integrator'
   *  Gain: '<S53>/Proportional Gain'
   */
  rtb_a = (real32_T)(Main_Firmware_P.I_dqPID1_P * rtb_Id_err) +
    Main_Firmware_DW.Integrator_DSTATE;

  /* Saturate: '<S55>/Saturation' */
  if (rtb_a > Main_Firmware_P.Voltage_max) {
    rtb_a = Main_Firmware_P.Voltage_max;
  } else if (rtb_a < Main_Firmware_P.I_dqPID1_LowerSaturationLimit) {
    rtb_a = Main_Firmware_P.I_dqPID1_LowerSaturationLimit;
  }

  /* Selector: '<S125>/Selector1' */
  rtb_FilterCoefficient = rtb_Bias[(int16_T)rtb_Bias_i_tmp - 1];

  /* Sum: '<S3>/Sum1' incorporates:
   *  Gain: '<S7>/Gain3'
   *  Gain: '<S7>/Gain4'
   *  Product: '<S7>/Product1'
   *  Saturate: '<S55>/Saturation'
   *  Selector: '<S125>/Selector1'
   *  Sum: '<S7>/Add1'
   */
  rtb_Vd = (rtb_FilterCoefficient * Main_Firmware_P.Ld * Main_Firmware_B.Switch
            [0] + Main_Firmware_P.lambda * rtb_Abs2) + rtb_a;

  /* Saturate: '<S3>/Limiter 1' */
  if (rtb_Vd > Main_Firmware_P.Voltage_max) {
    rtb_Vd = Main_Firmware_P.Voltage_max;
  } else if (rtb_Vd < Main_Firmware_P.Limiter1_LowerSat) {
    rtb_Vd = Main_Firmware_P.Limiter1_LowerSat;
  }

  /* End of Saturate: '<S3>/Limiter 1' */

  /* Saturate: '<S3>/Saturation' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (Main_Firmware_P.Constant1_Value_n > Main_Firmware_P.speed_max) {
    rtb_Filter = Main_Firmware_P.speed_max;
  } else if (Main_Firmware_P.Constant1_Value_n <
             Main_Firmware_P.Saturation_LowerSat_a) {
    rtb_Filter = Main_Firmware_P.Saturation_LowerSat_a;
  } else {
    rtb_Filter = Main_Firmware_P.Constant1_Value_n;
  }

  /* Sum: '<S3>/Sum6' incorporates:
   *  Gain: '<S3>/Gain7'
   *  Saturate: '<S3>/Saturation'
   */
  rtb_Filter = Main_Firmware_P.ppair * rtb_Filter - rtb_FilterCoefficient;

  /* Gain: '<S163>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S155>/Filter'
   *  Gain: '<S153>/Derivative Gain'
   *  Sum: '<S155>/SumD'
   */
  rtb_FilterCoefficient = (Main_Firmware_P.SpeedPID1_D * rtb_Filter -
    Main_Firmware_DW.Filter_DSTATE) * Main_Firmware_P.SpeedPID1_N;

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   */
  if (Main_Firmware_P.Constant2_Value > Main_Firmware_P.Switch_Threshold) {
    rtb_a = Main_Firmware_P.Constant3_Value;
  } else {
    /* Sum: '<S169>/Sum' incorporates:
     *  Gain: '<S165>/Proportional Gain'
     */
    rtb_a = Main_Firmware_P.SpeedPID1_P * rtb_Filter + rtb_FilterCoefficient;

    /* Saturate: '<S167>/Saturation' */
    if (rtb_a > Main_Firmware_P.Torque_max) {
      rtb_a = Main_Firmware_P.Torque_max;
    } else if (rtb_a < Main_Firmware_P.SpeedPID1_LowerSaturationLimit) {
      rtb_a = Main_Firmware_P.SpeedPID1_LowerSaturationLimit;
    }

    /* End of Saturate: '<S167>/Saturation' */
  }

  /* Saturate: '<S3>/Saturation1' incorporates:
   *  Switch: '<S3>/Switch'
   */
  if (rtb_a > Main_Firmware_P.Torque_max) {
    rtb_a = Main_Firmware_P.Torque_max;
  } else if (rtb_a < Main_Firmware_P.Saturation1_LowerSat) {
    rtb_a = Main_Firmware_P.Saturation1_LowerSat;
  }

  /* Gain: '<S3>/Gain6' incorporates:
   *  Saturate: '<S3>/Saturation1'
   */
  rtb_a *= Main_Firmware_P.Gain6_Gain;

  /* Saturate: '<S3>/Limiter1' */
  if (rtb_a > Main_Firmware_P.Current_max) {
    rtb_a = Main_Firmware_P.Current_max;
  } else if (rtb_a < Main_Firmware_P.Limiter1_LowerSat_j) {
    rtb_a = Main_Firmware_P.Limiter1_LowerSat_j;
  }

  /* Sum: '<S3>/Sum3' incorporates:
   *  Saturate: '<S3>/Limiter1'
   */
  rtb_Filter = rtb_a - Main_Firmware_B.Switch[1];

  /* Sum: '<S109>/Sum' incorporates:
   *  DiscreteIntegrator: '<S100>/Integrator'
   *  Gain: '<S105>/Proportional Gain'
   */
  rtb_a = Main_Firmware_P.I_dqPID2_P * rtb_Filter +
    Main_Firmware_DW.Integrator_DSTATE_m;

  /* Saturate: '<S107>/Saturation' */
  if (rtb_a > Main_Firmware_P.Voltage_max) {
    rtb_a = Main_Firmware_P.Voltage_max;
  } else if (rtb_a < Main_Firmware_P.I_dqPID2_LowerSaturationLimit) {
    rtb_a = Main_Firmware_P.I_dqPID2_LowerSaturationLimit;
  }

  /* Sum: '<S3>/Sum7' incorporates:
   *  Gain: '<S7>/Gain1'
   *  Product: '<S7>/Product'
   *  Saturate: '<S107>/Saturation'
   */
  rtb_Vq = Main_Firmware_P.Gain1_Gain_n * rtb_Abs2 * Main_Firmware_B.Switch[1] +
    rtb_a;

  /* Saturate: '<S3>/Limiter' */
  if (rtb_Vq > Main_Firmware_P.Voltage_max) {
    rtb_Vq = Main_Firmware_P.Voltage_max;
  } else if (rtb_Vq < Main_Firmware_P.Limiter_LowerSat) {
    rtb_Vq = Main_Firmware_P.Limiter_LowerSat;
  }

  /* End of Saturate: '<S3>/Limiter' */

  /* Sum: '<S10>/Add1' incorporates:
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product1'
   *  Trigonometry: '<S10>/Trigonometric Function'
   *  Trigonometry: '<S10>/Trigonometric Function1'
   */
  rtb_a = rtb_Vd * (real32_T)cos(rtb_Electricalspeed) - (real32_T)sin
    (rtb_Electricalspeed) * rtb_Vq;

  /* Bias: '<S10>/Bias' */
  rtb_b = rtb_Electricalspeed + Main_Firmware_P.Bias_Bias_e;

  /* Sum: '<S10>/Add3' incorporates:
   *  Product: '<S10>/Product2'
   *  Product: '<S10>/Product3'
   *  Trigonometry: '<S10>/Trigonometric Function2'
   *  Trigonometry: '<S10>/Trigonometric Function3'
   */
  rtb_b = rtb_Vd * (real32_T)cos(rtb_b) - (real32_T)sin(rtb_b) * rtb_Vq;

  /* Bias: '<S10>/Bias1' */
  rtb_Electricalspeed += Main_Firmware_P.Bias1_Bias_k;

  /* Sum: '<S10>/Add2' incorporates:
   *  Product: '<S10>/Product4'
   *  Product: '<S10>/Product5'
   *  Trigonometry: '<S10>/Trigonometric Function4'
   *  Trigonometry: '<S10>/Trigonometric Function5'
   */
  rtb_Electricalspeed = rtb_Vd * (real32_T)cos(rtb_Electricalspeed) - (real32_T)
    sin(rtb_Electricalspeed) * rtb_Vq;

  /* Abs: '<S4>/Abs1' */
  rtb_Vd = fabsf(rtb_a);
  rtb_Vq = fabsf(rtb_b);
  rtb_Abs1_idx_2 = fabsf(rtb_Electricalspeed);

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant7'
   *  Delay: '<S1>/Sampling Delay'
   *  Gain: '<S1>/Gain5'
   */
  Main_Firmware_DW.SamplingDelay_DSTATE[0] = Main_Firmware_P.Gain5_Gain * rtb_a
    + Main_Firmware_P.Constant7_Value;
  Main_Firmware_DW.SamplingDelay_DSTATE[1] = Main_Firmware_P.Gain5_Gain * rtb_b
    + Main_Firmware_P.Constant7_Value;
  Main_Firmware_DW.SamplingDelay_DSTATE[2] = Main_Firmware_P.Gain5_Gain *
    rtb_Electricalspeed + Main_Firmware_P.Constant7_Value;

  /* MinMax: '<S4>/Max' */
  if ((rtb_Abs_idx_0 >= rtb_Abs_idx_1) || rtIsNaNF(rtb_Abs_idx_1)) {
    rtb_Abs_idx_1 = rtb_Abs_idx_0;
  }

  /* MinMax: '<S4>/Max1' */
  if ((rtb_Vd >= rtb_Vq) || rtIsNaNF(rtb_Vq)) {
    rtb_Vq = rtb_Vd;
  }

  /* MinMax: '<S4>/Max' */
  if ((rtb_Abs_idx_1 >= rtb_Abs_idx_2) || rtIsNaNF(rtb_Abs_idx_2)) {
    rtb_Abs_idx_2 = rtb_Abs_idx_1;
  }

  /* MinMax: '<S4>/Max1' */
  if ((rtb_Vq >= rtb_Abs1_idx_2) || rtIsNaNF(rtb_Abs1_idx_2)) {
    rtb_Abs1_idx_2 = rtb_Vq;
  }

  /* Logic: '<S4>/AND' incorporates:
   *  Abs: '<S4>/Abs2'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<S178>/Constant'
   *  Constant: '<S179>/Constant'
   *  Constant: '<S180>/Constant'
   *  Gain: '<Root>/Gain'
   *  MinMax: '<S4>/Max'
   *  MinMax: '<S4>/Max1'
   *  RelationalOperator: '<S178>/Compare'
   *  RelationalOperator: '<S179>/Compare'
   *  RelationalOperator: '<S180>/Compare'
   */
  Main_Firmware_B.AND = ((!(rtb_Abs_idx_2 <=
    Main_Firmware_P.CompareToConstant_const_m)) || (!(fabsf
    (Main_Firmware_P.Gain_Gain_d * rtb_Abs2) <=
    Main_Firmware_P.CompareToConstant1_const_j)) || (!(rtb_Abs1_idx_2 <=
    Main_Firmware_P.CompareToConstant3_const)) ||
    (!(Main_Firmware_P.Constant4_Value != 0.0)));

  /* S-Function (c2802xpwm): '<S2>/AHI' incorporates:
   *  Constant: '<S2>/Constant'
   */
  uint16_T tbprdValue1Outputs = (EPwm1Regs.TBPRD + 1);

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)((uint32_T)(EPwm1Regs.TBPRD + 1) *
      Main_Firmware_P.Constant_Value * 0.01);
  }

  EPwm1Regs.AQCSFRC.bit.CSFA = (uint16_T)0U;
  EPwm1Regs.AQCSFRC.bit.CSFB = (uint16_T)0U;

  /* S-Function (c2802xpwm): '<S2>/B1' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  uint16_T tbprdValue4Outputs = (EPwm4Regs.TBPRD + 1);

  /*-- Update CMPA value for ePWM4 --*/
  {
    EPwm4Regs.CMPA.bit.CMPA = (uint16_T)((uint32_T)(EPwm4Regs.TBPRD + 1) *
      Main_Firmware_P.Constant1_Value_p * 0.01);
  }

  EPwm4Regs.AQCSFRC.bit.CSFA = (uint16_T)0U;
  EPwm4Regs.AQCSFRC.bit.CSFB = (uint16_T)0U;

  /* S-Function (c2802xpwm): '<S2>/C1' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  uint16_T tbprdValue2Outputs = (EPwm2Regs.TBPRD + 1);

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.bit.CMPA = (uint16_T)((uint32_T)(EPwm2Regs.TBPRD + 1) *
      Main_Firmware_P.Constant2_Value_m * 0.01);
  }

  EPwm2Regs.AQCSFRC.bit.CSFA = (uint16_T)0U;
  EPwm2Regs.AQCSFRC.bit.CSFB = (uint16_T)0U;

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

  /* Update for DiscreteIntegrator: '<S48>/Integrator' incorporates:
   *  Gain: '<S45>/Integral Gain'
   */
  Main_Firmware_DW.Integrator_DSTATE += (real32_T)(Main_Firmware_P.I_dqPID1_I *
    rtb_Id_err) * Main_Firmware_P.Integrator_gainval;
  if (Main_Firmware_DW.Integrator_DSTATE > Main_Firmware_P.Voltage_max) {
    Main_Firmware_DW.Integrator_DSTATE = Main_Firmware_P.Voltage_max;
  } else if (Main_Firmware_DW.Integrator_DSTATE <
             Main_Firmware_P.I_dqPID1_LowerIntegratorSaturat) {
    Main_Firmware_DW.Integrator_DSTATE =
      Main_Firmware_P.I_dqPID1_LowerIntegratorSaturat;
  }

  /* End of Update for DiscreteIntegrator: '<S48>/Integrator' */

  /* Update for UnitDelay: '<S124>/UD'
   *
   * Block description for '<S124>/UD':
   *
   *  Store in Global RAM
   */
  Main_Firmware_DW.UD_DSTATE = rtb_TSamp;

  /* Update for Delay: '<S125>/Delay1' */
  Main_Firmware_DW.Delay1_DSTATE = rtb_Diff;

  /* Update for Delay: '<S125>/Delay2' */
  Main_Firmware_DW.Delay2_DSTATE[0] = Main_Firmware_DW.Delay2_DSTATE[1];
  Main_Firmware_DW.Delay2_DSTATE[1] = rtb_Diff;

  /* Update for DiscreteIntegrator: '<S155>/Filter' */
  Main_Firmware_DW.Filter_DSTATE += Main_Firmware_P.Filter_gainval *
    rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S100>/Integrator' incorporates:
   *  Gain: '<S97>/Integral Gain'
   */
  Main_Firmware_DW.Integrator_DSTATE_m += Main_Firmware_P.I_dqPID2_I *
    rtb_Filter * Main_Firmware_P.Integrator_gainval_n;
  if (Main_Firmware_DW.Integrator_DSTATE_m > Main_Firmware_P.Voltage_max) {
    Main_Firmware_DW.Integrator_DSTATE_m = Main_Firmware_P.Voltage_max;
  } else if (Main_Firmware_DW.Integrator_DSTATE_m <
             Main_Firmware_P.I_dqPID2_LowerIntegratorSaturat) {
    Main_Firmware_DW.Integrator_DSTATE_m =
      Main_Firmware_P.I_dqPID2_LowerIntegratorSaturat;
  }

  /* End of Update for DiscreteIntegrator: '<S100>/Integrator' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Main_Firmware_M->Timing.taskTime0 =
    ((time_T)(++Main_Firmware_M->Timing.clockTick0)) *
    Main_Firmware_M->Timing.stepSize0;
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
  rtmSetTFinal(Main_Firmware_M, -1);
  Main_Firmware_M->Timing.stepSize0 = 0.0001;

  /* External mode info */
  Main_Firmware_M->Sizes.checksums[0] = (252938674U);
  Main_Firmware_M->Sizes.checksums[1] = (2196628880U);
  Main_Firmware_M->Sizes.checksums[2] = (960147150U);
  Main_Firmware_M->Sizes.checksums[3] = (3432762314U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    Main_Firmware_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &Main_Firmware_DW.Subsystempi2delay_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&Main_Firmware_DW.Subsystem1_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
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

  /* Start for S-Function (c2802xadc): '<S5>/ADC2' */
  if (MW_adcCInitFlag == 0U) {
    InitAdcC();
    MW_adcCInitFlag = 1U;
  }

  config_ADCC_SOC1 ();

  /* Start for S-Function (c2802xadc): '<S5>/ADC3' */
  if (MW_adcCInitFlag == 0U) {
    InitAdcC();
    MW_adcCInitFlag = 1U;
  }

  config_ADCC_SOC2 ();

  /* Start for S-Function (c2802xadc): '<S5>/ADC4' */
  if (MW_adcAInitFlag == 0U) {
    InitAdcA();
    MW_adcAInitFlag = 1U;
  }

  config_ADCA_SOC3 ();

  /* Start for S-Function (c2802xadc): '<S5>/ADC' */
  if (MW_adcBInitFlag == 0U) {
    InitAdcB();
    MW_adcBInitFlag = 1U;
  }

  config_ADCB_SOC0 ();

  /* Start for S-Function (c2802xadc): '<S5>/ADC1' */
  if (MW_adcAInitFlag == 0U) {
    InitAdcA();
    MW_adcAInitFlag = 1U;
  }

  config_ADCA_SOC8 ();

  /* Start for S-Function (c2802xpwm): '<S2>/AHI' incorporates:
   *  Constant: '<S2>/Constant'
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

  /* Start for S-Function (c2802xpwm): '<S2>/B1' incorporates:
   *  Constant: '<S2>/Constant1'
   */
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

  /* Start for S-Function (c2802xpwm): '<S2>/C1' incorporates:
   *  Constant: '<S2>/Constant2'
   */
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

  /* Start for DiscretePulseGenerator: '<Root>/LED Heartbeat' */
  Main_Firmware_DW.clockTickCounter = 0L;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xFFFF3FFFU;
  GpioCtrlRegs.GPADIR.all |= 0x800000U;
  EDIS;

  /* InitializeConditions for Delay: '<S1>/Sampling Delay' */
  Main_Firmware_DW.SamplingDelay_DSTATE[0] =
    Main_Firmware_P.SamplingDelay_InitialCondition;
  Main_Firmware_DW.SamplingDelay_DSTATE[1] =
    Main_Firmware_P.SamplingDelay_InitialCondition;
  Main_Firmware_DW.SamplingDelay_DSTATE[2] =
    Main_Firmware_P.SamplingDelay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S48>/Integrator' */
  Main_Firmware_DW.Integrator_DSTATE =
    Main_Firmware_P.I_dqPID1_InitialConditionForInt;

  /* InitializeConditions for UnitDelay: '<S124>/UD'
   *
   * Block description for '<S124>/UD':
   *
   *  Store in Global RAM
   */
  Main_Firmware_DW.UD_DSTATE = Main_Firmware_P.DiscreteDerivativecalc2_ICPrevS;

  /* InitializeConditions for Delay: '<S125>/Delay1' */
  Main_Firmware_DW.Delay1_DSTATE = Main_Firmware_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S125>/Delay2' */
  Main_Firmware_DW.Delay2_DSTATE[0] = Main_Firmware_P.Delay2_InitialCondition;
  Main_Firmware_DW.Delay2_DSTATE[1] = Main_Firmware_P.Delay2_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S155>/Filter' */
  Main_Firmware_DW.Filter_DSTATE =
    Main_Firmware_P.SpeedPID1_InitialConditionForFi;

  /* InitializeConditions for DiscreteIntegrator: '<S100>/Integrator' */
  Main_Firmware_DW.Integrator_DSTATE_m =
    Main_Firmware_P.I_dqPID2_InitialConditionForInt;

  /* SystemInitialize for Enabled SubSystem: '<S118>/Subsystem1' */
  /* SystemInitialize for Fcn: '<S123>/Fcn' incorporates:
   *  Outport: '<S123>/dq'
   */
  Main_Firmware_B.Fcn = Main_Firmware_P.dq_Y0_p[0];

  /* SystemInitialize for Fcn: '<S123>/Fcn1' incorporates:
   *  Outport: '<S123>/dq'
   */
  Main_Firmware_B.Fcn1 = Main_Firmware_P.dq_Y0_p[1];

  /* End of SystemInitialize for SubSystem: '<S118>/Subsystem1' */

  /* SystemInitialize for Enabled SubSystem: '<S118>/Subsystem - pi//2 delay' */
  /* SystemInitialize for Fcn: '<S122>/Fcn' incorporates:
   *  Outport: '<S122>/dq'
   */
  Main_Firmware_B.Fcn_j = Main_Firmware_P.dq_Y0[0];

  /* SystemInitialize for Fcn: '<S122>/Fcn1' incorporates:
   *  Outport: '<S122>/dq'
   */
  Main_Firmware_B.Fcn1_e = Main_Firmware_P.dq_Y0[1];

  /* End of SystemInitialize for SubSystem: '<S118>/Subsystem - pi//2 delay' */
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
