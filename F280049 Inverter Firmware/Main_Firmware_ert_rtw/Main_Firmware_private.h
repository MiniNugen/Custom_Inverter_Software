/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware_private.h
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

#ifndef Main_Firmware_private_h_
#define Main_Firmware_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Main_Firmware.h"
#include "Main_Firmware_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern void Main_Fir_Subsystempi2delay_Init(real_T *rty_dq, real_T *rty_dq_f,
  P_Subsystempi2delay_Main_Firm_T *localP);
extern void Main__Subsystempi2delay_Disable(DW_Subsystempi2delay_Main_Fir_T
  *localDW);
extern void Main_Firmware_Subsystempi2delay(RT_MODEL_Main_Firmware_T * const
  Main_Firmware_M, uint16_T rtu_Enable, const real_T rtu_alpha_beta[2], real_T
  rtu_wt, real_T *rty_dq, real_T *rty_dq_f, DW_Subsystempi2delay_Main_Fir_T
  *localDW);
extern void Main_Firmware_Subsystem1_Init(real_T *rty_dq, real_T *rty_dq_e,
  P_Subsystem1_Main_Firmware_T *localP);
extern void Main_Firmwar_Subsystem1_Disable(DW_Subsystem1_Main_Firmware_T
  *localDW);
extern void Main_Firmware_Subsystem1(RT_MODEL_Main_Firmware_T * const
  Main_Firmware_M, uint16_T rtu_Enable, const real_T rtu_alpha_beta[2], real_T
  rtu_wt, real_T *rty_dq, real_T *rty_dq_e, DW_Subsystem1_Main_Firmware_T
  *localDW);

/* private model entry point functions */
extern void Main_Firmware_derivatives(void);

#endif                                 /* Main_Firmware_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
