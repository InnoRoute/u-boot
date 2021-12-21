/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2006-2008
 * Texas Instruments.
 * Richard Woodruff <r-woodruff2@ti.com>
 * Syed Mohammed Khasim <x0khasim@ti.com>
 *
 * Configuration settings for the TI OMAP3530 Beagle board.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <configs/ti_omap3_common.h>

/*
 * We are only ever GP parts and will utilize all of the "downloaded image"
 * area in SRAM which starts at 0x40200000 and ends at 0x4020FFFF (64KB).
 */

#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_REVISION_TAG

/* NAND */
#if defined(CONFIG_MTD_RAW_NAND)
#define CONFIG_SYS_FLASH_BASE		NAND_BASE
#define CONFIG_SYS_MAX_NAND_DEVICE      1
#define CONFIG_SYS_NAND_5_ADDR_CYCLE
#define CONFIG_SYS_NAND_PAGE_COUNT      64
#define CONFIG_SYS_NAND_PAGE_SIZE       2048
#define CONFIG_SYS_NAND_OOBSIZE         64
#define CONFIG_SYS_NAND_BLOCK_SIZE      (128*1024)
#define CONFIG_SYS_NAND_BAD_BLOCK_POS   NAND_LARGE_BADBLOCK_POS
#define CONFIG_SYS_NAND_ECCPOS          {2, 3, 4, 5, 6, 7, 8, 9,\
                                         10, 11, 12, 13}
#define CONFIG_SYS_NAND_ECCSIZE         512
#define CONFIG_SYS_NAND_ECCBYTES        3
#define CONFIG_NAND_OMAP_ECCSCHEME      OMAP_ECC_HAM1_CODE_HW
//#define CONFIG_SYS_NAND_U_BOOT_OFFS     0x80000
#define CONFIG_SYS_ENV_SECT_SIZE        SZ_128K
/* NAND: SPL falcon mode configs */
#if defined(CONFIG_SPL_OS_BOOT)
#define CONFIG_SYS_NAND_SPL_KERNEL_OFFS 0x2a0000
#endif /* CONFIG_SPL_OS_BOOT */
#endif /* CONFIG_MTD_RAW_NAND */

/* USB EHCI */
//#define CONFIG_OMAP_EHCI_PHY1_RESET_GPIO	147

/* Enable Multi Bus support for I2C */
#define CONFIG_I2C_MULTI_BUS

/* DSS Support */

/* TWL4030 LED Support */

#define MEM_LAYOUT_ENV_SETTINGS \
	DEFAULT_LINUX_BOOT_ENV

#define BOOTENV_DEV_LEGACY_MMC(devtypeu, devtypel, instance) \
	"bootcmd_" #devtypel #instance "=" \
	"setenv mmcdev " #instance "; " \
	"run mmcboot\0"
#define BOOTENV_DEV_NAME_LEGACY_MMC(devtypeu, devtypel, instance) \
	#devtypel #instance " "

#if defined(CONFIG_MTD_RAW_NAND)

#define BOOTENV_DEV_NAND(devtypeu, devtypel, instance) \
	"bootcmd_" #devtypel #instance "=" \
	"if test ${mtdids} = '' || test ${mtdparts} = '' ; then " \
		"echo NAND boot disabled: No mtdids and/or mtdparts; " \
	"else " \
		"run nandboot; " \
	"fi\0"
#define BOOTENV_DEV_NAME_NAND(devtypeu, devtypel, instance) \
	#devtypel #instance " "

#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 0) \
	func(LEGACY_MMC, legacy_mmc, 0) \
	func(UBIFS, ubifs, 0) \
	func(NAND, nand, 0)

#else /* !CONFIG_MTD_RAW_NAND */

#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 0) \
	func(LEGACY_MMC, legacy_mmc, 0)

#endif /* CONFIG_MTD_RAW_NAND */

#include <config_distro_bootcmd.h>

#define CONFIG_EXTRA_ENV_SETTINGS \
	MEM_LAYOUT_ENV_SETTINGS \
	"console=ttyO2,115200n8\0" \
	BOOTENV
#endif /* __CONFIG_H */
