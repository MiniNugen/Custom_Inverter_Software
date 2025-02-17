/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Main_Firmware/FOC test/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Main_Firmware_bbbdb992_1_ds_sys_struct.h"
#include "Main_Firmware_bbbdb992_1_ds_dxy_p.h"
#include "Main_Firmware_bbbdb992_1_ds.h"
#include "Main_Firmware_bbbdb992_1_ds_externals.h"
#include "Main_Firmware_bbbdb992_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Main_Firmware_bbbdb992_1_ds_dxy_p(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_1[18] = { 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 5, 8, 8, 8, 8,
    8, 9, 9 };

  static int32_T _cg_const_2[9] = { 4, 3, 0, 1, 2, 0, 1, 2, 5 };

  (void)t1;
  (void)LC;
  out->mDXY_P.mNumCol = 17ULL;
  out->mDXY_P.mNumRow = 6ULL;
  out->mDXY_P.mJc[0] = _cg_const_1[0];
  out->mDXY_P.mJc[1] = _cg_const_1[1];
  out->mDXY_P.mJc[2] = _cg_const_1[2];
  out->mDXY_P.mJc[3] = _cg_const_1[3];
  out->mDXY_P.mJc[4] = _cg_const_1[4];
  out->mDXY_P.mJc[5] = _cg_const_1[5];
  out->mDXY_P.mJc[6] = _cg_const_1[6];
  out->mDXY_P.mJc[7] = _cg_const_1[7];
  out->mDXY_P.mJc[8] = _cg_const_1[8];
  out->mDXY_P.mJc[9] = _cg_const_1[9];
  out->mDXY_P.mJc[10] = _cg_const_1[10];
  out->mDXY_P.mJc[11] = _cg_const_1[11];
  out->mDXY_P.mJc[12] = _cg_const_1[12];
  out->mDXY_P.mJc[13] = _cg_const_1[13];
  out->mDXY_P.mJc[14] = _cg_const_1[14];
  out->mDXY_P.mJc[15] = _cg_const_1[15];
  out->mDXY_P.mJc[16] = _cg_const_1[16];
  out->mDXY_P.mJc[17] = _cg_const_1[17];
  out->mDXY_P.mIr[0] = _cg_const_2[0];
  out->mDXY_P.mIr[1] = _cg_const_2[1];
  out->mDXY_P.mIr[2] = _cg_const_2[2];
  out->mDXY_P.mIr[3] = _cg_const_2[3];
  out->mDXY_P.mIr[4] = _cg_const_2[4];
  out->mDXY_P.mIr[5] = _cg_const_2[5];
  out->mDXY_P.mIr[6] = _cg_const_2[6];
  out->mDXY_P.mIr[7] = _cg_const_2[7];
  out->mDXY_P.mIr[8] = _cg_const_2[8];
  (void)LC;
  (void)out;
  return 0;
}
