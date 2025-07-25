#include "c2000BoardSupport.h"
#include "MW_f28004x_includes.h"
#include "rtwtypes.h"
#include "Main_Firmware.h"
#include "Main_Firmware_private.h"
#include "MW_c28xAnalogSubsystem.h"

void config_ADCB_SOC4(void)
{
  EALLOW;
  AdcbRegs.ADCSOC4CTL.bit.CHSEL = 6U;  /* Set SOC4 channel select to ADCIN6*/
  AdcbRegs.ADCSOC4CTL.bit.TRIGSEL = 0U;
  AdcbRegs.ADCSOC4CTL.bit.ACQPS = (uint16_T)31.0;
                               /* Set SOC4 S/H Window to 32.0 ADC Clock Cycles*/
  AdcbRegs.ADCINTSEL1N2.bit.INT1E = 1U;/* Enabled/Disable ADCINT1 interrupt*/
  AdcbRegs.ADCINTSEL1N2.bit.INT1SEL = 4U;/* Setup EOC4 to trigger ADCINT1*/
  AdcbRegs.ADCINTSEL1N2.bit.INT1CONT = 1U;
                                     /* Enable/Disable ADCINT1 Continuous mode*/
  AdcbRegs.ADCINTSOCSEL1.bit.SOC4 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcbRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcbRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correction Value*/
  AdcbRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
             /* Interrupt pulse generation occurs at the end of the conversion*/
  AdcbRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCA_SOC6(void)
{
  EALLOW;
  AdcaRegs.ADCSOC6CTL.bit.CHSEL = 6U;  /* Set SOC6 channel select to ADCIN6*/
  AdcaRegs.ADCSOC6CTL.bit.TRIGSEL = 0U;
  AdcaRegs.ADCSOC6CTL.bit.ACQPS = (uint16_T)31.0;
                               /* Set SOC6 S/H Window to 32.0 ADC Clock Cycles*/
  AdcaRegs.ADCINTSEL1N2.bit.INT1E = 1U;/* Enabled/Disable ADCINT1 interrupt*/
  AdcaRegs.ADCINTSEL1N2.bit.INT1SEL = 6U;/* Setup EOC6 to trigger ADCINT1*/
  AdcaRegs.ADCINTSEL1N2.bit.INT1CONT = 1U;
                                     /* Enable/Disable ADCINT1 Continuous mode*/
  AdcaRegs.ADCINTSOCSEL1.bit.SOC6 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcaRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcaRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correction Value*/
  AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
             /* Interrupt pulse generation occurs at the end of the conversion*/
  AdcaRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCA_SOC5(void)
{
  EALLOW;
  AdcaRegs.ADCSOC5CTL.bit.CHSEL = 5U;  /* Set SOC5 channel select to ADCIN5*/
  AdcaRegs.ADCSOC5CTL.bit.TRIGSEL = 0U;
  AdcaRegs.ADCSOC5CTL.bit.ACQPS = (uint16_T)31.0;
                               /* Set SOC5 S/H Window to 32.0 ADC Clock Cycles*/
  AdcaRegs.ADCINTSEL1N2.bit.INT2E = 1U;/* Enabled/Disable ADCINT2 interrupt*/
  AdcaRegs.ADCINTSEL1N2.bit.INT2SEL = 5U;/* Setup EOC5 to trigger ADCINT2*/
  AdcaRegs.ADCINTSEL1N2.bit.INT2CONT = 1U;
                                     /* Enable/Disable ADCINT2 Continuous mode*/
  AdcaRegs.ADCINTSOCSEL1.bit.SOC5 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcaRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcaRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correction Value*/
  AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
             /* Interrupt pulse generation occurs at the end of the conversion*/
  AdcaRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCB_SOC0(void)
{
  EALLOW;
  AdcbRegs.ADCSOC0CTL.bit.CHSEL = 0U;  /* Set SOC0 channel select to ADCIN0*/
  AdcbRegs.ADCSOC0CTL.bit.TRIGSEL = 0U;
  AdcbRegs.ADCSOC0CTL.bit.ACQPS = (uint16_T)63.0;
                               /* Set SOC0 S/H Window to 64.0 ADC Clock Cycles*/
  AdcbRegs.ADCINTSEL1N2.bit.INT2E = 1U;/* Enabled/Disable ADCINT2 interrupt*/
  AdcbRegs.ADCINTSEL1N2.bit.INT2SEL = 0U;/* Setup EOC0 to trigger ADCINT2*/
  AdcbRegs.ADCINTSEL1N2.bit.INT2CONT = 1U;
                                     /* Enable/Disable ADCINT2 Continuous mode*/
  AdcbRegs.ADCINTSOCSEL1.bit.SOC0 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcbRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcbRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correction Value*/
  AdcbRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
             /* Interrupt pulse generation occurs at the end of the conversion*/
  AdcbRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCC_SOC2(void)
{
  EALLOW;
  AdccRegs.ADCSOC2CTL.bit.CHSEL = 2U;  /* Set SOC2 channel select to ADCIN2*/
  AdccRegs.ADCSOC2CTL.bit.TRIGSEL = 0U;
  AdccRegs.ADCSOC2CTL.bit.ACQPS = (uint16_T)63.0;
                               /* Set SOC2 S/H Window to 64.0 ADC Clock Cycles*/
  AdccRegs.ADCINTSEL1N2.bit.INT1E = 1U;/* Enabled/Disable ADCINT1 interrupt*/
  AdccRegs.ADCINTSEL1N2.bit.INT1SEL = 2U;/* Setup EOC2 to trigger ADCINT1*/
  AdccRegs.ADCINTSEL1N2.bit.INT1CONT = 1U;
                                     /* Enable/Disable ADCINT1 Continuous mode*/
  AdccRegs.ADCINTSOCSEL1.bit.SOC2 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdccRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdccRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correction Value*/
  AdccRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
             /* Interrupt pulse generation occurs at the end of the conversion*/
  AdccRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void InitAdcA(void)
{
  EALLOW;
  CpuSysRegs.PCLKCR13.bit.ADC_A = 1U;
  AdcaRegs.ADCCTL2.bit.PRESCALE = 2U;

  //power up the ADC
  AdcaRegs.ADCCTL1.bit.ADCPWDNZ = 1U;

  //delay for 1ms to allow ADC time to power up
  DELAY_US(1000);
  EDIS;
}

void InitAdcB(void)
{
  EALLOW;
  CpuSysRegs.PCLKCR13.bit.ADC_B = 1U;
  AdcbRegs.ADCCTL2.bit.PRESCALE = 2U;

  //power up the ADC
  AdcbRegs.ADCCTL1.bit.ADCPWDNZ = 1U;

  //delay for 1ms to allow ADC time to power up
  DELAY_US(1000);
  EDIS;
}

void InitAdcC(void)
{
  EALLOW;
  CpuSysRegs.PCLKCR13.bit.ADC_C = 1U;
  AdccRegs.ADCCTL2.bit.PRESCALE = 2U;

  //power up the ADC
  AdccRegs.ADCCTL1.bit.ADCPWDNZ = 1U;

  //delay for 1ms to allow ADC time to power up
  DELAY_US(1000);
  EDIS;
}
