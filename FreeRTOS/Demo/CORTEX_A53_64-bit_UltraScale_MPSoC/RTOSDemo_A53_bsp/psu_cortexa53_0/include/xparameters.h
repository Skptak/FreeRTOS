#ifndef XPARAMETERS_H /* prevent circular inclusions */
#define XPARAMETERS_H                           /* by using protection macros */

/* Definition for CPU ID */
#define XPAR_CPU_ID                             0U

/* Definitions for peripheral PSU_CORTEXA53_0 */
#define XPAR_PSU_CORTEXA53_0_CPU_CLK_FREQ_HZ    1199880000
#define XPAR_PSU_CORTEXA53_0_TIMESTAMP_CLK_FREQ 99990000

/******************************************************************/

/* Canonical definitions for peripheral PSU_CORTEXA53_0 */
#define XPAR_CPU_CORTEXA53_0_CPU_CLK_FREQ_HZ    1199880000
#define XPAR_CPU_CORTEXA53_0_TIMESTAMP_CLK_FREQ 99990000

/******************************************************************/

/* Definition for PSS REF CLK FREQUENCY */
#define XPAR_PSU_PSS_REF_CLK_FREQ_HZ            33330000U

#include "xparameters_ps.h"

#define XPS_BOARD_ZCU102

/* Number of Fabric Resets */
#define XPAR_NUM_FABRIC_RESETS 1

#define STDIN_BASEADDRESS      0xFF000000
#define STDOUT_BASEADDRESS     0xFF000000

/******************************************************************/

/* Platform specific definitions */
#define PLATFORM_ZYNQMP

/* Definitions for sleep timer configuration */
#define XSLEEP_TIMER_IS_DEFAULT_TIMER

/******************************************************************/
/* Definitions for driver AVBUF */
#define XPAR_XAVBUF_NUM_INSTANCES                    1

/* Definitions for peripheral PSU_DP */
#define XPAR_PSU_DP_DEVICE_ID                        0
#define XPAR_PSU_DP_BASEADDR                         0xFD4A0000
#define XPAR_PSU_DP_HIGHADDR                         0xFD4AFFFF

/******************************************************************/

/* Canonical definitions for peripheral PSU_DP */
#define XPAR_XAVBUF_0_DEVICE_ID                      XPAR_PSU_DP_DEVICE_ID
#define XPAR_XAVBUF_0_BASEADDR                       0xFD4A0000
#define XPAR_XAVBUF_0_HIGHADDR                       0xFD4AFFFF

/******************************************************************/

/* Definitions for driver AXIPMON */
#define XPAR_XAXIPMON_NUM_INSTANCES                  4U

/* Definitions for peripheral PSU_APM_0 */
#define XPAR_PSU_APM_0_DEVICE_ID                     0U
#define XPAR_PSU_APM_0_BASEADDR                      0xFD0B0000U
#define XPAR_PSU_APM_0_HIGHADDR                      0xFD0BFFFFU
#define XPAR_PSU_APM_0_GLOBAL_COUNT_WIDTH            32U
#define XPAR_PSU_APM_0_METRICS_SAMPLE_COUNT_WIDTH    32U
#define XPAR_PSU_APM_0_ENABLE_EVENT_COUNT            1U
#define XPAR_PSU_APM_0_NUM_MONITOR_SLOTS             6U
#define XPAR_PSU_APM_0_NUM_OF_COUNTERS               10U
#define XPAR_PSU_APM_0_HAVE_SAMPLED_METRIC_CNT       1U
#define XPAR_PSU_APM_0_ENABLE_EVENT_LOG              0U
#define XPAR_PSU_APM_0_FIFO_AXIS_DEPTH               32U
#define XPAR_PSU_APM_0_FIFO_AXIS_TDATA_WIDTH         56U
#define XPAR_PSU_APM_0_FIFO_AXIS_TID_WIDTH           1U
#define XPAR_PSU_APM_0_METRIC_COUNT_SCALE            1U
#define XPAR_PSU_APM_0_ENABLE_ADVANCED               1U
#define XPAR_PSU_APM_0_ENABLE_PROFILE                0U
#define XPAR_PSU_APM_0_ENABLE_TRACE                  0U
#define XPAR_PSU_APM_0_S_AXI4_BASEADDR               0x00000000U
#define XPAR_PSU_APM_0_S_AXI4_HIGHADDR               0x00000000U
#define XPAR_PSU_APM_0_ENABLE_32BIT_FILTER_ID        1U

/* Definitions for peripheral PSU_APM_1 */
#define XPAR_PSU_APM_1_DEVICE_ID                     1U
#define XPAR_PSU_APM_1_BASEADDR                      0xFFA00000U
#define XPAR_PSU_APM_1_HIGHADDR                      0xFFA0FFFFU
#define XPAR_PSU_APM_1_GLOBAL_COUNT_WIDTH            32U
#define XPAR_PSU_APM_1_METRICS_SAMPLE_COUNT_WIDTH    32U
#define XPAR_PSU_APM_1_ENABLE_EVENT_COUNT            1U
#define XPAR_PSU_APM_1_NUM_MONITOR_SLOTS             1U
#define XPAR_PSU_APM_1_NUM_OF_COUNTERS               3U
#define XPAR_PSU_APM_1_HAVE_SAMPLED_METRIC_CNT       1U
#define XPAR_PSU_APM_1_ENABLE_EVENT_LOG              0U
#define XPAR_PSU_APM_1_FIFO_AXIS_DEPTH               32U
#define XPAR_PSU_APM_1_FIFO_AXIS_TDATA_WIDTH         56U
#define XPAR_PSU_APM_1_FIFO_AXIS_TID_WIDTH           1U
#define XPAR_PSU_APM_1_METRIC_COUNT_SCALE            1U
#define XPAR_PSU_APM_1_ENABLE_ADVANCED               1U
#define XPAR_PSU_APM_1_ENABLE_PROFILE                0U
#define XPAR_PSU_APM_1_ENABLE_TRACE                  0U
#define XPAR_PSU_APM_1_S_AXI4_BASEADDR               0x00000000U
#define XPAR_PSU_APM_1_S_AXI4_HIGHADDR               0x00000000U
#define XPAR_PSU_APM_1_ENABLE_32BIT_FILTER_ID        1U

/* Definitions for peripheral PSU_APM_2 */
#define XPAR_PSU_APM_2_DEVICE_ID                     2U
#define XPAR_PSU_APM_2_BASEADDR                      0xFFA10000U
#define XPAR_PSU_APM_2_HIGHADDR                      0xFFA1FFFFU
#define XPAR_PSU_APM_2_GLOBAL_COUNT_WIDTH            32U
#define XPAR_PSU_APM_2_METRICS_SAMPLE_COUNT_WIDTH    32U
#define XPAR_PSU_APM_2_ENABLE_EVENT_COUNT            1U
#define XPAR_PSU_APM_2_NUM_MONITOR_SLOTS             1U
#define XPAR_PSU_APM_2_NUM_OF_COUNTERS               3U
#define XPAR_PSU_APM_2_HAVE_SAMPLED_METRIC_CNT       1U
#define XPAR_PSU_APM_2_ENABLE_EVENT_LOG              0U
#define XPAR_PSU_APM_2_FIFO_AXIS_DEPTH               32U
#define XPAR_PSU_APM_2_FIFO_AXIS_TDATA_WIDTH         56U
#define XPAR_PSU_APM_2_FIFO_AXIS_TID_WIDTH           1U
#define XPAR_PSU_APM_2_METRIC_COUNT_SCALE            1U
#define XPAR_PSU_APM_2_ENABLE_ADVANCED               1U
#define XPAR_PSU_APM_2_ENABLE_PROFILE                0U
#define XPAR_PSU_APM_2_ENABLE_TRACE                  0U
#define XPAR_PSU_APM_2_S_AXI4_BASEADDR               0x00000000U
#define XPAR_PSU_APM_2_S_AXI4_HIGHADDR               0x00000000U
#define XPAR_PSU_APM_2_ENABLE_32BIT_FILTER_ID        1U

/* Definitions for peripheral PSU_APM_5 */
#define XPAR_PSU_APM_5_DEVICE_ID                     3U
#define XPAR_PSU_APM_5_BASEADDR                      0xFD490000U
#define XPAR_PSU_APM_5_HIGHADDR                      0xFD49FFFFU
#define XPAR_PSU_APM_5_GLOBAL_COUNT_WIDTH            32U
#define XPAR_PSU_APM_5_METRICS_SAMPLE_COUNT_WIDTH    32U
#define XPAR_PSU_APM_5_ENABLE_EVENT_COUNT            1U
#define XPAR_PSU_APM_5_NUM_MONITOR_SLOTS             1U
#define XPAR_PSU_APM_5_NUM_OF_COUNTERS               3U
#define XPAR_PSU_APM_5_HAVE_SAMPLED_METRIC_CNT       1U
#define XPAR_PSU_APM_5_ENABLE_EVENT_LOG              0U
#define XPAR_PSU_APM_5_FIFO_AXIS_DEPTH               32U
#define XPAR_PSU_APM_5_FIFO_AXIS_TDATA_WIDTH         56U
#define XPAR_PSU_APM_5_FIFO_AXIS_TID_WIDTH           1U
#define XPAR_PSU_APM_5_METRIC_COUNT_SCALE            1U
#define XPAR_PSU_APM_5_ENABLE_ADVANCED               1U
#define XPAR_PSU_APM_5_ENABLE_PROFILE                0U
#define XPAR_PSU_APM_5_ENABLE_TRACE                  0U
#define XPAR_PSU_APM_5_S_AXI4_BASEADDR               0x00000000U
#define XPAR_PSU_APM_5_S_AXI4_HIGHADDR               0x00000000U
#define XPAR_PSU_APM_5_ENABLE_32BIT_FILTER_ID        1U

/******************************************************************/

/* Canonical definitions for peripheral PSU_APM_0 */
#define XPAR_AXIPMON_0_DEVICE_ID                     XPAR_PSU_APM_0_DEVICE_ID
#define XPAR_AXIPMON_0_BASEADDR                      0xFD0B0000U
#define XPAR_AXIPMON_0_HIGHADDR                      0xFD0BFFFFU
#define XPAR_AXIPMON_0_GLOBAL_COUNT_WIDTH            32U
#define XPAR_AXIPMON_0_METRICS_SAMPLE_COUNT_WIDTH    32U
#define XPAR_AXIPMON_0_ENABLE_EVENT_COUNT            1U
#define XPAR_AXIPMON_0_NUM_MONITOR_SLOTS             6U
#define XPAR_AXIPMON_0_NUM_OF_COUNTERS               10U
#define XPAR_AXIPMON_0_HAVE_SAMPLED_METRIC_CNT       1U
#define XPAR_AXIPMON_0_ENABLE_EVENT_LOG              0U
#define XPAR_AXIPMON_0_FIFO_AXIS_DEPTH               32U
#define XPAR_AXIPMON_0_FIFO_AXIS_TDATA_WIDTH         56U
#define XPAR_AXIPMON_0_FIFO_AXIS_TID_WIDTH           1U
#define XPAR_AXIPMON_0_METRIC_COUNT_SCALE            1U
#define XPAR_AXIPMON_0_ENABLE_ADVANCED               1U
#define XPAR_AXIPMON_0_ENABLE_PROFILE                0U
#define XPAR_AXIPMON_0_ENABLE_TRACE                  0U
#define XPAR_AXIPMON_0_S_AXI4_BASEADDR               0x00000000U
#define XPAR_AXIPMON_0_S_AXI4_HIGHADDR               0x00000000U
#define XPAR_AXIPMON_0_ENABLE_32BIT_FILTER_ID        1U

