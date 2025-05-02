/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware_data.c
 *
 * Code generated for Simulink model 'Main_Firmware'.
 *
 * Model version                  : 2.7
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri May  2 13:51:43 2025
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
   * Referenced by: '<S175>/Constant1'
   */
  1.24,

  /* Variable: C_d
   * Referenced by: '<S175>/Constant1'
   */
  0.7041,

  /* Variable: C_rr
   * Referenced by: '<S175>/Constant2'
   */
  0.02,

  /* Variable: Current_max
   * Referenced by: '<S3>/Limiter1'
   */
  30.0,

  /* Variable: Encoder_Offset
   * Referenced by:
   *   '<S3>/Const'
   *   '<S4>/Constant'
   */
  -0.30436796825529111,

  /* Variable: Ld
   * Referenced by:
   *   '<S5>/Gain3'
   *   '<S174>/Constant1'
   *   '<S174>/Gain'
   */
  0.0001,

  /* Variable: Lq
   * Referenced by:
   *   '<S5>/Gain1'
   *   '<S174>/Constant'
   *   '<S174>/Gain2'
   */
  0.0001,

  /* Variable: Rs
   * Referenced by:
   *   '<S174>/Gain1'
   *   '<S174>/Gain3'
   */
  0.0043333333333333331,

  /* Variable: Torque_max
   * Referenced by:
   *   '<S3>/Saturation1'
   *   '<S163>/Saturation'
   */
  6.75,

  /* Variable: Voltage_max
   * Referenced by:
   *   '<S1>/Gain5'
   *   '<S3>/Limiter'
   *   '<S3>/Limiter 1'
   *   '<S46>/Integrator'
   *   '<S53>/Saturation'
   *   '<S98>/Integrator'
   *   '<S105>/Saturation'
   */
  86.4,

  /* Variable: g
   * Referenced by: '<S175>/Constant2'
   */
  9.8,

  /* Variable: lambda
   * Referenced by:
   *   '<S3>/Gain6'
   *   '<S5>/Gain4'
   *   '<S174>/Gain4'
   *   '<S174>/Gain5'
   */
  0.0375,

  /* Variable: m
   * Referenced by: '<S175>/Constant2'
   */
  1.0,

  /* Variable: ppair
   * Referenced by:
   *   '<S3>/Gain2'
   *   '<S3>/Gain6'
   *   '<S3>/Gain7'
   *   '<S4>/Gain6'
   *   '<S174>/Constant'
   *   '<S174>/Constant1'
   *   '<S174>/Gain4'
   *   '<S174>/Gain5'
   *   '<S174>/Gain6'
   */
  4.0,

  /* Variable: rho
   * Referenced by: '<S175>/Constant1'
   */
  1.2,

  /* Variable: speed_max
   * Referenced by: '<S3>/Saturation'
   */
  523.59877559829886,

  /* Mask Parameter: dq0toAlphaBetaZero_Alignment
   * Referenced by: '<S185>/Constant'
   */
  1.0,

  /* Mask Parameter: AlphaBetaZerotodq0_Alignment
   * Referenced by: '<S116>/Constant'
   */
  1.0,

  /* Mask Parameter: AlphaBetaZerotodq0_Alignment_e
   * Referenced by: '<S178>/Constant'
   */
  1.0,

  /* Mask Parameter: SpeedPID1_D
   * Referenced by: '<S149>/Derivative Gain'
   */
  0.00205517598679868,

  /* Mask Parameter: I_dqPID2_I
   * Referenced by: '<S95>/Integral Gain'
   */
  8.23559930371868,

  /* Mask Parameter: I_dqPID1_I
   * Referenced by: '<S43>/Integral Gain'
   */
  8.23559930371868,

  /* Mask Parameter: DiscreteDerivativecalc_ICPrevSc
   * Referenced by: '<S6>/UD'
   */
  0.0,

  /* Mask Parameter: SpeedPID1_InitialConditionForFi
   * Referenced by: '<S151>/Filter'
   */
  0.0,

  /* Mask Parameter: I_dqPID1_InitialConditionForInt
   * Referenced by: '<S46>/Integrator'
   */
  0.0,

  /* Mask Parameter: I_dqPID2_InitialConditionForInt
   * Referenced by: '<S98>/Integrator'
   */
  0.0,

  /* Mask Parameter: SpeedPID1_N
   * Referenced by: '<S159>/Filter Coefficient'
   */
  100.498329175013,

  /* Mask Parameter: SpeedPID1_P
   * Referenced by: '<S161>/Proportional Gain'
   */
  20.6545195236646,

  /* Mask Parameter: I_dqPID1_P
   * Referenced by: '<S51>/Proportional Gain'
   */
  0.216674080570424,

  /* Mask Parameter: I_dqPID2_P
   * Referenced by: '<S103>/Proportional Gain'
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

  /* Mask Parameter: CompareToConstant_const_n
   * Referenced by: '<S180>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant1_const_n
   * Referenced by: '<S181>/Constant'
   */
  2.0,

  /* Expression: 4
   * Referenced by: '<Root>/Constant1'
   */
  4.0,

  /* Expression: [0,0]
   * Referenced by: '<S188>/alpha_beta'
   */
  { 0.0, 0.0 },

  /* Expression: [0,0]
   * Referenced by: '<S189>/alpha_beta'
   */
  { 0.0, 0.0 },

  /* Expression: 0.0
   * Referenced by: '<S1>/Sampling Delay'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S1>/Saturation'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S1>/Saturation'
   */
  0.0,

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
  200000.0,

  /* Computed Parameter: LEDHeartbeat_Duty
   * Referenced by: '<S2>/LED Heartbeat'
   */
  100000.0,

  /* Expression: 0
   * Referenced by: '<S2>/LED Heartbeat'
   */
  0.0,

  /* Expression: [1]
   * Referenced by: '<S175>/Discrete Transfer Fcn'
   */
  1.0,

  /* Expression: [J 0]
   * Referenced by: '<S175>/Discrete Transfer Fcn'
   */
  { 0.8303048, 0.0 },

  /* Expression: 0
   * Referenced by: '<S175>/Discrete Transfer Fcn'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator2_gainval
   * Referenced by: '<S174>/Discrete-Time Integrator2'
   */
  5.0E-6,

  /* Expression: 0
   * Referenced by: '<S174>/Discrete-Time Integrator2'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S174>/Discrete-Time Integrator'
   */
  5.0E-6,

  /* Expression: 0
   * Referenced by: '<S174>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<S174>/Discrete-Time Integrator1'
   */
  5.0E-6,

  /* Expression: 0
   * Referenced by: '<S174>/Discrete-Time Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant3'
   */
  0.0,

  /* Expression: [ 1   0   1; -1/2  sqrt(3)/2   1; -1/2  -sqrt(3)/2  1 ]
   * Referenced by: '<S184>/Gain3'
   */
  { 1.0, -0.5, -0.5, 0.0, 0.8660254037844386, -0.8660254037844386, 1.0, 1.0, 1.0
  },

  /* Expression: 1
   * Referenced by: '<Root>/Constant2'
   */
  1.0,

  /* Expression: 12
   * Referenced by: '<Root>/Constant'
   */
  12.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S6>/TSamp'
   */
  199999.99999999997,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S151>/Filter'
   */
  5.0E-6,

  /* Expression: 0
   * Referenced by: '<S3>/Switch'
   */
  0.0,

  /* Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ]
   * Referenced by: '<S117>/Gain3'
   */
  { 1.0, 0.0, 0.5, -0.5, 0.8660254037844386, 0.5, -0.5, -0.8660254037844386, 0.5
  },

  /* Expression: 2/3
   * Referenced by: '<S117>/Gain1'
   */
  0.66666666666666663,

  /* Expression: 0
   * Referenced by: '<S3>/Constant1'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S46>/Integrator'
   */
  5.0E-6,

  /* Expression: 0
   * Referenced by: '<S3>/Limiter 1'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_i
   * Referenced by: '<S98>/Integrator'
   */
  5.0E-6,

  /* Expression: 0
   * Referenced by: '<S3>/Limiter'
   */
  0.0,

  /* Expression: -2*pi/3
   * Referenced by: '<S9>/Bias'
   */
  -2.0943951023931953,

  /* Expression: 2*pi/3
   * Referenced by: '<S9>/Bias1'
   */
  2.0943951023931953,

  /* Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ]
   * Referenced by: '<S179>/Gain3'
   */
  { 1.0, 0.0, 0.5, -0.5, 0.8660254037844386, 0.5, -0.5, -0.8660254037844386, 0.5
  },

  /* Expression: 2/3
   * Referenced by: '<S179>/Gain1'
   */
  0.66666666666666663,

  /* Expression: 1/k^2
   * Referenced by: '<S175>/Gain'
   */
  1.0,

  /* Start of '<S178>/Subsystem1' */
  {
    /* Expression: [0,0]
     * Referenced by: '<S183>/dq'
     */
    { 0.0, 0.0 }
  }
  ,

  /* End of '<S178>/Subsystem1' */

  /* Start of '<S178>/Subsystem - pi//2 delay' */
  {
    /* Expression: [0,0]
     * Referenced by: '<S182>/dq'
     */
    { 0.0, 0.0 }
  }
  ,

  /* End of '<S178>/Subsystem - pi//2 delay' */

  /* Start of '<S116>/Subsystem1' */
  {
    /* Expression: [0,0]
     * Referenced by: '<S121>/dq'
     */
    { 0.0, 0.0 }
  }
  ,

  /* End of '<S116>/Subsystem1' */

  /* Start of '<S116>/Subsystem - pi//2 delay' */
  {
    /* Expression: [0,0]
     * Referenced by: '<S120>/dq'
     */
    { 0.0, 0.0 }
  }
  /* End of '<S116>/Subsystem - pi//2 delay' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
