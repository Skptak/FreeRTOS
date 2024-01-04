#!/usr/bin/env python3
# python >= 3.4

import os
from common.header_checker import HeaderChecker

#--------------------------------------------------------------------------------------------------
#                                            CONFIG
#--------------------------------------------------------------------------------------------------
FREERTOS_IGNORED_EXTENSIONS = [
    '.1',
    '.ASM',
    '.C',
    '.DSW',
    '.G_C',
    '.H',
    '.Hbp',
    '.IDE',
    '.LIB',
    '.Opt',
    '.PC',
    '.PRM',
    '.TXT',
    '.URL',
    '.UVL',
    '.Uv2',
    '.a',
    '.ac',
    '.am',
    '.atsln',
    '.atstart',
    '.atsuo',
    '.bash',
    '.bat',
    '.bbl',
    '.bit',
    '.board',
    '.bsb',
    '.bsdl',
    '.bts',
    '.ccxml',
    '.cdkproj',
    '.cdkws',
    '.cfg',
    '.cgp',
    '.checksum',
    '.cmake',
    '.cmd',
    '.config',
    '.cpp',
    '.cproj',
    '.cproject',
    '.crun',
    '.css',
    '.csv',
    '.custom_argvars',
    '.cxx',
    '.cydwr',
    '.cyprj',
    '.cysch',
    '.dat',
    '.datas',
    '.db',
    '.dbgdt',
    '.dep',
    '.dni',
    '.dnx',
    '.doc',
    '.dox',
    '.doxygen',
    '.ds',
    '.dsk',
    '.dtd',
    '.dts',
    '.elf',
    '.emProject',
    '.env_conf',
    '.ewd',
    '.ewp',
    '.ewt',
    '.eww',
    '.exe',
    '.filters',
    '.flash',
    '.fmt',
    '.ftl',
    '.gdb',
    '.gif',
    '.gise',
    '.gld',
    '.gpdsc',
    '.gui',
    '.h_from_toolchain',
    '.hdf',
    '.hdp',
    '.hex',
    '.hist',
    '.history',
    '.hsf',
    '.htm',
    '.html',
    '.hwc',
    '.hwl',
    '.hwp',
    '.hws',
    '.hzp',
    '.hzs',
    '.i',
    '.icf',
    '.ide',
    '.idx',
    '.in',
    '.inc',
    '.include',
    '.index',
    '.inf',
    '.ini',
    '.init',
    '.ipcf',
    '.ise',
    '.jlink',
    '.js',
    '.json',
    '.la',
    '.launch',
    '.lcf',
    '.ld',
    '.lds',
    '.lib',
    '.lk1',
    '.lkr',
    '.lm',
    '.lo',
    '.lock',
    '.lsl',
    '.lst',
    '.m4',
    '.mac',
    '.make',
    '.map',
    '.mbt',
    '.mcp',
    '.mcpar',
    '.mcs',
    '.mcw',
    '.md',
    '.mdm',
    '.mem',
    '.mhs',
    '.mk',
    '.mk1',
    '.mmi',
    '.mrt',
    '.mss',
    '.mtpj',
    '.nav',
    '.ntrc_log',
    '.opa',
    '.opb',
    '.opc',
    '.opl',
    '.opt',
    '.opv',
    '.out',
    '.pack',
    '.par',
    '.patch',
    '.pbd',
    '.pdsc',
    '.pe',
    '.pem',
    '.pgs',
    '.pl',
    '.plg',
    '.png',
    '.props',
    '.prc',
    '.pref',
    '.prefs',
    '.prj',
    '.project',
    '.properties',
    '.ps1',
    '.ptf',
    '.py',
    '.r79',
    '.rapp',
    '.rc',
    '.reggroups',
    '.reglist',
    '.resc',
    '.resources',
    '.rom',
    '.rprj',
    '.s',
    '.s79',
    '.s82',
    '.s90',
    '.sc',
    '.scf',
    '.scfg',
    '.script',
    '.sct',
    '.scvd',
    '.session',
    '.sfr',
    '.sh',
    '.shtml',
    '.sig',
    '.sln',
    '.spec',
    '.sprj',
    '.stf',
    '.stg',
    '.suo',
    '.sup',
    '.svg',
    '.tags',
    '.tcl',
    '.tdt',
    '.templ',
    '.template',
    '.tgt',
    '.tps',
    '.tra',
    '.tree',
    '.tws',
    '.txt',
    '.ucf',
    '.url',
    '.user',
    '.ut',
    '.uvmpw',
    '.uvopt',
    '.uvoptx',
    '.uvproj',
    '.uvprojx',
    '.vcproj',
    '.vcxproj',
    '.version',
    '.webserver',
    '.wpj',
    '.wsdt',
    '.wsp',
    '.wspos',
    '.wsx',
    '.x',
    '.xbcd',
    '.xcl',
    '.xise',
    '.xml',
    '.xmp',
    '.xmsgs',
    '.xsl',
    '.yml',
    '.zip'
]