/* Canonical definitions for peripheral PSU_APM_1 */
#define XPAR_AXIPMON_1_DEVICE_ID                     XPAR_PSU_APM_1_DEVICE_ID
#define XPAR_AXIPMON_1_BASEADDR                      0xFFA00000U
#define XPAR_AXIPMON_1_HIGHADDR                      0xFFA0FFFFU
#define XPAR_AXIPMON_1_GLOBAL_COUNT_WIDTH            32U
#define XPAR_AXIPMON_1_METRICS_SAMPLE_COUNT_WIDTH    32U
#define XPAR_AXIPMON_1_ENABLE_EVENT_COUNT            1U
#define XPAR_AXIPMON_1_NUM_MONITOR_SLOTS             1U
#define XPAR_AXIPMON_1_NUM_OF_COUNTERS               3U
#define XPAR_AXIPMON_1_HAVE_SAMPLED_METRIC_CNT       1U
#define XPAR_AXIPMON_1_ENABLE_EVENT_LOG              0U
#define XPAR_AXIPMON_1_FIFO_AXIS_DEPTH               32U
#define XPAR_AXIPMON_1_FIFO_AXIS_TDATA_WIDTH         56U
#define XPAR_AXIPMON_1_FIFO_AXIS_TID_WIDTH           1U
#define XPAR_AXIPMON_1_METRIC_COUNT_SCALE            1U
#define XPAR_AXIPMON_1_ENABLE_ADVANCED               1U
#define XPAR_AXIPMON_1_ENABLE_PROFILE                0U
#define XPAR_AXIPMON_1_ENABLE_TRACE                  0U
#define XPAR_AXIPMON_1_S_AXI4_BASEADDR               0x00000000U
#define XPAR_AXIPMON_1_S_AXI4_HIGHADDR               0x00000000U
#define XPAR_AXIPMON_1_ENABLE_32BIT_FILTER_ID        1U

/* Canonical definitions for peripheral PSU_APM_2 */
#define XPAR_AXIPMON_2_DEVICE_ID                     XPAR_PSU_APM_2_DEVICE_ID
#define XPAR_AXIPMON_2_BASEADDR                      0xFFA10000U
#define XPAR_AXIPMON_2_HIGHADDR                      0xFFA1FFFFU
#define XPAR_AXIPMON_2_GLOBAL_COUNT_WIDTH            32U
#define XPAR_AXIPMON_2_METRICS_SAMPLE_COUNT_WIDTH    32U
#define XPAR_AXIPMON_2_ENABLE_EVENT_COUNT            1U
#define XPAR_AXIPMON_2_NUM_MONITOR_SLOTS             1U
#define XPAR_AXIPMON_2_NUM_OF_COUNTERS               3U
#define XPAR_AXIPMON_2_HAVE_SAMPLED_METRIC_CNT       1U
#define XPAR_AXIPMON_2_ENABLE_EVENT_LOG              0U
#define XPAR_AXIPMON_2_FIFO_AXIS_DEPTH               32U
#define XPAR_AXIPMON_2_FIFO_AXIS_TDATA_WIDTH         56U
#define XPAR_AXIPMON_2_FIFO_AXIS_TID_WIDTH           1U
#define XPAR_AXIPMON_2_METRIC_COUNT_SCALE            1U
#define XPAR_AXIPMON_2_ENABLE_ADVANCED               1U
#define XPAR_AXIPMON_2_ENABLE_PROFILE                0U
#define XPAR_AXIPMON_2_ENABLE_TRACE                  0U
#define XPAR_AXIPMON_2_S_AXI4_BASEADDR               0x00000000U
#define XPAR_AXIPMON_2_S_AXI4_HIGHADDR               0x00000000U
#define XPAR_AXIPMON_2_ENABLE_32BIT_FILTER_ID        1U

/* Canonical definitions for peripheral PSU_APM_5 */
#define XPAR_AXIPMON_3_DEVICE_ID                     XPAR_PSU_APM_5_DEVICE_ID
#define XPAR_AXIPMON_3_BASEADDR                      0xFD490000U
#define XPAR_AXIPMON_3_HIGHADDR                      0xFD49FFFFU
#define XPAR_AXIPMON_3_GLOBAL_COUNT_WIDTH            32U
#define XPAR_AXIPMON_3_METRICS_SAMPLE_COUNT_WIDTH    32U
#define XPAR_AXIPMON_3_ENABLE_EVENT_COUNT            1U
#define XPAR_AXIPMON_3_NUM_MONITOR_SLOTS             1U
#define XPAR_AXIPMON_3_NUM_OF_COUNTERS               3U
#define XPAR_AXIPMON_3_HAVE_SAMPLED_METRIC_CNT       1U
#define XPAR_AXIPMON_3_ENABLE_EVENT_LOG              0U
#define XPAR_AXIPMON_3_FIFO_AXIS_DEPTH               32U
#define XPAR_AXIPMON_3_FIFO_AXIS_TDATA_WIDTH         56U
#define XPAR_AXIPMON_3_FIFO_AXIS_TID_WIDTH           1U
#define XPAR_AXIPMON_3_METRIC_COUNT_SCALE            1U
#define XPAR_AXIPMON_3_ENABLE_ADVANCED               1U
#define XPAR_AXIPMON_3_ENABLE_PROFILE                0U
#define XPAR_AXIPMON_3_ENABLE_TRACE                  0U
#define XPAR_AXIPMON_3_S_AXI4_BASEADDR               0x00000000U
#define XPAR_AXIPMON_3_S_AXI4_HIGHADDR               0x00000000U
#define XPAR_AXIPMON_3_ENABLE_32BIT_FILTER_ID        1U

/******************************************************************/

/* Definitions for driver CANPS */
#define XPAR_XCANPS_NUM_INSTANCES                    1

/* Definitions for peripheral PSU_CAN_1 */
#define XPAR_PSU_CAN_1_DEVICE_ID                     0
#define XPAR_PSU_CAN_1_BASEADDR                      0xFF070000
#define XPAR_PSU_CAN_1_HIGHADDR                      0xFF07FFFF
#define XPAR_PSU_CAN_1_CAN_CLK_FREQ_HZ               99990000

/******************************************************************/

/* Canonical definitions for peripheral PSU_CAN_1 */
#define XPAR_XCANPS_0_DEVICE_ID                      XPAR_PSU_CAN_1_DEVICE_ID
#define XPAR_XCANPS_0_BASEADDR                       0xFF070000
#define XPAR_XCANPS_0_HIGHADDR                       0xFF07FFFF
#define XPAR_XCANPS_0_CAN_CLK_FREQ_HZ                99990000

/******************************************************************/

/* Definitions for driver CSUDMA */
#define XPAR_XCSUDMA_NUM_INSTANCES                   1

/* Definitions for peripheral PSU_CSUDMA */
#define XPAR_PSU_CSUDMA_DEVICE_ID                    0
#define XPAR_PSU_CSUDMA_BASEADDR                     0xFFC80000
#define XPAR_PSU_CSUDMA_HIGHADDR                     0xFFC9FFFF
#define XPAR_PSU_CSUDMA_CSUDMA_CLK_FREQ_HZ           0

/******************************************************************/

/* Canonical definitions for peripheral PSU_CSUDMA */
#define XPAR_XCSUDMA_0_DEVICE_ID                     XPAR_PSU_CSUDMA_DEVICE_ID
#define XPAR_XCSUDMA_0_BASEADDR                      0xFFC80000
#define XPAR_XCSUDMA_0_HIGHADDR                      0xFFC9FFFF
#define XPAR_XCSUDMA_0_CSUDMA_CLK_FREQ_HZ            0

/******************************************************************/

/* Definitions for driver DDRCPSU */
#define XPAR_XDDRCPSU_NUM_INSTANCES                  1

/* Definitions for peripheral PSU_DDRC_0 */
#define XPAR_PSU_DDRC_0_DEVICE_ID                    0
#define XPAR_PSU_DDRC_0_BASEADDR                     0xFD070000
#define XPAR_PSU_DDRC_0_HIGHADDR                     0xFD070FFF
#define XPAR_PSU_DDRC_0_HAS_ECC                      0
#define XPAR_PSU_DDRC_0_DDRC_CLK_FREQ_HZ             533280000

/******************************************************************/

/* Canonical definitions for peripheral PSU_DDRC_0 */
#define XPAR_DDRCPSU_0_DEVICE_ID                     XPAR_PSU_DDRC_0_DEVICE_ID
#define XPAR_DDRCPSU_0_BASEADDR                      0xFD070000
#define XPAR_DDRCPSU_0_HIGHADDR                      0xFD070FFF
#define XPAR_DDRCPSU_0_DDRC_CLK_FREQ_HZ              533280000

/******************************************************************/

/* Definitions for driver DPDMA */
#define XPAR_XDPDMA_NUM_INSTANCES                    1

/* Definitions for peripheral PSU_DPDMA */
#define XPAR_PSU_DPDMA_DEVICE_ID                     0
#define XPAR_PSU_DPDMA_BASEADDR                      0xFD4C0000
#define XPAR_PSU_DPDMA_HIGHADDR                      0xFD4CFFFF

/******************************************************************/

/* Canonical definitions for peripheral PSU_DPDMA */
#define XPAR_XDPDMA_0_DEVICE_ID                      XPAR_PSU_DPDMA_DEVICE_ID
#define XPAR_XDPDMA_0_BASEADDR                       0xFD4C0000
#define XPAR_XDPDMA_0_HIGHADDR                       0xFD4CFFFF

/******************************************************************/

/* Definitions for driver EMACPS */
#define XPAR_XEMACPS_NUM_INSTANCES                   1

