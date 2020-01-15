/* { dg-do compile } */
/* { dg-options "-mcmse -mfloat-abi=hard -mfpu=fpv5-sp-d16" }  */
/* { dg-skip-if "Incompatible float ABI" { *-*-* } { "-mfloat-abi=*" } { "-mfloat-abi=hard" } } */
/* { dg-skip-if "Skip these if testing double precision" {*-*-*} {"-mfpu=fpv[4-5]-d16"} {""} } */

#include "../../../cmse-13.x"

/* Checks for saving and clearing prior to function call.  */
/* { dg-final { scan-assembler "lsrs\tr4, r4, #1" } } */
/* { dg-final { scan-assembler "lsls\tr4, r4, #1" } } */
/* { dg-final { scan-assembler "push\t\{r4, r5, r6, r7, r8, r9, r10, fp\}" } } */
/* { dg-final { scan-assembler "clrm\t\{r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, fp, ip, APSR\}" } } */
/* { dg-final { scan-assembler-not "vmov\.f32\ts0, #1\.0" } } */
/* { dg-final { scan-assembler-not "vmov\.f32\ts2, #1\.0" } } */
/* { dg-final { scan-assembler-not "vmov\.f32\ts3, #1\.0" } } */
/* { dg-final { scan-assembler "vscclrm\t\{s1, VPR\}" } } */
/* { dg-final { scan-assembler "vscclrm\t\{s4-s15, VPR\}" } } */
/* { dg-final { scan-assembler "pop\t\{r4, r5, r6, r7, r8, r9, r10, fp\}" } } */

/* Now we check that we use the correct intrinsic to call.  */
/* { dg-final { scan-assembler "bl\t__gnu_cmse_nonsecure_call" } } */
