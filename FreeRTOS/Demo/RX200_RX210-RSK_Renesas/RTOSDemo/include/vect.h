/***********************************************************************/
/*                                                                     */
/*  FILE        :vect.h                                                */
/*  DATE        :Wed, Aug 11, 2010                                     */
/*  DESCRIPTION :Definition of Vector                                  */
/*  CPU TYPE    :Other                                                 */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.50).    */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/



/*********************************************************************
*
* Device     : RX/RX200
*
* File Name  : vect.h
*
* Abstract   : Definition of Vector.
*
* History    : 1.00  (2009-08-07)
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright(c) 2009 Renesas Technology Corp.
*               And Renesas Solutions Corp.,All Rights Reserved.
*
*********************************************************************/

/* Exception(Supervisor Instruction) */
#pragma interrupt (Excep_SuperVisorInst)
void Excep_SuperVisorInst( void );

/* Exception(Undefined Instruction) */
#pragma interrupt (Excep_UndefinedInst)
void Excep_UndefinedInst( void );

/* Exception(Floating Point) */
#pragma interrupt (Excep_FloatingPoint)
void Excep_FloatingPoint( void );

/* NMI */
#pragma interrupt (NonMaskableInterrupt)
void NonMaskableInterrupt( void );

/* Dummy */
#pragma interrupt (Dummy)
void Dummy( void );

/* BRK */
#pragma interrupt (Excep_BRK(vect=0))
void Excep_BRK( void );

/*;<<VECTOR DATA START (POWER ON RESET)>> */
/*;Power On Reset PC */
extern void PowerON_Reset_PC( void );
/*;<<VECTOR DATA END (POWER ON RESET)>> */