/* Definitions for peripheral PSU_ETHERNET_3 */
#define XPAR_PSU_ETHERNET_3_DEVICE_ID                0
#define XPAR_PSU_ETHERNET_3_BASEADDR                 0xFF0E0000
#define XPAR_PSU_ETHERNET_3_HIGHADDR                 0xFF0EFFFF
#define XPAR_PSU_ETHERNET_3_ENET_CLK_FREQ_HZ         124987500
#define XPAR_PSU_ETHERNET_3_ENET_SLCR_1000MBPS_DIV0  12
#define XPAR_PSU_ETHERNET_3_ENET_SLCR_1000MBPS_DIV1  1
#define XPAR_PSU_ETHERNET_3_ENET_SLCR_100MBPS_DIV0   60
#define XPAR_PSU_ETHERNET_3_ENET_SLCR_100MBPS_DIV1   1
#define XPAR_PSU_ETHERNET_3_ENET_SLCR_10MBPS_DIV0    60
#define XPAR_PSU_ETHERNET_3_ENET_SLCR_10MBPS_DIV1    10
#define XPAR_PSU_ETHERNET_3_ENET_TSU_CLK_FREQ_HZ     249975000

/******************************************************************/

#define XPAR_PSU_ETHERNET_3_IS_CACHE_COHERENT        0
/* Canonical definitions for peripheral PSU_ETHERNET_3 */
#define XPAR_XEMACPS_0_DEVICE_ID                     XPAR_PSU_ETHERNET_3_DEVICE_ID
#define XPAR_XEMACPS_0_BASEADDR                      0xFF0E0000
#define XPAR_XEMACPS_0_HIGHADDR                      0xFF0EFFFF
#define XPAR_XEMACPS_0_ENET_CLK_FREQ_HZ              124987500
#define XPAR_XEMACPS_0_ENET_SLCR_1000Mbps_DIV0       12
#define XPAR_XEMACPS_0_ENET_SLCR_1000Mbps_DIV1       1
#define XPAR_XEMACPS_0_ENET_SLCR_100Mbps_DIV0        60
#define XPAR_XEMACPS_0_ENET_SLCR_100Mbps_DIV1        1
#define XPAR_XEMACPS_0_ENET_SLCR_10Mbps_DIV0         60
#define XPAR_XEMACPS_0_ENET_SLCR_10Mbps_DIV1         10
#define XPAR_XEMACPS_0_ENET_TSU_CLK_FREQ_HZ          249975000

/******************************************************************/

/* Definitions for peripheral PSU_AFI_0 */
#define XPAR_PSU_AFI_0_S_AXI_BASEADDR                0xFD360000
#define XPAR_PSU_AFI_0_S_AXI_HIGHADDR                0xFD36FFFF

/* Definitions for peripheral PSU_AFI_1 */
#define XPAR_PSU_AFI_1_S_AXI_BASEADDR                0xFD370000
#define XPAR_PSU_AFI_1_S_AXI_HIGHADDR                0xFD37FFFF

/* Definitions for peripheral PSU_AFI_2 */
#define XPAR_PSU_AFI_2_S_AXI_BASEADDR                0xFD380000
#define XPAR_PSU_AFI_2_S_AXI_HIGHADDR                0xFD38FFFF

/* Definitions for peripheral PSU_AFI_3 */
#define XPAR_PSU_AFI_3_S_AXI_BASEADDR                0xFD390000
#define XPAR_PSU_AFI_3_S_AXI_HIGHADDR                0xFD39FFFF

/* Definitions for peripheral PSU_AFI_4 */
#define XPAR_PSU_AFI_4_S_AXI_BASEADDR                0xFD3A0000
#define XPAR_PSU_AFI_4_S_AXI_HIGHADDR                0xFD3AFFFF

/* Definitions for peripheral PSU_AFI_5 */
#define XPAR_PSU_AFI_5_S_AXI_BASEADDR                0xFD3B0000
#define XPAR_PSU_AFI_5_S_AXI_HIGHADDR                0xFD3BFFFF

/* Definitions for peripheral PSU_AFI_6 */
#define XPAR_PSU_AFI_6_S_AXI_BASEADDR                0xFF9B0000
#define XPAR_PSU_AFI_6_S_AXI_HIGHADDR                0xFF9BFFFF

/* Definitions for peripheral PSU_APU */
#define XPAR_PSU_APU_S_AXI_BASEADDR                  0xFD5C0000
#define XPAR_PSU_APU_S_AXI_HIGHADDR                  0xFD5CFFFF

/* Definitions for peripheral PSU_CCI_GPV */
#define XPAR_PSU_CCI_GPV_S_AXI_BASEADDR              0xFD6E0000
#define XPAR_PSU_CCI_GPV_S_AXI_HIGHADDR              0xFD6EFFFF

/* Definitions for peripheral PSU_CCI_REG */
#define XPAR_PSU_CCI_REG_S_AXI_BASEADDR              0xFD5E0000
#define XPAR_PSU_CCI_REG_S_AXI_HIGHADDR              0xFD5EFFFF

/* Definitions for peripheral PSU_CRL_APB */
#define XPAR_PSU_CRL_APB_S_AXI_BASEADDR              0xFF5E0000
#define XPAR_PSU_CRL_APB_S_AXI_HIGHADDR              0xFF85FFFF

/* Definitions for peripheral PSU_CTRL_IPI */
#define XPAR_PSU_CTRL_IPI_S_AXI_BASEADDR             0xFF380000
#define XPAR_PSU_CTRL_IPI_S_AXI_HIGHADDR             0xFF3FFFFF

/* Definitions for peripheral PSU_DDR_0 */
#define XPAR_PSU_DDR_0_S_AXI_BASEADDR                0x00000000
#define XPAR_PSU_DDR_0_S_AXI_HIGHADDR                0x7FFFFFFF

/* Definitions for peripheral PSU_DDR_1 */
#define XPAR_PSU_DDR_1_S_AXI_BASEADDR                0x800000000
#define XPAR_PSU_DDR_1_S_AXI_HIGHADDR                0x87FFFFFFF

/* Definitions for peripheral PSU_DDR_PHY */
#define XPAR_PSU_DDR_PHY_S_AXI_BASEADDR              0xFD080000
#define XPAR_PSU_DDR_PHY_S_AXI_HIGHADDR              0xFD08FFFF

/* Definitions for peripheral PSU_DDR_QOS_CTRL */
#define XPAR_PSU_DDR_QOS_CTRL_S_AXI_BASEADDR         0xFD090000
#define XPAR_PSU_DDR_QOS_CTRL_S_AXI_HIGHADDR         0xFD09FFFF

/* Definitions for peripheral PSU_DDR_XMPU0_CFG */
#define XPAR_PSU_DDR_XMPU0_CFG_S_AXI_BASEADDR        0xFD000000
#define XPAR_PSU_DDR_XMPU0_CFG_S_AXI_HIGHADDR        0xFD00FFFF

/* Definitions for peripheral PSU_DDR_XMPU1_CFG */
#define XPAR_PSU_DDR_XMPU1_CFG_S_AXI_BASEADDR        0xFD010000
#define XPAR_PSU_DDR_XMPU1_CFG_S_AXI_HIGHADDR        0xFD01FFFF

/* Definitions for peripheral PSU_DDR_XMPU2_CFG */
#define XPAR_PSU_DDR_XMPU2_CFG_S_AXI_BASEADDR        0xFD020000
#define XPAR_PSU_DDR_XMPU2_CFG_S_AXI_HIGHADDR        0xFD02FFFF

/* Definitions for peripheral PSU_DDR_XMPU3_CFG */
#define XPAR_PSU_DDR_XMPU3_CFG_S_AXI_BASEADDR        0xFD030000
#define XPAR_PSU_DDR_XMPU3_CFG_S_AXI_HIGHADDR        0xFD03FFFF

/* Definitions for peripheral PSU_DDR_XMPU4_CFG */
#define XPAR_PSU_DDR_XMPU4_CFG_S_AXI_BASEADDR        0xFD040000
#define XPAR_PSU_DDR_XMPU4_CFG_S_AXI_HIGHADDR        0xFD04FFFF

/* Definitions for peripheral PSU_DDR_XMPU5_CFG */
#define XPAR_PSU_DDR_XMPU5_CFG_S_AXI_BASEADDR        0xFD050000
#define XPAR_PSU_DDR_XMPU5_CFG_S_AXI_HIGHADDR        0xFD05FFFF

/* Definitions for peripheral PSU_EFUSE */
#define XPAR_PSU_EFUSE_S_AXI_BASEADDR                0xFFCC0000
#define XPAR_PSU_EFUSE_S_AXI_HIGHADDR                0xFFCCFFFF

/* Definitions for peripheral PSU_FPD_GPV */
#define XPAR_PSU_FPD_GPV_S_AXI_BASEADDR              0xFD700000
#define XPAR_PSU_FPD_GPV_S_AXI_HIGHADDR              0xFD7FFFFF

/* Definitions for peripheral PSU_FPD_SLCR */
#define XPAR_PSU_FPD_SLCR_S_AXI_BASEADDR             0xFD610000
#define XPAR_PSU_FPD_SLCR_S_AXI_HIGHADDR             0xFD68FFFF

/* Definitions for peripheral PSU_FPD_SLCR_SECURE */
#define XPAR_PSU_FPD_SLCR_SECURE_S_AXI_BASEADDR      0xFD690000
#define XPAR_PSU_FPD_SLCR_SECURE_S_AXI_HIGHADDR      0xFD6CFFFF

/* Definitions for peripheral PSU_FPD_XMPU_CFG */
#define XPAR_PSU_FPD_XMPU_CFG_S_AXI_BASEADDR         0xFD5D0000
#define XPAR_PSU_FPD_XMPU_CFG_S_AXI_HIGHADDR         0xFD5DFFFF

/* Definitions for peripheral PSU_FPD_XMPU_SINK */
#define XPAR_PSU_FPD_XMPU_SINK_S_AXI_BASEADDR        0xFD4F0000
#define XPAR_PSU_FPD_XMPU_SINK_S_AXI_HIGHADDR        0xFD4FFFFF

/* Definitions for peripheral PSU_GPU */
#define XPAR_PSU_GPU_S_AXI_BASEADDR                  0xFD4B0000
#define XPAR_PSU_GPU_S_AXI_HIGHADDR                  0xFD4BFFFF

/* Definitions for peripheral PSU_IOU_SCNTR */
#define XPAR_PSU_IOU_SCNTR_S_AXI_BASEADDR            0xFF250000
#define XPAR_PSU_IOU_SCNTR_S_AXI_HIGHADDR            0xFF25FFFF

/* Definitions for peripheral PSU_IOU_SCNTRS */
#define XPAR_PSU_IOU_SCNTRS_S_AXI_BASEADDR           0xFF260000
#define XPAR_PSU_IOU_SCNTRS_S_AXI_HIGHADDR           0xFF26FFFF

/* Definitions for peripheral PSU_IOUSECURE_SLCR */
#define XPAR_PSU_IOUSECURE_SLCR_S_AXI_BASEADDR       0xFF240000
#define XPAR_PSU_IOUSECURE_SLCR_S_AXI_HIGHADDR       0xFF24FFFF

