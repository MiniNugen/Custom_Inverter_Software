/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware_data.c
 *
 * Code generated for Simulink model 'Main_Firmware'.
 *
 * Model version                  : 2.32
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sat Jul 12 16:27:19 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Main_Firmware.h"

/* Block parameters (default storage) */
P_Main_Firmware_T Main_Firmware_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S6>/Constant'
   */
  46.6690483F,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S7>/Constant'
   */
  575.958679F,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S8>/Constant'
   */
  10.500536F,

  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S9>/Constant'
   */
  132.0F,

  /* Expression: 1
   * Referenced by: '<S2>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant2'
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

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S4>/Gain2'
   */
  0.000805664051F,

  /* Computed Parameter: Bias1_Bias
   * Referenced by: '<S5>/Bias1'
   */
  -1.65F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S5>/Gain'
   */
  41.6666679F,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S4>/Gain1'
   */
  0.000805664051F,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<Root>/Constant'
   */
  false
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
