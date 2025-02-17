/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Main_Firmware/FOC test/Solver Configuration'.
 */

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#include "nesl_rtw.h"
#include "Main_Firmware_bbbdb992_1.h"
#include "Main_Firmware_bbbdb992_1_gateway.h"

void Main_Firmware_bbbdb992_1_gateway(void)
{
  NeModelParameters modelparams = { (enum NeSolverTypeTag)0, 0.001, 0.001, 0.001,
    FALSE, FALSE, (enum NeModifyAbsTolTag)0, 0.001, 0.0, FALSE, FALSE, FALSE, (
    enum SscLoggingSettingTag)0, 661725626.0, TRUE, FALSE, FALSE };

  NeSolverParameters solverparams = { FALSE, FALSE, TRUE, FALSE, FALSE, 0.001,
    0.001, 1e-09, FALSE, FALSE, 100U, FALSE, 1U, (enum NeConsistencySolverTag)2,
    (enum NeIndexReductionMethodTag)0, FALSE, 1e-09, (enum NeToleranceSourceTag)
    1, 0.001, 0.001, 0.001, TRUE, (enum NeLocalSolverChoiceTag)1, TRUE, 1U,
    1e-06, TRUE, 3U, 2U, FALSE, 2U, (enum NeLinearAlgebraChoiceTag)0, 0U, (enum
    NeEquationFormulationChoiceTag)0, 1024U, TRUE, 0.001, (enum
    NePartitionStorageMethodTag)0, 1024U, (enum NePartitionMethodTag)0, FALSE, (
    enum NeMultibodyLocalSolverChoiceTag)0, 0.001 };

  const NeOutputParameters* outputparameters = NULL;
  NeDae* dae;
  size_t numOutputs = 0;
  int* rtpDaes = NULL;
  int* rtwLogDaes = NULL;
  int* solverHitDaes = NULL;

  {
    static const NeOutputParameters outputparameters_init[] = { { 0U, 0U }, { 0U,
        1U }, };

    outputparameters = outputparameters_init;
    numOutputs = sizeof(outputparameters_init)/sizeof(outputparameters_init[0]);
  }

  Main_Firmware_bbbdb992_1_dae(&dae,
    &modelparams,
    &solverparams);
  nesl_register_simulator_group("Main_Firmware/FOC test/Solver Configuration_1",
    1,
    &dae,
    &solverparams,
    &modelparams,
    numOutputs,
    outputparameters,
    0,
    rtpDaes,
    0,
    rtwLogDaes,
    0,
    solverHitDaes);
}