/* Definitions for peripheral PSU_IOUSLCR_0 */
#define XPAR_PSU_IOUSLCR_0_S_AXI_BASEADDR            0xFF180000
#define XPAR_PSU_IOUSLCR_0_S_AXI_HIGHADDR            0xFF23FFFF

/* Definitions for peripheral PSU_LPD_SLCR */
#define XPAR_PSU_LPD_SLCR_S_AXI_BASEADDR             0xFF410000
#define XPAR_PSU_LPD_SLCR_S_AXI_HIGHADDR             0xFF4AFFFF

/* Definitions for peripheral PSU_LPD_SLCR_SECURE */
#define XPAR_PSU_LPD_SLCR_SECURE_S_AXI_BASEADDR      0xFF4B0000
#define XPAR_PSU_LPD_SLCR_SECURE_S_AXI_HIGHADDR      0xFF4DFFFF

/* Definitions for peripheral PSU_LPD_XPPU */
#define XPAR_PSU_LPD_XPPU_S_AXI_BASEADDR             0xFF980000
#define XPAR_PSU_LPD_XPPU_S_AXI_HIGHADDR             0xFF99FFFF

/* Definitions for peripheral PSU_LPD_XPPU_SINK */
#define XPAR_PSU_LPD_XPPU_SINK_S_AXI_BASEADDR        0xFF9C0000
#define XPAR_PSU_LPD_XPPU_SINK_S_AXI_HIGHADDR        0xFF9CFFFF

/* Definitions for peripheral PSU_MBISTJTAG */
#define XPAR_PSU_MBISTJTAG_S_AXI_BASEADDR            0xFFCF0000
#define XPAR_PSU_MBISTJTAG_S_AXI_HIGHADDR            0xFFCFFFFF

/* Definitions for peripheral PSU_MESSAGE_BUFFERS */
#define XPAR_PSU_MESSAGE_BUFFERS_S_AXI_BASEADDR      0xFF990000
#define XPAR_PSU_MESSAGE_BUFFERS_S_AXI_HIGHADDR      0xFF99FFFF

/* Definitions for peripheral PSU_OCM */
#define XPAR_PSU_OCM_S_AXI_BASEADDR                  0xFF960000
#define XPAR_PSU_OCM_S_AXI_HIGHADDR                  0xFF96FFFF

/* Definitions for peripheral PSU_OCM_RAM_0 */
#define XPAR_PSU_OCM_RAM_0_S_AXI_BASEADDR            0xFFFC0000
#define XPAR_PSU_OCM_RAM_0_S_AXI_HIGHADDR            0xFFFFFFFF

/* Definitions for peripheral PSU_OCM_XMPU_CFG */
#define XPAR_PSU_OCM_XMPU_CFG_S_AXI_BASEADDR         0xFFA70000
#define XPAR_PSU_OCM_XMPU_CFG_S_AXI_HIGHADDR         0xFFA7FFFF

/* Definitions for peripheral PSU_PCIE */
#define XPAR_PSU_PCIE_S_AXI_BASEADDR                 0xFD0E0000
#define XPAR_PSU_PCIE_S_AXI_HIGHADDR                 0xFD0EFFFF

/* Definitions for peripheral PSU_PCIE_ATTRIB_0 */
#define XPAR_PSU_PCIE_ATTRIB_0_S_AXI_BASEADDR        0xFD480000
#define XPAR_PSU_PCIE_ATTRIB_0_S_AXI_HIGHADDR        0xFD48FFFF

/* Definitions for peripheral PSU_PCIE_DMA */
#define XPAR_PSU_PCIE_DMA_S_AXI_BASEADDR             0xFD0F0000
#define XPAR_PSU_PCIE_DMA_S_AXI_HIGHADDR             0xFD0FFFFF

/* Definitions for peripheral PSU_PCIE_HIGH1 */
#define XPAR_PSU_PCIE_HIGH1_S_AXI_BASEADDR           0x600000000
#define XPAR_PSU_PCIE_HIGH1_S_AXI_HIGHADDR           0x7FFFFFFFF

/* Definitions for peripheral PSU_PCIE_HIGH2 */
#define XPAR_PSU_PCIE_HIGH2_S_AXI_BASEADDR           0x8000000000
#define XPAR_PSU_PCIE_HIGH2_S_AXI_HIGHADDR           0xBFFFFFFFFF

/* Definitions for peripheral PSU_PCIE_LOW */
#define XPAR_PSU_PCIE_LOW_S_AXI_BASEADDR             0xE0000000
#define XPAR_PSU_PCIE_LOW_S_AXI_HIGHADDR             0xEFFFFFFF

/* Definitions for peripheral PSU_PMU_GLOBAL_0 */
#define XPAR_PSU_PMU_GLOBAL_0_S_AXI_BASEADDR         0xFFD80000
#define XPAR_PSU_PMU_GLOBAL_0_S_AXI_HIGHADDR         0xFFDBFFFF

/* Definitions for peripheral PSU_QSPI_LINEAR_0 */
#define XPAR_PSU_QSPI_LINEAR_0_S_AXI_BASEADDR        0xC0000000
#define XPAR_PSU_QSPI_LINEAR_0_S_AXI_HIGHADDR        0xDFFFFFFF

/* Definitions for peripheral PSU_R5_0_ATCM_GLOBAL */
#define XPAR_PSU_R5_0_ATCM_GLOBAL_S_AXI_BASEADDR     0xFFE00000
#define XPAR_PSU_R5_0_ATCM_GLOBAL_S_AXI_HIGHADDR     0xFFE0FFFF

/* Definitions for peripheral PSU_R5_0_BTCM_GLOBAL */
#define XPAR_PSU_R5_0_BTCM_GLOBAL_S_AXI_BASEADDR     0xFFE20000
#define XPAR_PSU_R5_0_BTCM_GLOBAL_S_AXI_HIGHADDR     0xFFE2FFFF

/* Definitions for peripheral PSU_R5_1_ATCM_GLOBAL */
#define XPAR_PSU_R5_1_ATCM_GLOBAL_S_AXI_BASEADDR     0xFFE90000
#define XPAR_PSU_R5_1_ATCM_GLOBAL_S_AXI_HIGHADDR     0xFFE9FFFF

/* Definitions for peripheral PSU_R5_1_BTCM_GLOBAL */
#define XPAR_PSU_R5_1_BTCM_GLOBAL_S_AXI_BASEADDR     0xFFEB0000
#define XPAR_PSU_R5_1_BTCM_GLOBAL_S_AXI_HIGHADDR     0xFFEBFFFF

/* Definitions for peripheral PSU_R5_TCM_RAM_GLOBAL */
#define XPAR_PSU_R5_TCM_RAM_GLOBAL_S_AXI_BASEADDR    0xFFE00000
#define XPAR_PSU_R5_TCM_RAM_GLOBAL_S_AXI_HIGHADDR    0xFFE3FFFF

/* Definitions for peripheral PSU_RPU */
#define XPAR_PSU_RPU_S_AXI_BASEADDR                  0xFF9A0000
#define XPAR_PSU_RPU_S_AXI_HIGHADDR                  0xFF9AFFFF

/* Definitions for peripheral PSU_RSA */
#define XPAR_PSU_RSA_S_AXI_BASEADDR                  0xFFCE0000
#define XPAR_PSU_RSA_S_AXI_HIGHADDR                  0xFFCEFFFF

/* Definitions for peripheral PSU_SATA */
#define XPAR_PSU_SATA_S_AXI_BASEADDR                 0xFD0C0000
#define XPAR_PSU_SATA_S_AXI_HIGHADDR                 0xFD0CFFFF

/* Definitions for peripheral PSU_SERDES */
#define XPAR_PSU_SERDES_S_AXI_BASEADDR               0xFD400000
#define XPAR_PSU_SERDES_S_AXI_HIGHADDR               0xFD47FFFF

/* Definitions for peripheral PSU_SIOU */
#define XPAR_PSU_SIOU_S_AXI_BASEADDR                 0xFD3D0000
#define XPAR_PSU_SIOU_S_AXI_HIGHADDR                 0xFD3DFFFF

/* Definitions for peripheral PSU_SMMU_GPV */
#define XPAR_PSU_SMMU_GPV_S_AXI_BASEADDR             0xFD800000
#define XPAR_PSU_SMMU_GPV_S_AXI_HIGHADDR             0xFDFFFFFF

/* Definitions for peripheral PSU_SMMU_REG */
#define XPAR_PSU_SMMU_REG_S_AXI_BASEADDR             0xFD5F0000
#define XPAR_PSU_SMMU_REG_S_AXI_HIGHADDR             0xFD5FFFFF

/* Definitions for peripheral PSU_USB_0 */
#define XPAR_PSU_USB_0_S_AXI_BASEADDR                0xFF9D0000
#define XPAR_PSU_USB_0_S_AXI_HIGHADDR                0xFF9DFFFF

/******************************************************************/

/* Definitions for driver GPIOPS */
#define XPAR_XGPIOPS_NUM_INSTANCES                   1

/* Definitions for peripheral PSU_GPIO_0 */
#define XPAR_PSU_GPIO_0_DEVICE_ID                    0
#define XPAR_PSU_GPIO_0_BASEADDR                     0xFF0A0000
#define XPAR_PSU_GPIO_0_HIGHADDR                     0xFF0AFFFF

/******************************************************************/

/* Canonical definitions for peripheral PSU_GPIO_0 */
#define XPAR_XGPIOPS_0_DEVICE_ID                     XPAR_PSU_GPIO_0_DEVICE_ID
#define XPAR_XGPIOPS_0_BASEADDR                      0xFF0A0000
#define XPAR_XGPIOPS_0_HIGHADDR                      0xFF0AFFFF

/******************************************************************/

/* Definitions for driver IICPS */
#define XPAR_XIICPS_NUM_INSTANCES                    2

/* Definitions for peripheral PSU_I2C_0 */
#define XPAR_PSU_I2C_0_DEVICE_ID                     0
#define XPAR_PSU_I2C_0_BASEADDR                      0xFF020000
#define XPAR_PSU_I2C_0_HIGHADDR                      0xFF02FFFF
#define XPAR_PSU_I2C_0_I2C_CLK_FREQ_HZ               99990000

/* Definitions for peripheral PSU_I2C_1 */
#define XPAR_PSU_I2C_1_DEVICE_ID                     1
#define XPAR_PSU_I2C_1_BASEADDR                      0xFF030000
#define XPAR_PSU_I2C_1_HIGHADDR                      0xFF03FFFF
#define XPAR_PSU_I2C_1_I2C_CLK_FREQ_HZ               99990000

/******************************************************************/

