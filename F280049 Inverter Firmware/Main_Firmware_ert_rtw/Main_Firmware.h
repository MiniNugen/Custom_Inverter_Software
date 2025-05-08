/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware.h
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

#include <stddef.h>
#include "Main_Firmware_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
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

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

void MW_InitSysPll(uint16_T clock_source, uint16_T imult, uint16_T fmult,
                   uint16_T odiv, uint16_T divsel);
extern void executeOverrunService();
extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block states (default storage) for system '<S115>/Subsystem - pi//2 delay' */
typedef struct {
  int16_T Subsystempi2delay_SubsysRanBC;/* '<S115>/Subsystem - pi//2 delay' */
  boolean_T Subsystempi2delay_MODE;    /* '<S115>/Subsystem - pi//2 delay' */
} DW_Subsystempi2delay_Main_Fir_T;

/* Block states (default storage) for system '<S115>/Subsystem1' */
typedef struct {
  int16_T Subsystem1_SubsysRanBC;      /* '<S115>/Subsystem1' */
  boolean_T Subsystem1_MODE;           /* '<S115>/Subsystem1' */
} DW_Subsystem1_Main_Firmware_T;

/* Block signals (default storage) */
typedef struct {
  real_T TransferFcn;                  /* '<S174>/Transfer Fcn' */
  real_T Saturation;                   /* '<S3>/Saturation' */
  real_T RotorAngle;                   /* '<S4>/Sum' */
  real_T TmpSignalConversionAtTAQSigLogg[3];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux5_at_outport_0Inport1' */
  real_T Gain3[3];                     /* '<S183>/Gain3' */
  real_T Electricalspeed;              /* '<S3>/Gain2' */
  real_T FilterCoefficient;            /* '<S158>/Filter Coefficient' */
  real_T Te;                           /* '<S3>/Switch' */
  real_T Gain5;                        /* '<S173>/Gain5' */
  real_T TmpSignalConversionAtTAQSigLo_m[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux4_at_outport_0Inport1' */
  real_T Gain1[3];                     /* '<S116>/Gain1' */
  real_T Switch[2];                    /* '<S115>/Switch' */
  real_T TmpSignalConversionAtTAQSigLo_j[3];
  /* '<S3>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Park Transform_at_outport_0Inport1' */
  real_T a;                            /* '<S8>/Add' */
  real_T b;                            /* '<S8>/Add1' */
  real_T c;                            /* '<S8>/Add2' */
  real_T Gain5_k[3];                   /* '<S1>/Gain5' */
  real_T TmpSignalConversionAtTAQSigLo_g[3];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_From4_at_outport_0Inport1' */
  real_T Sine;                         /* '<Root>/Trigonometric Function' */
  real_T Cos;                          /* '<Root>/Trigonometric Function1' */
  real_T TmpSignalConversionAtTAQSigLo_i[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  real_T Gain;                         /* '<S173>/Gain' */
  real_T Gain2;                        /* '<S173>/Gain2' */
  real_T IntegralGain;                 /* '<S42>/Integral Gain' */
  real_T IntegralGain_a;               /* '<S94>/Integral Gain' */
  real_T Subtract;                     /* '<S174>/Subtract' */
  real_T Gain6;                        /* '<S173>/Gain6' */
  real_T Fcn;                          /* '<S188>/Fcn' */
  real_T Fcn1;                         /* '<S188>/Fcn1' */
  real_T Fcn_g;                        /* '<S187>/Fcn' */
  real_T Fcn1_l;                       /* '<S187>/Fcn1' */
  real_T Fcn_b;                        /* '<S182>/Fcn' */
  real_T Fcn1_d;                       /* '<S182>/Fcn1' */
  real_T Fcn_j;                        /* '<S181>/Fcn' */
  real_T Fcn1_k;                       /* '<S181>/Fcn1' */
  real_T Fcn_k;                        /* '<S120>/Fcn' */
  real_T Fcn1_n;                       /* '<S120>/Fcn1' */
  real_T Fcn_jc;                       /* '<S119>/Fcn' */
  real_T Fcn1_e;                       /* '<S119>/Fcn1' */
  real_T LEDHeartbeat;                 /* '<S2>/LED Heartbeat' */
  uint16_T Compare;                    /* '<S185>/Compare' */
  uint16_T Compare_o;                  /* '<S117>/Compare' */
  uint16_T Compare_n;                  /* '<S118>/Compare' */
  uint16_T Compare_g;                  /* '<S179>/Compare' */
  uint16_T Compare_b;                  /* '<S180>/Compare' */
} B_Main_Firmware_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T SamplingDelay_DSTATE[3];      /* '<S1>/Sampling Delay' */
  real_T TimeStampA;                   /* '<S3>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S3>/Derivative' */
  real_T TimeStampB;                   /* '<S3>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S3>/Derivative' */
  struct {
    void *LoggedData[3];
  } MainScope1_PWORK;                  /* '<Root>/Main Scope1' */

  struct {
    void *LoggedData[2];
  } MainScope2_PWORK;                  /* '<Root>/Main Scope2' */

  int32_T DigitalOutput1_FRAC_LEN;     /* '<S2>/Digital Output1' */
  int32_T clockTickCounter;            /* '<S2>/LED Heartbeat' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S2>/Digital Output' */
  int16_T Subsystem1_SubsysRanBC;      /* '<S184>/Subsystem1' */
  int16_T Subsystempi2delay_SubsysRanBC;/* '<S184>/Subsystem - pi//2 delay' */
  boolean_T Subsystem1_MODE;           /* '<S184>/Subsystem1' */
  boolean_T Subsystempi2delay_MODE;    /* '<S184>/Subsystem - pi//2 delay' */
  DW_Subsystem1_Main_Firmware_T Subsystem1_c;/* '<S177>/Subsystem1' */
  DW_Subsystempi2delay_Main_Fir_T Subsystempi2delay_o;/* '<S177>/Subsystem - pi//2 delay' */
  DW_Subsystem1_Main_Firmware_T Subsystem1;/* '<S115>/Subsystem1' */
  DW_Subsystempi2delay_Main_Fir_T Subsystempi2delay;/* '<S115>/Subsystem - pi//2 delay' */
} DW_Main_Firmware_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S174>/Transfer Fcn' */
  real_T Integrator2_CSTATE;           /* '<S173>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S173>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S173>/Integrator1' */
  real_T Filter_CSTATE;                /* '<S150>/Filter' */
  real_T Integrator_CSTATE_h;          /* '<S97>/Integrator' */
  real_T Integrator_CSTATE_hk;         /* '<S45>/Integrator' */
} X_Main_Firmware_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S174>/Transfer Fcn' */
  real_T Integrator2_CSTATE;           /* '<S173>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S173>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S173>/Integrator1' */
  real_T Filter_CSTATE;                /* '<S150>/Filter' */
  real_T Integrator_CSTATE_h;          /* '<S97>/Integrator' */
  real_T Integrator_CSTATE_hk;         /* '<S45>/Integrator' */
} XDot_Main_Firmware_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE;        /* '<S174>/Transfer Fcn' */
  boolean_T Integrator2_CSTATE;        /* '<S173>/Integrator2' */
  boolean_T Integrator_CSTATE;         /* '<S173>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S173>/Integrator1' */
  boolean_T Filter_CSTATE;             /* '<S150>/Filter' */
  boolean_T Integrator_CSTATE_h;       /* '<S97>/Integrator' */
  boolean_T Integrator_CSTATE_hk;      /* '<S45>/Integrator' */
} XDis_Main_Firmware_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters for system: '<S115>/Subsystem - pi//2 delay' */
struct P_Subsystempi2delay_Main_Firm_T_ {
  real_T dq_Y0[2];                     /* Expression: [0,0]
                                        * Referenced by: '<S119>/dq'
                                        */
};

