/*
 * SPDX-License-Identifier: GPL-2.0+
 */
/*
 * This file contains the configuration parameters for the AP135 board.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*-----------------------------------------------------------------------
 * Atheros Source Code Configuration
 */
/* see see lsdk-10.0.91/boot/u-boot/include/configs/board955x.h */
#define CFG_PLL_FREQ             CFG_PLL_720_600_200
#include <atheros.h>

#define CFG_FLASH_SECTOR_SIZE	(64*1024)
#if (FLASH_SIZE == 16)
#define CFG_FLASH_SIZE		0x01000000	/* Total flash size */
#elif (FLASH_SIZE == 8)
#define CFG_FLASH_SIZE		0x00800000	/* max number of sectors on one chip */
#else
#define CFG_FLASH_SIZE		0x00400000	/* Total flash size */
#endif

/*-----------------------------------------------------------------------
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_MONITOR_LEN		CFG_LOADER_PART_SIZE
#define CONFIG_SYS_TEXT_BASE            0x9f000000
#define CONFIG_SYS_MALLOC_LEN           256*1024
#define CONFIG_SYS_BOOTPARAMS_LEN       128*1024

#define FLASH_SIZE               16

#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO
#define CONFIG_BOARD_EARLY_INIT_F

#define CONFIG_SYS_HZ                   1000
#define CONFIG_SYS_MHZ                  325
#define CONFIG_SYS_MIPS_TIMER_FREQ      (CONFIG_SYS_MHZ * 1000000)

/* Cache Configuration */
#define CONFIG_SYS_DCACHE_SIZE          32768
#define CONFIG_SYS_ICACHE_SIZE          65536
#define CONFIG_SYS_CACHELINE_SIZE       32

#define CONFIG_SYS_MONITOR_BASE         CONFIG_SYS_TEXT_BASE



#define CONFIG_SYS_SDRAM_BASE           0x80000000
#define CONFIG_SYS_LOAD_ADDR            0x81000000

#define CONFIG_SYS_NO_FLASH					1

#define CONFIG_SYS_INIT_RAM_ADDR        0xbd000000
#define CONFIG_SYS_INIT_RAM_SIZE        0x2000
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_RAM_SIZE - 1)

/*
 * Serial Port
 */
#define CONFIG_DEBUG_UART_BASE 			0x18020000
#define CONFIG_BAUDRATE                 115200
#define CONFIG_SYS_BAUDRATE_TABLE \
	{9600, 19200, 38400, 57600, 115200}

#define CONFIG_BOOTDELAY                3
#define CONFIG_BOOTARGS                 "console=ttyS0,115200 " \
					"root=/dev/mtdblock6 " \
					"rootfstype=squashfs"
#define CONFIG_BOOTCOMMAND              "sf probe;" \
					"mtdparts default;" \
					"bootm 0x9f300000"
#define CONFIG_LZMA						1

#define MTDIDS_DEFAULT                  "nor0=spi-flash.0"
#define MTDPARTS_DEFAULT                "mtdparts=spi-flash.0:" \
					"192k(u-boot),64k(env)," \
					"64k(RFdata),384k(zyxel_rfsd)" \
					 "384k(romd),64k(header)" \
					 "2048k(uImage),13184k(rootfs)"

#define CONFIG_ENV_IS_IN_SPI_FLASH		1
#define CONFIG_ENV_SECT_SIZE	CFG_FLASH_SECTOR_SIZE
#define CONFIG_ENV_SIZE		CFG_ENV_PART_SIZE
#define CONFIG_ENV_ADDR		(CONFIG_SYS_FLASH_BASE + CONFIG_SYS_MONITOR_LEN)
#define CONFIG_ENV_OVERWRITE

#define CFG_ENV_PART_ADDR		0x9f030000
#define CFG_ENV_PART_SIZE		0x10000
/*
 * Command
 */
#define CONFIG_CMD_MTDPARTS			1

/* Miscellaneous configurable options */
#define CONFIG_SYS_CBSIZE               256
#define CONFIG_SYS_MAXARGS              16
#define CONFIG_SYS_PBSIZE               (CONFIG_SYS_CBSIZE + \
					sizeof(CONFIG_SYS_PROMPT) + 16)
					
					
#define CONFIG_CMDLINE_EDITING
#define CONFIG_AUTO_COMPLETE					


/*
 * Diagnostics
 */
#define CONFIG_SYS_MEMTEST_START        0x80200000
#define CONFIG_SYS_MEMTEST_END          0x83800000
#define CONFIG_CMD_MEMTEST

#endif  /* __CONFIG_H */
