/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Main_Firmware/FOC test/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Main_Firmware_bbbdb992_1_ds_sys_struct.h"
#include "Main_Firmware_bbbdb992_1_ds_nldv.h"
#include "Main_Firmware_bbbdb992_1_ds.h"
#include "Main_Firmware_bbbdb992_1_ds_externals.h"
#include "Main_Firmware_bbbdb992_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Main_Firmware_bbbdb992_1_ds_nldv(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static boolean_T _cg_const_1[17] = { false, false, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false
  };

  (void)t1;
  (void)LC;
  out->mNLDV.mX[0] = _cg_const_1[0];
  out->mNLDV.mX[1] = _cg_const_1[1];
  out->mNLDV.mX[2] = _cg_const_1[2];
  out->mNLDV.mX[3] = _cg_const_1[3];
  out->mNLDV.mX[4] = _cg_const_1[4];
  out->mNLDV.mX[5] = _cg_const_1[5];
  out->mNLDV.mX[6] = _cg_const_1[6];
  out->mNLDV.mX[7] = _cg_const_1[7];
  out->mNLDV.mX[8] = _cg_const_1[8];
  out->mNLDV.mX[9] = _cg_const_1[9];
  out->mNLDV.mX[10] = _cg_const_1[10];
  out->mNLDV.mX[11] = _cg_const_1[11];
  out->mNLDV.mX[12] = _cg_const_1[12];
  out->mNLDV.mX[13] = _cg_const_1[13];
  out->mNLDV.mX[14] = _cg_const_1[14];
  out->mNLDV.mX[15] = _cg_const_1[15];
  out->mNLDV.mX[16] = _cg_const_1[16];
  (void)LC;
  (void)out;
  return 0;
}
