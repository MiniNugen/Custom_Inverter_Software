/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware.h
 *
 * Code generated for Simulink model 'Main_Firmware'.
 *
 * Model version                  : 2.37
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Jul 17 17:20:37 2025
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
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
  real32_T Gain1[3];                   /* '<S2>/Gain1' */
  real32_T ADC2;                       /* '<S5>/ADC2' */
  real32_T ADC3;                       /* '<S5>/ADC3' */
  real32_T ADC4;                       /* '<S5>/ADC4' */
  real32_T Gain2[3];                   /* '<S5>/Gain2' */
  real32_T I_ABC[3];                   /* '<S6>/Gain' */
  real32_T Gain1_f[3];                 /* '<S119>/Gain1' */
  real32_T VCos;                       /* '<S5>/ADC' */
  real32_T VSine;                      /* '<S5>/ADC1' */
  real32_T Gain1_g[2];                 /* '<S5>/Gain1' */
  real32_T Switch[2];                  /* '<S118>/Switch' */
  real32_T TmpSignalConversionAtTAQSigLogg[3];
  /* '<S3>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Park Transform_at_outport_0Inport1' */
  real32_T Fcn;                        /* '<S123>/Fcn' */
  real32_T Fcn1;                       /* '<S123>/Fcn1' */
  real32_T Fcn_j;                      /* '<S122>/Fcn' */
  real32_T Fcn1_e;                     /* '<S122>/Fcn1' */
  boolean_T AND;                       /* '<S4>/AND' */
} B_Main_Firmware_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T SamplingDelay_DSTATE[3];      /* '<S1>/Sampling Delay' */
  struct {
    void *LoggedData[3];
  } MainScope2_PWORK;                  /* '<Root>/Main Scope2' */

  real32_T Integrator_DSTATE;          /* '<S48>/Integrator' */
  real32_T UD_DSTATE;                  /* '<S124>/UD' */
  real32_T Delay1_DSTATE;              /* '<S125>/Delay1' */
  real32_T Delay2_DSTATE[2];           /* '<S125>/Delay2' */
  real32_T Filter_DSTATE;              /* '<S155>/Filter' */
  real32_T Integrator_DSTATE_m;        /* '<S100>/Integrator' */
  int32_T clockTickCounter;            /* '<Root>/LED Heartbeat' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<Root>/Digital Output' */
  int16_T Subsystem1_SubsysRanBC;      /* '<S118>/Subsystem1' */
  int16_T Subsystempi2delay_SubsysRanBC;/* '<S118>/Subsystem - pi//2 delay' */
} DW_Main_Firmware_T;

