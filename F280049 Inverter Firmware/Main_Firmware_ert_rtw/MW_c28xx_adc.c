#include "c2000BoardSupport.h"
#include "MW_f28004x_includes.h"
#include "rtwtypes.h"
#include "Main_Firmware.h"
#include "Main_Firmware_private.h"
#include "MW_c28xAnalogSubsystem.h"

void config_ADCB_SOC0(void)
{
  EALLOW;
  AdcbRegs.ADCSOC0CTL.bit.CHSEL = 6U;  /* Set SOC0 channel select to ADCIN6*/
  AdcbRegs.ADCSOC0CTL.bit.TRIGSEL = 0U;
  AdcbRegs.ADCSOC0CTL.bit.ACQPS = (uint16_T)7.0;
                                /* Set SOC0 S/H Window to 8.0 ADC Clock Cycles*/
  AdcbRegs.ADCINTSOCSEL1.bit.SOC0 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcbRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcbRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correction Value*/
  AdcbRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
             /* Interrupt pulse generation occurs at the end of the conversion*/
  AdcbRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCA_SOC8(void)
{
  EALLOW;
  AdcaRegs.ADCSOC8CTL.bit.CHSEL = 6U;  /* Set SOC8 channel select to ADCIN6*/
  AdcaRegs.ADCSOC8CTL.bit.TRIGSEL = 0U;
  AdcaRegs.ADCSOC8CTL.bit.ACQPS = (uint16_T)7.0;
                                /* Set SOC8 S/H Window to 8.0 ADC Clock Cycles*/
  AdcaRegs.ADCINTSOCSEL2.bit.SOC8 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcaRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcaRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correction Value*/
  AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
             /* Interrupt pulse generation occurs at the end of the conversion*/
  AdcaRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCC_SOC1(void)
{
  EALLOW;
  AdccRegs.ADCSOC1CTL.bit.CHSEL = 3U;  /* Set SOC1 channel select to ADCIN3*/
  AdccRegs.ADCSOC1CTL.bit.TRIGSEL = 0U;
  AdccRegs.ADCSOC1CTL.bit.ACQPS = (uint16_T)7.0;
                                /* Set SOC1 S/H Window to 8.0 ADC Clock Cycles*/
  AdccRegs.ADCINTSOCSEL1.bit.SOC1 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdccRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdccRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correction Value*/
  AdccRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
             /* Interrupt pulse generation occurs at the end of the conversion*/
  AdccRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCC_SOC2(void)
{
  EALLOW;
  AdccRegs.ADCSOC2CTL.bit.CHSEL = 5U;  /* Set SOC2 channel select to ADCIN5*/
  AdccRegs.ADCSOC2CTL.bit.TRIGSEL = 0U;
  AdccRegs.ADCSOC2CTL.bit.ACQPS = (uint16_T)7.0;
                                /* Set SOC2 S/H Window to 8.0 ADC Clock Cycles*/
  AdccRegs.ADCINTSOCSEL1.bit.SOC2 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdccRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdccRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correction Value*/
  AdccRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
             /* Interrupt pulse generation occurs at the end of the conversion*/
  AdccRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCA_SOC3(void)
{
  EALLOW;
  AdcaRegs.ADCSOC3CTL.bit.CHSEL = 3U;  /* Set SOC3 channel select to ADCIN3*/
  AdcaRegs.ADCSOC3CTL.bit.TRIGSEL = 0U;
  AdcaRegs.ADCSOC3CTL.bit.ACQPS = (uint16_T)7.0;
                                /* Set SOC3 S/H Window to 8.0 ADC Clock Cycles*/
  AdcaRegs.ADCINTSOCSEL1.bit.SOC3 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcaRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcaRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correction Value*/
  AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
             /* Interrupt pulse generation occurs at the end of the conversion*/
  AdcaRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
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