/* Canonical definitions for peripheral PSU_I2C_0 */
#define XPAR_XIICPS_0_DEVICE_ID                      XPAR_PSU_I2C_0_DEVICE_ID
#define XPAR_XIICPS_0_BASEADDR                       0xFF020000
#define XPAR_XIICPS_0_HIGHADDR                       0xFF02FFFF
#define XPAR_XIICPS_0_I2C_CLK_FREQ_HZ                99990000

/* Canonical definitions for peripheral PSU_I2C_1 */
#define XPAR_XIICPS_1_DEVICE_ID                      XPAR_PSU_I2C_1_DEVICE_ID
#define XPAR_XIICPS_1_BASEADDR                       0xFF030000
#define XPAR_XIICPS_1_HIGHADDR                       0xFF03FFFF
#define XPAR_XIICPS_1_I2C_CLK_FREQ_HZ                99990000

/******************************************************************/

#define XPAR_XIPIPSU_NUM_INSTANCES                   1U

/* Parameter definitions for peripheral psu_ipi_0 */
#define XPAR_PSU_IPI_0_DEVICE_ID                     0U
#define XPAR_PSU_IPI_0_BASE_ADDRESS                  0xFF300000U
#define XPAR_PSU_IPI_0_BIT_MASK                      0x00000001U
#define XPAR_PSU_IPI_0_BUFFER_INDEX                  2U
#define XPAR_PSU_IPI_0_INT_ID                        67U

/* Canonical definitions for peripheral psu_ipi_0 */
#define XPAR_XIPIPSU_0_DEVICE_ID                     XPAR_PSU_IPI_0_DEVICE_ID
#define XPAR_XIPIPSU_0_BASE_ADDRESS                  XPAR_PSU_IPI_0_BASE_ADDRESS
#define XPAR_XIPIPSU_0_BIT_MASK                      XPAR_PSU_IPI_0_BIT_MASK
#define XPAR_XIPIPSU_0_BUFFER_INDEX                  XPAR_PSU_IPI_0_BUFFER_INDEX
#define XPAR_XIPIPSU_0_INT_ID                        XPAR_PSU_IPI_0_INT_ID

#define XPAR_XIPIPSU_NUM_TARGETS                     7U

#define XPAR_PSU_IPI_0_BIT_MASK                      0x00000001U
#define XPAR_PSU_IPI_0_BUFFER_INDEX                  2U
#define XPAR_PSU_IPI_1_BIT_MASK                      0x00000100U
#define XPAR_PSU_IPI_1_BUFFER_INDEX                  0U
#define XPAR_PSU_IPI_2_BIT_MASK                      0x00000200U
#define XPAR_PSU_IPI_2_BUFFER_INDEX                  1U
#define XPAR_PSU_IPI_3_BIT_MASK                      0x00010000U
#define XPAR_PSU_IPI_3_BUFFER_INDEX                  7U
#define XPAR_PSU_IPI_4_BIT_MASK                      0x00020000U
#define XPAR_PSU_IPI_4_BUFFER_INDEX                  7U
#define XPAR_PSU_IPI_5_BIT_MASK                      0x00040000U
#define XPAR_PSU_IPI_5_BUFFER_INDEX                  7U
#define XPAR_PSU_IPI_6_BIT_MASK                      0x00080000U
#define XPAR_PSU_IPI_6_BUFFER_INDEX                  7U
/* Target List for referring to processor IPI Targets */

#define XPAR_XIPIPS_TARGET_PSU_CORTEXA53_0_CH0_MASK  XPAR_PSU_IPI_0_BIT_MASK
#define XPAR_XIPIPS_TARGET_PSU_CORTEXA53_0_CH0_INDEX 0U

#define XPAR_XIPIPS_TARGET_PSU_CORTEXA53_1_CH0_MASK  XPAR_PSU_IPI_0_BIT_MASK
#define XPAR_XIPIPS_TARGET_PSU_CORTEXA53_1_CH0_INDEX 0U

#define XPAR_XIPIPS_TARGET_PSU_CORTEXA53_2_CH0_MASK  XPAR_PSU_IPI_0_BIT_MASK
#define XPAR_XIPIPS_TARGET_PSU_CORTEXA53_2_CH0_INDEX 0U

#define XPAR_XIPIPS_TARGET_PSU_CORTEXA53_3_CH0_MASK  XPAR_PSU_IPI_0_BIT_MASK
#define XPAR_XIPIPS_TARGET_PSU_CORTEXA53_3_CH0_INDEX 0U

#define XPAR_XIPIPS_TARGET_PSU_CORTEXR5_0_CH0_MASK   XPAR_PSU_IPI_1_BIT_MASK
#define XPAR_XIPIPS_TARGET_PSU_CORTEXR5_0_CH0_INDEX  1U

#define XPAR_XIPIPS_TARGET_PSU_CORTEXR5_1_CH0_MASK   XPAR_PSU_IPI_2_BIT_MASK
#define XPAR_XIPIPS_TARGET_PSU_CORTEXR5_1_CH0_INDEX  2U

#define XPAR_XIPIPS_TARGET_PSU_PMU_0_CH0_MASK        XPAR_PSU_IPI_3_BIT_MASK
#define XPAR_XIPIPS_TARGET_PSU_PMU_0_CH0_INDEX       3U
#define XPAR_XIPIPS_TARGET_PSU_PMU_0_CH1_MASK        XPAR_PSU_IPI_4_BIT_MASK
#define XPAR_XIPIPS_TARGET_PSU_PMU_0_CH1_INDEX       4U
#define XPAR_XIPIPS_TARGET_PSU_PMU_0_CH2_MASK        XPAR_PSU_IPI_5_BIT_MASK
#define XPAR_XIPIPS_TARGET_PSU_PMU_0_CH2_INDEX       5U
#define XPAR_XIPIPS_TARGET_PSU_PMU_0_CH3_MASK        XPAR_PSU_IPI_6_BIT_MASK
#define XPAR_XIPIPS_TARGET_PSU_PMU_0_CH3_INDEX       6U

/* Definitions for driver QSPIPSU */
#define XPAR_XQSPIPSU_NUM_INSTANCES                  1

/* Definitions for peripheral PSU_QSPI_0 */
#define XPAR_PSU_QSPI_0_DEVICE_ID                    0
#define XPAR_PSU_QSPI_0_BASEADDR                     0xFF0F0000
#define XPAR_PSU_QSPI_0_HIGHADDR                     0xFF0FFFFF
#define XPAR_PSU_QSPI_0_QSPI_CLK_FREQ_HZ             124987500
#define XPAR_PSU_QSPI_0_QSPI_MODE                    2
#define XPAR_PSU_QSPI_0_QSPI_BUS_WIDTH               2

/******************************************************************/

#define XPAR_PSU_QSPI_0_IS_CACHE_COHERENT            0
/* Canonical definitions for peripheral PSU_QSPI_0 */
#define XPAR_XQSPIPSU_0_DEVICE_ID                    XPAR_PSU_QSPI_0_DEVICE_ID
#define XPAR_XQSPIPSU_0_BASEADDR                     0xFF0F0000
#define XPAR_XQSPIPSU_0_HIGHADDR                     0xFF0FFFFF
#define XPAR_XQSPIPSU_0_QSPI_CLK_FREQ_HZ             124987500
#define XPAR_XQSPIPSU_0_QSPI_MODE                    2
#define XPAR_XQSPIPSU_0_QSPI_BUS_WIDTH               2

/******************************************************************/

/* Definitions for driver RESETPS */
#define XPAR_XRESETPS_NUM_INSTANCES                  1U
/* Definitions for peripheral RESETPS */
#define XPAR_XRESETPS_DEVICE_ID                      0
#define XPAR_XRESETPS_BASEADDR                       0xFFFFFFFFU

/******************************************************************/

/* Definitions for driver RTCPSU */
#define XPAR_XRTCPSU_NUM_INSTANCES                   1

/* Definitions for peripheral PSU_RTC */
#define XPAR_PSU_RTC_DEVICE_ID                       0
#define XPAR_PSU_RTC_BASEADDR                        0xFFA60000
#define XPAR_PSU_RTC_HIGHADDR                        0xFFA6FFFF

/******************************************************************/

/* Canonical definitions for peripheral PSU_RTC */
#define XPAR_XRTCPSU_0_DEVICE_ID                     XPAR_PSU_RTC_DEVICE_ID
#define XPAR_XRTCPSU_0_BASEADDR                      0xFFA60000
#define XPAR_XRTCPSU_0_HIGHADDR                      0xFFA6FFFF

/******************************************************************/

/* Definitions for driver SCUGIC */
#define XPAR_XSCUGIC_NUM_INSTANCES                   1U

/* Definitions for peripheral PSU_ACPU_GIC */
#define XPAR_PSU_ACPU_GIC_DEVICE_ID                  0U
#define XPAR_PSU_ACPU_GIC_BASEADDR                   0xF9020000U
#define XPAR_PSU_ACPU_GIC_HIGHADDR                   0xF9020FFFU
#define XPAR_PSU_ACPU_GIC_DIST_BASEADDR              0xF9010000U

/******************************************************************/

/* Canonical definitions for peripheral PSU_ACPU_GIC */
#define XPAR_SCUGIC_0_DEVICE_ID                      0U
#define XPAR_SCUGIC_0_CPU_BASEADDR                   0xF9020000U
#define XPAR_SCUGIC_0_CPU_HIGHADDR                   0xF9020FFFU
#define XPAR_SCUGIC_0_DIST_BASEADDR                  0xF9010000U

/******************************************************************/

/* Definitions for driver SDPS */
#define XPAR_XSDPS_NUM_INSTANCES                     1

/* Definitions for peripheral PSU_SD_1 */
#define XPAR_PSU_SD_1_DEVICE_ID                      0
#define XPAR_PSU_SD_1_BASEADDR                       0xFF170000
#define XPAR_PSU_SD_1_HIGHADDR                       0xFF17FFFF
#define XPAR_PSU_SD_1_SDIO_CLK_FREQ_HZ               187481250
#define XPAR_PSU_SD_1_HAS_CD                         1
#define XPAR_PSU_SD_1_HAS_WP                         1
#define XPAR_PSU_SD_1_BUS_WIDTH                      8
#define XPAR_PSU_SD_1_MIO_BANK                       1
#define XPAR_PSU_SD_1_HAS_EMIO                       0

/******************************************************************/

#define XPAR_PSU_SD_1_IS_CACHE_COHERENT              0
/* Canonical definitions for peripheral PSU_SD_1 */
#define XPAR_XSDPS_0_DEVICE_ID                       XPAR_PSU_SD_1_DEVICE_ID
#define XPAR_XSDPS_0_BASEADDR                        0xFF170000
#define XPAR_XSDPS_0_HIGHADDR                        0xFF17FFFF
#define XPAR_XSDPS_0_SDIO_CLK_FREQ_HZ                187481250
#define XPAR_XSDPS_0_HAS_CD                          1
#define XPAR_XSDPS_0_HAS_WP                          1
#define XPAR_XSDPS_0_BUS_WIDTH                       8
#define XPAR_XSDPS_0_MIO_BANK                        1
#define XPAR_XSDPS_0_HAS_EMIO                        0

