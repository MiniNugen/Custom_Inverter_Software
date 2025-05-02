/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware.h
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

#ifndef Main_Firmware_h_
#define Main_Firmware_h_
#ifndef Main_Firmware_COMMON_INCLUDES_
#define Main_Firmware_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "c2000BoardSupport.h"
#include "MW_f28004x_includes.h"
#include "IQmathLib.h"
#endif                                 /* Main_Firmware_COMMON_INCLUDES_ */

#include <stddef.h>
#include "Main_Firmware_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
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

/* Block states (default storage) for system '<S116>/Subsystem - pi//2 delay' */
typedef struct {
  int16_T Subsystempi2delay_SubsysRanBC;/* '<S116>/Subsystem - pi//2 delay' */
} DW_Subsystempi2delay_Main_Fir_T;

/* Block states (default storage) for system '<S116>/Subsystem1' */
typedef struct {
  int16_T Subsystem1_SubsysRanBC;      /* '<S116>/Subsystem1' */
} DW_Subsystem1_Main_Firmware_T;

/* Block signals (default storage) */
typedef struct {
  real_T DiscreteTransferFcn;          /* '<S175>/Discrete Transfer Fcn' */
  real_T RotorAngle;                   /* '<S4>/Sum' */
  real_T TmpSignalConversionAtTAQSigLogg[3];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux5_at_outport_0Inport1' */
  real_T Gain3[3];                     /* '<S184>/Gain3' */
  real_T Te;                           /* '<S3>/Saturation1' */
  real_T Gain5;                        /* '<S174>/Gain5' */
  real_T TmpSignalConversionAtTAQSigLo_m[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux4_at_outport_0Inport1' */
  real_T Gain1[3];                     /* '<S117>/Gain1' */
  real_T Switch[2];                    /* '<S116>/Switch' */
  real_T TmpSignalConversionAtTAQSigLo_j[3];
  /* '<S3>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Park Transform_at_outport_0Inport1' */
  real_T Iq;                           /* '<S3>/Limiter1' */
  real_T a;                            /* '<S9>/Add' */
  real_T b;                            /* '<S9>/Add1' */
  real_T c;                            /* '<S9>/Add2' */
  real_T TmpSignalConversionAtGain3Inpor[3];
                               /* '<S179>/TmpSignal ConversionAtGain3Inport1' */
  real_T Sine;                         /* '<Root>/Trigonometric Function' */
  real_T Cos;                          /* '<Root>/Trigonometric Function1' */
  real_T TmpSignalConversionAtTAQSigLo_i[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  real_T Fcn;                          /* '<S189>/Fcn' */
  real_T Fcn1;                         /* '<S189>/Fcn1' */
  real_T Fcn_l;                        /* '<S188>/Fcn' */
  real_T Fcn1_a;                       /* '<S188>/Fcn1' */
  real_T Fcn_f;                        /* '<S183>/Fcn' */
  real_T Fcn1_j;                       /* '<S183>/Fcn1' */
  real_T Fcn_m;                        /* '<S182>/Fcn' */
  real_T Fcn1_i;                       /* '<S182>/Fcn1' */
  real_T Fcn_k;                        /* '<S121>/Fcn' */
  real_T Fcn1_n;                       /* '<S121>/Fcn1' */
  real_T Fcn_j;                        /* '<S120>/Fcn' */
  real_T Fcn1_e;                       /* '<S120>/Fcn1' */
  real_T Subtract;                     /* '<S175>/Subtract' */
} B_Main_Firmware_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T SamplingDelay_DSTATE[3];      /* '<S1>/Sampling Delay' */
  real_T DiscreteTransferFcn_states;   /* '<S175>/Discrete Transfer Fcn' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<S174>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S174>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S174>/Discrete-Time Integrator1' */
  real_T UD_DSTATE;                    /* '<S6>/UD' */
  real_T Filter_DSTATE;                /* '<S151>/Filter' */
  real_T Integrator_DSTATE;            /* '<S46>/Integrator' */
  real_T Integrator_DSTATE_o;          /* '<S98>/Integrator' */
  struct {
    void *LoggedData[3];
  } MainScope1_PWORK;                  /* '<Root>/Main Scope1' */

  struct {
    void *LoggedData[2];
  } MainScope2_PWORK;                  /* '<Root>/Main Scope2' */

  struct {
    void *LoggedData[4];
  } Scope_PWORK;                       /* '<S3>/Scope' */

  int32_T DigitalOutput1_FRAC_LEN;     /* '<S2>/Digital Output1' */
  int32_T clockTickCounter;            /* '<S2>/LED Heartbeat' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S2>/Digital Output' */
  int16_T Subsystem1_SubsysRanBC;      /* '<S185>/Subsystem1' */
  int16_T Subsystempi2delay_SubsysRanBC;/* '<S185>/Subsystem - pi//2 delay' */
  DW_Subsystem1_Main_Firmware_T Subsystem1_k;/* '<S178>/Subsystem1' */
  DW_Subsystempi2delay_Main_Fir_T Subsystempi2delay_o;/* '<S178>/Subsystem - pi//2 delay' */
  DW_Subsystem1_Main_Firmware_T Subsystem1;/* '<S116>/Subsystem1' */
  DW_Subsystempi2delay_Main_Fir_T Subsystempi2delay;/* '<S116>/Subsystem - pi//2 delay' */
} DW_Main_Firmware_T;

/* Parameters for system: '<S116>/Subsystem - pi//2 delay' */
struct P_Subsystempi2delay_Main_Firm_T_ {
  real_T dq_Y0[2];                     /* Expression: [0,0]
                                        * Referenced by: '<S120>/dq'
                                        */
};

/* Parameters for system: '<S116>/Subsystem1' */
struct P_Subsystem1_Main_Firmware_T_ {
  real_T dq_Y0[2];                     /* Expression: [0,0]
                                        * Referenced by: '<S121>/dq'
                                        */
};

/* Parameters (default storage) */
struct P_Main_Firmware_T_ {
  real_T A_f;                          /* Variable: A_f
                                        * Referenced by: '<S175>/Constant1'
                                        */
  real_T C_d;                          /* Variable: C_d
                                        * Referenced by: '<S175>/Constant1'
                                        */
  real_T C_rr;                         /* Variable: C_rr
                                        * Referenced by: '<S175>/Constant2'
                                        */
  real_T Current_max;                  /* Variable: Current_max
                                        * Referenced by: '<S3>/Limiter1'
                                        */
  real_T Encoder_Offset;               /* Variable: Encoder_Offset
                                        * Referenced by:
                                        *   '<S3>/Const'
                                        *   '<S4>/Constant'
                                        */
  real_T Ld;                           /* Variable: Ld
                                        * Referenced by:
                                        *   '<S5>/Gain3'
                                        *   '<S174>/Constant1'
                                        *   '<S174>/Gain'
                                        */
  real_T Lq;                           /* Variable: Lq
                                        * Referenced by:
                                        *   '<S5>/Gain1'
                                        *   '<S174>/Constant'
                                        *   '<S174>/Gain2'
                                        */
  real_T Rs;                           /* Variable: Rs
                                        * Referenced by:
                                        *   '<S174>/Gain1'
                                        *   '<S174>/Gain3'
                                        */
  real_T Torque_max;                   /* Variable: Torque_max
                                        * Referenced by:
                                        *   '<S3>/Saturation1'
                                        *   '<S163>/Saturation'
                                        */
  real_T Voltage_max;                  /* Variable: Voltage_max
                                        * Referenced by:
                                        *   '<S1>/Gain5'
                                        *   '<S3>/Limiter'
                                        *   '<S3>/Limiter 1'
                                        *   '<S46>/Integrator'
                                        *   '<S53>/Saturation'
                                        *   '<S98>/Integrator'
                                        *   '<S105>/Saturation'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by: '<S175>/Constant2'
                                        */
  real_T lambda;                       /* Variable: lambda
                                        * Referenced by:
                                        *   '<S3>/Gain6'
                                        *   '<S5>/Gain4'
                                        *   '<S174>/Gain4'
                                        *   '<S174>/Gain5'
                                        */
  real_T m;                            /* Variable: m
                                        * Referenced by: '<S175>/Constant2'
                                        */
  real_T ppair;                        /* Variable: ppair
                                        * Referenced by:
                                        *   '<S3>/Gain2'
                                        *   '<S3>/Gain6'
                                        *   '<S3>/Gain7'
                                        *   '<S4>/Gain6'
                                        *   '<S174>/Constant'
                                        *   '<S174>/Constant1'
                                        *   '<S174>/Gain4'
                                        *   '<S174>/Gain5'
                                        *   '<S174>/Gain6'
                                        */
  real_T rho;                          /* Variable: rho
                                        * Referenced by: '<S175>/Constant1'
                                        */
  real_T speed_max;                    /* Variable: speed_max
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T dq0toAlphaBetaZero_Alignment;
                                 /* Mask Parameter: dq0toAlphaBetaZero_Alignment
                                  * Referenced by: '<S185>/Constant'
                                  */
  real_T AlphaBetaZerotodq0_Alignment;
                                 /* Mask Parameter: AlphaBetaZerotodq0_Alignment
                                  * Referenced by: '<S116>/Constant'
                                  */
  real_T AlphaBetaZerotodq0_Alignment_e;
                               /* Mask Parameter: AlphaBetaZerotodq0_Alignment_e
                                * Referenced by: '<S178>/Constant'
                                */
  real_T SpeedPID1_D;                  /* Mask Parameter: SpeedPID1_D
                                        * Referenced by: '<S149>/Derivative Gain'
                                        */
  real_T I_dqPID2_I;                   /* Mask Parameter: I_dqPID2_I
                                        * Referenced by: '<S95>/Integral Gain'
                                        */
  real_T I_dqPID1_I;                   /* Mask Parameter: I_dqPID1_I
                                        * Referenced by: '<S43>/Integral Gain'
                                        */
  real_T DiscreteDerivativecalc_ICPrevSc;
                              /* Mask Parameter: DiscreteDerivativecalc_ICPrevSc
                               * Referenced by: '<S6>/UD'
                               */
  real_T SpeedPID1_InitialConditionForFi;
                              /* Mask Parameter: SpeedPID1_InitialConditionForFi
                               * Referenced by: '<S151>/Filter'
                               */
  real_T I_dqPID1_InitialConditionForInt;
                              /* Mask Parameter: I_dqPID1_InitialConditionForInt
                               * Referenced by: '<S46>/Integrator'
                               */
  real_T I_dqPID2_InitialConditionForInt;
                              /* Mask Parameter: I_dqPID2_InitialConditionForInt
                               * Referenced by: '<S98>/Integrator'
                               */
  real_T SpeedPID1_N;                  /* Mask Parameter: SpeedPID1_N
                                        * Referenced by: '<S159>/Filter Coefficient'
                                        */
  real_T SpeedPID1_P;                  /* Mask Parameter: SpeedPID1_P
                                        * Referenced by: '<S161>/Proportional Gain'
                                        */
  real_T I_dqPID1_P;                   /* Mask Parameter: I_dqPID1_P
                                        * Referenced by: '<S51>/Proportional Gain'
                                        */
  real_T I_dqPID2_P;                   /* Mask Parameter: I_dqPID2_P
                                        * Referenced by: '<S103>/Proportional Gain'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S186>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S187>/Constant'
                                      */
  real_T CompareToConstant_const_o; /* Mask Parameter: CompareToConstant_const_o
                                     * Referenced by: '<S118>/Constant'
                                     */
  real_T CompareToConstant1_const_k;
                                   /* Mask Parameter: CompareToConstant1_const_k
                                    * Referenced by: '<S119>/Constant'
                                    */
  real_T CompareToConstant_const_n; /* Mask Parameter: CompareToConstant_const_n
                                     * Referenced by: '<S180>/Constant'
                                     */
  real_T CompareToConstant1_const_n;
                                   /* Mask Parameter: CompareToConstant1_const_n
                                    * Referenced by: '<S181>/Constant'
                                    */
  real_T Constant1_Value;              /* Expression: 4
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T alpha_beta_Y0[2];             /* Expression: [0,0]
                                        * Referenced by: '<S188>/alpha_beta'
                                        */
  real_T alpha_beta_Y0_l[2];           /* Expression: [0,0]
                                        * Referenced by: '<S189>/alpha_beta'
                                        */
  real_T SamplingDelay_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S1>/Sampling Delay'
                                         */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T LEDHeartbeat_Amp;             /* Expression: 1
                                        * Referenced by: '<S2>/LED Heartbeat'
                                        */
  real_T LEDHeartbeat_Period;         /* Computed Parameter: LEDHeartbeat_Period
                                       * Referenced by: '<S2>/LED Heartbeat'
                                       */
  real_T LEDHeartbeat_Duty;            /* Computed Parameter: LEDHeartbeat_Duty
                                        * Referenced by: '<S2>/LED Heartbeat'
                                        */
  real_T LEDHeartbeat_PhaseDelay;      /* Expression: 0
                                        * Referenced by: '<S2>/LED Heartbeat'
                                        */
  real_T DiscreteTransferFcn_NumCoef;  /* Expression: [1]
                                        * Referenced by: '<S175>/Discrete Transfer Fcn'
                                        */
  real_T DiscreteTransferFcn_DenCoef[2];/* Expression: [J 0]
                                         * Referenced by: '<S175>/Discrete Transfer Fcn'
                                         */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S175>/Discrete Transfer Fcn'
                                          */
  real_T DiscreteTimeIntegrator2_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator2_gainval
                           * Referenced by: '<S174>/Discrete-Time Integrator2'
                           */
  real_T DiscreteTimeIntegrator2_IC;   /* Expression: 0
                                        * Referenced by: '<S174>/Discrete-Time Integrator2'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S174>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S174>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<S174>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S174>/Discrete-Time Integrator1'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Gain3_Gain[9];
          /* Expression: [ 1   0   1; -1/2  sqrt(3)/2   1; -1/2  -sqrt(3)/2  1 ]
           * Referenced by: '<S184>/Gain3'
           */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value_d;             /* Expression: 12
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S6>/TSamp'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S151>/Filter'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Gain3_Gain_k[9];
  /* Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ]
   * Referenced by: '<S117>/Gain3'
   */
  real_T Gain1_Gain;                   /* Expression: 2/3
                                        * Referenced by: '<S117>/Gain1'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S46>/Integrator'
                                        */
  real_T Limiter1_LowerSat;            /* Expression: 0
                                        * Referenced by: '<S3>/Limiter 1'
                                        */
  real_T Integrator_gainval_i;       /* Computed Parameter: Integrator_gainval_i
                                      * Referenced by: '<S98>/Integrator'
                                      */
  real_T Limiter_LowerSat;             /* Expression: 0
                                        * Referenced by: '<S3>/Limiter'
                                        */
  real_T Bias_Bias;                    /* Expression: -2*pi/3
                                        * Referenced by: '<S9>/Bias'
                                        */
  real_T Bias1_Bias;                   /* Expression: 2*pi/3
                                        * Referenced by: '<S9>/Bias1'
                                        */
  real_T Gain3_Gain_k3[9];
  /* Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ]
   * Referenced by: '<S179>/Gain3'
   */
  real_T Gain1_Gain_i;                 /* Expression: 2/3
                                        * Referenced by: '<S179>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/k^2
                                        * Referenced by: '<S175>/Gain'
                                        */
  P_Subsystem1_Main_Firmware_T Subsystem1_k;/* '<S178>/Subsystem1' */
  P_Subsystempi2delay_Main_Firm_T Subsystempi2delay_o;/* '<S178>/Subsystem - pi//2 delay' */
  P_Subsystem1_Main_Firmware_T Subsystem1;/* '<S116>/Subsystem1' */
  P_Subsystempi2delay_Main_Firm_T Subsystempi2delay;/* '<S116>/Subsystem - pi//2 delay' */
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
    uint32_T clockTickH0;
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
 * Block '<S6>/Data Type Duplicate' : Unused code path elimination
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
 * '<S3>'   : 'Main_Firmware/FIELD ORIENTED CONTROLLER1'
 * '<S4>'   : 'Main_Firmware/PMSM Mathematical model (Simulation)'
 * '<S5>'   : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Decoupling'
 * '<S6>'   : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Discrete Derivative calc'
 * '<S7>'   : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1'
 * '<S8>'   : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2'
 * '<S9>'   : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Inverse park'
 * '<S10>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Park Transform'
 * '<S11>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1'
 * '<S12>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Anti-windup'
 * '<S13>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/D Gain'
 * '<S14>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/External Derivative'
 * '<S15>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Filter'
 * '<S16>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Filter ICs'
 * '<S17>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/I Gain'
 * '<S18>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Ideal P Gain'
 * '<S19>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Ideal P Gain Fdbk'
 * '<S20>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Integrator'
 * '<S21>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Integrator ICs'
 * '<S22>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/N Copy'
 * '<S23>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/N Gain'
 * '<S24>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/P Copy'
 * '<S25>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Parallel P Gain'
 * '<S26>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Reset Signal'
 * '<S27>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Saturation'
 * '<S28>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Saturation Fdbk'
 * '<S29>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Sum'
 * '<S30>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Sum Fdbk'
 * '<S31>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Tracking Mode'
 * '<S32>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Tracking Mode Sum'
 * '<S33>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Tsamp - Integral'
 * '<S34>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Tsamp - Ngain'
 * '<S35>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/postSat Signal'
 * '<S36>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/preInt Signal'
 * '<S37>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/preSat Signal'
 * '<S38>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Anti-windup/Passthrough'
 * '<S39>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/D Gain/Disabled'
 * '<S40>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/External Derivative/Disabled'
 * '<S41>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Filter/Disabled'
 * '<S42>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Filter ICs/Disabled'
 * '<S43>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/I Gain/Internal Parameters'
 * '<S44>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Ideal P Gain/Passthrough'
 * '<S45>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Ideal P Gain Fdbk/Disabled'
 * '<S46>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Integrator/Discrete'
 * '<S47>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Integrator ICs/Internal IC'
 * '<S48>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/N Copy/Disabled wSignal Specification'
 * '<S49>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/N Gain/Disabled'
 * '<S50>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/P Copy/Disabled'
 * '<S51>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Parallel P Gain/Internal Parameters'
 * '<S52>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Reset Signal/Disabled'
 * '<S53>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Saturation/Enabled'
 * '<S54>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Saturation Fdbk/Disabled'
 * '<S55>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Sum/Sum_PI'
 * '<S56>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Sum Fdbk/Disabled'
 * '<S57>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Tracking Mode/Disabled'
 * '<S58>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Tracking Mode Sum/Passthrough'
 * '<S59>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Tsamp - Integral/TsSignalSpecification'
 * '<S60>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/Tsamp - Ngain/Passthrough'
 * '<S61>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/postSat Signal/Forward_Path'
 * '<S62>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/preInt Signal/Internal PreInt'
 * '<S63>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID1/preSat Signal/Forward_Path'
 * '<S64>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Anti-windup'
 * '<S65>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/D Gain'
 * '<S66>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/External Derivative'
 * '<S67>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Filter'
 * '<S68>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Filter ICs'
 * '<S69>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/I Gain'
 * '<S70>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Ideal P Gain'
 * '<S71>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Ideal P Gain Fdbk'
 * '<S72>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Integrator'
 * '<S73>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Integrator ICs'
 * '<S74>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/N Copy'
 * '<S75>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/N Gain'
 * '<S76>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/P Copy'
 * '<S77>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Parallel P Gain'
 * '<S78>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Reset Signal'
 * '<S79>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Saturation'
 * '<S80>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Saturation Fdbk'
 * '<S81>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Sum'
 * '<S82>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Sum Fdbk'
 * '<S83>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Tracking Mode'
 * '<S84>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Tracking Mode Sum'
 * '<S85>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Tsamp - Integral'
 * '<S86>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Tsamp - Ngain'
 * '<S87>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/postSat Signal'
 * '<S88>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/preInt Signal'
 * '<S89>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/preSat Signal'
 * '<S90>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Anti-windup/Passthrough'
 * '<S91>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/D Gain/Disabled'
 * '<S92>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/External Derivative/Disabled'
 * '<S93>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Filter/Disabled'
 * '<S94>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Filter ICs/Disabled'
 * '<S95>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/I Gain/Internal Parameters'
 * '<S96>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Ideal P Gain/Passthrough'
 * '<S97>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Ideal P Gain Fdbk/Disabled'
 * '<S98>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Integrator/Discrete'
 * '<S99>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Integrator ICs/Internal IC'
 * '<S100>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/N Copy/Disabled wSignal Specification'
 * '<S101>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/N Gain/Disabled'
 * '<S102>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/P Copy/Disabled'
 * '<S103>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Parallel P Gain/Internal Parameters'
 * '<S104>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Reset Signal/Disabled'
 * '<S105>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Saturation/Enabled'
 * '<S106>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Saturation Fdbk/Disabled'
 * '<S107>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Sum/Sum_PI'
 * '<S108>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Sum Fdbk/Disabled'
 * '<S109>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Tracking Mode/Disabled'
 * '<S110>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Tracking Mode Sum/Passthrough'
 * '<S111>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Tsamp - Integral/TsSignalSpecification'
 * '<S112>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/Tsamp - Ngain/Passthrough'
 * '<S113>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/postSat Signal/Forward_Path'
 * '<S114>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/preInt Signal/Internal PreInt'
 * '<S115>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID2/preSat Signal/Forward_Path'
 * '<S116>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Park Transform/Alpha-Beta-Zero to dq0'
 * '<S117>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Park Transform/abc to Alpha-Beta-Zero'
 * '<S118>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Park Transform/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S119>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Park Transform/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S120>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Park Transform/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S121>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Park Transform/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S122>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Anti-windup'
 * '<S123>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/D Gain'
 * '<S124>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/External Derivative'
 * '<S125>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Filter'
 * '<S126>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Filter ICs'
 * '<S127>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/I Gain'
 * '<S128>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Ideal P Gain'
 * '<S129>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Ideal P Gain Fdbk'
 * '<S130>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Integrator'
 * '<S131>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Integrator ICs'
 * '<S132>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/N Copy'
 * '<S133>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/N Gain'
 * '<S134>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/P Copy'
 * '<S135>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Parallel P Gain'
 * '<S136>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Reset Signal'
 * '<S137>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Saturation'
 * '<S138>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Saturation Fdbk'
 * '<S139>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Sum'
 * '<S140>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Sum Fdbk'
 * '<S141>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Tracking Mode'
 * '<S142>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Tracking Mode Sum'
 * '<S143>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Tsamp - Integral'
 * '<S144>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Tsamp - Ngain'
 * '<S145>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/postSat Signal'
 * '<S146>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/preInt Signal'
 * '<S147>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/preSat Signal'
 * '<S148>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Anti-windup/Disabled'
 * '<S149>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/D Gain/Internal Parameters'
 * '<S150>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/External Derivative/Error'
 * '<S151>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Filter/Disc. Forward Euler Filter'
 * '<S152>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Filter ICs/Internal IC - Filter'
 * '<S153>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/I Gain/Disabled'
 * '<S154>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Ideal P Gain/Passthrough'
 * '<S155>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Ideal P Gain Fdbk/Disabled'
 * '<S156>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Integrator/Disabled'
 * '<S157>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Integrator ICs/Disabled'
 * '<S158>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/N Copy/Disabled'
 * '<S159>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/N Gain/Internal Parameters'
 * '<S160>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/P Copy/Disabled'
 * '<S161>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Parallel P Gain/Internal Parameters'
 * '<S162>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Reset Signal/Disabled'
 * '<S163>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Saturation/Enabled'
 * '<S164>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Saturation Fdbk/Disabled'
 * '<S165>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Sum/Sum_PD'
 * '<S166>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Sum Fdbk/Disabled'
 * '<S167>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Tracking Mode/Disabled'
 * '<S168>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Tracking Mode Sum/Passthrough'
 * '<S169>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Tsamp - Integral/TsSignalSpecification'
 * '<S170>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/Tsamp - Ngain/Passthrough'
 * '<S171>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/postSat Signal/Forward_Path'
 * '<S172>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/preInt Signal/Internal PreInt'
 * '<S173>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PID1/preSat Signal/Forward_Path'
 * '<S174>' : 'Main_Firmware/PMSM Mathematical model (Simulation)/Machine Model in DQ'
 * '<S175>' : 'Main_Firmware/PMSM Mathematical model (Simulation)/Mechanical Model'
 * '<S176>' : 'Main_Firmware/PMSM Mathematical model (Simulation)/abc to dq0'
 * '<S177>' : 'Main_Firmware/PMSM Mathematical model (Simulation)/dq0 to abc'
 * '<S178>' : 'Main_Firmware/PMSM Mathematical model (Simulation)/abc to dq0/Alpha-Beta-Zero to dq0'
 * '<S179>' : 'Main_Firmware/PMSM Mathematical model (Simulation)/abc to dq0/abc to Alpha-Beta-Zero'
 * '<S180>' : 'Main_Firmware/PMSM Mathematical model (Simulation)/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S181>' : 'Main_Firmware/PMSM Mathematical model (Simulation)/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S182>' : 'Main_Firmware/PMSM Mathematical model (Simulation)/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S183>' : 'Main_Firmware/PMSM Mathematical model (Simulation)/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S184>' : 'Main_Firmware/PMSM Mathematical model (Simulation)/dq0 to abc/Alpha-Beta-Zero to abc'
 * '<S185>' : 'Main_Firmware/PMSM Mathematical model (Simulation)/dq0 to abc/dq0 to Alpha-Beta-Zero'
 * '<S186>' : 'Main_Firmware/PMSM Mathematical model (Simulation)/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant'
 * '<S187>' : 'Main_Firmware/PMSM Mathematical model (Simulation)/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant1'
 * '<S188>' : 'Main_Firmware/PMSM Mathematical model (Simulation)/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay'
 * '<S189>' : 'Main_Firmware/PMSM Mathematical model (Simulation)/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem1'
 */
#endif                                 /* Main_Firmware_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
