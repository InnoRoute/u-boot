// SPDX-License-Identifier: GPL-2.0+
/*
 * (C) Copyright 2004-2011
 * Texas Instruments, <www.ti.com>
 *
 * Author :
 *	Sunil Kumar <sunilsaini05@gmail.com>
 *	Shashi Ranjan <shashiranjanmca05@gmail.com>
 *
 * Derived from Beagle Board and 3430 SDP code by
 *	Richard Woodruff <r-woodruff2@ti.com>
 *	Syed Mohammed Khasim <khasim@ti.com>
 *
 */
// mod for BfS ulbricht@innoroute.de 2021
#include <common.h>
#include <bootstage.h>
#include <dm.h>
#include <env.h>
#include <init.h>
#include <net.h>
#include <ns16550.h>
#include <serial.h>
#include <twl4030.h>
#include <linux/mtd/rawnand.h>
#include <asm/io.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/mux.h>
#include <asm/arch/mem.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-types.h>
#include <asm/omap_musb.h>
#include <linux/errno.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <linux/usb/musb.h>
#include "mws4.h"
#include <command.h>
#include <usb.h>
#include <asm/ehci-omap.h>

#define TWL4030_I2C_BUS			0
#define EXPANSION_EEPROM_I2C_BUS	1
#define EXPANSION_EEPROM_I2C_ADDRESS	0x50

#define TINCANTOOLS_ZIPPY		0x01000100
#define TINCANTOOLS_ZIPPY2		0x02000100
#define TINCANTOOLS_TRAINER		0x04000100
#define TINCANTOOLS_SHOWDOG		0x03000100
#define KBADC_BEAGLEFPGA		0x01000600
#define LW_BEAGLETOUCH			0x01000700
#define BRAINMUX_LCDOG			0x01000800
#define BRAINMUX_LCDOGTOUCH		0x02000800
#define BBTOYS_WIFI			0x01000B00
#define BBTOYS_VGA			0x02000B00
#define BBTOYS_LCD			0x03000B00
#define BCT_BRETTL3			0x01000F00
#define BCT_BRETTL4			0x02000F00
#define LSR_COM6L_ADPT			0x01001300
#define BEAGLE_NO_EEPROM		0xffffffff

DECLARE_GLOBAL_DATA_PTR;

static struct {
	unsigned int device_vendor;
	unsigned char revision;
	unsigned char content;
	char fab_revision[8];
	char env_var[16];
	char env_setting[64];
} expansion_config;


#if  !defined(CONFIG_SPL_BUILD)
/* Call usb_stop() before starting the kernel */
void show_boot_progress(int val)
{
        if (val == BOOTSTAGE_ID_RUN_OS)
                usb_stop();
}

static struct omap_usbhs_board_data usbhs_bdata = {
        .port_mode[0] = OMAP_EHCI_PORT_MODE_PHY
};

int ehci_hcd_init(int index, struct ehci_hccr **hccr, struct ehci_hcor **hcor)
{
        return omap_ehci_hcd_init(&usbhs_bdata, hccr, hcor);
}

int ehci_hcd_stop(int index)
{
        return omap_ehci_hcd_stop();
}
#endif
/*
 * Routine: board_init
 * Description: Early hardware init.
 */
int board_init(void)
{
	gpmc_init(); /* in SRAM or SDRAM, finish GPMC */
	/* board id for Linux */
	gd->bd->bi_arch_number = 5109;
	/* boot param addr */
	gd->bd->bi_boot_params = (OMAP34XX_SDRC_CS0 + 0x100);

printf("Support InnoRoute.de\n");

	twl4030_power_init();
	twl4030_i2c_write_u8(TWL4030_CHIP_PM_MASTER,
			     TWL4030_PM_MASTER_PROTECT_KEY, 0xC0);
	twl4030_i2c_write_u8(TWL4030_CHIP_PM_MASTER,
			     TWL4030_PM_MASTER_PROTECT_KEY, 0x0C);
		twl4030_i2c_write_u8(TWL4030_CHIP_PM_MASTER,
			     TWL4030_PM_MASTER_CFG_BOOT, 0x19);	
		twl4030_i2c_write_u8(TWL4030_CHIP_PM_MASTER,
			     TWL4030_PM_MASTER_PROTECT_KEY, 0x00);	
	return 0;
}

#if defined(CONFIG_SPL_OS_BOOT)
int spl_start_uboot(void)
{
	/* break into full u-boot on 'c' */
	if (serial_tstc() && serial_getc() == 'c')
		return 1;

	return 0;
}
#endif /* CONFIG_SPL_OS_BOOT */

/*
 * Routine: get_board_revision
 * Description: Detect if we are running on a Beagle revision Ax/Bx,
 *		C1/2/3, C4, xM Ax/Bx or xM Cx. This can be done by reading
 *		the level of GPIO173, GPIO172 and GPIO171. This should
 *		result in
 *		GPIO173, GPIO172, GPIO171: 1 1 1 => Ax/Bx
 *		GPIO173, GPIO172, GPIO171: 1 1 0 => C1/2/3
 *		GPIO173, GPIO172, GPIO171: 1 0 1 => C4
 *		GPIO173, GPIO172, GPIO171: 0 1 0 => xM Cx
 *		GPIO173, GPIO172, GPIO171: 0 0 0 => xM Ax/Bx
 */