/******************************************************************/

/* Definitions for driver SYSMONPSU */
#define XPAR_XSYSMONPSU_NUM_INSTANCES                1

/* Definitions for peripheral PSU_AMS */
#define XPAR_PSU_AMS_DEVICE_ID                       0
#define XPAR_PSU_AMS_BASEADDR                        0xFFA50000
#define XPAR_PSU_AMS_HIGHADDR                        0xFFA5FFFF

/******************************************************************/

#define XPAR_PSU_AMS_REF_FREQMHZ                     49.995
/* Canonical definitions for peripheral PSU_AMS */
#define XPAR_XSYSMONPSU_0_DEVICE_ID                  XPAR_PSU_AMS_DEVICE_ID
#define XPAR_XSYSMONPSU_0_BASEADDR                   0xFFA50000
#define XPAR_XSYSMONPSU_0_HIGHADDR                   0xFFA5FFFF

/******************************************************************/

/* Definitions for driver TTCPS */
#define XPAR_XTTCPS_NUM_INSTANCES                    12U

/* Definitions for peripheral PSU_TTC_0 */
#define XPAR_PSU_TTC_0_DEVICE_ID                     0U
#define XPAR_PSU_TTC_0_BASEADDR                      0XFF110000U
#define XPAR_PSU_TTC_0_TTC_CLK_FREQ_HZ               100000000U
#define XPAR_PSU_TTC_0_TTC_CLK_CLKSRC                0U
#define XPAR_PSU_TTC_1_DEVICE_ID                     1U
#define XPAR_PSU_TTC_1_BASEADDR                      0XFF110004U
#define XPAR_PSU_TTC_1_TTC_CLK_FREQ_HZ               100000000U
#define XPAR_PSU_TTC_1_TTC_CLK_CLKSRC                0U
#define XPAR_PSU_TTC_2_DEVICE_ID                     2U
#define XPAR_PSU_TTC_2_BASEADDR                      0XFF110008U
#define XPAR_PSU_TTC_2_TTC_CLK_FREQ_HZ               100000000U
#define XPAR_PSU_TTC_2_TTC_CLK_CLKSRC                0U

/* Definitions for peripheral PSU_TTC_1 */
#define XPAR_PSU_TTC_3_DEVICE_ID                     3U
#define XPAR_PSU_TTC_3_BASEADDR                      0XFF120000U
#define XPAR_PSU_TTC_3_TTC_CLK_FREQ_HZ               100000000U
#define XPAR_PSU_TTC_3_TTC_CLK_CLKSRC                0U
#define XPAR_PSU_TTC_4_DEVICE_ID                     4U
#define XPAR_PSU_TTC_4_BASEADDR                      0XFF120004U
#define XPAR_PSU_TTC_4_TTC_CLK_FREQ_HZ               100000000U
#define XPAR_PSU_TTC_4_TTC_CLK_CLKSRC                0U
#define XPAR_PSU_TTC_5_DEVICE_ID                     5U
#define XPAR_PSU_TTC_5_BASEADDR                      0XFF120008U
#define XPAR_PSU_TTC_5_TTC_CLK_FREQ_HZ               100000000U
#define XPAR_PSU_TTC_5_TTC_CLK_CLKSRC                0U

/* Definitions for peripheral PSU_TTC_2 */
#define XPAR_PSU_TTC_6_DEVICE_ID                     6U
#define XPAR_PSU_TTC_6_BASEADDR                      0XFF130000U
#define XPAR_PSU_TTC_6_TTC_CLK_FREQ_HZ               100000000U
#define XPAR_PSU_TTC_6_TTC_CLK_CLKSRC                0U
#define XPAR_PSU_TTC_7_DEVICE_ID                     7U
#define XPAR_PSU_TTC_7_BASEADDR                      0XFF130004U
#define XPAR_PSU_TTC_7_TTC_CLK_FREQ_HZ               100000000U
#define XPAR_PSU_TTC_7_TTC_CLK_CLKSRC                0U
#define XPAR_PSU_TTC_8_DEVICE_ID                     8U
#define XPAR_PSU_TTC_8_BASEADDR                      0XFF130008U
#define XPAR_PSU_TTC_8_TTC_CLK_FREQ_HZ               100000000U
#define XPAR_PSU_TTC_8_TTC_CLK_CLKSRC                0U

/* Definitions for peripheral PSU_TTC_3 */
#define XPAR_PSU_TTC_9_DEVICE_ID                     9U
#define XPAR_PSU_TTC_9_BASEADDR                      0XFF140000U
#define XPAR_PSU_TTC_9_TTC_CLK_FREQ_HZ               100000000U
#define XPAR_PSU_TTC_9_TTC_CLK_CLKSRC                0U
#define XPAR_PSU_TTC_10_DEVICE_ID                    10U
#define XPAR_PSU_TTC_10_BASEADDR                     0XFF140004U
#define XPAR_PSU_TTC_10_TTC_CLK_FREQ_HZ              100000000U
#define XPAR_PSU_TTC_10_TTC_CLK_CLKSRC               0U
#define XPAR_PSU_TTC_11_DEVICE_ID                    11U
#define XPAR_PSU_TTC_11_BASEADDR                     0XFF140008U
#define XPAR_PSU_TTC_11_TTC_CLK_FREQ_HZ              100000000U
#define XPAR_PSU_TTC_11_TTC_CLK_CLKSRC               0U

/******************************************************************/

/* Canonical definitions for peripheral PSU_TTC_0 */
#define XPAR_XTTCPS_0_DEVICE_ID                      XPAR_PSU_TTC_0_DEVICE_ID
#define XPAR_XTTCPS_0_BASEADDR                       0xFF110000U
#define XPAR_XTTCPS_0_TTC_CLK_FREQ_HZ                100000000U
#define XPAR_XTTCPS_0_TTC_CLK_CLKSRC                 0U

#define XPAR_XTTCPS_1_DEVICE_ID                      XPAR_PSU_TTC_1_DEVICE_ID
#define XPAR_XTTCPS_1_BASEADDR                       0xFF110004U
#define XPAR_XTTCPS_1_TTC_CLK_FREQ_HZ                100000000U
#define XPAR_XTTCPS_1_TTC_CLK_CLKSRC                 0U

#define XPAR_XTTCPS_2_DEVICE_ID                      XPAR_PSU_TTC_2_DEVICE_ID
#define XPAR_XTTCPS_2_BASEADDR                       0xFF110008U
#define XPAR_XTTCPS_2_TTC_CLK_FREQ_HZ                100000000U
#define XPAR_XTTCPS_2_TTC_CLK_CLKSRC                 0U

/* Canonical definitions for peripheral PSU_TTC_1 */
#define XPAR_XTTCPS_3_DEVICE_ID                      XPAR_PSU_TTC_3_DEVICE_ID
#define XPAR_XTTCPS_3_BASEADDR                       0xFF120000U
#define XPAR_XTTCPS_3_TTC_CLK_FREQ_HZ                100000000U
#define XPAR_XTTCPS_3_TTC_CLK_CLKSRC                 0U

#define XPAR_XTTCPS_4_DEVICE_ID                      XPAR_PSU_TTC_4_DEVICE_ID
#define XPAR_XTTCPS_4_BASEADDR                       0xFF120004U
#define XPAR_XTTCPS_4_TTC_CLK_FREQ_HZ                100000000U
#define XPAR_XTTCPS_4_TTC_CLK_CLKSRC                 0U

#define XPAR_XTTCPS_5_DEVICE_ID                      XPAR_PSU_TTC_5_DEVICE_ID
#define XPAR_XTTCPS_5_BASEADDR                       0xFF120008U
#define XPAR_XTTCPS_5_TTC_CLK_FREQ_HZ                100000000U
#define XPAR_XTTCPS_5_TTC_CLK_CLKSRC                 0U

/* Canonical definitions for peripheral PSU_TTC_2 */
#define XPAR_XTTCPS_6_DEVICE_ID                      XPAR_PSU_TTC_6_DEVICE_ID
#define XPAR_XTTCPS_6_BASEADDR                       0xFF130000U
#define XPAR_XTTCPS_6_TTC_CLK_FREQ_HZ                100000000U
#define XPAR_XTTCPS_6_TTC_CLK_CLKSRC                 0U

#define XPAR_XTTCPS_7_DEVICE_ID                      XPAR_PSU_TTC_7_DEVICE_ID
#define XPAR_XTTCPS_7_BASEADDR                       0xFF130004U
#define XPAR_XTTCPS_7_TTC_CLK_FREQ_HZ                100000000U
#define XPAR_XTTCPS_7_TTC_CLK_CLKSRC                 0U

#define XPAR_XTTCPS_8_DEVICE_ID                      XPAR_PSU_TTC_8_DEVICE_ID
#define XPAR_XTTCPS_8_BASEADDR                       0xFF130008U
#define XPAR_XTTCPS_8_TTC_CLK_FREQ_HZ                100000000U
#define XPAR_XTTCPS_8_TTC_CLK_CLKSRC                 0U

/* Canonical definitions for peripheral PSU_TTC_3 */
#define XPAR_XTTCPS_9_DEVICE_ID                      XPAR_PSU_TTC_9_DEVICE_ID
#define XPAR_XTTCPS_9_BASEADDR                       0xFF140000U
#define XPAR_XTTCPS_9_TTC_CLK_FREQ_HZ                100000000U
#define XPAR_XTTCPS_9_TTC_CLK_CLKSRC                 0U

#define XPAR_XTTCPS_10_DEVICE_ID                     XPAR_PSU_TTC_10_DEVICE_ID
#define XPAR_XTTCPS_10_BASEADDR                      0xFF140004U
#define XPAR_XTTCPS_10_TTC_CLK_FREQ_HZ               100000000U
#define XPAR_XTTCPS_10_TTC_CLK_CLKSRC                0U

#define XPAR_XTTCPS_11_DEVICE_ID                     XPAR_PSU_TTC_11_DEVICE_ID
#define XPAR_XTTCPS_11_BASEADDR                      0xFF140008U
#define XPAR_XTTCPS_11_TTC_CLK_FREQ_HZ               100000000U
#define XPAR_XTTCPS_11_TTC_CLK_CLKSRC                0U

/******************************************************************/

/* Definitions for driver UARTPS */
#define XPAR_XUARTPS_NUM_INSTANCES                   2

/* Definitions for peripheral PSU_UART_0 */
#define XPAR_PSU_UART_0_DEVICE_ID                    0
#define XPAR_PSU_UART_0_BASEADDR                     0xFF000000
#define XPAR_PSU_UART_0_HIGHADDR                     0xFF00FFFF
#define XPAR_PSU_UART_0_UART_CLK_FREQ_HZ             99990000
#define XPAR_PSU_UART_0_HAS_MODEM                    0

