/*
 * SPDX-License-Identifier: GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_SYS_TEXT_BASE            0x9f000000

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

#define CONFIG_SYS_MALLOC_LEN           256*1024
#define CONFIG_SYS_BOOTPARAMS_LEN       128*1024

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
#define CONFIG_SYS_NS16550_CLK          25000000
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
#define CONFIG_ENV_OFFSET               0x00000
#define CONFIG_ENV_SECT_SIZE            0x10000
#define CONFIG_ENV_SIZE                 0x10000

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
