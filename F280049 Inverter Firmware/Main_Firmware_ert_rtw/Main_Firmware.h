/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware.h
 *
 * Code generated for Simulink model 'Main_Firmware'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Feb 17 15:56:47 2025
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
#include "nesl_rtw.h"
#include "Main_Firmware_bbbdb992_1_gateway.h"
#endif                                 /* Main_Firmware_COMMON_INCLUDES_ */

#include <stddef.h>
#include "Main_Firmware_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
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

/* Block signals (default storage) */
typedef struct {
  real_T dv[51];
  real_T Probe[2];                     /* '<S195>/Probe' */
  real_T Gain2[3];                     /* '<S3>/Gain2' */
  real_T Gain3[3];                     /* '<S3>/Gain3' */
  real_T INPUT_1_1_1[4];               /* '<S205>/INPUT_1_1_1' */
  real_T INPUT_2_1_1[4];               /* '<S205>/INPUT_2_1_1' */
  real_T INPUT_3_1_1[4];               /* '<S205>/INPUT_3_1_1' */
  real_T INPUT_4_1_1[4];               /* '<S205>/INPUT_4_1_1' */
  real_T INPUT_5_1_1[4];               /* '<S205>/INPUT_5_1_1' */
  real_T INPUT_6_1_1[4];               /* '<S205>/INPUT_6_1_1' */
  real_T INPUT_7_1_1[4];               /* '<S205>/INPUT_7_1_1' */
  real_T STATE_1[23];                  /* '<S205>/STATE_1' */
  real_T OUTPUT_1_0[5];                /* '<S205>/OUTPUT_1_0' */
  real_T RESHAPE[3];                   /* '<S187>/RESHAPE' */
  real_T OUTPUT_1_1;                   /* '<S205>/OUTPUT_1_1' */
  real_T SpeedrequestRads1;            /* '<S1>/Speed request (Rad//s)1' */
  real_T Delay_j;                      /* '<S2>/Delay' */
  real_T RotorspeedRads;               /* '<S2>/Derivative' */
  real_T Electricalspeed;              /* '<S2>/Gain2' */
  real_T Gain1[3];                     /* '<S118>/Gain1' */
  real_T Switch[2];                    /* '<S117>/Switch' */
  real_T TmpSignalConversionAtTAQSigLogg[3];
  /* '<S2>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Park Transform_at_outport_0Inport1' */
  real_T Gain1_l;                      /* '<S11>/Gain1' */
  real_T Gain;                         /* '<S11>/Gain' */
  real_T Gain3_i;                      /* '<S11>/Gain3' */
  real_T Gain2_f;                      /* '<S11>/Gain2' */
  real_T We;                           /* '<S2>/Gain7' */
  real_T FilterCoefficient;            /* '<S159>/Filter Coefficient' */
  real_T DerivativeGain;               /* '<S43>/Derivative Gain' */
  real_T IntegralGain;                 /* '<S47>/Integral Gain' */
  real_T FilterCoefficient_e;          /* '<S53>/Filter Coefficient' */
  real_T ProportionalGain;             /* '<S55>/Proportional Gain' */
  real_T IntegralGain_k;               /* '<S97>/Integral Gain' */
  real_T FilterCoefficient_p;          /* '<S103>/Filter Coefficient' */
  real_T TrigonometricFunction;        /* '<S14>/Trigonometric Function' */
  real_T TrigonometricFunction1;       /* '<S14>/Trigonometric Function1' */
  real_T TrigonometricFunction2;       /* '<S14>/Trigonometric Function2' */
  real_T TrigonometricFunction3;       /* '<S14>/Trigonometric Function3' */
  real_T TrigonometricFunction4;       /* '<S14>/Trigonometric Function4' */
  real_T TrigonometricFunction5;       /* '<S14>/Trigonometric Function5' */
  real_T IntegralGain_b;               /* '<S153>/Integral Gain' */
  real_T Sum[3];                       /* '<S1>/Sum' */
  real_T Gain2_c;                      /* '<S1>/Gain2' */
  real_T Fcn;                          /* '<S122>/Fcn' */
  real_T Fcn1;                         /* '<S122>/Fcn1' */
  real_T Fcn_m;                        /* '<S121>/Fcn' */
  real_T Fcn1_f;                       /* '<S121>/Fcn1' */
  real_T LEDHeartbeat;                 /* '<S1>/LED Heartbeat' */
} B_Main_Firmware_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T SamplingDelay_DSTATE[3];      /* '<S1>/Sampling Delay' */
  real_T Integrator_DSTATE;            /* '<S196>/Integrator' */
  real_T Integrator_DSTATE_d;          /* '<S200>/Integrator' */
  real_T INPUT_1_1_1_Discrete[2];      /* '<S205>/INPUT_1_1_1' */
  real_T INPUT_2_1_1_Discrete[2];      /* '<S205>/INPUT_2_1_1' */
  real_T INPUT_3_1_1_Discrete[2];      /* '<S205>/INPUT_3_1_1' */
  real_T INPUT_4_1_1_Discrete[2];      /* '<S205>/INPUT_4_1_1' */
  real_T INPUT_5_1_1_Discrete[2];      /* '<S205>/INPUT_5_1_1' */
  real_T INPUT_6_1_1_Discrete[2];      /* '<S205>/INPUT_6_1_1' */
  real_T Delay_DSTATE;                 /* '<S1>/Delay' */
  real_T INPUT_7_1_1_Discrete[2];      /* '<S205>/INPUT_7_1_1' */
  real_T STATE_1_Discrete[17];         /* '<S205>/STATE_1' */
  real_T Delay_DSTATE_o;               /* '<S2>/Delay' */
  real_T STATE_1_ZcValueStore;         /* '<S205>/STATE_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S205>/OUTPUT_1_0' */
  real_T OUTPUT_1_0_ZcValueStore;      /* '<S205>/OUTPUT_1_0' */
  real_T OUTPUT_1_1_Discrete;          /* '<S205>/OUTPUT_1_1' */
  real_T OUTPUT_1_1_ZcValueStore;      /* '<S205>/OUTPUT_1_1' */
  real_T TimeStampA;                   /* '<S2>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S2>/Derivative' */
  real_T TimeStampB;                   /* '<S2>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S2>/Derivative' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<S3>/Scope' */

  void* STATE_1_Simulator;             /* '<S205>/STATE_1' */
  void* STATE_1_SimData;               /* '<S205>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S205>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S205>/STATE_1' */
  void* STATE_1_TsInfo;                /* '<S205>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S205>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S205>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S205>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S205>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsInfo;             /* '<S205>/OUTPUT_1_0' */
  void* OUTPUT_1_1_Simulator;          /* '<S205>/OUTPUT_1_1' */
  void* OUTPUT_1_1_SimData;            /* '<S205>/OUTPUT_1_1' */
  void* OUTPUT_1_1_DiagMgr;            /* '<S205>/OUTPUT_1_1' */
  void* OUTPUT_1_1_ZcLogger;           /* '<S205>/OUTPUT_1_1' */
  void* OUTPUT_1_1_TsInfo;             /* '<S205>/OUTPUT_1_1' */
  struct {
    void *LoggedData[3];
  } Scope_PWORK_h;                     /* '<S1>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_p;                     /* '<S2>/Scope' */

  int32_T clockTickCounter;            /* '<S1>/LED Heartbeat' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S1>/Digital Output' */
  int_T STATE_1_Modes[6];              /* '<S205>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S205>/OUTPUT_1_0' */
  int_T OUTPUT_1_1_Modes;              /* '<S205>/OUTPUT_1_1' */
  int16_T Subsystem1_SubsysRanBC;      /* '<S117>/Subsystem1' */
  int16_T Subsystempi2delay_SubsysRanBC;/* '<S117>/Subsystem - pi//2 delay' */
  uint16_T STATE_1_ZcSignalDir;        /* '<S205>/STATE_1' */
  uint16_T STATE_1_ZcStateStore;       /* '<S205>/STATE_1' */
  uint16_T OUTPUT_1_0_ZcSignalDir;     /* '<S205>/OUTPUT_1_0' */
  uint16_T OUTPUT_1_0_ZcStateStore;    /* '<S205>/OUTPUT_1_0' */
  uint16_T OUTPUT_1_1_ZcSignalDir;     /* '<S205>/OUTPUT_1_1' */
  uint16_T OUTPUT_1_1_ZcStateStore;    /* '<S205>/OUTPUT_1_1' */
  boolean_T Initial_FirstOutputTime;   /* '<S196>/Initial' */
  boolean_T Initial_FirstOutputTime_o; /* '<S200>/Initial' */
  boolean_T STATE_1_FirstOutput;       /* '<S205>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S205>/OUTPUT_1_0' */
  boolean_T OUTPUT_1_1_FirstOutput;    /* '<S205>/OUTPUT_1_1' */
} DW_Main_Firmware_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S156>/Integrator' */
  real_T Filter_CSTATE;                /* '<S151>/Filter' */
  real_T Filter_CSTATE_b;              /* '<S45>/Filter' */
  real_T Integrator_CSTATE_n;          /* '<S50>/Integrator' */
  real_T Filter_CSTATE_i;              /* '<S95>/Filter' */
  real_T Integrator_CSTATE_e;          /* '<S100>/Integrator' */
} X_Main_Firmware_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S156>/Integrator' */
  real_T Filter_CSTATE;                /* '<S151>/Filter' */
  real_T Filter_CSTATE_b;              /* '<S45>/Filter' */
  real_T Integrator_CSTATE_n;          /* '<S50>/Integrator' */
  real_T Filter_CSTATE_i;              /* '<S95>/Filter' */
  real_T Integrator_CSTATE_e;          /* '<S100>/Integrator' */
} XDot_Main_Firmware_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S156>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S151>/Filter' */
  boolean_T Filter_CSTATE_b;           /* '<S45>/Filter' */
  boolean_T Integrator_CSTATE_n;       /* '<S50>/Integrator' */
  boolean_T Filter_CSTATE_i;           /* '<S95>/Filter' */
  boolean_T Integrator_CSTATE_e;       /* '<S100>/Integrator' */
} XDis_Main_Firmware_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_Main_Firmware_T_ {
  real_T A_f;                          /* Variable: A_f
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T C_d;                          /* Variable: C_d
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T C_rr;                         /* Variable: C_rr
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Ld;                           /* Variable: Ld
                                        * Referenced by: '<S11>/Gain3'
                                        */
  real_T Lq;                           /* Variable: Lq
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T Rs;                           /* Variable: Rs
                                        * Referenced by:
                                        *   '<S11>/Gain'
                                        *   '<S11>/Gain2'
                                        */
  real_T Voltage_max;                  /* Variable: Voltage_max
                                        * Referenced by:
                                        *   '<S1>/Gain5'
                                        *   '<S2>/Limiter'
                                        *   '<S2>/Limiter 1'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T lambda;                       /* Variable: lambda
                                        * Referenced by:
                                        *   '<S2>/Gain6'
                                        *   '<S11>/Gain4'
                                        */
  real_T m;                            /* Variable: m
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T ppair;                        /* Variable: ppair
                                        * Referenced by:
                                        *   '<S2>/Gain2'
                                        *   '<S2>/Gain6'
                                        *   '<S2>/Gain7'
                                        *   '<S11>/Gain5'
                                        */
  real_T AlphaBetaZerotodq0_Alignment;
                                 /* Mask Parameter: AlphaBetaZerotodq0_Alignment
                                  * Referenced by: '<S117>/Constant'
                                  */
  real_T Carriercounter_CarrCount;   /* Mask Parameter: Carriercounter_CarrCount
                                      * Referenced by: '<S189>/Constant2'
                                      */
  real_T WePID_D;                      /* Mask Parameter: WePID_D
                                        * Referenced by: '<S149>/Derivative Gain'
                                        */
  real_T IDPID_D;                      /* Mask Parameter: IDPID_D
                                        * Referenced by: '<S43>/Derivative Gain'
                                        */
  real_T IQPID_D;                      /* Mask Parameter: IQPID_D
                                        * Referenced by: '<S93>/Derivative Gain'
                                        */
  real_T IDPID_I;                      /* Mask Parameter: IDPID_I
                                        * Referenced by: '<S47>/Integral Gain'
                                        */
  real_T IQPID_I;                      /* Mask Parameter: IQPID_I
                                        * Referenced by: '<S97>/Integral Gain'
                                        */
  real_T WePID_I;                      /* Mask Parameter: WePID_I
                                        * Referenced by: '<S153>/Integral Gain'
                                        */
  real_T WePID_InitialConditionForFilter;
                              /* Mask Parameter: WePID_InitialConditionForFilter
                               * Referenced by: '<S151>/Filter'
                               */
  real_T IDPID_InitialConditionForFilter;
                              /* Mask Parameter: IDPID_InitialConditionForFilter
                               * Referenced by: '<S45>/Filter'
                               */
  real_T IQPID_InitialConditionForFilter;
                              /* Mask Parameter: IQPID_InitialConditionForFilter
                               * Referenced by: '<S95>/Filter'
                               */
  real_T WePID_InitialConditionForIntegr;
                              /* Mask Parameter: WePID_InitialConditionForIntegr
                               * Referenced by: '<S156>/Integrator'
                               */
  real_T IDPID_InitialConditionForIntegr;
                              /* Mask Parameter: IDPID_InitialConditionForIntegr
                               * Referenced by: '<S50>/Integrator'
                               */
  real_T IQPID_InitialConditionForIntegr;
                              /* Mask Parameter: IQPID_InitialConditionForIntegr
                               * Referenced by: '<S100>/Integrator'
                               */
  real_T WePID_N;                      /* Mask Parameter: WePID_N
                                        * Referenced by: '<S159>/Filter Coefficient'
                                        */
  real_T IDPID_N;                      /* Mask Parameter: IDPID_N
                                        * Referenced by: '<S53>/Filter Coefficient'
                                        */
  real_T IQPID_N;                      /* Mask Parameter: IQPID_N
                                        * Referenced by: '<S103>/Filter Coefficient'
                                        */
  real_T WePID_P;                      /* Mask Parameter: WePID_P
                                        * Referenced by: '<S161>/Proportional Gain'
                                        */
  real_T IDPID_P;                      /* Mask Parameter: IDPID_P
                                        * Referenced by: '<S55>/Proportional Gain'
                                        */
  real_T IQPID_P;                      /* Mask Parameter: IQPID_P
                                        * Referenced by: '<S105>/Proportional Gain'
                                        */
  real_T Carriercounter_Range;         /* Mask Parameter: Carriercounter_Range
                                        * Referenced by:
                                        *   '<S189>/Bias'
                                        *   '<S189>/Gain'
                                        */
  real_T PWMGenerator_Tdelay;          /* Mask Parameter: PWMGenerator_Tdelay
                                        * Referenced by: '<S200>/Initial'
                                        */
  real_T PWMGenerator_Tper;            /* Mask Parameter: PWMGenerator_Tper
                                        * Referenced by:
                                        *   '<S189>/Constant10'
                                        *   '<S189>/Constant6'
                                        *   '<S189>/Gain1'
                                        *   '<S193>/Switch'
                                        *   '<S194>/Switch'
                                        *   '<S195>/Bias'
                                        *   '<S195>/Constant'
                                        *   '<S198>/Constant'
                                        *   '<S199>/Gain'
                                        *   '<S199>/Gain1'
                                        *   '<S202>/Constant'
                                        *   '<S203>/Gain'
                                        *   '<S203>/Gain1'
                                        */
  real_T IntegratorwithWrappedStateDiscr;
                              /* Mask Parameter: IntegratorwithWrappedStateDiscr
                               * Referenced by:
                               *   '<S197>/Constant'
                               *   '<S199>/Bias'
                               *   '<S199>/Gain'
                               *   '<S199>/Gain1'
                               */
  real_T IntegratorwithWrappedStateDis_n;
                              /* Mask Parameter: IntegratorwithWrappedStateDis_n
                               * Referenced by:
                               *   '<S201>/Constant'
                               *   '<S203>/Bias'
                               *   '<S203>/Gain'
                               *   '<S203>/Gain1'
                               */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S119>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S120>/Constant'
                                      */
  real_T IntegratorwithWrappedStateDis_b;
                              /* Mask Parameter: IntegratorwithWrappedStateDis_b
                               * Referenced by: '<S196>/Initial'
                               */
  real_T dq_Y0[2];                     /* Expression: [0,0]
                                        * Referenced by: '<S121>/dq'
                                        */
  real_T dq_Y0_j[2];                   /* Expression: [0,0]
                                        * Referenced by: '<S122>/dq'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T SamplingDelay_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S1>/Sampling Delay'
                                         */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S190>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S196>/Integrator'
                                        */
  real_T Constant2_Value_f;            /* Expression: 0
                                        * Referenced by: '<S193>/Constant2'
                                        */
  real_T Integrator_gainval_k;       /* Computed Parameter: Integrator_gainval_k
                                      * Referenced by: '<S200>/Integrator'
                                      */
  real_T Constant2_Value_o;            /* Expression: 0
                                        * Referenced by: '<S194>/Constant2'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: 1
                                        * Referenced by: '<S189>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: 0
                                        * Referenced by: '<S189>/Saturation'
                                        */
  real_T Gain2_Gain;                   /* Expression: 12
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 12
                                        * Referenced by: '<S3>/Gain3'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant7_Value;              /* Expression: 0.5
                                        * Referenced by: '<S1>/Constant7'
                                        */
  real_T SpeedrequestRads1_Value;      /* Expression: 1000
                                        * Referenced by: '<S1>/Speed request (Rad//s)1'
                                        */
  real_T Delay_InitialCondition_a;     /* Expression: 0.0
                                        * Referenced by: '<S2>/Delay'
                                        */
  real_T Gain3_Gain_l[9];
  /* Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ]
   * Referenced by: '<S118>/Gain3'
   */
  real_T Gain1_Gain;                   /* Expression: 2/3
                                        * Referenced by: '<S118>/Gain1'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T torquerequest_Value;          /* Expression: 10
                                        * Referenced by: '<S1>/torque request'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S2>/Switch'
                                        */
  real_T Limiter1_LowerSat;            /* Expression: 0
                                        * Referenced by: '<S2>/Limiter 1'
                                        */
  real_T Limiter_LowerSat;             /* Expression: 0
                                        * Referenced by: '<S2>/Limiter'
                                        */
  real_T Bias_Bias;                    /* Expression: -2*pi/3
                                        * Referenced by: '<S14>/Bias'
                                        */
  real_T Bias1_Bias;                   /* Expression: 2*pi/3
                                        * Referenced by: '<S14>/Bias1'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S189>/Constant3'
                                        */
  real_T Gain2_Gain_n;                 /* Expression: 1/k^2
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T LEDHeartbeat_Amp;             /* Expression: 1
                                        * Referenced by: '<S1>/LED Heartbeat'
                                        */
  real_T LEDHeartbeat_Period;         /* Computed Parameter: LEDHeartbeat_Period
                                       * Referenced by: '<S1>/LED Heartbeat'
                                       */
  real_T LEDHeartbeat_Duty;            /* Computed Parameter: LEDHeartbeat_Duty
                                        * Referenced by: '<S1>/LED Heartbeat'
                                        */
  real_T LEDHeartbeat_PhaseDelay;      /* Expression: 0
                                        * Referenced by: '<S1>/LED Heartbeat'
                                        */
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
  real_T odeY[6];
  real_T odeF[3][6];
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
    uint32_T clockTick2;
    struct {
      uint32_T TID[3];
    } TaskCounters;

    time_T tStart;
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
 * '<S1>'   : 'Main_Firmware/FOC test'
 * '<S2>'   : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER'
 * '<S3>'   : 'Main_Firmware/FOC test/Gate Driver'
 * '<S4>'   : 'Main_Firmware/FOC test/PS-Simulink Converter'
 * '<S5>'   : 'Main_Firmware/FOC test/PS-Simulink Converter1'
 * '<S6>'   : 'Main_Firmware/FOC test/PS-Simulink Converter2'
 * '<S7>'   : 'Main_Firmware/FOC test/PS-Simulink Converter3'
 * '<S8>'   : 'Main_Firmware/FOC test/PWM Generator'
 * '<S9>'   : 'Main_Firmware/FOC test/Simulink-PS Converter'
 * '<S10>'  : 'Main_Firmware/FOC test/Solver Configuration'
 * '<S11>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/Decoupling'
 * '<S12>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID'
 * '<S13>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID'
 * '<S14>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/Inverse park'
 * '<S15>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/Park Transform'
 * '<S16>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID'
 * '<S17>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Anti-windup'
 * '<S18>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/D Gain'
 * '<S19>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/External Derivative'
 * '<S20>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Filter'
 * '<S21>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Filter ICs'
 * '<S22>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/I Gain'
 * '<S23>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Ideal P Gain'
 * '<S24>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Ideal P Gain Fdbk'
 * '<S25>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Integrator'
 * '<S26>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Integrator ICs'
 * '<S27>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/N Copy'
 * '<S28>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/N Gain'
 * '<S29>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/P Copy'
 * '<S30>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Parallel P Gain'
 * '<S31>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Reset Signal'
 * '<S32>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Saturation'
 * '<S33>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Saturation Fdbk'
 * '<S34>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Sum'
 * '<S35>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Sum Fdbk'
 * '<S36>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Tracking Mode'
 * '<S37>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Tracking Mode Sum'
 * '<S38>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Tsamp - Integral'
 * '<S39>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Tsamp - Ngain'
 * '<S40>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/postSat Signal'
 * '<S41>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/preSat Signal'
 * '<S42>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Anti-windup/Passthrough'
 * '<S43>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/D Gain/Internal Parameters'
 * '<S44>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/External Derivative/Error'
 * '<S45>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Filter/Cont. Filter'
 * '<S46>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Filter ICs/Internal IC - Filter'
 * '<S47>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/I Gain/Internal Parameters'
 * '<S48>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Ideal P Gain/Passthrough'
 * '<S49>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Ideal P Gain Fdbk/Disabled'
 * '<S50>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Integrator/Continuous'
 * '<S51>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Integrator ICs/Internal IC'
 * '<S52>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/N Copy/Disabled'
 * '<S53>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/N Gain/Internal Parameters'
 * '<S54>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/P Copy/Disabled'
 * '<S55>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Parallel P Gain/Internal Parameters'
 * '<S56>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Reset Signal/Disabled'
 * '<S57>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Saturation/Passthrough'
 * '<S58>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Saturation Fdbk/Disabled'
 * '<S59>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Sum/Sum_PID'
 * '<S60>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Sum Fdbk/Disabled'
 * '<S61>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Tracking Mode/Disabled'
 * '<S62>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Tracking Mode Sum/Passthrough'
 * '<S63>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Tsamp - Integral/TsSignalSpecification'
 * '<S64>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/Tsamp - Ngain/Passthrough'
 * '<S65>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/postSat Signal/Forward_Path'
 * '<S66>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/ID PID/preSat Signal/Forward_Path'
 * '<S67>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Anti-windup'
 * '<S68>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/D Gain'
 * '<S69>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/External Derivative'
 * '<S70>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Filter'
 * '<S71>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Filter ICs'
 * '<S72>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/I Gain'
 * '<S73>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Ideal P Gain'
 * '<S74>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Ideal P Gain Fdbk'
 * '<S75>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Integrator'
 * '<S76>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Integrator ICs'
 * '<S77>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/N Copy'
 * '<S78>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/N Gain'
 * '<S79>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/P Copy'
 * '<S80>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Parallel P Gain'
 * '<S81>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Reset Signal'
 * '<S82>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Saturation'
 * '<S83>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Saturation Fdbk'
 * '<S84>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Sum'
 * '<S85>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Sum Fdbk'
 * '<S86>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Tracking Mode'
 * '<S87>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Tracking Mode Sum'
 * '<S88>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Tsamp - Integral'
 * '<S89>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Tsamp - Ngain'
 * '<S90>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/postSat Signal'
 * '<S91>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/preSat Signal'
 * '<S92>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Anti-windup/Passthrough'
 * '<S93>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/D Gain/Internal Parameters'
 * '<S94>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/External Derivative/Error'
 * '<S95>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Filter/Cont. Filter'
 * '<S96>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Filter ICs/Internal IC - Filter'
 * '<S97>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/I Gain/Internal Parameters'
 * '<S98>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Ideal P Gain/Passthrough'
 * '<S99>'  : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Ideal P Gain Fdbk/Disabled'
 * '<S100>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Integrator/Continuous'
 * '<S101>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Integrator ICs/Internal IC'
 * '<S102>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/N Copy/Disabled'
 * '<S103>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/N Gain/Internal Parameters'
 * '<S104>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/P Copy/Disabled'
 * '<S105>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Parallel P Gain/Internal Parameters'
 * '<S106>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Reset Signal/Disabled'
 * '<S107>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Saturation/Passthrough'
 * '<S108>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Saturation Fdbk/Disabled'
 * '<S109>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Sum/Sum_PID'
 * '<S110>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Sum Fdbk/Disabled'
 * '<S111>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Tracking Mode/Disabled'
 * '<S112>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Tracking Mode Sum/Passthrough'
 * '<S113>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Tsamp - Integral/TsSignalSpecification'
 * '<S114>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/Tsamp - Ngain/Passthrough'
 * '<S115>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/postSat Signal/Forward_Path'
 * '<S116>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/IQ PID/preSat Signal/Forward_Path'
 * '<S117>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/Park Transform/Alpha-Beta-Zero to dq0'
 * '<S118>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/Park Transform/abc to Alpha-Beta-Zero'
 * '<S119>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/Park Transform/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S120>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/Park Transform/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S121>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/Park Transform/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S122>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/Park Transform/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S123>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Anti-windup'
 * '<S124>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/D Gain'
 * '<S125>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/External Derivative'
 * '<S126>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Filter'
 * '<S127>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Filter ICs'
 * '<S128>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/I Gain'
 * '<S129>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Ideal P Gain'
 * '<S130>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Ideal P Gain Fdbk'
 * '<S131>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Integrator'
 * '<S132>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Integrator ICs'
 * '<S133>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/N Copy'
 * '<S134>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/N Gain'
 * '<S135>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/P Copy'
 * '<S136>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Parallel P Gain'
 * '<S137>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Reset Signal'
 * '<S138>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Saturation'
 * '<S139>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Saturation Fdbk'
 * '<S140>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Sum'
 * '<S141>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Sum Fdbk'
 * '<S142>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Tracking Mode'
 * '<S143>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Tracking Mode Sum'
 * '<S144>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Tsamp - Integral'
 * '<S145>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Tsamp - Ngain'
 * '<S146>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/postSat Signal'
 * '<S147>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/preSat Signal'
 * '<S148>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Anti-windup/Passthrough'
 * '<S149>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/D Gain/Internal Parameters'
 * '<S150>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/External Derivative/Error'
 * '<S151>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Filter/Cont. Filter'
 * '<S152>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Filter ICs/Internal IC - Filter'
 * '<S153>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/I Gain/Internal Parameters'
 * '<S154>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Ideal P Gain/Passthrough'
 * '<S155>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Ideal P Gain Fdbk/Disabled'
 * '<S156>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Integrator/Continuous'
 * '<S157>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Integrator ICs/Internal IC'
 * '<S158>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/N Copy/Disabled'
 * '<S159>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/N Gain/Internal Parameters'
 * '<S160>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/P Copy/Disabled'
 * '<S161>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Parallel P Gain/Internal Parameters'
 * '<S162>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Reset Signal/Disabled'
 * '<S163>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Saturation/Passthrough'
 * '<S164>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Saturation Fdbk/Disabled'
 * '<S165>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Sum/Sum_PID'
 * '<S166>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Sum Fdbk/Disabled'
 * '<S167>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Tracking Mode/Disabled'
 * '<S168>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Tracking Mode Sum/Passthrough'
 * '<S169>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Tsamp - Integral/TsSignalSpecification'
 * '<S170>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/Tsamp - Ngain/Passthrough'
 * '<S171>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/postSat Signal/Forward_Path'
 * '<S172>' : 'Main_Firmware/FOC test/FIELD ORIENTED CONTROLLER/We PID/preSat Signal/Forward_Path'
 * '<S173>' : 'Main_Firmware/FOC test/Gate Driver/Simulink-PS Converter3'
 * '<S174>' : 'Main_Firmware/FOC test/Gate Driver/Simulink-PS Converter4'
 * '<S175>' : 'Main_Firmware/FOC test/Gate Driver/Simulink-PS Converter5'
 * '<S176>' : 'Main_Firmware/FOC test/Gate Driver/Simulink-PS Converter6'
 * '<S177>' : 'Main_Firmware/FOC test/Gate Driver/Simulink-PS Converter7'
 * '<S178>' : 'Main_Firmware/FOC test/Gate Driver/Simulink-PS Converter8'
 * '<S179>' : 'Main_Firmware/FOC test/Gate Driver/Simulink-PS Converter3/EVAL_KEY'
 * '<S180>' : 'Main_Firmware/FOC test/Gate Driver/Simulink-PS Converter4/EVAL_KEY'
 * '<S181>' : 'Main_Firmware/FOC test/Gate Driver/Simulink-PS Converter5/EVAL_KEY'
 * '<S182>' : 'Main_Firmware/FOC test/Gate Driver/Simulink-PS Converter6/EVAL_KEY'
 * '<S183>' : 'Main_Firmware/FOC test/Gate Driver/Simulink-PS Converter7/EVAL_KEY'
 * '<S184>' : 'Main_Firmware/FOC test/Gate Driver/Simulink-PS Converter8/EVAL_KEY'
 * '<S185>' : 'Main_Firmware/FOC test/PS-Simulink Converter/EVAL_KEY'
 * '<S186>' : 'Main_Firmware/FOC test/PS-Simulink Converter1/EVAL_KEY'
 * '<S187>' : 'Main_Firmware/FOC test/PS-Simulink Converter2/EVAL_KEY'
 * '<S188>' : 'Main_Firmware/FOC test/PS-Simulink Converter3/EVAL_KEY'
 * '<S189>' : 'Main_Firmware/FOC test/PWM Generator/Carrier counter'
 * '<S190>' : 'Main_Firmware/FOC test/PWM Generator/Compare To Zero'
 * '<S191>' : 'Main_Firmware/FOC test/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)'
 * '<S192>' : 'Main_Firmware/FOC test/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1'
 * '<S193>' : 'Main_Firmware/FOC test/PWM Generator/Carrier counter/Limitation'
 * '<S194>' : 'Main_Firmware/FOC test/PWM Generator/Carrier counter/Limitation1'
 * '<S195>' : 'Main_Firmware/FOC test/PWM Generator/Carrier counter/scale'
 * '<S196>' : 'Main_Firmware/FOC test/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete'
 * '<S197>' : 'Main_Firmware/FOC test/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant'
 * '<S198>' : 'Main_Firmware/FOC test/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant1'
 * '<S199>' : 'Main_Firmware/FOC test/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Reinitialization'
 * '<S200>' : 'Main_Firmware/FOC test/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete'
 * '<S201>' : 'Main_Firmware/FOC test/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Compare To Constant'
 * '<S202>' : 'Main_Firmware/FOC test/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Compare To Constant1'
 * '<S203>' : 'Main_Firmware/FOC test/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Reinitialization'
 * '<S204>' : 'Main_Firmware/FOC test/Simulink-PS Converter/EVAL_KEY'
 * '<S205>' : 'Main_Firmware/FOC test/Solver Configuration/EVAL_KEY'
 */
#endif                                 /* Main_Firmware_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
