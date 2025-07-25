/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware.h
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

void MW_InitSysPll(uint16_T clock_source, uint16_T imult, uint16_T fmult,
                   uint16_T odiv, uint16_T divsel);
extern void executeOverrunService();
extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals for system '<S6>/Lowpass Filter1' */
typedef struct {
  real32_T LowpassFilter1;             /* '<S6>/Lowpass Filter1' */
} B_LowpassFilter1_Main_Firmwar_T;

/* Block states (default storage) for system '<S6>/Lowpass Filter1' */
typedef struct {
  dsp_simulink_LowpassFilter_Ma_T obj; /* '<S6>/Lowpass Filter1' */
  boolean_T objisempty;                /* '<S6>/Lowpass Filter1' */
  boolean_T isInitialized;             /* '<S6>/Lowpass Filter1' */
  boolean_T isInitialized_e;           /* '<S6>/Lowpass Filter1' */
} DW_LowpassFilter1_Main_Firmwa_T;

/* Block signals for system '<S6>/Lowpass Filter3' */
typedef struct {
  real32_T LowpassFilter3;             /* '<S6>/Lowpass Filter3' */
} B_LowpassFilter3_Main_Firmwar_T;

/* Block states (default storage) for system '<S6>/Lowpass Filter3' */
typedef struct {
  dsp_simulink_LowpassFilter_j_T obj;  /* '<S6>/Lowpass Filter3' */
  boolean_T objisempty;                /* '<S6>/Lowpass Filter3' */
  boolean_T isInitialized;             /* '<S6>/Lowpass Filter3' */
  boolean_T isInitialized_b;           /* '<S6>/Lowpass Filter3' */
} DW_LowpassFilter3_Main_Firmwa_T;

