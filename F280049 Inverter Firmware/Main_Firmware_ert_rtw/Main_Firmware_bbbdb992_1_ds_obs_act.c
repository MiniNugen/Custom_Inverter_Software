/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Main_Firmware/FOC test/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Main_Firmware_bbbdb992_1_ds_sys_struct.h"
#include "Main_Firmware_bbbdb992_1_ds_obs_act.h"
#include "Main_Firmware_bbbdb992_1_ds.h"
#include "Main_Firmware_bbbdb992_1_ds_externals.h"
#include "Main_Firmware_bbbdb992_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Main_Firmware_bbbdb992_1_ds_obs_act(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t46, NeDsMethodOutput *out)
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
  real_T t26;
  real_T t44;
  size_t t15;
  t1[0ULL] = t46->mU.mX[0ULL];
  t1[1ULL] = 0.0;
  t1[2ULL] = t46->mU.mX[1ULL];
  t1[3ULL] = 0.0;
  t1[4ULL] = t46->mU.mX[2ULL];
  t1[5ULL] = 0.0;
  t1[6ULL] = t46->mU.mX[3ULL];
  t1[7ULL] = 0.0;
  t1[8ULL] = t46->mU.mX[4ULL];
  t1[9ULL] = 0.0;
  t1[10ULL] = t46->mU.mX[5ULL];
  t1[11ULL] = 0.0;
  for (t15 = 0ULL; t15 < 12ULL; t15++) {
    FOC_test_Converter_Three_Phase_G_V[t15] = t1[t15];
  }

  FOC_test_Converter_Three_Phase_Q1_i = (-t46->mX.mX[9ULL] - t46->mX.mX[10ULL])
    + t46->mX.mX[8ULL];
  FOC_test_Converter_Three_Phase_Q1_ideal_switch_v = (-t46->mX.mX[7ULL] +
    t46->mX.mX[6ULL]) + 100.0;
  FOC_test_Converter_Three_Phase_Q1_ideal_switch_power_dissipated =
    FOC_test_Converter_Three_Phase_Q1_i *
    FOC_test_Converter_Three_Phase_Q1_ideal_switch_v * 0.001;
  FOC_test_Converter_Three_Phase_Q2_ideal_switch_v = -t46->mX.mX[6ULL] +
    t46->mX.mX[7ULL];
  FOC_test_Converter_Three_Phase_Q2_ideal_switch_power_dissipated = t46->mX.mX
    [8ULL] * FOC_test_Converter_Three_Phase_Q2_ideal_switch_v * 0.001;
  FOC_test_Converter_Three_Phase_Q3_i = t46->mX.mX[9ULL] + t46->mX.mX[12ULL];
  FOC_test_Converter_Three_Phase_Q3_ideal_switch_v = (-t46->mX.mX[11ULL] +
    t46->mX.mX[6ULL]) + 100.0;
  FOC_test_Converter_Three_Phase_Q3_ideal_switch_power_dissipated =
    FOC_test_Converter_Three_Phase_Q3_i *
    FOC_test_Converter_Three_Phase_Q3_ideal_switch_v * 0.001;
  FOC_test_Converter_Three_Phase_Q4_ideal_switch_v = -t46->mX.mX[6ULL] +
    t46->mX.mX[11ULL];
  FOC_test_Converter_Three_Phase_Q4_ideal_switch_power_dissipated = t46->mX.mX
    [12ULL] * FOC_test_Converter_Three_Phase_Q4_ideal_switch_v * 0.001;
  FOC_test_Converter_Three_Phase_Q5_i = t46->mX.mX[10ULL] + t46->mX.mX[14ULL];
  FOC_test_Converter_Three_Phase_Q5_ideal_switch_v = (-t46->mX.mX[13ULL] +
    t46->mX.mX[6ULL]) + 100.0;
  FOC_test_Converter_Three_Phase_Q5_ideal_switch_power_dissipated =
    FOC_test_Converter_Three_Phase_Q5_i *
    FOC_test_Converter_Three_Phase_Q5_ideal_switch_v * 0.001;
  FOC_test_Converter_Three_Phase_Q6_ideal_switch_v = -t46->mX.mX[6ULL] +
    t46->mX.mX[13ULL];
  FOC_test_Converter_Three_Phase_Q6_ideal_switch_power_dissipated = t46->mX.mX
    [14ULL] * FOC_test_Converter_Three_Phase_Q6_ideal_switch_v * 0.001;
  t44 = -t46->mX.mX[9ULL] - t46->mX.mX[10ULL];
  t26 = -t46->mU.mX[6ULL] + t46->mX.mX[15ULL];
  for (t15 = 0ULL; t15 < 12ULL; t15++) {
    out->mOBS_ACT.mX[t15] = FOC_test_Converter_Three_Phase_G_V[t15];
  }

  out->mOBS_ACT.mX[12ULL] = t46->mU.mX[0ULL];
  out->mOBS_ACT.mX[13ULL] = 0.0;
  out->mOBS_ACT.mX[14ULL] = t46->mU.mX[0ULL];
  out->mOBS_ACT.mX[15ULL] = t46->mU.mX[1ULL];
  out->mOBS_ACT.mX[16ULL] = 0.0;
  out->mOBS_ACT.mX[17ULL] = t46->mU.mX[1ULL];
  out->mOBS_ACT.mX[18ULL] = t46->mU.mX[2ULL];
  out->mOBS_ACT.mX[19ULL] = 0.0;
  out->mOBS_ACT.mX[20ULL] = t46->mU.mX[2ULL];
  out->mOBS_ACT.mX[21ULL] = t46->mU.mX[3ULL];
  out->mOBS_ACT.mX[22ULL] = 0.0;
  out->mOBS_ACT.mX[23ULL] = t46->mU.mX[3ULL];
  out->mOBS_ACT.mX[24ULL] = t46->mU.mX[4ULL];
  out->mOBS_ACT.mX[25ULL] = 0.0;
  out->mOBS_ACT.mX[26ULL] = t46->mU.mX[4ULL];
  out->mOBS_ACT.mX[27ULL] = t46->mU.mX[5ULL];
  out->mOBS_ACT.mX[28ULL] = 0.0;
  out->mOBS_ACT.mX[29ULL] = t46->mU.mX[5ULL];
  for (t15 = 0ULL; t15 < 12ULL; t15++) {
    out->mOBS_ACT.mX[t15 + 30ULL] = ((_NeDynamicSystem*)(LC))->mField0[t15];
  }

  out->mOBS_ACT.mX[42ULL] = 0.0;
  out->mOBS_ACT.mX[43ULL] = 0.0;
  out->mOBS_ACT.mX[44ULL] = 0.0;
  out->mOBS_ACT.mX[45ULL] = 0.0;
  out->mOBS_ACT.mX[46ULL] = 0.0;
  out->mOBS_ACT.mX[47ULL] = 0.0;
  out->mOBS_ACT.mX[48ULL] = 0.0;
  out->mOBS_ACT.mX[49ULL] = 0.0;
  out->mOBS_ACT.mX[50ULL] = 0.0;
  out->mOBS_ACT.mX[51ULL] = 0.0;
  out->mOBS_ACT.mX[52ULL] = 0.0;
  out->mOBS_ACT.mX[53ULL] = 0.0;
  for (t15 = 0ULL; t15 < 12ULL; t15++) {
    out->mOBS_ACT.mX[t15 + 54ULL] = FOC_test_Converter_Three_Phase_G_V[t15];
  }

  out->mOBS_ACT.mX[66ULL] = 0.0;
  out->mOBS_ACT.mX[67ULL] = 0.0;
  out->mOBS_ACT.mX[68ULL] = 0.0;
  out->mOBS_ACT.mX[69ULL] = t46->mX.mX[6ULL] + 100.0;
  out->mOBS_ACT.mX[70ULL] = t46->mU.mX[0ULL];
  out->mOBS_ACT.mX[71ULL] = 0.0;
  out->mOBS_ACT.mX[72ULL] = t46->mX.mX[7ULL];
  out->mOBS_ACT.mX[73ULL] = FOC_test_Converter_Three_Phase_Q1_i;
  out->mOBS_ACT.mX[74ULL] = FOC_test_Converter_Three_Phase_Q1_i;
  out->mOBS_ACT.mX[75ULL] = t46->mX.mX[7ULL];
  out->mOBS_ACT.mX[76ULL] = t46->mX.mX[6ULL] + 100.0;
  out->mOBS_ACT.mX[77ULL] =
    FOC_test_Converter_Three_Phase_Q1_ideal_switch_power_dissipated * 1000.0;
  out->mOBS_ACT.mX[78ULL] = FOC_test_Converter_Three_Phase_Q1_ideal_switch_v;
  out->mOBS_ACT.mX[79ULL] = t46->mU.mX[0ULL];
  out->mOBS_ACT.mX[80ULL] =
    FOC_test_Converter_Three_Phase_Q1_ideal_switch_power_dissipated * 1000.0;
  out->mOBS_ACT.mX[81ULL] = FOC_test_Converter_Three_Phase_Q1_ideal_switch_v;
  out->mOBS_ACT.mX[82ULL] = t46->mU.mX[0ULL];
  out->mOBS_ACT.mX[83ULL] = t46->mX.mX[7ULL];
  out->mOBS_ACT.mX[84ULL] = t46->mU.mX[1ULL];
  out->mOBS_ACT.mX[85ULL] = 0.0;
  out->mOBS_ACT.mX[86ULL] = t46->mX.mX[6ULL];
  out->mOBS_ACT.mX[87ULL] = t46->mX.mX[8ULL];
  out->mOBS_ACT.mX[88ULL] = t46->mX.mX[8ULL];
  out->mOBS_ACT.mX[89ULL] = t46->mX.mX[6ULL];
  out->mOBS_ACT.mX[90ULL] = t46->mX.mX[7ULL];
  out->mOBS_ACT.mX[91ULL] =
    FOC_test_Converter_Three_Phase_Q2_ideal_switch_power_dissipated * 1000.0;
  out->mOBS_ACT.mX[92ULL] = FOC_test_Converter_Three_Phase_Q2_ideal_switch_v;
  out->mOBS_ACT.mX[93ULL] = t46->mU.mX[1ULL];
  out->mOBS_ACT.mX[94ULL] =
    FOC_test_Converter_Three_Phase_Q2_ideal_switch_power_dissipated * 1000.0;
  out->mOBS_ACT.mX[95ULL] = FOC_test_Converter_Three_Phase_Q2_ideal_switch_v;
  out->mOBS_ACT.mX[96ULL] = t46->mU.mX[1ULL];
  out->mOBS_ACT.mX[97ULL] = t46->mX.mX[6ULL] + 100.0;
  out->mOBS_ACT.mX[98ULL] = t46->mU.mX[2ULL];
  out->mOBS_ACT.mX[99ULL] = 0.0;
  out->mOBS_ACT.mX[100ULL] = t46->mX.mX[11ULL];
  out->mOBS_ACT.mX[101ULL] = FOC_test_Converter_Three_Phase_Q3_i;
  out->mOBS_ACT.mX[102ULL] = FOC_test_Converter_Three_Phase_Q3_i;
  out->mOBS_ACT.mX[103ULL] = t46->mX.mX[11ULL];
  out->mOBS_ACT.mX[104ULL] = t46->mX.mX[6ULL] + 100.0;
  out->mOBS_ACT.mX[105ULL] =
    FOC_test_Converter_Three_Phase_Q3_ideal_switch_power_dissipated * 1000.0;
  out->mOBS_ACT.mX[106ULL] = FOC_test_Converter_Three_Phase_Q3_ideal_switch_v;
  out->mOBS_ACT.mX[107ULL] = t46->mU.mX[2ULL];
  out->mOBS_ACT.mX[108ULL] =
    FOC_test_Converter_Three_Phase_Q3_ideal_switch_power_dissipated * 1000.0;
  out->mOBS_ACT.mX[109ULL] = FOC_test_Converter_Three_Phase_Q3_ideal_switch_v;
  out->mOBS_ACT.mX[110ULL] = t46->mU.mX[2ULL];
  out->mOBS_ACT.mX[111ULL] = t46->mX.mX[11ULL];
  out->mOBS_ACT.mX[112ULL] = t46->mU.mX[3ULL];
  out->mOBS_ACT.mX[113ULL] = 0.0;
  out->mOBS_ACT.mX[114ULL] = t46->mX.mX[6ULL];
  out->mOBS_ACT.mX[115ULL] = t46->mX.mX[12ULL];
  out->mOBS_ACT.mX[116ULL] = t46->mX.mX[12ULL];
  out->mOBS_ACT.mX[117ULL] = t46->mX.mX[6ULL];
  out->mOBS_ACT.mX[118ULL] = t46->mX.mX[11ULL];
  out->mOBS_ACT.mX[119ULL] =
    FOC_test_Converter_Three_Phase_Q4_ideal_switch_power_dissipated * 1000.0;
  out->mOBS_ACT.mX[120ULL] = FOC_test_Converter_Three_Phase_Q4_ideal_switch_v;
  out->mOBS_ACT.mX[121ULL] = t46->mU.mX[3ULL];
  out->mOBS_ACT.mX[122ULL] =
    FOC_test_Converter_Three_Phase_Q4_ideal_switch_power_dissipated * 1000.0;
  out->mOBS_ACT.mX[123ULL] = FOC_test_Converter_Three_Phase_Q4_ideal_switch_v;
  out->mOBS_ACT.mX[124ULL] = t46->mU.mX[3ULL];
  out->mOBS_ACT.mX[125ULL] = t46->mX.mX[6ULL] + 100.0;
  out->mOBS_ACT.mX[126ULL] = t46->mU.mX[4ULL];
  out->mOBS_ACT.mX[127ULL] = 0.0;
  out->mOBS_ACT.mX[128ULL] = t46->mX.mX[13ULL];
  out->mOBS_ACT.mX[129ULL] = FOC_test_Converter_Three_Phase_Q5_i;
  out->mOBS_ACT.mX[130ULL] = FOC_test_Converter_Three_Phase_Q5_i;
  out->mOBS_ACT.mX[131ULL] = t46->mX.mX[13ULL];
  out->mOBS_ACT.mX[132ULL] = t46->mX.mX[6ULL] + 100.0;
  out->mOBS_ACT.mX[133ULL] =
    FOC_test_Converter_Three_Phase_Q5_ideal_switch_power_dissipated * 1000.0;
  out->mOBS_ACT.mX[134ULL] = FOC_test_Converter_Three_Phase_Q5_ideal_switch_v;
  out->mOBS_ACT.mX[135ULL] = t46->mU.mX[4ULL];
  out->mOBS_ACT.mX[136ULL] =
    FOC_test_Converter_Three_Phase_Q5_ideal_switch_power_dissipated * 1000.0;
  out->mOBS_ACT.mX[137ULL] = FOC_test_Converter_Three_Phase_Q5_ideal_switch_v;
  out->mOBS_ACT.mX[138ULL] = t46->mU.mX[4ULL];
  out->mOBS_ACT.mX[139ULL] = t46->mX.mX[13ULL];
  out->mOBS_ACT.mX[140ULL] = t46->mU.mX[5ULL];
  out->mOBS_ACT.mX[141ULL] = 0.0;
  out->mOBS_ACT.mX[142ULL] = t46->mX.mX[6ULL];
  out->mOBS_ACT.mX[143ULL] = t46->mX.mX[14ULL];
  out->mOBS_ACT.mX[144ULL] = t46->mX.mX[14ULL];
  out->mOBS_ACT.mX[145ULL] = t46->mX.mX[6ULL];
  out->mOBS_ACT.mX[146ULL] = t46->mX.mX[13ULL];
  out->mOBS_ACT.mX[147ULL] =
    FOC_test_Converter_Three_Phase_Q6_ideal_switch_power_dissipated * 1000.0;
  out->mOBS_ACT.mX[148ULL] = FOC_test_Converter_Three_Phase_Q6_ideal_switch_v;
  out->mOBS_ACT.mX[149ULL] = t46->mU.mX[5ULL];
  out->mOBS_ACT.mX[150ULL] =
    FOC_test_Converter_Three_Phase_Q6_ideal_switch_power_dissipated * 1000.0;
  out->mOBS_ACT.mX[151ULL] = FOC_test_Converter_Three_Phase_Q6_ideal_switch_v;
  out->mOBS_ACT.mX[152ULL] = t46->mU.mX[5ULL];
  out->mOBS_ACT.mX[153ULL] = t46->mX.mX[7ULL];
  out->mOBS_ACT.mX[154ULL] = t46->mX.mX[11ULL];
  out->mOBS_ACT.mX[155ULL] = t46->mX.mX[13ULL];
  out->mOBS_ACT.mX[156ULL] = t46->mX.mX[6ULL];
  out->mOBS_ACT.mX[157ULL] = t46->mX.mX[6ULL] + 100.0;
  out->mOBS_ACT.mX[158ULL] = t44;
  out->mOBS_ACT.mX[159ULL] = t46->mX.mX[9ULL];
  out->mOBS_ACT.mX[160ULL] = t46->mX.mX[10ULL];
  out->mOBS_ACT.mX[161ULL] = t46->mX.mX[7ULL];
  out->mOBS_ACT.mX[162ULL] = t46->mX.mX[7ULL];
  out->mOBS_ACT.mX[163ULL] = t46->mX.mX[11ULL];
  out->mOBS_ACT.mX[164ULL] = t46->mX.mX[11ULL];
  out->mOBS_ACT.mX[165ULL] = t46->mX.mX[13ULL];
  out->mOBS_ACT.mX[166ULL] = t46->mX.mX[13ULL];
  out->mOBS_ACT.mX[167ULL] = t44;
  out->mOBS_ACT.mX[168ULL] = t46->mX.mX[9ULL];
  out->mOBS_ACT.mX[169ULL] = t46->mX.mX[10ULL];
  out->mOBS_ACT.mX[170ULL] = t44;
  out->mOBS_ACT.mX[171ULL] = t46->mX.mX[9ULL];
  out->mOBS_ACT.mX[172ULL] = t46->mX.mX[10ULL];
  for (t15 = 0ULL; t15 < 12ULL; t15++) {
    out->mOBS_ACT.mX[t15 + 173ULL] = FOC_test_Converter_Three_Phase_G_V[t15];
  }

  out->mOBS_ACT.mX[185ULL] = t46->mU.mX[0ULL];
  out->mOBS_ACT.mX[186ULL] = t46->mU.mX[1ULL];
  out->mOBS_ACT.mX[187ULL] = t46->mU.mX[2ULL];
  out->mOBS_ACT.mX[188ULL] = t46->mU.mX[3ULL];
  out->mOBS_ACT.mX[189ULL] = t46->mU.mX[4ULL];
  out->mOBS_ACT.mX[190ULL] = t46->mU.mX[5ULL];
  out->mOBS_ACT.mX[191ULL] = 0.0;
  out->mOBS_ACT.mX[192ULL] = t46->mU.mX[0ULL];
  out->mOBS_ACT.mX[193ULL] = 0.0;
  out->mOBS_ACT.mX[194ULL] = t46->mU.mX[1ULL];
  out->mOBS_ACT.mX[195ULL] = 0.0;
  out->mOBS_ACT.mX[196ULL] = t46->mU.mX[2ULL];
  out->mOBS_ACT.mX[197ULL] = 0.0;
  out->mOBS_ACT.mX[198ULL] = t46->mU.mX[3ULL];
  out->mOBS_ACT.mX[199ULL] = 0.0;
  out->mOBS_ACT.mX[200ULL] = t46->mU.mX[4ULL];
  out->mOBS_ACT.mX[201ULL] = 0.0;
  out->mOBS_ACT.mX[202ULL] = t46->mU.mX[5ULL];
  for (t15 = 0ULL; t15 < 12ULL; t15++) {
    out->mOBS_ACT.mX[t15 + 203ULL] = -((_NeDynamicSystem*)(LC))->mField0[t15];
  }

  out->mOBS_ACT.mX[215ULL] = 0.0;
  out->mOBS_ACT.mX[216ULL] = 0.0;
  out->mOBS_ACT.mX[217ULL] = 0.0;
  out->mOBS_ACT.mX[218ULL] = 0.0;
  for (t15 = 0ULL; t15 < 12ULL; t15++) {
    out->mOBS_ACT.mX[t15 + 219ULL] = FOC_test_Converter_Three_Phase_G_V[t15];
  }

  out->mOBS_ACT.mX[231ULL] = t46->mX.mX[1ULL];
  out->mOBS_ACT.mX[232ULL] = 0.0;
  out->mOBS_ACT.mX[233ULL] = t46->mX.mX[0ULL];
  out->mOBS_ACT.mX[234ULL] = t46->mX.mX[0ULL];
  out->mOBS_ACT.mX[235ULL] = 0.0;
  out->mOBS_ACT.mX[236ULL] = t46->mX.mX[1ULL];
  out->mOBS_ACT.mX[237ULL] = t46->mX.mX[1ULL];
  out->mOBS_ACT.mX[238ULL] = t46->mX.mX[0ULL];
  out->mOBS_ACT.mX[239ULL] = t46->mX.mX[0ULL];
  out->mOBS_ACT.mX[240ULL] = t46->mX.mX[0ULL];
  out->mOBS_ACT.mX[241ULL] = t26;
  out->mOBS_ACT.mX[242ULL] = t26;
  out->mOBS_ACT.mX[243ULL] = t26;
  out->mOBS_ACT.mX[244ULL] = 0.0;
  out->mOBS_ACT.mX[245ULL] = t46->mX.mX[0ULL];
  out->mOBS_ACT.mX[246ULL] = t46->mU.mX[6ULL];
  out->mOBS_ACT.mX[247ULL] = -t46->mU.mX[6ULL];
  out->mOBS_ACT.mX[248ULL] = -t46->mX.mX[0ULL];
  out->mOBS_ACT.mX[249ULL] = t46->mX.mX[0ULL];
  out->mOBS_ACT.mX[250ULL] = t46->mX.mX[0ULL];
  out->mOBS_ACT.mX[251ULL] = t46->mX.mX[15ULL];
  out->mOBS_ACT.mX[252ULL] = t46->mX.mX[0ULL];
  out->mOBS_ACT.mX[253ULL] = 0.0;
  out->mOBS_ACT.mX[254ULL] = 0.0;
  out->mOBS_ACT.mX[255ULL] = 0.0;
  out->mOBS_ACT.mX[256ULL] = 0.0;
  out->mOBS_ACT.mX[257ULL] = 0.0;
  out->mOBS_ACT.mX[258ULL] = 0.0;
  out->mOBS_ACT.mX[259ULL] = 0.0;
  out->mOBS_ACT.mX[260ULL] = 0.0;
  out->mOBS_ACT.mX[261ULL] = 0.0;
  out->mOBS_ACT.mX[262ULL] = 0.0;
  out->mOBS_ACT.mX[263ULL] = 0.0;
  out->mOBS_ACT.mX[264ULL] = 0.0;
  out->mOBS_ACT.mX[265ULL] = t46->mX.mX[0ULL];
  out->mOBS_ACT.mX[266ULL] = 0.18;
  out->mOBS_ACT.mX[267ULL] = 0.18;
  out->mOBS_ACT.mX[268ULL] = 0.18;
  out->mOBS_ACT.mX[269ULL] = 0.0;
  out->mOBS_ACT.mX[270ULL] = 0.0;
  out->mOBS_ACT.mX[271ULL] = t46->mX.mX[7ULL];
  out->mOBS_ACT.mX[272ULL] = 0.0;
  out->mOBS_ACT.mX[273ULL] = 0.0;
  out->mOBS_ACT.mX[274ULL] = t46->mX.mX[2ULL] * 57.295779513082323;
  out->mOBS_ACT.mX[275ULL] = t46->mX.mX[3ULL] * 9.5492965855137211;
  out->mOBS_ACT.mX[276ULL] = t46->mX.mX[11ULL];
  out->mOBS_ACT.mX[277ULL] = 0.0;
  out->mOBS_ACT.mX[278ULL] = 0.0;
  out->mOBS_ACT.mX[279ULL] = t46->mX.mX[13ULL];
  out->mOBS_ACT.mX[280ULL] = 0.0;
  out->mOBS_ACT.mX[281ULL] = 0.0;
  out->mOBS_ACT.mX[282ULL] = t46->mX.mX[16ULL];
  out->mOBS_ACT.mX[283ULL] = 1.0;
  out->mOBS_ACT.mX[284ULL] = t44;
  out->mOBS_ACT.mX[285ULL] = t46->mX.mX[9ULL];
  out->mOBS_ACT.mX[286ULL] = t46->mX.mX[10ULL];
  out->mOBS_ACT.mX[287ULL] = t46->mX.mX[4ULL];
  out->mOBS_ACT.mX[288ULL] = 0.0;
  out->mOBS_ACT.mX[289ULL] = t46->mX.mX[5ULL];
  out->mOBS_ACT.mX[290ULL] = 0.0;
  out->mOBS_ACT.mX[291ULL] = -t26;
  out->mOBS_ACT.mX[292ULL] = 0.0;
  out->mOBS_ACT.mX[293ULL] = t46->mX.mX[7ULL];
  out->mOBS_ACT.mX[294ULL] = t46->mX.mX[11ULL];
  out->mOBS_ACT.mX[295ULL] = t46->mX.mX[13ULL];
  out->mOBS_ACT.mX[296ULL] = t46->mU.mX[6ULL];
  out->mOBS_ACT.mX[297ULL] = (-t46->mX.mX[8ULL] - t46->mX.mX[12ULL]) -
    t46->mX.mX[14ULL];
  out->mOBS_ACT.mX[298ULL] = t46->mX.mX[6ULL];
  out->mOBS_ACT.mX[299ULL] = t46->mX.mX[6ULL] + 100.0;
  out->mOBS_ACT.mX[300ULL] = 100.0;
  (void)LC;
  (void)out;
  return 0;
}
