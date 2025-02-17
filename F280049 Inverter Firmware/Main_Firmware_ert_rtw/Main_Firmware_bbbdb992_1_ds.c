/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Main_Firmware/FOC test/Solver Configuration'.
 */
/* Main_Firmware_bbbdb992_1_ds.c - body for module Main_Firmware_bbbdb992_1_ds */

#include "ne_ds.h"
#include "Main_Firmware_bbbdb992_1_ds_tdxy_p.h"
#include "Main_Firmware_bbbdb992_1_ds_nldv.h"
#include "Main_Firmware_bbbdb992_1_ds_obs_il.h"
#include "Main_Firmware_bbbdb992_1_ds_obs_all.h"
#include "Main_Firmware_bbbdb992_1_ds_obs_act.h"
#include "Main_Firmware_bbbdb992_1_ds_obs_exp.h"
#include "Main_Firmware_bbbdb992_1_ds_m_p.h"
#include "Main_Firmware_bbbdb992_1_ds_log.h"
#include "Main_Firmware_bbbdb992_1_ds_dxy_p.h"
#include "Main_Firmware_bbbdb992_1_ds_dnf_v_x.h"
#include "Main_Firmware_bbbdb992_1_ds_tdxf_p.h"
#include "Main_Firmware_bbbdb992_1_ds_a_p.h"
#include "Main_Firmware_bbbdb992_1_ds_dxf_p.h"
#include "Main_Firmware_bbbdb992_1_ds_dxf.h"
#include "Main_Firmware_bbbdb992_1_ds_f.h"
#include "Main_Firmware_bbbdb992_1_ds.h"
#include "ssc_ml_fun.h"
#include "Main_Firmware_bbbdb992_1_ds_external_struct.h"
#include "Main_Firmware_bbbdb992_1_ds_externals.h"
#include "Main_Firmware_bbbdb992_1_ds_sys_struct.h"

