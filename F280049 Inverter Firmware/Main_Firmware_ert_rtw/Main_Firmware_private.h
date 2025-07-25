/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware_private.h
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

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFFFU) ) || ( SCHAR_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
void InitAdcA (void);
void config_ADCA_SOC5 (void);
void InitAdcB (void);
void config_ADCB_SOC0 (void);
void InitAdcC (void);
void config_ADCC_SOC2 (void);
void config_ADCB_SOC4 (void);
void config_ADCA_SOC6 (void);
extern uint16_T MW_adcAInitFlag;
extern uint16_T MW_adcBInitFlag;
extern uint16_T MW_adcCInitFlag;
extern void Main_Fi_LowpassFilter1_Init(DW_LowpassFilter1_Main_Firmwa_T *localDW);
extern void Main_Firmwar_LowpassFilter1(real32_T rtu_0,
  B_LowpassFilter1_Main_Firmwar_T *localB, DW_LowpassFilter1_Main_Firmwa_T
  *localDW);
extern void Main_Fi_LowpassFilter3_Init(DW_LowpassFilter3_Main_Firmwa_T *localDW);
extern void Main_Firmwar_LowpassFilter3(real32_T rtu_0,
  B_LowpassFilter3_Main_Firmwar_T *localB, DW_LowpassFilter3_Main_Firmwa_T
  *localDW);
extern void Main_Fi_LowpassFilter1_Term(DW_LowpassFilter1_Main_Firmwa_T *localDW);
extern void Main_Fi_LowpassFilter3_Term(DW_LowpassFilter3_Main_Firmwa_T *localDW);

#endif                                 /* Main_Firmware_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
