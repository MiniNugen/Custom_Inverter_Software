/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: rtGetNaN.c
 *
 * Code generated for Simulink model 'Main_Firmware'.
 *
 * Model version                  : 2.32
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
 * C/C++ source code generated on : Sat Jul 12 16:27:19 2025
=======
 * C/C++ source code generated on : Fri Jul 11 14:41:25 2025
>>>>>>> Stashed changes
=======
 * C/C++ source code generated on : Fri Jul 11 14:41:25 2025
>>>>>>> Stashed changes
=======
 * C/C++ source code generated on : Fri Jul 11 14:41:25 2025
>>>>>>> Stashed changes
=======
 * C/C++ source code generated on : Fri Jul 11 14:41:25 2025
>>>>>>> Stashed changes
=======
 * C/C++ source code generated on : Fri Jul 11 14:41:25 2025
>>>>>>> Stashed changes
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "rtGetNaN.h"
#include <stddef.h>
#include "rt_nonfinite.h"
#define NumBitsPerChar                 16U

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