FREERTOS_IGNORED_PATTERNS = [
    r'.*\.git.*',
    r'.*mbedtls_config*',
    r'.*CMSIS.*',
    r'.*/Nordic_Code/*',
    r'.*/Nuvoton_Code/*',
    r'.*/ST_Code/*',
    r'.*/NXP_Code/*',
    r'.*/makefile',
    r'.*/Makefile',
    r'.*/printf-stdarg\.c.*',
    r'.*/startup.*',
    r'.*/Startup.*',
    r'.*/trcConfig\.h.*',
    r'.*/trcConfig\.c.*',
    r'.*/trcSnapshotConfig\.h.*',
    r'.*/trcKernelPortConfig\.h.*',
    r'.*/trcKernelPortSnapshotConfig\.h.*',
    r'.*/MicroZed_hw_platform.*',
    r'.*/ThirdParty/.*',
    r'.*/WinPCap/.*',
    r'.*/DRIVERS/.*',
    r'.*/FreeRTOS-Plus-Trace/.*',
    r'.*/Reliance-Edge/.*',
    r'.*/HCS12_CodeWarrior_banked/.*',
    r'.*/ARM7_STR75x_GCC/.*',
    r'.*/ARM7_STR75x_IAR/.*',
    r'.*/lwip-1.4.0/.*',
    r'.*/lwip-1.1.0/.*',
    r'.*/MSP430X_MSP430F5438_CCS/.*',
    r'.*/Atmel/.*',
    r'.*/drivers/.*',
    r'.*/lwIP/.*',
    r'.*/ARM7_AT91FR40008_GCC/.*',
    r'.*/ARM7_AT91SAM7S64_IAR/.*',
    r'.*/ARM7_LPC2106_GCC/.*',
    r'.*/CORTEX_A9_Cyclone_V_SoC_DK/.*',
    r'.*/CORTEX_A9_Zynq_ZC702/.*',
    r'.*/FreeRTOS-Plus/Demo/FreeRTOS_Plus_Reliance_Edge_and_CLI_Windows_Simulator/ConfigurationFiles//.*',
    r'.*/ARM7_AT91FR40008_GCC/.*',
    r'.*/ARM7_STR71x_IAR/.*',
    r'FreeRTOS/Demo/HCS12_GCC_banked/.*',
    r'FreeRTOS/Demo/CORTEX_LM3S102_GCC/hw_include/.*',
    r'FreeRTOS/Demo/CORTEX_LM3S102_GCC/hw_include/.*',
    r'FreeRTOS/Demo/CORTEX_STM32L152_Discovery_IAR/include/.*',
    r'FreeRTOS/Demo/CORTEX_M0_Infineon_XMC1000_IAR_Keil_GCC/.*',
    r'FreeRTOS/Demo/CORTEX_M4F_Infineon_XMC4000_Keil/.*',
    r'FreeRTOS/Demo/CORTEX_R4_RM46_HERCULES_MCU_GCC/BoardFiles/.*',
    r'FreeRTOS/Demo/CORTEX_R5_RM57_HERCULES_MCU_GCC/BoardFiles/.*',
    r'FreeRTOS/Demo/AVR_ATMega4809_Atmel_Studio/RTOSDemo/.*',
    r'FreeRTOS/Demo/AVR32_UC3/.*',
    r'FreeRTOS/Demo/AVR_ATMega4809_IAR/.*',
    r'FreeRTOS/Demo/AVR_ATMega4809_MPLAB.X/.*',
    r'FreeRTOS/Demo/AVR_Dx_IAR/.*',
    r'FreeRTOS/Demo/AVR_Dx_MPLAB.X/.*',
    r'FreeRTOS/Demo/ARM7_STR75x_GCC/STLibrary/inc/.*',
    r'FreeRTOS/Demo/ARM7_STR75x_IAR/STLibrary/inc/.*',
    r'FreeRTOS/Demo/CORTEX_R4F_RZ_T_GCC_IAR/System/GCC/inc/.*',
    r'FreeRTOS/Demo/CORTEX_A5_SAMA5D2x_Xplained_IAR/AtmelFiles/drivers/misc/.*',
    r'FreeRTOS/Demo/CORTEX_ATSAM3X_Atmel_Studio/src/.*',
    r'FreeRTOS/Demo/MSP430X_MSP430FR5969_LaunchPad_IAR_CCS/.*',
    r'FreeRTOS-Plus/Demo/FreeRTOS_Plus_CLI_with_Trace_Windows_Simulator/Trace_Recorder_Configuration/.*',
    r'FreeRTOS-Plus/Demo/FreeRTOS_Plus_TCP_Echo_Posix/Trace_Recorder_Configuration/.*',
    r'FreeRTOS-Plus/Demo/FreeRTOS_Plus_TCP_IPv6_Demo/common/WinPCap/.*',
    r'FreeRTOS-Plus/Demo/FreeRTOS_Plus_TCP_IPv6_Demo/common/WinPCap/pcap/.*',
    r'FreeRTOS-Plus/Demo/FreeRTOS_Plus_TCP_IPv6_Demo/IPv6_Multi_WinSim_demo/FreeRTOS_Plus_TCP_IPv6_Multi.props',
    r'FreeRTOS/Demo/lwIP_AVR32_UC3/.*',
    r'FreeRTOS/Demo/Tensilica_Simulator_Xplorer_XCC/.*',
    r'FreeRTOS/Demo/CORTEX_LM3S102_GCC/makedefs',
    r'FreeRTOS/Demo/AVR32_UC3/FreeRTOSConfig.h',
    r'FreeRTOS/Demo/RX700_RX72N_EnvisionKit_GCC_e2studio/src/smc_gen/.*',
    r'FreeRTOS/Demo/RX700_RX72N_EnvisionKit_IAR_e2studio_EWRX/src/smc_gen/.*',
    r'FreeRTOS/Demo/RX700_RX72N_EnvisionKit_Renesas_e2studio_CS\+/src/smc_gen/.*'
]

