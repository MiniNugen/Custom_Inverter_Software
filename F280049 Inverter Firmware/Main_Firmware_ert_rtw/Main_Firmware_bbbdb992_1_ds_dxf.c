/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Main_Firmware/FOC test/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Main_Firmware_bbbdb992_1_ds_sys_struct.h"
#include "Main_Firmware_bbbdb992_1_ds_dxf.h"
#include "Main_Firmware_bbbdb992_1_ds.h"
#include "Main_Firmware_bbbdb992_1_ds_externals.h"
#include "Main_Firmware_bbbdb992_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Main_Firmware_bbbdb992_1_ds_dxf(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t108, NeDsMethodOutput *out)
{
  real_T t27[6];
  real_T t23[5];
  real_T t25[5];
  real_T t26[5];
  real_T t28[4];
  real_T t30[4];
  real_T t31[4];
  real_T t32[4];
  real_T t34[4];
  real_T FOC_test_PMSM_psid;
  real_T t100;
  real_T t102;
  real_T t107;
  real_T t15;
  real_T t18;
  real_T t59;
  real_T t64;
  real_T t65;
  real_T t66;
  real_T t67;
  real_T t68;
  real_T t69;
  real_T t70;
  real_T t71;
  real_T t72;
  real_T t73;
  real_T t74;
  real_T t75;
  real_T t79;
  real_T t80;
  real_T t81;
  real_T t82;
  real_T t83;
  real_T t84;
  real_T t96;
  real_T t98;
  size_t t41;
  (void)LC;
  t64 = cos(t108->mX.mX[2ULL]) * 0.66666666666666663;
  t65 = cos(t108->mX.mX[2ULL] - 2.0943951023931953) * 0.66666666666666663;
  t66 = cos(t108->mX.mX[2ULL] + 2.0943951023931953) * 0.66666666666666663;
  t67 = -sin(t108->mX.mX[2ULL]) * 0.66666666666666663;
  t68 = -sin(t108->mX.mX[2ULL] - 2.0943951023931953) * 0.66666666666666663;
  t69 = -sin(t108->mX.mX[2ULL] + 2.0943951023931953) * 0.66666666666666663;
  FOC_test_PMSM_psid = t108->mX.mX[4ULL] * 0.000395 + 0.1194;
  t107 = t108->mX.mX[5ULL] * 0.000435;
  t59 = t108->mX.mX[7ULL] - (-t108->mX.mX[9ULL] - t108->mX.mX[10ULL]) * 0.18;
  t102 = t108->mX.mX[11ULL] - t108->mX.mX[9ULL] * 0.18;
  t100 = t108->mX.mX[13ULL] - t108->mX.mX[10ULL] * 0.18;
  t70 = cos(t108->mX.mX[2ULL]);
  t71 = -sin(t108->mX.mX[2ULL]);
  t72 = cos(t108->mX.mX[2ULL] - 2.0943951023931953);
  t73 = -sin(t108->mX.mX[2ULL] - 2.0943951023931953);
  t74 = cos(t108->mX.mX[2ULL] + 2.0943951023931953);
  t75 = -sin(t108->mX.mX[2ULL] + 2.0943951023931953);
  t79 = -sin(t108->mX.mX[2ULL]) * 0.66666666666666663;
  t80 = -sin(t108->mX.mX[2ULL] - 2.0943951023931953) * 0.66666666666666663;
  t81 = -sin(t108->mX.mX[2ULL] + 2.0943951023931953) * 0.66666666666666663;
  t82 = -cos(t108->mX.mX[2ULL]) * 0.66666666666666663;
  t83 = -cos(t108->mX.mX[2ULL] - 2.0943951023931953) * 0.66666666666666663;
  t84 = -cos(t108->mX.mX[2ULL] + 2.0943951023931953) * 0.66666666666666663;
  t98 = (t79 * t59 + t80 * t102) + t81 * t100;
  t79 = t64 * 0.18 + t65 * -0.18;
  t80 = t64;
  t81 = t64 * 0.18 + t66 * -0.18;
  t64 = t66;
  t66 = t65;
  t65 = (t82 * t59 + t83 * t102) + t84 * t100;
  t59 = -sin(t108->mX.mX[2ULL]);
  t102 = -cos(t108->mX.mX[2ULL]);
  t100 = -sin(t108->mX.mX[2ULL] - 2.0943951023931953);
  t82 = -cos(t108->mX.mX[2ULL] - 2.0943951023931953);
  t83 = -sin(t108->mX.mX[2ULL] + 2.0943951023931953);
  t96 = -cos(t108->mX.mX[2ULL] + 2.0943951023931953);
  if (t108->mM.mX[0ULL] != 0) {
    t27[0ULL] = 1.0;
  } else {
    t27[0ULL] = 1.0E-6;
  }

  if (t108->mM.mX[1ULL] != 0) {
    t27[1ULL] = -1.0;
  } else {
    t27[1ULL] = -1.0E-6;
  }

  if (t108->mM.mX[2ULL] != 0) {
    t27[2ULL] = 1.0;
  } else {
    t27[2ULL] = 1.0E-6;
  }

  if (t108->mM.mX[3ULL] != 0) {
    t27[3ULL] = -1.0;
  } else {
    t27[3ULL] = -1.0E-6;
  }

  if (t108->mM.mX[4ULL] != 0) {
    t27[4ULL] = 1.0;
  } else {
    t27[4ULL] = 1.0E-6;
  }

  if (t108->mM.mX[5ULL] != 0) {
    t27[5ULL] = -1.0;
  } else {
    t27[5ULL] = -1.0E-6;
  }

  if (t108->mM.mX[0ULL] != 0) {
    t28[2ULL] = -1.0;
  } else {
    t28[2ULL] = -1.0E-6;
  }

  if (t108->mM.mX[1ULL] != 0) {
    t28[3ULL] = 1.0;
  } else {
    t28[3ULL] = 1.0E-6;
  }

  if (t108->mM.mX[0ULL] != 0) {
    t84 = -0.001;
  } else {
    t84 = -1.0;
  }

  if (t108->mM.mX[0ULL] != 0) {
    t30[2ULL] = 0.001;
  } else {
    t30[2ULL] = 1.0;
  }

  if (t108->mM.mX[2ULL] != 0) {
    t30[3ULL] = -0.001;
  } else {
    t30[3ULL] = -1.0;
  }

  if (t108->mM.mX[0ULL] != 0) {
    t31[2ULL] = 0.001;
  } else {
    t31[2ULL] = 1.0;
  }

  if (t108->mM.mX[4ULL] != 0) {
    t31[3ULL] = -0.001;
  } else {
    t31[3ULL] = -1.0;
  }

  if (t108->mM.mX[2ULL] != 0) {
    t32[2ULL] = -1.0;
  } else {
    t32[2ULL] = -1.0E-6;
  }

  if (t108->mM.mX[3ULL] != 0) {
    t32[3ULL] = 1.0;
  } else {
    t32[3ULL] = 1.0E-6;
  }

  if (t108->mM.mX[2ULL] != 0) {
    t15 = -0.001;
  } else {
    t15 = -1.0;
  }

  if (t108->mM.mX[4ULL] != 0) {
    t34[2ULL] = -1.0;
  } else {
    t34[2ULL] = -1.0E-6;
  }

  if (t108->mM.mX[5ULL] != 0) {
    t34[3ULL] = 1.0;
  } else {
    t34[3ULL] = 1.0E-6;
  }

  if (t108->mM.mX[4ULL] != 0) {
    t18 = -0.001;
  } else {
    t18 = -1.0;
  }

  t23[0ULL] = -(t98 / 0.66666666666666663);
  t23[1ULL] = -(t65 / 0.57735026918962573);
  t23[2ULL] = -(t59 * t108->mX.mX[4ULL] + t102 * t108->mX.mX[5ULL]);
  t23[3ULL] = -(t100 * t108->mX.mX[4ULL] + t82 * t108->mX.mX[5ULL]);
  t23[4ULL] = -(t83 * t108->mX.mX[4ULL] + t96 * t108->mX.mX[5ULL]);
  t25[0ULL] = -(-(t108->mX.mX[3ULL] * 0.000395) / 0.57735026918962573);
  t25[1ULL] = -((t108->mX.mX[5ULL] * 0.000395 - t107) * 1.5);
  t25[2ULL] = -t70;
  t25[3ULL] = -t72;
  t25[4ULL] = -t74;
  t26[0ULL] = -(t108->mX.mX[3ULL] * 0.000435 / 0.66666666666666663);
  t26[1ULL] = -((FOC_test_PMSM_psid - t108->mX.mX[4ULL] * 0.000435) * 1.5);
  t26[2ULL] = -t71;
  t26[3ULL] = -t73;
  t26[4ULL] = -t75;
  t28[0ULL] = -(t80 / 0.66666666666666663);
  t28[1ULL] = -(t67 / 0.57735026918962573);
  t30[0ULL] = -(t79 / 0.66666666666666663);
  t30[1ULL] = -((t67 * 0.18 + t68 * -0.18) / 0.57735026918962573);
  t31[0ULL] = -(t81 / 0.66666666666666663);
  t31[1ULL] = -((t67 * 0.18 + t69 * -0.18) / 0.57735026918962573);
  t32[0ULL] = -(t66 / 0.66666666666666663);
  t32[1ULL] = -(t68 / 0.57735026918962573);
  t34[0ULL] = -(t64 / 0.66666666666666663);
  t34[1ULL] = -(t69 / 0.57735026918962573);
  for (t41 = 0ULL; t41 < 5ULL; t41++) {
    out->mDXF.mX[t41] = t23[t41];
  }

  out->mDXF.mX[5ULL] = -(t107 / 0.66666666666666663);
  out->mDXF.mX[6ULL] = -(-FOC_test_PMSM_psid / 0.57735026918962573);
  for (t41 = 0ULL; t41 < 5ULL; t41++) {
    out->mDXF.mX[t41 + 7ULL] = t25[t41];
  }

  for (t41 = 0ULL; t41 < 5ULL; t41++) {
    out->mDXF.mX[t41 + 12ULL] = t26[t41];
  }

  for (t41 = 0ULL; t41 < 6ULL; t41++) {
    out->mDXF.mX[t41 + 17ULL] = t27[t41];
  }

  for (t41 = 0ULL; t41 < 4ULL; t41++) {
    out->mDXF.mX[t41 + 23ULL] = t28[t41];
  }

  out->mDXF.mX[27ULL] = t84;
  out->mDXF.mX[28ULL] = t108->mM.mX[1ULL] != 0 ? -0.001 : -1.0;
  for (t41 = 0ULL; t41 < 4ULL; t41++) {
    out->mDXF.mX[t41 + 29ULL] = t30[t41];
  }

  for (t41 = 0ULL; t41 < 4ULL; t41++) {
    out->mDXF.mX[t41 + 33ULL] = t31[t41];
  }

  for (t41 = 0ULL; t41 < 4ULL; t41++) {
    out->mDXF.mX[t41 + 37ULL] = t32[t41];
  }

  out->mDXF.mX[41ULL] = t15;
  out->mDXF.mX[42ULL] = t108->mM.mX[3ULL] != 0 ? -0.001 : -1.0;
  for (t41 = 0ULL; t41 < 4ULL; t41++) {
    out->mDXF.mX[t41 + 43ULL] = t34[t41];
  }

  out->mDXF.mX[47ULL] = t18;
  out->mDXF.mX[48ULL] = t108->mM.mX[5ULL] != 0 ? -0.001 : -1.0;
  (void)LC;
  (void)out;
  return 0;
}
