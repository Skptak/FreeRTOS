// See LICENSE for license details.

#ifndef _SIFIVE_AON_H
#define _SIFIVE_AON_H

/* Register offsets */

#define AON_WDOGCFG              0x000
#define AON_WDOGCOUNT            0x008
#define AON_WDOGS                0x010
#define AON_WDOGFEED             0x018
#define AON_WDOGKEY              0x01C
#define AON_WDOGCMP              0x020

#define AON_RTCCFG               0x040
#define AON_RTCLO                0x048
#define AON_RTCHI                0x04C
#define AON_RTCS                 0x050
#define AON_RTCCMP               0x060

#define AON_BACKUP0              0x080
#define AON_BACKUP1              0x084
#define AON_BACKUP2              0x088
#define AON_BACKUP3              0x08C
#define AON_BACKUP4              0x090
#define AON_BACKUP5              0x094
#define AON_BACKUP6              0x098
#define AON_BACKUP7              0x09C
#define AON_BACKUP8              0x0A0
#define AON_BACKUP9              0x0A4
#define AON_BACKUP10             0x0A8
#define AON_BACKUP11             0x0AC
#define AON_BACKUP12             0x0B0
#define AON_BACKUP13             0x0B4
#define AON_BACKUP14             0x0B8
#define AON_BACKUP15             0x0BC

#define AON_PMUWAKEUPI0          0x100
#define AON_PMUWAKEUPI1          0x104
#define AON_PMUWAKEUPI2          0x108
#define AON_PMUWAKEUPI3          0x10C
#define AON_PMUWAKEUPI4          0x110
#define AON_PMUWAKEUPI5          0x114
#define AON_PMUWAKEUPI6          0x118
#define AON_PMUWAKEUPI7          0x11C
#define AON_PMUSLEEPI0           0x120
#define AON_PMUSLEEPI1           0x124
#define AON_PMUSLEEPI2           0x128
#define AON_PMUSLEEPI3           0x12C
#define AON_PMUSLEEPI4           0x130
#define AON_PMUSLEEPI5           0x134
#define AON_PMUSLEEPI6           0x138
#define AON_PMUSLEEPI7           0x13C
#define AON_PMUIE                0x140
#define AON_PMUCAUSE             0x144
#define AON_PMUSLEEP             0x148
#define AON_PMUKEY               0x14C

#define AON_LFROSC               0x070
/* Constants */

#define AON_WDOGKEY_VALUE        0x51F15E
#define AON_WDOGFEED_VALUE       0xD09F00D

#define AON_WDOGCFG_SCALE        0x0000000F
#define AON_WDOGCFG_RSTEN        0x00000100
#define AON_WDOGCFG_ZEROCMP      0x00000200
#define AON_WDOGCFG_ENALWAYS     0x00001000
#define AON_WDOGCFG_ENCOREAWAKE  0x00002000
#define AON_WDOGCFG_CMPIP        0x10000000

#define AON_RTCCFG_SCALE         0x0000000F
#define AON_RTCCFG_ENALWAYS      0x00001000
#define AON_RTCCFG_CMPIP         0x10000000

#define AON_WAKEUPCAUSE_RESET    0x00
#define AON_WAKEUPCAUSE_RTC      0x01
#define AON_WAKEUPCAUSE_DWAKEUP  0x02
#define AON_WAKEUPCAUSE_AWAKEUP  0x03

#define AON_RESETCAUSE_POWERON   0x0000
#define AON_RESETCAUSE_EXTERNAL  0x0100
#define AON_RESETCAUSE_WATCHDOG  0x0200

#define AON_PMUCAUSE_WAKEUPCAUSE 0x00FF
#define AON_PMUCAUSE_RESETCAUSE  0xFF00

#endif /* _SIFIVE_AON_H */
