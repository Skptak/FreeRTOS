/*
 * FreeRTOS V202212.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

/*
 * "Reg test" tasks - These fill the registers with known values, then check
 * that each register maintains its expected value for the lifetime of the
 * task.  Each task uses a different set of values.  The reg test tasks execute
 * with a very low priority, so get preempted very frequently.  A register
 * containing an unexpected value is indicative of an error in the context
 * switching mechanism.
 */

void vRegTest1Implementation( void ) __attribute__ ((naked));
void vRegTest2Implementation( void ) __attribute__ ((naked));

void vRegTest1Implementation( void )
{
	__asm volatile
	(
		".extern ulRegTest1LoopCounter \n"

		/* Fill the core registers with known values. */
		"mov r0, #100					\n"
		"mov r1, #101					\n"
		"mov r2, #102					\n"
		"mov r3, #103					\n"
		"mov r4, #104					\n"
		"mov r5, #105					\n"
		"mov r6, #106					\n"
		"mov r7, #107					\n"
		"mov r8, #108					\n"
		"mov r9, #109					\n"
		"mov r10, #110					\n"
		"mov r11, #111					\n"
		"mov r12, #112					\n"

		/* Fill the VFP registers with known values. */
		"vmov d0, r0, r1				\n"
		"vmov d1, r2, r3				\n"
		"vmov d2, r4, r5				\n"
		"vmov d3, r6, r7				\n"
		"vmov d4, r8, r9				\n"
		"vmov d5, r10, r11				\n"
		"vmov d6, r0, r1				\n"
		"vmov d7, r2, r3				\n"
		"vmov d8, r4, r5				\n"
		"vmov d9, r6, r7				\n"
		"vmov d10, r8, r9				\n"
		"vmov d11, r10, r11				\n"
		"vmov d12, r0, r1				\n"
		"vmov d13, r2, r3				\n"
		"vmov d14, r4, r5				\n"
		"vmov d15, r6, r7				\n"

	"reg1_loop:							\n"
		/* Check all the VFP registers still contain the values set above.
		First save registers that are clobbered by the test. */
		"push { r0-r1 }					\n"

		"vmov r0, r1, d0				\n"
		"cmp r0, #100					\n"
		"bne reg1_error_loopf			\n"
		"cmp r1, #101					\n"
		"bne reg1_error_loopf			\n"
		"vmov r0, r1, d1				\n"
		"cmp r0, #102					\n"
		"bne reg1_error_loopf			\n"
		"cmp r1, #103					\n"
		"bne reg1_error_loopf			\n"
		"vmov r0, r1, d2				\n"
		"cmp r0, #104					\n"
		"bne reg1_error_loopf			\n"
		"cmp r1, #105					\n"
		"bne reg1_error_loopf			\n"
		"vmov r0, r1, d3				\n"
		"cmp r0, #106					\n"
		"bne reg1_error_loopf			\n"
		"cmp r1, #107					\n"
		"bne reg1_error_loopf			\n"
		"vmov r0, r1, d4				\n"
		"cmp r0, #108					\n"
		"bne reg1_error_loopf			\n"
		"cmp r1, #109					\n"
		"bne reg1_error_loopf			\n"
		"vmov r0, r1, d5				\n"
		"cmp r0, #110					\n"
		"bne reg1_error_loopf			\n"
		"cmp r1, #111					\n"
		"bne reg1_error_loopf			\n"
		"vmov r0, r1, d6				\n"
		"cmp r0, #100					\n"
		"bne reg1_error_loopf			\n"
		"cmp r1, #101					\n"
		"bne reg1_error_loopf			\n"
		"vmov r0, r1, d7				\n"
		"cmp r0, #102					\n"
		"bne reg1_error_loopf			\n"
		"cmp r1, #103					\n"
		"bne reg1_error_loopf			\n"
		"vmov r0, r1, d8				\n"
		"cmp r0, #104					\n"
		"bne reg1_error_loopf			\n"
		"cmp r1, #105					\n"
		"bne reg1_error_loopf			\n"
		"vmov r0, r1, d9				\n"
		"cmp r0, #106					\n"
		"bne reg1_error_loopf			\n"
		"cmp r1, #107					\n"
		"bne reg1_error_loopf			\n"
		"vmov r0, r1, d10				\n"
		"cmp r0, #108					\n"
		"bne reg1_error_loopf			\n"
		"cmp r1, #109					\n"
		"bne reg1_error_loopf			\n"
		"vmov r0, r1, d11				\n"
		"cmp r0, #110					\n"
		"bne reg1_error_loopf			\n"
		"cmp r1, #111					\n"
		"bne reg1_error_loopf			\n"
		"vmov r0, r1, d12				\n"
		"cmp r0, #100					\n"
		"bne reg1_error_loopf			\n"
		"cmp r1, #101					\n"
		"bne reg1_error_loopf			\n"
		"vmov r0, r1, d13				\n"
		"cmp r0, #102					\n"
		"bne reg1_error_loopf			\n"
		"cmp r1, #103					\n"
		"bne reg1_error_loopf			\n"
		"vmov r0, r1, d14				\n"
		"cmp r0, #104					\n"
		"bne reg1_error_loopf			\n"
		"cmp r1, #105					\n"
		"bne reg1_error_loopf			\n"
		"vmov r0, r1, d15				\n"
		"cmp r0, #106					\n"
		"bne reg1_error_loopf			\n"
		"cmp r1, #107					\n"
		"bne reg1_error_loopf			\n"

		/* Restore the registers that were clobbered by the test. */
		"pop {r0-r1}					\n"

		/* VFP register test passed.  Jump to the core register test. */
		"b reg1_loopf_pass				\n"

	"reg1_error_loopf:					\n"
		/* If this line is hit then a VFP register value was found to be
		incorrect. */
		"b reg1_error_loopf				\n"

	"reg1_loopf_pass:					\n"

		"cmp	r0, #100				\n"
		"bne	reg1_error_loop			\n"
		"cmp	r1, #101				\n"
		"bne	reg1_error_loop			\n"
		"cmp	r2, #102				\n"
		"bne	reg1_error_loop			\n"
		"cmp r3, #103					\n"
		"bne	reg1_error_loop			\n"
		"cmp	r4, #104				\n"
		"bne	reg1_error_loop			\n"
		"cmp	r5, #105				\n"
		"bne	reg1_error_loop			\n"
		"cmp	r6, #106				\n"
		"bne	reg1_error_loop			\n"
		"cmp	r7, #107				\n"
		"bne	reg1_error_loop			\n"
		"cmp	r8, #108				\n"
		"bne	reg1_error_loop			\n"
		"cmp	r9, #109				\n"
		"bne	reg1_error_loop			\n"
		"cmp	r10, #110				\n"
		"bne	reg1_error_loop			\n"
		"cmp	r11, #111				\n"
		"bne	reg1_error_loop			\n"
		"cmp	r12, #112				\n"
		"bne	reg1_error_loop			\n"

		/* Everything passed, increment the loop counter. */
		"push { r0-r1 }					\n"
		"ldr	r0, =ulRegTest1LoopCounter	\n"
		"ldr r1, [r0]					\n"
		"adds r1, r1, #1				\n"
		"str r1, [r0]					\n"
		"pop { r0-r1 }					\n"

		/* Start again. */
		"b reg1_loop					\n"

	"reg1_error_loop:					\n"
		/* If this line is hit then there was an error in a core register value.
		The loop ensures the loop counter stops incrementing. */
		"b reg1_error_loop				\n"
		"nop							\n"
	); /* __asm volatile. */
}
/*-----------------------------------------------------------*/

