/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware_private.h
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

#ifndef Main_Firmware_private_h_
#define Main_Firmware_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Main_Firmware_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

void InitAdcC (void);
void config_ADCC_SOC1 (void);
void config_ADCC_SOC2 (void);
void InitAdcA (void);
void config_ADCA_SOC3 (void);
void InitAdcB (void);
void config_ADCB_SOC0 (void);
void config_ADCA_SOC8 (void);
extern uint16_T MW_adcCInitFlag;
extern uint16_T MW_adcAInitFlag;
extern uint16_T MW_adcBInitFlag;

#endif                                 /* Main_Firmware_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
