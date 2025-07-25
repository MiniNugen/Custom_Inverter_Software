/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware_types.h
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

#ifndef Main_Firmware_types_h_
#define Main_Firmware_types_h_
#include "rtwtypes.h"
#ifndef struct_tag_H1BUfwNihC3TVWVprpNrk
#define struct_tag_H1BUfwNihC3TVWVprpNrk

struct tag_H1BUfwNihC3TVWVprpNrk
{
  int16_T S0_isInitialized;
  real32_T W0_states[10];
  real32_T W1_simContextBuf[20];
  real32_T W2_simRevCoeff[11];
  int32_T W3_halideSimTBBGrainSize;
  real32_T P0_InitialStates;
  real32_T P1_Coefficients[11];
};

#endif                                 /* struct_tag_H1BUfwNihC3TVWVprpNrk */

#ifndef typedef_b_dsp_FIRFilter_0_Main_Firmwa_T
#define typedef_b_dsp_FIRFilter_0_Main_Firmwa_T

typedef struct tag_H1BUfwNihC3TVWVprpNrk b_dsp_FIRFilter_0_Main_Firmwa_T;

#endif                             /* typedef_b_dsp_FIRFilter_0_Main_Firmwa_T */

#ifndef struct_tag_MV4cL80ISm0b7q170Jwwp
#define struct_tag_MV4cL80ISm0b7q170Jwwp

struct tag_MV4cL80ISm0b7q170Jwwp
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_Main_Firmwa_T cSFunObject;
};

#endif                                 /* struct_tag_MV4cL80ISm0b7q170Jwwp */

#ifndef typedef_b_dspcodegen_FIRFilter_Main_F_T
#define typedef_b_dspcodegen_FIRFilter_Main_F_T

typedef struct tag_MV4cL80ISm0b7q170Jwwp b_dspcodegen_FIRFilter_Main_F_T;

#endif                             /* typedef_b_dspcodegen_FIRFilter_Main_F_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_Main_Firmware_T
#define typedef_cell_wrap_Main_Firmware_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_Main_Firmware_T;

#endif                                 /* typedef_cell_wrap_Main_Firmware_T */

#ifndef struct_tag_ENUXA9RFOrWuhaYpz1PVaH
#define struct_tag_ENUXA9RFOrWuhaYpz1PVaH

struct tag_ENUXA9RFOrWuhaYpz1PVaH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_Main_Firmware_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_Main_F_T *FilterObj;
  b_dspcodegen_FIRFilter_Main_F_T _pobj0;
};

#endif                                 /* struct_tag_ENUXA9RFOrWuhaYpz1PVaH */

#ifndef typedef_dsp_simulink_LowpassFilter_Ma_T
#define typedef_dsp_simulink_LowpassFilter_Ma_T

typedef struct tag_ENUXA9RFOrWuhaYpz1PVaH dsp_simulink_LowpassFilter_Ma_T;

#endif                             /* typedef_dsp_simulink_LowpassFilter_Ma_T */

#ifndef struct_tag_Sv4ltMUnANpTQaUTks1LMD
#define struct_tag_Sv4ltMUnANpTQaUTks1LMD

struct tag_Sv4ltMUnANpTQaUTks1LMD
{
  int16_T S0_isInitialized;
  real32_T W0_states[9];
  real32_T W1_simContextBuf[18];
  real32_T W2_simRevCoeff[10];
  int32_T W3_halideSimTBBGrainSize;
  real32_T P0_InitialStates;
  real32_T P1_Coefficients[10];
};

#endif                                 /* struct_tag_Sv4ltMUnANpTQaUTks1LMD */

#ifndef typedef_b_dsp_FIRFilter_0_Main_Firm_a_T
#define typedef_b_dsp_FIRFilter_0_Main_Firm_a_T

typedef struct tag_Sv4ltMUnANpTQaUTks1LMD b_dsp_FIRFilter_0_Main_Firm_a_T;

#endif                             /* typedef_b_dsp_FIRFilter_0_Main_Firm_a_T */

#ifndef struct_tag_UzQV0Gk3FM5nsHNNgrfNLD
#define struct_tag_UzQV0Gk3FM5nsHNNgrfNLD

struct tag_UzQV0Gk3FM5nsHNNgrfNLD
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_Main_Firm_a_T cSFunObject;
};

#endif                                 /* struct_tag_UzQV0Gk3FM5nsHNNgrfNLD */

#ifndef typedef_b_dspcodegen_FIRFilter_Main_l_T
#define typedef_b_dspcodegen_FIRFilter_Main_l_T

typedef struct tag_UzQV0Gk3FM5nsHNNgrfNLD b_dspcodegen_FIRFilter_Main_l_T;

#endif                             /* typedef_b_dspcodegen_FIRFilter_Main_l_T */

#ifndef struct_tag_SevztjyqLbjjrKDwBJGGu
#define struct_tag_SevztjyqLbjjrKDwBJGGu

struct tag_SevztjyqLbjjrKDwBJGGu
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_Main_Firmware_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_Main_l_T *FilterObj;
  b_dspcodegen_FIRFilter_Main_l_T _pobj0;
};

#endif                                 /* struct_tag_SevztjyqLbjjrKDwBJGGu */

#ifndef typedef_dsp_simulink_LowpassFilter_j_T
#define typedef_dsp_simulink_LowpassFilter_j_T

typedef struct tag_SevztjyqLbjjrKDwBJGGu dsp_simulink_LowpassFilter_j_T;

#endif                              /* typedef_dsp_simulink_LowpassFilter_j_T */

/* Parameters (default storage) */
typedef struct P_Main_Firmware_T_ P_Main_Firmware_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Main_Firmware_T RT_MODEL_Main_Firmware_T;

#endif                                 /* Main_Firmware_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
