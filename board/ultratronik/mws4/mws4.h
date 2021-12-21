/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2008
 * Dirk Behme <dirk.behme@gmail.com>
 */
// mod for BfS ulbricht@innoroute.de 2021
#ifndef _BEAGLE_H_
#define _BEAGLE_H_

#include <asm/arch/dss.h>

const omap3_sysinfo sysinfo = {
	DDR_STACKED,
	"BfS MWS4",
#if defined(CONFIG_ENV_IS_IN_ONENAND)
	"OneNAND",
#else
	"NAND",
#endif
};

/* BeagleBoard revisions */
#define REVISION_AXBX	0x7
#define REVISION_CX	0x6
#define REVISION_C4	0x5
#define REVISION_XM_AB	0x0
#define REVISION_XM_C	0x2

/*
 * IEN  - Input Enable
 * IDIS - Input Disable
 * PTD  - Pull type Down
 * PTU  - Pull type Up
 * DIS  - Pull type selection is inactive
 * EN   - Pull type selection is active
 * M0   - Mode 0
 * The commented string gives the final mux configuration for that pin
 */
#define MUX_MWS4() \
 /*SDRC*/\
	MUX_VAL(CP(SDRC_D0),		(IEN  | PTD | DIS | M0)) /*SDRC_D0*/\
	MUX_VAL(CP(SDRC_D1),		(IEN  | PTD | DIS | M0)) /*SDRC_D1*/\
	MUX_VAL(CP(SDRC_D2),		(IEN  | PTD | DIS | M0)) /*SDRC_D2*/\
	MUX_VAL(CP(SDRC_D3),		(IEN  | PTD | DIS | M0)) /*SDRC_D3*/\
	MUX_VAL(CP(SDRC_D4),		(IEN  | PTD | DIS | M0)) /*SDRC_D4*/\
	MUX_VAL(CP(SDRC_D5),		(IEN  | PTD | DIS | M0)) /*SDRC_D5*/\
	MUX_VAL(CP(SDRC_D6),		(IEN  | PTD | DIS | M0)) /*SDRC_D6*/\
	MUX_VAL(CP(SDRC_D7),		(IEN  | PTD | DIS | M0)) /*SDRC_D7*/\
	MUX_VAL(CP(SDRC_D8),		(IEN  | PTD | DIS | M0)) /*SDRC_D8*/\
	MUX_VAL(CP(SDRC_D9),		(IEN  | PTD | DIS | M0)) /*SDRC_D9*/\
	MUX_VAL(CP(SDRC_D10),		(IEN  | PTD | DIS | M0)) /*SDRC_D10*/\
	MUX_VAL(CP(SDRC_D11),		(IEN  | PTD | DIS | M0)) /*SDRC_D11*/\
	MUX_VAL(CP(SDRC_D12),		(IEN  | PTD | DIS | M0)) /*SDRC_D12*/\
	MUX_VAL(CP(SDRC_D13),		(IEN  | PTD | DIS | M0)) /*SDRC_D13*/\
	MUX_VAL(CP(SDRC_D14),		(IEN  | PTD | DIS | M0)) /*SDRC_D14*/\
	MUX_VAL(CP(SDRC_D15),		(IEN  | PTD | DIS | M0)) /*SDRC_D15*/\
	MUX_VAL(CP(SDRC_D16),		(IEN  | PTD | DIS | M0)) /*SDRC_D16*/\
	MUX_VAL(CP(SDRC_D17),		(IEN  | PTD | DIS | M0)) /*SDRC_D17*/\
	MUX_VAL(CP(SDRC_D18),		(IEN  | PTD | DIS | M0)) /*SDRC_D18*/\
	MUX_VAL(CP(SDRC_D19),		(IEN  | PTD | DIS | M0)) /*SDRC_D19*/\
	MUX_VAL(CP(SDRC_D20),		(IEN  | PTD | DIS | M0)) /*SDRC_D20*/\
	MUX_VAL(CP(SDRC_D21),		(IEN  | PTD | DIS | M0)) /*SDRC_D21*/\
	MUX_VAL(CP(SDRC_D22),		(IEN  | PTD | DIS | M0)) /*SDRC_D22*/\
	MUX_VAL(CP(SDRC_D23),		(IEN  | PTD | DIS | M0)) /*SDRC_D23*/\
	MUX_VAL(CP(SDRC_D24),		(IEN  | PTD | DIS | M0)) /*SDRC_D24*/\
	MUX_VAL(CP(SDRC_D25),		(IEN  | PTD | DIS | M0)) /*SDRC_D25*/\
	MUX_VAL(CP(SDRC_D26),		(IEN  | PTD | DIS | M0)) /*SDRC_D26*/\
	MUX_VAL(CP(SDRC_D27),		(IEN  | PTD | DIS | M0)) /*SDRC_D27*/\
	MUX_VAL(CP(SDRC_D28),		(IEN  | PTD | DIS | M0)) /*SDRC_D28*/\
	MUX_VAL(CP(SDRC_D29),		(IEN  | PTD | DIS | M0)) /*SDRC_D29*/\
	MUX_VAL(CP(SDRC_D30),		(IEN  | PTD | DIS | M0)) /*SDRC_D30*/\
	MUX_VAL(CP(SDRC_D31),		(IEN  | PTD | DIS | M0)) /*SDRC_D31*/\
	MUX_VAL(CP(SDRC_CLK),		(IEN  | PTD | DIS | M0)) /*SDRC_CLK*/\
	MUX_VAL(CP(SDRC_DQS0),		(IEN  | PTD | DIS | M0)) /*SDRC_DQS0*/\
	MUX_VAL(CP(SDRC_DQS1),		(IEN  | PTD | DIS | M0)) /*SDRC_DQS1*/\
	MUX_VAL(CP(SDRC_DQS2),		(IEN  | PTD | DIS | M0)) /*SDRC_DQS2*/\
	MUX_VAL(CP(SDRC_DQS3),		(IEN  | PTD | DIS | M0)) /*SDRC_DQS3*/\
 /*GPMC*/\
	MUX_VAL(CP(GPMC_A1),		(IDIS | PTD | DIS | M0)) /*GPMC_A1*/\
	MUX_VAL(CP(GPMC_A2),		(IDIS | PTD | DIS | M0)) /*GPMC_A2*/\
	MUX_VAL(CP(GPMC_A3),		(IDIS | PTD | DIS | M0)) /*GPMC_A3*/\
	MUX_VAL(CP(GPMC_A4),		(IDIS | PTD | DIS | M0)) /*GPMC_A4*/\
	MUX_VAL(CP(GPMC_A5),		(IDIS | PTD | DIS | M0)) /*GPMC_A5*/\
	MUX_VAL(CP(GPMC_A6),		(IDIS | PTD | DIS | M0)) /*GPMC_A6*/\
	MUX_VAL(CP(GPMC_A7),		(IDIS | PTD | DIS | M0)) /*GPMC_A7*/\
	MUX_VAL(CP(GPMC_A8),		(IDIS | PTD | DIS | M0)) /*GPMC_A8*/\
	MUX_VAL(CP(GPMC_A9),		(IDIS | PTD | DIS | M0)) /*GPMC_A9*/\
	MUX_VAL(CP(GPMC_A10),		(IDIS | PTD | DIS | M0)) /*GPMC_A10*/\
	MUX_VAL(CP(GPMC_D0),		(IEN  | PTD | DIS | M0)) /*GPMC_D0*/\
	MUX_VAL(CP(GPMC_D1),		(IEN  | PTD | DIS | M0)) /*GPMC_D1*/\
	MUX_VAL(CP(GPMC_D2),		(IEN  | PTD | DIS | M0)) /*GPMC_D2*/\
	MUX_VAL(CP(GPMC_D3),		(IEN  | PTD | DIS | M0)) /*GPMC_D3*/\
	MUX_VAL(CP(GPMC_D4),		(IEN  | PTD | DIS | M0)) /*GPMC_D4*/\
	MUX_VAL(CP(GPMC_D5),		(IEN  | PTD | DIS | M0)) /*GPMC_D5*/\
	MUX_VAL(CP(GPMC_D6),		(IEN  | PTD | DIS | M0)) /*GPMC_D6*/\
	MUX_VAL(CP(GPMC_D7),		(IEN  | PTD | DIS | M0)) /*GPMC_D7*/\
	MUX_VAL(CP(GPMC_D8),		(IEN  | PTD | DIS | M0)) /*GPMC_D8*/\
	MUX_VAL(CP(GPMC_D9),		(IEN  | PTD | DIS | M0)) /*GPMC_D9*/\
	MUX_VAL(CP(GPMC_D10),		(IEN  | PTD | DIS | M0)) /*GPMC_D10*/\
	MUX_VAL(CP(GPMC_D11),		(IEN  | PTD | DIS | M0)) /*GPMC_D11*/\
	MUX_VAL(CP(GPMC_D12),		(IEN  | PTD | DIS | M0)) /*GPMC_D12*/\
	MUX_VAL(CP(GPMC_D13),		(IEN  | PTD | DIS | M0)) /*GPMC_D13*/\
	MUX_VAL(CP(GPMC_D14),		(IEN  | PTD | DIS | M0)) /*GPMC_D14*/\
	MUX_VAL(CP(GPMC_D15),		(IEN  | PTD | DIS | M0)) /*GPMC_D15*/\
	MUX_VAL(CP(GPMC_NCS0),		(IDIS | PTU | EN  | M0)) /*GPMC_nCS0*/\
	MUX_VAL(CP(GPMC_NCS1),		(IDIS | PTU | EN  | M0)) /*GPMC_nCS1*/\
	MUX_VAL(CP(GPMC_NCS2),		(IDIS | PTU | EN  | M0)) /*GPMC_nCS2*/\
	MUX_VAL(CP(GPMC_NCS3),		(IDIS | PTU | EN  | M0)) /*GPMC_nCS3*/\
	MUX_VAL(CP(GPMC_NCS4),		(IDIS | PTU | EN  | M0)) /*GPMC_nCS4*/\
	MUX_VAL(CP(GPMC_NCS5),		(IDIS | PTD | DIS | M0)) /*GPMC_nCS5*/\
	MUX_VAL(CP(GPMC_NCS6),		(IEN  | PTD | DIS | M1)) /*SYS_nDMA_REQ2*/\
	MUX_VAL(CP(GPMC_NCS7),		(IEN  | PTU | EN  | M1)) /*SYS_nDMA_REQ3*/\
	MUX_VAL(CP(GPMC_NBE1),		(IEN  | PTD | DIS | M0)) /*GPMC_nBE1*/\
	MUX_VAL(CP(GPMC_WAIT2),		(IEN  | PTU | EN  | M0)) /*GPMC_WAIT2*/\
	MUX_VAL(CP(GPMC_WAIT3),		(IEN  | PTU | EN  | M0)) /*GPMC_WAIT3*/\
	MUX_VAL(CP(GPMC_CLK),		(IEN | PTD | DIS | M4)) /*GPMC_CLK*/\
	MUX_VAL(CP(GPMC_NADV_ALE),	(IDIS | PTD | DIS | M0)) /*GPMC_nADV_ALE*/\
	MUX_VAL(CP(GPMC_NOE),		(IDIS | PTD | DIS | M0)) /*GPMC_nOE*/\
	MUX_VAL(CP(GPMC_NWE),		(IDIS | PTD | DIS | M0)) /*GPMC_nWE*/\
	MUX_VAL(CP(GPMC_NBE0_CLE),	(IDIS | PTD | DIS | M0)) /*GPMC_nBE0_CLE*/\
	MUX_VAL(CP(GPMC_NWP),		(IEN  | PTD | DIS | M0)) /*GPMC_nWP*/\
	MUX_VAL(CP(GPMC_WAIT0),		(IEN  | PTU | EN  | M0)) /*GPMC_WAIT0*/\
	MUX_VAL(CP(GPMC_WAIT1),		(IEN  | PTU | EN  | M0)) /*GPMC_WAIT1*/\
 /*CAMERA*/\
	MUX_VAL(CP(CAM_HS),		(IEN | PTU | EN | M4)) /*CAM_HS HW0*/\
	MUX_VAL(CP(CAM_VS),		(IEN | PTU | EN | M4)) /*CAM_VS HW1*/\
	MUX_VAL(CP(CAM_XCLKA),		(IEN | PTU | EN | M4)) /*CAM_XCLKA HW2*/\
	MUX_VAL(CP(CAM_D0),		(IEN  | PTD | DIS | M4)) /*CAM_D0 DIN1*/\
	MUX_VAL(CP(CAM_D1),		(IEN  | PTD | DIS | M4)) /*CAM_D1 DIN2*/\
	MUX_VAL(CP(CAM_D2),		(IDIS  | PTD | DIS | M4)) /*CAM_D2, led_sm*/\
	MUX_VAL(CP(CAM_D3),		(IDIS  | PTD | DIS | M4)) /*CAM_D3, led1*/\
	MUX_VAL(CP(CAM_D4),		(IDIS  | PTD | DIS | M4)) /*CAM_D4, led2*/\
	MUX_VAL(CP(CAM_D5),		(IDIS  | PTD | DIS | M4)) /*CAM_D5, led3*/\
	MUX_VAL(CP(CAM_D6),		(IEN  | PTD | DIS | M4)) /*CAM_D6 sw_sm*/\
	MUX_VAL(CP(CAM_D7),		(IEN  | PTD | DIS | M4)) /*CAM_D7 DIN3*/\
	MUX_VAL(CP(CAM_D8),		(IEN  | PTD | DIS | M4)) /*CAM_D8 DIN4*/\
	MUX_VAL(CP(CAM_D9),		(IEN  | PTD | DIS | M4)) /*CAM_D9 DIN5*/\
	MUX_VAL(CP(CAM_D11),		(IDIS  | PTD | DIS | M4)) /*CAM_D11,usb2en*/\
 /*Audio Interface */\
	MUX_VAL(CP(MCBSP2_CLKX),	(IDIS  | PTD | DIS | M4)) /*McBSP2_CLKX wd_trigger*/\
 /*Expansion card */\
	MUX_VAL(CP(MMC1_CLK),		(IDIS | PTU | EN  | M0)) /*MMC1_CLK*/\
	MUX_VAL(CP(MMC1_CMD),		(IEN  | PTU | EN  | M0)) /*MMC1_CMD*/\
	MUX_VAL(CP(MMC1_DAT0),		(IEN  | PTU | EN  | M0)) /*MMC1_DAT0*/\
	MUX_VAL(CP(MMC1_DAT1),		(IEN  | PTU | EN  | M0)) /*MMC1_DAT1*/\
	MUX_VAL(CP(MMC1_DAT2),		(IEN  | PTU | EN  | M0)) /*MMC1_DAT2*/\
	MUX_VAL(CP(MMC1_DAT3),		(IEN  | PTU | EN  | M0)) /*MMC1_DAT3*/\
 /*Wireless LAN */\
	MUX_VAL(CP(MMC2_CLK),		(IEN  | PTU | DIS  | M4)) /*GPIO_130 eth_irq*/\
 /*Modem Interface */\
	MUX_VAL(CP(UART1_TX),		(IDIS | PTD | DIS | M0)) /*UART1_TX*/\
	MUX_VAL(CP(UART1_RTS),		(IDIS | PTD | DIS | M0)) /*GPIO_149*/ \
	MUX_VAL(CP(UART1_RX),		(IEN  | PTD | DIS | M0)) /*UART1_RX*/\
	MUX_VAL(CP(MCBSP4_CLKX),	(IDIS | PTD | DIS | M0)) /*SSI1_DAT_RX*/\
	MUX_VAL(CP(MCBSP1_CLKR),	(IEN | PTD | DIS | M0)) /*GPIO_156*/\
	MUX_VAL(CP(MCBSP1_FSR),		(IDIS | PTU | DIS  | M4)) /*GPIO_157 GPO1*/\
	MUX_VAL(CP(MCBSP1_DX),		(IDIS | PTD | DIS | M4)) /*GPIO_158 GPO2*/\
	MUX_VAL(CP(MCBSP1_DR),		(IDIS | PTD | DIS | M4)) /*GPIO_159 GPO3*/\
	MUX_VAL(CP(MCBSP_CLKS),		(IDIS | PTD | DIS | M4)) /*McBSP_CLKS GPO4*/\
	MUX_VAL(CP(MCBSP1_FSX),		(IDIS | PTD | DIS | M4)) /*GPIO_161 GPO5*/\
	MUX_VAL(CP(MCBSP1_CLKX),	(IDIS | PTD | DIS | M4)) /*GPIO_162 GPO6*/\
 /*Serial Interface*/\