/* Block signals (default storage) */
typedef struct {
  real_T Gain1[3];                     /* '<S2>/Gain1' */
  real_T Constant4;                    /* '<Root>/Constant4' */
  real_T LEDHeartbeat;                 /* '<Root>/LED Heartbeat' */
  real32_T ADC5;                       /* '<S5>/ADC5' */
  real32_T ADC6;                       /* '<S5>/ADC6' */
  real32_T ADC7;                       /* '<S5>/ADC7' */
  real32_T I_ABC[3];                   /* '<S6>/Gain' */
  real32_T Bias2;                      /* '<S6>/Bias2' */
  real32_T Bias3;                      /* '<S6>/Bias3' */
  real32_T Bias4;                      /* '<S6>/Bias4' */
  real32_T TmpSignalConversionAtGain3Inpor[3];
                               /* '<S123>/TmpSignal ConversionAtGain3Inport1' */
  real32_T Max;                        /* '<S4>/Max' */
  real32_T VCos;                       /* '<S5>/ADC' */
  real32_T VSine;                      /* '<S5>/ADC1' */
  real32_T Gain1_p[2];                 /* '<S5>/Gain1' */
  real32_T Gain;                       /* '<Root>/Gain' */
  real32_T Abs2;                       /* '<S4>/Abs2' */
  real32_T Saturation;                 /* '<S3>/Saturation' */
  real32_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux5_at_outport_0Inport1' */
  real32_T Saturation1;                /* '<S3>/Saturation1' */
  real32_T TmpSignalConversionAtTAQSigLo_m[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux4_at_outport_0Inport1' */
  real32_T Gain1_l[3];                 /* '<S123>/Gain1' */
  real32_T Switch[2];                  /* '<S122>/Switch' */
  real32_T TmpSignalConversionAtTAQSigLo_j[3];
  /* '<S3>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Park Transform_at_outport_0Inport1' */
  real32_T TmpRTBAtMainScope2Inport3[3];
  real32_T I_ABC_a[3];
  real32_T I_ABC_av[3];                /* '<S6>/Gain' */
  real32_T a;                          /* '<S14>/Add1' */
  real32_T b;                          /* '<S14>/Add3' */
  real32_T c;                          /* '<S14>/Add2' */
  real32_T TmpSignalConversionAtTAQSigLo_d[3];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_From17_at_outport_0Inport1' */
  real32_T a_l[3];
  real32_T v_SineCos[2];
  real32_T SINECOSADC[2];
  real32_T Merge[5];                   /* '<S2>/Merge' */
  real32_T Fcn;                        /* '<S127>/Fcn' */
  real32_T Fcn1;                       /* '<S127>/Fcn1' */
  real32_T Fcn_n;                      /* '<S126>/Fcn' */
  real32_T Fcn1_f;                     /* '<S126>/Fcn1' */
  int16_T DataTypeConversion;          /* '<S2>/Data Type Conversion' */
  boolean_T Compare;                   /* '<S182>/Compare' */
  boolean_T Compare_l;                 /* '<S183>/Compare' */
  boolean_T AND;                       /* '<S4>/AND' */
  B_LowpassFilter1_Main_Firmwar_T LowpassFilter5;/* '<S6>/Lowpass Filter1' */
  B_LowpassFilter3_Main_Firmwar_T LowpassFilter4;/* '<S6>/Lowpass Filter3' */
  B_LowpassFilter3_Main_Firmwar_T LowpassFilter3;/* '<S6>/Lowpass Filter3' */
  B_LowpassFilter1_Main_Firmwar_T LowpassFilter2;/* '<S6>/Lowpass Filter1' */
  B_LowpassFilter1_Main_Firmwar_T LowpassFilter1;/* '<S6>/Lowpass Filter1' */
} B_Main_Firmware_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S52>/Integrator' */
  struct {
    void *LoggedData[4];
  } MainScope1_PWORK;                  /* '<Root>/Main Scope1' */

  struct {
    void *LoggedData[3];
  } MainScope2_PWORK;                  /* '<S6>/Main Scope2' */

  struct {
    void *LoggedData[3];
  } MainScope2_PWORK_a;                /* '<Root>/Main Scope2' */

  real32_T UD_DSTATE;                  /* '<S128>/UD' */
  real32_T Delay1_DSTATE;              /* '<S129>/Delay1' */
  real32_T Delay2_DSTATE[2];           /* '<S129>/Delay2' */
  real32_T Filter_DSTATE;              /* '<S159>/Filter' */
  real32_T Integrator_DSTATE_i;        /* '<S104>/Integrator' */
  real32_T TmpRTBAtMainScope2Inport3_Buffe[3];/* synthesized block */
  real32_T TmpRTBAtMainScope2Inport3_Buf_o[3];/* synthesized block */
  real32_T I_ABC_Buffer[3];            /* synthesized block */
  real32_T a_Buffer[3];                /* synthesized block */
  real32_T v_SineCos_Buffer[2];        /* synthesized block */
  real32_T v_SineCos_Buffer_m[2];      /* synthesized block */
  int32_T clockTickCounter;            /* '<Root>/LED Heartbeat' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<Root>/Digital Output' */
  int16_T Subsystem1_SubsysRanBC;      /* '<S122>/Subsystem1' */
  int16_T Subsystempi2delay_SubsysRanBC;/* '<S122>/Subsystem - pi//2 delay' */
  int16_T FaultState_SubsysRanBC;      /* '<S2>/Fault State' */
  int16_T RegenMode_SubsysRanBC;       /* '<S2>/Regen Mode' */
  int16_T SwitchCaseActionSubsystem2_Subs;
                                      /* '<S2>/Switch Case Action Subsystem2' */
  DW_LowpassFilter1_Main_Firmwa_T LowpassFilter5;/* '<S6>/Lowpass Filter1' */
  DW_LowpassFilter3_Main_Firmwa_T LowpassFilter4;/* '<S6>/Lowpass Filter3' */
  DW_LowpassFilter3_Main_Firmwa_T LowpassFilter3;/* '<S6>/Lowpass Filter3' */
  DW_LowpassFilter1_Main_Firmwa_T LowpassFilter2;/* '<S6>/Lowpass Filter1' */
  DW_LowpassFilter1_Main_Firmwa_T LowpassFilter1;/* '<S6>/Lowpass Filter1' */
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
                                        * Referenced by: '<S11>/Gain3'
                                        */
  real32_T Torque_max;                 /* Variable: Torque_max
                                        * Referenced by:
                                        *   '<S3>/Saturation1'
                                        *   '<S171>/Saturation'
                                        */
  real32_T lambda;                     /* Variable: lambda
                                        * Referenced by: '<S11>/Gain4'
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
                                  * Referenced by: '<S122>/Constant'
                                  */
  real_T I_dqPID1_I;                   /* Mask Parameter: I_dqPID1_I
                                        * Referenced by: '<S49>/Integral Gain'
                                        */
  real_T I_dqPID1_InitialConditionForInt;
                              /* Mask Parameter: I_dqPID1_InitialConditionForInt
                               * Referenced by: '<S52>/Integrator'
                               */
  real_T I_dqPID1_P;                   /* Mask Parameter: I_dqPID1_P
                                        * Referenced by: '<S57>/Proportional Gain'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S124>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S125>/Constant'
                                      */
  real32_T SpeedPID1_D;                /* Mask Parameter: SpeedPID1_D
                                        * Referenced by: '<S157>/Derivative Gain'
                                        */
  real32_T I_dqPID2_I;                 /* Mask Parameter: I_dqPID2_I
                                        * Referenced by: '<S101>/Integral Gain'
                                        */
  real32_T DiscreteDerivativecalc2_ICPrevS;
                              /* Mask Parameter: DiscreteDerivativecalc2_ICPrevS
                               * Referenced by: '<S128>/UD'
                               */
  real32_T SpeedPID1_InitialConditionForFi;
                              /* Mask Parameter: SpeedPID1_InitialConditionForFi
                               * Referenced by: '<S159>/Filter'
                               */
  real32_T I_dqPID2_InitialConditionForInt;
                              /* Mask Parameter: I_dqPID2_InitialConditionForInt
                               * Referenced by: '<S104>/Integrator'
                               */
  real32_T I_dqPID2_LowerIntegratorSaturat;
                              /* Mask Parameter: I_dqPID2_LowerIntegratorSaturat
                               * Referenced by: '<S104>/Integrator'
                               */
  real32_T SpeedPID1_LowerSaturationLimit;
                               /* Mask Parameter: SpeedPID1_LowerSaturationLimit
                                * Referenced by: '<S171>/Saturation'
                                */
  real32_T SpeedPID1_N;                /* Mask Parameter: SpeedPID1_N
                                        * Referenced by: '<S167>/Filter Coefficient'
                                        */
  real32_T SpeedPID1_P;                /* Mask Parameter: SpeedPID1_P
                                        * Referenced by: '<S169>/Proportional Gain'
                                        */
  real32_T I_dqPID2_P;                 /* Mask Parameter: I_dqPID2_P
                                        * Referenced by: '<S109>/Proportional Gain'
                                        */
  real32_T CompareToConstant_const_k;
                                    /* Mask Parameter: CompareToConstant_const_k
                                     * Referenced by: '<S182>/Constant'
                                     */
  real32_T CompareToConstant1_const_h;
                                   /* Mask Parameter: CompareToConstant1_const_h
                                    * Referenced by: '<S183>/Constant'
                                    */
  real_T SineWave_Amp;                 /* Expression: 0.43
                                        * Referenced by: '<S2>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0.43
                                        * Referenced by: '<S2>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 0.1*2*pi
                                        * Referenced by: '<S2>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave'
                                        */
  real_T SineWave2_Amp;                /* Expression: 0.43
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave2_Bias;               /* Expression: 0.43
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave2_Freq;               /* Expression: 0.1*2*pi
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave2_Phase;              /* Expression: 2*pi/3
                                        * Referenced by: '<S2>/Sine Wave2'
                                        */
  real_T SineWave1_Amp;                /* Expression: 0.43
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0.43
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: 0.1*2*pi
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: -2*pi/3
                                        * Referenced by: '<S2>/Sine Wave1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S52>/Integrator'
                                        */
  real_T Integrator_UpperSat;      /* Expression: UpperIntegratorSaturationLimit
                                    * Referenced by: '<S52>/Integrator'
                                    */
  real_T Integrator_LowerSat;      /* Expression: LowerIntegratorSaturationLimit
                                    * Referenced by: '<S52>/Integrator'
                                    */
  real_T Limiter1_UpperSat;            /* Expression: Voltage_max
                                        * Referenced by: '<S3>/Limiter 1'
                                        */
  real_T Limiter1_LowerSat;            /* Expression: 0
                                        * Referenced by: '<S3>/Limiter 1'
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
                                        * Referenced by: '<S129>/Bias'
                                        */
  real32_T Constant1_Value_f;          /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real32_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S9>/Constant'
                                        */
  real32_T Constant2_Value_h;          /* Computed Parameter: Constant2_Value_h
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real32_T Constant5_Value;            /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S9>/Constant5'
                                        */
  real32_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S8>/Constant'
                                        */
  real32_T Constant1_Value_h;          /* Computed Parameter: Constant1_Value_h
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real32_T Constant3_Value_m;          /* Computed Parameter: Constant3_Value_m
                                        * Referenced by: '<S8>/Constant3'
                                        */
  real32_T Constant4_Value_k;          /* Computed Parameter: Constant4_Value_k
                                        * Referenced by: '<S8>/Constant4'
                                        */
  real32_T Constant5_Value_j;          /* Computed Parameter: Constant5_Value_j
                                        * Referenced by: '<S8>/Constant5'
                                        */
  real32_T dq_Y0[2];                   /* Computed Parameter: dq_Y0
                                        * Referenced by: '<S126>/dq'
                                        */
  real32_T dq_Y0_c[2];                 /* Computed Parameter: dq_Y0_c
                                        * Referenced by: '<S127>/dq'
                                        */
  real32_T Constant3_Value_j;          /* Computed Parameter: Constant3_Value_j
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real32_T Bias1_Bias;                 /* Computed Parameter: Bias1_Bias
                                        * Referenced by: '<S6>/Bias1'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S6>/Gain'
                                        */
  real32_T Bias2_Bias;                 /* Computed Parameter: Bias2_Bias
                                        * Referenced by: '<S6>/Bias2'
                                        */
  real32_T Bias3_Bias;                 /* Computed Parameter: Bias3_Bias
                                        * Referenced by: '<S6>/Bias3'
                                        */
  real32_T Bias4_Bias;                 /* Computed Parameter: Bias4_Bias
                                        * Referenced by: '<S6>/Bias4'
                                        */
  real32_T Gain1_Gain_n;               /* Computed Parameter: Gain1_Gain_n
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real32_T Bias_Bias_j;                /* Computed Parameter: Bias_Bias_j
                                        * Referenced by: '<S6>/Bias'
                                        */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S128>/TSamp'
                                        */
  real32_T Delay1_InitialCondition;
                                  /* Computed Parameter: Delay1_InitialCondition
                                   * Referenced by: '<S129>/Delay1'
                                   */
  real32_T Delay2_InitialCondition;
                                  /* Computed Parameter: Delay2_InitialCondition
                                   * Referenced by: '<S129>/Delay2'
                                   */
  real32_T Constant1_Value_b;          /* Computed Parameter: Constant1_Value_b
                                        * Referenced by: '<S129>/Constant1'
                                        */
  real32_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S129>/Constant'
                                        */
  real32_T Gain_Gain_n;                /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<Root>/Gain'
                                        */
  real32_T Constant1_Value_k;          /* Computed Parameter: Constant1_Value_k
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S3>/Saturation'
                                       */
  real32_T Filter_gainval;             /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S159>/Filter'
                                        */
  real32_T Saturation1_LowerSat;     /* Computed Parameter: Saturation1_LowerSat
                                      * Referenced by: '<S3>/Saturation1'
                                      */
  real32_T Gain3_Gain_m[9];            /* Computed Parameter: Gain3_Gain_m
                                        * Referenced by: '<S123>/Gain3'
                                        */
  real32_T Gain1_Gain_i;               /* Computed Parameter: Gain1_Gain_i
                                        * Referenced by: '<S123>/Gain1'
                                        */
  real32_T Gain6_Gain;                 /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<S3>/Gain6'
                                        */
  real32_T Limiter1_LowerSat_m;       /* Computed Parameter: Limiter1_LowerSat_m
                                       * Referenced by: '<S3>/Limiter1'
                                       */
  real32_T Integrator_gainval_p;     /* Computed Parameter: Integrator_gainval_p
                                      * Referenced by: '<S104>/Integrator'
                                      */
  real32_T Integrator_UpperSat_b;  /* Expression: UpperIntegratorSaturationLimit
                                    * Referenced by: '<S104>/Integrator'
                                    */
  real32_T Gain1_Gain_k;               /* Computed Parameter: Gain1_Gain_k
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real32_T Limiter_UpperSat;           /* Expression: Voltage_max
                                        * Referenced by: '<S3>/Limiter'
                                        */
  real32_T Limiter_LowerSat;           /* Computed Parameter: Limiter_LowerSat
                                        * Referenced by: '<S3>/Limiter'
                                        */
  real32_T Bias_Bias_o;                /* Computed Parameter: Bias_Bias_o
                                        * Referenced by: '<S14>/Bias'
                                        */
  real32_T Bias1_Bias_c;               /* Computed Parameter: Bias1_Bias_c
                                        * Referenced by: '<S14>/Bias1'
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
    struct {
      uint16_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Main_Firmware_T Main_Firmware_P;

/* Block signals (default storage) */
extern B_Main_Firmware_T Main_Firmware_B;

/* Block states (default storage) */
extern DW_Main_Firmware_T Main_Firmware_DW;

/* External function called from main */
extern void Main_Firmware_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Main_Firmware_initialize(void);
extern void Main_Firmware_step0(void); /* Sample time: [0.0s, 0.0s] */
extern void Main_Firmware_step2(void); /* Sample time: [0.01s, 0.0s] */
extern void Main_Firmware_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Main_Firmware_T *const Main_Firmware_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant5' : Unused code path elimination
 * Block '<S1>/Constant7' : Unused code path elimination
 * Block '<S1>/Gain5' : Unused code path elimination
 * Block '<S1>/Sampling Delay' : Unused code path elimination
 * Block '<S1>/Saturation' : Unused code path elimination
 * Block '<S1>/Sum' : Unused code path elimination
 * Block '<S128>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<S7>'   : 'Main_Firmware/EPWM/Bit Concat'
 * '<S8>'   : 'Main_Firmware/EPWM/Fault State'
 * '<S9>'   : 'Main_Firmware/EPWM/Regen Mode'
 * '<S10>'  : 'Main_Firmware/EPWM/Switch Case Action Subsystem2'
 * '<S11>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Decoupling'
 * '<S12>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1'
 * '<S13>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2'
 * '<S14>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Inverse park'
 * '<S15>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Park Transform'
 * '<S16>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed Calc'
 * '<S17>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1'
 * '<S18>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Anti-windup'
 * '<S19>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/D Gain'
 * '<S20>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/External Derivative'
 * '<S21>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Filter'
 * '<S22>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Filter ICs'
 * '<S23>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/I Gain'
 * '<S24>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Ideal P Gain'
 * '<S25>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Ideal P Gain Fdbk'
 * '<S26>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Integrator'
 * '<S27>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Integrator ICs'
 * '<S28>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/N Copy'
 * '<S29>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/N Gain'
 * '<S30>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/P Copy'
 * '<S31>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Parallel P Gain'
 * '<S32>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Reset Signal'
 * '<S33>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Saturation'
 * '<S34>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Saturation Fdbk'
 * '<S35>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Sum'
 * '<S36>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Sum Fdbk'
 * '<S37>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Tracking Mode'
 * '<S38>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Tracking Mode Sum'
 * '<S39>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Tsamp - Integral'
 * '<S40>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Tsamp - Ngain'
 * '<S41>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/postSat Signal'
 * '<S42>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/preInt Signal'
 * '<S43>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/preSat Signal'
 * '<S44>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Anti-windup/Passthrough'
 * '<S45>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/D Gain/Disabled'
 * '<S46>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/External Derivative/Disabled'
 * '<S47>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Filter/Disabled'
 * '<S48>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Filter ICs/Disabled'
 * '<S49>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/I Gain/Internal Parameters'
 * '<S50>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Ideal P Gain/Passthrough'
 * '<S51>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Ideal P Gain Fdbk/Disabled'
 * '<S52>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Integrator/Discrete'
 * '<S53>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Integrator ICs/Internal IC'
 * '<S54>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/N Copy/Disabled wSignal Specification'
 * '<S55>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/N Gain/Disabled'
 * '<S56>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/P Copy/Disabled'
 * '<S57>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Parallel P Gain/Internal Parameters'
 * '<S58>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Reset Signal/Disabled'
 * '<S59>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Saturation/Passthrough'
 * '<S60>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Saturation Fdbk/Disabled'
 * '<S61>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Sum/Sum_PI'
 * '<S62>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Sum Fdbk/Disabled'
 * '<S63>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Tracking Mode/Disabled'
 * '<S64>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Tracking Mode Sum/Passthrough'
 * '<S65>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Tsamp - Integral/TsSignalSpecification'
 * '<S66>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/Tsamp - Ngain/Passthrough'
 * '<S67>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/postSat Signal/Forward_Path'
 * '<S68>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/preInt Signal/Internal PreInt'
 * '<S69>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID1/preSat Signal/Forward_Path'
 * '<S70>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Anti-windup'
 * '<S71>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/D Gain'
 * '<S72>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/External Derivative'
 * '<S73>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Filter'
 * '<S74>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Filter ICs'
 * '<S75>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/I Gain'
 * '<S76>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Ideal P Gain'
 * '<S77>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Ideal P Gain Fdbk'
 * '<S78>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Integrator'
 * '<S79>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Integrator ICs'
 * '<S80>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/N Copy'
 * '<S81>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/N Gain'
 * '<S82>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/P Copy'
 * '<S83>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Parallel P Gain'
 * '<S84>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Reset Signal'
 * '<S85>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Saturation'
 * '<S86>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Saturation Fdbk'
 * '<S87>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Sum'
 * '<S88>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Sum Fdbk'
 * '<S89>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Tracking Mode'
 * '<S90>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Tracking Mode Sum'
 * '<S91>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Tsamp - Integral'
 * '<S92>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Tsamp - Ngain'
 * '<S93>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/postSat Signal'
 * '<S94>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/preInt Signal'
 * '<S95>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/preSat Signal'
 * '<S96>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Anti-windup/Passthrough'
 * '<S97>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/D Gain/Disabled'
 * '<S98>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/External Derivative/Disabled'
 * '<S99>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Filter/Disabled'
 * '<S100>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Filter ICs/Disabled'
 * '<S101>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/I Gain/Internal Parameters'
 * '<S102>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Ideal P Gain/Passthrough'
 * '<S103>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Ideal P Gain Fdbk/Disabled'
 * '<S104>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Integrator/Discrete'
 * '<S105>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Integrator ICs/Internal IC'
 * '<S106>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/N Copy/Disabled wSignal Specification'
 * '<S107>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/N Gain/Disabled'
 * '<S108>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/P Copy/Disabled'
 * '<S109>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Parallel P Gain/Internal Parameters'
 * '<S110>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Reset Signal/Disabled'
 * '<S111>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Saturation/Passthrough'
 * '<S112>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Saturation Fdbk/Disabled'
 * '<S113>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Sum/Sum_PI'
 * '<S114>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Sum Fdbk/Disabled'
 * '<S115>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Tracking Mode/Disabled'
 * '<S116>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Tracking Mode Sum/Passthrough'
 * '<S117>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Tsamp - Integral/TsSignalSpecification'
 * '<S118>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/Tsamp - Ngain/Passthrough'
 * '<S119>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/postSat Signal/Forward_Path'
 * '<S120>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/preInt Signal/Internal PreInt'
 * '<S121>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/I_dq PID2/preSat Signal/Forward_Path'
 * '<S122>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Park Transform/Alpha-Beta-Zero to dq0'
 * '<S123>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Park Transform/abc to Alpha-Beta-Zero'
 * '<S124>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Park Transform/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S125>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Park Transform/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S126>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Park Transform/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S127>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Park Transform/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S128>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed Calc/Discrete Derivative calc2'
 * '<S129>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed Calc/Ignore Overflow'
 * '<S130>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Anti-windup'
 * '<S131>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/D Gain'
 * '<S132>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/External Derivative'
 * '<S133>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Filter'
 * '<S134>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Filter ICs'
 * '<S135>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/I Gain'
 * '<S136>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Ideal P Gain'
 * '<S137>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Ideal P Gain Fdbk'
 * '<S138>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Integrator'
 * '<S139>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Integrator ICs'
 * '<S140>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/N Copy'
 * '<S141>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/N Gain'
 * '<S142>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/P Copy'
 * '<S143>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Parallel P Gain'
 * '<S144>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Reset Signal'
 * '<S145>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Saturation'
 * '<S146>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Saturation Fdbk'
 * '<S147>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Sum'
 * '<S148>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Sum Fdbk'
 * '<S149>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Tracking Mode'
 * '<S150>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Tracking Mode Sum'
 * '<S151>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Tsamp - Integral'
 * '<S152>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Tsamp - Ngain'
 * '<S153>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/postSat Signal'
 * '<S154>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/preInt Signal'
 * '<S155>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/preSat Signal'
 * '<S156>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Anti-windup/Disabled'
 * '<S157>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/D Gain/Internal Parameters'
 * '<S158>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/External Derivative/Error'
 * '<S159>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Filter/Disc. Forward Euler Filter'
 * '<S160>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Filter ICs/Internal IC - Filter'
 * '<S161>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/I Gain/Disabled'
 * '<S162>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Ideal P Gain/Passthrough'
 * '<S163>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Ideal P Gain Fdbk/Disabled'
 * '<S164>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Integrator/Disabled'
 * '<S165>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Integrator ICs/Disabled'
 * '<S166>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/N Copy/Disabled'
 * '<S167>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/N Gain/Internal Parameters'
 * '<S168>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/P Copy/Disabled'
 * '<S169>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Parallel P Gain/Internal Parameters'
 * '<S170>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Reset Signal/Disabled'
 * '<S171>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Saturation/Enabled'
 * '<S172>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Saturation Fdbk/Disabled'
 * '<S173>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Sum/Sum_PD'
 * '<S174>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Sum Fdbk/Disabled'
 * '<S175>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Tracking Mode/Disabled'
 * '<S176>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Tracking Mode Sum/Passthrough'
 * '<S177>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Tsamp - Integral/TsSignalSpecification'
 * '<S178>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/Tsamp - Ngain/Passthrough'
 * '<S179>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/postSat Signal/Forward_Path'
 * '<S180>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/preInt Signal/Internal PreInt'
 * '<S181>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER/Speed PID1/preSat Signal/Forward_Path'
 * '<S182>' : 'Main_Firmware/HV Safety shutdown 1/Compare To Constant'
 * '<S183>' : 'Main_Firmware/HV Safety shutdown 1/Compare To Constant1'
 */
#endif                                 /* Main_Firmware_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