FREERTOS_IGNORED_FILES = [
    'cspell.config.yaml',
    '.cproject',
    '.project',
    'requirements.txt',
    'run-cbmc-proofs.py',
    '.editorconfig',
    'lcovrc',
    'htif.c', 'htif.h',
    'ethernetif.c',
    'platform.c',
    'platform.h',
    'platform_config.h',
    'FreeRTOS_asm_vectors.S',
    'interrupt_vector.s',
    'reg_test.S',
    'gdbinit',
    'libslirp-version.h',
    'LPC21xx.h',
    'lpc221x.h',
    'winbase.h',
    'windows.h',
    'direct.h',
    'stm32f10x_conf.h',
    'lwipopts.h',
    'lwipopts.h',
    'xil_assert.h',
    'alt_i2c.h',
    'alt_clkmgr.h',
    'hal_lcd.c',
    'adc.h',
    'redconf.c',
    'redconf.h',
    'redtypes.h',
]

FREERTOS_HEADER = [
    '/*\n',
    ' * FreeRTOS V202212.00\n',
    ' * Copyright (C) 2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.\n',
    ' *\n',
    ' * Permission is hereby granted, free of charge, to any person obtaining a copy of\n',
    ' * this software and associated documentation files (the "Software"), to deal in\n',
    ' * the Software without restriction, including without limitation the rights to\n',
    ' * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of\n',
    ' * the Software, and to permit persons to whom the Software is furnished to do so,\n',
    ' * subject to the following conditions:\n',
    ' *\n',
    ' * The above copyright notice and this permission notice shall be included in all\n',
    ' * copies or substantial portions of the Software.\n',
    ' *\n',
    ' * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n',
    ' * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS\n',
    ' * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR\n',
    ' * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER\n',
    ' * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN\n',
    ' * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n',
    ' *\n',
    ' * https://www.FreeRTOS.org\n',
    ' * https://github.com/FreeRTOS\n',
    ' *\n',
    ' */\n',
]

FREERTOS_COPYRIGHT_REGEX = r"^( *(\/\*|\*|#|\/\/))? Copyright \(C\) 20\d\d Amazon.com, Inc. or its affiliates. All Rights Reserved\.( \*\/)?$"

def main():
    parser = HeaderChecker.configArgParser()
    args   = parser.parse_args()

    # Configure the checks then run
    checker = HeaderChecker(FREERTOS_HEADER, copyright_regex=FREERTOS_COPYRIGHT_REGEX)
    checker.ignoreExtension(*FREERTOS_IGNORED_EXTENSIONS)
    checker.ignorePattern(*FREERTOS_IGNORED_PATTERNS)
    checker.ignoreFile(*FREERTOS_IGNORED_FILES)
    checker.ignoreFile(os.path.split(__file__)[-1])

    rc = checker.processArgs(args)
    if rc:
        checker.showHelp(__file__)

    return rc

if __name__ == '__main__':
    exit(main())
