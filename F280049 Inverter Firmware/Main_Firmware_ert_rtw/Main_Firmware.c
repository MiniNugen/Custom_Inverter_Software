/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware.c
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

#include "Main_Firmware.h"
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>
#include "Main_Firmware_private.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_Main_Firmware_T Main_Firmware_B;

/* Continuous states */
X_Main_Firmware_T Main_Firmware_X;

/* Disabled State Vector */
XDis_Main_Firmware_T Main_Firmware_XDis;

/* Block states (default storage) */
DW_Main_Firmware_T Main_Firmware_DW;

/* Real-time model */
static RT_MODEL_Main_Firmware_T Main_Firmware_M_;
RT_MODEL_Main_Firmware_T *const Main_Firmware_M = &Main_Firmware_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Main_Firmware_M->Timing.TaskCounters.TID[2])++;
  if ((Main_Firmware_M->Timing.TaskCounters.TID[2]) > 499999) {/* Sample time: [0.5s, 0.0s] */
    Main_Firmware_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Main_Firmware_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Main_Firmware_step();
  Main_Firmware_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Main_Firmware_step();
  Main_Firmware_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void Main_Firmware_step(void)
{
  if (rtmIsMajorTimeStep(Main_Firmware_M)) {
    /* set solver stop time */
    if (!(Main_Firmware_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Main_Firmware_M->solverInfo,
                            ((Main_Firmware_M->Timing.clockTickH0 + 1) *
        Main_Firmware_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Main_Firmware_M->solverInfo,
                            ((Main_Firmware_M->Timing.clockTick0 + 1) *
        Main_Firmware_M->Timing.stepSize0 + Main_Firmware_M->Timing.clockTickH0 *
        Main_Firmware_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Main_Firmware_M)) {
    Main_Firmware_M->Timing.t[0] = rtsiGetT(&Main_Firmware_M->solverInfo);
  }

  {
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    NeuDiagnosticTree *diagnosticTree_1;
    char *msg;
    char *msg_0;
    char *msg_1;
    real_T tmp_4[51];
    real_T tmp_0[28];
    real_T Initial;
    real_T Initial_i;
    real_T rtb_Add;
    real_T rtb_Add1;
    real_T rtb_Product1_b;
    real_T rtb_speed_err;
    real_T time;
    real_T time_0;
    real_T time_1;
    real_T time_2;
    real_T time_3;
    real_T time_4;
    real_T *lastU;
    int32_T isHit;
    int32_T isHit_0;
    int32_T isHit_1;
    int32_T tmp_2;
    int16_T rtb_Compare;
    int_T tmp_3[9];
    int_T tmp_5[9];
    int_T tmp_1[8];
    boolean_T tmp;

    /* Reset subsysRan breadcrumbs */
    srClearBC(Main_Firmware_DW.Subsystempi2delay_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Main_Firmware_DW.Subsystem1_SubsysRanBC);
    if (rtmIsMajorTimeStep(Main_Firmware_M) &&
        Main_Firmware_M->Timing.TaskCounters.TID[1] == 0) {
      /* Saturate: '<S1>/Saturation' incorporates:
       *  Delay: '<S1>/Sampling Delay'
       */
      Initial = Main_Firmware_DW.SamplingDelay_DSTATE[0];
      if (Initial > Main_Firmware_P.Saturation_UpperSat) {
        Main_Firmware_DW.SamplingDelay_DSTATE[0] =
          Main_Firmware_P.Saturation_UpperSat;
      } else if (Initial < Main_Firmware_P.Saturation_LowerSat) {
        Main_Firmware_DW.SamplingDelay_DSTATE[0] =
          Main_Firmware_P.Saturation_LowerSat;
      }

      Initial = Main_Firmware_DW.SamplingDelay_DSTATE[1];
      if (Initial > Main_Firmware_P.Saturation_UpperSat) {
        Main_Firmware_DW.SamplingDelay_DSTATE[1] =
          Main_Firmware_P.Saturation_UpperSat;
      } else if (Initial < Main_Firmware_P.Saturation_LowerSat) {
        Main_Firmware_DW.SamplingDelay_DSTATE[1] =
          Main_Firmware_P.Saturation_LowerSat;
      }

      Initial = Main_Firmware_DW.SamplingDelay_DSTATE[2];
      if (Initial > Main_Firmware_P.Saturation_UpperSat) {
        Main_Firmware_DW.SamplingDelay_DSTATE[2] =
          Main_Firmware_P.Saturation_UpperSat;
      } else if (Initial < Main_Firmware_P.Saturation_LowerSat) {
        Main_Firmware_DW.SamplingDelay_DSTATE[2] =
          Main_Firmware_P.Saturation_LowerSat;
      }

      /* End of Saturate: '<S1>/Saturation' */

      /* InitialCondition: '<S196>/Initial' */
      if (Main_Firmware_DW.Initial_FirstOutputTime) {
        Main_Firmware_DW.Initial_FirstOutputTime = false;

        /* InitialCondition: '<S196>/Initial' */
        Initial = Main_Firmware_P.IntegratorwithWrappedStateDis_b;
      } else {
        /* Gain: '<S199>/Gain' incorporates:
         *  Gain: '<S199>/Gain1'
         */
        Initial = Main_Firmware_P.PWMGenerator_Tper -
          Main_Firmware_P.IntegratorwithWrappedStateDiscr;

        /* InitialCondition: '<S196>/Initial' incorporates:
         *  Bias: '<S199>/Bias'
         *  Gain: '<S199>/Gain'
         *  Gain: '<S199>/Gain1'
         *  Rounding: '<S199>/Rounding Function'
         *  Sum: '<S199>/Sum1'
         */
        Initial = Main_Firmware_DW.Integrator_DSTATE - floor(1.0 / Initial *
          (Main_Firmware_DW.Integrator_DSTATE -
           Main_Firmware_P.IntegratorwithWrappedStateDiscr)) * Initial;
      }

      /* End of InitialCondition: '<S196>/Initial' */

      /* DiscreteIntegrator: '<S196>/Integrator' incorporates:
       *  Constant: '<S197>/Constant'
       *  Constant: '<S198>/Constant'
       *  Logic: '<S196>/Logical Operator'
       *  RelationalOperator: '<S197>/Compare'
       *  RelationalOperator: '<S198>/Compare'
       */
      if ((Main_Firmware_DW.Integrator_DSTATE <
           Main_Firmware_P.IntegratorwithWrappedStateDiscr) ||
          (Main_Firmware_DW.Integrator_DSTATE >=
           Main_Firmware_P.PWMGenerator_Tper)) {
        Main_Firmware_DW.Integrator_DSTATE = Initial;
      }

      /* Product: '<S195>/Product1' incorporates:
       *  Constant: '<S195>/Constant'
       *  DiscreteIntegrator: '<S196>/Integrator'
       *  Product: '<S195>/Product'
       *  Sum: '<S195>/Sum'
       */
      rtb_Product1_b = Main_Firmware_P.PWMGenerator_Tper /
        (Main_Firmware_P.PWMGenerator_Tper - Main_Firmware_B.Probe[0]) *
        Main_Firmware_DW.Integrator_DSTATE;

      /* Bias: '<S195>/Bias' */
      Initial = Main_Firmware_B.Probe[0] + Main_Firmware_P.PWMGenerator_Tper;

      /* InitialCondition: '<S200>/Initial' */
      if (Main_Firmware_DW.Initial_FirstOutputTime_o) {
        Main_Firmware_DW.Initial_FirstOutputTime_o = false;

        /* InitialCondition: '<S200>/Initial' */
        Initial_i = Main_Firmware_P.PWMGenerator_Tdelay;
      } else {
        /* Gain: '<S203>/Gain' incorporates:
         *  Gain: '<S203>/Gain1'
         */
        Initial_i = 2.0 * Main_Firmware_P.PWMGenerator_Tper -
          Main_Firmware_P.IntegratorwithWrappedStateDis_n;

        /* InitialCondition: '<S200>/Initial' incorporates:
         *  Bias: '<S203>/Bias'
         *  Gain: '<S203>/Gain'
         *  Gain: '<S203>/Gain1'
         *  Rounding: '<S203>/Rounding Function'
         *  Sum: '<S203>/Sum1'
         */
        Initial_i = Main_Firmware_DW.Integrator_DSTATE_d - floor(1.0 / Initial_i
          * (Main_Firmware_DW.Integrator_DSTATE_d -
             Main_Firmware_P.IntegratorwithWrappedStateDis_n)) * Initial_i;
      }

      /* End of InitialCondition: '<S200>/Initial' */

      /* DiscreteIntegrator: '<S200>/Integrator' incorporates:
       *  Constant: '<S201>/Constant'
       *  Constant: '<S202>/Constant'
       *  Logic: '<S200>/Logical Operator'
       *  RelationalOperator: '<S201>/Compare'
       *  RelationalOperator: '<S202>/Compare'
       */
      if ((Main_Firmware_DW.Integrator_DSTATE_d <
           Main_Firmware_P.IntegratorwithWrappedStateDis_n) ||
          (Main_Firmware_DW.Integrator_DSTATE_d >= 2.0 *
           Main_Firmware_P.PWMGenerator_Tper)) {
        Main_Firmware_DW.Integrator_DSTATE_d = Initial_i;
      }

      /* MultiPortSwitch: '<S189>/Multiport Switch' incorporates:
       *  Constant: '<S189>/Constant2'
       *  Constant: '<S189>/Constant6'
       *  Product: '<S195>/Product2'
       *  Product: '<S195>/Product3'
       *  Rounding: '<S195>/Rounding Function'
       *  Sum: '<S189>/Sum3'
       *  Sum: '<S189>/Sum5'
       *  Sum: '<S195>/Sum1'
       *  Switch: '<S193>/Switch'
       *  Switch: '<S194>/Switch'
       */
      switch ((int16_T)Main_Firmware_P.Carriercounter_CarrCount) {
       case 1:
        Initial = rtb_Product1_b - floor(rtb_Product1_b / Initial) * Initial;
        break;

       case 2:
        Initial = Main_Firmware_P.PWMGenerator_Tper - (rtb_Product1_b - floor
          (rtb_Product1_b / Initial) * Initial);
        break;

       default:
        /* Sum: '<S189>/Sum4' incorporates:
         *  Constant: '<S189>/Constant10'
         *  DiscreteIntegrator: '<S200>/Integrator'
         */
        Initial = 2.0 * Main_Firmware_P.PWMGenerator_Tper -
          Main_Firmware_DW.Integrator_DSTATE_d;

        /* Switch: '<S193>/Switch' incorporates:
         *  Constant: '<S193>/Constant2'
         *  DiscreteIntegrator: '<S200>/Integrator'
         */
        if (Main_Firmware_DW.Integrator_DSTATE_d >
            Main_Firmware_P.PWMGenerator_Tper) {
          rtb_Product1_b = Main_Firmware_P.Constant2_Value_f;
        } else {
          rtb_Product1_b = Main_Firmware_DW.Integrator_DSTATE_d;
        }

        /* Switch: '<S194>/Switch' incorporates:
         *  Constant: '<S194>/Constant2'
         */
        if (Initial > Main_Firmware_P.PWMGenerator_Tper) {
          Initial = Main_Firmware_P.Constant2_Value_o;
        }

        Initial += rtb_Product1_b;
        break;
      }

      /* End of MultiPortSwitch: '<S189>/Multiport Switch' */

      /* Gain: '<S189>/Gain1' */
      Initial *= 1.0 / Main_Firmware_P.PWMGenerator_Tper;

      /* Saturate: '<S189>/Saturation' */
      if (Initial > Main_Firmware_P.Saturation_UpperSat_j) {
        Initial = Main_Firmware_P.Saturation_UpperSat_j;
      } else if (Initial < Main_Firmware_P.Saturation_LowerSat_p) {
        Initial = Main_Firmware_P.Saturation_LowerSat_p;
      }

      /* End of Saturate: '<S189>/Saturation' */

      /* Bias: '<S189>/Bias' incorporates:
       *  Gain: '<S189>/Gain'
       */
      Initial_i = Main_Firmware_P.Carriercounter_Range * Initial +
        (-Main_Firmware_P.Carriercounter_Range + 1.0);

      /* RelationalOperator: '<S190>/Compare' incorporates:
       *  Delay: '<S1>/Sampling Delay'
       */
      rtb_Product1_b = Main_Firmware_DW.SamplingDelay_DSTATE[0];

      /* DataTypeConversion: '<S8>/Data Type Conversion2' incorporates:
       *  Constant: '<S190>/Constant'
       *  Delay: '<S1>/Sampling Delay'
       *  Logic: '<S8>/Logical Operator'
       *  RelationalOperator: '<S190>/Compare'
       *  RelationalOperator: '<S8>/Relational Operator'
       */
      rtb_Product1_b = ((rtb_Product1_b != Main_Firmware_P.Constant_Value) &&
                        (rtb_Product1_b >= Initial_i));
      Main_Firmware_DW.SamplingDelay_DSTATE[0] = rtb_Product1_b;

      /* Gain: '<S3>/Gain2' incorporates:
       *  Constant: '<S3>/Constant2'
       *  Sum: '<S3>/Subtract6'
       */
      Main_Firmware_B.Gain2[0] = (Main_Firmware_P.Constant2_Value -
        rtb_Product1_b) * Main_Firmware_P.Gain2_Gain;

      /* Gain: '<S3>/Gain3' */
      Main_Firmware_B.Gain3[0] = Main_Firmware_P.Gain3_Gain * rtb_Product1_b;

      /* RelationalOperator: '<S190>/Compare' incorporates:
       *  Delay: '<S1>/Sampling Delay'
       */
      rtb_Product1_b = Main_Firmware_DW.SamplingDelay_DSTATE[1];

      /* DataTypeConversion: '<S8>/Data Type Conversion2' incorporates:
       *  Constant: '<S190>/Constant'
       *  Delay: '<S1>/Sampling Delay'
       *  Logic: '<S8>/Logical Operator'
       *  RelationalOperator: '<S190>/Compare'
       *  RelationalOperator: '<S8>/Relational Operator'
       */
      rtb_Product1_b = ((rtb_Product1_b != Main_Firmware_P.Constant_Value) &&
                        (rtb_Product1_b >= Initial_i));
      Main_Firmware_DW.SamplingDelay_DSTATE[1] = rtb_Product1_b;

      /* Gain: '<S3>/Gain2' incorporates:
       *  Constant: '<S3>/Constant2'
       *  Sum: '<S3>/Subtract6'
       */
      Main_Firmware_B.Gain2[1] = (Main_Firmware_P.Constant2_Value -
        rtb_Product1_b) * Main_Firmware_P.Gain2_Gain;

      /* Gain: '<S3>/Gain3' */
      Main_Firmware_B.Gain3[1] = Main_Firmware_P.Gain3_Gain * rtb_Product1_b;

      /* RelationalOperator: '<S190>/Compare' incorporates:
       *  Delay: '<S1>/Sampling Delay'
       */
      rtb_Product1_b = Main_Firmware_DW.SamplingDelay_DSTATE[2];

      /* DataTypeConversion: '<S8>/Data Type Conversion2' incorporates:
       *  Constant: '<S190>/Constant'
       *  Delay: '<S1>/Sampling Delay'
       *  Logic: '<S8>/Logical Operator'
       *  RelationalOperator: '<S190>/Compare'
       *  RelationalOperator: '<S8>/Relational Operator'
       */
      rtb_Product1_b = ((rtb_Product1_b != Main_Firmware_P.Constant_Value) &&
                        (rtb_Product1_b >= Initial_i));
      Main_Firmware_DW.SamplingDelay_DSTATE[2] = rtb_Product1_b;

      /* Gain: '<S3>/Gain2' incorporates:
       *  Constant: '<S3>/Constant2'
       *  Sum: '<S3>/Subtract6'
       */
      Main_Firmware_B.Gain2[2] = (Main_Firmware_P.Constant2_Value -
        rtb_Product1_b) * Main_Firmware_P.Gain2_Gain;

      /* Gain: '<S3>/Gain3' */
      Main_Firmware_B.Gain3[2] = Main_Firmware_P.Gain3_Gain * rtb_Product1_b;

      /* SimscapeInputBlock: '<S205>/INPUT_1_1_1' incorporates:
       *  Delay: '<S1>/Delay'
       *  SimscapeInputBlock: '<S205>/INPUT_7_1_1'
       */
      if (rtmIsMajorTimeStep(Main_Firmware_M) &&
          Main_Firmware_M->Timing.TaskCounters.TID[1] == 0) {
        Main_Firmware_B.INPUT_1_1_1[0] = Main_Firmware_B.Gain3[0];
        Main_Firmware_B.INPUT_1_1_1[1] = 0.0;
        Main_Firmware_B.INPUT_1_1_1[2] = 0.0;
        Main_Firmware_DW.INPUT_1_1_1_Discrete[0] =
          !(Main_Firmware_B.INPUT_1_1_1[0] ==
            Main_Firmware_DW.INPUT_1_1_1_Discrete[1]);
        Main_Firmware_DW.INPUT_1_1_1_Discrete[1] = Main_Firmware_B.INPUT_1_1_1[0];
        Main_Firmware_B.INPUT_1_1_1[0] = Main_Firmware_DW.INPUT_1_1_1_Discrete[1];
        Main_Firmware_B.INPUT_1_1_1[3] = Main_Firmware_DW.INPUT_1_1_1_Discrete[0];

        /* SimscapeInputBlock: '<S205>/INPUT_2_1_1' incorporates:
         *  SimscapeInputBlock: '<S205>/INPUT_1_1_1'
         */
        Main_Firmware_B.INPUT_2_1_1[0] = Main_Firmware_B.Gain2[0];
        Main_Firmware_B.INPUT_2_1_1[1] = 0.0;
        Main_Firmware_B.INPUT_2_1_1[2] = 0.0;
        Main_Firmware_DW.INPUT_2_1_1_Discrete[0] =
          !(Main_Firmware_B.INPUT_2_1_1[0] ==
            Main_Firmware_DW.INPUT_2_1_1_Discrete[1]);
        Main_Firmware_DW.INPUT_2_1_1_Discrete[1] = Main_Firmware_B.INPUT_2_1_1[0];
        Main_Firmware_B.INPUT_2_1_1[0] = Main_Firmware_DW.INPUT_2_1_1_Discrete[1];
        Main_Firmware_B.INPUT_2_1_1[3] = Main_Firmware_DW.INPUT_2_1_1_Discrete[0];

        /* SimscapeInputBlock: '<S205>/INPUT_3_1_1' */
        Main_Firmware_B.INPUT_3_1_1[0] = Main_Firmware_B.Gain3[1];
        Main_Firmware_B.INPUT_3_1_1[1] = 0.0;
        Main_Firmware_B.INPUT_3_1_1[2] = 0.0;
        Main_Firmware_DW.INPUT_3_1_1_Discrete[0] =
          !(Main_Firmware_B.INPUT_3_1_1[0] ==
            Main_Firmware_DW.INPUT_3_1_1_Discrete[1]);
        Main_Firmware_DW.INPUT_3_1_1_Discrete[1] = Main_Firmware_B.INPUT_3_1_1[0];
        Main_Firmware_B.INPUT_3_1_1[0] = Main_Firmware_DW.INPUT_3_1_1_Discrete[1];
        Main_Firmware_B.INPUT_3_1_1[3] = Main_Firmware_DW.INPUT_3_1_1_Discrete[0];

        /* SimscapeInputBlock: '<S205>/INPUT_4_1_1' */
        Main_Firmware_B.INPUT_4_1_1[0] = Main_Firmware_B.Gain2[1];
        Main_Firmware_B.INPUT_4_1_1[1] = 0.0;
        Main_Firmware_B.INPUT_4_1_1[2] = 0.0;
        Main_Firmware_DW.INPUT_4_1_1_Discrete[0] =
          !(Main_Firmware_B.INPUT_4_1_1[0] ==
            Main_Firmware_DW.INPUT_4_1_1_Discrete[1]);
        Main_Firmware_DW.INPUT_4_1_1_Discrete[1] = Main_Firmware_B.INPUT_4_1_1[0];
        Main_Firmware_B.INPUT_4_1_1[0] = Main_Firmware_DW.INPUT_4_1_1_Discrete[1];
        Main_Firmware_B.INPUT_4_1_1[3] = Main_Firmware_DW.INPUT_4_1_1_Discrete[0];

        /* SimscapeInputBlock: '<S205>/INPUT_5_1_1' */
        Main_Firmware_B.INPUT_5_1_1[0] = Main_Firmware_B.Gain3[2];
        Main_Firmware_B.INPUT_5_1_1[1] = 0.0;
        Main_Firmware_B.INPUT_5_1_1[2] = 0.0;
        Main_Firmware_DW.INPUT_5_1_1_Discrete[0] =
          !(Main_Firmware_B.INPUT_5_1_1[0] ==
            Main_Firmware_DW.INPUT_5_1_1_Discrete[1]);
        Main_Firmware_DW.INPUT_5_1_1_Discrete[1] = Main_Firmware_B.INPUT_5_1_1[0];
        Main_Firmware_B.INPUT_5_1_1[0] = Main_Firmware_DW.INPUT_5_1_1_Discrete[1];
        Main_Firmware_B.INPUT_5_1_1[3] = Main_Firmware_DW.INPUT_5_1_1_Discrete[0];

        /* SimscapeInputBlock: '<S205>/INPUT_6_1_1' */
        Main_Firmware_B.INPUT_6_1_1[0] = Main_Firmware_B.Gain2[2];
        Main_Firmware_B.INPUT_6_1_1[1] = 0.0;
        Main_Firmware_B.INPUT_6_1_1[2] = 0.0;
        Main_Firmware_DW.INPUT_6_1_1_Discrete[0] =
          !(Main_Firmware_B.INPUT_6_1_1[0] ==
            Main_Firmware_DW.INPUT_6_1_1_Discrete[1]);
        Main_Firmware_DW.INPUT_6_1_1_Discrete[1] = Main_Firmware_B.INPUT_6_1_1[0];
        Main_Firmware_B.INPUT_6_1_1[0] = Main_Firmware_DW.INPUT_6_1_1_Discrete[1];
        Main_Firmware_B.INPUT_6_1_1[3] = Main_Firmware_DW.INPUT_6_1_1_Discrete[0];
        Main_Firmware_B.INPUT_7_1_1[0] = Main_Firmware_DW.Delay_DSTATE;
        Main_Firmware_B.INPUT_7_1_1[1] = 0.0;
        Main_Firmware_B.INPUT_7_1_1[2] = 0.0;
        Main_Firmware_DW.INPUT_7_1_1_Discrete[0] =
          !(Main_Firmware_B.INPUT_7_1_1[0] ==
            Main_Firmware_DW.INPUT_7_1_1_Discrete[1]);
        Main_Firmware_DW.INPUT_7_1_1_Discrete[1] = Main_Firmware_B.INPUT_7_1_1[0];
        Main_Firmware_B.INPUT_7_1_1[0] = Main_Firmware_DW.INPUT_7_1_1_Discrete[1];
        Main_Firmware_B.INPUT_7_1_1[3] = Main_Firmware_DW.INPUT_7_1_1_Discrete[0];
      }

      /* End of SimscapeInputBlock: '<S205>/INPUT_1_1_1' */

      /* SimscapeExecutionBlock: '<S205>/STATE_1' incorporates:
       *  SimscapeExecutionBlock: '<S205>/OUTPUT_1_0'
       *  SimscapeExecutionBlock: '<S205>/OUTPUT_1_1'
       */
      simulationData = (NeslSimulationData *)Main_Firmware_DW.STATE_1_SimData;
      rtb_Product1_b = Main_Firmware_M->Timing.t[0];
      time = rtb_Product1_b;
      simulationData->mData->mTime.mN = 1;
      simulationData->mData->mTime.mX = &time;
      simulationData->mData->mContStates.mN = 0;
      simulationData->mData->mContStates.mX = NULL;
      simulationData->mData->mDiscStates.mN = 17;
      simulationData->mData->mDiscStates.mX =
        &Main_Firmware_DW.STATE_1_Discrete[0];
      simulationData->mData->mModeVector.mN = 6;
      simulationData->mData->mModeVector.mX = (int32_T *)
        &Main_Firmware_DW.STATE_1_Modes[0];
      tmp = false;
      simulationData->mData->mFoundZcEvents = tmp;
      simulationData->mData->mHadEvents = false;
      simulationData->mData->mIsMajorTimeStep = true;
      tmp = false;
      simulationData->mData->mIsSolverAssertCheck = tmp;
      simulationData->mData->mIsSolverCheckingCIC = false;
      simulationData->mData->mIsComputingJacobian = false;
      simulationData->mData->mIsEvaluatingF0 = false;
      simulationData->mData->mIsSolverRequestingReset = false;
      simulationData->mData->mIsModeUpdateTimeStep = true;
      tmp_1[0] = 0;
      tmp_0[0] = Main_Firmware_B.INPUT_1_1_1[0];
      tmp_0[1] = Main_Firmware_B.INPUT_1_1_1[1];
      tmp_0[2] = Main_Firmware_B.INPUT_1_1_1[2];
      tmp_0[3] = Main_Firmware_B.INPUT_1_1_1[3];
      tmp_1[1] = 4;
      tmp_0[4] = Main_Firmware_B.INPUT_2_1_1[0];
      tmp_0[5] = Main_Firmware_B.INPUT_2_1_1[1];
      tmp_0[6] = Main_Firmware_B.INPUT_2_1_1[2];
      tmp_0[7] = Main_Firmware_B.INPUT_2_1_1[3];
      tmp_1[2] = 8;
      tmp_0[8] = Main_Firmware_B.INPUT_3_1_1[0];
      tmp_0[9] = Main_Firmware_B.INPUT_3_1_1[1];
      tmp_0[10] = Main_Firmware_B.INPUT_3_1_1[2];
      tmp_0[11] = Main_Firmware_B.INPUT_3_1_1[3];
      tmp_1[3] = 12;
      tmp_0[12] = Main_Firmware_B.INPUT_4_1_1[0];
      tmp_0[13] = Main_Firmware_B.INPUT_4_1_1[1];
      tmp_0[14] = Main_Firmware_B.INPUT_4_1_1[2];
      tmp_0[15] = Main_Firmware_B.INPUT_4_1_1[3];
      tmp_1[4] = 16;
      tmp_0[16] = Main_Firmware_B.INPUT_5_1_1[0];
      tmp_0[17] = Main_Firmware_B.INPUT_5_1_1[1];
      tmp_0[18] = Main_Firmware_B.INPUT_5_1_1[2];
      tmp_0[19] = Main_Firmware_B.INPUT_5_1_1[3];
      tmp_1[5] = 20;
      tmp_0[20] = Main_Firmware_B.INPUT_6_1_1[0];
      tmp_0[21] = Main_Firmware_B.INPUT_6_1_1[1];
      tmp_0[22] = Main_Firmware_B.INPUT_6_1_1[2];
      tmp_0[23] = Main_Firmware_B.INPUT_6_1_1[3];
      tmp_1[6] = 24;
      tmp_0[24] = Main_Firmware_B.INPUT_7_1_1[0];
      tmp_0[25] = Main_Firmware_B.INPUT_7_1_1[1];
      tmp_0[26] = Main_Firmware_B.INPUT_7_1_1[2];
      tmp_0[27] = Main_Firmware_B.INPUT_7_1_1[3];
      tmp_1[7] = 28;
      simulationData->mData->mInputValues.mN = 28;
      simulationData->mData->mInputValues.mX = &tmp_0[0];
      simulationData->mData->mInputOffsets.mN = 8;
      simulationData->mData->mInputOffsets.mX = (int32_T *)&tmp_1[0];
      simulationData->mData->mOutputs.mN = 23;
      simulationData->mData->mOutputs.mX = &Main_Firmware_B.STATE_1[0];
      simulationData->mData->mTolerances.mN = 0;
      simulationData->mData->mTolerances.mX = NULL;
      simulationData->mData->mCstateHasChanged = false;
      simulationData->mData->mDstateHasChanged = false;
      Initial_i = (((Main_Firmware_M->Timing.clockTick1+
                     Main_Firmware_M->Timing.clockTickH1* 4294967296.0)) *
                   1.0E-6);
      time_0 = Initial_i;
      simulationData->mData->mTime.mN = 1;
      simulationData->mData->mTime.mX = &time_0;
      isHit = 0L;
      simulationData->mData->mSampleHits.mN = 1;
      simulationData->mData->mSampleHits.mX = &isHit;
      simulationData->mData->mIsFundamentalSampleHit = true;
      simulationData->mData->mHadEvents = false;
      diagnosticManager = (NeuDiagnosticManager *)
        Main_Firmware_DW.STATE_1_DiagMgr;
      diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
      tmp_2 = ne_simulator_method((NeslSimulator *)
        Main_Firmware_DW.STATE_1_Simulator, NESL_SIM_OUTPUTS, simulationData,
        diagnosticManager);
      if (tmp_2 != 0L) {
        tmp = error_buffer_is_empty(rtmGetErrorStatus(Main_Firmware_M));
        if (tmp) {
          msg = rtw_diagnostics_msg(diagnosticTree);
          rtmSetErrorStatus(Main_Firmware_M, msg);
        }
      }

      /* End of SimscapeExecutionBlock: '<S205>/STATE_1' */

      /* SimscapeExecutionBlock: '<S205>/OUTPUT_1_0' */
      simulationData = (NeslSimulationData *)Main_Firmware_DW.OUTPUT_1_0_SimData;
      time_1 = rtb_Product1_b;
      simulationData->mData->mTime.mN = 1;
      simulationData->mData->mTime.mX = &time_1;
      simulationData->mData->mContStates.mN = 0;
      simulationData->mData->mContStates.mX = NULL;
      simulationData->mData->mDiscStates.mN = 0;
      simulationData->mData->mDiscStates.mX =
        &Main_Firmware_DW.OUTPUT_1_0_Discrete;
      simulationData->mData->mModeVector.mN = 0;
      simulationData->mData->mModeVector.mX = (int32_T *)
        &Main_Firmware_DW.OUTPUT_1_0_Modes;
      tmp = false;
      simulationData->mData->mFoundZcEvents = tmp;
      simulationData->mData->mHadEvents = false;
      simulationData->mData->mIsMajorTimeStep = true;
      tmp = false;
      simulationData->mData->mIsSolverAssertCheck = tmp;
      simulationData->mData->mIsSolverCheckingCIC = false;
      simulationData->mData->mIsComputingJacobian = false;
      simulationData->mData->mIsEvaluatingF0 = false;
      simulationData->mData->mIsSolverRequestingReset = false;
      simulationData->mData->mIsModeUpdateTimeStep = true;
      tmp_3[0] = 0;
      Main_Firmware_B.dv[0] = Main_Firmware_B.INPUT_1_1_1[0];
      Main_Firmware_B.dv[1] = Main_Firmware_B.INPUT_1_1_1[1];
      Main_Firmware_B.dv[2] = Main_Firmware_B.INPUT_1_1_1[2];
      Main_Firmware_B.dv[3] = Main_Firmware_B.INPUT_1_1_1[3];
      tmp_3[1] = 4;
      Main_Firmware_B.dv[4] = Main_Firmware_B.INPUT_2_1_1[0];
      Main_Firmware_B.dv[5] = Main_Firmware_B.INPUT_2_1_1[1];
      Main_Firmware_B.dv[6] = Main_Firmware_B.INPUT_2_1_1[2];
      Main_Firmware_B.dv[7] = Main_Firmware_B.INPUT_2_1_1[3];
      tmp_3[2] = 8;
      Main_Firmware_B.dv[8] = Main_Firmware_B.INPUT_3_1_1[0];
      Main_Firmware_B.dv[9] = Main_Firmware_B.INPUT_3_1_1[1];
      Main_Firmware_B.dv[10] = Main_Firmware_B.INPUT_3_1_1[2];
      Main_Firmware_B.dv[11] = Main_Firmware_B.INPUT_3_1_1[3];
      tmp_3[3] = 12;
      Main_Firmware_B.dv[12] = Main_Firmware_B.INPUT_4_1_1[0];
      Main_Firmware_B.dv[13] = Main_Firmware_B.INPUT_4_1_1[1];
      Main_Firmware_B.dv[14] = Main_Firmware_B.INPUT_4_1_1[2];
      Main_Firmware_B.dv[15] = Main_Firmware_B.INPUT_4_1_1[3];
      tmp_3[4] = 16;
      Main_Firmware_B.dv[16] = Main_Firmware_B.INPUT_5_1_1[0];
      Main_Firmware_B.dv[17] = Main_Firmware_B.INPUT_5_1_1[1];
      Main_Firmware_B.dv[18] = Main_Firmware_B.INPUT_5_1_1[2];
      Main_Firmware_B.dv[19] = Main_Firmware_B.INPUT_5_1_1[3];
      tmp_3[5] = 20;
      Main_Firmware_B.dv[20] = Main_Firmware_B.INPUT_6_1_1[0];
      Main_Firmware_B.dv[21] = Main_Firmware_B.INPUT_6_1_1[1];
      Main_Firmware_B.dv[22] = Main_Firmware_B.INPUT_6_1_1[2];
      Main_Firmware_B.dv[23] = Main_Firmware_B.INPUT_6_1_1[3];
      tmp_3[6] = 24;
      Main_Firmware_B.dv[24] = Main_Firmware_B.INPUT_7_1_1[0];
      Main_Firmware_B.dv[25] = Main_Firmware_B.INPUT_7_1_1[1];
      Main_Firmware_B.dv[26] = Main_Firmware_B.INPUT_7_1_1[2];
      Main_Firmware_B.dv[27] = Main_Firmware_B.INPUT_7_1_1[3];
      tmp_3[7] = 28;
      memcpy(&Main_Firmware_B.dv[28], &Main_Firmware_B.STATE_1[0], 23U * sizeof
             (real_T));
      tmp_3[8] = 51;
      simulationData->mData->mInputValues.mN = 51;
      simulationData->mData->mInputValues.mX = &Main_Firmware_B.dv[0];
      simulationData->mData->mInputOffsets.mN = 9;
      simulationData->mData->mInputOffsets.mX = (int32_T *)&tmp_3[0];
      simulationData->mData->mOutputs.mN = 5;
      simulationData->mData->mOutputs.mX = &Main_Firmware_B.OUTPUT_1_0[0];
      simulationData->mData->mTolerances.mN = 0;
      simulationData->mData->mTolerances.mX = NULL;
      simulationData->mData->mCstateHasChanged = false;
      simulationData->mData->mDstateHasChanged = false;
      time_2 = Initial_i;
      simulationData->mData->mTime.mN = 1;
      simulationData->mData->mTime.mX = &time_2;
      isHit_0 = 0L;
      simulationData->mData->mSampleHits.mN = 1;
      simulationData->mData->mSampleHits.mX = &isHit_0;
      simulationData->mData->mIsFundamentalSampleHit = true;
      simulationData->mData->mHadEvents = false;
      diagnosticManager = (NeuDiagnosticManager *)
        Main_Firmware_DW.OUTPUT_1_0_DiagMgr;
      diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree
        (diagnosticManager);
      tmp_2 = ne_simulator_method((NeslSimulator *)
        Main_Firmware_DW.OUTPUT_1_0_Simulator, NESL_SIM_OUTPUTS, simulationData,
        diagnosticManager);
      if (tmp_2 != 0L) {
        tmp = error_buffer_is_empty(rtmGetErrorStatus(Main_Firmware_M));
        if (tmp) {
          msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
          rtmSetErrorStatus(Main_Firmware_M, msg_0);
        }
      }

      /* Reshape: '<S187>/RESHAPE' */
      Main_Firmware_B.RESHAPE[0] = Main_Firmware_B.OUTPUT_1_0[0];
      Main_Firmware_B.RESHAPE[1] = Main_Firmware_B.OUTPUT_1_0[1];
      Main_Firmware_B.RESHAPE[2] = Main_Firmware_B.OUTPUT_1_0[2];

      /* SimscapeExecutionBlock: '<S205>/OUTPUT_1_1' */
      simulationData = (NeslSimulationData *)Main_Firmware_DW.OUTPUT_1_1_SimData;
      time_3 = rtb_Product1_b;
      simulationData->mData->mTime.mN = 1;
      simulationData->mData->mTime.mX = &time_3;
      simulationData->mData->mContStates.mN = 0;
      simulationData->mData->mContStates.mX = NULL;
      simulationData->mData->mDiscStates.mN = 0;
      simulationData->mData->mDiscStates.mX =
        &Main_Firmware_DW.OUTPUT_1_1_Discrete;
      simulationData->mData->mModeVector.mN = 0;
      simulationData->mData->mModeVector.mX = (int32_T *)
        &Main_Firmware_DW.OUTPUT_1_1_Modes;
      tmp = false;
      simulationData->mData->mFoundZcEvents = tmp;
      simulationData->mData->mHadEvents = false;
      simulationData->mData->mIsMajorTimeStep = true;
      tmp = false;
      simulationData->mData->mIsSolverAssertCheck = tmp;
      simulationData->mData->mIsSolverCheckingCIC = false;
      simulationData->mData->mIsComputingJacobian = false;
      simulationData->mData->mIsEvaluatingF0 = false;
      simulationData->mData->mIsSolverRequestingReset = false;
      simulationData->mData->mIsModeUpdateTimeStep = true;
      tmp_5[0] = 0;
      tmp_4[0] = Main_Firmware_B.INPUT_1_1_1[0];
      tmp_4[1] = Main_Firmware_B.INPUT_1_1_1[1];
      tmp_4[2] = Main_Firmware_B.INPUT_1_1_1[2];
      tmp_4[3] = Main_Firmware_B.INPUT_1_1_1[3];
      tmp_5[1] = 4;
      tmp_4[4] = Main_Firmware_B.INPUT_2_1_1[0];
      tmp_4[5] = Main_Firmware_B.INPUT_2_1_1[1];
      tmp_4[6] = Main_Firmware_B.INPUT_2_1_1[2];
      tmp_4[7] = Main_Firmware_B.INPUT_2_1_1[3];
      tmp_5[2] = 8;
      tmp_4[8] = Main_Firmware_B.INPUT_3_1_1[0];
      tmp_4[9] = Main_Firmware_B.INPUT_3_1_1[1];
      tmp_4[10] = Main_Firmware_B.INPUT_3_1_1[2];
      tmp_4[11] = Main_Firmware_B.INPUT_3_1_1[3];
      tmp_5[3] = 12;
      tmp_4[12] = Main_Firmware_B.INPUT_4_1_1[0];
      tmp_4[13] = Main_Firmware_B.INPUT_4_1_1[1];
      tmp_4[14] = Main_Firmware_B.INPUT_4_1_1[2];
      tmp_4[15] = Main_Firmware_B.INPUT_4_1_1[3];
      tmp_5[4] = 16;
      tmp_4[16] = Main_Firmware_B.INPUT_5_1_1[0];
      tmp_4[17] = Main_Firmware_B.INPUT_5_1_1[1];
      tmp_4[18] = Main_Firmware_B.INPUT_5_1_1[2];
      tmp_4[19] = Main_Firmware_B.INPUT_5_1_1[3];
      tmp_5[5] = 20;
      tmp_4[20] = Main_Firmware_B.INPUT_6_1_1[0];
      tmp_4[21] = Main_Firmware_B.INPUT_6_1_1[1];
      tmp_4[22] = Main_Firmware_B.INPUT_6_1_1[2];
      tmp_4[23] = Main_Firmware_B.INPUT_6_1_1[3];
      tmp_5[6] = 24;
      tmp_4[24] = Main_Firmware_B.INPUT_7_1_1[0];
      tmp_4[25] = Main_Firmware_B.INPUT_7_1_1[1];
      tmp_4[26] = Main_Firmware_B.INPUT_7_1_1[2];
      tmp_4[27] = Main_Firmware_B.INPUT_7_1_1[3];
      tmp_5[7] = 28;
      memcpy(&tmp_4[28], &Main_Firmware_B.STATE_1[0], 23U * sizeof(real_T));
      tmp_5[8] = 51;
      simulationData->mData->mInputValues.mN = 51;
      simulationData->mData->mInputValues.mX = &tmp_4[0];
      simulationData->mData->mInputOffsets.mN = 9;
      simulationData->mData->mInputOffsets.mX = (int32_T *)&tmp_5[0];
      simulationData->mData->mOutputs.mN = 1;

      /* SimscapeExecutionBlock: '<S205>/OUTPUT_1_1' */
      simulationData->mData->mOutputs.mX = &Main_Firmware_B.OUTPUT_1_1;

      /* SimscapeExecutionBlock: '<S205>/OUTPUT_1_1' */
      simulationData->mData->mTolerances.mN = 0;
      simulationData->mData->mTolerances.mX = NULL;
      simulationData->mData->mCstateHasChanged = false;
      simulationData->mData->mDstateHasChanged = false;
      time_4 = Initial_i;
      simulationData->mData->mTime.mN = 1;
      simulationData->mData->mTime.mX = &time_4;
      isHit_1 = 0L;
      simulationData->mData->mSampleHits.mN = 1;
      simulationData->mData->mSampleHits.mX = &isHit_1;
      simulationData->mData->mIsFundamentalSampleHit = true;
      simulationData->mData->mHadEvents = false;
      diagnosticManager = (NeuDiagnosticManager *)
        Main_Firmware_DW.OUTPUT_1_1_DiagMgr;
      diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree
        (diagnosticManager);
      tmp_2 = ne_simulator_method((NeslSimulator *)
        Main_Firmware_DW.OUTPUT_1_1_Simulator, NESL_SIM_OUTPUTS, simulationData,
        diagnosticManager);
      if (tmp_2 != 0L) {
        tmp = error_buffer_is_empty(rtmGetErrorStatus(Main_Firmware_M));
        if (tmp) {
          msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
          rtmSetErrorStatus(Main_Firmware_M, msg_1);
        }
      }

      /* Constant: '<S1>/Speed request (Rad//s)1' */
      Main_Firmware_B.SpeedrequestRads1 =
        Main_Firmware_P.SpeedrequestRads1_Value;

      /* Delay: '<S2>/Delay' */
      Main_Firmware_B.Delay_j = Main_Firmware_DW.Delay_DSTATE_o;
    }

    /* Derivative: '<S2>/Derivative' */
    rtb_Product1_b = Main_Firmware_M->Timing.t[0];
    if ((Main_Firmware_DW.TimeStampA >= rtb_Product1_b) &&
        (Main_Firmware_DW.TimeStampB >= rtb_Product1_b)) {
      /* Derivative: '<S2>/Derivative' */
      Main_Firmware_B.RotorspeedRads = 0.0;
    } else {
      Initial_i = Main_Firmware_DW.TimeStampA;
      lastU = &Main_Firmware_DW.LastUAtTimeA;
      if (Main_Firmware_DW.TimeStampA < Main_Firmware_DW.TimeStampB) {
        if (Main_Firmware_DW.TimeStampB < rtb_Product1_b) {
          Initial_i = Main_Firmware_DW.TimeStampB;
          lastU = &Main_Firmware_DW.LastUAtTimeB;
        }
      } else if (Main_Firmware_DW.TimeStampA >= rtb_Product1_b) {
        Initial_i = Main_Firmware_DW.TimeStampB;
        lastU = &Main_Firmware_DW.LastUAtTimeB;
      }

      /* Derivative: '<S2>/Derivative' */
      Main_Firmware_B.RotorspeedRads = (Main_Firmware_B.Delay_j - *lastU) /
        (rtb_Product1_b - Initial_i);
    }

    /* End of Derivative: '<S2>/Derivative' */
    if (rtmIsMajorTimeStep(Main_Firmware_M) &&
        Main_Firmware_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* Gain: '<S2>/Gain2' */
    Main_Firmware_B.Electricalspeed = Main_Firmware_P.ppair *
      Main_Firmware_B.RotorspeedRads;
    if (rtmIsMajorTimeStep(Main_Firmware_M) &&
        Main_Firmware_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S118>/Gain3' incorporates:
       *  Delay: '<S1>/Sampling Delay'
       */
      Initial_i = Main_Firmware_B.RESHAPE[1];
      rtb_speed_err = Main_Firmware_B.RESHAPE[0];
      rtb_Add = Main_Firmware_B.RESHAPE[2];
      for (rtb_Compare = 0; rtb_Compare < 3; rtb_Compare++) {
        rtb_Product1_b = (Main_Firmware_P.Gain3_Gain_l[rtb_Compare + 3] *
                          Initial_i + Main_Firmware_P.Gain3_Gain_l[rtb_Compare] *
                          rtb_speed_err) +
          Main_Firmware_P.Gain3_Gain_l[rtb_Compare + 6] * rtb_Add;

        /* Delay: '<S1>/Sampling Delay' incorporates:
         *  Gain: '<S118>/Gain3'
         */
        Main_Firmware_DW.SamplingDelay_DSTATE[rtb_Compare] = rtb_Product1_b;

        /* Gain: '<S118>/Gain1' incorporates:
         *  Delay: '<S1>/Sampling Delay'
         */
        Main_Firmware_B.Gain1[rtb_Compare] = Main_Firmware_P.Gain1_Gain *
          rtb_Product1_b;
      }

      /* End of Gain: '<S118>/Gain3' */

      /* RelationalOperator: '<S119>/Compare' incorporates:
       *  Constant: '<S117>/Constant'
       *  Constant: '<S119>/Constant'
       */
      rtb_Compare = (Main_Firmware_P.AlphaBetaZerotodq0_Alignment ==
                     Main_Firmware_P.CompareToConstant_const);

      /* Outputs for Enabled SubSystem: '<S117>/Subsystem1' incorporates:
       *  EnablePort: '<S122>/Enable'
       */
      /* RelationalOperator: '<S119>/Compare' */
      if ((uint16_T)rtb_Compare > 0U) {
        /* Fcn: '<S122>/Fcn' */
        Main_Firmware_B.Fcn = Main_Firmware_B.Gain1[0] * cos
          (Main_Firmware_B.OUTPUT_1_0[3]) + Main_Firmware_B.Gain1[1] * sin
          (Main_Firmware_B.OUTPUT_1_0[3]);

        /* Fcn: '<S122>/Fcn1' */
        Main_Firmware_B.Fcn1 = -Main_Firmware_B.Gain1[0] * sin
          (Main_Firmware_B.OUTPUT_1_0[3]) + Main_Firmware_B.Gain1[1] * cos
          (Main_Firmware_B.OUTPUT_1_0[3]);
        if (rtsiIsModeUpdateTimeStep(&Main_Firmware_M->solverInfo)) {
          srUpdateBC(Main_Firmware_DW.Subsystem1_SubsysRanBC);
        }
      }

      /* End of Outputs for SubSystem: '<S117>/Subsystem1' */

      /* Outputs for Enabled SubSystem: '<S117>/Subsystem - pi//2 delay' incorporates:
       *  EnablePort: '<S121>/Enable'
       */
      /* RelationalOperator: '<S120>/Compare' incorporates:
       *  Constant: '<S117>/Constant'
       *  Constant: '<S120>/Constant'
       */
      if (Main_Firmware_P.AlphaBetaZerotodq0_Alignment ==
          Main_Firmware_P.CompareToConstant1_const) {
        /* Fcn: '<S121>/Fcn' */
        Main_Firmware_B.Fcn_m = Main_Firmware_B.Gain1[0] * sin
          (Main_Firmware_B.OUTPUT_1_0[3]) - Main_Firmware_B.Gain1[1] * cos
          (Main_Firmware_B.OUTPUT_1_0[3]);

        /* Fcn: '<S121>/Fcn1' */
        Main_Firmware_B.Fcn1_f = Main_Firmware_B.Gain1[0] * cos
          (Main_Firmware_B.OUTPUT_1_0[3]) + Main_Firmware_B.Gain1[1] * sin
          (Main_Firmware_B.OUTPUT_1_0[3]);
        if (rtsiIsModeUpdateTimeStep(&Main_Firmware_M->solverInfo)) {
          srUpdateBC(Main_Firmware_DW.Subsystempi2delay_SubsysRanBC);
        }
      }

      /* End of RelationalOperator: '<S120>/Compare' */
      /* End of Outputs for SubSystem: '<S117>/Subsystem - pi//2 delay' */

      /* Switch: '<S117>/Switch' incorporates:
       *  RelationalOperator: '<S119>/Compare'
       */
      if ((uint16_T)rtb_Compare != 0U) {
        /* Switch: '<S117>/Switch' */
        Main_Firmware_B.Switch[0] = Main_Firmware_B.Fcn;
        Main_Firmware_B.Switch[1] = Main_Firmware_B.Fcn1;
      } else {
        /* Switch: '<S117>/Switch' */
        Main_Firmware_B.Switch[0] = Main_Firmware_B.Fcn_m;
        Main_Firmware_B.Switch[1] = Main_Firmware_B.Fcn1_f;
      }

      /* End of Switch: '<S117>/Switch' */

      /* SignalConversion generated from: '<S2>/Park Transform' */
      Main_Firmware_B.TmpSignalConversionAtTAQSigLogg[0] =
        Main_Firmware_B.Switch[0];
      Main_Firmware_B.TmpSignalConversionAtTAQSigLogg[1] =
        Main_Firmware_B.Switch[1];
      Main_Firmware_B.TmpSignalConversionAtTAQSigLogg[2] =
        Main_Firmware_B.Gain1[2];

      /* Gain: '<S11>/Gain1' */
      Main_Firmware_B.Gain1_l = Main_Firmware_P.Lq * Main_Firmware_B.Switch[1];

      /* Gain: '<S11>/Gain' */
      Main_Firmware_B.Gain = Main_Firmware_P.Rs * Main_Firmware_B.Switch[0];
    }

    /* Gain: '<S11>/Gain5' */
    rtb_speed_err = Main_Firmware_P.ppair * Main_Firmware_B.Electricalspeed;

    /* Sum: '<S11>/Add' incorporates:
     *  Product: '<S11>/Product'
     */
    rtb_Add = Main_Firmware_B.Gain - Main_Firmware_B.Gain1_l * rtb_speed_err;
    if (rtmIsMajorTimeStep(Main_Firmware_M) &&
        Main_Firmware_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S11>/Gain3' */
      Main_Firmware_B.Gain3_i = Main_Firmware_P.Ld * Main_Firmware_B.Switch[0];

      /* Gain: '<S11>/Gain2' */
      Main_Firmware_B.Gain2_f = Main_Firmware_P.Rs * Main_Firmware_B.Switch[1];

      /* Gain: '<S2>/Gain7' */
      Main_Firmware_B.We = Main_Firmware_P.ppair *
        Main_Firmware_B.SpeedrequestRads1;
    }

    /* Sum: '<S11>/Add1' incorporates:
     *  Gain: '<S11>/Gain4'
     *  Product: '<S11>/Product1'
     */
    rtb_Add1 = (Main_Firmware_B.Gain3_i * rtb_speed_err +
                Main_Firmware_B.Gain2_f) + Main_Firmware_P.lambda *
      rtb_speed_err;

    /* Sum: '<S2>/Sum6' */
    rtb_speed_err = Main_Firmware_B.We - Main_Firmware_B.Electricalspeed;

    /* Gain: '<S159>/Filter Coefficient' incorporates:
     *  Gain: '<S149>/Derivative Gain'
     *  Integrator: '<S151>/Filter'
     *  Sum: '<S151>/SumD'
     */
    Main_Firmware_B.FilterCoefficient = (Main_Firmware_P.WePID_D * rtb_speed_err
      - Main_Firmware_X.Filter_CSTATE) * Main_Firmware_P.WePID_N;
    if (rtmIsMajorTimeStep(Main_Firmware_M) &&
        Main_Firmware_M->Timing.TaskCounters.TID[1] == 0) {
      /* Sum: '<S2>/Sum4' incorporates:
       *  Constant: '<S2>/Constant1'
       */
      Initial = Main_Firmware_P.Constant1_Value - Main_Firmware_B.Switch[0];

      /* Gain: '<S43>/Derivative Gain' */
      Main_Firmware_B.DerivativeGain = Main_Firmware_P.IDPID_D * Initial;

      /* Gain: '<S47>/Integral Gain' */
      Main_Firmware_B.IntegralGain = Main_Firmware_P.IDPID_I * Initial;

      /* Gain: '<S55>/Proportional Gain' */
      Main_Firmware_B.ProportionalGain = Main_Firmware_P.IDPID_P * Initial;
    }

    /* Gain: '<S53>/Filter Coefficient' incorporates:
     *  Integrator: '<S45>/Filter'
     *  Sum: '<S45>/SumD'
     */
    Main_Firmware_B.FilterCoefficient_e = (Main_Firmware_B.DerivativeGain -
      Main_Firmware_X.Filter_CSTATE_b) * Main_Firmware_P.IDPID_N;

    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S1>/Constant'
     *  Constant: '<S1>/torque request'
     *  Gain: '<S161>/Proportional Gain'
     *  Integrator: '<S156>/Integrator'
     *  Sum: '<S165>/Sum'
     */
    if (Main_Firmware_P.Constant_Value_d > Main_Firmware_P.Switch_Threshold) {
      rtb_Product1_b = Main_Firmware_P.torquerequest_Value;
    } else {
      rtb_Product1_b = (Main_Firmware_P.WePID_P * rtb_speed_err +
                        Main_Firmware_X.Integrator_CSTATE) +
        Main_Firmware_B.FilterCoefficient;
    }

    /* Sum: '<S2>/Sum3' incorporates:
     *  Gain: '<S2>/Gain6'
     *  Switch: '<S2>/Switch'
     */
    Initial_i = 2.0 / (Main_Firmware_P.ppair * Main_Firmware_P.lambda * 3.0) *
      rtb_Product1_b - Main_Firmware_B.Switch[1];

    /* Gain: '<S97>/Integral Gain' */
    Main_Firmware_B.IntegralGain_k = Main_Firmware_P.IQPID_I * Initial_i;

    /* Gain: '<S103>/Filter Coefficient' incorporates:
     *  Gain: '<S93>/Derivative Gain'
     *  Integrator: '<S95>/Filter'
     *  Sum: '<S95>/SumD'
     */
    Main_Firmware_B.FilterCoefficient_p = (Main_Firmware_P.IQPID_D * Initial_i -
      Main_Firmware_X.Filter_CSTATE_i) * Main_Firmware_P.IQPID_N;

    /* Sum: '<S2>/Sum1' incorporates:
     *  Integrator: '<S50>/Integrator'
     *  Sum: '<S59>/Sum'
     */
    rtb_Add1 += (Main_Firmware_B.ProportionalGain +
                 Main_Firmware_X.Integrator_CSTATE_n) +
      Main_Firmware_B.FilterCoefficient_e;

    /* Saturate: '<S2>/Limiter 1' */
    if (rtb_Add1 > Main_Firmware_P.Voltage_max) {
      rtb_Add1 = Main_Firmware_P.Voltage_max;
    } else if (rtb_Add1 < Main_Firmware_P.Limiter1_LowerSat) {
      rtb_Add1 = Main_Firmware_P.Limiter1_LowerSat;
    }

    /* End of Saturate: '<S2>/Limiter 1' */
    if (rtmIsMajorTimeStep(Main_Firmware_M) &&
        Main_Firmware_M->Timing.TaskCounters.TID[1] == 0) {
      /* Trigonometry: '<S14>/Trigonometric Function' */
      Main_Firmware_B.TrigonometricFunction = cos(Main_Firmware_B.OUTPUT_1_0[3]);

      /* Trigonometry: '<S14>/Trigonometric Function1' */
      Main_Firmware_B.TrigonometricFunction1 = sin(Main_Firmware_B.OUTPUT_1_0[3]);
    }

    /* Sum: '<S2>/Sum7' incorporates:
     *  Gain: '<S105>/Proportional Gain'
     *  Integrator: '<S100>/Integrator'
     *  Sum: '<S109>/Sum'
     */
    Initial_i = ((Main_Firmware_P.IQPID_P * Initial_i +
                  Main_Firmware_X.Integrator_CSTATE_e) +
                 Main_Firmware_B.FilterCoefficient_p) + rtb_Add;

    /* Saturate: '<S2>/Limiter' */
    if (Initial_i > Main_Firmware_P.Voltage_max) {
      Initial_i = Main_Firmware_P.Voltage_max;
    } else if (Initial_i < Main_Firmware_P.Limiter_LowerSat) {
      Initial_i = Main_Firmware_P.Limiter_LowerSat;
    }

    /* End of Saturate: '<S2>/Limiter' */
    if (rtmIsMajorTimeStep(Main_Firmware_M) &&
        Main_Firmware_M->Timing.TaskCounters.TID[1] == 0) {
      /* Bias: '<S14>/Bias' */
      Initial = Main_Firmware_B.OUTPUT_1_0[3] + Main_Firmware_P.Bias_Bias;

      /* Trigonometry: '<S14>/Trigonometric Function2' */
      Main_Firmware_B.TrigonometricFunction2 = cos(Initial);

      /* Trigonometry: '<S14>/Trigonometric Function3' */
      Main_Firmware_B.TrigonometricFunction3 = sin(Initial);

      /* Bias: '<S14>/Bias1' */
      Initial = Main_Firmware_B.OUTPUT_1_0[3] + Main_Firmware_P.Bias1_Bias;

      /* Trigonometry: '<S14>/Trigonometric Function4' */
      Main_Firmware_B.TrigonometricFunction4 = cos(Initial);

      /* Trigonometry: '<S14>/Trigonometric Function5' */
      Main_Firmware_B.TrigonometricFunction5 = sin(Initial);
    }

    /* Gain: '<S153>/Integral Gain' */
    Main_Firmware_B.IntegralGain_b = Main_Firmware_P.WePID_I * rtb_speed_err;

    /* Gain: '<S1>/Gain5' */
    rtb_Product1_b = 1.0 / Main_Firmware_P.Voltage_max;

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/Constant7'
     *  Gain: '<S1>/Gain5'
     *  Product: '<S14>/Product'
     *  Product: '<S14>/Product1'
     *  Product: '<S14>/Product2'
     *  Product: '<S14>/Product3'
     *  Product: '<S14>/Product4'
     *  Product: '<S14>/Product5'
     *  Sum: '<S14>/Add'
     *  Sum: '<S14>/Add1'
     *  Sum: '<S14>/Add2'
     */
    Main_Firmware_B.Sum[0] = (rtb_Add1 * Main_Firmware_B.TrigonometricFunction -
      Main_Firmware_B.TrigonometricFunction1 * Initial_i) * rtb_Product1_b +
      Main_Firmware_P.Constant7_Value;
    Main_Firmware_B.Sum[1] = (rtb_Add1 * Main_Firmware_B.TrigonometricFunction2
      - Main_Firmware_B.TrigonometricFunction3 * Initial_i) * rtb_Product1_b +
      Main_Firmware_P.Constant7_Value;
    Main_Firmware_B.Sum[2] = (rtb_Add1 * Main_Firmware_B.TrigonometricFunction4
      - Main_Firmware_B.TrigonometricFunction5 * Initial_i) * rtb_Product1_b +
      Main_Firmware_P.Constant7_Value;
    if (rtmIsMajorTimeStep(Main_Firmware_M) &&
        Main_Firmware_M->Timing.TaskCounters.TID[1] == 0) {
      /* Math: '<S1>/Square' */
      Initial = Main_Firmware_B.OUTPUT_1_0[4] * Main_Firmware_B.OUTPUT_1_0[4];

      /* Gain: '<S1>/Gain2' incorporates:
       *  Constant: '<S1>/Constant2'
       *  Constant: '<S1>/Constant3'
       *  Product: '<S1>/Product2'
       *  Sum: '<S1>/Sum1'
       */
      Main_Firmware_B.Gain2_c = ((0.0 - 5.0E-5 * Main_Firmware_P.C_d *
        Main_Firmware_P.A_f * 0.1296 * Initial) - Main_Firmware_P.m *
        Main_Firmware_P.g * Main_Firmware_P.C_rr) * Main_Firmware_P.Gain2_Gain_n;
    }

    if (rtmIsMajorTimeStep(Main_Firmware_M) &&
        Main_Firmware_M->Timing.TaskCounters.TID[2] == 0) {
      /* DiscretePulseGenerator: '<S1>/LED Heartbeat' */
      Main_Firmware_B.LEDHeartbeat = (Main_Firmware_DW.clockTickCounter <
        Main_Firmware_P.LEDHeartbeat_Duty) && (Main_Firmware_DW.clockTickCounter
        >= 0L) ? Main_Firmware_P.LEDHeartbeat_Amp : 0.0;

      /* DiscretePulseGenerator: '<S1>/LED Heartbeat' */
      if (Main_Firmware_DW.clockTickCounter >=
          Main_Firmware_P.LEDHeartbeat_Period - 1.0) {
        Main_Firmware_DW.clockTickCounter = 0L;
      } else {
        Main_Firmware_DW.clockTickCounter++;
      }

      /* S-Function (c280xgpio_do): '<S1>/Digital Output' */
      {
        if (Main_Firmware_B.LEDHeartbeat) {
          GpioDataRegs.GPASET.bit.GPIO23 = 1U;
        } else {
          GpioDataRegs.GPACLEAR.bit.GPIO23 = 1U;
        }
      }
    }
  }

  if (rtmIsMajorTimeStep(Main_Firmware_M)) {
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    char *msg;
    real_T tmp_0[28];
    real_T time;
    real_T *lastU;
    int32_T tmp_2;
    int_T tmp_1[8];
    boolean_T tmp;
    if (rtmIsMajorTimeStep(Main_Firmware_M) &&
        Main_Firmware_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for Delay: '<S1>/Sampling Delay' */
      Main_Firmware_DW.SamplingDelay_DSTATE[0] = Main_Firmware_B.Sum[0];
      Main_Firmware_DW.SamplingDelay_DSTATE[1] = Main_Firmware_B.Sum[1];
      Main_Firmware_DW.SamplingDelay_DSTATE[2] = Main_Firmware_B.Sum[2];

      /* Update for DiscreteIntegrator: '<S196>/Integrator' incorporates:
       *  Constant: '<S189>/Constant3'
       */
      Main_Firmware_DW.Integrator_DSTATE += Main_Firmware_P.Integrator_gainval *
        Main_Firmware_P.Constant3_Value;

      /* Update for DiscreteIntegrator: '<S200>/Integrator' incorporates:
       *  Constant: '<S189>/Constant3'
       */
      Main_Firmware_DW.Integrator_DSTATE_d +=
        Main_Firmware_P.Integrator_gainval_k * Main_Firmware_P.Constant3_Value;

      /* Update for Delay: '<S1>/Delay' */
      Main_Firmware_DW.Delay_DSTATE = Main_Firmware_B.Gain2_c;

      /* Update for SimscapeExecutionBlock: '<S205>/STATE_1' */
      simulationData = (NeslSimulationData *)Main_Firmware_DW.STATE_1_SimData;
      time = Main_Firmware_M->Timing.t[0];
      simulationData->mData->mTime.mN = 1;
      simulationData->mData->mTime.mX = &time;
      simulationData->mData->mContStates.mN = 0;
      simulationData->mData->mContStates.mX = NULL;
      simulationData->mData->mDiscStates.mN = 17;
      simulationData->mData->mDiscStates.mX =
        &Main_Firmware_DW.STATE_1_Discrete[0];
      simulationData->mData->mModeVector.mN = 6;
      simulationData->mData->mModeVector.mX = (int32_T *)
        &Main_Firmware_DW.STATE_1_Modes[0];
      tmp = false;
      simulationData->mData->mFoundZcEvents = tmp;
      simulationData->mData->mHadEvents = false;
      simulationData->mData->mIsMajorTimeStep = true;
      tmp = false;
      simulationData->mData->mIsSolverAssertCheck = tmp;
      simulationData->mData->mIsSolverCheckingCIC = false;
      simulationData->mData->mIsComputingJacobian = false;
      simulationData->mData->mIsEvaluatingF0 = false;
      simulationData->mData->mIsSolverRequestingReset = false;
      simulationData->mData->mIsModeUpdateTimeStep = true;
      tmp_1[0] = 0;
      tmp_0[0] = Main_Firmware_B.INPUT_1_1_1[0];
      tmp_0[1] = Main_Firmware_B.INPUT_1_1_1[1];
      tmp_0[2] = Main_Firmware_B.INPUT_1_1_1[2];
      tmp_0[3] = Main_Firmware_B.INPUT_1_1_1[3];
      tmp_1[1] = 4;
      tmp_0[4] = Main_Firmware_B.INPUT_2_1_1[0];
      tmp_0[5] = Main_Firmware_B.INPUT_2_1_1[1];
      tmp_0[6] = Main_Firmware_B.INPUT_2_1_1[2];
      tmp_0[7] = Main_Firmware_B.INPUT_2_1_1[3];
      tmp_1[2] = 8;
      tmp_0[8] = Main_Firmware_B.INPUT_3_1_1[0];
      tmp_0[9] = Main_Firmware_B.INPUT_3_1_1[1];
      tmp_0[10] = Main_Firmware_B.INPUT_3_1_1[2];
      tmp_0[11] = Main_Firmware_B.INPUT_3_1_1[3];
      tmp_1[3] = 12;
      tmp_0[12] = Main_Firmware_B.INPUT_4_1_1[0];
      tmp_0[13] = Main_Firmware_B.INPUT_4_1_1[1];
      tmp_0[14] = Main_Firmware_B.INPUT_4_1_1[2];
      tmp_0[15] = Main_Firmware_B.INPUT_4_1_1[3];
      tmp_1[4] = 16;
      tmp_0[16] = Main_Firmware_B.INPUT_5_1_1[0];
      tmp_0[17] = Main_Firmware_B.INPUT_5_1_1[1];
      tmp_0[18] = Main_Firmware_B.INPUT_5_1_1[2];
      tmp_0[19] = Main_Firmware_B.INPUT_5_1_1[3];
      tmp_1[5] = 20;
      tmp_0[20] = Main_Firmware_B.INPUT_6_1_1[0];
      tmp_0[21] = Main_Firmware_B.INPUT_6_1_1[1];
      tmp_0[22] = Main_Firmware_B.INPUT_6_1_1[2];
      tmp_0[23] = Main_Firmware_B.INPUT_6_1_1[3];
      tmp_1[6] = 24;
      tmp_0[24] = Main_Firmware_B.INPUT_7_1_1[0];
      tmp_0[25] = Main_Firmware_B.INPUT_7_1_1[1];
      tmp_0[26] = Main_Firmware_B.INPUT_7_1_1[2];
      tmp_0[27] = Main_Firmware_B.INPUT_7_1_1[3];
      tmp_1[7] = 28;
      simulationData->mData->mInputValues.mN = 28;
      simulationData->mData->mInputValues.mX = &tmp_0[0];
      simulationData->mData->mInputOffsets.mN = 8;
      simulationData->mData->mInputOffsets.mX = (int32_T *)&tmp_1[0];
      diagnosticManager = (NeuDiagnosticManager *)
        Main_Firmware_DW.STATE_1_DiagMgr;
      diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
      tmp_2 = ne_simulator_method((NeslSimulator *)
        Main_Firmware_DW.STATE_1_Simulator, NESL_SIM_UPDATE, simulationData,
        diagnosticManager);
      if (tmp_2 != 0L) {
        tmp = error_buffer_is_empty(rtmGetErrorStatus(Main_Firmware_M));
        if (tmp) {
          msg = rtw_diagnostics_msg(diagnosticTree);
          rtmSetErrorStatus(Main_Firmware_M, msg);
        }
      }

      /* End of Update for SimscapeExecutionBlock: '<S205>/STATE_1' */

      /* Update for Delay: '<S2>/Delay' */
      Main_Firmware_DW.Delay_DSTATE_o = Main_Firmware_B.OUTPUT_1_0[3];
    }

    /* Update for Derivative: '<S2>/Derivative' */
    if (Main_Firmware_DW.TimeStampA == (rtInf)) {
      Main_Firmware_DW.TimeStampA = Main_Firmware_M->Timing.t[0];
      lastU = &Main_Firmware_DW.LastUAtTimeA;
    } else if (Main_Firmware_DW.TimeStampB == (rtInf)) {
      Main_Firmware_DW.TimeStampB = Main_Firmware_M->Timing.t[0];
      lastU = &Main_Firmware_DW.LastUAtTimeB;
    } else if (Main_Firmware_DW.TimeStampA < Main_Firmware_DW.TimeStampB) {
      Main_Firmware_DW.TimeStampA = Main_Firmware_M->Timing.t[0];
      lastU = &Main_Firmware_DW.LastUAtTimeA;
    } else {
      Main_Firmware_DW.TimeStampB = Main_Firmware_M->Timing.t[0];
      lastU = &Main_Firmware_DW.LastUAtTimeB;
    }

    *lastU = Main_Firmware_B.Delay_j;

    /* End of Update for Derivative: '<S2>/Derivative' */
    if (rtmIsMajorTimeStep(Main_Firmware_M) &&
        Main_Firmware_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [1.0E-6s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        (((Main_Firmware_M->Timing.clockTick1+
           Main_Firmware_M->Timing.clockTickH1* 4294967296.0) * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(Main_Firmware_M) &&
        Main_Firmware_M->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.5s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((Main_Firmware_M->Timing.clockTick2 * 500000) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(2,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Main_Firmware_M)) {
    rt_ertODEUpdateContinuousStates(&Main_Firmware_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Main_Firmware_M->Timing.clockTick0)) {
      ++Main_Firmware_M->Timing.clockTickH0;
    }

    Main_Firmware_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Main_Firmware_M->solverInfo);

    {
      /* Update absolute timer for sample time: [1.0E-6s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 1.0E-6, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Main_Firmware_M->Timing.clockTick1++;
      if (!Main_Firmware_M->Timing.clockTick1) {
        Main_Firmware_M->Timing.clockTickH1++;
      }
    }

    if (rtmIsMajorTimeStep(Main_Firmware_M) &&
        Main_Firmware_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update absolute timer for sample time: [0.5s, 0.0s] */
      /* The "clockTick2" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.5, which is the step size
       * of the task. Size of "clockTick2" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Main_Firmware_M->Timing.clockTick2++;
    }

    rate_scheduler();
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Main_Firmware_derivatives(void)
{
  XDot_Main_Firmware_T *_rtXdot;
  _rtXdot = ((XDot_Main_Firmware_T *) Main_Firmware_M->derivs);

  /* Derivatives for Integrator: '<S156>/Integrator' */
  _rtXdot->Integrator_CSTATE = Main_Firmware_B.IntegralGain_b;

  /* Derivatives for Integrator: '<S151>/Filter' */
  _rtXdot->Filter_CSTATE = Main_Firmware_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S45>/Filter' */
  _rtXdot->Filter_CSTATE_b = Main_Firmware_B.FilterCoefficient_e;

  /* Derivatives for Integrator: '<S50>/Integrator' */
  _rtXdot->Integrator_CSTATE_n = Main_Firmware_B.IntegralGain;

  /* Derivatives for Integrator: '<S95>/Filter' */
  _rtXdot->Filter_CSTATE_i = Main_Firmware_B.FilterCoefficient_p;

  /* Derivatives for Integrator: '<S100>/Integrator' */
  _rtXdot->Integrator_CSTATE_e = Main_Firmware_B.IntegralGain_k;
}

/* Model initialize function */
void Main_Firmware_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Main_Firmware_M, 0,
                sizeof(RT_MODEL_Main_Firmware_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Main_Firmware_M->solverInfo,
                          &Main_Firmware_M->Timing.simTimeStep);
    rtsiSetTPtr(&Main_Firmware_M->solverInfo, &rtmGetTPtr(Main_Firmware_M));
    rtsiSetStepSizePtr(&Main_Firmware_M->solverInfo,
                       &Main_Firmware_M->Timing.stepSize0);
    rtsiSetdXPtr(&Main_Firmware_M->solverInfo, &Main_Firmware_M->derivs);
    rtsiSetContStatesPtr(&Main_Firmware_M->solverInfo, (real_T **)
                         &Main_Firmware_M->contStates);
    rtsiSetNumContStatesPtr(&Main_Firmware_M->solverInfo,
      &Main_Firmware_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Main_Firmware_M->solverInfo,
      &Main_Firmware_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Main_Firmware_M->solverInfo,
      &Main_Firmware_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Main_Firmware_M->solverInfo,
      &Main_Firmware_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&Main_Firmware_M->solverInfo, (boolean_T**)
      &Main_Firmware_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&Main_Firmware_M->solverInfo, (&rtmGetErrorStatus
      (Main_Firmware_M)));
    rtsiSetRTModelPtr(&Main_Firmware_M->solverInfo, Main_Firmware_M);
  }

  rtsiSetSimTimeStep(&Main_Firmware_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Main_Firmware_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&Main_Firmware_M->solverInfo, false);
  Main_Firmware_M->intgData.y = Main_Firmware_M->odeY;
  Main_Firmware_M->intgData.f[0] = Main_Firmware_M->odeF[0];
  Main_Firmware_M->intgData.f[1] = Main_Firmware_M->odeF[1];
  Main_Firmware_M->intgData.f[2] = Main_Firmware_M->odeF[2];
  Main_Firmware_M->contStates = ((X_Main_Firmware_T *) &Main_Firmware_X);
  Main_Firmware_M->contStateDisabled = ((XDis_Main_Firmware_T *)
    &Main_Firmware_XDis);
  Main_Firmware_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&Main_Firmware_M->solverInfo, (void *)
                    &Main_Firmware_M->intgData);
  rtsiSetSolverName(&Main_Firmware_M->solverInfo,"ode3");
  rtmSetTPtr(Main_Firmware_M, &Main_Firmware_M->Timing.tArray[0]);
  rtmSetTFinal(Main_Firmware_M, -1);
  Main_Firmware_M->Timing.stepSize0 = 1.0E-6;

  /* External mode info */
  Main_Firmware_M->Sizes.checksums[0] = (992459904U);
  Main_Firmware_M->Sizes.checksums[1] = (3381992738U);
  Main_Firmware_M->Sizes.checksums[2] = (2507045517U);
  Main_Firmware_M->Sizes.checksums[3] = (1150926523U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    Main_Firmware_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &Main_Firmware_DW.Subsystempi2delay_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&Main_Firmware_DW.Subsystem1_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Main_Firmware_M->extModeInfo,
      &Main_Firmware_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Main_Firmware_M->extModeInfo,
                        Main_Firmware_M->Sizes.checksums);
    rteiSetTPtr(Main_Firmware_M->extModeInfo, rtmGetTPtr(Main_Firmware_M));
  }

  /* block I/O */
  (void) memset(((void *) &Main_Firmware_B), 0,
                sizeof(B_Main_Firmware_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Main_Firmware_X, 0,
                  sizeof(X_Main_Firmware_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&Main_Firmware_XDis, 0,
                  sizeof(XDis_Main_Firmware_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Main_Firmware_DW, 0,
                sizeof(DW_Main_Firmware_T));

  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeModelParameters modelParameters_1;
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    NeuDiagnosticTree *diagnosticTree_1;
    char *msg;
    char *msg_0;
    char *msg_1;
    real_T Initial;
    real_T Initial_i;
    real_T tmp_2;
    int32_T tmp_3;
    boolean_T tmp_0;

    /* Start for Probe: '<S195>/Probe' */
    Main_Firmware_B.Probe[0] = 1.0E-6;
    Main_Firmware_B.Probe[1] = 0.0;

    /* Start for InitialCondition: '<S196>/Initial' */
    Initial = Main_Firmware_P.IntegratorwithWrappedStateDis_b;

    /* Start for InitialCondition: '<S196>/Initial' */
    Main_Firmware_DW.Initial_FirstOutputTime = true;

    /* Start for InitialCondition: '<S200>/Initial' */
    Initial_i = Main_Firmware_P.PWMGenerator_Tdelay;

    /* Start for InitialCondition: '<S200>/Initial' */
    Main_Firmware_DW.Initial_FirstOutputTime_o = true;

    /* Start for SimscapeExecutionBlock: '<S205>/STATE_1' */
    tmp = nesl_lease_simulator("Main_Firmware/FOC test/Solver Configuration_1",
      0L, 0L);
    Main_Firmware_DW.STATE_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(Main_Firmware_DW.STATE_1_Simulator);
    if (tmp_0) {
      Main_Firmware_bbbdb992_1_gateway();
      tmp = nesl_lease_simulator("Main_Firmware/FOC test/Solver Configuration_1",
        0L, 0L);
      Main_Firmware_DW.STATE_1_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    Main_Firmware_DW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    Main_Firmware_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters.mSolverAbsTol = 0.001;
    modelParameters.mSolverRelTol = 0.001;
    modelParameters.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters.mRTWModifiedTimeStamp = 6.61725626E+8;
    modelParameters.mUseModelRefSolver = false;
    modelParameters.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters.mSolverTolerance = tmp_2;
    tmp_2 = 1.0E-6;
    modelParameters.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters.mIsUsingODEN = tmp_0;
    modelParameters.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)Main_Firmware_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      Main_Firmware_DW.STATE_1_Simulator, &modelParameters, diagnosticManager);
    if (tmp_3 != 0L) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Main_Firmware_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Main_Firmware_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S205>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S205>/OUTPUT_1_0' */
    tmp = nesl_lease_simulator("Main_Firmware/FOC test/Solver Configuration_1",
      1L, 0L);
    Main_Firmware_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(Main_Firmware_DW.OUTPUT_1_0_Simulator);
    if (tmp_0) {
      Main_Firmware_bbbdb992_1_gateway();
      tmp = nesl_lease_simulator("Main_Firmware/FOC test/Solver Configuration_1",
        1L, 0L);
      Main_Firmware_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    Main_Firmware_DW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    Main_Firmware_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_0.mSolverAbsTol = 0.001;
    modelParameters_0.mSolverRelTol = 0.001;
    modelParameters_0.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters_0.mRTWModifiedTimeStamp = 6.61725626E+8;
    modelParameters_0.mUseModelRefSolver = false;
    modelParameters_0.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_2;
    tmp_2 = 1.0E-6;
    modelParameters_0.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_0.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_0.mIsUsingODEN = tmp_0;
    modelParameters_0.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      Main_Firmware_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      Main_Firmware_DW.OUTPUT_1_0_Simulator, &modelParameters_0,
      diagnosticManager);
    if (tmp_3 != 0L) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Main_Firmware_M));
      if (tmp_0) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(Main_Firmware_M, msg_0);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S205>/OUTPUT_1_0' */

    /* Start for SimscapeExecutionBlock: '<S205>/OUTPUT_1_1' */
    tmp = nesl_lease_simulator("Main_Firmware/FOC test/Solver Configuration_1",
      1L, 1L);
    Main_Firmware_DW.OUTPUT_1_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(Main_Firmware_DW.OUTPUT_1_1_Simulator);
    if (tmp_0) {
      Main_Firmware_bbbdb992_1_gateway();
      tmp = nesl_lease_simulator("Main_Firmware/FOC test/Solver Configuration_1",
        1L, 1L);
      Main_Firmware_DW.OUTPUT_1_1_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    Main_Firmware_DW.OUTPUT_1_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    Main_Firmware_DW.OUTPUT_1_1_DiagMgr = (void *)diagnosticManager;
    modelParameters_1.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_1.mSolverAbsTol = 0.001;
    modelParameters_1.mSolverRelTol = 0.001;
    modelParameters_1.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_1.mStartTime = 0.0;
    modelParameters_1.mLoadInitialState = false;
    modelParameters_1.mUseSimState = false;
    modelParameters_1.mLinTrimCompile = false;
    modelParameters_1.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters_1.mRTWModifiedTimeStamp = 6.61725626E+8;
    modelParameters_1.mUseModelRefSolver = false;
    modelParameters_1.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters_1.mSolverTolerance = tmp_2;
    tmp_2 = 1.0E-6;
    modelParameters_1.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_1.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_1.mIsUsingODEN = tmp_0;
    modelParameters_1.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      Main_Firmware_DW.OUTPUT_1_1_DiagMgr;
    diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      Main_Firmware_DW.OUTPUT_1_1_Simulator, &modelParameters_1,
      diagnosticManager);
    if (tmp_3 != 0L) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Main_Firmware_M));
      if (tmp_0) {
        msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
        rtmSetErrorStatus(Main_Firmware_M, msg_1);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S205>/OUTPUT_1_1' */
    /* Start for DiscretePulseGenerator: '<S1>/LED Heartbeat' */
    Main_Firmware_DW.clockTickCounter = 0L;

    /* Start for S-Function (c280xgpio_do): '<S1>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0xFFFF3FFFU;
    GpioCtrlRegs.GPADIR.all |= 0x800000U;
    EDIS;

    /* InitializeConditions for Delay: '<S1>/Sampling Delay' */
    Main_Firmware_DW.SamplingDelay_DSTATE[0] =
      Main_Firmware_P.SamplingDelay_InitialCondition;
    Main_Firmware_DW.SamplingDelay_DSTATE[1] =
      Main_Firmware_P.SamplingDelay_InitialCondition;
    Main_Firmware_DW.SamplingDelay_DSTATE[2] =
      Main_Firmware_P.SamplingDelay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S196>/Integrator' */
    Main_Firmware_DW.Integrator_DSTATE = Initial;

    /* InitializeConditions for DiscreteIntegrator: '<S200>/Integrator' */
    Main_Firmware_DW.Integrator_DSTATE_d = Initial_i;

    /* InitializeConditions for Delay: '<S1>/Delay' */
    Main_Firmware_DW.Delay_DSTATE = Main_Firmware_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S2>/Delay' */
    Main_Firmware_DW.Delay_DSTATE_o = Main_Firmware_P.Delay_InitialCondition_a;

    /* InitializeConditions for Derivative: '<S2>/Derivative' */
    Main_Firmware_DW.TimeStampA = (rtInf);
    Main_Firmware_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Integrator: '<S156>/Integrator' */
    Main_Firmware_X.Integrator_CSTATE =
      Main_Firmware_P.WePID_InitialConditionForIntegr;

    /* InitializeConditions for Integrator: '<S151>/Filter' */
    Main_Firmware_X.Filter_CSTATE =
      Main_Firmware_P.WePID_InitialConditionForFilter;

    /* InitializeConditions for Integrator: '<S45>/Filter' */
    Main_Firmware_X.Filter_CSTATE_b =
      Main_Firmware_P.IDPID_InitialConditionForFilter;

    /* InitializeConditions for Integrator: '<S50>/Integrator' */
    Main_Firmware_X.Integrator_CSTATE_n =
      Main_Firmware_P.IDPID_InitialConditionForIntegr;

    /* InitializeConditions for Integrator: '<S95>/Filter' */
    Main_Firmware_X.Filter_CSTATE_i =
      Main_Firmware_P.IQPID_InitialConditionForFilter;

    /* InitializeConditions for Integrator: '<S100>/Integrator' */
    Main_Firmware_X.Integrator_CSTATE_e =
      Main_Firmware_P.IQPID_InitialConditionForIntegr;

    /* SystemInitialize for Enabled SubSystem: '<S117>/Subsystem1' */
    /* SystemInitialize for Fcn: '<S122>/Fcn' incorporates:
     *  Outport: '<S122>/dq'
     */
    Main_Firmware_B.Fcn = Main_Firmware_P.dq_Y0_j[0];

    /* SystemInitialize for Fcn: '<S122>/Fcn1' incorporates:
     *  Outport: '<S122>/dq'
     */
    Main_Firmware_B.Fcn1 = Main_Firmware_P.dq_Y0_j[1];

    /* End of SystemInitialize for SubSystem: '<S117>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S117>/Subsystem - pi//2 delay' */
    /* SystemInitialize for Fcn: '<S121>/Fcn' incorporates:
     *  Outport: '<S121>/dq'
     */
    Main_Firmware_B.Fcn_m = Main_Firmware_P.dq_Y0[0];

    /* SystemInitialize for Fcn: '<S121>/Fcn1' incorporates:
     *  Outport: '<S121>/dq'
     */
    Main_Firmware_B.Fcn1_f = Main_Firmware_P.dq_Y0[1];

    /* End of SystemInitialize for SubSystem: '<S117>/Subsystem - pi//2 delay' */
  }
}

/* Model terminate function */
void Main_Firmware_terminate(void)
{
  /* Terminate for SimscapeExecutionBlock: '<S205>/STATE_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    Main_Firmware_DW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    Main_Firmware_DW.STATE_1_SimData);
  nesl_erase_simulator("Main_Firmware/FOC test/Solver Configuration_1");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S205>/OUTPUT_1_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    Main_Firmware_DW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    Main_Firmware_DW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("Main_Firmware/FOC test/Solver Configuration_1");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S205>/OUTPUT_1_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    Main_Firmware_DW.OUTPUT_1_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    Main_Firmware_DW.OUTPUT_1_1_SimData);
  nesl_erase_simulator("Main_Firmware/FOC test/Solver Configuration_1");
  nesl_destroy_registry();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
