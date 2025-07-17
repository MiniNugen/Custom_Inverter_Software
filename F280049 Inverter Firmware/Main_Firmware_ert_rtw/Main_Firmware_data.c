/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware_data.c
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

/* Block parameters (default storage) */
P_Main_Firmware_T Main_Firmware_P = {
  /* Variable: Encoder_Offset
   * Referenced by: '<S3>/Const'
   */
  -0.78539816339744828,

  /* Variable: Current_max
   * Referenced by: '<S3>/Limiter1'
   */
  42.4264069F,

  /* Variable: Ld
   * Referenced by: '<S7>/Gain3'
   */
  0.0001F,

  /* Variable: Torque_max
   * Referenced by:
   *   '<S3>/Saturation1'
   *   '<S167>/Saturation'
   */
  9.54594135F,

  /* Variable: Voltage_max
   * Referenced by:
   *   '<S3>/Limiter'
   *   '<S3>/Limiter 1'
   *   '<S48>/Integrator'
   *   '<S55>/Saturation'
   *   '<S100>/Integrator'
   *   '<S107>/Saturation'
   */
  96.0F,

  /* Variable: lambda
   * Referenced by: '<S7>/Gain4'
   */
  0.0375F,

  /* Variable: ppair
   * Referenced by:
   *   '<S3>/Gain2'
   *   '<S3>/Gain7'
   */
  4.0F,

  /* Variable: speed_max
   * Referenced by: '<S3>/Saturation'
   */
  523.598755F,

  /* Mask Parameter: AlphaBetaZerotodq0_Alignment
   * Referenced by: '<S118>/Constant'
   */
  1.0,

  /* Mask Parameter: I_dqPID1_I
   * Referenced by: '<S45>/Integral Gain'
   */
  8.23559930371868,

  /* Mask Parameter: I_dqPID1_P
   * Referenced by: '<S53>/Proportional Gain'
   */
  0.216674080570424,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S120>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S121>/Constant'
   */
  2.0,

  /* Mask Parameter: SpeedPID1_D
   * Referenced by: '<S153>/Derivative Gain'
   */
  0.00205517607F,

  /* Mask Parameter: I_dqPID2_I
   * Referenced by: '<S97>/Integral Gain'
   */
  8.23559952F,

  /* Mask Parameter: DiscreteDerivativecalc2_ICPrevS
   * Referenced by: '<S124>/UD'
   */
  0.0F,

  /* Mask Parameter: SpeedPID1_InitialConditionForFi
   * Referenced by: '<S155>/Filter'
   */
  0.0F,

  /* Mask Parameter: I_dqPID1_InitialConditionForInt
   * Referenced by: '<S48>/Integrator'
   */
  0.0F,

  /* Mask Parameter: I_dqPID2_InitialConditionForInt
   * Referenced by: '<S100>/Integrator'
   */
  0.0F,

  /* Mask Parameter: I_dqPID1_LowerIntegratorSaturat
   * Referenced by: '<S48>/Integrator'
   */
  -96.0F,

  /* Mask Parameter: I_dqPID2_LowerIntegratorSaturat
   * Referenced by: '<S100>/Integrator'
   */
  -96.0F,

  /* Mask Parameter: I_dqPID1_LowerSaturationLimit
   * Referenced by: '<S55>/Saturation'
   */
  -96.0F,

  /* Mask Parameter: SpeedPID1_LowerSaturationLimit
   * Referenced by: '<S167>/Saturation'
   */
  -9.54594135F,

  /* Mask Parameter: I_dqPID2_LowerSaturationLimit
   * Referenced by: '<S107>/Saturation'
   */
  -96.0F,

  /* Mask Parameter: SpeedPID1_N
   * Referenced by: '<S163>/Filter Coefficient'
   */
  100.498329F,

  /* Mask Parameter: SpeedPID1_P
   * Referenced by: '<S165>/Proportional Gain'
   */
  20.65452F,

  /* Mask Parameter: I_dqPID2_P
   * Referenced by: '<S105>/Proportional Gain'
   */
  0.216674075F,

  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S180>/Constant'
   */
  105.6F,

  /* Mask Parameter: CompareToConstant_const_m
   * Referenced by: '<S178>/Constant'
   */
  46.6690483F,

  /* Mask Parameter: CompareToConstant1_const_j
   * Referenced by: '<S179>/Constant'
   */
  575.958679F,

  /* Expression: 0.0
   * Referenced by: '<S1>/Sampling Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Switch'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Constant7'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<Root>/Constant4'
   */
  1.0,

  /* Expression: 50
   * Referenced by: '<S2>/Constant'
   */
  50.0,

  /* Expression: 37
   * Referenced by: '<S2>/Constant1'
   */
  37.0,

  /* Expression: 72
   * Referenced by: '<S2>/Constant2'
   */
  72.0,

  /* Expression: 1
   * Referenced by: '<Root>/LED Heartbeat'
   */
  1.0,

  /* Computed Parameter: LEDHeartbeat_Period
   * Referenced by: '<Root>/LED Heartbeat'
   */
  10000.0,

  /* Computed Parameter: LEDHeartbeat_Duty
   * Referenced by: '<Root>/LED Heartbeat'
   */
  5000.0,

  /* Expression: 0
   * Referenced by: '<Root>/LED Heartbeat'
   */
  0.0,

  /* Computed Parameter: Bias_Bias
   * Referenced by: '<S125>/Bias'
   */
  1,

  /* Computed Parameter: dq_Y0
   * Referenced by: '<S122>/dq'
   */
  { 0.0F, 0.0F },

  /* Computed Parameter: dq_Y0_p
   * Referenced by: '<S123>/dq'
   */
  { 0.0F, 0.0F },

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<Root>/Constant3'
   */
  5.0F,

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<S1>/Saturation'
   */
  95.0F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S1>/Saturation'
   */
  0.0F,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S2>/Gain1'
   */
  100.0F,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S5>/Gain2'
   */
  0.000805664051F,

  /* Computed Parameter: Bias1_Bias
   * Referenced by: '<S6>/Bias1'
   */
  -1.65F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S6>/Gain'
   */
  41.6666679F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S119>/Gain3'
   */
  { 1.0F, 0.0F, 0.5F, -0.5F, 0.866025388F, 0.5F, -0.5F, -0.866025388F, 0.5F },

  /* Computed Parameter: Gain1_Gain_l
   * Referenced by: '<S119>/Gain1'
   */
  0.666666687F,

  /* Computed Parameter: Gain1_Gain_a
   * Referenced by: '<S5>/Gain1'
   */
  0.000805664051F,

  /* Computed Parameter: Bias_Bias_g
   * Referenced by: '<S6>/Bias'
   */
  -1.5F,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S48>/Integrator'
   */
  0.0001F,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S124>/TSamp'
   */
  10000.0F,

  /* Computed Parameter: Delay1_InitialCondition
   * Referenced by: '<S125>/Delay1'
   */
  0.0F,

  /* Computed Parameter: Delay2_InitialCondition
   * Referenced by: '<S125>/Delay2'
   */
  0.0F,

  /* Computed Parameter: Constant1_Value_i
   * Referenced by: '<S125>/Constant1'
   */
  2617.9939F,

  /* Computed Parameter: Constant_Value_f
   * Referenced by: '<S125>/Constant'
   */
  2617.9939F,

  /* Computed Parameter: Limiter1_LowerSat
   * Referenced by: '<S3>/Limiter 1'
   */
  0.0F,

  /* Computed Parameter: Constant1_Value_n
   * Referenced by: '<Root>/Constant1'
   */
  0.0F,

  /* Computed Parameter: Saturation_LowerSat_a
   * Referenced by: '<S3>/Saturation'
   */
  -523.598755F,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S155>/Filter'
   */
  0.0001F,

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<S3>/Saturation1'
   */
  -9.54594135F,

  /* Computed Parameter: Gain6_Gain
   * Referenced by: '<S3>/Gain6'
   */
  4.44444466F,

  /* Computed Parameter: Limiter1_LowerSat_j
   * Referenced by: '<S3>/Limiter1'
   */
  -42.4264069F,

  /* Computed Parameter: Integrator_gainval_n
   * Referenced by: '<S100>/Integrator'
   */
  0.0001F,

  /* Computed Parameter: Gain1_Gain_n
   * Referenced by: '<S7>/Gain1'
   */
  -0.0001F,

  /* Computed Parameter: Limiter_LowerSat
   * Referenced by: '<S3>/Limiter'
   */
  0.0F,

  /* Computed Parameter: Bias_Bias_e
   * Referenced by: '<S10>/Bias'
   */
  -2.09439516F,

  /* Computed Parameter: Bias1_Bias_k
   * Referenced by: '<S10>/Bias1'
   */
  2.09439516F,

  /* Computed Parameter: Gain5_Gain
   * Referenced by: '<S1>/Gain5'
   */
  0.010416667F,

  /* Computed Parameter: Gain_Gain_d
   * Referenced by: '<Root>/Gain'
   */
  0.25F
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
