/*******************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only
 * intended for use with Renesas products. No other uses are authorized. This
 * software is owned by Renesas Electronics Corporation and is protected under
 * all applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
 * LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
 * TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
 * ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
 * FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
 * ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
 * BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software
 * and to discontinue the availability of this software. By using this software,
 * you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.
 *******************************************************************************/
/*******************************************************************************
 * System Name  : RZ/T1 Init program
 * File Name    : r_icu_init.h
 * Version      : 0.1
 * Device       : R7S9100xx
 * Abstract     : API for ICU init
 * Tool-Chain   : IAR Embedded Workbench Ver.7.20
 * OS           : not use
 * H/W Platform : Renesas Starter Kit for RZ/T1(Preliminary)
 * Description  : Initialize interrupt controller unit.
 * Limitation   : none
 *******************************************************************************/
/*******************************************************************************
 * History      : DD.MM.YYYY Version  Description
 *              :                     First Release
 *******************************************************************************/

#ifndef _R_ICU_INIT_HEADER_
    #define _R_ICU_INIT_HEADER_

/*******************************************************************************
Macro definitions
*******************************************************************************/

    #define ICU_EXT_PIN_0        ( 0 )
    #define ICU_EXT_PIN_1        ( 1 )
    #define ICU_EXT_PIN_2        ( 2 )
    #define ICU_EXT_PIN_3        ( 3 )
    #define ICU_EXT_PIN_4        ( 4 )
    #define ICU_EXT_PIN_5        ( 5 )
    #define ICU_EXT_PIN_6        ( 6 )
    #define ICU_EXT_PIN_7        ( 7 )
    #define ICU_EXT_PIN_8        ( 8 )
    #define ICU_EXT_PIN_9        ( 9 )
    #define ICU_EXT_PIN_10       ( 10 )
    #define ICU_EXT_PIN_11       ( 11 )
    #define ICU_EXT_PIN_12       ( 12 )
    #define ICU_EXT_PIN_13       ( 13 )
    #define ICU_EXT_PIN_14       ( 14 )
    #define ICU_EXT_PIN_15       ( 15 )

    #define ICU_DETECT_LOW       ( 0x00 )
    #define ICU_DETECT_FALL      ( 0x04 )
    #define ICU_DETECT_RISE      ( 0x08 )
    #define ICU_DETECT_RISE_FALL ( 0x0C )

    #define ICU_DNF_DIVISION_1   ( 0 )
    #define ICU_DNF_DIVISION_8   ( 1 )
    #define ICU_DNF_DIVISION_32  ( 2 )
    #define ICU_DNF_DIVISION_64  ( 3 )
    #define ICU_DNF_NO_USE       ( 4 )

    #define ICU_VEC_NUM_1        ( 1 )
    #define ICU_VEC_NUM_2        ( 2 )
    #define ICU_VEC_NUM_3        ( 3 )
    #define ICU_VEC_NUM_4        ( 4 )
    #define ICU_VEC_NUM_5        ( 5 )
    #define ICU_VEC_NUM_6        ( 6 )
    #define ICU_VEC_NUM_7        ( 7 )
    #define ICU_VEC_NUM_8        ( 8 )
    #define ICU_VEC_NUM_9        ( 9 )
    #define ICU_VEC_NUM_10       ( 10 )
    #define ICU_VEC_NUM_11       ( 11 )
    #define ICU_VEC_NUM_12       ( 12 )
    #define ICU_VEC_NUM_13       ( 13 )
    #define ICU_VEC_NUM_14       ( 14 )
    #define ICU_VEC_NUM_15       ( 15 )
    #define ICU_VEC_NUM_16       ( 16 )
    #define ICU_VEC_NUM_17       ( 17 )
    #define ICU_VEC_NUM_18       ( 18 )
    #define ICU_VEC_NUM_19       ( 19 )
    #define ICU_VEC_NUM_20       ( 20 )
    #define ICU_VEC_NUM_21       ( 21 )
    #define ICU_VEC_NUM_22       ( 22 )
    #define ICU_VEC_NUM_23       ( 23 )
    #define ICU_VEC_NUM_24       ( 24 )
    #define ICU_VEC_NUM_25       ( 25 )
    #define ICU_VEC_NUM_26       ( 26 )
    #define ICU_VEC_NUM_27       ( 27 )
    #define ICU_VEC_NUM_28       ( 28 )
    #define ICU_VEC_NUM_29       ( 29 )
    #define ICU_VEC_NUM_30       ( 30 )
    #define ICU_VEC_NUM_31       ( 31 )
    #define ICU_VEC_NUM_32       ( 32 )
    #define ICU_VEC_NUM_33       ( 33 )
    #define ICU_VEC_NUM_34       ( 34 )
    #define ICU_VEC_NUM_35       ( 35 )
    #define ICU_VEC_NUM_36       ( 36 )
    #define ICU_VEC_NUM_37       ( 37 )
    #define ICU_VEC_NUM_38       ( 38 )
    #define ICU_VEC_NUM_39       ( 39 )
    #define ICU_VEC_NUM_40       ( 40 )
    #define ICU_VEC_NUM_41       ( 41 )
    #define ICU_VEC_NUM_42       ( 42 )
    #define ICU_VEC_NUM_43       ( 43 )
    #define ICU_VEC_NUM_44       ( 44 )
    #define ICU_VEC_NUM_45       ( 45 )
    #define ICU_VEC_NUM_46       ( 46 )
    #define ICU_VEC_NUM_47       ( 47 )
    #define ICU_VEC_NUM_48       ( 48 )
    #define ICU_VEC_NUM_49       ( 49 )
    #define ICU_VEC_NUM_50       ( 50 )
    #define ICU_VEC_NUM_51       ( 51 )
    #define ICU_VEC_NUM_52       ( 52 )
    #define ICU_VEC_NUM_53       ( 53 )
    #define ICU_VEC_NUM_54       ( 54 )
    #define ICU_VEC_NUM_55       ( 55 )
    #define ICU_VEC_NUM_56       ( 56 )
    #define ICU_VEC_NUM_57       ( 57 )
    #define ICU_VEC_NUM_58       ( 58 )
    #define ICU_VEC_NUM_59       ( 59 )
    #define ICU_VEC_NUM_60       ( 60 )
    #define ICU_VEC_NUM_61       ( 61 )
    #define ICU_VEC_NUM_62       ( 62 )
    #define ICU_VEC_NUM_63       ( 63 )
    #define ICU_VEC_NUM_64       ( 64 )
    #define ICU_VEC_NUM_65       ( 65 )
    #define ICU_VEC_NUM_66       ( 66 )
    #define ICU_VEC_NUM_67       ( 67 )
    #define ICU_VEC_NUM_68       ( 68 )
    #define ICU_VEC_NUM_69       ( 69 )
    #define ICU_VEC_NUM_70       ( 70 )
    #define ICU_VEC_NUM_73       ( 73 )
    #define ICU_VEC_NUM_74       ( 74 )
    #define ICU_VEC_NUM_75       ( 75 )
    #define ICU_VEC_NUM_76       ( 76 )
    #define ICU_VEC_NUM_77       ( 77 )
    #define ICU_VEC_NUM_78       ( 78 )
    #define ICU_VEC_NUM_79       ( 79 )
    #define ICU_VEC_NUM_80       ( 80 )
    #define ICU_VEC_NUM_81       ( 81 )
    #define ICU_VEC_NUM_82       ( 82 )
    #define ICU_VEC_NUM_83       ( 83 )
    #define ICU_VEC_NUM_84       ( 84 )
    #define ICU_VEC_NUM_85       ( 85 )
    #define ICU_VEC_NUM_86       ( 86 )
    #define ICU_VEC_NUM_87       ( 87 )
    #define ICU_VEC_NUM_88       ( 88 )
    #define ICU_VEC_NUM_89       ( 89 )
    #define ICU_VEC_NUM_90       ( 90 )
    #define ICU_VEC_NUM_91       ( 91 )
    #define ICU_VEC_NUM_92       ( 92 )
    #define ICU_VEC_NUM_93       ( 93 )
    #define ICU_VEC_NUM_94       ( 94 )
    #define ICU_VEC_NUM_95       ( 95 )
    #define ICU_VEC_NUM_96       ( 96 )
    #define ICU_VEC_NUM_97       ( 97 )
    #define ICU_VEC_NUM_98       ( 98 )
    #define ICU_VEC_NUM_99       ( 99 )
    #define ICU_VEC_NUM_100      ( 100 )
    #define ICU_VEC_NUM_101      ( 101 )
    #define ICU_VEC_NUM_102      ( 102 )
    #define ICU_VEC_NUM_103      ( 103 )
    #define ICU_VEC_NUM_104      ( 104 )
    #define ICU_VEC_NUM_105      ( 105 )
    #define ICU_VEC_NUM_106      ( 106 )
    #define ICU_VEC_NUM_107      ( 107 )
    #define ICU_VEC_NUM_108      ( 108 )
    #define ICU_VEC_NUM_109      ( 109 )
    #define ICU_VEC_NUM_110      ( 110 )
    #define ICU_VEC_NUM_111      ( 111 )
    #define ICU_VEC_NUM_112      ( 112 )
    #define ICU_VEC_NUM_113      ( 113 )
    #define ICU_VEC_NUM_114      ( 114 )
    #define ICU_VEC_NUM_115      ( 115 )
    #define ICU_VEC_NUM_116      ( 116 )
    #define ICU_VEC_NUM_117      ( 117 )
    #define ICU_VEC_NUM_118      ( 118 )
    #define ICU_VEC_NUM_119      ( 119 )
    #define ICU_VEC_NUM_120      ( 120 )
    #define ICU_VEC_NUM_121      ( 121 )
    #define ICU_VEC_NUM_122      ( 122 )
    #define ICU_VEC_NUM_123      ( 123 )
    #define ICU_VEC_NUM_124      ( 124 )
    #define ICU_VEC_NUM_125      ( 125 )
    #define ICU_VEC_NUM_126      ( 126 )
    #define ICU_VEC_NUM_127      ( 127 )
    #define ICU_VEC_NUM_128      ( 128 )
    #define ICU_VEC_NUM_145      ( 145 )
    #define ICU_VEC_NUM_146      ( 146 )
    #define ICU_VEC_NUM_147      ( 147 )
    #define ICU_VEC_NUM_148      ( 148 )
    #define ICU_VEC_NUM_149      ( 149 )
    #define ICU_VEC_NUM_150      ( 150 )
    #define ICU_VEC_NUM_151      ( 151 )
    #define ICU_VEC_NUM_152      ( 152 )
    #define ICU_VEC_NUM_153      ( 153 )
    #define ICU_VEC_NUM_154      ( 154 )
    #define ICU_VEC_NUM_155      ( 155 )
    #define ICU_VEC_NUM_156      ( 156 )
    #define ICU_VEC_NUM_157      ( 157 )
    #define ICU_VEC_NUM_158      ( 158 )
    #define ICU_VEC_NUM_159      ( 159 )
    #define ICU_VEC_NUM_160      ( 160 )
    #define ICU_VEC_NUM_161      ( 161 )
    #define ICU_VEC_NUM_162      ( 162 )
    #define ICU_VEC_NUM_163      ( 163 )
    #define ICU_VEC_NUM_164      ( 164 )
    #define ICU_VEC_NUM_165      ( 165 )
    #define ICU_VEC_NUM_166      ( 166 )
    #define ICU_VEC_NUM_167      ( 167 )
    #define ICU_VEC_NUM_168      ( 168 )
    #define ICU_VEC_NUM_169      ( 169 )
    #define ICU_VEC_NUM_170      ( 170 )
    #define ICU_VEC_NUM_171      ( 171 )
    #define ICU_VEC_NUM_172      ( 172 )
    #define ICU_VEC_NUM_173      ( 173 )
    #define ICU_VEC_NUM_174      ( 174 )
    #define ICU_VEC_NUM_175      ( 175 )
    #define ICU_VEC_NUM_176      ( 176 )
    #define ICU_VEC_NUM_177      ( 177 )
    #define ICU_VEC_NUM_178      ( 178 )
    #define ICU_VEC_NUM_179      ( 179 )
    #define ICU_VEC_NUM_180      ( 180 )
    #define ICU_VEC_NUM_181      ( 181 )
    #define ICU_VEC_NUM_182      ( 182 )
    #define ICU_VEC_NUM_183      ( 183 )
    #define ICU_VEC_NUM_184      ( 184 )
    #define ICU_VEC_NUM_185      ( 185 )
    #define ICU_VEC_NUM_186      ( 186 )
    #define ICU_VEC_NUM_187      ( 187 )
    #define ICU_VEC_NUM_188      ( 188 )
    #define ICU_VEC_NUM_189      ( 189 )
    #define ICU_VEC_NUM_190      ( 190 )
    #define ICU_VEC_NUM_191      ( 191 )
    #define ICU_VEC_NUM_192      ( 192 )
    #define ICU_VEC_NUM_193      ( 193 )
    #define ICU_VEC_NUM_194      ( 194 )
    #define ICU_VEC_NUM_195      ( 195 )
    #define ICU_VEC_NUM_196      ( 196 )
    #define ICU_VEC_NUM_197      ( 197 )
    #define ICU_VEC_NUM_198      ( 198 )
    #define ICU_VEC_NUM_199      ( 199 )
    #define ICU_VEC_NUM_200      ( 200 )
    #define ICU_VEC_NUM_201      ( 201 )
    #define ICU_VEC_NUM_202      ( 202 )
    #define ICU_VEC_NUM_203      ( 203 )
    #define ICU_VEC_NUM_204      ( 204 )
    #define ICU_VEC_NUM_205      ( 205 )
    #define ICU_VEC_NUM_206      ( 206 )
    #define ICU_VEC_NUM_207      ( 207 )
    #define ICU_VEC_NUM_208      ( 208 )
    #define ICU_VEC_NUM_209      ( 209 )
    #define ICU_VEC_NUM_210      ( 210 )
    #define ICU_VEC_NUM_211      ( 211 )
    #define ICU_VEC_NUM_212      ( 212 )
    #define ICU_VEC_NUM_213      ( 213 )
    #define ICU_VEC_NUM_214      ( 214 )
    #define ICU_VEC_NUM_215      ( 215 )
    #define ICU_VEC_NUM_216      ( 216 )
    #define ICU_VEC_NUM_217      ( 217 )
    #define ICU_VEC_NUM_218      ( 218 )
    #define ICU_VEC_NUM_219      ( 219 )
    #define ICU_VEC_NUM_220      ( 220 )
    #define ICU_VEC_NUM_221      ( 221 )
    #define ICU_VEC_NUM_222      ( 222 )
    #define ICU_VEC_NUM_223      ( 223 )
    #define ICU_VEC_NUM_224      ( 224 )
    #define ICU_VEC_NUM_225      ( 225 )
    #define ICU_VEC_NUM_226      ( 226 )
    #define ICU_VEC_NUM_227      ( 227 )
    #define ICU_VEC_NUM_228      ( 228 )
    #define ICU_VEC_NUM_229      ( 229 )
    #define ICU_VEC_NUM_230      ( 230 )
    #define ICU_VEC_NUM_231      ( 231 )
    #define ICU_VEC_NUM_232      ( 232 )
    #define ICU_VEC_NUM_233      ( 233 )
    #define ICU_VEC_NUM_234      ( 234 )
    #define ICU_VEC_NUM_235      ( 235 )
    #define ICU_VEC_NUM_236      ( 236 )
    #define ICU_VEC_NUM_237      ( 237 )
    #define ICU_VEC_NUM_238      ( 238 )
    #define ICU_VEC_NUM_239      ( 239 )
    #define ICU_VEC_NUM_240      ( 240 )
    #define ICU_VEC_NUM_241      ( 241 )
    #define ICU_VEC_NUM_242      ( 242 )
    #define ICU_VEC_NUM_243      ( 243 )
    #define ICU_VEC_NUM_246      ( 246 )
    #define ICU_VEC_NUM_247      ( 247 )
    #define ICU_VEC_NUM_248      ( 248 )
    #define ICU_VEC_NUM_249      ( 249 )
    #define ICU_VEC_NUM_250      ( 250 )
    #define ICU_VEC_NUM_251      ( 251 )
    #define ICU_VEC_NUM_252      ( 252 )
    #define ICU_VEC_NUM_254      ( 254 )
    #define ICU_VEC_NUM_256      ( 256 )
    #define ICU_VEC_NUM_257      ( 257 )
    #define ICU_VEC_NUM_258      ( 258 )
    #define ICU_VEC_NUM_259      ( 259 )
    #define ICU_VEC_NUM_260      ( 260 )
    #define ICU_VEC_NUM_261      ( 261 )
    #define ICU_VEC_NUM_262      ( 262 )
    #define ICU_VEC_NUM_263      ( 263 )
    #define ICU_VEC_NUM_264      ( 264 )
    #define ICU_VEC_NUM_265      ( 265 )
    #define ICU_VEC_NUM_266      ( 266 )
    #define ICU_VEC_NUM_267      ( 267 )
    #define ICU_VEC_NUM_268      ( 268 )
    #define ICU_VEC_NUM_269      ( 269 )
    #define ICU_VEC_NUM_270      ( 270 )
    #define ICU_VEC_NUM_271      ( 271 )
    #define ICU_VEC_NUM_272      ( 272 )
    #define ICU_VEC_NUM_273      ( 273 )
    #define ICU_VEC_NUM_274      ( 274 )
    #define ICU_VEC_NUM_275      ( 275 )
    #define ICU_VEC_NUM_276      ( 276 )
    #define ICU_VEC_NUM_277      ( 277 )
    #define ICU_VEC_NUM_278      ( 278 )
    #define ICU_VEC_NUM_279      ( 279 )
    #define ICU_VEC_NUM_280      ( 280 )
    #define ICU_VEC_NUM_281      ( 281 )
    #define ICU_VEC_NUM_282      ( 282 )
    #define ICU_VEC_NUM_283      ( 283 )
    #define ICU_VEC_NUM_284      ( 284 )
    #define ICU_VEC_NUM_285      ( 285 )
    #define ICU_VEC_NUM_286      ( 286 )
    #define ICU_VEC_NUM_287      ( 287 )
    #define ICU_VEC_NUM_288      ( 288 )
    #define ICU_VEC_NUM_289      ( 289 )
    #define ICU_VEC_NUM_290      ( 290 )
    #define ICU_VEC_NUM_291      ( 291 )
    #define ICU_VEC_NUM_292      ( 292 )
    #define ICU_VEC_NUM_293      ( 293 )
    #define ICU_VEC_NUM_294      ( 294 )

    #define ICU_TYPE_LEVEL       ( 0 )
    #define ICU_TYPE_EDGE        ( 1 )

    #define ICU_PRIORITY_0       ( 0 )
    #define ICU_PRIORITY_1       ( 1 )
    #define ICU_PRIORITY_2       ( 2 )
    #define ICU_PRIORITY_3       ( 3 )
    #define ICU_PRIORITY_4       ( 4 )
    #define ICU_PRIORITY_5       ( 5 )
    #define ICU_PRIORITY_6       ( 6 )
    #define ICU_PRIORITY_7       ( 7 )
    #define ICU_PRIORITY_8       ( 8 )
    #define ICU_PRIORITY_9       ( 9 )
    #define ICU_PRIORITY_10      ( 10 )
    #define ICU_PRIORITY_11      ( 11 )
    #define ICU_PRIORITY_12      ( 12 )
    #define ICU_PRIORITY_13      ( 13 )
    #define ICU_PRIORITY_14      ( 14 )
    #define ICU_PRIORITY_15      ( 15 )

    #define ICU_IEC_MASK_SET     ( 1 )

    #define ICU_PIC_EDGE_CLEAR   ( 1 )

/*******************************************************************************
Typedef definitions
*******************************************************************************/

/*******************************************************************************
Exported global variables and functions (to be accessed by other files)
*******************************************************************************/
void R_ICU_Disable( uint32_t vec_num );
void R_ICU_Enable( uint32_t vec_num );
void R_ICU_ExtPinInit( uint16_t pin_num, uint8_t detect, uint32_t dnf_set );
void R_ICU_Regist( uint32_t vec_num,
                   uint32_t type,
                   uint32_t priority,
                   uint32_t isr_addr );
void R_ICU_Disable( uint32_t vec_num );
void R_ICU_Enable( uint32_t vec_num );

#endif

/* End of File */
