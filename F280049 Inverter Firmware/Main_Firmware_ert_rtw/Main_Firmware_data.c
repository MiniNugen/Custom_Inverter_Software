/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware_data.c
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

/* Block parameters (default storage) */
P_Main_Firmware_T Main_Firmware_P = {
  /* Variable: Encoder_Offset
   * Referenced by: '<S3>/Const'
   */
  -0.19198621771937624,

  /* Variable: Current_max
   * Referenced by: '<S3>/Limiter1'
   */
  5.0F,

  /* Variable: Ld
   * Referenced by: '<S11>/Gain3'
   */
  0.0001F,

  /* Variable: Torque_max
   * Referenced by:
   *   '<S3>/Saturation1'
   *   '<S171>/Saturation'
   */
  1.125F,

  /* Variable: lambda
   * Referenced by: '<S11>/Gain4'
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
   * Referenced by: '<S122>/Constant'
   */
  1.0,

  /* Mask Parameter: I_dqPID1_I
   * Referenced by: '<S49>/Integral Gain'
   */
  8.23559930371868,

  /* Mask Parameter: I_dqPID1_InitialConditionForInt
   * Referenced by: '<S52>/Integrator'
   */
  0.0,

  /* Mask Parameter: I_dqPID1_P
   * Referenced by: '<S57>/Proportional Gain'
   */
  0.216674080570424,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S124>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S125>/Constant'
   */
  2.0,

  /* Mask Parameter: SpeedPID1_D
   * Referenced by: '<S157>/Derivative Gain'
   */
  0.00205517607F,

  /* Mask Parameter: I_dqPID2_I
   * Referenced by: '<S101>/Integral Gain'
   */
  8.23559952F,

  /* Mask Parameter: DiscreteDerivativecalc2_ICPrevS
   * Referenced by: '<S128>/UD'
   */
  0.0F,

  /* Mask Parameter: SpeedPID1_InitialConditionForFi
   * Referenced by: '<S159>/Filter'
   */
  0.0F,

  /* Mask Parameter: I_dqPID2_InitialConditionForInt
   * Referenced by: '<S104>/Integrator'
   */
  0.0F,

  /* Mask Parameter: I_dqPID2_LowerIntegratorSaturat
   * Referenced by: '<S104>/Integrator'
   */
  -60.0F,

  /* Mask Parameter: SpeedPID1_LowerSaturationLimit
   * Referenced by: '<S171>/Saturation'
   */
  -1.125F,

  /* Mask Parameter: SpeedPID1_N
   * Referenced by: '<S167>/Filter Coefficient'
   */
  100.498329F,

  /* Mask Parameter: SpeedPID1_P
   * Referenced by: '<S169>/Proportional Gain'
   */
  20.65452F,

  /* Mask Parameter: I_dqPID2_P
   * Referenced by: '<S109>/Proportional Gain'
   */
  0.216674075F,

  /* Mask Parameter: CompareToConstant_const_k
   * Referenced by: '<S182>/Constant'
   */
  5.5F,

  /* Mask Parameter: CompareToConstant1_const_h
   * Referenced by: '<S183>/Constant'
   */
  575.958679F,

  /* Expression: 0.43
   * Referenced by: '<S2>/Sine Wave'
   */
  0.43,

  /* Expression: 0.43
   * Referenced by: '<S2>/Sine Wave'
   */
  0.43,

  /* Expression: 0.1*2*pi
   * Referenced by: '<S2>/Sine Wave'
   */
  0.62831853071795862,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave'
   */
  0.0,

  /* Expression: 0.43
   * Referenced by: '<S2>/Sine Wave2'
   */
  0.43,

  /* Expression: 0.43
   * Referenced by: '<S2>/Sine Wave2'
   */
  0.43,

  /* Expression: 0.1*2*pi
   * Referenced by: '<S2>/Sine Wave2'
   */
  0.62831853071795862,

  /* Expression: 2*pi/3
   * Referenced by: '<S2>/Sine Wave2'
   */
  2.0943951023931953,

  /* Expression: 0.43
   * Referenced by: '<S2>/Sine Wave1'
   */
  0.43,

  /* Expression: 0.43
   * Referenced by: '<S2>/Sine Wave1'
   */
  0.43,

  /* Expression: 0.1*2*pi
   * Referenced by: '<S2>/Sine Wave1'
   */
  0.62831853071795862,

  /* Expression: -2*pi/3
   * Referenced by: '<S2>/Sine Wave1'
   */
  -2.0943951023931953,

  /* Expression: 100
   * Referenced by: '<S2>/Gain1'
   */
  100.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant4'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
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

  /* Expression: 0
   * Referenced by: '<S3>/Constant1'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S52>/Integrator'
   */
  0.0001,

  /* Expression: UpperIntegratorSaturationLimit
   * Referenced by: '<S52>/Integrator'
   */
  60.0,

  /* Expression: LowerIntegratorSaturationLimit
   * Referenced by: '<S52>/Integrator'
   */
  -60.0,

  /* Expression: Voltage_max
   * Referenced by: '<S3>/Limiter 1'
   */
  60.0,

  /* Expression: 0
   * Referenced by: '<S3>/Limiter 1'
   */
  0.0,

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
   * Referenced by: '<S129>/Bias'
   */
  1,

  /* Computed Parameter: Constant1_Value_f
   * Referenced by: '<S10>/Constant1'
   */
  0.0F,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S10>/Constant3'
   */
  0.0F,

  /* Computed Parameter: Constant_Value_c
   * Referenced by: '<S9>/Constant'
   */
  0.0F,

  /* Computed Parameter: Constant2_Value_h
   * Referenced by: '<S9>/Constant2'
   */
  100.0F,

  /* Computed Parameter: Constant5_Value
   * Referenced by: '<S9>/Constant5'
   */
  1.0F,

  /* Computed Parameter: Constant_Value_l
   * Referenced by: '<S8>/Constant'
   */
  0.0F,

  /* Computed Parameter: Constant1_Value_h
   * Referenced by: '<S8>/Constant1'
   */
  1.0F,

  /* Computed Parameter: Constant3_Value_m
   * Referenced by: '<S8>/Constant3'
   */
  100.0F,

  /* Computed Parameter: Constant4_Value_k
   * Referenced by: '<S8>/Constant4'
   */
  100.0F,

  /* Computed Parameter: Constant5_Value_j
   * Referenced by: '<S8>/Constant5'
   */
  100.0F,

  /* Computed Parameter: dq_Y0
   * Referenced by: '<S126>/dq'
   */
  { 0.0F, 0.0F },

  /* Computed Parameter: dq_Y0_c
   * Referenced by: '<S127>/dq'
   */
  { 0.0F, 0.0F },

  /* Computed Parameter: Constant3_Value_j
   * Referenced by: '<Root>/Constant3'
   */
  0.0F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S5>/Gain3'
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

  /* Computed Parameter: Bias2_Bias
   * Referenced by: '<S6>/Bias2'
   */
  -0.07F,

  /* Computed Parameter: Bias3_Bias
   * Referenced by: '<S6>/Bias3'
   */
  -0.286F,

  /* Computed Parameter: Bias4_Bias
   * Referenced by: '<S6>/Bias4'
   */
  -0.39F,

  /* Computed Parameter: Gain1_Gain_n
   * Referenced by: '<S5>/Gain1'
   */
  0.000805664051F,

  /* Computed Parameter: Bias_Bias_j
   * Referenced by: '<S6>/Bias'
   */
  -1.5F,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S128>/TSamp'
   */
  10000.0F,

  /* Computed Parameter: Delay1_InitialCondition
   * Referenced by: '<S129>/Delay1'
   */
  0.0F,

  /* Computed Parameter: Delay2_InitialCondition
   * Referenced by: '<S129>/Delay2'
   */
  0.0F,

  /* Computed Parameter: Constant1_Value_b
   * Referenced by: '<S129>/Constant1'
   */
  2617.9939F,

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S129>/Constant'
   */
  2617.9939F,

  /* Computed Parameter: Gain_Gain_n
   * Referenced by: '<Root>/Gain'
   */
  0.25F,

  /* Computed Parameter: Constant1_Value_k
   * Referenced by: '<Root>/Constant1'
   */
  0.0F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S3>/Saturation'
   */
  -523.598755F,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S159>/Filter'
   */
  0.0001F,

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<S3>/Saturation1'
   */
  -1.125F,

  /* Computed Parameter: Gain3_Gain_m
   * Referenced by: '<S123>/Gain3'
   */
  { 1.0F, 0.0F, 0.5F, -0.5F, 0.866025388F, 0.5F, -0.5F, -0.866025388F, 0.5F },

  /* Computed Parameter: Gain1_Gain_i
   * Referenced by: '<S123>/Gain1'
   */
  0.666666687F,

  /* Computed Parameter: Gain6_Gain
   * Referenced by: '<S3>/Gain6'
   */
  4.44444466F,

  /* Computed Parameter: Limiter1_LowerSat_m
   * Referenced by: '<S3>/Limiter1'
   */
  -5.0F,

  /* Computed Parameter: Integrator_gainval_p
   * Referenced by: '<S104>/Integrator'
   */
  0.0001F,

  /* Expression: UpperIntegratorSaturationLimit
   * Referenced by: '<S104>/Integrator'
   */
  60.0F,

  /* Computed Parameter: Gain1_Gain_k
   * Referenced by: '<S11>/Gain1'
   */
  -0.0001F,

  /* Expression: Voltage_max
   * Referenced by: '<S3>/Limiter'
   */
  60.0F,

  /* Computed Parameter: Limiter_LowerSat
   * Referenced by: '<S3>/Limiter'
   */
  -60.0F,

  /* Computed Parameter: Bias_Bias_o
   * Referenced by: '<S14>/Bias'
   */
  -2.09439516F,

  /* Computed Parameter: Bias1_Bias_c
   * Referenced by: '<S14>/Bias1'
   */
  2.09439516F
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