/*	MUX_VAL(CP(UART3_CTS_RCTX),	(IDIS | PTD | DIS | M4)) *//*UART3_CTS_RCTX IIC_RES_18*/\
	MUX_VAL(CP(UART3_RX_IRRX),	(IEN  | PTD | DIS | M0)) /*UART3_RX_IRRX*/\
	MUX_VAL(CP(UART3_TX_IRTX),	(IDIS | PTD | DIS | M0)) /*UART3_TX_IRTX*/\
	MUX_VAL(CP(HSUSB0_CLK),		(IEN  | PTD | DIS | M0)) /*HSUSB0_CLK*/\
	MUX_VAL(CP(HSUSB0_STP),		(IDIS | PTU | EN  | M0)) /*HSUSB0_STP*/\
	MUX_VAL(CP(HSUSB0_DIR),		(IEN  | PTD | DIS | M0)) /*HSUSB0_DIR*/\
	MUX_VAL(CP(HSUSB0_NXT),		(IEN  | PTD | DIS | M0)) /*HSUSB0_NXT*/\
	MUX_VAL(CP(HSUSB0_DATA0),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DATA0*/\
	MUX_VAL(CP(HSUSB0_DATA1),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DATA1*/\
	MUX_VAL(CP(HSUSB0_DATA2),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DATA2*/\
	MUX_VAL(CP(HSUSB0_DATA3),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DATA3*/\
	MUX_VAL(CP(HSUSB0_DATA4),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DATA4*/\
	MUX_VAL(CP(HSUSB0_DATA5),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DATA5*/\
	MUX_VAL(CP(HSUSB0_DATA6),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DATA6*/\
	MUX_VAL(CP(HSUSB0_DATA7),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DATA7*/\
	MUX_VAL(CP(I2C1_SCL),		(IEN  | PTU | DIS  | M0)) /*I2C1_SCL*/\
	MUX_VAL(CP(I2C1_SDA),		(IEN  | PTU | DIS  | M0)) /*I2C1_SDA*/\
	MUX_VAL(CP(I2C2_SCL),		(IEN  | PTU | DIS  | M0)) /*I2C2_SCL*/\
	MUX_VAL(CP(I2C2_SDA),		(IEN  | PTU | DIS  | M0)) /*I2C2_SDA*/\
	MUX_VAL(CP(I2C3_SCL),		(IEN  | PTU | DIS  | M0)) /*I2C3_SCL*/\
	MUX_VAL(CP(I2C3_SDA),		(IEN  | PTU | DIS  | M0)) /*I2C3_SDA*/\
	MUX_VAL(CP(I2C4_SCL),		(IEN  | PTU | DIS  | M0)) /*I2C4_SCL*/\
	MUX_VAL(CP(I2C4_SDA),		(IEN  | PTU | DIS  | M0)) /*I2C4_SDA*/\
 /*Control and debug */\
	MUX_VAL(CP(SYS_32K),		(IEN  | PTD | DIS | M0)) /*SYS_32K*/\
	MUX_VAL(CP(SYS_BOOT0),		(IEN  | PTD | DIS | M0)) /*GPIO_2*/\
	MUX_VAL(CP(SYS_BOOT1),		(IEN  | PTD | DIS | M0)) /*GPIO_3*/\
	MUX_VAL(CP(SYS_BOOT2),		(IEN  | PTD | DIS | M0)) /*GPIO_4*/\
	MUX_VAL(CP(SYS_BOOT3),		(IEN  | PTD | DIS | M0)) /*GPIO_5*/\
	MUX_VAL(CP(SYS_BOOT4),		(IEN  | PTD | DIS | M0)) /*GPIO_6*/\
	MUX_VAL(CP(SYS_BOOT5),		(IEN  | PTD | DIS | M0)) /*GPIO_7*/\
	MUX_VAL(CP(SYS_BOOT6),		(IDIS | PTD | DIS | M0)) /*GPIO_8*/ \
	MUX_VAL(CP(SYS_OFF_MODE),	(IDIS  | PTD | DIS | M0)) /*SYS_OFF_MODE*/\
	MUX_VAL(CP(SDRC_CKE0),		(IDIS | PTU | EN  | M0)) /*sdrc_cke0*/\
	MUX_VAL(CP(SDRC_CKE1),		(IDIS | PTU | EN  | M0)) /*sdrc_cke1*/


#endif