static int32_T ds_m(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                    NeDsMethodOutput *out);
static int32_T ds_vmm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dxm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_ddm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dum_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dum(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dtm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dpm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dpm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_a(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                    NeDsMethodOutput *out);
static int32_T ds_b_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_b(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                    NeDsMethodOutput *out);
static int32_T ds_c_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_c(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                    NeDsMethodOutput *out);
static int32_T ds_vmf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_vpf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_vsf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_slf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_slf0(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_duf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_duf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dtf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_ddf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dpdxf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_dpdxf(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dwf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dwf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_tduf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dnf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dnf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_cer(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dxcer(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxcer_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_ddcer(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddcer_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_ic(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_icr(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_icr_im(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_icr_id(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_icr_il(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxicr(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxicr_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_ddicr(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddicr_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_tduicr_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_icrm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_icrm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dxicrm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxicrm(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddicrm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddicrm(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_freqs(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_solverhits(const NeDynamicSystem *ds, const
  NeDynamicSystemInput *in, NeDsMethodOutput *out);
static int32_T ds_mduy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_mdxy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_tduy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_y(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                    NeDsMethodOutput *out);
static int32_T ds_dxy(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_duy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_duy(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dty_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dty(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_mode(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_zc(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_cache_r(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_cache_i(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_update_r(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_update_i(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_update2_r(const NeDynamicSystem *ds, const
  NeDynamicSystemInput *in, NeDsMethodOutput *out);
static int32_T ds_update2_i(const NeDynamicSystem *ds, const
  NeDynamicSystemInput *in, NeDsMethodOutput *out);
static int32_T ds_lock_r(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_lock_i(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_lock2_r(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_lock2_i(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_sfo(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_sfp(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_init_r(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_init_i(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_assert(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_passert(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_iassert(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_del_t(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_del_v(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_del_v0(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_del_tmax(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxdelt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxdelt(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dudelt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dudelt(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtdelt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtdelt(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dp_l(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dp_i(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dp_j(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dp_r(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_qx(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_qu(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_qt(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_q1(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_qx_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_qu_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_qt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_q1_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_var_tol(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_eq_tol(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_lv(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_slv(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_sclv(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_imin(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_imax(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dimin(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dimax(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static NeDsMethodOutput *ds_output_m_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_m(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vmm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_ddm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_ddm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dum_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dum(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dtm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dtm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dpm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dpm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_a_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_a(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_b_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_b(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_c_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_c(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_f(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vmf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vpf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vsf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_slf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_slf0(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_duf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_duf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dtf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dtf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_ddf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_ddf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dpdxf_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dpdxf(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dwf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dwf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tduf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tdxf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dnf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dnf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dnf_v_x(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_cer(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxcer(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxcer_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_ddcer(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_ddcer_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_ic(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr_im(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr_id(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr_il(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxicr(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_ddicr(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_ddicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_tduicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_icrm_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icrm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxicrm_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dxicrm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_ddicrm_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_ddicrm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_freqs(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_solverhits(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_mduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_y(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxy(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_duy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_duy(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dty_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dty(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mode(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_zc(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_cache_r(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_cache_i(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_update_r(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_update_i(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_update2_r(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_update2_i(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_lock_r(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_lock_i(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_lock2_r(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_lock2_i(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_sfo(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_sfp(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_init_r(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_init_i(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_log(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_assert(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_passert(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_iassert(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_del_t(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_del_v(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_del_v0(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_del_tmax(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dxdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dxdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dudelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dudelt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dtdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dtdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_obs_exp(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_obs_act(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_obs_all(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_obs_il(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_l(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_i(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_j(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_r(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qx(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qu(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_q1(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qx_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qu_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qt_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_q1_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_var_tol(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_eq_tol(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_lv(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_slv(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_nldv(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_sclv(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_imin(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_imax(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dimin(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dimax(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static void release_reference(NeDynamicSystem *ds);
static void get_reference(NeDynamicSystem *ds);
static NeDynamicSystem *diagnostics(NeDynamicSystem *ds, boolean_T);
static void expand(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                   PmRealVector *out, boolean_T kp);
static void rtpmap(const NeDynamicSystem * ds, const PmIntVector* inl, const
                   PmIntVector* ini, const PmIntVector* inj, const PmRealVector*
                   inr, PmIntVector* outl, PmIntVector* outi, PmIntVector* outj,
                   PmRealVector* outr);
static NeEquationData s_equation_data[17] = { { "", 0U, 8,
    NE_EQUATION_DOMAIN_TIME,
    "Main_Firmware/FOC test/Ideal Rotational Motion Sensor", 1U, 0U, TRUE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "Main_Firmware/FOC test/Inertia", 2U, 1U, TRUE, 1.0, "1", }, { "", 0U, 8,
    NE_EQUATION_DOMAIN_TIME, "Main_Firmware/FOC test/PMSM", 2U, 3U, TRUE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME, "Main_Firmware/FOC test/PMSM",
    1U, 5U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "Main_Firmware/FOC test/PMSM", 1U, 6U, FALSE, 1.0, "1", }, { "", 0U, 8,
    NE_EQUATION_DOMAIN_TIME, "Main_Firmware/FOC test/PMSM", 1U, 7U, TRUE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "Main_Firmware/FOC test/Converter (Three-Phase)", 3U, 8U, TRUE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "Main_Firmware/FOC test/Converter (Three-Phase)", 3U, 11U, TRUE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "Main_Firmware/FOC test/Converter (Three-Phase)", 3U, 14U, TRUE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "Main_Firmware/FOC test/Converter (Three-Phase)", 3U, 17U, TRUE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "Main_Firmware/FOC test/Converter (Three-Phase)", 3U, 20U, TRUE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "Main_Firmware/FOC test/Converter (Three-Phase)", 3U, 23U, TRUE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME, "Main_Firmware/FOC test/PMSM", 1U, 26U,
    TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "Main_Firmware/FOC test/PMSM", 1U, 27U, FALSE, 1.0, "1", }, { "", 0U, 8,
    NE_EQUATION_DOMAIN_TIME, "Main_Firmware/FOC test/PMSM", 1U, 28U, FALSE, 1.0,
    "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME, "Main_Firmware/FOC test/PMSM",
    1U, 29U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "Main_Firmware/FOC test/PMSM", 1U, 30U, FALSE, 1.0, "1", } };

static NeCERData *s_cer_data = NULL;
static NeICRData *s_icr_data = NULL;
static NeVariableData s_variable_data[17] = { { "FOC_test.Inertia.w", 0U, 0,
    "Main_Firmware/FOC test/Inertia", 1.0, "1", 0.0, TRUE, FALSE, { 1, "1x1" },
    NE_INIT_MODE_MANDATORY, "Rotational velocity", }, {
    "FOC_test.Ideal_Rotational_Motion_Sensor.phi", 0U, 0,
    "Main_Firmware/FOC test/Ideal Rotational Motion Sensor", 1.0, "1", 0.0, TRUE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Angle", }, {
    "FOC_test.PMSM.angular_position", 0U, 0, "Main_Firmware/FOC test/PMSM", 1.0,
    "1", 0.0, TRUE, FALSE, { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Rotor angle",
  }, { "FOC_test.PMSM.angular_velocity", 0U, 0, "Main_Firmware/FOC test/PMSM",
    1.0, "1", 0.0, TRUE, FALSE, { 1, "1x1" }, NE_INIT_MODE_MANDATORY,
    "Rotor speed", }, { "FOC_test.PMSM.i_d", 0U, 0,
    "Main_Firmware/FOC test/PMSM", 1.0, "1", 0.0, TRUE, FALSE, { 1, "1x1" },
    NE_INIT_MODE_NONE, "D-axis current", }, { "FOC_test.PMSM.i_q", 0U, 0,
    "Main_Firmware/FOC test/PMSM", 1.0, "1", 0.0, TRUE, FALSE, { 1, "1x1" },
    NE_INIT_MODE_NONE, "Q-axis current", }, {
    "FOC_test.Converter_Three_Phase.Q2.K.v", 0U, 1,
    "Main_Firmware/FOC test/Converter (Three-Phase)", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Voltage", }, {
    "FOC_test.Current_Sensor_Three_Phase.a2.v", 0U, 1,
    "Main_Firmware/FOC test/Current Sensor (Three-Phase)", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q2.i", 0U, 0,
    "Main_Firmware/FOC test/Converter (Three-Phase)", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "i", }, {
    "FOC_test.Current_Sensor_Three_Phase.i_b", 0U, 0,
    "Main_Firmware/FOC test/Current Sensor (Three-Phase)", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "i_b", }, {
    "FOC_test.Current_Sensor_Three_Phase.i_c", 0U, 0,
    "Main_Firmware/FOC test/Current Sensor (Three-Phase)", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "i_c", }, {
    "FOC_test.Current_Sensor_Three_Phase.b2.v", 0U, 1,
    "Main_Firmware/FOC test/Current Sensor (Three-Phase)", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q4.i", 0U, 0,
    "Main_Firmware/FOC test/Converter (Three-Phase)", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "i", }, {
    "FOC_test.Current_Sensor_Three_Phase.c2.v", 0U, 1,
    "Main_Firmware/FOC test/Current Sensor (Three-Phase)", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q6.i", 0U, 0,
    "Main_Firmware/FOC test/Converter (Three-Phase)", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "i", }, { "FOC_test.Inertia.t", 0U,
    0, "Main_Firmware/FOC test/Inertia", 1.0, "1", 0.0, FALSE, FALSE, { 1, "1x1"
    }, NE_INIT_MODE_NONE, "Torque", }, { "FOC_test.PMSM.electrical_torque", 0U,
    0, "Main_Firmware/FOC test/PMSM", 1.0, "1", 0.0, FALSE, FALSE, { 1, "1x1" },
    NE_INIT_MODE_NONE, "Electrical torque", } };

static NeVariableData *s_discrete_data = NULL;
static NeObservableData s_observable_data[228] = { {
    "FOC_test.Converter_Three_Phase.G.V",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 12, "1x12" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G1",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "G1", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G1n.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G1p.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G2",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "G2", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G2n.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G2p.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G3",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "G3", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G3n.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G3p.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G4",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "G4", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G4n.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G4p.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G5",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "G5", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G5n.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G5p.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G6",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "G6", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G6n.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.G6p.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.I",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 12, "1x12" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "I", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.i1n",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i1n", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.i1p",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i1p", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.i2n",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i2n", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.i2p",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i2p", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.i3n",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i3n", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.i3p",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i3p", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.i4n",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i4n", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.i4p",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i4p", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.i5n",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i5n", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.i5p",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i5p", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.i6n",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i6n", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.i6p",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i6p", }, {
    "FOC_test.Converter_Three_Phase.demux_gates.p.V",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 12, "1x12" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "V", }, {
    "FOC_test.Converter_Three_Phase.N.V",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 3, "1x3" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "V", }, {
    "FOC_test.Converter_Three_Phase.Q1.A.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q1.G",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "G", }, {
    "FOC_test.Converter_Three_Phase.Q1.G_elec.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q1.K.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q1.i",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "i", }, {
    "FOC_test.Converter_Three_Phase.Q1.ideal_switch.i",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i", }, {
    "FOC_test.Converter_Three_Phase.Q1.ideal_switch.n.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q1.ideal_switch.p.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q1.ideal_switch.power_dissipated",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "W", 1.0,
    "kW", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Power dissipated", }, {
    "FOC_test.Converter_Three_Phase.Q1.ideal_switch.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "v", }, {
    "FOC_test.Converter_Three_Phase.Q1.ideal_switch.vT",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "PS", }, {
    "FOC_test.Converter_Three_Phase.Q1.power_dissipated",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "W", 1.0,
    "kW", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Power dissipated", }, {
    "FOC_test.Converter_Three_Phase.Q1.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "v", }, {
    "FOC_test.Converter_Three_Phase.Q1.vT",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "vT", }, {
    "FOC_test.Converter_Three_Phase.Q2.A.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q2.G",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "G", }, {
    "FOC_test.Converter_Three_Phase.Q2.G_elec.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q2.K.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q2.i",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "i", }, {
    "FOC_test.Converter_Three_Phase.Q2.ideal_switch.i",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i", }, {
    "FOC_test.Converter_Three_Phase.Q2.ideal_switch.n.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q2.ideal_switch.p.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q2.ideal_switch.power_dissipated",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "W", 1.0,
    "kW", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Power dissipated", }, {
    "FOC_test.Converter_Three_Phase.Q2.ideal_switch.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "v", }, {
    "FOC_test.Converter_Three_Phase.Q2.ideal_switch.vT",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "PS", }, {
    "FOC_test.Converter_Three_Phase.Q2.power_dissipated",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "W", 1.0,
    "kW", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Power dissipated", }, {
    "FOC_test.Converter_Three_Phase.Q2.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "v", }, {
    "FOC_test.Converter_Three_Phase.Q2.vT",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "vT", }, {
    "FOC_test.Converter_Three_Phase.Q3.A.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q3.G",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "G", }, {
    "FOC_test.Converter_Three_Phase.Q3.G_elec.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q3.K.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q3.i",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "i", }, {
    "FOC_test.Converter_Three_Phase.Q3.ideal_switch.i",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i", }, {
    "FOC_test.Converter_Three_Phase.Q3.ideal_switch.n.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q3.ideal_switch.p.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q3.ideal_switch.power_dissipated",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "W", 1.0,
    "kW", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Power dissipated", }, {
    "FOC_test.Converter_Three_Phase.Q3.ideal_switch.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "v", }, {
    "FOC_test.Converter_Three_Phase.Q3.ideal_switch.vT",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "PS", }, {
    "FOC_test.Converter_Three_Phase.Q3.power_dissipated",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "W", 1.0,
    "kW", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Power dissipated", }, {
    "FOC_test.Converter_Three_Phase.Q3.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "v", }, {
    "FOC_test.Converter_Three_Phase.Q3.vT",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "vT", }, {
    "FOC_test.Converter_Three_Phase.Q4.A.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q4.G",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "G", }, {
    "FOC_test.Converter_Three_Phase.Q4.G_elec.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q4.K.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q4.i",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "i", }, {
    "FOC_test.Converter_Three_Phase.Q4.ideal_switch.i",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i", }, {
    "FOC_test.Converter_Three_Phase.Q4.ideal_switch.n.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q4.ideal_switch.p.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q4.ideal_switch.power_dissipated",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "W", 1.0,
    "kW", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Power dissipated", }, {
    "FOC_test.Converter_Three_Phase.Q4.ideal_switch.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "v", }, {
    "FOC_test.Converter_Three_Phase.Q4.ideal_switch.vT",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "PS", }, {
    "FOC_test.Converter_Three_Phase.Q4.power_dissipated",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "W", 1.0,
    "kW", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Power dissipated", }, {
    "FOC_test.Converter_Three_Phase.Q4.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "v", }, {
    "FOC_test.Converter_Three_Phase.Q4.vT",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "vT", }, {
    "FOC_test.Converter_Three_Phase.Q5.A.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q5.G",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "G", }, {
    "FOC_test.Converter_Three_Phase.Q5.G_elec.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q5.K.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q5.i",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "i", }, {
    "FOC_test.Converter_Three_Phase.Q5.ideal_switch.i",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i", }, {
    "FOC_test.Converter_Three_Phase.Q5.ideal_switch.n.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q5.ideal_switch.p.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q5.ideal_switch.power_dissipated",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "W", 1.0,
    "kW", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Power dissipated", }, {
    "FOC_test.Converter_Three_Phase.Q5.ideal_switch.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "v", }, {
    "FOC_test.Converter_Three_Phase.Q5.ideal_switch.vT",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "PS", }, {
    "FOC_test.Converter_Three_Phase.Q5.power_dissipated",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "W", 1.0,
    "kW", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Power dissipated", }, {
    "FOC_test.Converter_Three_Phase.Q5.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "v", }, {
    "FOC_test.Converter_Three_Phase.Q5.vT",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "vT", }, {
    "FOC_test.Converter_Three_Phase.Q6.A.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q6.G",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "G", }, {
    "FOC_test.Converter_Three_Phase.Q6.G_elec.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q6.K.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q6.i",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "i", }, {
    "FOC_test.Converter_Three_Phase.Q6.ideal_switch.i",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i", }, {
    "FOC_test.Converter_Three_Phase.Q6.ideal_switch.n.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q6.ideal_switch.p.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.Q6.ideal_switch.power_dissipated",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "W", 1.0,
    "kW", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Power dissipated", }, {
    "FOC_test.Converter_Three_Phase.Q6.ideal_switch.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "v", }, {
    "FOC_test.Converter_Three_Phase.Q6.ideal_switch.vT",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "PS", }, {
    "FOC_test.Converter_Three_Phase.Q6.power_dissipated",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "W", 1.0,
    "kW", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Power dissipated", }, {
    "FOC_test.Converter_Three_Phase.Q6.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "v", }, {
    "FOC_test.Converter_Three_Phase.Q6.vT",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "vT", }, {
    "FOC_test.Converter_Three_Phase.a.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.b.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.c.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.n.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Converter_Three_Phase.p.v",
    "Main_Firmware/FOC test/Converter (Three-Phase)", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Current_Sensor_Three_Phase.I_output",
    "Main_Firmware/FOC test/Current Sensor (Three-Phase)", { 3, "1x3" }, "A",
    1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I", }, {
    "FOC_test.Current_Sensor_Three_Phase.a1.v",
    "Main_Firmware/FOC test/Current Sensor (Three-Phase)", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Current_Sensor_Three_Phase.a2.v",
    "Main_Firmware/FOC test/Current Sensor (Three-Phase)", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Current_Sensor_Three_Phase.b1.v",
    "Main_Firmware/FOC test/Current Sensor (Three-Phase)", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Current_Sensor_Three_Phase.b2.v",
    "Main_Firmware/FOC test/Current Sensor (Three-Phase)", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Current_Sensor_Three_Phase.c1.v",
    "Main_Firmware/FOC test/Current Sensor (Three-Phase)", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Current_Sensor_Three_Phase.c2.v",
    "Main_Firmware/FOC test/Current Sensor (Three-Phase)", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Current_Sensor_Three_Phase.i_a",
    "Main_Firmware/FOC test/Current Sensor (Three-Phase)", { 1, "1x1" }, "A",
    1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "i_a", }, {
    "FOC_test.Current_Sensor_Three_Phase.i_b",
    "Main_Firmware/FOC test/Current Sensor (Three-Phase)", { 1, "1x1" }, "A",
    1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "i_b", }, {
    "FOC_test.Current_Sensor_Three_Phase.i_c",
    "Main_Firmware/FOC test/Current Sensor (Three-Phase)", { 1, "1x1" }, "A",
    1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "i_c", }, {
    "FOC_test.Current_Sensor_Three_Phase_I_output0",
    "Main_Firmware/FOC test/PS-Simulink\nConverter2", { 3, "1x3" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Current_Sensor_Three_Phase_I_output0",
  }, { "FOC_test.Gate_Driver.Gate.V", "Main_Firmware/FOC test/Gate Driver", { 12,
      "1x12" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "V", }, {
    "FOC_test.Gate_Driver.Simulink_PS_Converter3_output0",
    "Main_Firmware/FOC test/Gate Driver/Simulink-PS\nConverter3", { 1, "1x1" },
    "1", 1.0, "1", NE_NOMINAL_SOURCE_FIXED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Simulink_PS_Converter3_output0", }, {
    "FOC_test.Gate_Driver.Simulink_PS_Converter4_output0",
    "Main_Firmware/FOC test/Gate Driver/Simulink-PS\nConverter4", { 1, "1x1" },
    "1", 1.0, "1", NE_NOMINAL_SOURCE_FIXED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Simulink_PS_Converter4_output0", }, {
    "FOC_test.Gate_Driver.Simulink_PS_Converter5_output0",
    "Main_Firmware/FOC test/Gate Driver/Simulink-PS\nConverter5", { 1, "1x1" },
    "1", 1.0, "1", NE_NOMINAL_SOURCE_FIXED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Simulink_PS_Converter5_output0", }, {
    "FOC_test.Gate_Driver.Simulink_PS_Converter6_output0",
    "Main_Firmware/FOC test/Gate Driver/Simulink-PS\nConverter6", { 1, "1x1" },
    "1", 1.0, "1", NE_NOMINAL_SOURCE_FIXED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Simulink_PS_Converter6_output0", }, {
    "FOC_test.Gate_Driver.Simulink_PS_Converter7_output0",
    "Main_Firmware/FOC test/Gate Driver/Simulink-PS\nConverter7", { 1, "1x1" },
    "1", 1.0, "1", NE_NOMINAL_SOURCE_FIXED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Simulink_PS_Converter7_output0", }, {
    "FOC_test.Gate_Driver.Simulink_PS_Converter8_output0",
    "Main_Firmware/FOC test/Gate Driver/Simulink-PS\nConverter8", { 1, "1x1" },
    "1", 1.0, "1", NE_NOMINAL_SOURCE_FIXED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Simulink_PS_Converter8_output0", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.GaH.v",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.GaH_ps",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Ga(H)", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.GaL.v",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.GaL_ps",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Ga(L)", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.GbH.v",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.GbH_ps",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Gb(H)", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.GbL.v",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.GbL_ps",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Gb(L)", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.GcH.v",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.GcH_ps",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Gc(H)", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.GcL.v",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.GcL_ps",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Gc(L)", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.I",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 12,
      "1x12" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "I", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.L.v",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.a.v",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.b.v",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.c.v",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.Gate_Driver.Six_Pulse_Gate_Multiplexer.p.V",
    "Main_Firmware/FOC test/Gate Driver/Six-Pulse Gate Multiplexer", { 12,
      "1x12" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, {
    "FOC_test.Ideal_Rotational_Motion_Sensor.A",
    "Main_Firmware/FOC test/Ideal Rotational Motion Sensor", { 1, "1x1" }, "rad",
    1.0, "1", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "A", }, {
    "FOC_test.Ideal_Rotational_Motion_Sensor.C.w",
    "Main_Firmware/FOC test/Ideal Rotational Motion Sensor", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "FOC_test.Ideal_Rotational_Motion_Sensor.R.w",
    "Main_Firmware/FOC test/Ideal Rotational Motion Sensor", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "FOC_test.Ideal_Rotational_Motion_Sensor.W",
    "Main_Firmware/FOC test/Ideal Rotational Motion Sensor", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "W", }, {
    "FOC_test.Ideal_Rotational_Motion_Sensor.alpha",
    "Main_Firmware/FOC test/Ideal Rotational Motion Sensor", { 1, "1x1" },
    "rad/s^2", 1.0, "1/s^2", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "\\u03B1", }, {
    "FOC_test.Ideal_Rotational_Motion_Sensor.phi",
    "Main_Firmware/FOC test/Ideal Rotational Motion Sensor", { 1, "1x1" }, "rad",
    1.0, "1", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_MANDATORY, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Angle", }, {
    "FOC_test.Ideal_Rotational_Motion_Sensor_A0",
    "Main_Firmware/FOC test/PS-Simulink\nConverter", { 1, "1x1" }, "rad", 1.0,
    "1", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Ideal_Rotational_Motion_Sensor_A0", },
    { "FOC_test.Ideal_Rotational_Motion_Sensor_W0",
    "Main_Firmware/FOC test/PS-Simulink\nConverter1", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Ideal_Rotational_Motion_Sensor_W0", },
    { "FOC_test.Ideal_Torque_Sensor.C.w",
    "Main_Firmware/FOC test/Ideal Torque Sensor", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "FOC_test.Ideal_Torque_Sensor.R.w",
    "Main_Firmware/FOC test/Ideal Torque Sensor", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "FOC_test.Ideal_Torque_Sensor.T",
    "Main_Firmware/FOC test/Ideal Torque Sensor", { 1, "1x1" }, "N*m", 1.0,
    "N*m", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "T", }, {
    "FOC_test.Ideal_Torque_Sensor.t",
    "Main_Firmware/FOC test/Ideal Torque Sensor", { 1, "1x1" }, "N*m", 1.0,
    "N*m", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "FOC_test.Ideal_Torque_Sensor_T0",
    "Main_Firmware/FOC test/PS-Simulink\nConverter3", { 1, "1x1" }, "N*m", 1.0,
    "N*m", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Ideal_Torque_Sensor_T0", }, {
    "FOC_test.Ideal_Torque_Source.C.w",
    "Main_Firmware/FOC test/Ideal Torque Source", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "FOC_test.Ideal_Torque_Source.R.w",
    "Main_Firmware/FOC test/Ideal Torque Source", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "FOC_test.Ideal_Torque_Source.S",
    "Main_Firmware/FOC test/Ideal Torque Source", { 1, "1x1" }, "N*m", 1.0,
    "N*m", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "S", }, {
    "FOC_test.Ideal_Torque_Source.t",
    "Main_Firmware/FOC test/Ideal Torque Source", { 1, "1x1" }, "N*m", 1.0,
    "N*m", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, {
    "FOC_test.Ideal_Torque_Source.w",
    "Main_Firmware/FOC test/Ideal Torque Source", { 1, "1x1" }, "rad/s", 1.0,
    "1/s", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Angular velocity", }, {
    "FOC_test.Inertia.I.w", "Main_Firmware/FOC test/Inertia", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "FOC_test.Inertia.J.w", "Main_Firmware/FOC test/Inertia", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rotational velocity", }, {
    "FOC_test.Inertia.t", "Main_Firmware/FOC test/Inertia", { 1, "1x1" }, "N*m",
    1.0, "N*m", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, { "FOC_test.Inertia.w",
    "Main_Firmware/FOC test/Inertia", { 1, "1x1" }, "rad/s", 1.0, "1/s",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_MANDATORY, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "FOC_test.Mechanical_Rotational_Reference.W.w",
    "Main_Firmware/FOC test/Mechanical Rotational Reference", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "FOC_test.Mechanical_Rotational_Reference1.W.w",
    "Main_Firmware/FOC test/Mechanical Rotational Reference1", { 1, "1x1" },
    "rad/s", 1.0, "1/s", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "FOC_test.PMSM.C.w", "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "rad/s",
    1.0, "1/s", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "FOC_test.PMSM.N.V", "Main_Firmware/FOC test/PMSM", { 3, "1x3" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "V", }, { "FOC_test.PMSM.N1.V",
    "Main_Firmware/FOC test/PMSM", { 3, "1x3" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "V", }, { "FOC_test.PMSM.N2.V",
    "Main_Firmware/FOC test/PMSM", { 3, "1x3" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "V", }, { "FOC_test.PMSM.R.w",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "rad/s", 1.0, "1/s",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotational velocity", }, {
    "FOC_test.PMSM.Ra", "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "Ohm", 1.0,
    "kg*m^2/(C^2*s)", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Ra", }, { "FOC_test.PMSM.Rb",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "Ohm", 1.0, "kg*m^2/(C^2*s)",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rb", }, { "FOC_test.PMSM.Rc",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "Ohm", 1.0, "kg*m^2/(C^2*s)",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Rc", }, { "FOC_test.PMSM.Vd_losses",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "W", 1.0, "kW",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "Iron losses in cross-tooth path, f(Vd^*)", }, { "FOC_test.PMSM.Vm_losses",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "W", 1.0, "kW",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "Iron losses in main magnetizing path, f(Vm)", }, { "FOC_test.PMSM.a.v",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "FOC_test.PMSM.a1.v",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, { "FOC_test.PMSM.a2.v",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.PMSM.angular_position", "Main_Firmware/FOC test/PMSM", { 1, "1x1"
    }, "deg", 1.0, "1", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_MANDATORY, FALSE,
    TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotor angle", }, {
    "FOC_test.PMSM.angular_velocity", "Main_Firmware/FOC test/PMSM", { 1, "1x1"
    }, "rpm", 1.0, "1/s", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_MANDATORY,
    FALSE, TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rotor speed", }, {
    "FOC_test.PMSM.b.v", "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "FOC_test.PMSM.b1.v",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, { "FOC_test.PMSM.b2.v",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, { "FOC_test.PMSM.c.v",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "FOC_test.PMSM.c1.v",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, { "FOC_test.PMSM.c2.v",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.PMSM.electrical_torque", "Main_Firmware/FOC test/PMSM", { 1, "1x1"
    }, "N*m", 1.0, "N*m", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Electrical torque", }, {
    "FOC_test.PMSM.fluxReductionForTemp", "Main_Firmware/FOC test/PMSM", { 1,
      "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "fluxReductionForTemp", }, {
    "FOC_test.PMSM.i_a", "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "i_a", }, { "FOC_test.PMSM.i_b",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "A", 1.0, "A",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "i_b", }, { "FOC_test.PMSM.i_c",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "A", 1.0, "A",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "i_c", }, { "FOC_test.PMSM.i_d",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "A", 1.0, "A",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "D-axis current", }, {
    "FOC_test.PMSM.i_n", "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "i_n", }, { "FOC_test.PMSM.i_q",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "A", 1.0, "A",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Q-axis current", }, {
    "FOC_test.PMSM.x_pm_flux_linkage", "Main_Firmware/FOC test/PMSM", { 1, "1x1"
    }, "Wb", 1.0, "Wb", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "x_pm_flux_linkage", }, {
    "FOC_test.PMSM.lambda", "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "Wb",
    1.0, "Wb", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "lambda", }, { "FOC_test.PMSM.n.v",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "FOC_test.PMSM.power_dissipated", "Main_Firmware/FOC test/PMSM", { 1, "1x1"
    }, "kW", 1.0, "kW", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "power_dissipated", }, {
    "FOC_test.PMSM.x_Ld", "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "H", 1.0,
    "H", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "x_Ld", }, { "FOC_test.PMSM.x_Lq",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "H", 1.0, "H",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "x_Lq", }, { "FOC_test.PMSM.torque",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "N*m", 1.0, "N*m",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Torque", }, { "FOC_test.PMSM.trq_loss",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "N*m", 1.0, "N*m",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Torque losses", }, {
    "FOC_test.PMSM.v_a", "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "v_a", }, { "FOC_test.PMSM.v_b",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "v_b", }, { "FOC_test.PMSM.v_c",
    "Main_Firmware/FOC test/PMSM", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "v_c", }, {
    "FOC_test.Simulink_PS_Converter_output0",
    "Main_Firmware/FOC test/Simulink-PS\nConverter", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_FIXED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Simulink_PS_Converter_output0", }, {
    "FOC_test.Voltage_Source.i", "Main_Firmware/FOC test/Voltage Source", { 1,
      "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current (positive in)", }, {
    "FOC_test.Voltage_Source.n.v", "Main_Firmware/FOC test/Voltage Source", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Voltage_Source.p.v", "Main_Firmware/FOC test/Voltage Source", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "FOC_test.Voltage_Source.v", "Main_Firmware/FOC test/Voltage Source", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", } };

static NeModeData *s_major_mode_data = NULL;
static NeZCData s_zc_data[6] = { {
    "Main_Firmware/FOC test/Converter (Three-Phase)", 1U, 0U,
    "FOC_test.Converter_Three_Phase.Q1.ideal_switch",
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    NE_ZC_TYPE_FALSE, }, { "Main_Firmware/FOC test/Converter (Three-Phase)", 1U,
    1U, "FOC_test.Converter_Three_Phase.Q2.ideal_switch",
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    NE_ZC_TYPE_FALSE, }, { "Main_Firmware/FOC test/Converter (Three-Phase)", 1U,
    2U, "FOC_test.Converter_Three_Phase.Q3.ideal_switch",
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    NE_ZC_TYPE_FALSE, }, { "Main_Firmware/FOC test/Converter (Three-Phase)", 1U,
    3U, "FOC_test.Converter_Three_Phase.Q4.ideal_switch",
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    NE_ZC_TYPE_FALSE, }, { "Main_Firmware/FOC test/Converter (Three-Phase)", 1U,
    4U, "FOC_test.Converter_Three_Phase.Q5.ideal_switch",
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    NE_ZC_TYPE_FALSE, }, { "Main_Firmware/FOC test/Converter (Three-Phase)", 1U,
    5U, "FOC_test.Converter_Three_Phase.Q6.ideal_switch",
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    NE_ZC_TYPE_FALSE, } };

static NeRange s_range[6] = { {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, } };

static NeAssertData s_assert_data[6] = { { "Main_Firmware/FOC test/PMSM", 1U, 0U,
    "FOC_test.PMSM.power_dissipated",
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "Main_Firmware/FOC test/PMSM", 1U, 1U, "FOC_test.PMSM.power_dissipated",
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "Main_Firmware/FOC test/PMSM", 1U, 2U, "FOC_test.PMSM.power_dissipated",
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "Main_Firmware/FOC test/PMSM", 1U, 3U, "FOC_test.PMSM.power_dissipated",
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "Main_Firmware/FOC test/PMSM", 1U, 4U, "FOC_test.PMSM.power_dissipated",
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "Main_Firmware/FOC test/PMSM", 1U, 5U, "FOC_test.PMSM.power_dissipated",
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", } };

static NeRange s_assert_range[6] = { {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, } };

static NeAssertData *s_param_assert_data = NULL;
static NeRange *s_param_assert_range = NULL;
static NeAssertData *s_initial_assert_data = NULL;
static NeRange *s_initial_assert_range = NULL;
static NeRange s_equation_range[31] = { {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+sensors/angular_velocity.ssc",
    78U, 9U, 78U, 22U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+rotational/inertia.ssc",
    44U, 5U, 44U, 21U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/simscape/library/m/+foundation/+mechanical/+rotational/inertia.ssc",
    44U, 20U, 44U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+semiconductors/+ideal/switch_equation.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "C:/Program Files/MATLAB/R2024a/toolbox/physmod/elec/library/m/+ee/+electromech/+pmsm/+pm_rotor/+pmsm/base.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, } };

static NeRange *s_cer_range = NULL;
static NeRange *s_icr_range = NULL;
static NeParameterData *s_logical_parameter_data = NULL;
static NeParameterData *s_integer_parameter_data = NULL;
static NeParameterData *s_index_parameter_data = NULL;
static NeParameterData *s_real_parameter_data = NULL;
static real_T s_constant_table0[12] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
  0.0, 0.0, 0.0, 0.0 };

static NeDsMethodOutput *ds_output_m_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mM_P.mNumCol = 17;
  out->mM_P.mNumRow = 17;
  out->mM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    18);
  out->mM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    6);
  return out;
}

static NeDsMethodOutput *ds_output_m(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mM.mN = 6;
  out->mM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 6);
  return out;
}

static NeDsMethodOutput *ds_output_vmm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVMM.mN = 6;
  out->mVMM.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    6);
  return out;
}

static NeDsMethodOutput *ds_output_dxm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXM_P.mNumCol = 17;
  out->mDXM_P.mNumRow = 6;
  out->mDXM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    18);
  out->mDXM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dxm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXM.mN = 0;
  out->mDXM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDM_P.mNumCol = 0;
  out->mDDM_P.mNumRow = 6;
  out->mDDM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  out->mDDM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_ddm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDM.mN = 0;
  out->mDDM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dum_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUM_P.mNumCol = 7;
  out->mDUM_P.mNumRow = 6;
  out->mDUM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    8);
  out->mDUM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dum(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUM.mN = 0;
  out->mDUM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dtm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTM_P.mNumCol = 1;
  out->mDTM_P.mNumRow = 6;
  out->mDTM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mDTM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dtm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTM.mN = 0;
  out->mDTM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dpm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDPM_P.mNumCol = 0;
  out->mDPM_P.mNumRow = 6;
  out->mDPM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  out->mDPM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dpm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDPM.mN = 0;
  out->mDPM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_a_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mA_P.mNumCol = 17;
  out->mA_P.mNumRow = 17;
  out->mA_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    18);
  out->mA_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    16);
  return out;
}

static NeDsMethodOutput *ds_output_a(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mA.mN = 16;
  out->mA.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 16);
  return out;
}

static NeDsMethodOutput *ds_output_b_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mB_P.mNumCol = 7;
  out->mB_P.mNumRow = 17;
  out->mB_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    8);
  out->mB_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  return out;
}

static NeDsMethodOutput *ds_output_b(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mB.mN = 1;
  out->mB.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 1);
  return out;
}

static NeDsMethodOutput *ds_output_c_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mC_P.mNumCol = 1;
  out->mC_P.mNumRow = 17;
  out->mC_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mC_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_c(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mC.mN = 0;
  out->mC.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_f(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mF.mN = 17;
  out->mF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 17);
  return out;
}

static NeDsMethodOutput *ds_output_vmf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVMF.mN = 17;
  out->mVMF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    17);
  return out;
}

static NeDsMethodOutput *ds_output_vpf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVPF.mN = 17;
  out->mVPF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    17);
  return out;
}

static NeDsMethodOutput *ds_output_vsf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVSF.mN = 17;
  out->mVSF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    17);
  return out;
}

static NeDsMethodOutput *ds_output_slf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSLF.mN = 17;
  out->mSLF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    17);
  return out;
}

static NeDsMethodOutput *ds_output_slf0(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSLF0.mN = 17;
  out->mSLF0.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 17);
  return out;
}

static NeDsMethodOutput *ds_output_dxf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXF_P.mNumCol = 17;
  out->mDXF_P.mNumRow = 17;
  out->mDXF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    18);
  out->mDXF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    49);
  return out;
}

static NeDsMethodOutput *ds_output_dxf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXF.mN = 49;
  out->mDXF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 49);
  return out;
}

static NeDsMethodOutput *ds_output_duf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUF_P.mNumCol = 7;
  out->mDUF_P.mNumRow = 17;
  out->mDUF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    8);
  out->mDUF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_duf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUF.mN = 0;
  out->mDUF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dtf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTF_P.mNumCol = 1;
  out->mDTF_P.mNumRow = 17;
  out->mDTF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mDTF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dtf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTF.mN = 0;
  out->mDTF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDF_P.mNumCol = 0;
  out->mDDF_P.mNumRow = 17;
  out->mDDF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  out->mDDF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_ddf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDF.mN = 0;
  out->mDDF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dpdxf_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDPDXF_P.mNumCol = 0;
  out->mDPDXF_P.mNumRow = 49;
  out->mDPDXF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 1);
  out->mDPDXF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dpdxf(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDPDXF.mN = 0;
  out->mDPDXF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dwf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDWF_P.mNumCol = 0;
  out->mDWF_P.mNumRow = 17;
  out->mDWF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  out->mDWF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dwf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDWF.mN = 0;
  out->mDWF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_tduf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDUF_P.mNumCol = 7;
  out->mTDUF_P.mNumRow = 17;
  out->mTDUF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    8);
  out->mTDUF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    7);
  return out;
}

static NeDsMethodOutput *ds_output_tdxf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDXF_P.mNumCol = 17;
  out->mTDXF_P.mNumRow = 17;
  out->mTDXF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    18);
  out->mTDXF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    65);
  return out;
}

static NeDsMethodOutput *ds_output_dnf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDNF_P.mNumCol = 21;
  out->mDNF_P.mNumRow = 17;
  out->mDNF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    22);
  out->mDNF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dnf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDNF.mN = 0;
  out->mDNF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dnf_v_x(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDNF_V_X.mN = 17;
  out->mDNF_V_X.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 17);
  return out;
}

static NeDsMethodOutput *ds_output_cer(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCER.mN = 0;
  out->mCER.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxcer(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXCER.mN = 0;
  out->mDXCER.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxcer_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXCER_P.mNumCol = 17;
  out->mDXCER_P.mNumRow = 0;
  out->mDXCER_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 18);
  out->mDXCER_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddcer(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDCER.mN = 0;
  out->mDDCER.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddcer_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDCER_P.mNumCol = 0;
  out->mDDCER_P.mNumRow = 0;
  out->mDDCER_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 1);
  out->mDDCER_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ic(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mIC.mN = 17;
  out->mIC.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 17);
  return out;
}

static NeDsMethodOutput *ds_output_icr(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR.mN = 0;
  out->mICR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_icr_im(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR_IM.mN = 0;
  out->mICR_IM.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_icr_id(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR_ID.mN = 0;
  out->mICR_ID.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_icr_il(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR_IL.mN = 0;
  out->mICR_IL.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxicr(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXICR.mN = 0;
  out->mDXICR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXICR_P.mNumCol = 17;
  out->mDXICR_P.mNumRow = 0;
  out->mDXICR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 18);
  out->mDXICR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddicr(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDICR.mN = 0;
  out->mDDICR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDICR_P.mNumCol = 0;
  out->mDDICR_P.mNumRow = 0;
  out->mDDICR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 1);
  out->mDDICR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_tduicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDUICR_P.mNumCol = 7;
  out->mTDUICR_P.mNumRow = 0;
  out->mTDUICR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 8);
  out->mTDUICR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_icrm_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICRM_P.mNumCol = 17;
  out->mICRM_P.mNumRow = 0;
  out->mICRM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    18);
  out->mICRM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_icrm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICRM.mN = 0;
  out->mICRM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxicrm_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXICRM_P.mNumCol = 17;
  out->mDXICRM_P.mNumRow = 0;
  out->mDXICRM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 18);
  out->mDXICRM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxicrm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXICRM.mN = 0;
  out->mDXICRM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_ddicrm_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDICRM_P.mNumCol = 0;
  out->mDDICRM_P.mNumRow = 0;
  out->mDDICRM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 1);
  out->mDDICRM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddicrm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDICRM.mN = 0;
  out->mDDICRM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_freqs(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mFREQS.mN = 0;
  out->mFREQS.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_solverhits(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSOLVERHITS.mN = 0;
  out->mSOLVERHITS.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof
    (real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_mduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMDUY_P.mNumCol = 7;
  out->mMDUY_P.mNumRow = 6;
  out->mMDUY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    8);
  out->mMDUY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_mdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMDXY_P.mNumCol = 17;
  out->mMDXY_P.mNumRow = 6;
  out->mMDXY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    18);
  out->mMDXY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_tduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDUY_P.mNumCol = 7;
  out->mTDUY_P.mNumRow = 6;
  out->mTDUY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    8);
  out->mTDUY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  return out;
}

static NeDsMethodOutput *ds_output_tdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDXY_P.mNumCol = 17;
  out->mTDXY_P.mNumRow = 6;
  out->mTDXY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    18);
  out->mTDXY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    9);
  return out;
}

static NeDsMethodOutput *ds_output_y(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mY.mN = 6;
  out->mY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 6);
  return out;
}

static NeDsMethodOutput *ds_output_dxy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXY_P.mNumCol = 17;
  out->mDXY_P.mNumRow = 6;
  out->mDXY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    18);
  out->mDXY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    9);
  return out;
}

static NeDsMethodOutput *ds_output_dxy(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXY.mN = 9;
  out->mDXY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 9);
  return out;
}

static NeDsMethodOutput *ds_output_duy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUY_P.mNumCol = 7;
  out->mDUY_P.mNumRow = 6;
  out->mDUY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    8);
  out->mDUY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  return out;
}

static NeDsMethodOutput *ds_output_duy(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUY.mN = 1;
  out->mDUY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 1);
  return out;
}

static NeDsMethodOutput *ds_output_dty_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTY_P.mNumCol = 1;
  out->mDTY_P.mNumRow = 6;
  out->mDTY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mDTY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dty(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTY.mN = 0;
  out->mDTY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_mode(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMODE.mN = 6;
  out->mMODE.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    6);
  return out;
}

static NeDsMethodOutput *ds_output_zc(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mZC.mN = 6;
  out->mZC.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 6);
  return out;
}

static NeDsMethodOutput *ds_output_cache_r(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCACHE_R.mN = 0;
  out->mCACHE_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_cache_i(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCACHE_I.mN = 0;
  out->mCACHE_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_update_r(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mUPDATE_R.mN = 0;
  out->mUPDATE_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_update_i(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mUPDATE_I.mN = 0;
  out->mUPDATE_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_update2_r(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mUPDATE2_R.mN = 0;
  out->mUPDATE2_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_update2_i(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mUPDATE2_I.mN = 0;
  out->mUPDATE2_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_lock_r(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOCK_R.mN = 0;
  out->mLOCK_R.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_lock_i(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOCK_I.mN = 0;
  out->mLOCK_I.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_lock2_r(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOCK2_R.mN = 0;
  out->mLOCK2_R.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_lock2_i(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOCK2_I.mN = 0;
  out->mLOCK2_I.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_sfo(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSFO.mN = 0;
  out->mSFO.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_sfp(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSFP.mN = 0;
  out->mSFP.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_init_r(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mINIT_R.mN = 0;
  out->mINIT_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_init_i(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mINIT_I.mN = 0;
  out->mINIT_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_log(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOG.mN = 210;
  out->mLOG.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 210);
  return out;
}

static NeDsMethodOutput *ds_output_assert(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mASSERT.mN = 6;
  out->mASSERT.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    6);
  return out;
}

static NeDsMethodOutput *ds_output_passert(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mPASSERT.mN = 0;
  out->mPASSERT.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_iassert(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mIASSERT.mN = 0;
  out->mIASSERT.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_del_t(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_T.mN = 0;
  out->mDEL_T.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_del_v(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_V.mN = 0;
  out->mDEL_V.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_del_v0(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_V0.mN = 0;
  out->mDEL_V0.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_del_tmax(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_TMAX.mN = 0;
  out->mDEL_TMAX.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dxdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXDELT_P.mNumCol = 17;
  out->mDXDELT_P.mNumRow = 0;
  out->mDXDELT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 18);
  out->mDXDELT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXDELT.mN = 0;
  out->mDXDELT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dudelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUDELT_P.mNumCol = 7;
  out->mDUDELT_P.mNumRow = 0;
  out->mDUDELT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 8);
  out->mDUDELT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dudelt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUDELT.mN = 0;
  out->mDUDELT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dtdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTDELT_P.mNumCol = 1;
  out->mDTDELT_P.mNumRow = 0;
  out->mDTDELT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 2);
  out->mDTDELT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dtdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTDELT.mN = 0;
  out->mDTDELT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_obs_exp(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_EXP.mN = 301;
  out->mOBS_EXP.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    301);
  return out;
}

static NeDsMethodOutput *ds_output_obs_act(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_ACT.mN = 301;
  out->mOBS_ACT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    301);
  return out;
}

static NeDsMethodOutput *ds_output_obs_all(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_ALL.mN = 301;
  out->mOBS_ALL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    301);
  return out;
}

static NeDsMethodOutput *ds_output_obs_il(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_IL.mN = 301;
  out->mOBS_IL.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 301);
  return out;
}

static NeDsMethodOutput *ds_output_dp_l(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_L.mN = 0;
  out->mDP_L.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dp_i(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_I.mN = 0;
  out->mDP_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dp_j(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_J.mN = 0;
  out->mDP_J.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dp_r(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_R.mN = 0;
  out->mDP_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_qx(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQX.mN = 0;
  out->mQX.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_qu(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQU.mN = 0;
  out->mQU.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_qt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQT.mN = 0;
  out->mQT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_q1(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQ1.mN = 0;
  out->mQ1.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_qx_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQX_P.mNumCol = 17;
  out->mQX_P.mNumRow = 17;
  out->mQX_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    18);
  out->mQX_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_qu_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQU_P.mNumCol = 7;
  out->mQU_P.mNumRow = 17;
  out->mQU_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    8);
  out->mQU_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_qt_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQT_P.mNumCol = 1;
  out->mQT_P.mNumRow = 17;
  out->mQT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mQT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_q1_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQ1_P.mNumCol = 1;
  out->mQ1_P.mNumRow = 17;
  out->mQ1_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mQ1_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_var_tol(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVAR_TOL.mN = 17;
  out->mVAR_TOL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    17);
  return out;
}

static NeDsMethodOutput *ds_output_eq_tol(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mEQ_TOL.mN = 17;
  out->mEQ_TOL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    17);
  return out;
}

static NeDsMethodOutput *ds_output_lv(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLV.mN = 17;
  out->mLV.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    17);
  return out;
}

static NeDsMethodOutput *ds_output_slv(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSLV.mN = 17;
  out->mSLV.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    17);
  return out;
}

static NeDsMethodOutput *ds_output_nldv(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mNLDV.mN = 17;
  out->mNLDV.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 17);
  return out;
}

static NeDsMethodOutput *ds_output_sclv(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSCLV.mN = 17;
  out->mSCLV.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 17);
  return out;
}

static NeDsMethodOutput *ds_output_imin(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mIMIN.mN = 17;
  out->mIMIN.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 17);
  return out;
}

static NeDsMethodOutput *ds_output_imax(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mIMAX.mN = 17;
  out->mIMAX.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 17);
  return out;
}

static NeDsMethodOutput *ds_output_dimin(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDIMIN.mN = 0;
  out->mDIMIN.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dimax(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDIMAX.mN = 0;
  out->mDIMAX.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static void release_reference(NeDynamicSystem *ds)
{
  _NeDynamicSystem *_ds;
  _ds = (_NeDynamicSystem *)ds;
  if (--_ds->mRefCnt == 0) {
    _ds->mAlloc.mFreeFcn(&_ds->mAlloc, _ds);
  }
}

static void get_reference(NeDynamicSystem *ds)
{
  _NeDynamicSystem *_ds;
  _ds = (_NeDynamicSystem *)ds;
  ++_ds->mRefCnt;
}

static NeDynamicSystem *diagnostics(NeDynamicSystem *ds, boolean_T kp)
{
  _NeDynamicSystem *_ds = (_NeDynamicSystem *)ds;
  (void) kp;
  ne_ds_get_reference(&_ds->mBase);
  return &_ds->mBase;
}

static void expand(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                   PmRealVector *out, boolean_T kp)
{
  (void)ds;
  (void)kp;
  memcpy(out->mX, in->mX.mX, sizeof(real_T)*out->mN);
}

static void rtpmap(const NeDynamicSystem * ds, const PmIntVector* inl, const
                   PmIntVector* ini, const PmIntVector* inj, const PmRealVector*
                   inr, PmIntVector* outl, PmIntVector* outi, PmIntVector* outj,
                   PmRealVector* outr)
{
  (void)ds;
  memcpy(outl->mX, inl->mX, sizeof(int32_T)*inl->mN);
  memcpy(outi->mX, ini->mX, sizeof(int32_T)*ini->mN);
  memcpy(outj->mX, inj->mX, sizeof(int32_T)*inj->mN);
  memcpy(outr->mX, inr->mX, sizeof(real_T)*inr->mN);
}

NeDynamicSystem *Main_Firmware_bbbdb992_1_dae_ds(PmAllocator *allocator)
{
  NeDynamicSystem *ds;
  _NeDynamicSystem *_ds;
  static SscIoInfo input_info[7];
  static SscIoInfo output_info[4];

  /* allocate dynamic system data and extended data */
  _ds = (_NeDynamicSystem *)allocator->mCallocFcn( allocator, sizeof
    (_NeDynamicSystem), 1);
  _ds->mAlloc = *allocator;
  _ds->mRefCnt = 1;
  ds = &_ds->mBase;

  /* setup sizes */
  ds->mNumVariables = 17;
  ds->mNumDiscreteRealVariables = 0;
  ds->mNumDifferentialVariables = 6;
  ds->mNumEquations = 17;
  ds->mNumCEResiduals = 0;
  ds->mNumICResiduals = 0;
  ds->mNumFreqs = 0;
  ds->mNumSolverHits = 0;
  ds->mNumModes = 6;
  ds->mNumMajorModes = 0;
  ds->mNumRealCache = 0;
  ds->mNumIntCache = 0;
  ds->mNumObservables = 228;
  ds->mNumObservableElements = 301;
  ds->mNumZcs = 6;
  ds->mNumAsserts = 6;
  ds->mNumAssertRanges = 6;
  ds->mNumParamAsserts = 0;
  ds->mNumParamAssertRanges = 0;
  ds->mNumInitialAsserts = 0;
  ds->mNumInitialAssertRanges = 0;
  ds->mNumRanges = 6;
  ds->mNumEquationRanges = 31;
  ds->mNumCERRanges = 0;
  ds->mNumICRRanges = 0;
  ds->mNumFundamentalSamples = 0;
  ds->mNumDelays = 0;
  ds->mNumLogicalParameters = 0;
  ds->mNumIntegerParameters = 0;
  ds->mNumIndexParameters = 0;
  ds->mNumRealParameters = 0;
  ds->mNumLogicalDerivedParameters = 0;
  ds->mNumIntegerDerivedParameters = 0;
  ds->mNumIndexDerivedParameters = 0;
  ds->mNumRealDerivedParameters = 0;
  ds->mIsOutputLinear = TRUE;
  ds->mIsOutputSwitchedLinear = TRUE;
  ds->mIsScalable = FALSE;

  /* setup ios */
  ds->mNumIo[SSC_INPUT_IO_TYPE] = 7;
  input_info[0].identifier =
    "FOC_test.Gate_Driver.Simulink_PS_Converter3_output0";
  input_info[0].size.numElements = 1;
  input_info[0].size.encodedDimensions = "1x1";
  input_info[0].name = "FOC_test.Gate_Driver.Simulink_PS_Converter3_output0";
  input_info[0].unit = "1";
  input_info[1].identifier =
    "FOC_test.Gate_Driver.Simulink_PS_Converter4_output0";
  input_info[1].size.numElements = 1;
  input_info[1].size.encodedDimensions = "1x1";
  input_info[1].name = "FOC_test.Gate_Driver.Simulink_PS_Converter4_output0";
  input_info[1].unit = "1";
  input_info[2].identifier =
    "FOC_test.Gate_Driver.Simulink_PS_Converter5_output0";
  input_info[2].size.numElements = 1;
  input_info[2].size.encodedDimensions = "1x1";
  input_info[2].name = "FOC_test.Gate_Driver.Simulink_PS_Converter5_output0";
  input_info[2].unit = "1";
  input_info[3].identifier =
    "FOC_test.Gate_Driver.Simulink_PS_Converter6_output0";
  input_info[3].size.numElements = 1;
  input_info[3].size.encodedDimensions = "1x1";
  input_info[3].name = "FOC_test.Gate_Driver.Simulink_PS_Converter6_output0";
  input_info[3].unit = "1";
  input_info[4].identifier =
    "FOC_test.Gate_Driver.Simulink_PS_Converter7_output0";
  input_info[4].size.numElements = 1;
  input_info[4].size.encodedDimensions = "1x1";
  input_info[4].name = "FOC_test.Gate_Driver.Simulink_PS_Converter7_output0";
  input_info[4].unit = "1";
  input_info[5].identifier =
    "FOC_test.Gate_Driver.Simulink_PS_Converter8_output0";
  input_info[5].size.numElements = 1;
  input_info[5].size.encodedDimensions = "1x1";
  input_info[5].name = "FOC_test.Gate_Driver.Simulink_PS_Converter8_output0";
  input_info[5].unit = "1";
  input_info[6].identifier = "FOC_test.Simulink_PS_Converter_output0";
  input_info[6].size.numElements = 1;
  input_info[6].size.encodedDimensions = "1x1";
  input_info[6].name = "FOC_test.Simulink_PS_Converter_output0";
  input_info[6].unit = "1";
  ds->mIo[SSC_INPUT_IO_TYPE] = input_info;
  ds->mNumIo[SSC_OUTPUT_IO_TYPE] = 4;
  output_info[0].identifier = "FOC_test.Current_Sensor_Three_Phase_I_output0";
  output_info[0].size.numElements = 3;
  output_info[0].size.encodedDimensions = "1x3";
  output_info[0].name = "FOC_test.Current_Sensor_Three_Phase_I_output0";
  output_info[0].unit = "A";
  output_info[1].identifier = "FOC_test.Ideal_Rotational_Motion_Sensor_A0";
  output_info[1].size.numElements = 1;
  output_info[1].size.encodedDimensions = "1x1";
  output_info[1].name = "FOC_test.Ideal_Rotational_Motion_Sensor_A0";
  output_info[1].unit = "rad";
  output_info[2].identifier = "FOC_test.Ideal_Rotational_Motion_Sensor_W0";
  output_info[2].size.numElements = 1;
  output_info[2].size.encodedDimensions = "1x1";
  output_info[2].name = "FOC_test.Ideal_Rotational_Motion_Sensor_W0";
  output_info[2].unit = "rad/s";
  output_info[3].identifier = "FOC_test.Ideal_Torque_Sensor_T0";
  output_info[3].size.numElements = 1;
  output_info[3].size.encodedDimensions = "1x1";
  output_info[3].name = "FOC_test.Ideal_Torque_Sensor_T0";
  output_info[3].unit = "N*m";
  ds->mIo[SSC_OUTPUT_IO_TYPE] = output_info;

  /* setup administration methods */
  ds->mReleaseReference = release_reference;
  ds->mGetReference = get_reference;
  ds->mDiagnosticsDsFcn = diagnostics;
  ds->mExpandFcn = expand;
  ds->mRtpMapFcn = rtpmap;
  ds->mMethods[NE_DS_METHOD_M_P] = Main_Firmware_bbbdb992_1_ds_m_p;
  ds->mMakeOutput[NE_DS_METHOD_M_P] = ds_output_m_p;
  ds->mMethods[NE_DS_METHOD_M] = ds_m;
  ds->mMakeOutput[NE_DS_METHOD_M] = ds_output_m;
  ds->mMethods[NE_DS_METHOD_VMM] = ds_vmm;
  ds->mMakeOutput[NE_DS_METHOD_VMM] = ds_output_vmm;
  ds->mMethods[NE_DS_METHOD_DXM_P] = ds_dxm_p;
  ds->mMakeOutput[NE_DS_METHOD_DXM_P] = ds_output_dxm_p;
  ds->mMethods[NE_DS_METHOD_DXM] = ds_dxm;
  ds->mMakeOutput[NE_DS_METHOD_DXM] = ds_output_dxm;
  ds->mMethods[NE_DS_METHOD_DDM_P] = ds_ddm_p;
  ds->mMakeOutput[NE_DS_METHOD_DDM_P] = ds_output_ddm_p;
  ds->mMethods[NE_DS_METHOD_DDM] = ds_ddm;
  ds->mMakeOutput[NE_DS_METHOD_DDM] = ds_output_ddm;
  ds->mMethods[NE_DS_METHOD_DUM_P] = ds_dum_p;
  ds->mMakeOutput[NE_DS_METHOD_DUM_P] = ds_output_dum_p;
  ds->mMethods[NE_DS_METHOD_DUM] = ds_dum;
  ds->mMakeOutput[NE_DS_METHOD_DUM] = ds_output_dum;
  ds->mMethods[NE_DS_METHOD_DTM_P] = ds_dtm_p;
  ds->mMakeOutput[NE_DS_METHOD_DTM_P] = ds_output_dtm_p;
  ds->mMethods[NE_DS_METHOD_DTM] = ds_dtm;
  ds->mMakeOutput[NE_DS_METHOD_DTM] = ds_output_dtm;
  ds->mMethods[NE_DS_METHOD_DPM_P] = ds_dpm_p;
  ds->mMakeOutput[NE_DS_METHOD_DPM_P] = ds_output_dpm_p;
  ds->mMethods[NE_DS_METHOD_DPM] = ds_dpm;
  ds->mMakeOutput[NE_DS_METHOD_DPM] = ds_output_dpm;
  ds->mMethods[NE_DS_METHOD_A_P] = Main_Firmware_bbbdb992_1_ds_a_p;
  ds->mMakeOutput[NE_DS_METHOD_A_P] = ds_output_a_p;
  ds->mMethods[NE_DS_METHOD_A] = ds_a;
  ds->mMakeOutput[NE_DS_METHOD_A] = ds_output_a;
  ds->mMethods[NE_DS_METHOD_B_P] = ds_b_p;
  ds->mMakeOutput[NE_DS_METHOD_B_P] = ds_output_b_p;
  ds->mMethods[NE_DS_METHOD_B] = ds_b;
  ds->mMakeOutput[NE_DS_METHOD_B] = ds_output_b;
  ds->mMethods[NE_DS_METHOD_C_P] = ds_c_p;
  ds->mMakeOutput[NE_DS_METHOD_C_P] = ds_output_c_p;
  ds->mMethods[NE_DS_METHOD_C] = ds_c;
  ds->mMakeOutput[NE_DS_METHOD_C] = ds_output_c;
  ds->mMethods[NE_DS_METHOD_F] = Main_Firmware_bbbdb992_1_ds_f;
  ds->mMakeOutput[NE_DS_METHOD_F] = ds_output_f;
  ds->mMethods[NE_DS_METHOD_VMF] = ds_vmf;
  ds->mMakeOutput[NE_DS_METHOD_VMF] = ds_output_vmf;
  ds->mMethods[NE_DS_METHOD_VPF] = ds_vpf;
  ds->mMakeOutput[NE_DS_METHOD_VPF] = ds_output_vpf;
  ds->mMethods[NE_DS_METHOD_VSF] = ds_vsf;
  ds->mMakeOutput[NE_DS_METHOD_VSF] = ds_output_vsf;
  ds->mMethods[NE_DS_METHOD_SLF] = ds_slf;
  ds->mMakeOutput[NE_DS_METHOD_SLF] = ds_output_slf;
  ds->mMethods[NE_DS_METHOD_SLF0] = ds_slf0;
  ds->mMakeOutput[NE_DS_METHOD_SLF0] = ds_output_slf0;
  ds->mMethods[NE_DS_METHOD_DXF_P] = Main_Firmware_bbbdb992_1_ds_dxf_p;
  ds->mMakeOutput[NE_DS_METHOD_DXF_P] = ds_output_dxf_p;
  ds->mMethods[NE_DS_METHOD_DXF] = Main_Firmware_bbbdb992_1_ds_dxf;
  ds->mMakeOutput[NE_DS_METHOD_DXF] = ds_output_dxf;
  ds->mMethods[NE_DS_METHOD_DUF_P] = ds_duf_p;
  ds->mMakeOutput[NE_DS_METHOD_DUF_P] = ds_output_duf_p;
  ds->mMethods[NE_DS_METHOD_DUF] = ds_duf;
  ds->mMakeOutput[NE_DS_METHOD_DUF] = ds_output_duf;
  ds->mMethods[NE_DS_METHOD_DTF_P] = ds_dtf_p;
  ds->mMakeOutput[NE_DS_METHOD_DTF_P] = ds_output_dtf_p;
  ds->mMethods[NE_DS_METHOD_DTF] = ds_dtf;
  ds->mMakeOutput[NE_DS_METHOD_DTF] = ds_output_dtf;
  ds->mMethods[NE_DS_METHOD_DDF_P] = ds_ddf_p;
  ds->mMakeOutput[NE_DS_METHOD_DDF_P] = ds_output_ddf_p;
  ds->mMethods[NE_DS_METHOD_DDF] = ds_ddf;
  ds->mMakeOutput[NE_DS_METHOD_DDF] = ds_output_ddf;
  ds->mMethods[NE_DS_METHOD_DPDXF_P] = ds_dpdxf_p;
  ds->mMakeOutput[NE_DS_METHOD_DPDXF_P] = ds_output_dpdxf_p;
  ds->mMethods[NE_DS_METHOD_DPDXF] = ds_dpdxf;
  ds->mMakeOutput[NE_DS_METHOD_DPDXF] = ds_output_dpdxf;
  ds->mMethods[NE_DS_METHOD_DWF_P] = ds_dwf_p;
  ds->mMakeOutput[NE_DS_METHOD_DWF_P] = ds_output_dwf_p;
  ds->mMethods[NE_DS_METHOD_DWF] = ds_dwf;
  ds->mMakeOutput[NE_DS_METHOD_DWF] = ds_output_dwf;
  ds->mMethods[NE_DS_METHOD_TDUF_P] = ds_tduf_p;
  ds->mMakeOutput[NE_DS_METHOD_TDUF_P] = ds_output_tduf_p;
  ds->mMethods[NE_DS_METHOD_TDXF_P] = Main_Firmware_bbbdb992_1_ds_tdxf_p;
  ds->mMakeOutput[NE_DS_METHOD_TDXF_P] = ds_output_tdxf_p;
  ds->mMethods[NE_DS_METHOD_DNF_P] = ds_dnf_p;
  ds->mMakeOutput[NE_DS_METHOD_DNF_P] = ds_output_dnf_p;
  ds->mMethods[NE_DS_METHOD_DNF] = ds_dnf;
  ds->mMakeOutput[NE_DS_METHOD_DNF] = ds_output_dnf;
  ds->mMethods[NE_DS_METHOD_DNF_V_X] = Main_Firmware_bbbdb992_1_ds_dnf_v_x;
  ds->mMakeOutput[NE_DS_METHOD_DNF_V_X] = ds_output_dnf_v_x;
  ds->mMethods[NE_DS_METHOD_CER] = ds_cer;
  ds->mMakeOutput[NE_DS_METHOD_CER] = ds_output_cer;
  ds->mMethods[NE_DS_METHOD_DXCER] = ds_dxcer;
  ds->mMakeOutput[NE_DS_METHOD_DXCER] = ds_output_dxcer;
  ds->mMethods[NE_DS_METHOD_DXCER_P] = ds_dxcer_p;
  ds->mMakeOutput[NE_DS_METHOD_DXCER_P] = ds_output_dxcer_p;
  ds->mMethods[NE_DS_METHOD_DDCER] = ds_ddcer;
  ds->mMakeOutput[NE_DS_METHOD_DDCER] = ds_output_ddcer;
  ds->mMethods[NE_DS_METHOD_DDCER_P] = ds_ddcer_p;
  ds->mMakeOutput[NE_DS_METHOD_DDCER_P] = ds_output_ddcer_p;
  ds->mMethods[NE_DS_METHOD_IC] = ds_ic;
  ds->mMakeOutput[NE_DS_METHOD_IC] = ds_output_ic;
  ds->mMethods[NE_DS_METHOD_ICR] = ds_icr;
  ds->mMakeOutput[NE_DS_METHOD_ICR] = ds_output_icr;
  ds->mMethods[NE_DS_METHOD_ICR_IM] = ds_icr_im;
  ds->mMakeOutput[NE_DS_METHOD_ICR_IM] = ds_output_icr_im;
  ds->mMethods[NE_DS_METHOD_ICR_ID] = ds_icr_id;
  ds->mMakeOutput[NE_DS_METHOD_ICR_ID] = ds_output_icr_id;
  ds->mMethods[NE_DS_METHOD_ICR_IL] = ds_icr_il;
  ds->mMakeOutput[NE_DS_METHOD_ICR_IL] = ds_output_icr_il;
  ds->mMethods[NE_DS_METHOD_DXICR] = ds_dxicr;
  ds->mMakeOutput[NE_DS_METHOD_DXICR] = ds_output_dxicr;
  ds->mMethods[NE_DS_METHOD_DXICR_P] = ds_dxicr_p;
  ds->mMakeOutput[NE_DS_METHOD_DXICR_P] = ds_output_dxicr_p;
  ds->mMethods[NE_DS_METHOD_DDICR] = ds_ddicr;
  ds->mMakeOutput[NE_DS_METHOD_DDICR] = ds_output_ddicr;
  ds->mMethods[NE_DS_METHOD_DDICR_P] = ds_ddicr_p;
  ds->mMakeOutput[NE_DS_METHOD_DDICR_P] = ds_output_ddicr_p;
  ds->mMethods[NE_DS_METHOD_TDUICR_P] = ds_tduicr_p;
  ds->mMakeOutput[NE_DS_METHOD_TDUICR_P] = ds_output_tduicr_p;
  ds->mMethods[NE_DS_METHOD_ICRM_P] = ds_icrm_p;
  ds->mMakeOutput[NE_DS_METHOD_ICRM_P] = ds_output_icrm_p;
  ds->mMethods[NE_DS_METHOD_ICRM] = ds_icrm;
  ds->mMakeOutput[NE_DS_METHOD_ICRM] = ds_output_icrm;
  ds->mMethods[NE_DS_METHOD_DXICRM_P] = ds_dxicrm_p;
  ds->mMakeOutput[NE_DS_METHOD_DXICRM_P] = ds_output_dxicrm_p;
  ds->mMethods[NE_DS_METHOD_DXICRM] = ds_dxicrm;
  ds->mMakeOutput[NE_DS_METHOD_DXICRM] = ds_output_dxicrm;
  ds->mMethods[NE_DS_METHOD_DDICRM_P] = ds_ddicrm_p;
  ds->mMakeOutput[NE_DS_METHOD_DDICRM_P] = ds_output_ddicrm_p;
  ds->mMethods[NE_DS_METHOD_DDICRM] = ds_ddicrm;
  ds->mMakeOutput[NE_DS_METHOD_DDICRM] = ds_output_ddicrm;
  ds->mMethods[NE_DS_METHOD_FREQS] = ds_freqs;
  ds->mMakeOutput[NE_DS_METHOD_FREQS] = ds_output_freqs;
  ds->mMethods[NE_DS_METHOD_SOLVERHITS] = ds_solverhits;
  ds->mMakeOutput[NE_DS_METHOD_SOLVERHITS] = ds_output_solverhits;
  ds->mMethods[NE_DS_METHOD_MDUY_P] = ds_mduy_p;
  ds->mMakeOutput[NE_DS_METHOD_MDUY_P] = ds_output_mduy_p;
  ds->mMethods[NE_DS_METHOD_MDXY_P] = ds_mdxy_p;
  ds->mMakeOutput[NE_DS_METHOD_MDXY_P] = ds_output_mdxy_p;
  ds->mMethods[NE_DS_METHOD_TDUY_P] = ds_tduy_p;
  ds->mMakeOutput[NE_DS_METHOD_TDUY_P] = ds_output_tduy_p;
  ds->mMethods[NE_DS_METHOD_TDXY_P] = Main_Firmware_bbbdb992_1_ds_tdxy_p;
  ds->mMakeOutput[NE_DS_METHOD_TDXY_P] = ds_output_tdxy_p;
  ds->mMethods[NE_DS_METHOD_Y] = ds_y;
  ds->mMakeOutput[NE_DS_METHOD_Y] = ds_output_y;
  ds->mMethods[NE_DS_METHOD_DXY_P] = Main_Firmware_bbbdb992_1_ds_dxy_p;
  ds->mMakeOutput[NE_DS_METHOD_DXY_P] = ds_output_dxy_p;
  ds->mMethods[NE_DS_METHOD_DXY] = ds_dxy;
  ds->mMakeOutput[NE_DS_METHOD_DXY] = ds_output_dxy;
  ds->mMethods[NE_DS_METHOD_DUY_P] = ds_duy_p;
  ds->mMakeOutput[NE_DS_METHOD_DUY_P] = ds_output_duy_p;
  ds->mMethods[NE_DS_METHOD_DUY] = ds_duy;
  ds->mMakeOutput[NE_DS_METHOD_DUY] = ds_output_duy;
  ds->mMethods[NE_DS_METHOD_DTY_P] = ds_dty_p;
  ds->mMakeOutput[NE_DS_METHOD_DTY_P] = ds_output_dty_p;
  ds->mMethods[NE_DS_METHOD_DTY] = ds_dty;
  ds->mMakeOutput[NE_DS_METHOD_DTY] = ds_output_dty;
  ds->mMethods[NE_DS_METHOD_MODE] = ds_mode;
  ds->mMakeOutput[NE_DS_METHOD_MODE] = ds_output_mode;
  ds->mMethods[NE_DS_METHOD_ZC] = ds_zc;
  ds->mMakeOutput[NE_DS_METHOD_ZC] = ds_output_zc;
  ds->mMethods[NE_DS_METHOD_CACHE_R] = ds_cache_r;
  ds->mMakeOutput[NE_DS_METHOD_CACHE_R] = ds_output_cache_r;
  ds->mMethods[NE_DS_METHOD_CACHE_I] = ds_cache_i;
  ds->mMakeOutput[NE_DS_METHOD_CACHE_I] = ds_output_cache_i;
  ds->mMethods[NE_DS_METHOD_UPDATE_R] = ds_update_r;
  ds->mMakeOutput[NE_DS_METHOD_UPDATE_R] = ds_output_update_r;
  ds->mMethods[NE_DS_METHOD_UPDATE_I] = ds_update_i;
  ds->mMakeOutput[NE_DS_METHOD_UPDATE_I] = ds_output_update_i;
  ds->mMethods[NE_DS_METHOD_UPDATE2_R] = ds_update2_r;
  ds->mMakeOutput[NE_DS_METHOD_UPDATE2_R] = ds_output_update2_r;
  ds->mMethods[NE_DS_METHOD_UPDATE2_I] = ds_update2_i;
  ds->mMakeOutput[NE_DS_METHOD_UPDATE2_I] = ds_output_update2_i;
  ds->mMethods[NE_DS_METHOD_LOCK_R] = ds_lock_r;
  ds->mMakeOutput[NE_DS_METHOD_LOCK_R] = ds_output_lock_r;
  ds->mMethods[NE_DS_METHOD_LOCK_I] = ds_lock_i;
  ds->mMakeOutput[NE_DS_METHOD_LOCK_I] = ds_output_lock_i;
  ds->mMethods[NE_DS_METHOD_LOCK2_R] = ds_lock2_r;
  ds->mMakeOutput[NE_DS_METHOD_LOCK2_R] = ds_output_lock2_r;
  ds->mMethods[NE_DS_METHOD_LOCK2_I] = ds_lock2_i;
  ds->mMakeOutput[NE_DS_METHOD_LOCK2_I] = ds_output_lock2_i;
  ds->mMethods[NE_DS_METHOD_SFO] = ds_sfo;
  ds->mMakeOutput[NE_DS_METHOD_SFO] = ds_output_sfo;
  ds->mMethods[NE_DS_METHOD_SFP] = ds_sfp;
  ds->mMakeOutput[NE_DS_METHOD_SFP] = ds_output_sfp;
  ds->mMethods[NE_DS_METHOD_INIT_R] = ds_init_r;
  ds->mMakeOutput[NE_DS_METHOD_INIT_R] = ds_output_init_r;
  ds->mMethods[NE_DS_METHOD_INIT_I] = ds_init_i;
  ds->mMakeOutput[NE_DS_METHOD_INIT_I] = ds_output_init_i;
  ds->mMethods[NE_DS_METHOD_LOG] = Main_Firmware_bbbdb992_1_ds_log;
  ds->mMakeOutput[NE_DS_METHOD_LOG] = ds_output_log;
  ds->mMethods[NE_DS_METHOD_ASSERT] = ds_assert;
  ds->mMakeOutput[NE_DS_METHOD_ASSERT] = ds_output_assert;
  ds->mMethods[NE_DS_METHOD_PASSERT] = ds_passert;
  ds->mMakeOutput[NE_DS_METHOD_PASSERT] = ds_output_passert;
  ds->mMethods[NE_DS_METHOD_IASSERT] = ds_iassert;
  ds->mMakeOutput[NE_DS_METHOD_IASSERT] = ds_output_iassert;
  ds->mMethods[NE_DS_METHOD_DEL_T] = ds_del_t;
  ds->mMakeOutput[NE_DS_METHOD_DEL_T] = ds_output_del_t;
  ds->mMethods[NE_DS_METHOD_DEL_V] = ds_del_v;
  ds->mMakeOutput[NE_DS_METHOD_DEL_V] = ds_output_del_v;
  ds->mMethods[NE_DS_METHOD_DEL_V0] = ds_del_v0;
  ds->mMakeOutput[NE_DS_METHOD_DEL_V0] = ds_output_del_v0;
  ds->mMethods[NE_DS_METHOD_DEL_TMAX] = ds_del_tmax;
  ds->mMakeOutput[NE_DS_METHOD_DEL_TMAX] = ds_output_del_tmax;
  ds->mMethods[NE_DS_METHOD_DXDELT_P] = ds_dxdelt_p;
  ds->mMakeOutput[NE_DS_METHOD_DXDELT_P] = ds_output_dxdelt_p;
  ds->mMethods[NE_DS_METHOD_DXDELT] = ds_dxdelt;
  ds->mMakeOutput[NE_DS_METHOD_DXDELT] = ds_output_dxdelt;
  ds->mMethods[NE_DS_METHOD_DUDELT_P] = ds_dudelt_p;
  ds->mMakeOutput[NE_DS_METHOD_DUDELT_P] = ds_output_dudelt_p;
  ds->mMethods[NE_DS_METHOD_DUDELT] = ds_dudelt;
  ds->mMakeOutput[NE_DS_METHOD_DUDELT] = ds_output_dudelt;
  ds->mMethods[NE_DS_METHOD_DTDELT_P] = ds_dtdelt_p;
  ds->mMakeOutput[NE_DS_METHOD_DTDELT_P] = ds_output_dtdelt_p;
  ds->mMethods[NE_DS_METHOD_DTDELT] = ds_dtdelt;
  ds->mMakeOutput[NE_DS_METHOD_DTDELT] = ds_output_dtdelt;
  ds->mMethods[NE_DS_METHOD_OBS_EXP] = Main_Firmware_bbbdb992_1_ds_obs_exp;
  ds->mMakeOutput[NE_DS_METHOD_OBS_EXP] = ds_output_obs_exp;
  ds->mMethods[NE_DS_METHOD_OBS_ACT] = Main_Firmware_bbbdb992_1_ds_obs_act;
  ds->mMakeOutput[NE_DS_METHOD_OBS_ACT] = ds_output_obs_act;
  ds->mMethods[NE_DS_METHOD_OBS_ALL] = Main_Firmware_bbbdb992_1_ds_obs_all;
  ds->mMakeOutput[NE_DS_METHOD_OBS_ALL] = ds_output_obs_all;
  ds->mMethods[NE_DS_METHOD_OBS_IL] = Main_Firmware_bbbdb992_1_ds_obs_il;
  ds->mMakeOutput[NE_DS_METHOD_OBS_IL] = ds_output_obs_il;
  ds->mMethods[NE_DS_METHOD_DP_L] = ds_dp_l;
  ds->mMakeOutput[NE_DS_METHOD_DP_L] = ds_output_dp_l;
  ds->mMethods[NE_DS_METHOD_DP_I] = ds_dp_i;
  ds->mMakeOutput[NE_DS_METHOD_DP_I] = ds_output_dp_i;
  ds->mMethods[NE_DS_METHOD_DP_J] = ds_dp_j;
  ds->mMakeOutput[NE_DS_METHOD_DP_J] = ds_output_dp_j;
  ds->mMethods[NE_DS_METHOD_DP_R] = ds_dp_r;
  ds->mMakeOutput[NE_DS_METHOD_DP_R] = ds_output_dp_r;
  ds->mMethods[NE_DS_METHOD_QX] = ds_qx;
  ds->mMakeOutput[NE_DS_METHOD_QX] = ds_output_qx;
  ds->mMethods[NE_DS_METHOD_QU] = ds_qu;
  ds->mMakeOutput[NE_DS_METHOD_QU] = ds_output_qu;
  ds->mMethods[NE_DS_METHOD_QT] = ds_qt;
  ds->mMakeOutput[NE_DS_METHOD_QT] = ds_output_qt;
  ds->mMethods[NE_DS_METHOD_Q1] = ds_q1;
  ds->mMakeOutput[NE_DS_METHOD_Q1] = ds_output_q1;
  ds->mMethods[NE_DS_METHOD_QX_P] = ds_qx_p;
  ds->mMakeOutput[NE_DS_METHOD_QX_P] = ds_output_qx_p;
  ds->mMethods[NE_DS_METHOD_QU_P] = ds_qu_p;
  ds->mMakeOutput[NE_DS_METHOD_QU_P] = ds_output_qu_p;
  ds->mMethods[NE_DS_METHOD_QT_P] = ds_qt_p;
  ds->mMakeOutput[NE_DS_METHOD_QT_P] = ds_output_qt_p;
  ds->mMethods[NE_DS_METHOD_Q1_P] = ds_q1_p;
  ds->mMakeOutput[NE_DS_METHOD_Q1_P] = ds_output_q1_p;
  ds->mMethods[NE_DS_METHOD_VAR_TOL] = ds_var_tol;
  ds->mMakeOutput[NE_DS_METHOD_VAR_TOL] = ds_output_var_tol;
  ds->mMethods[NE_DS_METHOD_EQ_TOL] = ds_eq_tol;
  ds->mMakeOutput[NE_DS_METHOD_EQ_TOL] = ds_output_eq_tol;
  ds->mMethods[NE_DS_METHOD_LV] = ds_lv;
  ds->mMakeOutput[NE_DS_METHOD_LV] = ds_output_lv;
  ds->mMethods[NE_DS_METHOD_SLV] = ds_slv;
  ds->mMakeOutput[NE_DS_METHOD_SLV] = ds_output_slv;
  ds->mMethods[NE_DS_METHOD_NLDV] = Main_Firmware_bbbdb992_1_ds_nldv;
  ds->mMakeOutput[NE_DS_METHOD_NLDV] = ds_output_nldv;
  ds->mMethods[NE_DS_METHOD_SCLV] = ds_sclv;
  ds->mMakeOutput[NE_DS_METHOD_SCLV] = ds_output_sclv;
  ds->mMethods[NE_DS_METHOD_IMIN] = ds_imin;
  ds->mMakeOutput[NE_DS_METHOD_IMIN] = ds_output_imin;
  ds->mMethods[NE_DS_METHOD_IMAX] = ds_imax;
  ds->mMakeOutput[NE_DS_METHOD_IMAX] = ds_output_imax;
  ds->mMethods[NE_DS_METHOD_DIMIN] = ds_dimin;
  ds->mMakeOutput[NE_DS_METHOD_DIMIN] = ds_output_dimin;
  ds->mMethods[NE_DS_METHOD_DIMAX] = ds_dimax;
  ds->mMakeOutput[NE_DS_METHOD_DIMAX] = ds_output_dimax;

  /* equation data */
  ds->mEquationData = s_equation_data;

  /* cer data */
  ds->mCERData = s_cer_data;

  /* icr data */
  ds->mICRData = s_icr_data;

  /* continuous variable data */
  ds->mVariableData = s_variable_data;

  /* discrete variable data */
  ds->mDiscreteData = s_discrete_data;

  /* observable data */
  ds->mObservableData = s_observable_data;

  /* major mode data */
  ds->mMajorModeData = s_major_mode_data;

  /* zc data */
  ds->mZCData = s_zc_data;

  /* ranges */
  ds->mRanges = s_range;

  /* assert data */
  ds->mAssertData = s_assert_data;

  /* assert ranges */
  ds->mAssertRanges = s_assert_range;

  /* param assert data */
  ds->mParamAssertData = s_param_assert_data;

  /* param assert ranges */
  ds->mParamAssertRanges = s_param_assert_range;

  /* initial assert data */
  ds->mInitialAssertData = s_initial_assert_data;

  /* initial assert ranges */
  ds->mInitialAssertRanges = s_initial_assert_range;

  /* equation ranges */
  ds->mEquationRanges = s_equation_range;

  /* cer ranges */
  ds->mCERRanges = s_cer_range;

  /* icr ranges */
  ds->mICRRanges = s_icr_range;

  /* parameters */
  ds->mLogicalParameters = s_logical_parameter_data;
  ds->mIntegerParameters = s_integer_parameter_data;
  ds->mIndexParameters = s_index_parameter_data;
  ds->mRealParameters = s_real_parameter_data;

  /* constant tables */
  _ds->mField0 = s_constant_table0;
  ds->mNumLargeArray = 1;
  return (NeDynamicSystem *)_ds;
}

static int32_T ds_assert (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mASSERT.mX[0] = 1;
  out->mASSERT.mX[1] = 1;
  out->mASSERT.mX[2] = 1;
  out->mASSERT.mX[3] = 1;
  out->mASSERT.mX[4] = 1;
  out->mASSERT.mX[5] = 1;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_passert (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_iassert (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_cer (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dxcer (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dxcer_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDXCER_P.mNumCol = 17ULL;
  out->mDXCER_P.mNumRow = 0ULL;
  out->mDXCER_P.mJc[0] = 0;
  out->mDXCER_P.mJc[1] = 0;
  out->mDXCER_P.mJc[2] = 0;
  out->mDXCER_P.mJc[3] = 0;
  out->mDXCER_P.mJc[4] = 0;
  out->mDXCER_P.mJc[5] = 0;
  out->mDXCER_P.mJc[6] = 0;
  out->mDXCER_P.mJc[7] = 0;
  out->mDXCER_P.mJc[8] = 0;
  out->mDXCER_P.mJc[9] = 0;
  out->mDXCER_P.mJc[10] = 0;
  out->mDXCER_P.mJc[11] = 0;
  out->mDXCER_P.mJc[12] = 0;
  out->mDXCER_P.mJc[13] = 0;
  out->mDXCER_P.mJc[14] = 0;
  out->mDXCER_P.mJc[15] = 0;
  out->mDXCER_P.mJc[16] = 0;
  out->mDXCER_P.mJc[17] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddcer (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddcer_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDDCER_P.mNumCol = 0ULL;
  out->mDDCER_P.mNumRow = 0ULL;
  out->mDDCER_P.mJc[0] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_del_v (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_del_v0 (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_del_tmax (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_del_t (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dxdelt (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dxdelt_p (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDXDELT_P.mNumCol = 17ULL;
  out->mDXDELT_P.mNumRow = 0ULL;
  out->mDXDELT_P.mJc[0] = 0;
  out->mDXDELT_P.mJc[1] = 0;
  out->mDXDELT_P.mJc[2] = 0;
  out->mDXDELT_P.mJc[3] = 0;
  out->mDXDELT_P.mJc[4] = 0;
  out->mDXDELT_P.mJc[5] = 0;
  out->mDXDELT_P.mJc[6] = 0;
  out->mDXDELT_P.mJc[7] = 0;
  out->mDXDELT_P.mJc[8] = 0;
  out->mDXDELT_P.mJc[9] = 0;
  out->mDXDELT_P.mJc[10] = 0;
  out->mDXDELT_P.mJc[11] = 0;
  out->mDXDELT_P.mJc[12] = 0;
  out->mDXDELT_P.mJc[13] = 0;
  out->mDXDELT_P.mJc[14] = 0;
  out->mDXDELT_P.mJc[15] = 0;
  out->mDXDELT_P.mJc[16] = 0;
  out->mDXDELT_P.mJc[17] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dudelt (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dudelt_p (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDUDELT_P.mNumCol = 7ULL;
  out->mDUDELT_P.mNumRow = 0ULL;
  out->mDUDELT_P.mJc[0] = 0;
  out->mDUDELT_P.mJc[1] = 0;
  out->mDUDELT_P.mJc[2] = 0;
  out->mDUDELT_P.mJc[3] = 0;
  out->mDUDELT_P.mJc[4] = 0;
  out->mDUDELT_P.mJc[5] = 0;
  out->mDUDELT_P.mJc[6] = 0;
  out->mDUDELT_P.mJc[7] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dtdelt (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dtdelt_p (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDTDELT_P.mNumCol = 1ULL;
  out->mDTDELT_P.mNumRow = 0ULL;
  out->mDTDELT_P.mJc[0] = 0;
  out->mDTDELT_P.mJc[1] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_cache_r (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_init_r (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_update_r (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_lock_r (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_cache_i (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_init_i (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_update_i (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_lock_i (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_update2_r (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_lock2_r (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_update2_i (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_lock2_i (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_sfp (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_sfo (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_duf (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_duf_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDUF_P.mNumCol = 7ULL;
  out->mDUF_P.mNumRow = 17ULL;
  out->mDUF_P.mJc[0] = 0;
  out->mDUF_P.mJc[1] = 0;
  out->mDUF_P.mJc[2] = 0;
  out->mDUF_P.mJc[3] = 0;
  out->mDUF_P.mJc[4] = 0;
  out->mDUF_P.mJc[5] = 0;
  out->mDUF_P.mJc[6] = 0;
  out->mDUF_P.mJc[7] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dtf (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dtf_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDTF_P.mNumCol = 1ULL;
  out->mDTF_P.mNumRow = 17ULL;
  out->mDTF_P.mJc[0] = 0;
  out->mDTF_P.mJc[1] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddf (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddf_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDDF_P.mNumCol = 0ULL;
  out->mDDF_P.mNumRow = 17ULL;
  out->mDDF_P.mJc[0] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_a (const NeDynamicSystem *LC, const NeDynamicSystemInput *t24,
                     NeDsMethodOutput *out)
{
  (void)t24;
  (void)LC;
  out->mA.mX[0ULL] = 1.0;
  out->mA.mX[3ULL] = -0.0;
  out->mA.mX[12ULL] = -0.65702055370538581;
  out->mA.mX[13ULL] = -1.0;
  out->mA.mX[1ULL] = -1.0;
  out->mA.mX[2ULL] = -1.0;
  out->mA.mX[4ULL] = 1.0;
  out->mA.mX[5ULL] = -1.0E-12;
  out->mA.mX[6ULL] = -1.0;
  out->mA.mX[7ULL] = 1.0;
  out->mA.mX[8ULL] = -1.0;
  out->mA.mX[9ULL] = 1.0;
  out->mA.mX[10ULL] = -1.0E-12;
  out->mA.mX[11ULL] = -1.0E-12;
  out->mA.mX[14ULL] = 1.0;
  out->mA.mX[15ULL] = 1.0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_b (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
                     NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mB.mX[0ULL] = 1.0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_b_p (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  static int32_T _cg_const_1[8] = { 0, 0, 0, 0, 0, 0, 0, 1 };

  (void)t1;
  (void)LC;
  out->mB_P.mNumCol = 7ULL;
  out->mB_P.mNumRow = 17ULL;
  out->mB_P.mJc[0] = _cg_const_1[0];
  out->mB_P.mJc[1] = _cg_const_1[1];
  out->mB_P.mJc[2] = _cg_const_1[2];
  out->mB_P.mJc[3] = _cg_const_1[3];
  out->mB_P.mJc[4] = _cg_const_1[4];
  out->mB_P.mJc[5] = _cg_const_1[5];
  out->mB_P.mJc[6] = _cg_const_1[6];
  out->mB_P.mJc[7] = _cg_const_1[7];
  out->mB_P.mIr[0] = 5;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_c (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
                     NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_c_p (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mC_P.mNumCol = 1ULL;
  out->mC_P.mNumRow = 17ULL;
  out->mC_P.mJc[0] = 0;
  out->mC_P.mJc[1] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_tduf_p (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_2[7] = { 6, 7, 8, 9, 10, 11, 5 };

  (void)t1;
  (void)LC;
  out->mTDUF_P.mNumCol = 7ULL;
  out->mTDUF_P.mNumRow = 17ULL;
  out->mTDUF_P.mJc[0] = 0;
  out->mTDUF_P.mJc[1] = 1;
  out->mTDUF_P.mJc[2] = 2;
  out->mTDUF_P.mJc[3] = 3;
  out->mTDUF_P.mJc[4] = 4;
  out->mTDUF_P.mJc[5] = 5;
  out->mTDUF_P.mJc[6] = 6;
  out->mTDUF_P.mJc[7] = 7;
  out->mTDUF_P.mIr[0] = _cg_const_2[0];
  out->mTDUF_P.mIr[1] = _cg_const_2[1];
  out->mTDUF_P.mIr[2] = _cg_const_2[2];
  out->mTDUF_P.mIr[3] = _cg_const_2[3];
  out->mTDUF_P.mIr[4] = _cg_const_2[4];
  out->mTDUF_P.mIr[5] = _cg_const_2[5];
  out->mTDUF_P.mIr[6] = _cg_const_2[6];
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dwf (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dwf_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDWF_P.mNumCol = 0ULL;
  out->mDWF_P.mNumRow = 17ULL;
  out->mDWF_P.mJc[0] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dpdxf (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dpdxf_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDPDXF_P.mNumCol = 0ULL;
  out->mDPDXF_P.mNumRow = 49ULL;
  out->mDPDXF_P.mJc[0] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_vmf (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  static boolean_T _cg_const_1[17] = { false, false, false, true, true, false,
    true, true, true, true, true, true, false, true, true, true, true };

  (void)t1;
  (void)LC;
  out->mVMF.mX[0] = _cg_const_1[0];
  out->mVMF.mX[1] = _cg_const_1[1];
  out->mVMF.mX[2] = _cg_const_1[2];
  out->mVMF.mX[3] = _cg_const_1[3];
  out->mVMF.mX[4] = _cg_const_1[4];
  out->mVMF.mX[5] = _cg_const_1[5];
  out->mVMF.mX[6] = _cg_const_1[6];
  out->mVMF.mX[7] = _cg_const_1[7];
  out->mVMF.mX[8] = _cg_const_1[8];
  out->mVMF.mX[9] = _cg_const_1[9];
  out->mVMF.mX[10] = _cg_const_1[10];
  out->mVMF.mX[11] = _cg_const_1[11];
  out->mVMF.mX[12] = _cg_const_1[12];
  out->mVMF.mX[13] = _cg_const_1[13];
  out->mVMF.mX[14] = _cg_const_1[14];
  out->mVMF.mX[15] = _cg_const_1[15];
  out->mVMF.mX[16] = _cg_const_1[16];
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_slf (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mSLF.mX[0] = false;
  out->mSLF.mX[1] = false;
  out->mSLF.mX[2] = false;
  out->mSLF.mX[3] = false;
  out->mSLF.mX[4] = false;
  out->mSLF.mX[5] = false;
  out->mSLF.mX[6] = false;
  out->mSLF.mX[7] = false;
  out->mSLF.mX[8] = false;
  out->mSLF.mX[9] = false;
  out->mSLF.mX[10] = false;
  out->mSLF.mX[11] = false;
  out->mSLF.mX[12] = false;
  out->mSLF.mX[13] = false;
  out->mSLF.mX[14] = false;
  out->mSLF.mX[15] = false;
  out->mSLF.mX[16] = false;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dnf (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dnf_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDNF_P.mNumCol = 21ULL;
  out->mDNF_P.mNumRow = 17ULL;
  out->mDNF_P.mJc[0] = 0;
  out->mDNF_P.mJc[1] = 0;
  out->mDNF_P.mJc[2] = 0;
  out->mDNF_P.mJc[3] = 0;
  out->mDNF_P.mJc[4] = 0;
  out->mDNF_P.mJc[5] = 0;
  out->mDNF_P.mJc[6] = 0;
  out->mDNF_P.mJc[7] = 0;
  out->mDNF_P.mJc[8] = 0;
  out->mDNF_P.mJc[9] = 0;
  out->mDNF_P.mJc[10] = 0;
  out->mDNF_P.mJc[11] = 0;
  out->mDNF_P.mJc[12] = 0;
  out->mDNF_P.mJc[13] = 0;
  out->mDNF_P.mJc[14] = 0;
  out->mDNF_P.mJc[15] = 0;
  out->mDNF_P.mJc[16] = 0;
  out->mDNF_P.mJc[17] = 0;
  out->mDNF_P.mJc[18] = 0;
  out->mDNF_P.mJc[19] = 0;
  out->mDNF_P.mJc[20] = 0;
  out->mDNF_P.mJc[21] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_slf0 (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mSLF0.mX[0] = false;
  out->mSLF0.mX[1] = false;
  out->mSLF0.mX[2] = false;
  out->mSLF0.mX[3] = false;
  out->mSLF0.mX[4] = false;
  out->mSLF0.mX[5] = false;
  out->mSLF0.mX[6] = false;
  out->mSLF0.mX[7] = false;
  out->mSLF0.mX[8] = false;
  out->mSLF0.mX[9] = false;
  out->mSLF0.mX[10] = false;
  out->mSLF0.mX[11] = false;
  out->mSLF0.mX[12] = false;
  out->mSLF0.mX[13] = false;
  out->mSLF0.mX[14] = false;
  out->mSLF0.mX[15] = false;
  out->mSLF0.mX[16] = false;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_vpf (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mVPF.mX[0] = false;
  out->mVPF.mX[1] = false;
  out->mVPF.mX[2] = false;
  out->mVPF.mX[3] = false;
  out->mVPF.mX[4] = false;
  out->mVPF.mX[5] = false;
  out->mVPF.mX[6] = false;
  out->mVPF.mX[7] = false;
  out->mVPF.mX[8] = false;
  out->mVPF.mX[9] = false;
  out->mVPF.mX[10] = false;
  out->mVPF.mX[11] = false;
  out->mVPF.mX[12] = false;
  out->mVPF.mX[13] = false;
  out->mVPF.mX[14] = false;
  out->mVPF.mX[15] = false;
  out->mVPF.mX[16] = false;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_vsf (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mVSF.mX[0] = false;
  out->mVSF.mX[1] = false;
  out->mVSF.mX[2] = false;
  out->mVSF.mX[3] = false;
  out->mVSF.mX[4] = false;
  out->mVSF.mX[5] = false;
  out->mVSF.mX[6] = false;
  out->mVSF.mX[7] = false;
  out->mVSF.mX[8] = false;
  out->mVSF.mX[9] = false;
  out->mVSF.mX[10] = false;
  out->mVSF.mX[11] = false;
  out->mVSF.mX[12] = false;
  out->mVSF.mX[13] = false;
  out->mVSF.mX[14] = false;
  out->mVSF.mX[15] = false;
  out->mVSF.mX[16] = false;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_freqs (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ic (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mIC.mX[0] = 0.0;
  out->mIC.mX[1] = 0.0;
  out->mIC.mX[2] = 0.0;
  out->mIC.mX[3] = 0.0;
  out->mIC.mX[4] = 0.0;
  out->mIC.mX[5] = 0.0;
  out->mIC.mX[6] = 0.0;
  out->mIC.mX[7] = 0.0;
  out->mIC.mX[8] = 0.0;
  out->mIC.mX[9] = 0.0;
  out->mIC.mX[10] = 0.0;
  out->mIC.mX[11] = 0.0;
  out->mIC.mX[12] = 0.0;
  out->mIC.mX[13] = 0.0;
  out->mIC.mX[14] = 0.0;
  out->mIC.mX[15] = 0.0;
  out->mIC.mX[16] = 0.0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_icr (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_icr_im (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_icr_id (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_icr_il (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dxicr (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dxicr_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDXICR_P.mNumCol = 17ULL;
  out->mDXICR_P.mNumRow = 0ULL;
  out->mDXICR_P.mJc[0] = 0;
  out->mDXICR_P.mJc[1] = 0;
  out->mDXICR_P.mJc[2] = 0;
  out->mDXICR_P.mJc[3] = 0;
  out->mDXICR_P.mJc[4] = 0;
  out->mDXICR_P.mJc[5] = 0;
  out->mDXICR_P.mJc[6] = 0;
  out->mDXICR_P.mJc[7] = 0;
  out->mDXICR_P.mJc[8] = 0;
  out->mDXICR_P.mJc[9] = 0;
  out->mDXICR_P.mJc[10] = 0;
  out->mDXICR_P.mJc[11] = 0;
  out->mDXICR_P.mJc[12] = 0;
  out->mDXICR_P.mJc[13] = 0;
  out->mDXICR_P.mJc[14] = 0;
  out->mDXICR_P.mJc[15] = 0;
  out->mDXICR_P.mJc[16] = 0;
  out->mDXICR_P.mJc[17] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddicr (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddicr_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDDICR_P.mNumCol = 0ULL;
  out->mDDICR_P.mNumRow = 0ULL;
  out->mDDICR_P.mJc[0] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_tduicr_p (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mTDUICR_P.mNumCol = 7ULL;
  out->mTDUICR_P.mNumRow = 0ULL;
  out->mTDUICR_P.mJc[0] = 0;
  out->mTDUICR_P.mJc[1] = 0;
  out->mTDUICR_P.mJc[2] = 0;
  out->mTDUICR_P.mJc[3] = 0;
  out->mTDUICR_P.mJc[4] = 0;
  out->mTDUICR_P.mJc[5] = 0;
  out->mTDUICR_P.mJc[6] = 0;
  out->mTDUICR_P.mJc[7] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_icrm (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_icrm_p (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mICRM_P.mNumCol = 17ULL;
  out->mICRM_P.mNumRow = 0ULL;
  out->mICRM_P.mJc[0] = 0;
  out->mICRM_P.mJc[1] = 0;
  out->mICRM_P.mJc[2] = 0;
  out->mICRM_P.mJc[3] = 0;
  out->mICRM_P.mJc[4] = 0;
  out->mICRM_P.mJc[5] = 0;
  out->mICRM_P.mJc[6] = 0;
  out->mICRM_P.mJc[7] = 0;
  out->mICRM_P.mJc[8] = 0;
  out->mICRM_P.mJc[9] = 0;
  out->mICRM_P.mJc[10] = 0;
  out->mICRM_P.mJc[11] = 0;
  out->mICRM_P.mJc[12] = 0;
  out->mICRM_P.mJc[13] = 0;
  out->mICRM_P.mJc[14] = 0;
  out->mICRM_P.mJc[15] = 0;
  out->mICRM_P.mJc[16] = 0;
  out->mICRM_P.mJc[17] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dxicrm (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dxicrm_p (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDXICRM_P.mNumCol = 17ULL;
  out->mDXICRM_P.mNumRow = 0ULL;
  out->mDXICRM_P.mJc[0] = 0;
  out->mDXICRM_P.mJc[1] = 0;
  out->mDXICRM_P.mJc[2] = 0;
  out->mDXICRM_P.mJc[3] = 0;
  out->mDXICRM_P.mJc[4] = 0;
  out->mDXICRM_P.mJc[5] = 0;
  out->mDXICRM_P.mJc[6] = 0;
  out->mDXICRM_P.mJc[7] = 0;
  out->mDXICRM_P.mJc[8] = 0;
  out->mDXICRM_P.mJc[9] = 0;
  out->mDXICRM_P.mJc[10] = 0;
  out->mDXICRM_P.mJc[11] = 0;
  out->mDXICRM_P.mJc[12] = 0;
  out->mDXICRM_P.mJc[13] = 0;
  out->mDXICRM_P.mJc[14] = 0;
  out->mDXICRM_P.mJc[15] = 0;
  out->mDXICRM_P.mJc[16] = 0;
  out->mDXICRM_P.mJc[17] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddicrm (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddicrm_p (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDDICRM_P.mNumCol = 0ULL;
  out->mDDICRM_P.mNumRow = 0ULL;
  out->mDDICRM_P.mJc[0] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_imin (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mIMIN.mX[0] = -pmf_get_inf();
  out->mIMIN.mX[1] = -pmf_get_inf();
  out->mIMIN.mX[2] = -pmf_get_inf();
  out->mIMIN.mX[3] = -pmf_get_inf();
  out->mIMIN.mX[4] = -pmf_get_inf();
  out->mIMIN.mX[5] = -pmf_get_inf();
  out->mIMIN.mX[6] = -pmf_get_inf();
  out->mIMIN.mX[7] = -pmf_get_inf();
  out->mIMIN.mX[8] = -pmf_get_inf();
  out->mIMIN.mX[9] = -pmf_get_inf();
  out->mIMIN.mX[10] = -pmf_get_inf();
  out->mIMIN.mX[11] = -pmf_get_inf();
  out->mIMIN.mX[12] = -pmf_get_inf();
  out->mIMIN.mX[13] = -pmf_get_inf();
  out->mIMIN.mX[14] = -pmf_get_inf();
  out->mIMIN.mX[15] = -pmf_get_inf();
  out->mIMIN.mX[16] = -pmf_get_inf();
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_imax (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mIMAX.mX[0] = pmf_get_inf();
  out->mIMAX.mX[1] = pmf_get_inf();
  out->mIMAX.mX[2] = pmf_get_inf();
  out->mIMAX.mX[3] = pmf_get_inf();
  out->mIMAX.mX[4] = pmf_get_inf();
  out->mIMAX.mX[5] = pmf_get_inf();
  out->mIMAX.mX[6] = pmf_get_inf();
  out->mIMAX.mX[7] = pmf_get_inf();
  out->mIMAX.mX[8] = pmf_get_inf();
  out->mIMAX.mX[9] = pmf_get_inf();
  out->mIMAX.mX[10] = pmf_get_inf();
  out->mIMAX.mX[11] = pmf_get_inf();
  out->mIMAX.mX[12] = pmf_get_inf();
  out->mIMAX.mX[13] = pmf_get_inf();
  out->mIMAX.mX[14] = pmf_get_inf();
  out->mIMAX.mX[15] = pmf_get_inf();
  out->mIMAX.mX[16] = pmf_get_inf();
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dimin (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dimax (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_m (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
                     NeDsMethodOutput *out)
{
  static real_T _cg_const_1[6] = { -1.0, 1.0, -1.0, 1.0E-6, -0.0005925,
    -0.00075344210129246172 };

  (void)t1;
  (void)LC;
  out->mM.mX[0] = _cg_const_1[0];
  out->mM.mX[1] = _cg_const_1[1];
  out->mM.mX[2] = _cg_const_1[2];
  out->mM.mX[3] = _cg_const_1[3];
  out->mM.mX[4] = _cg_const_1[4];
  out->mM.mX[5] = _cg_const_1[5];
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dxm (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dxm_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDXM_P.mNumCol = 17ULL;
  out->mDXM_P.mNumRow = 6ULL;
  out->mDXM_P.mJc[0] = 0;
  out->mDXM_P.mJc[1] = 0;
  out->mDXM_P.mJc[2] = 0;
  out->mDXM_P.mJc[3] = 0;
  out->mDXM_P.mJc[4] = 0;
  out->mDXM_P.mJc[5] = 0;
  out->mDXM_P.mJc[6] = 0;
  out->mDXM_P.mJc[7] = 0;
  out->mDXM_P.mJc[8] = 0;
  out->mDXM_P.mJc[9] = 0;
  out->mDXM_P.mJc[10] = 0;
  out->mDXM_P.mJc[11] = 0;
  out->mDXM_P.mJc[12] = 0;
  out->mDXM_P.mJc[13] = 0;
  out->mDXM_P.mJc[14] = 0;
  out->mDXM_P.mJc[15] = 0;
  out->mDXM_P.mJc[16] = 0;
  out->mDXM_P.mJc[17] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddm (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_ddm_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDDM_P.mNumCol = 0ULL;
  out->mDDM_P.mNumRow = 6ULL;
  out->mDDM_P.mJc[0] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dum (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dum_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDUM_P.mNumCol = 7ULL;
  out->mDUM_P.mNumRow = 6ULL;
  out->mDUM_P.mJc[0] = 0;
  out->mDUM_P.mJc[1] = 0;
  out->mDUM_P.mJc[2] = 0;
  out->mDUM_P.mJc[3] = 0;
  out->mDUM_P.mJc[4] = 0;
  out->mDUM_P.mJc[5] = 0;
  out->mDUM_P.mJc[6] = 0;
  out->mDUM_P.mJc[7] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dtm (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dtm_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDTM_P.mNumCol = 1ULL;
  out->mDTM_P.mNumRow = 6ULL;
  out->mDTM_P.mJc[0] = 0;
  out->mDTM_P.mJc[1] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dpm (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dpm_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDPM_P.mNumCol = 0ULL;
  out->mDPM_P.mNumRow = 6ULL;
  out->mDPM_P.mJc[0] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_vmm (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mVMM.mX[0] = false;
  out->mVMM.mX[1] = false;
  out->mVMM.mX[2] = false;
  out->mVMM.mX[3] = false;
  out->mVMM.mX[4] = false;
  out->mVMM.mX[5] = false;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_mode (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)LC;
  out->mMODE.mX[0ULL] = (int32_T)(t1->mU.mX[0ULL] > 6.0);
  out->mMODE.mX[1ULL] = (int32_T)(t1->mU.mX[1ULL] > 6.0);
  out->mMODE.mX[2ULL] = (int32_T)(t1->mU.mX[2ULL] > 6.0);
  out->mMODE.mX[3ULL] = (int32_T)(t1->mU.mX[3ULL] > 6.0);
  out->mMODE.mX[4ULL] = (int32_T)(t1->mU.mX[4ULL] > 6.0);
  out->mMODE.mX[5ULL] = (int32_T)(t1->mU.mX[5ULL] > 6.0);
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dp_l (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dp_i (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dp_j (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dp_r (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_qx (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_qu (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_qt (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_q1 (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_qx_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mQX_P.mNumCol = 17ULL;
  out->mQX_P.mNumRow = 17ULL;
  out->mQX_P.mJc[0] = 0;
  out->mQX_P.mJc[1] = 0;
  out->mQX_P.mJc[2] = 0;
  out->mQX_P.mJc[3] = 0;
  out->mQX_P.mJc[4] = 0;
  out->mQX_P.mJc[5] = 0;
  out->mQX_P.mJc[6] = 0;
  out->mQX_P.mJc[7] = 0;
  out->mQX_P.mJc[8] = 0;
  out->mQX_P.mJc[9] = 0;
  out->mQX_P.mJc[10] = 0;
  out->mQX_P.mJc[11] = 0;
  out->mQX_P.mJc[12] = 0;
  out->mQX_P.mJc[13] = 0;
  out->mQX_P.mJc[14] = 0;
  out->mQX_P.mJc[15] = 0;
  out->mQX_P.mJc[16] = 0;
  out->mQX_P.mJc[17] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_qu_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mQU_P.mNumCol = 7ULL;
  out->mQU_P.mNumRow = 17ULL;
  out->mQU_P.mJc[0] = 0;
  out->mQU_P.mJc[1] = 0;
  out->mQU_P.mJc[2] = 0;
  out->mQU_P.mJc[3] = 0;
  out->mQU_P.mJc[4] = 0;
  out->mQU_P.mJc[5] = 0;
  out->mQU_P.mJc[6] = 0;
  out->mQU_P.mJc[7] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_qt_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mQT_P.mNumCol = 1ULL;
  out->mQT_P.mNumRow = 17ULL;
  out->mQT_P.mJc[0] = 0;
  out->mQT_P.mJc[1] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_q1_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mQ1_P.mNumCol = 1ULL;
  out->mQ1_P.mNumRow = 17ULL;
  out->mQ1_P.mJc[0] = 0;
  out->mQ1_P.mJc[1] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_solverhits (const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_var_tol (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mVAR_TOL.mX[0] = 1.0E-9;
  out->mVAR_TOL.mX[1] = 1.0E-9;
  out->mVAR_TOL.mX[2] = 1.0E-9;
  out->mVAR_TOL.mX[3] = 1.0E-9;
  out->mVAR_TOL.mX[4] = 1.0E-9;
  out->mVAR_TOL.mX[5] = 1.0E-9;
  out->mVAR_TOL.mX[6] = 1.0E-9;
  out->mVAR_TOL.mX[7] = 1.0E-9;
  out->mVAR_TOL.mX[8] = 1.0E-9;
  out->mVAR_TOL.mX[9] = 1.0E-9;
  out->mVAR_TOL.mX[10] = 1.0E-9;
  out->mVAR_TOL.mX[11] = 1.0E-9;
  out->mVAR_TOL.mX[12] = 1.0E-9;
  out->mVAR_TOL.mX[13] = 1.0E-9;
  out->mVAR_TOL.mX[14] = 1.0E-9;
  out->mVAR_TOL.mX[15] = 1.0E-9;
  out->mVAR_TOL.mX[16] = 1.0E-9;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_eq_tol (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mEQ_TOL.mX[0] = 1.0E-9;
  out->mEQ_TOL.mX[1] = 1.0E-9;
  out->mEQ_TOL.mX[2] = 1.0E-9;
  out->mEQ_TOL.mX[3] = 1.0E-9;
  out->mEQ_TOL.mX[4] = 1.0E-9;
  out->mEQ_TOL.mX[5] = 1.0E-9;
  out->mEQ_TOL.mX[6] = 1.0E-9;
  out->mEQ_TOL.mX[7] = 1.0E-9;
  out->mEQ_TOL.mX[8] = 1.0E-9;
  out->mEQ_TOL.mX[9] = 1.0E-9;
  out->mEQ_TOL.mX[10] = 1.0E-9;
  out->mEQ_TOL.mX[11] = 1.0E-9;
  out->mEQ_TOL.mX[12] = 1.0E-9;
  out->mEQ_TOL.mX[13] = 1.0E-9;
  out->mEQ_TOL.mX[14] = 1.0E-9;
  out->mEQ_TOL.mX[15] = 1.0E-9;
  out->mEQ_TOL.mX[16] = 1.0E-9;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_lv (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *out)
{
  static boolean_T _cg_const_1[17] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, false };

  (void)t1;
  (void)LC;
  out->mLV.mX[0] = _cg_const_1[0];
  out->mLV.mX[1] = _cg_const_1[1];
  out->mLV.mX[2] = _cg_const_1[2];
  out->mLV.mX[3] = _cg_const_1[3];
  out->mLV.mX[4] = _cg_const_1[4];
  out->mLV.mX[5] = _cg_const_1[5];
  out->mLV.mX[6] = _cg_const_1[6];
  out->mLV.mX[7] = _cg_const_1[7];
  out->mLV.mX[8] = _cg_const_1[8];
  out->mLV.mX[9] = _cg_const_1[9];
  out->mLV.mX[10] = _cg_const_1[10];
  out->mLV.mX[11] = _cg_const_1[11];
  out->mLV.mX[12] = _cg_const_1[12];
  out->mLV.mX[13] = _cg_const_1[13];
  out->mLV.mX[14] = _cg_const_1[14];
  out->mLV.mX[15] = _cg_const_1[15];
  out->mLV.mX[16] = _cg_const_1[16];
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_slv (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  static boolean_T _cg_const_1[17] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, false };

  (void)t1;
  (void)LC;
  out->mSLV.mX[0] = _cg_const_1[0];
  out->mSLV.mX[1] = _cg_const_1[1];
  out->mSLV.mX[2] = _cg_const_1[2];
  out->mSLV.mX[3] = _cg_const_1[3];
  out->mSLV.mX[4] = _cg_const_1[4];
  out->mSLV.mX[5] = _cg_const_1[5];
  out->mSLV.mX[6] = _cg_const_1[6];
  out->mSLV.mX[7] = _cg_const_1[7];
  out->mSLV.mX[8] = _cg_const_1[8];
  out->mSLV.mX[9] = _cg_const_1[9];
  out->mSLV.mX[10] = _cg_const_1[10];
  out->mSLV.mX[11] = _cg_const_1[11];
  out->mSLV.mX[12] = _cg_const_1[12];
  out->mSLV.mX[13] = _cg_const_1[13];
  out->mSLV.mX[14] = _cg_const_1[14];
  out->mSLV.mX[15] = _cg_const_1[15];
  out->mSLV.mX[16] = _cg_const_1[16];
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_sclv (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mSCLV.mX[0] = false;
  out->mSCLV.mX[1] = false;
  out->mSCLV.mX[2] = false;
  out->mSCLV.mX[3] = false;
  out->mSCLV.mX[4] = false;
  out->mSCLV.mX[5] = false;
  out->mSCLV.mX[6] = false;
  out->mSCLV.mX[7] = false;
  out->mSCLV.mX[8] = false;
  out->mSCLV.mX[9] = false;
  out->mSCLV.mX[10] = false;
  out->mSCLV.mX[11] = false;
  out->mSCLV.mX[12] = false;
  out->mSCLV.mX[13] = false;
  out->mSCLV.mX[14] = false;
  out->mSCLV.mX[15] = false;
  out->mSCLV.mX[16] = false;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_y (const NeDynamicSystem *LC, const NeDynamicSystemInput *t10,
                     NeDsMethodOutput *out)
{
  (void)LC;
  out->mY.mX[0ULL] = -t10->mX.mX[9ULL] - t10->mX.mX[10ULL];
  out->mY.mX[1ULL] = t10->mX.mX[9ULL];
  out->mY.mX[2ULL] = t10->mX.mX[10ULL];
  out->mY.mX[4ULL] = t10->mX.mX[0ULL];
  out->mY.mX[5ULL] = -t10->mU.mX[6ULL] + t10->mX.mX[15ULL];
  out->mY.mX[3ULL] = t10->mX.mX[1ULL];
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dxy (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t16, NeDsMethodOutput *out)
{
  (void)t16;
  (void)LC;
  out->mDXY.mX[2ULL] = -1.0;
  out->mDXY.mX[3ULL] = 1.0;
  out->mDXY.mX[4ULL] = 0.0;
  out->mDXY.mX[5ULL] = -1.0;
  out->mDXY.mX[6ULL] = 0.0;
  out->mDXY.mX[7ULL] = 1.0;
  out->mDXY.mX[0ULL] = 1.0;
  out->mDXY.mX[1ULL] = 1.0;
  out->mDXY.mX[8ULL] = 1.0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_duy (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDUY.mX[0ULL] = -1.0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_duy_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_1[8] = { 0, 0, 0, 0, 0, 0, 0, 1 };

  (void)t1;
  (void)LC;
  out->mDUY_P.mNumCol = 7ULL;
  out->mDUY_P.mNumRow = 6ULL;
  out->mDUY_P.mJc[0] = _cg_const_1[0];
  out->mDUY_P.mJc[1] = _cg_const_1[1];
  out->mDUY_P.mJc[2] = _cg_const_1[2];
  out->mDUY_P.mJc[3] = _cg_const_1[3];
  out->mDUY_P.mJc[4] = _cg_const_1[4];
  out->mDUY_P.mJc[5] = _cg_const_1[5];
  out->mDUY_P.mJc[6] = _cg_const_1[6];
  out->mDUY_P.mJc[7] = _cg_const_1[7];
  out->mDUY_P.mIr[0] = 5;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_mduy_p (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mMDUY_P.mNumCol = 7ULL;
  out->mMDUY_P.mNumRow = 6ULL;
  out->mMDUY_P.mJc[0] = 0;
  out->mMDUY_P.mJc[1] = 0;
  out->mMDUY_P.mJc[2] = 0;
  out->mMDUY_P.mJc[3] = 0;
  out->mMDUY_P.mJc[4] = 0;
  out->mMDUY_P.mJc[5] = 0;
  out->mMDUY_P.mJc[6] = 0;
  out->mMDUY_P.mJc[7] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_mdxy_p (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mMDXY_P.mNumCol = 17ULL;
  out->mMDXY_P.mNumRow = 6ULL;
  out->mMDXY_P.mJc[0] = 0;
  out->mMDXY_P.mJc[1] = 0;
  out->mMDXY_P.mJc[2] = 0;
  out->mMDXY_P.mJc[3] = 0;
  out->mMDXY_P.mJc[4] = 0;
  out->mMDXY_P.mJc[5] = 0;
  out->mMDXY_P.mJc[6] = 0;
  out->mMDXY_P.mJc[7] = 0;
  out->mMDXY_P.mJc[8] = 0;
  out->mMDXY_P.mJc[9] = 0;
  out->mMDXY_P.mJc[10] = 0;
  out->mMDXY_P.mJc[11] = 0;
  out->mMDXY_P.mJc[12] = 0;
  out->mMDXY_P.mJc[13] = 0;
  out->mMDXY_P.mJc[14] = 0;
  out->mMDXY_P.mJc[15] = 0;
  out->mMDXY_P.mJc[16] = 0;
  out->mMDXY_P.mJc[17] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_tduy_p (const NeDynamicSystem *LC, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_1[8] = { 0, 0, 0, 0, 0, 0, 0, 1 };

  (void)t1;
  (void)LC;
  out->mTDUY_P.mNumCol = 7ULL;
  out->mTDUY_P.mNumRow = 6ULL;
  out->mTDUY_P.mJc[0] = _cg_const_1[0];
  out->mTDUY_P.mJc[1] = _cg_const_1[1];
  out->mTDUY_P.mJc[2] = _cg_const_1[2];
  out->mTDUY_P.mJc[3] = _cg_const_1[3];
  out->mTDUY_P.mJc[4] = _cg_const_1[4];
  out->mTDUY_P.mJc[5] = _cg_const_1[5];
  out->mTDUY_P.mJc[6] = _cg_const_1[6];
  out->mTDUY_P.mJc[7] = _cg_const_1[7];
  out->mTDUY_P.mIr[0] = 5;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dty (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
  NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  (void)out;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_dty_p (const NeDynamicSystem *LC, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)LC;
  out->mDTY_P.mNumCol = 1ULL;
  out->mDTY_P.mNumRow = 6ULL;
  out->mDTY_P.mJc[0] = 0;
  out->mDTY_P.mJc[1] = 0;
  (void)LC;
  (void)out;
  return 0;
}

static int32_T ds_zc (const NeDynamicSystem *LC, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *out)
{
  (void)LC;
  out->mZC.mX[0ULL] = t1->mU.mX[0ULL] - 6.0;
  out->mZC.mX[1ULL] = t1->mU.mX[1ULL] - 6.0;
  out->mZC.mX[2ULL] = t1->mU.mX[2ULL] - 6.0;
  out->mZC.mX[3ULL] = t1->mU.mX[3ULL] - 6.0;
  out->mZC.mX[4ULL] = t1->mU.mX[4ULL] - 6.0;
  out->mZC.mX[5ULL] = t1->mU.mX[5ULL] - 6.0;
  (void)LC;
  (void)out;
  return 0;
}
