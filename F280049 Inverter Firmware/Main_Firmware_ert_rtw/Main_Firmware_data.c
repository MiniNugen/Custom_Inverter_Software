/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware_data.c
 *
 * Code generated for Simulink model 'Main_Firmware'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Feb 17 15:56:47 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Main_Firmware.h"

/* Block parameters (default storage) */
P_Main_Firmware_T Main_Firmware_P = {
  /* Variable: A_f
   * Referenced by: '<S1>/Constant2'
   */
  2.22,

  /* Variable: C_d
   * Referenced by: '<S1>/Constant2'
   */
  0.219,

  /* Variable: C_rr
   * Referenced by: '<S1>/Constant3'
   */
  0.01,

  /* Variable: Ld
   * Referenced by: '<S11>/Gain3'
   */
  0.000395,

  /* Variable: Lq
   * Referenced by: '<S11>/Gain1'
   */
  0.000435,

  /* Variable: Rs
   * Referenced by:
   *   '<S11>/Gain'
   *   '<S11>/Gain2'
   */
  0.18,

  /* Variable: Voltage_max
   * Referenced by:
   *   '<S1>/Gain5'
   *   '<S2>/Limiter'
   *   '<S2>/Limiter 1'
   */
  100.0,

  /* Variable: g
   * Referenced by: '<S1>/Constant3'
   */
  9.8,

  /* Variable: lambda
   * Referenced by:
   *   '<S2>/Gain6'
   *   '<S11>/Gain4'
   */
  0.1194,

  /* Variable: m
   * Referenced by: '<S1>/Constant3'
   */
  1835.0,

  /* Variable: ppair
   * Referenced by:
   *   '<S2>/Gain2'
   *   '<S2>/Gain6'
   *   '<S2>/Gain7'
   *   '<S11>/Gain5'
   */
  1.0,

  /* Mask Parameter: AlphaBetaZerotodq0_Alignment
   * Referenced by: '<S117>/Constant'
   */
  1.0,

  /* Mask Parameter: Carriercounter_CarrCount
   * Referenced by: '<S189>/Constant2'
   */
  3.0,

  /* Mask Parameter: WePID_D
   * Referenced by: '<S149>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: IDPID_D
   * Referenced by: '<S43>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: IQPID_D
   * Referenced by: '<S93>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: IDPID_I
   * Referenced by: '<S47>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: IQPID_I
   * Referenced by: '<S97>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: WePID_I
   * Referenced by: '<S153>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: WePID_InitialConditionForFilter
   * Referenced by: '<S151>/Filter'
   */
  0.0,

  /* Mask Parameter: IDPID_InitialConditionForFilter
   * Referenced by: '<S45>/Filter'
   */
  0.0,

  /* Mask Parameter: IQPID_InitialConditionForFilter
   * Referenced by: '<S95>/Filter'
   */
  0.0,

  /* Mask Parameter: WePID_InitialConditionForIntegr
   * Referenced by: '<S156>/Integrator'
   */
  0.0,

  /* Mask Parameter: IDPID_InitialConditionForIntegr
   * Referenced by: '<S50>/Integrator'
   */
  0.0,

  /* Mask Parameter: IQPID_InitialConditionForIntegr
   * Referenced by: '<S100>/Integrator'
   */
  0.0,

  /* Mask Parameter: WePID_N
   * Referenced by: '<S159>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: IDPID_N
   * Referenced by: '<S53>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: IQPID_N
   * Referenced by: '<S103>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: WePID_P
   * Referenced by: '<S161>/Proportional Gain'
   */
  1.0,

  /* Mask Parameter: IDPID_P
   * Referenced by: '<S55>/Proportional Gain'
   */
  1.0,

  /* Mask Parameter: IQPID_P
   * Referenced by: '<S105>/Proportional Gain'
   */
  1.0,

  /* Mask Parameter: Carriercounter_Range
   * Referenced by:
   *   '<S189>/Bias'
   *   '<S189>/Gain'
   */
  1.0,

  /* Mask Parameter: PWMGenerator_Tdelay
   * Referenced by: '<S200>/Initial'
   */
  0.0,

  /* Mask Parameter: PWMGenerator_Tper
   * Referenced by:
   *   '<S189>/Constant10'
   *   '<S189>/Constant6'
   *   '<S189>/Gain1'
   *   '<S193>/Switch'
   *   '<S194>/Switch'
   *   '<S195>/Bias'
   *   '<S195>/Constant'
   *   '<S198>/Constant'
   *   '<S199>/Gain'
   *   '<S199>/Gain1'
   *   '<S202>/Constant'
   *   '<S203>/Gain'
   *   '<S203>/Gain1'
   */
  5.0E-5,

  /* Mask Parameter: IntegratorwithWrappedStateDiscr
   * Referenced by:
   *   '<S197>/Constant'
   *   '<S199>/Bias'
   *   '<S199>/Gain'
   *   '<S199>/Gain1'
   */
  0.0,

  /* Mask Parameter: IntegratorwithWrappedStateDis_n
   * Referenced by:
   *   '<S201>/Constant'
   *   '<S203>/Bias'
   *   '<S203>/Gain'
   *   '<S203>/Gain1'
   */
  0.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S119>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S120>/Constant'
   */
  2.0,

  /* Mask Parameter: IntegratorwithWrappedStateDis_b
   * Referenced by: '<S196>/Initial'
   */
  0.0,

  /* Expression: [0,0]
   * Referenced by: '<S121>/dq'
   */
  { 0.0, 0.0 },

  /* Expression: [0,0]
   * Referenced by: '<S122>/dq'
   */
  { 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S3>/Constant2'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Sampling Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S190>/Constant'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S196>/Integrator'
   */
  1.0E-6,

  /* Expression: 0
   * Referenced by: '<S193>/Constant2'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_k
   * Referenced by: '<S200>/Integrator'
   */
  1.0E-6,

  /* Expression: 0
   * Referenced by: '<S194>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S189>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S189>/Saturation'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<S3>/Gain2'
   */
  12.0,

  /* Expression: 12
   * Referenced by: '<S3>/Gain3'
   */
  12.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Constant7'
   */
  0.5,

  /* Expression: 1000
   * Referenced by: '<S1>/Speed request (Rad//s)1'
   */
  1000.0,

  /* Expression: 0.0
   * Referenced by: '<S2>/Delay'
   */
  0.0,

  /* Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ]
   * Referenced by: '<S118>/Gain3'
   */
  { 1.0, 0.0, 0.5, -0.5, 0.8660254037844386, 0.5, -0.5, -0.8660254037844386, 0.5
  },

  /* Expression: 2/3
   * Referenced by: '<S118>/Gain1'
   */
  0.66666666666666663,

  /* Expression: 0
   * Referenced by: '<S2>/Constant1'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S1>/torque request'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S2>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Limiter 1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Limiter'
   */
  0.0,

  /* Expression: -2*pi/3
   * Referenced by: '<S14>/Bias'
   */
  -2.0943951023931953,

  /* Expression: 2*pi/3
   * Referenced by: '<S14>/Bias1'
   */
  2.0943951023931953,

  /* Expression: 1
   * Referenced by: '<S189>/Constant3'
   */
  1.0,

  /* Expression: 1/k^2
   * Referenced by: '<S1>/Gain2'
   */
  0.0064,

  /* Expression: 1
   * Referenced by: '<S1>/LED Heartbeat'
   */
  1.0,

  /* Computed Parameter: LEDHeartbeat_Period
   * Referenced by: '<S1>/LED Heartbeat'
   */
  2.0,

  /* Computed Parameter: LEDHeartbeat_Duty
   * Referenced by: '<S1>/LED Heartbeat'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/LED Heartbeat'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
