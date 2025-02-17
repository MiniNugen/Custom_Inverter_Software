/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Main_Firmware/FOC test/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Main_Firmware_bbbdb992_1_ds_sys_struct.h"
#include "Main_Firmware_bbbdb992_1_ds_log.h"
#include "Main_Firmware_bbbdb992_1_ds.h"
#include "Main_Firmware_bbbdb992_1_ds_externals.h"
#include "Main_Firmware_bbbdb992_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Main_Firmware_bbbdb992_1_ds_log(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t24, NeDsMethodOutput *out)
{
  real_T FOC_test_Converter_Three_Phase_G_V[12];
  real_T t1[12];
  real_T FOC_test_Converter_Three_Phase_Q1_i;
  real_T FOC_test_Converter_Three_Phase_Q1_ideal_switch_power_dissipated;
  real_T FOC_test_Converter_Three_Phase_Q1_ideal_switch_v;
  real_T FOC_test_Converter_Three_Phase_Q2_ideal_switch_power_dissipated;
  real_T FOC_test_Converter_Three_Phase_Q2_ideal_switch_v;
  real_T FOC_test_Converter_Three_Phase_Q3_i;
  real_T FOC_test_Converter_Three_Phase_Q3_ideal_switch_power_dissipated;
  real_T FOC_test_Converter_Three_Phase_Q3_ideal_switch_v;
  real_T FOC_test_Converter_Three_Phase_Q4_ideal_switch_power_dissipated;
  real_T FOC_test_Converter_Three_Phase_Q4_ideal_switch_v;
  real_T FOC_test_Converter_Three_Phase_Q5_i;
  real_T FOC_test_Converter_Three_Phase_Q5_ideal_switch_power_dissipated;
  real_T FOC_test_Converter_Three_Phase_Q5_ideal_switch_v;
  real_T FOC_test_Converter_Three_Phase_Q6_ideal_switch_power_dissipated;
  real_T FOC_test_Converter_Three_Phase_Q6_ideal_switch_v;
  real_T t16;
  real_T t22;
  size_t t9;
  (void)LC;
  t1[0ULL] = t24->mU.mX[0ULL];
  t1[1ULL] = 0.0;
  t1[2ULL] = t24->mU.mX[1ULL];
  t1[3ULL] = 0.0;
  t1[4ULL] = t24->mU.mX[2ULL];
  t1[5ULL] = 0.0;
  t1[6ULL] = t24->mU.mX[3ULL];
  t1[7ULL] = 0.0;
  t1[8ULL] = t24->mU.mX[4ULL];
  t1[9ULL] = 0.0;
  t1[10ULL] = t24->mU.mX[5ULL];
  t1[11ULL] = 0.0;
  for (t9 = 0ULL; t9 < 12ULL; t9++) {
    FOC_test_Converter_Three_Phase_G_V[t9] = t1[t9];
  }

  FOC_test_Converter_Three_Phase_Q1_i = (-t24->mX.mX[9ULL] - t24->mX.mX[10ULL])
    + t24->mX.mX[8ULL];
  FOC_test_Converter_Three_Phase_Q1_ideal_switch_v = (-t24->mX.mX[7ULL] +
    t24->mX.mX[6ULL]) + 100.0;
  FOC_test_Converter_Three_Phase_Q1_ideal_switch_power_dissipated =
    FOC_test_Converter_Three_Phase_Q1_i *
    FOC_test_Converter_Three_Phase_Q1_ideal_switch_v * 0.001;
  FOC_test_Converter_Three_Phase_Q2_ideal_switch_v = -t24->mX.mX[6ULL] +
    t24->mX.mX[7ULL];
  FOC_test_Converter_Three_Phase_Q2_ideal_switch_power_dissipated = t24->mX.mX
    [8ULL] * FOC_test_Converter_Three_Phase_Q2_ideal_switch_v * 0.001;
  FOC_test_Converter_Three_Phase_Q3_i = t24->mX.mX[9ULL] + t24->mX.mX[12ULL];
  FOC_test_Converter_Three_Phase_Q3_ideal_switch_v = (-t24->mX.mX[11ULL] +
    t24->mX.mX[6ULL]) + 100.0;
  FOC_test_Converter_Three_Phase_Q3_ideal_switch_power_dissipated =
    FOC_test_Converter_Three_Phase_Q3_i *
    FOC_test_Converter_Three_Phase_Q3_ideal_switch_v * 0.001;
  FOC_test_Converter_Three_Phase_Q4_ideal_switch_v = -t24->mX.mX[6ULL] +
    t24->mX.mX[11ULL];
  FOC_test_Converter_Three_Phase_Q4_ideal_switch_power_dissipated = t24->mX.mX
    [12ULL] * FOC_test_Converter_Three_Phase_Q4_ideal_switch_v * 0.001;
  FOC_test_Converter_Three_Phase_Q5_i = t24->mX.mX[10ULL] + t24->mX.mX[14ULL];
  FOC_test_Converter_Three_Phase_Q5_ideal_switch_v = (-t24->mX.mX[13ULL] +
    t24->mX.mX[6ULL]) + 100.0;
  FOC_test_Converter_Three_Phase_Q5_ideal_switch_power_dissipated =
    FOC_test_Converter_Three_Phase_Q5_i *
    FOC_test_Converter_Three_Phase_Q5_ideal_switch_v * 0.001;
  FOC_test_Converter_Three_Phase_Q6_ideal_switch_v = -t24->mX.mX[6ULL] +
    t24->mX.mX[13ULL];
  FOC_test_Converter_Three_Phase_Q6_ideal_switch_power_dissipated = t24->mX.mX
    [14ULL] * FOC_test_Converter_Three_Phase_Q6_ideal_switch_v * 0.001;
  t22 = -t24->mX.mX[9ULL] - t24->mX.mX[10ULL];
  t16 = -t24->mU.mX[6ULL] + t24->mX.mX[15ULL];
  for (t9 = 0ULL; t9 < 12ULL; t9++) {
    out->mLOG.mX[t9] = FOC_test_Converter_Three_Phase_G_V[t9];
  }

  out->mLOG.mX[12ULL] = t24->mU.mX[0ULL];
  out->mLOG.mX[13ULL] = t24->mU.mX[0ULL];
  out->mLOG.mX[14ULL] = t24->mU.mX[1ULL];
  out->mLOG.mX[15ULL] = t24->mU.mX[1ULL];
  out->mLOG.mX[16ULL] = t24->mU.mX[2ULL];
  out->mLOG.mX[17ULL] = t24->mU.mX[2ULL];
  out->mLOG.mX[18ULL] = t24->mU.mX[3ULL];
  out->mLOG.mX[19ULL] = t24->mU.mX[3ULL];
  out->mLOG.mX[20ULL] = t24->mU.mX[4ULL];
  out->mLOG.mX[21ULL] = t24->mU.mX[4ULL];
  out->mLOG.mX[22ULL] = t24->mU.mX[5ULL];
  out->mLOG.mX[23ULL] = t24->mU.mX[5ULL];
  for (t9 = 0ULL; t9 < 12ULL; t9++) {
    out->mLOG.mX[t9 + 24ULL] = FOC_test_Converter_Three_Phase_G_V[t9];
  }

  out->mLOG.mX[36ULL] = t24->mX.mX[6ULL] + 100.0;
  out->mLOG.mX[37ULL] = t24->mU.mX[0ULL];
  out->mLOG.mX[38ULL] = t24->mX.mX[7ULL];
  out->mLOG.mX[39ULL] = FOC_test_Converter_Three_Phase_Q1_i;
  out->mLOG.mX[40ULL] = FOC_test_Converter_Three_Phase_Q1_i;
  out->mLOG.mX[41ULL] = t24->mX.mX[7ULL];
  out->mLOG.mX[42ULL] = t24->mX.mX[6ULL] + 100.0;
  out->mLOG.mX[43ULL] =
    FOC_test_Converter_Three_Phase_Q1_ideal_switch_power_dissipated * 1000.0;
  out->mLOG.mX[44ULL] = FOC_test_Converter_Three_Phase_Q1_ideal_switch_v;
  out->mLOG.mX[45ULL] = t24->mU.mX[0ULL];
  out->mLOG.mX[46ULL] =
    FOC_test_Converter_Three_Phase_Q1_ideal_switch_power_dissipated * 1000.0;
  out->mLOG.mX[47ULL] = FOC_test_Converter_Three_Phase_Q1_ideal_switch_v;
  out->mLOG.mX[48ULL] = t24->mU.mX[0ULL];
  out->mLOG.mX[49ULL] = t24->mX.mX[7ULL];
  out->mLOG.mX[50ULL] = t24->mU.mX[1ULL];
  out->mLOG.mX[51ULL] = t24->mX.mX[6ULL];
  out->mLOG.mX[52ULL] = t24->mX.mX[8ULL];
  out->mLOG.mX[53ULL] = t24->mX.mX[8ULL];
  out->mLOG.mX[54ULL] = t24->mX.mX[6ULL];
  out->mLOG.mX[55ULL] = t24->mX.mX[7ULL];
  out->mLOG.mX[56ULL] =
    FOC_test_Converter_Three_Phase_Q2_ideal_switch_power_dissipated * 1000.0;
  out->mLOG.mX[57ULL] = FOC_test_Converter_Three_Phase_Q2_ideal_switch_v;
  out->mLOG.mX[58ULL] = t24->mU.mX[1ULL];
  out->mLOG.mX[59ULL] =
    FOC_test_Converter_Three_Phase_Q2_ideal_switch_power_dissipated * 1000.0;
  out->mLOG.mX[60ULL] = FOC_test_Converter_Three_Phase_Q2_ideal_switch_v;
  out->mLOG.mX[61ULL] = t24->mU.mX[1ULL];
  out->mLOG.mX[62ULL] = t24->mX.mX[6ULL] + 100.0;
  out->mLOG.mX[63ULL] = t24->mU.mX[2ULL];
  out->mLOG.mX[64ULL] = t24->mX.mX[11ULL];
  out->mLOG.mX[65ULL] = FOC_test_Converter_Three_Phase_Q3_i;
  out->mLOG.mX[66ULL] = FOC_test_Converter_Three_Phase_Q3_i;
  out->mLOG.mX[67ULL] = t24->mX.mX[11ULL];
  out->mLOG.mX[68ULL] = t24->mX.mX[6ULL] + 100.0;
  out->mLOG.mX[69ULL] =
    FOC_test_Converter_Three_Phase_Q3_ideal_switch_power_dissipated * 1000.0;
  out->mLOG.mX[70ULL] = FOC_test_Converter_Three_Phase_Q3_ideal_switch_v;
  out->mLOG.mX[71ULL] = t24->mU.mX[2ULL];
  out->mLOG.mX[72ULL] =
    FOC_test_Converter_Three_Phase_Q3_ideal_switch_power_dissipated * 1000.0;
  out->mLOG.mX[73ULL] = FOC_test_Converter_Three_Phase_Q3_ideal_switch_v;
  out->mLOG.mX[74ULL] = t24->mU.mX[2ULL];
  out->mLOG.mX[75ULL] = t24->mX.mX[11ULL];
  out->mLOG.mX[76ULL] = t24->mU.mX[3ULL];
  out->mLOG.mX[77ULL] = t24->mX.mX[6ULL];
  out->mLOG.mX[78ULL] = t24->mX.mX[12ULL];
  out->mLOG.mX[79ULL] = t24->mX.mX[12ULL];
  out->mLOG.mX[80ULL] = t24->mX.mX[6ULL];
  out->mLOG.mX[81ULL] = t24->mX.mX[11ULL];
  out->mLOG.mX[82ULL] =
    FOC_test_Converter_Three_Phase_Q4_ideal_switch_power_dissipated * 1000.0;
  out->mLOG.mX[83ULL] = FOC_test_Converter_Three_Phase_Q4_ideal_switch_v;
  out->mLOG.mX[84ULL] = t24->mU.mX[3ULL];
  out->mLOG.mX[85ULL] =
    FOC_test_Converter_Three_Phase_Q4_ideal_switch_power_dissipated * 1000.0;
  out->mLOG.mX[86ULL] = FOC_test_Converter_Three_Phase_Q4_ideal_switch_v;
  out->mLOG.mX[87ULL] = t24->mU.mX[3ULL];
  out->mLOG.mX[88ULL] = t24->mX.mX[6ULL] + 100.0;
  out->mLOG.mX[89ULL] = t24->mU.mX[4ULL];
  out->mLOG.mX[90ULL] = t24->mX.mX[13ULL];
  out->mLOG.mX[91ULL] = FOC_test_Converter_Three_Phase_Q5_i;
  out->mLOG.mX[92ULL] = FOC_test_Converter_Three_Phase_Q5_i;
  out->mLOG.mX[93ULL] = t24->mX.mX[13ULL];
  out->mLOG.mX[94ULL] = t24->mX.mX[6ULL] + 100.0;
  out->mLOG.mX[95ULL] =
    FOC_test_Converter_Three_Phase_Q5_ideal_switch_power_dissipated * 1000.0;
  out->mLOG.mX[96ULL] = FOC_test_Converter_Three_Phase_Q5_ideal_switch_v;
  out->mLOG.mX[97ULL] = t24->mU.mX[4ULL];
  out->mLOG.mX[98ULL] =
    FOC_test_Converter_Three_Phase_Q5_ideal_switch_power_dissipated * 1000.0;
  out->mLOG.mX[99ULL] = FOC_test_Converter_Three_Phase_Q5_ideal_switch_v;
  out->mLOG.mX[100ULL] = t24->mU.mX[4ULL];
  out->mLOG.mX[101ULL] = t24->mX.mX[13ULL];
  out->mLOG.mX[102ULL] = t24->mU.mX[5ULL];
  out->mLOG.mX[103ULL] = t24->mX.mX[6ULL];
  out->mLOG.mX[104ULL] = t24->mX.mX[14ULL];
  out->mLOG.mX[105ULL] = t24->mX.mX[14ULL];
  out->mLOG.mX[106ULL] = t24->mX.mX[6ULL];
  out->mLOG.mX[107ULL] = t24->mX.mX[13ULL];
  out->mLOG.mX[108ULL] =
    FOC_test_Converter_Three_Phase_Q6_ideal_switch_power_dissipated * 1000.0;
  out->mLOG.mX[109ULL] = FOC_test_Converter_Three_Phase_Q6_ideal_switch_v;
  out->mLOG.mX[110ULL] = t24->mU.mX[5ULL];
  out->mLOG.mX[111ULL] =
    FOC_test_Converter_Three_Phase_Q6_ideal_switch_power_dissipated * 1000.0;
  out->mLOG.mX[112ULL] = FOC_test_Converter_Three_Phase_Q6_ideal_switch_v;
  out->mLOG.mX[113ULL] = t24->mU.mX[5ULL];
  out->mLOG.mX[114ULL] = t24->mX.mX[7ULL];
  out->mLOG.mX[115ULL] = t24->mX.mX[11ULL];
  out->mLOG.mX[116ULL] = t24->mX.mX[13ULL];
  out->mLOG.mX[117ULL] = t24->mX.mX[6ULL];
  out->mLOG.mX[118ULL] = t24->mX.mX[6ULL] + 100.0;
  out->mLOG.mX[119ULL] = t22;
  out->mLOG.mX[120ULL] = t24->mX.mX[9ULL];
  out->mLOG.mX[121ULL] = t24->mX.mX[10ULL];
  out->mLOG.mX[122ULL] = t24->mX.mX[7ULL];
  out->mLOG.mX[123ULL] = t24->mX.mX[7ULL];
  out->mLOG.mX[124ULL] = t24->mX.mX[11ULL];
  out->mLOG.mX[125ULL] = t24->mX.mX[11ULL];
  out->mLOG.mX[126ULL] = t24->mX.mX[13ULL];
  out->mLOG.mX[127ULL] = t24->mX.mX[13ULL];
  out->mLOG.mX[128ULL] = t22;
  out->mLOG.mX[129ULL] = t24->mX.mX[9ULL];
  out->mLOG.mX[130ULL] = t24->mX.mX[10ULL];
  out->mLOG.mX[131ULL] = t22;
  out->mLOG.mX[132ULL] = t24->mX.mX[9ULL];
  out->mLOG.mX[133ULL] = t24->mX.mX[10ULL];
  for (t9 = 0ULL; t9 < 12ULL; t9++) {
    out->mLOG.mX[t9 + 134ULL] = FOC_test_Converter_Three_Phase_G_V[t9];
  }

  out->mLOG.mX[146ULL] = t24->mU.mX[0ULL];
  out->mLOG.mX[147ULL] = t24->mU.mX[1ULL];
  out->mLOG.mX[148ULL] = t24->mU.mX[2ULL];
  out->mLOG.mX[149ULL] = t24->mU.mX[3ULL];
  out->mLOG.mX[150ULL] = t24->mU.mX[4ULL];
  out->mLOG.mX[151ULL] = t24->mU.mX[5ULL];
  out->mLOG.mX[152ULL] = t24->mU.mX[0ULL];
  out->mLOG.mX[153ULL] = t24->mU.mX[1ULL];
  out->mLOG.mX[154ULL] = t24->mU.mX[2ULL];
  out->mLOG.mX[155ULL] = t24->mU.mX[3ULL];
  out->mLOG.mX[156ULL] = t24->mU.mX[4ULL];
  out->mLOG.mX[157ULL] = t24->mU.mX[5ULL];
  for (t9 = 0ULL; t9 < 12ULL; t9++) {
    out->mLOG.mX[t9 + 158ULL] = FOC_test_Converter_Three_Phase_G_V[t9];
  }

  out->mLOG.mX[170ULL] = t24->mX.mX[1ULL];
  out->mLOG.mX[171ULL] = t24->mX.mX[0ULL];
  out->mLOG.mX[172ULL] = t24->mX.mX[0ULL];
  out->mLOG.mX[173ULL] = t24->mX.mX[1ULL];
  out->mLOG.mX[174ULL] = t24->mX.mX[1ULL];
  out->mLOG.mX[175ULL] = t24->mX.mX[0ULL];
  out->mLOG.mX[176ULL] = t24->mX.mX[0ULL];
  out->mLOG.mX[177ULL] = t24->mX.mX[0ULL];
  out->mLOG.mX[178ULL] = t16;
  out->mLOG.mX[179ULL] = t16;
  out->mLOG.mX[180ULL] = t16;
  out->mLOG.mX[181ULL] = t24->mX.mX[0ULL];
  out->mLOG.mX[182ULL] = t24->mU.mX[6ULL];
  out->mLOG.mX[183ULL] = -t24->mU.mX[6ULL];
  out->mLOG.mX[184ULL] = -t24->mX.mX[0ULL];
  out->mLOG.mX[185ULL] = t24->mX.mX[0ULL];
  out->mLOG.mX[186ULL] = t24->mX.mX[0ULL];
  out->mLOG.mX[187ULL] = t24->mX.mX[15ULL];
  out->mLOG.mX[188ULL] = t24->mX.mX[0ULL];
  out->mLOG.mX[189ULL] = t24->mX.mX[0ULL];
  out->mLOG.mX[190ULL] = t24->mX.mX[7ULL];
  out->mLOG.mX[191ULL] = t24->mX.mX[2ULL] * 57.295779513082323;
  out->mLOG.mX[192ULL] = t24->mX.mX[3ULL] * 9.5492965855137211;
  out->mLOG.mX[193ULL] = t24->mX.mX[11ULL];
  out->mLOG.mX[194ULL] = t24->mX.mX[13ULL];
  out->mLOG.mX[195ULL] = t24->mX.mX[16ULL];
  out->mLOG.mX[196ULL] = t22;
  out->mLOG.mX[197ULL] = t24->mX.mX[9ULL];
  out->mLOG.mX[198ULL] = t24->mX.mX[10ULL];
  out->mLOG.mX[199ULL] = t24->mX.mX[4ULL];
  out->mLOG.mX[200ULL] = t24->mX.mX[5ULL];
  out->mLOG.mX[201ULL] = (t22 * t22 * 0.00017999999999999998 + t24->mX.mX[9ULL] *
    t24->mX.mX[9ULL] * 0.00017999999999999998) + t24->mX.mX[10ULL] * t24->mX.mX
    [10ULL] * 0.00017999999999999998;
  out->mLOG.mX[202ULL] = -t16;
  out->mLOG.mX[203ULL] = t24->mX.mX[7ULL];
  out->mLOG.mX[204ULL] = t24->mX.mX[11ULL];
  out->mLOG.mX[205ULL] = t24->mX.mX[13ULL];
  out->mLOG.mX[206ULL] = t24->mU.mX[6ULL];
  out->mLOG.mX[207ULL] = (-t24->mX.mX[8ULL] - t24->mX.mX[12ULL]) - t24->mX.mX
    [14ULL];
  out->mLOG.mX[208ULL] = t24->mX.mX[6ULL];
  out->mLOG.mX[209ULL] = t24->mX.mX[6ULL] + 100.0;
  (void)LC;
  (void)out;
  return 0;
}
