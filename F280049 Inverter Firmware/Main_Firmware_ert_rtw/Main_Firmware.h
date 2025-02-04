/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware.h
 *
 * Code generated for Simulink model 'Main_Firmware'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Feb  1 13:54:01 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Main_Firmware_h_
#define Main_Firmware_h_
#ifndef Main_Firmware_COMMON_INCLUDES_
#define Main_Firmware_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "c2000BoardSupport.h"
#include "MW_f28004x_includes.h"
#endif                                 /* Main_Firmware_COMMON_INCLUDES_ */

#include <stddef.h>
#include "Main_Firmware_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

void MW_InitSysPll(uint16_T clock_source, uint16_T imult, uint16_T fmult,
                   uint16_T odiv, uint16_T divsel);

/* Block signals (default storage) */
typedef struct {
  real_T Constant;                     /* '<S1>/Constant' */
  real_T SineWave;                     /* '<Root>/Sine Wave' */
  real_T VariablePulseGenerator;       /* '<S1>/Variable Pulse Generator' */
  real_T PropagationDelay;             /* '<S1>/Propagation Delay' */
} B_Main_Firmware_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T startTimeOfNextCycle;         /* '<S1>/Variable Pulse Generator' */
  void* TNext;                         /* '<S1>/Propagation Delay' */
  void* YNext;                         /* '<S1>/Propagation Delay' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T DigitalOutput_FRAC_LEN;      /* '<Root>/Digital Output' */
  uint32_T Head;                       /* '<S1>/Propagation Delay' */
  uint32_T Tail;                       /* '<S1>/Propagation Delay' */
  uint32_T Size;                       /* '<S1>/Propagation Delay' */
  uint32_T BufferCapacity;             /* '<S1>/Propagation Delay' */
  boolean_T nextOutput;                /* '<S1>/Variable Pulse Generator' */
  boolean_T isStartOfNextCycle;        /* '<S1>/Variable Pulse Generator' */
} DW_Main_Firmware_T;

/* Parameters (default storage) */
struct P_Main_Firmware_T_ {
  real_T PWM_Period;                   /* Mask Parameter: PWM_Period
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T SineWave_Amp;                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0.5
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 0.25*2*pi
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T delay_Value;                  /* Expression: 0.01
                                        * Referenced by: '<S1>/delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Main_Firmware_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    uint32_T clockTick3;
    struct {
      uint32_T TID[4];
    } TaskCounters;

    uint32_T CtrlRateNumTicksToNextHit[2];
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[4];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Main_Firmware_T Main_Firmware_P;

/* Block signals (default storage) */
extern B_Main_Firmware_T Main_Firmware_B;

/* Block states (default storage) */
extern DW_Main_Firmware_T Main_Firmware_DW;

/* Model entry point functions */
extern void Main_Firmware_initialize(void);
extern void Main_Firmware_step(void);
extern void Main_Firmware_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Main_Firmware_T *const Main_Firmware_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Main_Firmware'
 * '<S1>'   : 'Main_Firmware/PWM'
 */
#endif                                 /* Main_Firmware_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