void vRegTest2Implementation( void )
{
	__asm volatile
	(
		".extern ulRegTest2LoopCounter 	\n"

		/* Set all the core registers to known values. */
		"mov r0, #-1					\n"
		"mov r1, #1						\n"
		"mov r2, #2						\n"
		"mov r3, #3						\n"
		"mov r4, #4						\n"
		"mov r5, #5						\n"
		"mov r6, #6						\n"
		"mov r7, #7						\n"
		"mov r8, #8						\n"
		"mov r9, #9						\n"
		"mov r10, #10					\n"
		"mov r11, #11					\n"
		"mov r12, #12					\n"

		/* Set all the VFP to known values. */
		"vmov d0, r0, r1				\n"
		"vmov d1, r2, r3				\n"
		"vmov d2, r4, r5				\n"
		"vmov d3, r6, r7				\n"
		"vmov d4, r8, r9				\n"
		"vmov d5, r10, r11				\n"
		"vmov d6, r0, r1				\n"
		"vmov d7, r2, r3				\n"
		"vmov d8, r4, r5				\n"
		"vmov d9, r6, r7				\n"
		"vmov d10, r8, r9				\n"
		"vmov d11, r10, r11				\n"
		"vmov d12, r0, r1				\n"
		"vmov d13, r2, r3				\n"
		"vmov d14, r4, r5				\n"
		"vmov d15, r6, r7				\n"

	"reg2_loop:							\n"

		/* Check all the VFP registers still contain the values set above.
		First save registers that are clobbered by the test. */
		"push { r0-r1 }					\n"

		"vmov r0, r1, d0				\n"
		"cmp r0, #-1					\n"
		"bne reg2_error_loopf			\n"
		"cmp r1, #1						\n"
		"bne reg2_error_loopf			\n"
		"vmov r0, r1, d1				\n"
		"cmp r0, #2						\n"
		"bne reg2_error_loopf			\n"
		"cmp r1, #3						\n"
		"bne reg2_error_loopf			\n"
		"vmov r0, r1, d2				\n"
		"cmp r0, #4						\n"
		"bne reg2_error_loopf			\n"
		"cmp r1, #5						\n"
		"bne reg2_error_loopf			\n"
		"vmov r0, r1, d3				\n"
		"cmp r0, #6						\n"
		"bne reg2_error_loopf			\n"
		"cmp r1, #7						\n"
		"bne reg2_error_loopf			\n"
		"vmov r0, r1, d4				\n"
		"cmp r0, #8						\n"
		"bne reg2_error_loopf			\n"
		"cmp r1, #9						\n"
		"bne reg2_error_loopf			\n"
		"vmov r0, r1, d5				\n"
		"cmp r0, #10					\n"
		"bne reg2_error_loopf			\n"
		"cmp r1, #11					\n"
		"bne reg2_error_loopf			\n"
		"vmov r0, r1, d6				\n"
		"cmp r0, #-1					\n"
		"bne reg2_error_loopf			\n"
		"cmp r1, #1						\n"
		"bne reg2_error_loopf			\n"
		"vmov r0, r1, d7				\n"
		"cmp r0, #2						\n"
		"bne reg2_error_loopf			\n"
		"cmp r1, #3						\n"
		"bne reg2_error_loopf			\n"
		"vmov r0, r1, d8				\n"
		"cmp r0, #4						\n"
		"bne reg2_error_loopf			\n"
		"cmp r1, #5						\n"
		"bne reg2_error_loopf			\n"
		"vmov r0, r1, d9				\n"
		"cmp r0, #6						\n"
		"bne reg2_error_loopf			\n"
		"cmp r1, #7						\n"
		"bne reg2_error_loopf			\n"
		"vmov r0, r1, d10				\n"
		"cmp r0, #8						\n"
		"bne reg2_error_loopf			\n"
		"cmp r1, #9						\n"
		"bne reg2_error_loopf			\n"
		"vmov r0, r1, d11				\n"
		"cmp r0, #10					\n"
		"bne reg2_error_loopf			\n"
		"cmp r1, #11					\n"
		"bne reg2_error_loopf			\n"
		"vmov r0, r1, d12				\n"
		"cmp r0, #-1					\n"
		"bne reg2_error_loopf			\n"
		"cmp r1, #1						\n"
		"bne reg2_error_loopf			\n"
		"vmov r0, r1, d13				\n"
		"cmp r0, #2						\n"
		"bne reg2_error_loopf			\n"
		"cmp r1, #3						\n"
		"bne reg2_error_loopf			\n"
		"vmov r0, r1, d14				\n"
		"cmp r0, #4						\n"
		"bne reg2_error_loopf			\n"
		"cmp r1, #5						\n"
		"bne reg2_error_loopf			\n"
		"vmov r0, r1, d15				\n"
		"cmp r0, #6						\n"
		"bne reg2_error_loopf			\n"
		"cmp r1, #7						\n"
		"bne reg2_error_loopf			\n"

		/* Restore the registers that were clobbered by the test. */
		"pop {r0-r1}					\n"

		/* VFP register test passed.  Jump to the core register test. */
		"b reg2_loopf_pass				\n"

	"reg2_error_loopf:					\n"
		/* If this line is hit then a VFP register value was found to be
		incorrect. */
		"b reg2_error_loopf				\n"

	"reg2_loopf_pass:					\n"

		"cmp	r0, #-1					\n"
		"bne	reg2_error_loop			\n"
		"cmp	r1, #1					\n"
		"bne	reg2_error_loop			\n"
		"cmp	r2, #2					\n"
		"bne	reg2_error_loop			\n"
		"cmp r3, #3						\n"
		"bne	reg2_error_loop			\n"
		"cmp	r4, #4					\n"
		"bne	reg2_error_loop			\n"
		"cmp	r5, #5					\n"
		"bne	reg2_error_loop			\n"
		"cmp	r6, #6					\n"
		"bne	reg2_error_loop			\n"
		"cmp	r7, #7					\n"
		"bne	reg2_error_loop			\n"
		"cmp	r8, #8					\n"
		"bne	reg2_error_loop			\n"
		"cmp	r9, #9					\n"
		"bne	reg2_error_loop			\n"
		"cmp	r10, #10				\n"
		"bne	reg2_error_loop			\n"
		"cmp	r11, #11				\n"
		"bne	reg2_error_loop			\n"
		"cmp	r12, #12				\n"
		"bne	reg2_error_loop			\n"

		/* Increment the loop counter to indicate this test is still functioning
		correctly. */
		"push { r0-r1 }					\n"
		"ldr	r0, =ulRegTest2LoopCounter	\n"
		"ldr r1, [r0]					\n"
		"adds r1, r1, #1				\n"
		"str r1, [r0]					\n"

		/* Yield to increase test coverage. */
		"movs r0, #0x01					\n"
		"ldr r1, =0xe000ed04 			\n" /*NVIC_INT_CTRL */
		"lsl r0, r0, #28 				\n" /* Shift to PendSV bit */
		"str r0, [r1]					\n"
		"dsb							\n"

		"pop { r0-r1 }					\n"

		/* Start again. */
		"b reg2_loop					\n"

	"reg2_error_loop:					\n"
		/* If this line is hit then there was an error in a core register value.
		This loop ensures the loop counter variable stops incrementing. */
		"b reg2_error_loop				\n"
		
	); /* __asm volatile */
}
/*-----------------------------------------------------------*/

