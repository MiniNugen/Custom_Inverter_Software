/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Main_Firmware.c
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

#include "Main_Firmware.h"
#include "rtwtypes.h"
#include "Main_Firmware_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>

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
  int_T nXc = 7;
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

/*
 * System initialize for enable system:
 *    '<S115>/Subsystem - pi//2 delay'
 *    '<S177>/Subsystem - pi//2 delay'
 */
void Main_Fir_Subsystempi2delay_Init(real_T *rty_dq, real_T *rty_dq_f,
  P_Subsystempi2delay_Main_Firm_T *localP)
{
  /* SystemInitialize for Outport: '<S119>/dq' */
  *rty_dq = localP->dq_Y0[0];
  *rty_dq_f = localP->dq_Y0[1];
}

/*
 * Disable for enable system:
 *    '<S115>/Subsystem - pi//2 delay'
 *    '<S177>/Subsystem - pi//2 delay'
 */
void Main__Subsystempi2delay_Disable(DW_Subsystempi2delay_Main_Fir_T *localDW)
{
  localDW->Subsystempi2delay_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S115>/Subsystem - pi//2 delay'
 *    '<S177>/Subsystem - pi//2 delay'
 */
void Main_Firmware_Subsystempi2delay(RT_MODEL_Main_Firmware_T * const
  Main_Firmware_M, uint16_T rtu_Enable, const real_T rtu_alpha_beta[2], real_T
  rtu_wt, real_T *rty_dq, real_T *rty_dq_f, DW_Subsystempi2delay_Main_Fir_T
  *localDW)
{
  real_T tmp;
  real_T tmp_0;

  /* Outputs for Enabled SubSystem: '<S115>/Subsystem - pi//2 delay' incorporates:
   *  EnablePort: '<S119>/Enable'
   */
  if (rtmIsMajorTimeStep(Main_Firmware_M) && rtsiIsModeUpdateTimeStep
      (&Main_Firmware_M->solverInfo)) {
    if (rtu_Enable > 0U) {
      localDW->Subsystempi2delay_MODE = true;
    } else if (localDW->Subsystempi2delay_MODE) {
      Main__Subsystempi2delay_Disable(localDW);
    }
  }

  if (localDW->Subsystempi2delay_MODE) {
    /* Fcn: '<S119>/Fcn' incorporates:
     *  Fcn: '<S119>/Fcn1'
     */
    tmp = cos(rtu_wt);
    tmp_0 = sin(rtu_wt);
    *rty_dq = rtu_alpha_beta[0] * tmp_0 - rtu_alpha_beta[1] * tmp;

    /* Fcn: '<S119>/Fcn1' */
    *rty_dq_f = rtu_alpha_beta[0] * tmp + rtu_alpha_beta[1] * tmp_0;
    if (rtsiIsModeUpdateTimeStep(&Main_Firmware_M->solverInfo)) {
      srUpdateBC(localDW->Subsystempi2delay_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S115>/Subsystem - pi//2 delay' */
}

/*
 * System initialize for enable system:
 *    '<S115>/Subsystem1'
 *    '<S177>/Subsystem1'
 */
void Main_Firmware_Subsystem1_Init(real_T *rty_dq, real_T *rty_dq_e,
  P_Subsystem1_Main_Firmware_T *localP)
{
  /* SystemInitialize for Outport: '<S120>/dq' */
  *rty_dq = localP->dq_Y0[0];
  *rty_dq_e = localP->dq_Y0[1];
}

/*
 * Disable for enable system:
 *    '<S115>/Subsystem1'
 *    '<S177>/Subsystem1'
 */
void Main_Firmwar_Subsystem1_Disable(DW_Subsystem1_Main_Firmware_T *localDW)
{
  localDW->Subsystem1_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S115>/Subsystem1'
 *    '<S177>/Subsystem1'
 */
void Main_Firmware_Subsystem1(RT_MODEL_Main_Firmware_T * const Main_Firmware_M,
  uint16_T rtu_Enable, const real_T rtu_alpha_beta[2], real_T rtu_wt, real_T
  *rty_dq, real_T *rty_dq_e, DW_Subsystem1_Main_Firmware_T *localDW)
{
  real_T tmp;
  real_T tmp_0;

  /* Outputs for Enabled SubSystem: '<S115>/Subsystem1' incorporates:
   *  EnablePort: '<S120>/Enable'
   */
  if (rtmIsMajorTimeStep(Main_Firmware_M) && rtsiIsModeUpdateTimeStep
      (&Main_Firmware_M->solverInfo)) {
    if (rtu_Enable > 0U) {
      localDW->Subsystem1_MODE = true;
    } else if (localDW->Subsystem1_MODE) {
      Main_Firmwar_Subsystem1_Disable(localDW);
    }
  }

  if (localDW->Subsystem1_MODE) {
    /* Fcn: '<S120>/Fcn' incorporates:
     *  Fcn: '<S120>/Fcn1'
     */
    tmp = sin(rtu_wt);
    tmp_0 = cos(rtu_wt);
    *rty_dq = rtu_alpha_beta[0] * tmp_0 + rtu_alpha_beta[1] * tmp;

    /* Fcn: '<S120>/Fcn1' */
    *rty_dq_e = -rtu_alpha_beta[0] * tmp + rtu_alpha_beta[1] * tmp_0;
    if (rtsiIsModeUpdateTimeStep(&Main_Firmware_M->solverInfo)) {
      srUpdateBC(localDW->Subsystem1_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S115>/Subsystem1' */
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
    real_T rtb_Gain_c[3];
    real_T rtb_Gain4_k;
    real_T rtb_Id_err;
    real_T rtb_Iq_error;
    real_T rtb_Product1_p;
    real_T rtb_Sum1_d_tmp;
    real_T rtb_Sum1_j;
    real_T *lastU;
    int16_T i;
    boolean_T tmp;

    /* Reset subsysRan breadcrumbs */
    srClearBC(Main_Firmware_DW.Subsystempi2delay.Subsystempi2delay_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Main_Firmware_DW.Subsystem1.Subsystem1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Main_Firmware_DW.Subsystempi2delay_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Main_Firmware_DW.Subsystem1_SubsysRanBC);

    /* Outputs for Enabled SubSystem: '<S184>/Subsystem1' incorporates:
     *  EnablePort: '<S188>/Enable'
     */
    tmp = rtmIsMajorTimeStep(Main_Firmware_M);

    /* End of Outputs for SubSystem: '<S184>/Subsystem1' */
    if (tmp) {
      /* Delay: '<S1>/Sampling Delay' */
      rtb_Id_err = Main_Firmware_DW.SamplingDelay_DSTATE[0];

      /* Saturate: '<S1>/Saturation' */
      if (rtb_Id_err > Main_Firmware_P.Saturation_UpperSat) {
        rtb_Id_err = Main_Firmware_P.Saturation_UpperSat;
      } else if (rtb_Id_err < Main_Firmware_P.Saturation_LowerSat) {
        rtb_Id_err = Main_Firmware_P.Saturation_LowerSat;
      }

      /* Gain: '<S2>/Gain' incorporates:
       *  Saturate: '<S1>/Saturation'
       */
      rtb_Gain_c[0] = Main_Firmware_P.Gain_Gain * rtb_Id_err;

      /* Delay: '<S1>/Sampling Delay' */
      rtb_Id_err = Main_Firmware_DW.SamplingDelay_DSTATE[1];

      /* Saturate: '<S1>/Saturation' */
      if (rtb_Id_err > Main_Firmware_P.Saturation_UpperSat) {
        rtb_Id_err = Main_Firmware_P.Saturation_UpperSat;
      } else if (rtb_Id_err < Main_Firmware_P.Saturation_LowerSat) {
        rtb_Id_err = Main_Firmware_P.Saturation_LowerSat;
      }

      /* Gain: '<S2>/Gain' incorporates:
       *  Saturate: '<S1>/Saturation'
       */
      rtb_Gain_c[1] = Main_Firmware_P.Gain_Gain * rtb_Id_err;

      /* Delay: '<S1>/Sampling Delay' */
      rtb_Id_err = Main_Firmware_DW.SamplingDelay_DSTATE[2];

      /* Saturate: '<S1>/Saturation' */
      if (rtb_Id_err > Main_Firmware_P.Saturation_UpperSat) {
        rtb_Id_err = Main_Firmware_P.Saturation_UpperSat;
      } else if (rtb_Id_err < Main_Firmware_P.Saturation_LowerSat) {
        rtb_Id_err = Main_Firmware_P.Saturation_LowerSat;
      }

      /* Gain: '<S2>/Gain' incorporates:
       *  Saturate: '<S1>/Saturation'
       */
      rtb_Gain_c[2] = Main_Firmware_P.Gain_Gain * rtb_Id_err;

      /* S-Function (c2802xpwm): '<S2>/A' */
      uint16_T tbprdValue1Outputs = (EPwm1Regs.TBPRD + 1);

      /*-- Update CMPA value for ePWM1 --*/
      {
        EPwm1Regs.CMPA.bit.CMPA = (uint16_T)((uint32_T)(EPwm1Regs.TBPRD + 1) *
          rtb_Gain_c[0] * 0.01);
      }

      /* S-Function (c2802xpwm): '<S2>/B' */
      uint16_T tbprdValue4Outputs = (EPwm4Regs.TBPRD + 1);

      /*-- Update CMPA value for ePWM4 --*/
      {
        EPwm4Regs.CMPA.bit.CMPA = (uint16_T)((uint32_T)(EPwm4Regs.TBPRD + 1) *
          rtb_Gain_c[1] * 0.01);
      }

      /* S-Function (c2802xpwm): '<S2>/C' */
      uint16_T tbprdValue2Outputs = (EPwm2Regs.TBPRD + 1);

      /*-- Update CMPA value for ePWM2 --*/
      {
        EPwm2Regs.CMPA.bit.CMPA = (uint16_T)((uint32_T)(EPwm2Regs.TBPRD + 1) *
          rtb_Gain_c[2] * 0.01);
      }

      /* S-Function (c280xgpio_do): '<S2>/Digital Output1' incorporates:
       *  Constant: '<S2>/Constant'
       */
      {
        if (Main_Firmware_P.Constant_Value) {
          GpioDataRegs.GPASET.bit.GPIO31 = 1U;
        } else {
          GpioDataRegs.GPACLEAR.bit.GPIO31 = 1U;
        }
      }

      /* DiscretePulseGenerator: '<S2>/LED Heartbeat' */
      Main_Firmware_B.LEDHeartbeat = (Main_Firmware_DW.clockTickCounter <
        Main_Firmware_P.LEDHeartbeat_Duty) && (Main_Firmware_DW.clockTickCounter
        >= 0L) ? Main_Firmware_P.LEDHeartbeat_Amp : 0.0;

      /* DiscretePulseGenerator: '<S2>/LED Heartbeat' */
      if (Main_Firmware_DW.clockTickCounter >=
          Main_Firmware_P.LEDHeartbeat_Period - 1.0) {
        Main_Firmware_DW.clockTickCounter = 0L;
      } else {
        Main_Firmware_DW.clockTickCounter++;
      }

      /* S-Function (c280xgpio_do): '<S2>/Digital Output' */
      {
        if (Main_Firmware_B.LEDHeartbeat) {
          GpioDataRegs.GPASET.bit.GPIO23 = 1U;
        } else {
          GpioDataRegs.GPACLEAR.bit.GPIO23 = 1U;
        }
      }
    }

    /* TransferFcn: '<S174>/Transfer Fcn' */
    Main_Firmware_B.TransferFcn = Main_Firmware_P.TransferFcn_C *
      Main_Firmware_X.TransferFcn_CSTATE;

    /* Step: '<Root>/Step1' incorporates:
     *  Step: '<Root>/Step'
     */
    rtb_Iq_error = Main_Firmware_M->Timing.t[0];
    if (rtb_Iq_error < Main_Firmware_P.Step1_Time) {
      Main_Firmware_B.Saturation = Main_Firmware_P.Step1_Y0;
    } else {
      Main_Firmware_B.Saturation = Main_Firmware_P.Step1_YFinal;
    }

    /* Saturate: '<S3>/Saturation' */
    if (Main_Firmware_B.Saturation > Main_Firmware_P.speed_max) {
      /* Step: '<Root>/Step1' incorporates:
       *  Saturate: '<S3>/Saturation'
       */
      Main_Firmware_B.Saturation = Main_Firmware_P.speed_max;
    } else if (Main_Firmware_B.Saturation < -Main_Firmware_P.speed_max) {
      /* Step: '<Root>/Step1' incorporates:
       *  Saturate: '<S3>/Saturation'
       */
      Main_Firmware_B.Saturation = -Main_Firmware_P.speed_max;
    }

    /* End of Saturate: '<S3>/Saturation' */

    /* Integrator: '<S173>/Integrator2' */
    /* Limited  Integrator  */
    if (Main_Firmware_X.Integrator2_CSTATE >=
        Main_Firmware_P.Integrator2_UpperSat) {
      Main_Firmware_X.Integrator2_CSTATE = Main_Firmware_P.Integrator2_UpperSat;
    } else if (Main_Firmware_X.Integrator2_CSTATE <=
               Main_Firmware_P.Integrator2_LowerSat) {
      Main_Firmware_X.Integrator2_CSTATE = Main_Firmware_P.Integrator2_LowerSat;
    }

    /* Sum: '<S4>/Sum' incorporates:
     *  Constant: '<S4>/Constant'
     *  Gain: '<S4>/Gain6'
     *  Integrator: '<S173>/Integrator2'
     */
    Main_Firmware_B.RotorAngle = 1.0 / Main_Firmware_P.ppair *
      Main_Firmware_X.Integrator2_CSTATE + Main_Firmware_P.Encoder_Offset;
    if (tmp) {
      /* SignalConversion generated from: '<Root>/Mux5' */
      Main_Firmware_B.TmpSignalConversionAtTAQSigLogg[0] =
        Main_Firmware_B.TransferFcn;
      Main_Firmware_B.TmpSignalConversionAtTAQSigLogg[1] =
        Main_Firmware_B.Saturation;
      Main_Firmware_B.TmpSignalConversionAtTAQSigLogg[2] =
        Main_Firmware_B.RotorAngle;

      /* RelationalOperator: '<S185>/Compare' incorporates:
       *  Constant: '<S184>/Constant'
       *  Constant: '<S185>/Constant'
       */
      Main_Firmware_B.Compare = (uint16_T)
        (Main_Firmware_P.dq0toAlphaBetaZero_Alignment ==
         Main_Firmware_P.CompareToConstant_const);
    }

    /* Integrator: '<S173>/Integrator' */
    /* Limited  Integrator  */
    if (Main_Firmware_X.Integrator_CSTATE >= Main_Firmware_P.Integrator_UpperSat)
    {
      Main_Firmware_X.Integrator_CSTATE = Main_Firmware_P.Integrator_UpperSat;
    } else if (Main_Firmware_X.Integrator_CSTATE <=
               Main_Firmware_P.Integrator_LowerSat) {
      Main_Firmware_X.Integrator_CSTATE = Main_Firmware_P.Integrator_LowerSat;
    }

    /* Integrator: '<S173>/Integrator1' */
    /* Limited  Integrator  */
    if (Main_Firmware_X.Integrator1_CSTATE >=
        Main_Firmware_P.Integrator1_UpperSat) {
      Main_Firmware_X.Integrator1_CSTATE = Main_Firmware_P.Integrator1_UpperSat;
    } else if (Main_Firmware_X.Integrator1_CSTATE <=
               Main_Firmware_P.Integrator1_LowerSat) {
      Main_Firmware_X.Integrator1_CSTATE = Main_Firmware_P.Integrator1_LowerSat;
    }

    /* Outputs for Enabled SubSystem: '<S184>/Subsystem1' incorporates:
     *  EnablePort: '<S188>/Enable'
     */
    if (tmp && rtsiIsModeUpdateTimeStep(&Main_Firmware_M->solverInfo)) {
      /* RelationalOperator: '<S185>/Compare' */
      Main_Firmware_DW.Subsystem1_MODE = (Main_Firmware_B.Compare > 0U);
    }

    if (Main_Firmware_DW.Subsystem1_MODE) {
      /* Fcn: '<S188>/Fcn' incorporates:
       *  Fcn: '<S188>/Fcn1'
       *  Integrator: '<S173>/Integrator2'
       */
      rtb_Id_err = sin(Main_Firmware_X.Integrator2_CSTATE);
      rtb_Product1_p = cos(Main_Firmware_X.Integrator2_CSTATE);

      /* Fcn: '<S188>/Fcn' incorporates:
       *  Integrator: '<S173>/Integrator'
       *  Integrator: '<S173>/Integrator1'
       */
      Main_Firmware_B.Fcn = Main_Firmware_X.Integrator_CSTATE * rtb_Product1_p -
        Main_Firmware_X.Integrator1_CSTATE * rtb_Id_err;

      /* Fcn: '<S188>/Fcn1' incorporates:
       *  Integrator: '<S173>/Integrator'
       *  Integrator: '<S173>/Integrator1'
       */
      Main_Firmware_B.Fcn1 = Main_Firmware_X.Integrator_CSTATE * rtb_Id_err +
        Main_Firmware_X.Integrator1_CSTATE * rtb_Product1_p;
      if (rtsiIsModeUpdateTimeStep(&Main_Firmware_M->solverInfo)) {
        srUpdateBC(Main_Firmware_DW.Subsystem1_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S184>/Subsystem1' */
    if (tmp) {
      /* Outputs for Enabled SubSystem: '<S184>/Subsystem - pi//2 delay' incorporates:
       *  EnablePort: '<S187>/Enable'
       */
      if (rtsiIsModeUpdateTimeStep(&Main_Firmware_M->solverInfo)) {
        /* RelationalOperator: '<S186>/Compare' incorporates:
         *  Constant: '<S184>/Constant'
         *  Constant: '<S186>/Constant'
         */
        Main_Firmware_DW.Subsystempi2delay_MODE =
          (Main_Firmware_P.dq0toAlphaBetaZero_Alignment ==
           Main_Firmware_P.CompareToConstant1_const);
      }

      /* End of Outputs for SubSystem: '<S184>/Subsystem - pi//2 delay' */
    }

    /* Outputs for Enabled SubSystem: '<S184>/Subsystem - pi//2 delay' incorporates:
     *  EnablePort: '<S187>/Enable'
     */
    if (Main_Firmware_DW.Subsystempi2delay_MODE) {
      /* Fcn: '<S187>/Fcn' incorporates:
       *  Integrator: '<S173>/Integrator'
       *  Integrator: '<S173>/Integrator1'
       *  Integrator: '<S173>/Integrator2'
       */
      Main_Firmware_B.Fcn_g = Main_Firmware_X.Integrator_CSTATE * sin
        (Main_Firmware_X.Integrator2_CSTATE) +
        Main_Firmware_X.Integrator1_CSTATE * cos
        (Main_Firmware_X.Integrator2_CSTATE);

      /* Fcn: '<S187>/Fcn1' incorporates:
       *  Integrator: '<S173>/Integrator'
       *  Integrator: '<S173>/Integrator1'
       *  Integrator: '<S173>/Integrator2'
       */
      Main_Firmware_B.Fcn1_l = -Main_Firmware_X.Integrator_CSTATE * cos
        (Main_Firmware_X.Integrator2_CSTATE) +
        Main_Firmware_X.Integrator1_CSTATE * sin
        (Main_Firmware_X.Integrator2_CSTATE);
      if (rtsiIsModeUpdateTimeStep(&Main_Firmware_M->solverInfo)) {
        srUpdateBC(Main_Firmware_DW.Subsystempi2delay_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S184>/Subsystem - pi//2 delay' */

    /* Switch: '<S184>/Switch' incorporates:
     *  RelationalOperator: '<S185>/Compare'
     */
    if (Main_Firmware_B.Compare != 0U) {
      /* SignalConversion generated from: '<S183>/Gain3' */
      rtb_Id_err = Main_Firmware_B.Fcn;
      rtb_Product1_p = Main_Firmware_B.Fcn1;
    } else {
      /* SignalConversion generated from: '<S183>/Gain3' */
      rtb_Id_err = Main_Firmware_B.Fcn_g;
      rtb_Product1_p = Main_Firmware_B.Fcn1_l;
    }

    /* End of Switch: '<S184>/Switch' */
    for (i = 0; i < 3; i++) {
      /* Gain: '<S183>/Gain3' incorporates:
       *  Constant: '<S4>/Constant3'
       */
      Main_Firmware_B.Gain3[i] = (Main_Firmware_P.Gain3_Gain[i + 3] *
        rtb_Product1_p + Main_Firmware_P.Gain3_Gain[i] * rtb_Id_err) +
        Main_Firmware_P.Gain3_Gain[i + 6] * Main_Firmware_P.Constant3_Value;
    }

    /* Gain: '<S3>/Gain2' incorporates:
     *  Constant: '<S3>/Const'
     *  Sum: '<S3>/Subtract'
     */
    Main_Firmware_B.Electricalspeed = (Main_Firmware_B.RotorAngle -
      Main_Firmware_P.Encoder_Offset) * Main_Firmware_P.ppair;

    /* Derivative: '<S3>/Derivative' */
    rtb_Product1_p = Main_Firmware_M->Timing.t[0];
    if ((Main_Firmware_DW.TimeStampA >= rtb_Product1_p) &&
        (Main_Firmware_DW.TimeStampB >= rtb_Product1_p)) {
      rtb_Product1_p = 0.0;
    } else {
      rtb_Id_err = Main_Firmware_DW.TimeStampA;
      lastU = &Main_Firmware_DW.LastUAtTimeA;
      if (Main_Firmware_DW.TimeStampA < Main_Firmware_DW.TimeStampB) {
        if (Main_Firmware_DW.TimeStampB < rtb_Product1_p) {
          rtb_Id_err = Main_Firmware_DW.TimeStampB;
          lastU = &Main_Firmware_DW.LastUAtTimeB;
        }
      } else if (Main_Firmware_DW.TimeStampA >= rtb_Product1_p) {
        rtb_Id_err = Main_Firmware_DW.TimeStampB;
        lastU = &Main_Firmware_DW.LastUAtTimeB;
      }

      rtb_Product1_p = (Main_Firmware_B.Electricalspeed - *lastU) /
        (rtb_Product1_p - rtb_Id_err);
    }

    /* End of Derivative: '<S3>/Derivative' */

    /* Sum: '<S3>/Sum6' incorporates:
     *  Gain: '<S3>/Gain7'
     */
    rtb_Id_err = Main_Firmware_P.ppair * Main_Firmware_B.Saturation -
      rtb_Product1_p;

    /* Gain: '<S158>/Filter Coefficient' incorporates:
     *  Gain: '<S148>/Derivative Gain'
     *  Integrator: '<S150>/Filter'
     *  Sum: '<S150>/SumD'
     */
    Main_Firmware_B.FilterCoefficient = (Main_Firmware_P.SpeedPD_D * rtb_Id_err
      - Main_Firmware_X.Filter_CSTATE) * Main_Firmware_P.SpeedPD_N;

    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    if (Main_Firmware_P.Constant2_Value > Main_Firmware_P.Switch_Threshold) {
      /* Step: '<Root>/Step' */
      if (rtb_Iq_error < Main_Firmware_P.Step_Time) {
        /* Sum: '<S164>/Sum' incorporates:
         *  Switch: '<S3>/Switch'
         */
        Main_Firmware_B.Te = Main_Firmware_P.Step_Y0;
      } else {
        /* Sum: '<S164>/Sum' incorporates:
         *  Switch: '<S3>/Switch'
         */
        Main_Firmware_B.Te = Main_Firmware_P.Step_YFinal;
      }
    } else {
      /* Sum: '<S164>/Sum' incorporates:
       *  Gain: '<S160>/Proportional Gain'
       */
      Main_Firmware_B.Te = Main_Firmware_P.SpeedPD_P * rtb_Id_err +
        Main_Firmware_B.FilterCoefficient;

      /* Saturate: '<S162>/Saturation' */
      if (Main_Firmware_B.Te > Main_Firmware_P.Torque_max) {
        /* Sum: '<S164>/Sum' incorporates:
         *  Switch: '<S3>/Switch'
         */
        Main_Firmware_B.Te = Main_Firmware_P.Torque_max;
      } else if (Main_Firmware_B.Te < -Main_Firmware_P.Torque_max) {
        /* Sum: '<S164>/Sum' incorporates:
         *  Switch: '<S3>/Switch'
         */
        Main_Firmware_B.Te = -Main_Firmware_P.Torque_max;
      }

      /* End of Saturate: '<S162>/Saturation' */
    }

    /* End of Switch: '<S3>/Switch' */

    /* Gain: '<S173>/Gain5' incorporates:
     *  Integrator: '<S173>/Integrator1'
     */
    Main_Firmware_B.Gain5 = 1.5 * Main_Firmware_P.ppair * Main_Firmware_P.lambda
      * Main_Firmware_X.Integrator1_CSTATE;
    if (tmp) {
      /* SignalConversion generated from: '<Root>/Mux4' */
      Main_Firmware_B.TmpSignalConversionAtTAQSigLo_m[0] = Main_Firmware_B.Te;
      Main_Firmware_B.TmpSignalConversionAtTAQSigLo_m[1] = Main_Firmware_B.Gain5;
    }

    /* Gain: '<S116>/Gain3' */
    rtb_Id_err = Main_Firmware_B.Gain3[1];
    rtb_Iq_error = Main_Firmware_B.Gain3[0];
    rtb_Gain4_k = Main_Firmware_B.Gain3[2];
    for (i = 0; i < 3; i++) {
      /* Gain: '<S116>/Gain1' incorporates:
       *  Gain: '<S116>/Gain3'
       */
      Main_Firmware_B.Gain1[i] = ((Main_Firmware_P.Gain3_Gain_k[i + 3] *
        rtb_Id_err + Main_Firmware_P.Gain3_Gain_k[i] * rtb_Iq_error) +
        Main_Firmware_P.Gain3_Gain_k[i + 6] * rtb_Gain4_k) *
        Main_Firmware_P.Gain1_Gain;
    }

    /* End of Gain: '<S116>/Gain3' */
    if (tmp) {
      /* RelationalOperator: '<S117>/Compare' incorporates:
       *  Constant: '<S115>/Constant'
       *  Constant: '<S117>/Constant'
       */
      Main_Firmware_B.Compare_o = (uint16_T)
        (Main_Firmware_P.AlphaBetaZerotodq0_Alignment ==
         Main_Firmware_P.CompareToConstant_const_o);
    }

    /* Outputs for Enabled SubSystem: '<S115>/Subsystem1' */
    /* Gain: '<S116>/Gain1' */
    Main_Firmware_Subsystem1(Main_Firmware_M, Main_Firmware_B.Compare_o,
      &Main_Firmware_B.Gain1[0], Main_Firmware_B.Electricalspeed,
      &Main_Firmware_B.Fcn_k, &Main_Firmware_B.Fcn1_n,
      &Main_Firmware_DW.Subsystem1);

    /* End of Outputs for SubSystem: '<S115>/Subsystem1' */
    if (tmp) {
      /* RelationalOperator: '<S118>/Compare' incorporates:
       *  Constant: '<S115>/Constant'
       *  Constant: '<S118>/Constant'
       */
      Main_Firmware_B.Compare_n = (uint16_T)
        (Main_Firmware_P.AlphaBetaZerotodq0_Alignment ==
         Main_Firmware_P.CompareToConstant1_const_k);
    }

    /* Outputs for Enabled SubSystem: '<S115>/Subsystem - pi//2 delay' */
    /* Gain: '<S116>/Gain1' */
    Main_Firmware_Subsystempi2delay(Main_Firmware_M, Main_Firmware_B.Compare_n,
      &Main_Firmware_B.Gain1[0], Main_Firmware_B.Electricalspeed,
      &Main_Firmware_B.Fcn_jc, &Main_Firmware_B.Fcn1_e,
      &Main_Firmware_DW.Subsystempi2delay);

    /* End of Outputs for SubSystem: '<S115>/Subsystem - pi//2 delay' */

    /* Switch: '<S115>/Switch' incorporates:
     *  RelationalOperator: '<S117>/Compare'
     */
    if (Main_Firmware_B.Compare_o != 0U) {
      /* Switch: '<S115>/Switch' */
      Main_Firmware_B.Switch[0] = Main_Firmware_B.Fcn_k;
      Main_Firmware_B.Switch[1] = Main_Firmware_B.Fcn1_n;
    } else {
      /* Switch: '<S115>/Switch' */
      Main_Firmware_B.Switch[0] = Main_Firmware_B.Fcn_jc;
      Main_Firmware_B.Switch[1] = Main_Firmware_B.Fcn1_e;
    }

    /* End of Switch: '<S115>/Switch' */
    if (tmp) {
      /* SignalConversion generated from: '<S3>/Park Transform' */
      Main_Firmware_B.TmpSignalConversionAtTAQSigLo_j[0] =
        Main_Firmware_B.Switch[0];
      Main_Firmware_B.TmpSignalConversionAtTAQSigLo_j[1] =
        Main_Firmware_B.Switch[1];
      Main_Firmware_B.TmpSignalConversionAtTAQSigLo_j[2] =
        Main_Firmware_B.Gain1[2];
    }

    /* Sum: '<S3>/Sum4' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    rtb_Id_err = Main_Firmware_P.Constant1_Value - Main_Firmware_B.Switch[0];

    /* Integrator: '<S97>/Integrator' */
    /* Limited  Integrator  */
    if (Main_Firmware_X.Integrator_CSTATE_h >= Main_Firmware_P.Voltage_max) {
      Main_Firmware_X.Integrator_CSTATE_h = Main_Firmware_P.Voltage_max;
    } else if (Main_Firmware_X.Integrator_CSTATE_h <=
               -Main_Firmware_P.Voltage_max) {
      Main_Firmware_X.Integrator_CSTATE_h = -Main_Firmware_P.Voltage_max;
    }

    /* Sum: '<S106>/Sum' incorporates:
     *  Gain: '<S102>/Proportional Gain'
     *  Integrator: '<S97>/Integrator'
     */
    rtb_Sum1_j = Main_Firmware_P.I_dqPID3_P * rtb_Id_err +
      Main_Firmware_X.Integrator_CSTATE_h;

    /* Saturate: '<S104>/Saturation' */
    if (rtb_Sum1_j > Main_Firmware_P.Voltage_max) {
      rtb_Sum1_j = Main_Firmware_P.Voltage_max;
    } else if (rtb_Sum1_j < -Main_Firmware_P.Voltage_max) {
      rtb_Sum1_j = -Main_Firmware_P.Voltage_max;
    }

    /* Sum: '<S3>/Sum1' incorporates:
     *  Gain: '<S5>/Gain3'
     *  Gain: '<S5>/Gain4'
     *  Product: '<S5>/Product1'
     *  Saturate: '<S104>/Saturation'
     *  Sum: '<S5>/Add1'
     */
    rtb_Gain4_k = (Main_Firmware_P.Ld * rtb_Product1_p * Main_Firmware_B.Switch
                   [0] + Main_Firmware_P.lambda * rtb_Product1_p) + rtb_Sum1_j;

    /* Saturate: '<S3>/Limiter 1' */
    if (rtb_Gain4_k > Main_Firmware_P.Voltage_max) {
      rtb_Gain4_k = Main_Firmware_P.Voltage_max;
    } else if (rtb_Gain4_k < Main_Firmware_P.Limiter1_LowerSat) {
      rtb_Gain4_k = Main_Firmware_P.Limiter1_LowerSat;
    }

    /* End of Saturate: '<S3>/Limiter 1' */

    /* Gain: '<S3>/Gain6' incorporates:
     *  Gain: '<S173>/Gain4'
     */
    rtb_Sum1_d_tmp = Main_Firmware_P.ppair * Main_Firmware_P.lambda;
    rtb_Sum1_j = 2.0 / (rtb_Sum1_d_tmp * 3.0) * Main_Firmware_B.Te;

    /* Saturate: '<S3>/Limiter1' */
    if (rtb_Sum1_j > Main_Firmware_P.Current_max) {
      rtb_Sum1_j = Main_Firmware_P.Current_max;
    } else if (rtb_Sum1_j < -Main_Firmware_P.Current_max) {
      rtb_Sum1_j = -Main_Firmware_P.Current_max;
    }

    /* Sum: '<S3>/Sum3' incorporates:
     *  Saturate: '<S3>/Limiter1'
     */
    rtb_Iq_error = rtb_Sum1_j - Main_Firmware_B.Switch[1];

    /* Integrator: '<S45>/Integrator' */
    /* Limited  Integrator  */
    if (Main_Firmware_X.Integrator_CSTATE_hk >= Main_Firmware_P.Voltage_max) {
      Main_Firmware_X.Integrator_CSTATE_hk = Main_Firmware_P.Voltage_max;
    } else if (Main_Firmware_X.Integrator_CSTATE_hk <=
               -Main_Firmware_P.Voltage_max) {
      Main_Firmware_X.Integrator_CSTATE_hk = -Main_Firmware_P.Voltage_max;
    }

    /* Sum: '<S54>/Sum' incorporates:
     *  Gain: '<S50>/Proportional Gain'
     *  Integrator: '<S45>/Integrator'
     */
    rtb_Sum1_j = Main_Firmware_P.I_dqPID_P * rtb_Iq_error +
      Main_Firmware_X.Integrator_CSTATE_hk;

    /* Saturate: '<S52>/Saturation' */
    if (rtb_Sum1_j > Main_Firmware_P.Voltage_max) {
      rtb_Sum1_j = Main_Firmware_P.Voltage_max;
    } else if (rtb_Sum1_j < -Main_Firmware_P.Voltage_max) {
      rtb_Sum1_j = -Main_Firmware_P.Voltage_max;
    }

    /* Sum: '<S3>/Sum7' incorporates:
     *  Gain: '<S5>/Gain1'
     *  Product: '<S5>/Product'
     *  Saturate: '<S52>/Saturation'
     */
    rtb_Sum1_j += -Main_Firmware_P.Lq * rtb_Product1_p * Main_Firmware_B.Switch
      [1];

    /* Saturate: '<S3>/Limiter' */
    if (rtb_Sum1_j > Main_Firmware_P.Voltage_max) {
      rtb_Sum1_j = Main_Firmware_P.Voltage_max;
    } else if (rtb_Sum1_j < Main_Firmware_P.Limiter_LowerSat) {
      rtb_Sum1_j = Main_Firmware_P.Limiter_LowerSat;
    }

    /* End of Saturate: '<S3>/Limiter' */

    /* Sum: '<S8>/Add' incorporates:
     *  Product: '<S8>/Product'
     *  Product: '<S8>/Product1'
     *  Trigonometry: '<S8>/Trigonometric Function'
     *  Trigonometry: '<S8>/Trigonometric Function1'
     */
    Main_Firmware_B.a = rtb_Gain4_k * cos(Main_Firmware_B.Electricalspeed) - sin
      (Main_Firmware_B.Electricalspeed) * rtb_Sum1_j;

    /* Bias: '<S8>/Bias' */
    rtb_Product1_p = Main_Firmware_B.Electricalspeed + Main_Firmware_P.Bias_Bias;

    /* Sum: '<S8>/Add1' incorporates:
     *  Product: '<S8>/Product2'
     *  Product: '<S8>/Product3'
     *  Trigonometry: '<S8>/Trigonometric Function2'
     *  Trigonometry: '<S8>/Trigonometric Function3'
     */
    Main_Firmware_B.b = rtb_Gain4_k * cos(rtb_Product1_p) - sin(rtb_Product1_p) *
      rtb_Sum1_j;

    /* Bias: '<S8>/Bias1' */
    rtb_Product1_p = Main_Firmware_B.Electricalspeed +
      Main_Firmware_P.Bias1_Bias;

    /* Sum: '<S8>/Add2' incorporates:
     *  Product: '<S8>/Product4'
     *  Product: '<S8>/Product5'
     *  Trigonometry: '<S8>/Trigonometric Function4'
     *  Trigonometry: '<S8>/Trigonometric Function5'
     */
    Main_Firmware_B.c = rtb_Gain4_k * cos(rtb_Product1_p) - sin(rtb_Product1_p) *
      rtb_Sum1_j;

    /* SignalConversion generated from: '<S178>/Gain3' */
    Main_Firmware_B.Gain5_k[0] = Main_Firmware_B.a;
    Main_Firmware_B.Gain5_k[1] = Main_Firmware_B.b;
    Main_Firmware_B.Gain5_k[2] = Main_Firmware_B.c;

    /* Gain: '<S178>/Gain3' */
    rtb_Product1_p = Main_Firmware_B.Gain5_k[1];
    rtb_Gain4_k = Main_Firmware_B.Gain5_k[0];
    rtb_Sum1_j = Main_Firmware_B.Gain5_k[2];
    for (i = 0; i < 3; i++) {
      /* Gain: '<S178>/Gain1' incorporates:
       *  Gain: '<S178>/Gain3'
       */
      rtb_Gain_c[i] = ((Main_Firmware_P.Gain3_Gain_g[i + 3] * rtb_Product1_p +
                        Main_Firmware_P.Gain3_Gain_g[i] * rtb_Gain4_k) +
                       Main_Firmware_P.Gain3_Gain_g[i + 6] * rtb_Sum1_j) *
        Main_Firmware_P.Gain1_Gain_e;
    }

    /* End of Gain: '<S178>/Gain3' */
    if (tmp) {
      /* RelationalOperator: '<S179>/Compare' incorporates:
       *  Constant: '<S177>/Constant'
       *  Constant: '<S179>/Constant'
       */
      Main_Firmware_B.Compare_g = (uint16_T)
        (Main_Firmware_P.AlphaBetaZerotodq0_Alignment_n ==
         Main_Firmware_P.CompareToConstant_const_i);
    }

    /* Outputs for Enabled SubSystem: '<S177>/Subsystem1' */
    /* Gain: '<S178>/Gain1' incorporates:
     *  Integrator: '<S173>/Integrator2'
     */
    Main_Firmware_Subsystem1(Main_Firmware_M, Main_Firmware_B.Compare_g,
      &rtb_Gain_c[0], Main_Firmware_X.Integrator2_CSTATE, &Main_Firmware_B.Fcn_b,
      &Main_Firmware_B.Fcn1_d, &Main_Firmware_DW.Subsystem1_c);

    /* End of Outputs for SubSystem: '<S177>/Subsystem1' */
    if (tmp) {
      /* RelationalOperator: '<S180>/Compare' incorporates:
       *  Constant: '<S177>/Constant'
       *  Constant: '<S180>/Constant'
       */
      Main_Firmware_B.Compare_b = (uint16_T)
        (Main_Firmware_P.AlphaBetaZerotodq0_Alignment_n ==
         Main_Firmware_P.CompareToConstant1_const_m);
    }

    /* Outputs for Enabled SubSystem: '<S177>/Subsystem - pi//2 delay' */
    /* Gain: '<S178>/Gain1' incorporates:
     *  Integrator: '<S173>/Integrator2'
     */
    Main_Firmware_Subsystempi2delay(Main_Firmware_M, Main_Firmware_B.Compare_b,
      &rtb_Gain_c[0], Main_Firmware_X.Integrator2_CSTATE, &Main_Firmware_B.Fcn_j,
      &Main_Firmware_B.Fcn1_k, &Main_Firmware_DW.Subsystempi2delay_o);

    /* End of Outputs for SubSystem: '<S177>/Subsystem - pi//2 delay' */

    /* Gain: '<S1>/Gain5' */
    rtb_Product1_p = 1.0 / Main_Firmware_P.Voltage_max;

    /* Gain: '<S1>/Gain5' incorporates:
     *  SignalConversion generated from: '<S178>/Gain3'
     */
    Main_Firmware_B.Gain5_k[0] *= rtb_Product1_p;
    Main_Firmware_B.Gain5_k[1] *= rtb_Product1_p;
    Main_Firmware_B.Gain5_k[2] *= rtb_Product1_p;

    /* Trigonometry: '<Root>/Trigonometric Function' */
    Main_Firmware_B.Sine = sin(Main_Firmware_B.RotorAngle);

    /* Trigonometry: '<Root>/Trigonometric Function1' */
    Main_Firmware_B.Cos = cos(Main_Firmware_B.RotorAngle);
    if (tmp) {
      /* SignalConversion generated from: '<Root>/From4' */
      Main_Firmware_B.TmpSignalConversionAtTAQSigLo_g[0] = Main_Firmware_B.a;
      Main_Firmware_B.TmpSignalConversionAtTAQSigLo_g[1] = Main_Firmware_B.b;
      Main_Firmware_B.TmpSignalConversionAtTAQSigLo_g[2] = Main_Firmware_B.c;

      /* SignalConversion generated from: '<Root>/Mux' */
      Main_Firmware_B.TmpSignalConversionAtTAQSigLo_i[0] = Main_Firmware_B.Sine;
      Main_Firmware_B.TmpSignalConversionAtTAQSigLo_i[1] = Main_Firmware_B.Cos;
    }

    /* Switch: '<S177>/Switch' incorporates:
     *  RelationalOperator: '<S179>/Compare'
     */
    if (Main_Firmware_B.Compare_g != 0U) {
      rtb_Gain4_k = Main_Firmware_B.Fcn_b;
      rtb_Product1_p = Main_Firmware_B.Fcn1_d;
    } else {
      rtb_Gain4_k = Main_Firmware_B.Fcn_j;
      rtb_Product1_p = Main_Firmware_B.Fcn1_k;
    }

    /* End of Switch: '<S177>/Switch' */
    if (tmp) {
    }

    /* Gain: '<S173>/Gain' incorporates:
     *  Constant: '<S173>/Constant'
     *  Gain: '<S173>/Gain1'
     *  Integrator: '<S173>/Integrator'
     *  Integrator: '<S173>/Integrator1'
     *  Product: '<S173>/Product'
     *  Sum: '<S173>/Sum'
     */
    Main_Firmware_B.Gain = (Main_Firmware_P.Lq * Main_Firmware_P.ppair *
      Main_Firmware_B.TransferFcn * Main_Firmware_X.Integrator1_CSTATE +
      (rtb_Gain4_k - Main_Firmware_P.Rs * Main_Firmware_X.Integrator_CSTATE)) *
      (1.0 / Main_Firmware_P.Ld);

    /* Gain: '<S173>/Gain2' incorporates:
     *  Constant: '<S173>/Constant1'
     *  Gain: '<S173>/Gain3'
     *  Gain: '<S173>/Gain4'
     *  Integrator: '<S173>/Integrator'
     *  Integrator: '<S173>/Integrator1'
     *  Product: '<S173>/Product1'
     *  Sum: '<S173>/Sum1'
     */
    Main_Firmware_B.Gain2 = (((rtb_Product1_p - Main_Firmware_P.Rs *
      Main_Firmware_X.Integrator1_CSTATE) - Main_Firmware_P.Ld *
      Main_Firmware_P.ppair * Main_Firmware_B.TransferFcn *
      Main_Firmware_X.Integrator_CSTATE) - rtb_Sum1_d_tmp *
      Main_Firmware_B.TransferFcn) * (1.0 / Main_Firmware_P.Lq);

    /* Gain: '<S42>/Integral Gain' */
    Main_Firmware_B.IntegralGain = Main_Firmware_P.I_dqPID_I * rtb_Iq_error;

    /* Gain: '<S94>/Integral Gain' */
    Main_Firmware_B.IntegralGain_a = Main_Firmware_P.I_dqPID3_I * rtb_Id_err;

    /* Signum: '<S174>/Sign' */
    if (rtIsNaN(Main_Firmware_B.TransferFcn)) {
      rtb_Product1_p = (rtNaN);
    } else if (Main_Firmware_B.TransferFcn < 0.0) {
      rtb_Product1_p = -1.0;
    } else {
      rtb_Product1_p = (Main_Firmware_B.TransferFcn > 0.0);
    }

    /* Sum: '<S174>/Subtract' incorporates:
     *  Constant: '<S174>/Constant1'
     *  Constant: '<S174>/Constant2'
     *  Gain: '<S174>/Gain'
     *  Math: '<S174>/Square'
     *  Product: '<S174>/Product'
     *  Product: '<S174>/Product2'
     *  Signum: '<S174>/Sign'
     *  Sum: '<S174>/Sum1'
     */
    Main_Firmware_B.Subtract = Main_Firmware_B.Gain5 - (0.5 *
      Main_Firmware_P.rho * Main_Firmware_P.C_d * Main_Firmware_P.A_f *
      0.04129024 * (Main_Firmware_B.TransferFcn * Main_Firmware_B.TransferFcn) *
      Main_Firmware_P.Gain_Gain_m + Main_Firmware_P.m * Main_Firmware_P.g *
      Main_Firmware_P.C_rr * rtb_Product1_p);

    /* Gain: '<S173>/Gain6' */
    Main_Firmware_B.Gain6 = Main_Firmware_P.ppair * Main_Firmware_B.TransferFcn;
  }

  if (rtmIsMajorTimeStep(Main_Firmware_M)) {
    real_T *lastU;
    if (rtmIsMajorTimeStep(Main_Firmware_M)) {
      /* Update for Delay: '<S1>/Sampling Delay' */
      Main_Firmware_DW.SamplingDelay_DSTATE[0] = Main_Firmware_B.Gain5_k[0];
      Main_Firmware_DW.SamplingDelay_DSTATE[1] = Main_Firmware_B.Gain5_k[1];
      Main_Firmware_DW.SamplingDelay_DSTATE[2] = Main_Firmware_B.Gain5_k[2];
    }

    /* Update for Derivative: '<S3>/Derivative' */
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

    *lastU = Main_Firmware_B.Electricalspeed;

    /* End of Update for Derivative: '<S3>/Derivative' */
    if (rtmIsMajorTimeStep(Main_Firmware_M)) {/* Sample time: [2.0E-5s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
        (((Main_Firmware_M->Timing.clockTick1+
           Main_Firmware_M->Timing.clockTickH1* 4294967296.0) * 1) + 0);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1, extmodeTime);
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
      /* Update absolute timer for sample time: [2.0E-5s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 2.0E-5, which is the step size
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
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Main_Firmware_derivatives(void)
{
  XDot_Main_Firmware_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_Main_Firmware_T *) Main_Firmware_M->derivs);

  /* Derivatives for TransferFcn: '<S174>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = Main_Firmware_P.TransferFcn_A *
    Main_Firmware_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += Main_Firmware_B.Subtract;

  /* Derivatives for Integrator: '<S173>/Integrator2' */
  lsat = (Main_Firmware_X.Integrator2_CSTATE <=
          Main_Firmware_P.Integrator2_LowerSat);
  usat = (Main_Firmware_X.Integrator2_CSTATE >=
          Main_Firmware_P.Integrator2_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (Main_Firmware_B.Gain6 > 0.0)) || (usat &&
       (Main_Firmware_B.Gain6 < 0.0))) {
    _rtXdot->Integrator2_CSTATE = Main_Firmware_B.Gain6;
  } else {
    /* in saturation */
    _rtXdot->Integrator2_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S173>/Integrator2' */

  /* Derivatives for Integrator: '<S173>/Integrator' */
  lsat = (Main_Firmware_X.Integrator_CSTATE <=
          Main_Firmware_P.Integrator_LowerSat);
  usat = (Main_Firmware_X.Integrator_CSTATE >=
          Main_Firmware_P.Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (Main_Firmware_B.Gain > 0.0)) || (usat &&
       (Main_Firmware_B.Gain < 0.0))) {
    _rtXdot->Integrator_CSTATE = Main_Firmware_B.Gain;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S173>/Integrator' */

  /* Derivatives for Integrator: '<S173>/Integrator1' */
  lsat = (Main_Firmware_X.Integrator1_CSTATE <=
          Main_Firmware_P.Integrator1_LowerSat);
  usat = (Main_Firmware_X.Integrator1_CSTATE >=
          Main_Firmware_P.Integrator1_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (Main_Firmware_B.Gain2 > 0.0)) || (usat &&
       (Main_Firmware_B.Gain2 < 0.0))) {
    _rtXdot->Integrator1_CSTATE = Main_Firmware_B.Gain2;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S173>/Integrator1' */

  /* Derivatives for Integrator: '<S150>/Filter' */
  _rtXdot->Filter_CSTATE = Main_Firmware_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S97>/Integrator' */
  lsat = (Main_Firmware_X.Integrator_CSTATE_h <= -Main_Firmware_P.Voltage_max);
  usat = (Main_Firmware_X.Integrator_CSTATE_h >= Main_Firmware_P.Voltage_max);
  if (((!lsat) && (!usat)) || (lsat && (Main_Firmware_B.IntegralGain_a > 0.0)) ||
      (usat && (Main_Firmware_B.IntegralGain_a < 0.0))) {
    _rtXdot->Integrator_CSTATE_h = Main_Firmware_B.IntegralGain_a;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE_h = 0.0;
  }

  /* End of Derivatives for Integrator: '<S97>/Integrator' */

  /* Derivatives for Integrator: '<S45>/Integrator' */
  lsat = (Main_Firmware_X.Integrator_CSTATE_hk <= -Main_Firmware_P.Voltage_max);
  usat = (Main_Firmware_X.Integrator_CSTATE_hk >= Main_Firmware_P.Voltage_max);
  if (((!lsat) && (!usat)) || (lsat && (Main_Firmware_B.IntegralGain > 0.0)) ||
      (usat && (Main_Firmware_B.IntegralGain < 0.0))) {
    _rtXdot->Integrator_CSTATE_hk = Main_Firmware_B.IntegralGain;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE_hk = 0.0;
  }

  /* End of Derivatives for Integrator: '<S45>/Integrator' */
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
  Main_Firmware_M->Timing.stepSize0 = 2.0E-5;

  /* External mode info */
  Main_Firmware_M->Sizes.checksums[0] = (1887059552U);
  Main_Firmware_M->Sizes.checksums[1] = (2392219314U);
  Main_Firmware_M->Sizes.checksums[2] = (2474872685U);
  Main_Firmware_M->Sizes.checksums[3] = (1430349666U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    Main_Firmware_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &Main_Firmware_DW.Subsystempi2delay.Subsystempi2delay_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &Main_Firmware_DW.Subsystem1.Subsystem1_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &Main_Firmware_DW.Subsystempi2delay_o.Subsystempi2delay_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &Main_Firmware_DW.Subsystem1_c.Subsystem1_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &Main_Firmware_DW.Subsystempi2delay_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&Main_Firmware_DW.Subsystem1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Main_Firmware_M->extModeInfo,
      &Main_Firmware_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Main_Firmware_M->extModeInfo,
                        Main_Firmware_M->Sizes.checksums);
    rteiSetTFinalTicks(Main_Firmware_M->extModeInfo, -1);
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

  /* Start for S-Function (c2802xpwm): '<S2>/A' */
  real32_T tbprdValue1 = (real32_T)(EPwm1Regs.TBPRD + 1);

  /*** Initialize ePWM1 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 0U;          -- Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 3U;          -- Sync Output Select
       EPwm1Regs.TBCTL2.bit.SYNCOSELX           = 0U;          -- Sync Output Select - additional options

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm1Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          -- Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          -- Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x30U;
    EPwm1Regs.TBCTL2.all = (EPwm1Regs.TBCTL2.all & ~0xF000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 499U;            // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm1Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm1Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm1Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm1Regs.CMPCTL2.all = (EPwm1Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm1Regs.CMPA.bit.CMPA = 0U;      // Counter Compare A Register
    EPwm1Regs.CMPB.bit.CMPB = 32000U;  // Counter Compare B Register
    EPwm1Regs.CMPC = 300U;             // Counter Compare C Register
    EPwm1Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 150U;
                               // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 2070U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 0U;          -- Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 0;          -- Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm1Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm1Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm1Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm1Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x8FFFU) | 0x0U;
    EPwm1Regs.DBRED.bit.DBRED = (uint16_T)(0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED.bit.DBFED = (uint16_T)(0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCASEL              = 1U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM1SOC Period Select
       EPwm1Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM1SOCB Period Select
       EPwm1Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM1INTn Period Select
       EPwm1Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF7FU) | 0x1101U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm1Regs.ETSOCPS.all = (EPwm1Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm1Regs.ETINTPS.all = (EPwm1Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          -- Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 1U;          -- EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x20U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm1Regs.EPWMXLINK.bit.TBPRDLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPALINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPBLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPCLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPDLINK = 0U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm1Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm1Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm1Regs.HRPCTL.all = (EPwm1Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S2>/B' */
  real32_T tbprdValue4 = (real32_T)(EPwm4Regs.TBPRD + 1);

  /*** Initialize ePWM4 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm4Regs.TBCTL.bit.CTRMODE              = 0U;          -- Counter Mode
       EPwm4Regs.TBCTL.bit.SYNCOSEL             = 3U;          -- Sync Output Select
       EPwm4Regs.TBCTL2.bit.SYNCOSELX           = 0U;          -- Sync Output Select - additional options

       EPwm4Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm4Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm4Regs.TBCTL.bit.PHSEN                = 0U;          -- Phase Load Enable
       EPwm4Regs.TBCTL.bit.PHSDIR               = 0U;          -- Phase Direction Bit
       EPwm4Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm4Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm4Regs.TBCTL.all = (EPwm4Regs.TBCTL.all & ~0x3FFFU) | 0x30U;
    EPwm4Regs.TBCTL2.all = (EPwm4Regs.TBCTL2.all & ~0xF000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm4Regs.TBPRD = 499U;            // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm4Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm4Regs.TBPHS.all = (EPwm4Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm4Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm4Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm4Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm4Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm4Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm4Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm4Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm4Regs.CMPCTL.all = (EPwm4Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm4Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm4Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm4Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm4Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm4Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm4Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm4Regs.CMPCTL2.all = (EPwm4Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm4Regs.CMPA.bit.CMPA = 0U;      // Counter Compare A Register
    EPwm4Regs.CMPB.bit.CMPB = 32000U;  // Counter Compare B Register
    EPwm4Regs.CMPC = 300U;             // Counter Compare C Register
    EPwm4Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm4Regs.AQCTLA.all = 150U;
                               // Action Qualifier Control Register For Output A
    EPwm4Regs.AQCTLB.all = 2070U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm4Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm4Regs.AQSFRC.all = (EPwm4Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm4Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm4Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm4Regs.AQCSFRC.all = (EPwm4Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm4Regs.DBCTL.bit.OUT_MODE             = 0U;          -- Dead Band Output Mode Control
       EPwm4Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm4Regs.DBCTL.bit.POLSEL               = 0;          -- Polarity Select Control
       EPwm4Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm4Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm4Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm4Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm4Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm4Regs.DBCTL.all = (EPwm4Regs.DBCTL.all & ~0x8FFFU) | 0x0U;
    EPwm4Regs.DBRED.bit.DBRED = (uint16_T)(0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm4Regs.DBFED.bit.DBFED = (uint16_T)(0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm4Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm4Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm4Regs.ETSEL.bit.SOCASEL              = 1U;          -- Start of Conversion A Select
       EPwm4Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM4SOC Period Select
       EPwm4Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm4Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm4Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm4Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm4Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM4SOCB Period Select
       EPwm4Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm4Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM4INTn Enable
       EPwm4Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm4Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm4Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM4INTn Period Select
       EPwm4Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm4Regs.ETSEL.all = (EPwm4Regs.ETSEL.all & ~0xFF7FU) | 0x1101U;
    EPwm4Regs.ETPS.all = (EPwm4Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm4Regs.ETSOCPS.all = (EPwm4Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm4Regs.ETINTPS.all = (EPwm4Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm4Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm4Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm4Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm4Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm4Regs.PCCTL.all = (EPwm4Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm4Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm4Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM4A
       EPwm4Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM4B
       EPwm4Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM4A action on DCAEVT1
       EPwm4Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM4A action on DCAEVT2
       EPwm4Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM4B action on DCBEVT1
       EPwm4Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM4B action on DCBEVT2
     */
    EPwm4Regs.TZCTL.all = (EPwm4Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm4Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm4Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm4Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm4Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm4Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm4Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm4Regs.TZEINT.all = (EPwm4Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm4Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm4Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm4Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm4Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm4Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm4Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm4Regs.DCACTL.all = (EPwm4Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm4Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm4Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm4Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm4Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm4Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm4Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm4Regs.DCBCTL.all = (EPwm4Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm4Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm4Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          -- Digital Compare A Low COMP Input Select
       EPwm4Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm4Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm4Regs.DCTRIPSEL.all = (EPwm4Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm4Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm4Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm4Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm4Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm4Regs.TZDCSEL.all = (EPwm4Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm4Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm4Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm4Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm4Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm4Regs.DCFCTL.all = (EPwm4Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm4Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm4Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm4Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm4Regs.DCCAPCTL.all = (EPwm4Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm4Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm4Regs.HRCNFG.bit.SELOUTB             = 1U;          -- EPWMB Output Selection Bit
     */
    EPwm4Regs.HRCNFG.all = (EPwm4Regs.HRCNFG.all & ~0xA0U) | 0x20U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm4Regs.EPWMXLINK.bit.TBPRDLINK = 0U;
    EPwm4Regs.EPWMXLINK.bit.CMPALINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPBLINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPCLINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPDLINK = 3U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm4Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm4Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm4Regs.HRPCTL.all = (EPwm4Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S2>/C' */
  real32_T tbprdValue2 = (real32_T)(EPwm2Regs.TBPRD + 1);

  /*** Initialize ePWM2 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 0U;          -- Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 3U;          -- Sync Output Select
       EPwm2Regs.TBCTL2.bit.SYNCOSELX           = 0U;          -- Sync Output Select - additional options

       EPwm2Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm2Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm2Regs.TBCTL.bit.PHSEN                = 0U;          -- Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 0U;          -- Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFFU) | 0x30U;
    EPwm2Regs.TBCTL2.all = (EPwm2Regs.TBCTL2.all & ~0xF000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 499U;            // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm2Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm2Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm2Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm2Regs.CMPCTL2.all = (EPwm2Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm2Regs.CMPA.bit.CMPA = 0U;      // Counter Compare A Register
    EPwm2Regs.CMPB.bit.CMPB = 32000U;  // Counter Compare B Register
    EPwm2Regs.CMPC = 300U;             // Counter Compare C Register
    EPwm2Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 150U;
                               // Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 2070U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm2Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE             = 0U;          -- Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL               = 0;          -- Polarity Select Control
       EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm2Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm2Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm2Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm2Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x8FFFU) | 0x0U;
    EPwm2Regs.DBRED.bit.DBRED = (uint16_T)(0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED.bit.DBFED = (uint16_T)(0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCASEL              = 1U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM2SOC Period Select
       EPwm2Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM2SOCB Period Select
       EPwm2Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm2Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM2INTn Period Select
       EPwm2Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF7FU) | 0x1101U;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm2Regs.ETSOCPS.all = (EPwm2Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm2Regs.ETINTPS.all = (EPwm2Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM2B
       EPwm2Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM2A action on DCAEVT1
       EPwm2Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM2A action on DCAEVT2
       EPwm2Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM2B action on DCBEVT1
       EPwm2Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM2B action on DCBEVT2
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm2Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          -- Digital Compare A Low COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm2Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm2Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm2Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm2Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm2Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm2Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm2Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm2Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm2Regs.HRCNFG.bit.SELOUTB             = 1U;          -- EPWMB Output Selection Bit
     */
    EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0U) | 0x20U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm2Regs.EPWMXLINK.bit.TBPRDLINK = 0U;
    EPwm2Regs.EPWMXLINK.bit.CMPALINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPBLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPCLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPDLINK = 1U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm2Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm2Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm2Regs.HRPCTL.all = (EPwm2Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c280xgpio_do): '<S2>/Digital Output1' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFFU;
  GpioCtrlRegs.GPADIR.all |= 0x80000000U;
  EDIS;

  /* Start for DiscretePulseGenerator: '<S2>/LED Heartbeat' */
  Main_Firmware_DW.clockTickCounter = 0L;

  /* Start for S-Function (c280xgpio_do): '<S2>/Digital Output' */
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

  /* InitializeConditions for TransferFcn: '<S174>/Transfer Fcn' */
  Main_Firmware_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S173>/Integrator2' */
  Main_Firmware_X.Integrator2_CSTATE = Main_Firmware_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S173>/Integrator' */
  Main_Firmware_X.Integrator_CSTATE = Main_Firmware_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S173>/Integrator1' */
  Main_Firmware_X.Integrator1_CSTATE = Main_Firmware_P.Integrator1_IC;

  /* InitializeConditions for Derivative: '<S3>/Derivative' */
  Main_Firmware_DW.TimeStampA = (rtInf);
  Main_Firmware_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S150>/Filter' */
  Main_Firmware_X.Filter_CSTATE =
    Main_Firmware_P.SpeedPD_InitialConditionForFilt;

  /* InitializeConditions for Integrator: '<S97>/Integrator' */
  Main_Firmware_X.Integrator_CSTATE_h =
    Main_Firmware_P.I_dqPID3_InitialConditionForInt;

  /* InitializeConditions for Integrator: '<S45>/Integrator' */
  Main_Firmware_X.Integrator_CSTATE_hk =
    Main_Firmware_P.I_dqPID_InitialConditionForInte;

  /* SystemInitialize for Enabled SubSystem: '<S184>/Subsystem1' */
  /* SystemInitialize for Fcn: '<S188>/Fcn' incorporates:
   *  Outport: '<S188>/alpha_beta'
   */
  Main_Firmware_B.Fcn = Main_Firmware_P.alpha_beta_Y0_i[0];

  /* SystemInitialize for Fcn: '<S188>/Fcn1' incorporates:
   *  Outport: '<S188>/alpha_beta'
   */
  Main_Firmware_B.Fcn1 = Main_Firmware_P.alpha_beta_Y0_i[1];

  /* End of SystemInitialize for SubSystem: '<S184>/Subsystem1' */

  /* SystemInitialize for Enabled SubSystem: '<S184>/Subsystem - pi//2 delay' */
  /* SystemInitialize for Fcn: '<S187>/Fcn' incorporates:
   *  Outport: '<S187>/alpha_beta'
   */
  Main_Firmware_B.Fcn_g = Main_Firmware_P.alpha_beta_Y0[0];

  /* SystemInitialize for Fcn: '<S187>/Fcn1' incorporates:
   *  Outport: '<S187>/alpha_beta'
   */
  Main_Firmware_B.Fcn1_l = Main_Firmware_P.alpha_beta_Y0[1];

  /* End of SystemInitialize for SubSystem: '<S184>/Subsystem - pi//2 delay' */

  /* SystemInitialize for Enabled SubSystem: '<S115>/Subsystem1' */
  Main_Firmware_Subsystem1_Init(&Main_Firmware_B.Fcn_k, &Main_Firmware_B.Fcn1_n,
    &Main_Firmware_P.Subsystem1);

  /* End of SystemInitialize for SubSystem: '<S115>/Subsystem1' */

  /* SystemInitialize for Enabled SubSystem: '<S115>/Subsystem - pi//2 delay' */
  Main_Fir_Subsystempi2delay_Init(&Main_Firmware_B.Fcn_jc,
    &Main_Firmware_B.Fcn1_e, &Main_Firmware_P.Subsystempi2delay);

  /* End of SystemInitialize for SubSystem: '<S115>/Subsystem - pi//2 delay' */

  /* SystemInitialize for Enabled SubSystem: '<S177>/Subsystem1' */
  Main_Firmware_Subsystem1_Init(&Main_Firmware_B.Fcn_b, &Main_Firmware_B.Fcn1_d,
    &Main_Firmware_P.Subsystem1_c);

  /* End of SystemInitialize for SubSystem: '<S177>/Subsystem1' */

  /* SystemInitialize for Enabled SubSystem: '<S177>/Subsystem - pi//2 delay' */
  Main_Fir_Subsystempi2delay_Init(&Main_Firmware_B.Fcn_j,
    &Main_Firmware_B.Fcn1_k, &Main_Firmware_P.Subsystempi2delay_o);

  /* End of SystemInitialize for SubSystem: '<S177>/Subsystem - pi//2 delay' */
}

/* Model terminate function */
void Main_Firmware_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