/* Definitions for peripheral PSU_UART_1 */
#define XPAR_PSU_UART_1_DEVICE_ID                    1
#define XPAR_PSU_UART_1_BASEADDR                     0xFF010000
#define XPAR_PSU_UART_1_HIGHADDR                     0xFF01FFFF
#define XPAR_PSU_UART_1_UART_CLK_FREQ_HZ             99990000
#define XPAR_PSU_UART_1_HAS_MODEM                    0

/******************************************************************/

/* Canonical definitions for peripheral PSU_UART_0 */
#define XPAR_XUARTPS_0_DEVICE_ID                     XPAR_PSU_UART_0_DEVICE_ID
#define XPAR_XUARTPS_0_BASEADDR                      0xFF000000
#define XPAR_XUARTPS_0_HIGHADDR                      0xFF00FFFF
#define XPAR_XUARTPS_0_UART_CLK_FREQ_HZ              99990000
#define XPAR_XUARTPS_0_HAS_MODEM                     0

/* Canonical definitions for peripheral PSU_UART_1 */
#define XPAR_XUARTPS_1_DEVICE_ID                     XPAR_PSU_UART_1_DEVICE_ID
#define XPAR_XUARTPS_1_BASEADDR                      0xFF010000
#define XPAR_XUARTPS_1_HIGHADDR                      0xFF01FFFF
#define XPAR_XUARTPS_1_UART_CLK_FREQ_HZ              99990000
#define XPAR_XUARTPS_1_HAS_MODEM                     0

/******************************************************************/

/* Definitions for driver USBPSU */
#define XPAR_XUSBPSU_NUM_INSTANCES                   1

/* Definitions for peripheral PSU_USB_XHCI_0 */
#define XPAR_PSU_USB_XHCI_0_DEVICE_ID                0
#define XPAR_PSU_USB_XHCI_0_BASEADDR                 0xFE200000
#define XPAR_PSU_USB_XHCI_0_HIGHADDR                 0xFE20FFFF

/******************************************************************/

#define XPAR_PSU_USB_XHCI_0_IS_CACHE_COHERENT        0
/* Canonical definitions for peripheral PSU_USB_XHCI_0 */
#define XPAR_XUSBPSU_0_DEVICE_ID                     XPAR_PSU_USB_XHCI_0_DEVICE_ID
#define XPAR_XUSBPSU_0_BASEADDR                      0xFE200000
#define XPAR_XUSBPSU_0_HIGHADDR                      0xFE20FFFF

/******************************************************************/

/* Definitions for driver WDTPS */
#define XPAR_XWDTPS_NUM_INSTANCES                    2

/* Definitions for peripheral PSU_WDT_0 */
#define XPAR_PSU_WDT_0_DEVICE_ID                     0
#define XPAR_PSU_WDT_0_BASEADDR                      0xFF150000
#define XPAR_PSU_WDT_0_HIGHADDR                      0xFF15FFFF
#define XPAR_PSU_WDT_0_WDT_CLK_FREQ_HZ               99989998

/* Definitions for peripheral PSU_WDT_1 */
#define XPAR_PSU_WDT_1_DEVICE_ID                     1
#define XPAR_PSU_WDT_1_BASEADDR                      0xFD4D0000
#define XPAR_PSU_WDT_1_HIGHADDR                      0xFD4DFFFF
#define XPAR_PSU_WDT_1_WDT_CLK_FREQ_HZ               99989998

/******************************************************************/

/* Canonical definitions for peripheral PSU_WDT_0 */
#define XPAR_XWDTPS_0_DEVICE_ID                      XPAR_PSU_WDT_0_DEVICE_ID
#define XPAR_XWDTPS_0_BASEADDR                       0xFF150000
#define XPAR_XWDTPS_0_HIGHADDR                       0xFF15FFFF
#define XPAR_XWDTPS_0_WDT_CLK_FREQ_HZ                99989998

/* Canonical definitions for peripheral PSU_WDT_1 */
#define XPAR_XWDTPS_1_DEVICE_ID                      XPAR_PSU_WDT_1_DEVICE_ID
#define XPAR_XWDTPS_1_BASEADDR                       0xFD4D0000
#define XPAR_XWDTPS_1_HIGHADDR                       0xFD4DFFFF
#define XPAR_XWDTPS_1_WDT_CLK_FREQ_HZ                99989998

/******************************************************************/

/* Definitions for driver ZDMA */
#define XPAR_XZDMA_NUM_INSTANCES                     16

/* Definitions for peripheral PSU_ADMA_0 */
#define XPAR_PSU_ADMA_0_DEVICE_ID                    0
#define XPAR_PSU_ADMA_0_BASEADDR                     0xFFA80000
#define XPAR_PSU_ADMA_0_DMA_MODE                     1
#define XPAR_PSU_ADMA_0_HIGHADDR                     0xFFA8FFFF
#define XPAR_PSU_ADMA_0_ZDMA_CLK_FREQ_HZ             0

/* Definitions for peripheral PSU_ADMA_1 */
#define XPAR_PSU_ADMA_1_DEVICE_ID                    1
#define XPAR_PSU_ADMA_1_BASEADDR                     0xFFA90000
#define XPAR_PSU_ADMA_1_DMA_MODE                     1
#define XPAR_PSU_ADMA_1_HIGHADDR                     0xFFA9FFFF
#define XPAR_PSU_ADMA_1_ZDMA_CLK_FREQ_HZ             0

/* Definitions for peripheral PSU_ADMA_2 */
#define XPAR_PSU_ADMA_2_DEVICE_ID                    2
#define XPAR_PSU_ADMA_2_BASEADDR                     0xFFAA0000
#define XPAR_PSU_ADMA_2_DMA_MODE                     1
#define XPAR_PSU_ADMA_2_HIGHADDR                     0xFFAAFFFF
#define XPAR_PSU_ADMA_2_ZDMA_CLK_FREQ_HZ             0

/* Definitions for peripheral PSU_ADMA_3 */
#define XPAR_PSU_ADMA_3_DEVICE_ID                    3
#define XPAR_PSU_ADMA_3_BASEADDR                     0xFFAB0000
#define XPAR_PSU_ADMA_3_DMA_MODE                     1
#define XPAR_PSU_ADMA_3_HIGHADDR                     0xFFABFFFF
#define XPAR_PSU_ADMA_3_ZDMA_CLK_FREQ_HZ             0

/* Definitions for peripheral PSU_ADMA_4 */
#define XPAR_PSU_ADMA_4_DEVICE_ID                    4
#define XPAR_PSU_ADMA_4_BASEADDR                     0xFFAC0000
#define XPAR_PSU_ADMA_4_DMA_MODE                     1
#define XPAR_PSU_ADMA_4_HIGHADDR                     0xFFACFFFF
#define XPAR_PSU_ADMA_4_ZDMA_CLK_FREQ_HZ             0

/* Definitions for peripheral PSU_ADMA_5 */
#define XPAR_PSU_ADMA_5_DEVICE_ID                    5
#define XPAR_PSU_ADMA_5_BASEADDR                     0xFFAD0000
#define XPAR_PSU_ADMA_5_DMA_MODE                     1
#define XPAR_PSU_ADMA_5_HIGHADDR                     0xFFADFFFF
#define XPAR_PSU_ADMA_5_ZDMA_CLK_FREQ_HZ             0

/* Definitions for peripheral PSU_ADMA_6 */
#define XPAR_PSU_ADMA_6_DEVICE_ID                    6
#define XPAR_PSU_ADMA_6_BASEADDR                     0xFFAE0000
#define XPAR_PSU_ADMA_6_DMA_MODE                     1
#define XPAR_PSU_ADMA_6_HIGHADDR                     0xFFAEFFFF
#define XPAR_PSU_ADMA_6_ZDMA_CLK_FREQ_HZ             0

/* Definitions for peripheral PSU_ADMA_7 */
#define XPAR_PSU_ADMA_7_DEVICE_ID                    7
#define XPAR_PSU_ADMA_7_BASEADDR                     0xFFAF0000
#define XPAR_PSU_ADMA_7_DMA_MODE                     1
#define XPAR_PSU_ADMA_7_HIGHADDR                     0xFFAFFFFF
#define XPAR_PSU_ADMA_7_ZDMA_CLK_FREQ_HZ             0

/* Definitions for peripheral PSU_GDMA_0 */
#define XPAR_PSU_GDMA_0_DEVICE_ID                    8
#define XPAR_PSU_GDMA_0_BASEADDR                     0xFD500000
#define XPAR_PSU_GDMA_0_DMA_MODE                     0
#define XPAR_PSU_GDMA_0_HIGHADDR                     0xFD50FFFF
#define XPAR_PSU_GDMA_0_ZDMA_CLK_FREQ_HZ             0

/* Definitions for peripheral PSU_GDMA_1 */
#define XPAR_PSU_GDMA_1_DEVICE_ID                    9
#define XPAR_PSU_GDMA_1_BASEADDR                     0xFD510000
#define XPAR_PSU_GDMA_1_DMA_MODE                     0
#define XPAR_PSU_GDMA_1_HIGHADDR                     0xFD51FFFF
#define XPAR_PSU_GDMA_1_ZDMA_CLK_FREQ_HZ             0

/* Definitions for peripheral PSU_GDMA_2 */
#define XPAR_PSU_GDMA_2_DEVICE_ID                    10
#define XPAR_PSU_GDMA_2_BASEADDR                     0xFD520000
#define XPAR_PSU_GDMA_2_DMA_MODE                     0
#define XPAR_PSU_GDMA_2_HIGHADDR                     0xFD52FFFF
#define XPAR_PSU_GDMA_2_ZDMA_CLK_FREQ_HZ             0

/* Definitions for peripheral PSU_GDMA_3 */
#define XPAR_PSU_GDMA_3_DEVICE_ID                    11
#define XPAR_PSU_GDMA_3_BASEADDR                     0xFD530000
#define XPAR_PSU_GDMA_3_DMA_MODE                     0
#define XPAR_PSU_GDMA_3_HIGHADDR                     0xFD53FFFF
#define XPAR_PSU_GDMA_3_ZDMA_CLK_FREQ_HZ             0

/* Definitions for peripheral PSU_GDMA_4 */
#define XPAR_PSU_GDMA_4_DEVICE_ID                    12
#define XPAR_PSU_GDMA_4_BASEADDR                     0xFD540000
#define XPAR_PSU_GDMA_4_DMA_MODE                     0
#define XPAR_PSU_GDMA_4_HIGHADDR                     0xFD54FFFF
#define XPAR_PSU_GDMA_4_ZDMA_CLK_FREQ_HZ             0

