/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware_data.c
 *
 * Code generated for Simulink model 'Main_Firmware'.
 *
 * Model version                  : 2.12
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed May  7 18:27:31 2025
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
   * Referenced by: '<S174>/Constant1'
   */
  1.24,

  /* Variable: C_d
   * Referenced by: '<S174>/Constant1'
   */
  0.7041,

  /* Variable: C_rr
   * Referenced by: '<S174>/Constant2'
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
  -0.78539816339744828,

  /* Variable: Ld
   * Referenced by:
   *   '<S5>/Gain3'
   *   '<S173>/Constant1'
   *   '<S173>/Gain'
   */
  0.0001,

  /* Variable: Lq
   * Referenced by:
   *   '<S5>/Gain1'
   *   '<S173>/Constant'
   *   '<S173>/Gain2'
   */
  0.0001,

  /* Variable: Rs
   * Referenced by:
   *   '<S173>/Gain1'
   *   '<S173>/Gain3'
   */
  0.0043333333333333331,

  /* Variable: Torque_max
   * Referenced by: '<S162>/Saturation'
   */
  6.75,

  /* Variable: Voltage_max
   * Referenced by:
   *   '<S1>/Gain5'
   *   '<S3>/Limiter'
   *   '<S3>/Limiter 1'
   *   '<S45>/Integrator'
   *   '<S52>/Saturation'
   *   '<S97>/Integrator'
   *   '<S104>/Saturation'
   */
  86.4,

  /* Variable: g
   * Referenced by: '<S174>/Constant2'
   */
  9.8,

  /* Variable: lambda
   * Referenced by:
   *   '<S3>/Gain6'
   *   '<S5>/Gain4'
   *   '<S173>/Gain4'
   *   '<S173>/Gain5'
   */
  0.0375,

  /* Variable: m
   * Referenced by: '<S174>/Constant2'
   */
  1.0,

  /* Variable: ppair
   * Referenced by:
   *   '<S3>/Gain2'
   *   '<S3>/Gain6'
   *   '<S3>/Gain7'
   *   '<S4>/Gain6'
   *   '<S173>/Constant'
   *   '<S173>/Constant1'
   *   '<S173>/Gain4'
   *   '<S173>/Gain5'
   *   '<S173>/Gain6'
   */
  4.0,

  /* Variable: rho
   * Referenced by: '<S174>/Constant1'
   */
  1.2,

  /* Variable: speed_max
   * Referenced by: '<S3>/Saturation'
   */
  523.59877559829886,

  /* Mask Parameter: dq0toAlphaBetaZero_Alignment
   * Referenced by: '<S184>/Constant'
   */
  1.0,

  /* Mask Parameter: AlphaBetaZerotodq0_Alignment
   * Referenced by: '<S115>/Constant'
   */
  1.0,

  /* Mask Parameter: AlphaBetaZerotodq0_Alignment_n
   * Referenced by: '<S177>/Constant'
   */
  1.0,

  /* Mask Parameter: SpeedPD_D
   * Referenced by: '<S148>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: I_dqPID_I
   * Referenced by: '<S42>/Integral Gain'
   */
  7.0005743607815,

  /* Mask Parameter: I_dqPID3_I
   * Referenced by: '<S94>/Integral Gain'
   */
  7.0005743607815,

  /* Mask Parameter: SpeedPD_InitialConditionForFilt
   * Referenced by: '<S150>/Filter'
   */
  0.0,

  /* Mask Parameter: I_dqPID3_InitialConditionForInt
   * Referenced by: '<S97>/Integrator'
   */
  0.0,

  /* Mask Parameter: I_dqPID_InitialConditionForInte
   * Referenced by: '<S45>/Integrator'
   */
  0.0,

  /* Mask Parameter: SpeedPD_N
   * Referenced by: '<S158>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: SpeedPD_P
   * Referenced by: '<S160>/Proportional Gain'
   */
  20.75762,

  /* Mask Parameter: I_dqPID3_P
   * Referenced by: '<S102>/Proportional Gain'
   */
  0.199995991549269,

  /* Mask Parameter: I_dqPID_P
   * Referenced by: '<S50>/Proportional Gain'
   */
  0.199995991549269,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S185>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S186>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant_const_o
   * Referenced by: '<S117>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant1_const_k
   * Referenced by: '<S118>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant_const_i
   * Referenced by: '<S179>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant1_const_m
   * Referenced by: '<S180>/Constant'
   */
  2.0,

  /* Expression: [0,0]
   * Referenced by: '<S187>/alpha_beta'
   */
  { 0.0, 0.0 },

  /* Expression: [0,0]
   * Referenced by: '<S188>/alpha_beta'
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

  /* Expression: 100
   * Referenced by: '<S2>/Gain'
   */
  100.0,

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
  50000.0,

  /* Computed Parameter: LEDHeartbeat_Duty
   * Referenced by: '<S2>/LED Heartbeat'
   */
  25000.0,

  /* Expression: 0
   * Referenced by: '<S2>/LED Heartbeat'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S174>/Transfer Fcn'
   */
  -0.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S174>/Transfer Fcn'
   */
  1.2043769950504923,

  /* Expression: 45
   * Referenced by: '<Root>/Step1'
   */
  45.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step1'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<Root>/Step1'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<S173>/Integrator2'
   */
  0.0,

  /* Expression: 3.40282347E+38
   * Referenced by: '<S173>/Integrator2'
   */
  3.40282347E+38,

  /* Expression: -3.40282347E+38
   * Referenced by: '<S173>/Integrator2'
   */
  -3.40282347E+38,

  /* Expression: 0
   * Referenced by: '<S173>/Integrator'
   */
  0.0,

  /* Expression: 3.40282347E+38
   * Referenced by: '<S173>/Integrator'
   */
  3.40282347E+38,

  /* Expression: -3.40282347E+38
   * Referenced by: '<S173>/Integrator'
   */
  -3.40282347E+38,

  /* Expression: 0
   * Referenced by: '<S173>/Integrator1'
   */
  0.0,

  /* Expression: 3.40282347E+38
   * Referenced by: '<S173>/Integrator1'
   */
  3.40282347E+38,

  /* Expression: -3.40282347E+38
   * Referenced by: '<S173>/Integrator1'
   */
  -3.40282347E+38,

  /* Expression: 0
   * Referenced by: '<S4>/Constant3'
   */
  0.0,

  /* Expression: [ 1   0   1; -1/2  sqrt(3)/2   1; -1/2  -sqrt(3)/2  1 ]
   * Referenced by: '<S183>/Gain3'
   */
  { 1.0, -0.5, -0.5, 0.0, 0.8660254037844386, -0.8660254037844386, 1.0, 1.0, 1.0
  },

  /* Expression: 40
   * Referenced by: '<Root>/Step'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<Root>/Step'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Switch'
   */
  0.0,

  /* Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ]
   * Referenced by: '<S116>/Gain3'
   */
  { 1.0, 0.0, 0.5, -0.5, 0.8660254037844386, 0.5, -0.5, -0.8660254037844386, 0.5
  },

  /* Expression: 2/3
   * Referenced by: '<S116>/Gain1'
   */
  0.66666666666666663,

  /* Expression: 0
   * Referenced by: '<S3>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Limiter 1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Limiter'
   */
  0.0,

  /* Expression: -2*pi/3
   * Referenced by: '<S8>/Bias'
   */
  -2.0943951023931953,

  /* Expression: 2*pi/3
   * Referenced by: '<S8>/Bias1'
   */
  2.0943951023931953,

  /* Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ]
   * Referenced by: '<S178>/Gain3'
   */
  { 1.0, 0.0, 0.5, -0.5, 0.8660254037844386, 0.5, -0.5, -0.8660254037844386, 0.5
  },

  /* Expression: 2/3
   * Referenced by: '<S178>/Gain1'
   */
  0.66666666666666663,

  /* Expression: 1/k^2
   * Referenced by: '<S174>/Gain'
   */
  1.0,

  /* Start of '<S177>/Subsystem1' */
  {
    /* Expression: [0,0]
     * Referenced by: '<S182>/dq'
     */
    { 0.0, 0.0 }
  }
  ,

  /* End of '<S177>/Subsystem1' */

  /* Start of '<S177>/Subsystem - pi//2 delay' */
  {
    /* Expression: [0,0]
     * Referenced by: '<S181>/dq'
     */
    { 0.0, 0.0 }
  }
  ,

  /* End of '<S177>/Subsystem - pi//2 delay' */

  /* Start of '<S115>/Subsystem1' */
  {
    /* Expression: [0,0]
     * Referenced by: '<S120>/dq'
     */
    { 0.0, 0.0 }
  }
  ,

  /* End of '<S115>/Subsystem1' */

  /* Start of '<S115>/Subsystem - pi//2 delay' */
  {
    /* Expression: [0,0]
     * Referenced by: '<S119>/dq'
     */
    { 0.0, 0.0 }
  }
  /* End of '<S115>/Subsystem - pi//2 delay' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