/* Parameters for system: '<S115>/Subsystem1' */
struct P_Subsystem1_Main_Firmware_T_ {
  real_T dq_Y0[2];                     /* Expression: [0,0]
                                        * Referenced by: '<S120>/dq'
                                        */
};

/* Parameters (default storage) */
struct P_Main_Firmware_T_ {
  real_T A_f;                          /* Variable: A_f
                                        * Referenced by: '<S174>/Constant1'
                                        */
  real_T C_d;                          /* Variable: C_d
                                        * Referenced by: '<S174>/Constant1'
                                        */
  real_T C_rr;                         /* Variable: C_rr
                                        * Referenced by: '<S174>/Constant2'
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
                                        *   '<S173>/Constant1'
                                        *   '<S173>/Gain'
                                        */
  real_T Lq;                           /* Variable: Lq
                                        * Referenced by:
                                        *   '<S5>/Gain1'
                                        *   '<S173>/Constant'
                                        *   '<S173>/Gain2'
                                        */
  real_T Rs;                           /* Variable: Rs
                                        * Referenced by:
                                        *   '<S173>/Gain1'
                                        *   '<S173>/Gain3'
                                        */
  real_T Torque_max;                   /* Variable: Torque_max
                                        * Referenced by: '<S162>/Saturation'
                                        */
  real_T Voltage_max;                  /* Variable: Voltage_max
                                        * Referenced by:
                                        *   '<S1>/Gain5'
                                        *   '<S3>/Limiter'
                                        *   '<S3>/Limiter 1'
                                        *   '<S45>/Integrator'
                                        *   '<S52>/Saturation'
                                        *   '<S97>/Integrator'
                                        *   '<S104>/Saturation'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by: '<S174>/Constant2'
                                        */
  real_T lambda;                       /* Variable: lambda
                                        * Referenced by:
                                        *   '<S3>/Gain6'
                                        *   '<S5>/Gain4'
                                        *   '<S173>/Gain4'
                                        *   '<S173>/Gain5'
                                        */
  real_T m;                            /* Variable: m
                                        * Referenced by: '<S174>/Constant2'
                                        */
  real_T ppair;                        /* Variable: ppair
                                        * Referenced by:
                                        *   '<S3>/Gain2'
                                        *   '<S3>/Gain6'
                                        *   '<S3>/Gain7'
                                        *   '<S4>/Gain6'
                                        *   '<S173>/Constant'
                                        *   '<S173>/Constant1'
                                        *   '<S173>/Gain4'
                                        *   '<S173>/Gain5'
                                        *   '<S173>/Gain6'
                                        */
  real_T rho;                          /* Variable: rho
                                        * Referenced by: '<S174>/Constant1'
                                        */
  real_T speed_max;                    /* Variable: speed_max
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T dq0toAlphaBetaZero_Alignment;
                                 /* Mask Parameter: dq0toAlphaBetaZero_Alignment
                                  * Referenced by: '<S184>/Constant'
                                  */
  real_T AlphaBetaZerotodq0_Alignment;
                                 /* Mask Parameter: AlphaBetaZerotodq0_Alignment
                                  * Referenced by: '<S115>/Constant'
                                  */
  real_T AlphaBetaZerotodq0_Alignment_n;
                               /* Mask Parameter: AlphaBetaZerotodq0_Alignment_n
                                * Referenced by: '<S177>/Constant'
                                */
  real_T SpeedPD_D;                    /* Mask Parameter: SpeedPD_D
                                        * Referenced by: '<S148>/Derivative Gain'
                                        */
  real_T I_dqPID_I;                    /* Mask Parameter: I_dqPID_I
                                        * Referenced by: '<S42>/Integral Gain'
                                        */
  real_T I_dqPID3_I;                   /* Mask Parameter: I_dqPID3_I
                                        * Referenced by: '<S94>/Integral Gain'
                                        */
  real_T SpeedPD_InitialConditionForFilt;
                              /* Mask Parameter: SpeedPD_InitialConditionForFilt
                               * Referenced by: '<S150>/Filter'
                               */
  real_T I_dqPID3_InitialConditionForInt;
                              /* Mask Parameter: I_dqPID3_InitialConditionForInt
                               * Referenced by: '<S97>/Integrator'
                               */
  real_T I_dqPID_InitialConditionForInte;
                              /* Mask Parameter: I_dqPID_InitialConditionForInte
                               * Referenced by: '<S45>/Integrator'
                               */
  real_T SpeedPD_N;                    /* Mask Parameter: SpeedPD_N
                                        * Referenced by: '<S158>/Filter Coefficient'
                                        */
  real_T SpeedPD_P;                    /* Mask Parameter: SpeedPD_P
                                        * Referenced by: '<S160>/Proportional Gain'
                                        */
  real_T I_dqPID3_P;                   /* Mask Parameter: I_dqPID3_P
                                        * Referenced by: '<S102>/Proportional Gain'
                                        */
  real_T I_dqPID_P;                    /* Mask Parameter: I_dqPID_P
                                        * Referenced by: '<S50>/Proportional Gain'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S185>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S186>/Constant'
                                      */
  real_T CompareToConstant_const_o; /* Mask Parameter: CompareToConstant_const_o
                                     * Referenced by: '<S117>/Constant'
                                     */
  real_T CompareToConstant1_const_k;
                                   /* Mask Parameter: CompareToConstant1_const_k
                                    * Referenced by: '<S118>/Constant'
                                    */
  real_T CompareToConstant_const_i; /* Mask Parameter: CompareToConstant_const_i
                                     * Referenced by: '<S179>/Constant'
                                     */
  real_T CompareToConstant1_const_m;
                                   /* Mask Parameter: CompareToConstant1_const_m
                                    * Referenced by: '<S180>/Constant'
                                    */
  real_T alpha_beta_Y0[2];             /* Expression: [0,0]
                                        * Referenced by: '<S187>/alpha_beta'
                                        */
  real_T alpha_beta_Y0_i[2];           /* Expression: [0,0]
                                        * Referenced by: '<S188>/alpha_beta'
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
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S2>/Gain'
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
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S174>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S174>/Transfer Fcn'
                                        */
  real_T Step1_Time;                   /* Expression: 45
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 12
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S173>/Integrator2'
                                        */
  real_T Integrator2_UpperSat;         /* Expression: 3.40282347E+38
                                        * Referenced by: '<S173>/Integrator2'
                                        */
  real_T Integrator2_LowerSat;         /* Expression: -3.40282347E+38
                                        * Referenced by: '<S173>/Integrator2'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S173>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: 3.40282347E+38
                                        * Referenced by: '<S173>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: -3.40282347E+38
                                        * Referenced by: '<S173>/Integrator'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S173>/Integrator1'
                                        */
  real_T Integrator1_UpperSat;         /* Expression: 3.40282347E+38
                                        * Referenced by: '<S173>/Integrator1'
                                        */
  real_T Integrator1_LowerSat;         /* Expression: -3.40282347E+38
                                        * Referenced by: '<S173>/Integrator1'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Gain3_Gain[9];
          /* Expression: [ 1   0   1; -1/2  sqrt(3)/2   1; -1/2  -sqrt(3)/2  1 ]
           * Referenced by: '<S183>/Gain3'
           */
  real_T Step_Time;                    /* Expression: 40
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 5
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Gain3_Gain_k[9];
  /* Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ]
   * Referenced by: '<S116>/Gain3'
   */
  real_T Gain1_Gain;                   /* Expression: 2/3
                                        * Referenced by: '<S116>/Gain1'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Limiter1_LowerSat;            /* Expression: 0
                                        * Referenced by: '<S3>/Limiter 1'
                                        */
  real_T Limiter_LowerSat;             /* Expression: 0
                                        * Referenced by: '<S3>/Limiter'
                                        */
  real_T Bias_Bias;                    /* Expression: -2*pi/3
                                        * Referenced by: '<S8>/Bias'
                                        */
  real_T Bias1_Bias;                   /* Expression: 2*pi/3
                                        * Referenced by: '<S8>/Bias1'
                                        */
  real_T Gain3_Gain_g[9];
  /* Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ]
   * Referenced by: '<S178>/Gain3'
   */
  real_T Gain1_Gain_e;                 /* Expression: 2/3
                                        * Referenced by: '<S178>/Gain1'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 1/k^2
                                        * Referenced by: '<S174>/Gain'
                                        */
  P_Subsystem1_Main_Firmware_T Subsystem1_c;/* '<S177>/Subsystem1' */
  P_Subsystempi2delay_Main_Firm_T Subsystempi2delay_o;/* '<S177>/Subsystem - pi//2 delay' */
  P_Subsystem1_Main_Firmware_T Subsystem1;/* '<S115>/Subsystem1' */
  P_Subsystempi2delay_Main_Firm_T Subsystempi2delay;/* '<S115>/Subsystem - pi//2 delay' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Main_Firmware_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_Main_Firmware_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_Main_Firmware_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[7];
  real_T odeF[3][7];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tStart;
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

/* Continuous states (default storage) */
extern X_Main_Firmware_T Main_Firmware_X;

/* Disabled states (default storage) */
extern XDis_Main_Firmware_T Main_Firmware_XDis;

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
 * '<S1>'   : 'Main_Firmware/Duty Cycle Gen'
 * '<S2>'   : 'Main_Firmware/EPWM'
 * '<S3>'   : 'Main_Firmware/FIELD ORIENTED CONTROLLER1'
 * '<S4>'   : 'Main_Firmware/PMSM Mathematical model'
 * '<S5>'   : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Decoupling'
 * '<S6>'   : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID'
 * '<S7>'   : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3'
 * '<S8>'   : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Inverse park'
 * '<S9>'   : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Park Transform'
 * '<S10>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD'
 * '<S11>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Anti-windup'
 * '<S12>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/D Gain'
 * '<S13>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/External Derivative'
 * '<S14>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Filter'
 * '<S15>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Filter ICs'
 * '<S16>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/I Gain'
 * '<S17>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Ideal P Gain'
 * '<S18>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Ideal P Gain Fdbk'
 * '<S19>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Integrator'
 * '<S20>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Integrator ICs'
 * '<S21>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/N Copy'
 * '<S22>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/N Gain'
 * '<S23>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/P Copy'
 * '<S24>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Parallel P Gain'
 * '<S25>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Reset Signal'
 * '<S26>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Saturation'
 * '<S27>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Saturation Fdbk'
 * '<S28>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Sum'
 * '<S29>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Sum Fdbk'
 * '<S30>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Tracking Mode'
 * '<S31>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Tracking Mode Sum'
 * '<S32>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Tsamp - Integral'
 * '<S33>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Tsamp - Ngain'
 * '<S34>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/postSat Signal'
 * '<S35>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/preInt Signal'
 * '<S36>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/preSat Signal'
 * '<S37>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Anti-windup/Passthrough'
 * '<S38>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/D Gain/Disabled'
 * '<S39>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/External Derivative/Disabled'
 * '<S40>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Filter/Disabled'
 * '<S41>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Filter ICs/Disabled'
 * '<S42>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/I Gain/Internal Parameters'
 * '<S43>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Ideal P Gain/Passthrough'
 * '<S44>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Ideal P Gain Fdbk/Disabled'
 * '<S45>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Integrator/Continuous'
 * '<S46>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Integrator ICs/Internal IC'
 * '<S47>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/N Copy/Disabled wSignal Specification'
 * '<S48>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/N Gain/Disabled'
 * '<S49>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/P Copy/Disabled'
 * '<S50>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Parallel P Gain/Internal Parameters'
 * '<S51>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Reset Signal/Disabled'
 * '<S52>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Saturation/Enabled'
 * '<S53>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Saturation Fdbk/Disabled'
 * '<S54>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Sum/Sum_PI'
 * '<S55>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Sum Fdbk/Disabled'
 * '<S56>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Tracking Mode/Disabled'
 * '<S57>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Tracking Mode Sum/Passthrough'
 * '<S58>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Tsamp - Integral/TsSignalSpecification'
 * '<S59>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/Tsamp - Ngain/Passthrough'
 * '<S60>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/postSat Signal/Forward_Path'
 * '<S61>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/preInt Signal/Internal PreInt'
 * '<S62>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID/preSat Signal/Forward_Path'
 * '<S63>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Anti-windup'
 * '<S64>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/D Gain'
 * '<S65>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/External Derivative'
 * '<S66>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Filter'
 * '<S67>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Filter ICs'
 * '<S68>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/I Gain'
 * '<S69>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Ideal P Gain'
 * '<S70>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Ideal P Gain Fdbk'
 * '<S71>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Integrator'
 * '<S72>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Integrator ICs'
 * '<S73>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/N Copy'
 * '<S74>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/N Gain'
 * '<S75>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/P Copy'
 * '<S76>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Parallel P Gain'
 * '<S77>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Reset Signal'
 * '<S78>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Saturation'
 * '<S79>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Saturation Fdbk'
 * '<S80>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Sum'
 * '<S81>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Sum Fdbk'
 * '<S82>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Tracking Mode'
 * '<S83>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Tracking Mode Sum'
 * '<S84>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Tsamp - Integral'
 * '<S85>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Tsamp - Ngain'
 * '<S86>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/postSat Signal'
 * '<S87>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/preInt Signal'
 * '<S88>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/preSat Signal'
 * '<S89>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Anti-windup/Passthrough'
 * '<S90>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/D Gain/Disabled'
 * '<S91>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/External Derivative/Disabled'
 * '<S92>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Filter/Disabled'
 * '<S93>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Filter ICs/Disabled'
 * '<S94>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/I Gain/Internal Parameters'
 * '<S95>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Ideal P Gain/Passthrough'
 * '<S96>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Ideal P Gain Fdbk/Disabled'
 * '<S97>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Integrator/Continuous'
 * '<S98>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Integrator ICs/Internal IC'
 * '<S99>'  : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/N Copy/Disabled wSignal Specification'
 * '<S100>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/N Gain/Disabled'
 * '<S101>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/P Copy/Disabled'
 * '<S102>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Parallel P Gain/Internal Parameters'
 * '<S103>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Reset Signal/Disabled'
 * '<S104>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Saturation/Enabled'
 * '<S105>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Saturation Fdbk/Disabled'
 * '<S106>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Sum/Sum_PI'
 * '<S107>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Sum Fdbk/Disabled'
 * '<S108>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Tracking Mode/Disabled'
 * '<S109>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Tracking Mode Sum/Passthrough'
 * '<S110>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Tsamp - Integral/TsSignalSpecification'
 * '<S111>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/Tsamp - Ngain/Passthrough'
 * '<S112>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/postSat Signal/Forward_Path'
 * '<S113>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/preInt Signal/Internal PreInt'
 * '<S114>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/I_dq PID3/preSat Signal/Forward_Path'
 * '<S115>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Park Transform/Alpha-Beta-Zero to dq0'
 * '<S116>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Park Transform/abc to Alpha-Beta-Zero'
 * '<S117>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Park Transform/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S118>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Park Transform/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S119>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Park Transform/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S120>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Park Transform/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S121>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Anti-windup'
 * '<S122>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/D Gain'
 * '<S123>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/External Derivative'
 * '<S124>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Filter'
 * '<S125>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Filter ICs'
 * '<S126>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/I Gain'
 * '<S127>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Ideal P Gain'
 * '<S128>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Ideal P Gain Fdbk'
 * '<S129>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Integrator'
 * '<S130>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Integrator ICs'
 * '<S131>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/N Copy'
 * '<S132>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/N Gain'
 * '<S133>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/P Copy'
 * '<S134>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Parallel P Gain'
 * '<S135>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Reset Signal'
 * '<S136>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Saturation'
 * '<S137>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Saturation Fdbk'
 * '<S138>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Sum'
 * '<S139>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Sum Fdbk'
 * '<S140>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Tracking Mode'
 * '<S141>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Tracking Mode Sum'
 * '<S142>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Tsamp - Integral'
 * '<S143>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Tsamp - Ngain'
 * '<S144>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/postSat Signal'
 * '<S145>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/preInt Signal'
 * '<S146>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/preSat Signal'
 * '<S147>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Anti-windup/Disabled'
 * '<S148>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/D Gain/Internal Parameters'
 * '<S149>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/External Derivative/Error'
 * '<S150>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Filter/Cont. Filter'
 * '<S151>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Filter ICs/Internal IC - Filter'
 * '<S152>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/I Gain/Disabled'
 * '<S153>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Ideal P Gain/Passthrough'
 * '<S154>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Ideal P Gain Fdbk/Disabled'
 * '<S155>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Integrator/Disabled'
 * '<S156>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Integrator ICs/Disabled'
 * '<S157>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/N Copy/Disabled'
 * '<S158>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/N Gain/Internal Parameters'
 * '<S159>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/P Copy/Disabled'
 * '<S160>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Parallel P Gain/Internal Parameters'
 * '<S161>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Reset Signal/Disabled'
 * '<S162>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Saturation/Enabled'
 * '<S163>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Saturation Fdbk/Disabled'
 * '<S164>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Sum/Sum_PD'
 * '<S165>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Sum Fdbk/Disabled'
 * '<S166>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Tracking Mode/Disabled'
 * '<S167>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Tracking Mode Sum/Passthrough'
 * '<S168>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Tsamp - Integral/TsSignalSpecification'
 * '<S169>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/Tsamp - Ngain/Passthrough'
 * '<S170>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/postSat Signal/Forward_Path'
 * '<S171>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/preInt Signal/Internal PreInt'
 * '<S172>' : 'Main_Firmware/FIELD ORIENTED CONTROLLER1/Speed PD/preSat Signal/Forward_Path'
 * '<S173>' : 'Main_Firmware/PMSM Mathematical model/Machine Model in DQ'
 * '<S174>' : 'Main_Firmware/PMSM Mathematical model/Mechanical Model'
 * '<S175>' : 'Main_Firmware/PMSM Mathematical model/abc to dq0'
 * '<S176>' : 'Main_Firmware/PMSM Mathematical model/dq0 to abc'
 * '<S177>' : 'Main_Firmware/PMSM Mathematical model/abc to dq0/Alpha-Beta-Zero to dq0'
 * '<S178>' : 'Main_Firmware/PMSM Mathematical model/abc to dq0/abc to Alpha-Beta-Zero'
 * '<S179>' : 'Main_Firmware/PMSM Mathematical model/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S180>' : 'Main_Firmware/PMSM Mathematical model/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S181>' : 'Main_Firmware/PMSM Mathematical model/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S182>' : 'Main_Firmware/PMSM Mathematical model/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S183>' : 'Main_Firmware/PMSM Mathematical model/dq0 to abc/Alpha-Beta-Zero to abc'
 * '<S184>' : 'Main_Firmware/PMSM Mathematical model/dq0 to abc/dq0 to Alpha-Beta-Zero'
 * '<S185>' : 'Main_Firmware/PMSM Mathematical model/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant'
 * '<S186>' : 'Main_Firmware/PMSM Mathematical model/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant1'
 * '<S187>' : 'Main_Firmware/PMSM Mathematical model/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay'
 * '<S188>' : 'Main_Firmware/PMSM Mathematical model/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem1'
 */
#endif                                 /* Main_Firmware_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