/* Definitions for peripheral PSU_GDMA_5 */
#define XPAR_PSU_GDMA_5_DEVICE_ID                    13
#define XPAR_PSU_GDMA_5_BASEADDR                     0xFD550000
#define XPAR_PSU_GDMA_5_DMA_MODE                     0
#define XPAR_PSU_GDMA_5_HIGHADDR                     0xFD55FFFF
#define XPAR_PSU_GDMA_5_ZDMA_CLK_FREQ_HZ             0

/* Definitions for peripheral PSU_GDMA_6 */
#define XPAR_PSU_GDMA_6_DEVICE_ID                    14
#define XPAR_PSU_GDMA_6_BASEADDR                     0xFD560000
#define XPAR_PSU_GDMA_6_DMA_MODE                     0
#define XPAR_PSU_GDMA_6_HIGHADDR                     0xFD56FFFF
#define XPAR_PSU_GDMA_6_ZDMA_CLK_FREQ_HZ             0

/* Definitions for peripheral PSU_GDMA_7 */
#define XPAR_PSU_GDMA_7_DEVICE_ID                    15
#define XPAR_PSU_GDMA_7_BASEADDR                     0xFD570000
#define XPAR_PSU_GDMA_7_DMA_MODE                     0
#define XPAR_PSU_GDMA_7_HIGHADDR                     0xFD57FFFF
#define XPAR_PSU_GDMA_7_ZDMA_CLK_FREQ_HZ             0

/******************************************************************/

#define XPAR_PSU_ADMA_0_IS_CACHE_COHERENT            0
#define XPAR_PSU_ADMA_1_IS_CACHE_COHERENT            0
#define XPAR_PSU_ADMA_2_IS_CACHE_COHERENT            0
#define XPAR_PSU_ADMA_3_IS_CACHE_COHERENT            0
#define XPAR_PSU_ADMA_4_IS_CACHE_COHERENT            0
#define XPAR_PSU_ADMA_5_IS_CACHE_COHERENT            0
#define XPAR_PSU_ADMA_6_IS_CACHE_COHERENT            0
#define XPAR_PSU_ADMA_7_IS_CACHE_COHERENT            0
#define XPAR_PSU_GDMA_0_IS_CACHE_COHERENT            0
#define XPAR_PSU_GDMA_1_IS_CACHE_COHERENT            0
#define XPAR_PSU_GDMA_2_IS_CACHE_COHERENT            0
#define XPAR_PSU_GDMA_3_IS_CACHE_COHERENT            0
#define XPAR_PSU_GDMA_4_IS_CACHE_COHERENT            0
#define XPAR_PSU_GDMA_5_IS_CACHE_COHERENT            0
#define XPAR_PSU_GDMA_6_IS_CACHE_COHERENT            0
#define XPAR_PSU_GDMA_7_IS_CACHE_COHERENT            0
/* Canonical definitions for peripheral PSU_ADMA_0 */
#define XPAR_XZDMA_0_DEVICE_ID                       XPAR_PSU_ADMA_0_DEVICE_ID
#define XPAR_XZDMA_0_BASEADDR                        0xFFA80000
#define XPAR_XZDMA_0_DMA_MODE                        1
#define XPAR_XZDMA_0_HIGHADDR                        0xFFA8FFFF
#define XPAR_XZDMA_0_ZDMA_CLK_FREQ_HZ                0

/* Canonical definitions for peripheral PSU_ADMA_1 */
#define XPAR_XZDMA_1_DEVICE_ID                       XPAR_PSU_ADMA_1_DEVICE_ID
#define XPAR_XZDMA_1_BASEADDR                        0xFFA90000
#define XPAR_XZDMA_1_DMA_MODE                        1
#define XPAR_XZDMA_1_HIGHADDR                        0xFFA9FFFF
#define XPAR_XZDMA_1_ZDMA_CLK_FREQ_HZ                0

/* Canonical definitions for peripheral PSU_ADMA_2 */
#define XPAR_XZDMA_2_DEVICE_ID                       XPAR_PSU_ADMA_2_DEVICE_ID
#define XPAR_XZDMA_2_BASEADDR                        0xFFAA0000
#define XPAR_XZDMA_2_DMA_MODE                        1
#define XPAR_XZDMA_2_HIGHADDR                        0xFFAAFFFF
#define XPAR_XZDMA_2_ZDMA_CLK_FREQ_HZ                0

/* Canonical definitions for peripheral PSU_ADMA_3 */
#define XPAR_XZDMA_3_DEVICE_ID                       XPAR_PSU_ADMA_3_DEVICE_ID
#define XPAR_XZDMA_3_BASEADDR                        0xFFAB0000
#define XPAR_XZDMA_3_DMA_MODE                        1
#define XPAR_XZDMA_3_HIGHADDR                        0xFFABFFFF
#define XPAR_XZDMA_3_ZDMA_CLK_FREQ_HZ                0

/* Canonical definitions for peripheral PSU_ADMA_4 */
#define XPAR_XZDMA_4_DEVICE_ID                       XPAR_PSU_ADMA_4_DEVICE_ID
#define XPAR_XZDMA_4_BASEADDR                        0xFFAC0000
#define XPAR_XZDMA_4_DMA_MODE                        1
#define XPAR_XZDMA_4_HIGHADDR                        0xFFACFFFF
#define XPAR_XZDMA_4_ZDMA_CLK_FREQ_HZ                0

/* Canonical definitions for peripheral PSU_ADMA_5 */
#define XPAR_XZDMA_5_DEVICE_ID                       XPAR_PSU_ADMA_5_DEVICE_ID
#define XPAR_XZDMA_5_BASEADDR                        0xFFAD0000
#define XPAR_XZDMA_5_DMA_MODE                        1
#define XPAR_XZDMA_5_HIGHADDR                        0xFFADFFFF
#define XPAR_XZDMA_5_ZDMA_CLK_FREQ_HZ                0

/* Canonical definitions for peripheral PSU_ADMA_6 */
#define XPAR_XZDMA_6_DEVICE_ID                       XPAR_PSU_ADMA_6_DEVICE_ID
#define XPAR_XZDMA_6_BASEADDR                        0xFFAE0000
#define XPAR_XZDMA_6_DMA_MODE                        1
#define XPAR_XZDMA_6_HIGHADDR                        0xFFAEFFFF
#define XPAR_XZDMA_6_ZDMA_CLK_FREQ_HZ                0

/* Canonical definitions for peripheral PSU_ADMA_7 */
#define XPAR_XZDMA_7_DEVICE_ID                       XPAR_PSU_ADMA_7_DEVICE_ID
#define XPAR_XZDMA_7_BASEADDR                        0xFFAF0000
#define XPAR_XZDMA_7_DMA_MODE                        1
#define XPAR_XZDMA_7_HIGHADDR                        0xFFAFFFFF
#define XPAR_XZDMA_7_ZDMA_CLK_FREQ_HZ                0

/* Canonical definitions for peripheral PSU_GDMA_0 */
#define XPAR_XZDMA_8_DEVICE_ID                       XPAR_PSU_GDMA_0_DEVICE_ID
#define XPAR_XZDMA_8_BASEADDR                        0xFD500000
#define XPAR_XZDMA_8_DMA_MODE                        0
#define XPAR_XZDMA_8_HIGHADDR                        0xFD50FFFF
#define XPAR_XZDMA_8_ZDMA_CLK_FREQ_HZ                0

/* Canonical definitions for peripheral PSU_GDMA_1 */
#define XPAR_XZDMA_9_DEVICE_ID                       XPAR_PSU_GDMA_1_DEVICE_ID
#define XPAR_XZDMA_9_BASEADDR                        0xFD510000
#define XPAR_XZDMA_9_DMA_MODE                        0
#define XPAR_XZDMA_9_HIGHADDR                        0xFD51FFFF
#define XPAR_XZDMA_9_ZDMA_CLK_FREQ_HZ                0

/* Canonical definitions for peripheral PSU_GDMA_2 */
#define XPAR_XZDMA_10_DEVICE_ID                      XPAR_PSU_GDMA_2_DEVICE_ID
#define XPAR_XZDMA_10_BASEADDR                       0xFD520000
#define XPAR_XZDMA_10_DMA_MODE                       0
#define XPAR_XZDMA_10_HIGHADDR                       0xFD52FFFF
#define XPAR_XZDMA_10_ZDMA_CLK_FREQ_HZ               0

/* Canonical definitions for peripheral PSU_GDMA_3 */
#define XPAR_XZDMA_11_DEVICE_ID                      XPAR_PSU_GDMA_3_DEVICE_ID
#define XPAR_XZDMA_11_BASEADDR                       0xFD530000
#define XPAR_XZDMA_11_DMA_MODE                       0
#define XPAR_XZDMA_11_HIGHADDR                       0xFD53FFFF
#define XPAR_XZDMA_11_ZDMA_CLK_FREQ_HZ               0

/* Canonical definitions for peripheral PSU_GDMA_4 */
#define XPAR_XZDMA_12_DEVICE_ID                      XPAR_PSU_GDMA_4_DEVICE_ID
#define XPAR_XZDMA_12_BASEADDR                       0xFD540000
#define XPAR_XZDMA_12_DMA_MODE                       0
#define XPAR_XZDMA_12_HIGHADDR                       0xFD54FFFF
#define XPAR_XZDMA_12_ZDMA_CLK_FREQ_HZ               0

/* Canonical definitions for peripheral PSU_GDMA_5 */
#define XPAR_XZDMA_13_DEVICE_ID                      XPAR_PSU_GDMA_5_DEVICE_ID
#define XPAR_XZDMA_13_BASEADDR                       0xFD550000
#define XPAR_XZDMA_13_DMA_MODE                       0
#define XPAR_XZDMA_13_HIGHADDR                       0xFD55FFFF
#define XPAR_XZDMA_13_ZDMA_CLK_FREQ_HZ               0

/* Canonical definitions for peripheral PSU_GDMA_6 */
#define XPAR_XZDMA_14_DEVICE_ID                      XPAR_PSU_GDMA_6_DEVICE_ID
#define XPAR_XZDMA_14_BASEADDR                       0xFD560000
#define XPAR_XZDMA_14_DMA_MODE                       0
#define XPAR_XZDMA_14_HIGHADDR                       0xFD56FFFF
#define XPAR_XZDMA_14_ZDMA_CLK_FREQ_HZ               0

/* Canonical definitions for peripheral PSU_GDMA_7 */
#define XPAR_XZDMA_15_DEVICE_ID                      XPAR_PSU_GDMA_7_DEVICE_ID
#define XPAR_XZDMA_15_BASEADDR                       0xFD570000
#define XPAR_XZDMA_15_DMA_MODE                       0
#define XPAR_XZDMA_15_HIGHADDR                       0xFD57FFFF
#define XPAR_XZDMA_15_ZDMA_CLK_FREQ_HZ               0

/******************************************************************/

#endif /* end of protection macro */