/* Parameters (default storage) */
struct P_Main_Firmware_T_ {
  real_T Encoder_Offset;               /* Variable: Encoder_Offset
                                        * Referenced by: '<S3>/Const'
                                        */
  real32_T Current_max;                /* Variable: Current_max
                                        * Referenced by: '<S3>/Limiter1'
                                        */
  real32_T Ld;                         /* Variable: Ld
                                        * Referenced by: '<S7>/Gain3'
                                        */
  real32_T Torque_max;                 /* Variable: Torque_max
                                        * Referenced by:
                                        *   '<S3>/Saturation1'
                                        *   '<S167>/Saturation'
                                        */
  real32_T Voltage_max;                /* Variable: Voltage_max
                                        * Referenced by:
                                        *   '<S3>/Limiter'
                                        *   '<S3>/Limiter 1'
                                        *   '<S48>/Integrator'
                                        *   '<S55>/Saturation'
                                        *   '<S100>/Integrator'
                                        *   '<S107>/Saturation'
                                        */
  real32_T lambda;                     /* Variable: lambda
                                        * Referenced by: '<S7>/Gain4'
                                        */
  real32_T ppair;                      /* Variable: ppair
                                        * Referenced by:
                                        *   '<S3>/Gain2'
                                        *   '<S3>/Gain7'
                                        */
  real32_T speed_max;                  /* Variable: speed_max
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T AlphaBetaZerotodq0_Alignment;
                                 /* Mask Parameter: AlphaBetaZerotodq0_Alignment
                                  * Referenced by: '<S118>/Constant'
                                  */
  real_T I_dqPID1_I;                   /* Mask Parameter: I_dqPID1_I
                                        * Referenced by: '<S45>/Integral Gain'
                                        */
  real_T I_dqPID1_P;                   /* Mask Parameter: I_dqPID1_P
                                        * Referenced by: '<S53>/Proportional Gain'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S120>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S121>/Constant'
                                      */
  real32_T SpeedPID1_D;                /* Mask Parameter: SpeedPID1_D
                                        * Referenced by: '<S153>/Derivative Gain'
                                        */
  real32_T I_dqPID2_I;                 /* Mask Parameter: I_dqPID2_I
                                        * Referenced by: '<S97>/Integral Gain'
                                        */
  real32_T DiscreteDerivativecalc2_ICPrevS;
                              /* Mask Parameter: DiscreteDerivativecalc2_ICPrevS
                               * Referenced by: '<S124>/UD'
                               */
  real32_T SpeedPID1_InitialConditionForFi;
                              /* Mask Parameter: SpeedPID1_InitialConditionForFi
                               * Referenced by: '<S155>/Filter'
                               */
  real32_T I_dqPID1_InitialConditionForInt;
                              /* Mask Parameter: I_dqPID1_InitialConditionForInt
                               * Referenced by: '<S48>/Integrator'
                               */
  real32_T I_dqPID2_InitialConditionForInt;
                              /* Mask Parameter: I_dqPID2_InitialConditionForInt
                               * Referenced by: '<S100>/Integrator'
                               */
  real32_T I_dqPID1_LowerIntegratorSaturat;
                              /* Mask Parameter: I_dqPID1_LowerIntegratorSaturat
                               * Referenced by: '<S48>/Integrator'
                               */
  real32_T I_dqPID2_LowerIntegratorSaturat;
                              /* Mask Parameter: I_dqPID2_LowerIntegratorSaturat
                               * Referenced by: '<S100>/Integrator'
                               */
  real32_T I_dqPID1_LowerSaturationLimit;
                                /* Mask Parameter: I_dqPID1_LowerSaturationLimit
                                 * Referenced by: '<S55>/Saturation'
                                 */
  real32_T SpeedPID1_LowerSaturationLimit;
                               /* Mask Parameter: SpeedPID1_LowerSaturationLimit
                                * Referenced by: '<S167>/Saturation'
                                */
  real32_T I_dqPID2_LowerSaturationLimit;
                                /* Mask Parameter: I_dqPID2_LowerSaturationLimit
                                 * Referenced by: '<S107>/Saturation'
                                 */
  real32_T SpeedPID1_N;                /* Mask Parameter: SpeedPID1_N
                                        * Referenced by: '<S163>/Filter Coefficient'
                                        */
  real32_T SpeedPID1_P;                /* Mask Parameter: SpeedPID1_P
                                        * Referenced by: '<S165>/Proportional Gain'
                                        */
  real32_T I_dqPID2_P;                 /* Mask Parameter: I_dqPID2_P
                                        * Referenced by: '<S105>/Proportional Gain'
                                        */
  real32_T CompareToConstant3_const; /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S180>/Constant'
                                      */
  real32_T CompareToConstant_const_m;
                                    /* Mask Parameter: CompareToConstant_const_m
                                     * Referenced by: '<S178>/Constant'
                                     */
  real32_T CompareToConstant1_const_j;
                                   /* Mask Parameter: CompareToConstant1_const_j
                                    * Referenced by: '<S179>/Constant'
                                    */
  real_T SamplingDelay_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S1>/Sampling Delay'
                                         */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Constant7_Value;              /* Expression: 0.5
                                        * Referenced by: '<S1>/Constant7'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant_Value;               /* Expression: 50
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant1_Value_p;            /* Expression: 37
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant2_Value_m;            /* Expression: 72
                                        * Referenced by: '<S2>/Constant2'
                                        */
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
  int32_T Bias_Bias;                   /* Computed Parameter: Bias_Bias
                                        * Referenced by: '<S125>/Bias'
                                        */
  real32_T dq_Y0[2];                   /* Computed Parameter: dq_Y0
                                        * Referenced by: '<S122>/dq'
                                        */
  real32_T dq_Y0_p[2];                 /* Computed Parameter: dq_Y0_p
                                        * Referenced by: '<S123>/dq'
                                        */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real32_T Saturation_UpperSat;       /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<S1>/Saturation'
                                       */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S1>/Saturation'
                                       */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real32_T Bias1_Bias;                 /* Computed Parameter: Bias1_Bias
                                        * Referenced by: '<S6>/Bias1'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S6>/Gain'
                                        */
  real32_T Gain3_Gain[9];              /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S119>/Gain3'
                                        */
  real32_T Gain1_Gain_l;               /* Computed Parameter: Gain1_Gain_l
                                        * Referenced by: '<S119>/Gain1'
                                        */
  real32_T Gain1_Gain_a;               /* Computed Parameter: Gain1_Gain_a
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real32_T Bias_Bias_g;                /* Computed Parameter: Bias_Bias_g
                                        * Referenced by: '<S6>/Bias'
                                        */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S48>/Integrator'
                                        */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S124>/TSamp'
                                        */
  real32_T Delay1_InitialCondition;
                                  /* Computed Parameter: Delay1_InitialCondition
                                   * Referenced by: '<S125>/Delay1'
                                   */
  real32_T Delay2_InitialCondition;
                                  /* Computed Parameter: Delay2_InitialCondition
                                   * Referenced by: '<S125>/Delay2'
                                   */
  real32_T Constant1_Value_i;          /* Computed Parameter: Constant1_Value_i
                                        * Referenced by: '<S125>/Constant1'
                                        */
  real32_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S125>/Constant'
                                        */
  real32_T Limiter1_LowerSat;          /* Computed Parameter: Limiter1_LowerSat
                                        * Referenced by: '<S3>/Limiter 1'
                                        */
  real32_T Constant1_Value_n;          /* Computed Parameter: Constant1_Value_n
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real32_T Saturation_LowerSat_a;   /* Computed Parameter: Saturation_LowerSat_a
                                     * Referenced by: '<S3>/Saturation'
                                     */
  real32_T Filter_gainval;             /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S155>/Filter'
                                        */
  real32_T Saturation1_LowerSat;     /* Computed Parameter: Saturation1_LowerSat
                                      * Referenced by: '<S3>/Saturation1'
                                      */
  real32_T Gain6_Gain;                 /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<S3>/Gain6'
                                        */
  real32_T Limiter1_LowerSat_j;       /* Computed Parameter: Limiter1_LowerSat_j
                                       * Referenced by: '<S3>/Limiter1'
                                       */
  real32_T Integrator_gainval_n;     /* Computed Parameter: Integrator_gainval_n
                                      * Referenced by: '<S100>/Integrator'
                                      */
  real32_T Gain1_Gain_n;               /* Computed Parameter: Gain1_Gain_n
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real32_T Limiter_LowerSat;           /* Computed Parameter: Limiter_LowerSat
                                        * Referenced by: '<S3>/Limiter'
                                        */
  real32_T Bias_Bias_e;                /* Computed Parameter: Bias_Bias_e
                                        * Referenced by: '<S10>/Bias'
                                        */
  real32_T Bias1_Bias_k;               /* Computed Parameter: Bias1_Bias_k
                                        * Referenced by: '<S10>/Bias1'
                                        */
  real32_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S1>/Gain5'
                                        */
  real32_T Gain_Gain_d;                /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Main_Firmware_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

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
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
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
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<S2>/Data Type Conversion3' : Unused code path elimination
 * Block '<S124>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition1' : Eliminated since input and output rates are identical
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
 * '<S3>'   : 'Main_Firmware/FIELD ORIENTED CONTROLLER'
 * '<S4>'   : 'Main_Firmware/HV Safety shutdown 1'
 * '<S5>'   : 'Main_Firmware/Resolver Voltage Reading'
 * '<S6>'   : 'Main_Firmware/Sine_Cos decoder'
 * '<S7>'   : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Decoupling'
 * '<S8>'   : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1'
 * '<S9>'   : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2'
 * '<S10>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Inverse park'
 * '<S11>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Park Transform'
 * '<S12>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed Calc'
 * '<S13>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1'
 * '<S14>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Anti-windup'
 * '<S15>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/D Gain'
 * '<S16>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/External Derivative'
 * '<S17>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Filter'
 * '<S18>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Filter ICs'
 * '<S19>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/I Gain'
 * '<S20>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Ideal P Gain'
 * '<S21>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Ideal P Gain Fdbk'
 * '<S22>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Integrator'
 * '<S23>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Integrator ICs'
 * '<S24>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/N Copy'
 * '<S25>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/N Gain'
 * '<S26>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/P Copy'
 * '<S27>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Parallel P Gain'
 * '<S28>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Reset Signal'
 * '<S29>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Saturation'
 * '<S30>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Saturation Fdbk'
 * '<S31>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Sum'
 * '<S32>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Sum Fdbk'
 * '<S33>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Tracking Mode'
 * '<S34>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Tracking Mode Sum'
 * '<S35>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Tsamp - Integral'
 * '<S36>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Tsamp - Ngain'
 * '<S37>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/postSat Signal'
 * '<S38>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/preInt Signal'
 * '<S39>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/preSat Signal'
 * '<S40>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Anti-windup/Passthrough'
 * '<S41>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/D Gain/Disabled'
 * '<S42>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/External Derivative/Disabled'
 * '<S43>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Filter/Disabled'
 * '<S44>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Filter ICs/Disabled'
 * '<S45>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/I Gain/Internal Parameters'
 * '<S46>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Ideal P Gain/Passthrough'
 * '<S47>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Ideal P Gain Fdbk/Disabled'
 * '<S48>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Integrator/Discrete'
 * '<S49>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Integrator ICs/Internal IC'
 * '<S50>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/N Copy/Disabled wSignal Specification'
 * '<S51>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/N Gain/Disabled'
 * '<S52>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/P Copy/Disabled'
 * '<S53>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Parallel P Gain/Internal Parameters'
 * '<S54>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Reset Signal/Disabled'
 * '<S55>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Saturation/Enabled'
 * '<S56>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Saturation Fdbk/Disabled'
 * '<S57>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Sum/Sum_PI'
 * '<S58>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Sum Fdbk/Disabled'
 * '<S59>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Tracking Mode/Disabled'
 * '<S60>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Tracking Mode Sum/Passthrough'
 * '<S61>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Tsamp - Integral/TsSignalSpecification'
 * '<S62>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Tsamp - Ngain/Passthrough'
 * '<S63>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/postSat Signal/Forward_Path'
 * '<S64>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/preInt Signal/Internal PreInt'
 * '<S65>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/preSat Signal/Forward_Path'
 * '<S66>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Anti-windup'
 * '<S67>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/D Gain'
 * '<S68>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/External Derivative'
 * '<S69>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Filter'
 * '<S70>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Filter ICs'
 * '<S71>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/I Gain'
 * '<S72>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Ideal P Gain'
 * '<S73>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Ideal P Gain Fdbk'
 * '<S74>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Integrator'
 * '<S75>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Integrator ICs'
 * '<S76>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/N Copy'
 * '<S77>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/N Gain'
 * '<S78>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/P Copy'
 * '<S79>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Parallel P Gain'
 * '<S80>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Reset Signal'
 * '<S81>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Saturation'
 * '<S82>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Saturation Fdbk'
 * '<S83>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Sum'
 * '<S84>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Sum Fdbk'
 * '<S85>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Tracking Mode'
 * '<S86>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Tracking Mode Sum'
 * '<S87>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Tsamp - Integral'
 * '<S88>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Tsamp - Ngain'
 * '<S89>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/postSat Signal'
 * '<S90>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/preInt Signal'
 * '<S91>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/preSat Signal'
 * '<S92>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Anti-windup/Passthrough'
 * '<S93>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/D Gain/Disabled'
 * '<S94>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/External Derivative/Disabled'
 * '<S95>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Filter/Disabled'
 * '<S96>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Filter ICs/Disabled'
 * '<S97>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/I Gain/Internal Parameters'
 * '<S98>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Ideal P Gain/Passthrough'
 * '<S99>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Ideal P Gain Fdbk/Disabled'
 * '<S100>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Integrator/Discrete'
 * '<S101>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Integrator ICs/Internal IC'
 * '<S102>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/N Copy/Disabled wSignal Specification'
 * '<S103>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/N Gain/Disabled'
 * '<S104>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/P Copy/Disabled'
 * '<S105>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Parallel P Gain/Internal Parameters'
 * '<S106>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Reset Signal/Disabled'
 * '<S107>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Saturation/Enabled'
 * '<S108>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Saturation Fdbk/Disabled'
 * '<S109>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Sum/Sum_PI'
 * '<S110>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Sum Fdbk/Disabled'
 * '<S111>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Tracking Mode/Disabled'
 * '<S112>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Tracking Mode Sum/Passthrough'
 * '<S113>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Tsamp - Integral/TsSignalSpecification'
 * '<S114>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Tsamp - Ngain/Passthrough'
 * '<S115>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/postSat Signal/Forward_Path'
 * '<S116>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/preInt Signal/Internal PreInt'
 * '<S117>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/preSat Signal/Forward_Path'
 * '<S118>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Park Transform/Alpha-Beta-Zero to dq0'
 * '<S119>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Park Transform/abc to Alpha-Beta-Zero'
 * '<S120>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Park Transform/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S121>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Park Transform/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S122>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Park Transform/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S123>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Park Transform/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S124>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed Calc/Discrete Derivative calc2'
 * '<S125>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed Calc/Ignore Overflow'
 * '<S126>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Anti-windup'
 * '<S127>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/D Gain'
 * '<S128>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/External Derivative'
 * '<S129>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Filter'
 * '<S130>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Filter ICs'
 * '<S131>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/I Gain'
 * '<S132>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Ideal P Gain'
 * '<S133>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Ideal P Gain Fdbk'
 * '<S134>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Integrator'
 * '<S135>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Integrator ICs'
 * '<S136>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/N Copy'
 * '<S137>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/N Gain'
 * '<S138>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/P Copy'
 * '<S139>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Parallel P Gain'
 * '<S140>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Reset Signal'
 * '<S141>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Saturation'
 * '<S142>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Saturation Fdbk'
 * '<S143>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Sum'
 * '<S144>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Sum Fdbk'
 * '<S145>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Tracking Mode'
 * '<S146>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Tracking Mode Sum'
 * '<S147>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Tsamp - Integral'
 * '<S148>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Tsamp - Ngain'
 * '<S149>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/postSat Signal'
 * '<S150>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/preInt Signal'
 * '<S151>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/preSat Signal'
 * '<S152>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Anti-windup/Disabled'
 * '<S153>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/D Gain/Internal Parameters'
 * '<S154>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/External Derivative/Error'
 * '<S155>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Filter/Disc. Forward Euler Filter'
 * '<S156>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Filter ICs/Internal IC - Filter'
 * '<S157>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/I Gain/Disabled'
 * '<S158>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Ideal P Gain/Passthrough'
 * '<S159>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Ideal P Gain Fdbk/Disabled'
 * '<S160>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Integrator/Disabled'
 * '<S161>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Integrator ICs/Disabled'
 * '<S162>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/N Copy/Disabled'
 * '<S163>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/N Gain/Internal Parameters'
 * '<S164>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/P Copy/Disabled'
 * '<S165>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Parallel P Gain/Internal Parameters'
 * '<S166>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Reset Signal/Disabled'
 * '<S167>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Saturation/Enabled'
 * '<S168>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Saturation Fdbk/Disabled'
 * '<S169>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Sum/Sum_PD'
 * '<S170>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Sum Fdbk/Disabled'
 * '<S171>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Tracking Mode/Disabled'
 * '<S172>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Tracking Mode Sum/Passthrough'
 * '<S173>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Tsamp - Integral/TsSignalSpecification'
 * '<S174>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Tsamp - Ngain/Passthrough'
 * '<S175>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/postSat Signal/Forward_Path'
 * '<S176>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/preInt Signal/Internal PreInt'
 * '<S177>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/preSat Signal/Forward_Path'
 * '<S178>' : 'Main_Firmware/HV Safety shutdown 1/Compare To Constant'
 * '<S179>' : 'Main_Firmware/HV Safety shutdown 1/Compare To Constant1'
 * '<S180>' : 'Main_Firmware/HV Safety shutdown 1/Compare To Constant3'
 */
#endif                                 /* Main_Firmware_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
