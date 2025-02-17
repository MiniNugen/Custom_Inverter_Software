/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Main_Firmware/FOC test/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Main_Firmware_bbbdb992_1_ds_sys_struct.h"
#include "Main_Firmware_bbbdb992_1_ds_f.h"
#include "Main_Firmware_bbbdb992_1_ds.h"
#include "Main_Firmware_bbbdb992_1_ds_externals.h"
#include "Main_Firmware_bbbdb992_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Main_Firmware_bbbdb992_1_ds_f(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t30, NeDsMethodOutput *out)
{
  real_T FOC_test_Converter_Three_Phase_Q4_ideal_switch_v;
  real_T FOC_test_Converter_Three_Phase_Q5_i;
  real_T FOC_test_Converter_Three_Phase_Q5_ideal_switch_v;
  real_T FOC_test_Converter_Three_Phase_Q6_ideal_switch_v;
  real_T FOC_test_PMSM_psid;
  real_T FOC_test_PMSM_v_d;
  real_T t0;
  real_T t1;
  real_T t10;
  real_T t16;
  real_T t19;
  real_T t2;
  real_T t20;
  real_T t21;
  real_T t22;
  real_T t25;
  real_T t27;
  real_T t29;
  real_T t3;
  real_T t4;
  real_T t5;
  (void)LC;
  t1 = (-t30->mX.mX[9ULL] - t30->mX.mX[10ULL]) + t30->mX.mX[8ULL];
  t2 = (-t30->mX.mX[7ULL] + t30->mX.mX[6ULL]) + 100.0;
  t3 = -t30->mX.mX[6ULL] + t30->mX.mX[7ULL];
  t5 = t30->mX.mX[9ULL] + t30->mX.mX[12ULL];
  t29 = (-t30->mX.mX[11ULL] + t30->mX.mX[6ULL]) + 100.0;
  FOC_test_Converter_Three_Phase_Q4_ideal_switch_v = -t30->mX.mX[6ULL] +
    t30->mX.mX[11ULL];
  FOC_test_Converter_Three_Phase_Q5_i = t30->mX.mX[10ULL] + t30->mX.mX[14ULL];
  FOC_test_Converter_Three_Phase_Q5_ideal_switch_v = (-t30->mX.mX[13ULL] +
    t30->mX.mX[6ULL]) + 100.0;
  FOC_test_Converter_Three_Phase_Q6_ideal_switch_v = -t30->mX.mX[6ULL] +
    t30->mX.mX[13ULL];
  t16 = cos(t30->mX.mX[2ULL]) * 0.66666666666666663;
  t25 = cos(t30->mX.mX[2ULL] - 2.0943951023931953) * 0.66666666666666663;
  t27 = cos(t30->mX.mX[2ULL] + 2.0943951023931953) * 0.66666666666666663;
  t19 = -sin(t30->mX.mX[2ULL]) * 0.66666666666666663;
  t20 = -sin(t30->mX.mX[2ULL] - 2.0943951023931953) * 0.66666666666666663;
  t21 = -sin(t30->mX.mX[2ULL] + 2.0943951023931953) * 0.66666666666666663;
  FOC_test_PMSM_psid = t30->mX.mX[4ULL] * 0.000395 + 0.1194;
  t10 = t30->mX.mX[5ULL] * 0.000435;
  t22 = t30->mX.mX[7ULL] - (-t30->mX.mX[9ULL] - t30->mX.mX[10ULL]) * 0.18;
  t0 = t30->mX.mX[11ULL] - t30->mX.mX[9ULL] * 0.18;
  t4 = t30->mX.mX[13ULL] - t30->mX.mX[10ULL] * 0.18;
  FOC_test_PMSM_v_d = (t16 * t22 + t25 * t0) + t27 * t4;
  t19 = (t19 * t22 + t20 * t0) + t21 * t4;
  t22 = cos(t30->mX.mX[2ULL]);
  t16 = -sin(t30->mX.mX[2ULL]);
  t20 = cos(t30->mX.mX[2ULL] - 2.0943951023931953);
  t25 = -sin(t30->mX.mX[2ULL] - 2.0943951023931953);
  t21 = cos(t30->mX.mX[2ULL] + 2.0943951023931953);
  t27 = -sin(t30->mX.mX[2ULL] + 2.0943951023931953);
  if (t30->mM.mX[0ULL] != 0) {
    out->mF.mX[6ULL] = t2 - t1 * 0.001;
  } else {
    out->mF.mX[6ULL] = t2 * 1.0E-6 - t1;
  }

  if (t30->mM.mX[1ULL] != 0) {
    out->mF.mX[7ULL] = t3 - t30->mX.mX[8ULL] * 0.001;
  } else {
    out->mF.mX[7ULL] = t3 * 1.0E-6 - t30->mX.mX[8ULL];
  }

  if (t30->mM.mX[2ULL] != 0) {
    out->mF.mX[8ULL] = t29 - t5 * 0.001;
  } else {
    out->mF.mX[8ULL] = t29 * 1.0E-6 - t5;
  }

  if (t30->mM.mX[3ULL] != 0) {
    out->mF.mX[9ULL] = FOC_test_Converter_Three_Phase_Q4_ideal_switch_v -
      t30->mX.mX[12ULL] * 0.001;
  } else {
    out->mF.mX[9ULL] = FOC_test_Converter_Three_Phase_Q4_ideal_switch_v * 1.0E-6
      - t30->mX.mX[12ULL];
  }

  if (t30->mM.mX[4ULL] != 0) {
    out->mF.mX[10ULL] = FOC_test_Converter_Three_Phase_Q5_ideal_switch_v -
      FOC_test_Converter_Three_Phase_Q5_i * 0.001;
  } else {
    out->mF.mX[10ULL] = FOC_test_Converter_Three_Phase_Q5_ideal_switch_v *
      1.0E-6 - FOC_test_Converter_Three_Phase_Q5_i;
  }

  if (t30->mM.mX[5ULL] != 0) {
    out->mF.mX[11ULL] = FOC_test_Converter_Three_Phase_Q6_ideal_switch_v -
      t30->mX.mX[14ULL] * 0.001;
  } else {
    out->mF.mX[11ULL] = FOC_test_Converter_Three_Phase_Q6_ideal_switch_v *
      1.0E-6 - t30->mX.mX[14ULL];
  }

  out->mF.mX[0ULL] = -0.0;
  out->mF.mX[1ULL] = -0.0;
  out->mF.mX[2ULL] = -0.0;
  out->mF.mX[3ULL] = -((FOC_test_PMSM_v_d - (-(t30->mX.mX[3ULL] * t10))) /
                       0.66666666666666663);
  out->mF.mX[4ULL] = -((t19 - t30->mX.mX[3ULL] * FOC_test_PMSM_psid) /
                       0.57735026918962573);
  out->mF.mX[5ULL] = -0.0;
  out->mF.mX[12ULL] = 0.0;
  out->mF.mX[13ULL] = -((t30->mX.mX[5ULL] * FOC_test_PMSM_psid - t30->mX.mX[4ULL]
    * t10) * 1.5);
  out->mF.mX[14ULL] = -(t22 * t30->mX.mX[4ULL] + t16 * t30->mX.mX[5ULL]);
  out->mF.mX[15ULL] = -(t20 * t30->mX.mX[4ULL] + t25 * t30->mX.mX[5ULL]);
  out->mF.mX[16ULL] = -(t21 * t30->mX.mX[4ULL] + t27 * t30->mX.mX[5ULL]);
  (void)LC;
  (void)out;
  return 0;
}
