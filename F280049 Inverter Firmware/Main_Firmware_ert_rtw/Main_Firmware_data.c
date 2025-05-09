/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware_data.c
 *
 * Code generated for Simulink model 'Main_Firmware'.
 *
 * Model version                  : 2.21
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu May  8 18:41:37 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Main_Firmware.h"

/* Block parameters (default storage) */
P_Main_Firmware_T Main_Firmware_P = {
  /* Variable: C_rr
   * Referenced by: '<S175>/Constant2'
   */
  0.02,

  /* Variable: g
   * Referenced by: '<S175>/Constant2'
   */
  9.8,

  /* Variable: m
   * Referenced by: '<S175>/Constant2'
   */
  1.0,

  /* Variable: Current_max
   * Referenced by: '<S3>/Limiter1'
   */
  30.0F,

  /* Variable: Ld
   * Referenced by: '<S5>/Gain3'
   */
  0.0001F,

  /* Variable: Rs
   * Referenced by:
   *   '<S174>/Gain1'
   *   '<S174>/Gain3'
   */
  0.00433333311F,

  /* Variable: Torque_max
   * Referenced by:
   *   '<S3>/Saturation1'
   *   '<S163>/Saturation'
   */
  6.75F,

  /* Variable: Voltage_max
   * Referenced by:
   *   '<S3>/Limiter'
   *   '<S3>/Limiter 1'
   *   '<S46>/Integrator'
   *   '<S53>/Saturation'
   *   '<S98>/Integrator'
   *   '<S105>/Saturation'
   */
  86.4F,

  /* Variable: lambda
   * Referenced by: '<S5>/Gain4'
   */
  0.0375F,

  /* Variable: ppair
   * Referenced by:
   *   '<S3>/Gain2'
   *   '<S3>/Gain7'
   *   '<S174>/Gain6'
   */
  4.0F,

  /* Variable: speed_max
   * Referenced by: '<S3>/Saturation'
   */
  523.598755F,

  /* Mask Parameter: dq0toAlphaBetaZero_Alignment
   * Referenced by: '<S185>/Constant'
   */
  1.0,

  /* Mask Parameter: AlphaBetaZerotodq0_Alignment
   * Referenced by: '<S116>/Constant'
   */
  1.0,

  /* Mask Parameter: AlphaBetaZerotodq0_Alignment_n
   * Referenced by: '<S178>/Constant'
   */
  1.0,

  /* Mask Parameter: I_dqPID1_I
   * Referenced by: '<S43>/Integral Gain'
   */
  8.23559930371868,

  /* Mask Parameter: I_dqPID1_P
   * Referenced by: '<S51>/Proportional Gain'
   */
  0.216674080570424,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S186>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S187>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant_const_o
   * Referenced by: '<S118>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant1_const_k
   * Referenced by: '<S119>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant_const_i
   * Referenced by: '<S180>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant1_const_m
   * Referenced by: '<S181>/Constant'
   */
  2.0,

  /* Mask Parameter: SpeedPID1_D
   * Referenced by: '<S149>/Derivative Gain'
   */
  0.00205517607F,

  /* Mask Parameter: I_dqPID2_I
   * Referenced by: '<S95>/Integral Gain'
   */
  8.23559952F,

  /* Mask Parameter: DiscreteDerivativecalc_ICPrevSc
   * Referenced by: '<S6>/UD'
   */
  0.0F,

  /* Mask Parameter: SpeedPID1_InitialConditionForFi
   * Referenced by: '<S151>/Filter'
   */
  0.0F,

  /* Mask Parameter: I_dqPID1_InitialConditionForInt
   * Referenced by: '<S46>/Integrator'
   */
  0.0F,

  /* Mask Parameter: I_dqPID2_InitialConditionForInt
   * Referenced by: '<S98>/Integrator'
   */
  0.0F,

  /* Mask Parameter: I_dqPID1_LowerIntegratorSaturat
   * Referenced by: '<S46>/Integrator'
   */
  -86.4F,

  /* Mask Parameter: I_dqPID2_LowerIntegratorSaturat
   * Referenced by: '<S98>/Integrator'
   */
  -86.4F,

  /* Mask Parameter: SpeedPID1_LowerSaturationLimit
   * Referenced by: '<S163>/Saturation'
   */
  -6.75F,

  /* Mask Parameter: I_dqPID1_LowerSaturationLimit
   * Referenced by: '<S53>/Saturation'
   */
  -86.4F,

  /* Mask Parameter: I_dqPID2_LowerSaturationLimit
   * Referenced by: '<S105>/Saturation'
   */
  -86.4F,

  /* Mask Parameter: SpeedPID1_N
   * Referenced by: '<S159>/Filter Coefficient'
   */
  100.498329F,

  /* Mask Parameter: SpeedPID1_P
   * Referenced by: '<S161>/Proportional Gain'
   */
  20.65452F,

  /* Mask Parameter: I_dqPID2_P
   * Referenced by: '<S103>/Proportional Gain'
   */
  0.216674075F,

  /* Expression: 0
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/LED Heartbeat'
   */
  1.0,

  /* Computed Parameter: LEDHeartbeat_Period
   * Referenced by: '<S2>/LED Heartbeat'
   */
  10000.0,

  /* Computed Parameter: LEDHeartbeat_Duty
   * Referenced by: '<S2>/LED Heartbeat'
   */
  5000.0,

  /* Expression: 0
   * Referenced by: '<S2>/LED Heartbeat'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: Encoder_Offset
   * Referenced by: '<S3>/Const'
   */
  -0.78539816339744828,

  /* Expression: 0
   * Referenced by: '<S3>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant1'
   */
  0.0,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<Root>/Constant3'
   */
  3.0F,

  /* Computed Parameter: alpha_beta_Y0
   * Referenced by: '<S188>/alpha_beta'
   */
  { 0.0F, 0.0F },

  /* Computed Parameter: alpha_beta_Y0_i
   * Referenced by: '<S189>/alpha_beta'
   */
  { 0.0F, 0.0F },

  /* Computed Parameter: SamplingDelay_InitialCondition
   * Referenced by: '<S1>/Sampling Delay'
   */
  0.0F,

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<S1>/Saturation'
   */
  100.0F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S1>/Saturation'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S2>/Gain'
   */
  100.0F,

  /* Computed Parameter: TransferFcn_NumCoef
   * Referenced by: '<S175>/Transfer Fcn'
   */
  { 0.0F, 0.000120437697F },

  /* Computed Parameter: TransferFcn_DenCoef
   * Referenced by: '<S175>/Transfer Fcn'
   */
  { 1.0F, -1.0F },

  /* Computed Parameter: TransferFcn_InitialStates
   * Referenced by: '<S175>/Transfer Fcn'
   */
  0.0F,

  /* Computed Parameter: Constant1_Value_n
   * Referenced by: '<Root>/Constant1'
   */
  5.333F,

  /* Computed Parameter: Saturation_LowerSat_a
   * Referenced by: '<S3>/Saturation'
   */
  -523.598755F,

  /* Computed Parameter: Integrator2_gainval
   * Referenced by: '<S174>/Integrator2'
   */
  0.0001F,

  /* Computed Parameter: Integrator2_IC
   * Referenced by: '<S174>/Integrator2'
   */
  0.0F,

  /* Computed Parameter: Integrator2_UpperSat
   * Referenced by: '<S174>/Integrator2'
   */
  3.402823466E+38F,

  /* Computed Parameter: Integrator2_LowerSat
   * Referenced by: '<S174>/Integrator2'
   */
  -3.402823466E+38F,

  /* Computed Parameter: Gain6_Gain
   * Referenced by: '<S4>/Gain6'
   */
  0.25F,

  /* Expression: Encoder_Offset
   * Referenced by: '<S4>/Constant'
   */
  -0.785398185F,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S174>/Integrator'
   */
  0.0001F,

  /* Computed Parameter: Integrator_IC
   * Referenced by: '<S174>/Integrator'
   */
  0.0F,

  /* Computed Parameter: Integrator_UpperSat
   * Referenced by: '<S174>/Integrator'
   */
  3.402823466E+38F,

  /* Computed Parameter: Integrator_LowerSat
   * Referenced by: '<S174>/Integrator'
   */
  -3.402823466E+38F,

  /* Computed Parameter: Integrator1_gainval
   * Referenced by: '<S174>/Integrator1'
   */
  0.0001F,

  /* Computed Parameter: Integrator1_IC
   * Referenced by: '<S174>/Integrator1'
   */
  0.0F,

  /* Computed Parameter: Integrator1_UpperSat
   * Referenced by: '<S174>/Integrator1'
   */
  3.402823466E+38F,

  /* Computed Parameter: Integrator1_LowerSat
   * Referenced by: '<S174>/Integrator1'
   */
  -3.402823466E+38F,

  /* Computed Parameter: Constant3_Value_a
   * Referenced by: '<S4>/Constant3'
   */
  0.0F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S184>/Gain3'
   */
  { 1.0F, -0.5F, -0.5F, 0.0F, 0.866025388F, -0.866025388F, 1.0F, 1.0F, 1.0F },

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S6>/TSamp'
   */
  10000.0F,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S151>/Filter'
   */
  0.0001F,

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<S3>/Saturation1'
   */
  -6.75F,

  /* Computed Parameter: Gain5_Gain
   * Referenced by: '<S174>/Gain5'
   */
  0.225F,

  /* Computed Parameter: Gain3_Gain_k
   * Referenced by: '<S117>/Gain3'
   */
  { 1.0F, 0.0F, 0.5F, -0.5F, 0.866025388F, 0.5F, -0.5F, -0.866025388F, 0.5F },

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S117>/Gain1'
   */
  0.666666687F,

  /* Computed Parameter: Integrator_gainval_l
   * Referenced by: '<S46>/Integrator'
   */
  0.0001F,

  /* Computed Parameter: Limiter1_LowerSat
   * Referenced by: '<S3>/Limiter 1'
   */
  0.0F,

  /* Computed Parameter: Gain6_Gain_p
   * Referenced by: '<S3>/Gain6'
   */
  4.44444466F,

  /* Computed Parameter: Limiter1_LowerSat_j
   * Referenced by: '<S3>/Limiter1'
   */
  -30.0F,

  /* Computed Parameter: Integrator_gainval_n
   * Referenced by: '<S98>/Integrator'
   */
  0.0001F,

  /* Computed Parameter: Gain1_Gain_n
   * Referenced by: '<S5>/Gain1'
   */
  -0.0001F,

  /* Computed Parameter: Limiter_LowerSat
   * Referenced by: '<S3>/Limiter'
   */
  0.0F,

  /* Computed Parameter: Bias_Bias
   * Referenced by: '<S9>/Bias'
   */
  -2.09439516F,

  /* Computed Parameter: Bias1_Bias
   * Referenced by: '<S9>/Bias1'
   */
  2.09439516F,

  /* Computed Parameter: Gain5_Gain_i
   * Referenced by: '<S1>/Gain5'
   */
  0.0115740737F,

  /* Computed Parameter: Gain3_Gain_g
   * Referenced by: '<S179>/Gain3'
   */
  { 1.0F, 0.0F, 0.5F, -0.5F, 0.866025388F, 0.5F, -0.5F, -0.866025388F, 0.5F },

  /* Computed Parameter: Gain1_Gain_e
   * Referenced by: '<S179>/Gain1'
   */
  0.666666687F,

  /* Computed Parameter: Constant_Value_i
   * Referenced by: '<S174>/Constant'
   */
  0.0004F,

  /* Computed Parameter: Gain_Gain_k
   * Referenced by: '<S174>/Gain'
   */
  10000.0F,

  /* Computed Parameter: Constant1_Value_p
   * Referenced by: '<S174>/Constant1'
   */
  0.0004F,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<S174>/Gain4'
   */
  0.15F,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S174>/Gain2'
   */
  10000.0F,

  /* Computed Parameter: Constant1_Value_no
   * Referenced by: '<S175>/Constant1'
   */
  0.0216299091F,

  /* Computed Parameter: Gain_Gain_m
   * Referenced by: '<S175>/Gain'
   */
  1.0F,

  /* Start of '<S178>/Subsystem1' */
  {
    /* Computed Parameter: dq_Y0
     * Referenced by: '<S183>/dq'
     */
    { 0.0F, 0.0F }
  }
  ,

  /* End of '<S178>/Subsystem1' */

  /* Start of '<S178>/Subsystem - pi//2 delay' */
  {
    /* Computed Parameter: dq_Y0
     * Referenced by: '<S182>/dq'
     */
    { 0.0F, 0.0F }
  }
  ,

  /* End of '<S178>/Subsystem - pi//2 delay' */

  /* Start of '<S116>/Subsystem1' */
  {
    /* Computed Parameter: dq_Y0
     * Referenced by: '<S121>/dq'
     */
    { 0.0F, 0.0F }
  }
  ,

  /* End of '<S116>/Subsystem1' */

  /* Start of '<S116>/Subsystem - pi//2 delay' */
  {
    /* Computed Parameter: dq_Y0
     * Referenced by: '<S120>/dq'
     */
    { 0.0F, 0.0F }
  }
  /* End of '<S116>/Subsystem - pi//2 delay' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
