/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware_data.c
 *
 * Code generated for Simulink model 'Main_Firmware'.
 *
 * Model version                  : 2.26
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed May 14 13:11:55 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Main_Firmware.h"

/* Block parameters (default storage) */
P_Main_Firmware_T Main_Firmware_P = {
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

  /* Expression: 28
   * Referenced by: '<S1>/Constant1'
   */
  28.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S2>/Gain1'
   */
  0.000805664051F,

  /* Computed Parameter: Bias_Bias
   * Referenced by: '<S3>/Bias'
   */
  -1.5F
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