static int get_board_revision(void)
{
	static int revision = 7;

/*	if (revision == -1) {*/
/*		if (!gpio_request(171, "rev0") &&*/
/*		    !gpio_request(172, "rev1") &&*/
/*		    !gpio_request(173, "rev2")) {*/
/*			gpio_direction_input(171);*/
/*			gpio_direction_input(172);*/
/*			gpio_direction_input(173);*/

/*			revision = gpio_get_value(173) << 2 |*/
/*				gpio_get_value(172) << 1 |*/
/*				gpio_get_value(171);*/
/*		} else {*/
/*			printf("Error: unable to acquire board revision GPIOs\n");*/
/*		}*/
/*	}*/

	return revision;
}

#ifdef CONFIG_SPL_BUILD
/*
 * Routine: get_board_mem_timings
 * Description: If we use SPL then there is no x-loader nor config header
 * so we have to setup the DDR timings ourself on the first bank.  This
 * provides the timing values back to the function that configures
 * the memory.
 */
void get_board_mem_timings(struct board_sdrc_timings *timings)
{
	int pop_mfr, pop_id;
	
	/* 256MB DDR */
	timings->mcfg = HYNIX_V_MCFG_200(256 << 20);
	timings->ctrla = HYNIX_V_ACTIMA_200;
	timings->ctrlb = HYNIX_V_ACTIMB_200;
	timings->rfr_ctrl = SDP_3430_SDRC_RFR_CTRL_200MHz;
	timings->mr = MICRON_V_MR_165;
}
#endif





/*
 * Routine: misc_init_r
 * Description: Configure board specific parts
 */
int misc_init_r(void)
{
	struct gpio *gpio5_base = (struct gpio *)OMAP34XX_GPIO5_BASE;
	struct gpio *gpio6_base = (struct gpio *)OMAP34XX_GPIO6_BASE;
	struct control_prog_io *prog_io_base = (struct control_prog_io *)OMAP34XX_CTRL_BASE;
	bool generate_fake_mac = false;
	u32 value;

	/* Enable i2c2 pullup resisters */
	value = readl(&prog_io_base->io1);
	value &= ~(PRG_I2C2_PULLUPRESX);
	writel(value, &prog_io_base->io1);
env_set("beaglerev", "AxBx");



env_set("buddy", "none");

	     		     

	/* Set GPIO states before they are made outputs */
/*	writel(GPIO23 | GPIO10 | GPIO8 | GPIO2 | GPIO1,*/
/*		&gpio6_base->setdataout);*/
/*	writel(GPIO31 | GPIO30 | GPIO29 | GPIO28 | GPIO22 | GPIO21 |*/
/*		GPIO15 | GPIO14 | GPIO13 | GPIO12, &gpio5_base->setdataout);*/

/*	 //Configure GPIOs to output */
/*	writel(~(GPIO23 | GPIO10 | GPIO8 | GPIO2 | GPIO1), &gpio6_base->oe);*/
/*	writel(~(GPIO31 | GPIO30 | GPIO29 | GPIO28 | GPIO22 | GPIO21 |*/
/*		GPIO15 | GPIO14 | GPIO13 | GPIO12), &gpio5_base->oe);*/

	omap_die_id_display();
/* Set VAUX2 to 1.8V for EHCI PHY */
	twl4030_pmrecv_vsel_cfg(TWL4030_PM_RECEIVER_VAUX2_DEDICATED,
					TWL4030_PM_RECEIVER_VAUX2_VSEL_18,
					TWL4030_PM_RECEIVER_VAUX2_DEV_GRP,
					TWL4030_PM_RECEIVER_DEV_GRP_P1);

	//dieid_num_r();
/*#ifdef CONFIG_VIDEO_OMAP3*/
/*	beagle_dvi_pup();*/
/*	beagle_display_init();*/
/*	omap3_dss_enable();*/
/*#endif*/

/*	if (generate_fake_mac)*/
/*		omap_die_id_usbethaddr();*/

/*#if defined(CONFIG_MTDIDS_DEFAULT) && defined(CONFIG_MTDPARTS_DEFAULT)*/
/*	if (strlen(CONFIG_MTDIDS_DEFAULT))*/
/*		env_set("mtdids", CONFIG_MTDIDS_DEFAULT);*/

/*	if (strlen(CONFIG_MTDPARTS_DEFAULT))*/
/*		env_set("mtdparts", CONFIG_MTDPARTS_DEFAULT);*/
/*#endif*/

	return 0;
}

/*
 * Routine: set_muxconf_regs
 * Description: Setting up the configuration Mux registers specific to the
 *		hardware. Many pins need to be moved from protect to primary
 *		mode.
 */
void set_muxconf_regs(void)
{
	MUX_MWS4();
}

#if defined(CONFIG_MMC)
int board_mmc_init(struct bd_info *bis)
{
	return omap_mmc_init(0, 0, 0, -1, -1);
}
#endif

#if defined(CONFIG_MMC)
void board_mmc_power_init(void)
{
	twl4030_power_mmc_init(0);
}
#endif
