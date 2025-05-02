/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware_private.h
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

#ifndef Main_Firmware_private_h_
#define Main_Firmware_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Main_Firmware.h"
#include "Main_Firmware_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void Main_Fir_Subsystempi2delay_Init(real_T *rty_dq, real_T *rty_dq_f,
  P_Subsystempi2delay_Main_Firm_T *localP);
extern void Main_Firmware_Subsystempi2delay(uint16_T rtu_Enable, const real_T
  rtu_alpha_beta[2], real_T rtu_wt, real_T *rty_dq, real_T *rty_dq_f,
  DW_Subsystempi2delay_Main_Fir_T *localDW);
extern void Main_Firmware_Subsystem1_Init(real_T *rty_dq, real_T *rty_dq_e,
  P_Subsystem1_Main_Firmware_T *localP);
extern void Main_Firmware_Subsystem1(uint16_T rtu_Enable, const real_T
  rtu_alpha_beta[2], real_T rtu_wt, real_T *rty_dq, real_T *rty_dq_e,
  DW_Subsystem1_Main_Firmware_T *localDW);

#endif                                 /* Main_Firmware_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
