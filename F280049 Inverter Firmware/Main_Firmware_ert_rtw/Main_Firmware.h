/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware.h
 *
 * Code generated for Simulink model 'Main_Firmware'.
 *
 * Model version                  : 2.32
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
<<<<<<< Updated upstream
 * C/C++ source code generated on : Sat Jul 12 16:27:19 2025
=======
 * C/C++ source code generated on : Fri Jul 11 14:41:25 2025
>>>>>>> Stashed changes
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
#include "IQmathLib.h"
#endif                                 /* Main_Firmware_COMMON_INCLUDES_ */

#include "MW_c28xAnalogSubsystem.h"
#include <stddef.h>
#include "Main_Firmware_types.h"
#include <string.h>
#include "rt_nonfinite.h"
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
extern void executeOverrunService();
extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals (default storage) */
typedef struct {
  real_T LEDHeartbeat;                 /* '<Root>/LED Heartbeat' */
  real32_T ADC2;                       /* '<S4>/ADC2' */
  real32_T ADC3;                       /* '<S4>/ADC3' */
  real32_T ADC4;                       /* '<S4>/ADC4' */
  real32_T Gain2[3];                   /* '<S4>/Gain2' */
  real32_T I_ABC[3];                   /* '<S5>/Gain' */
  real32_T VCos;                       /* '<S4>/ADC' */
  real32_T VSine;                      /* '<S4>/ADC1' */
  real32_T Gain1[2];                   /* '<S4>/Gain1' */
  boolean_T AND;                       /* '<S3>/AND' */
} B_Main_Firmware_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData[3];
  } MainScope2_PWORK;                  /* '<Root>/Main Scope2' */

  int32_T clockTickCounter;            /* '<Root>/LED Heartbeat' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<Root>/Digital Output' */
} DW_Main_Firmware_T;

/* Parameters (default storage) */
struct P_Main_Firmware_T_ {
  real32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S6>/Constant'
                                       */
  real32_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S7>/Constant'
                                      */
  real32_T CompareToConstant2_const; /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S8>/Constant'
                                      */
  real32_T CompareToConstant3_const; /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S9>/Constant'
                                      */
<<<<<<< Updated upstream
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
=======
  real_T SineWave1_Amp;                /* Expression: 50
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 50
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: 0.1*2*pi
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: -2*pi/3
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave2_Amp;                /* Expression: 50
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave2_Bias;               /* Expression: 50
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave2_Freq;               /* Expression: 0.1*2*pi
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave2_Phase;              /* Expression: 2*pi/3
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T Constant1_Value;              /* Expression: 80
                                        * Referenced by: '<S2>/Constant1'
                                        */
>>>>>>> Stashed changes
  real_T LEDHeartbeat_Amp;             /* Expression: 1
                                        * Referenced by: '<Root>/LED Heartbeat'
                                        */
  real_T LEDHeartbeat_Period;         /* Computed Parameter: LEDHeartbeat_Period
                                       * Referenced by: '<Root>/LED Heartbeat'
                                       */
  real_T LEDHeartbeat_Duty;            /* Computed Parameter: LEDHeartbeat_Duty
                                        * Referenced by: '<Root>/LED Heartbeat'
                                        */
  real_T LEDHeartbeat_PhaseDelay;      /* Expression: 0
                                        * Referenced by: '<Root>/LED Heartbeat'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real32_T Bias1_Bias;                 /* Computed Parameter: Bias1_Bias
                                        * Referenced by: '<S5>/Bias1'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S5>/Gain'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S4>/Gain1'
                                        */
  boolean_T Constant_Value;            /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
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
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
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
 * These blocks were eliminated from the model due to optimizations:
 *
<<<<<<< Updated upstream
 * Block '<S1>/Constant7' : Unused code path elimination
 * Block '<S1>/Gain5' : Unused code path elimination
 * Block '<S1>/Sampling Delay' : Unused code path elimination
 * Block '<S1>/Saturation' : Unused code path elimination
 * Block '<S1>/Sum' : Unused code path elimination
=======
 * Block '<S1>/Gain5' : Unused code path elimination
 * Block '<S1>/Sampling Delay' : Unused code path elimination
 * Block '<S1>/Saturation' : Unused code path elimination
>>>>>>> Stashed changes
 * Block '<S5>/Atan' : Unused code path elimination
 * Block '<S5>/Bias' : Unused code path elimination
 * Block '<S5>/Divide' : Unused code path elimination
 */

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
 * '<S1>'   : 'Main_Firmware/Duty Cycle Gen'
 * '<S2>'   : 'Main_Firmware/EPWM'
 * '<S3>'   : 'Main_Firmware/HV Safety shutdown 1'
 * '<S4>'   : 'Main_Firmware/Resolver Voltage Reading'
 * '<S5>'   : 'Main_Firmware/Sine_Cos decoder'
 * '<S6>'   : 'Main_Firmware/HV Safety shutdown 1/Compare To Constant'
 * '<S7>'   : 'Main_Firmware/HV Safety shutdown 1/Compare To Constant1'
 * '<S8>'   : 'Main_Firmware/HV Safety shutdown 1/Compare To Constant2'
 * '<S9>'   : 'Main_Firmware/HV Safety shutdown 1/Compare To Constant3'
 */
#endif                                 /* Main_Firmware_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
