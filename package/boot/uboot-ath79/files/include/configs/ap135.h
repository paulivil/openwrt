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
#undef MTDPARTS_DEFAULT
#undef CFG_HZ
#define FLASH_SIZE               16
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
 * Board Configuration
 */
#define CONFIG_BOARD_AP135		1
#define CONFIG_BOARD_NAME		"AP135"

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

/*-----------------------------------------------------------------------
 * Miscellaneous configurable options
 */

#define TEXT_BASE            0x9f000000
#define CONFIG_SYS_MALLOC_LEN           256*1024
#define CONFIG_SYS_BOOTPARAMS_LEN       128*1024



#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO
#define CONFIG_BOARD_EARLY_INIT_F

#define CONFIG_SYS_MHZ                  700
#define CONFIG_SYS_MIPS_TIMER_FREQ      (CONFIG_SYS_MHZ * 1000000)
#define CONFIG_SYS_CBSIZE               512
#define CONFIG_SYS_MAXARGS              16
#define CONFIG_SYS_PBSIZE               (CONFIG_SYS_CBSIZE + \
					sizeof(CONFIG_SYS_PROMPT) + 16)  /* Print Buffer Size */
					
					
#define CONFIG_CMDLINE_EDITING
#define CONFIG_AUTO_COMPLETE
#define CONFIG_LZMA						1
#define CONFIG_SYS_MONITOR_BASE		TEXT_BASE
#define CONFIG_SYS_MONITOR_LEN		CFG_LOADER_PART_SIZE
/*
 * For booting Linux, the board info and command line data
 * have to be in the first 8 MB of memory, since this is
 * the maximum mapped by the Linux kernel during initialization ??
 */

#define CONFIG_SYS_SDRAM_SIZE   128       /* SDRAM size in MB */
#define CONFIG_SYS_BOOTMAPSZ		(CONFIG_SYS_SDRAM_BASE + (CONFIG_SYS_SDRAM_SIZE << 20))
#define CONFIG_SYS_BOOTM_LEN		(CONFIG_SYS_SDRAM_SIZE << 20)
/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define CONFIG_ENV_IS_IN_SPI_FLASH		1
/* NOR Flash start address */
#define CONFIG_SYS_FLASH_BASE			0x9f000000
#ifdef COMPRESSED_UBOOT
#define BOOTSTRAP_TEXT_BASE		CONFIG_SYS_FLASH_BASE
#define BOOTSTRAP_CFG_MONITOR_BASE	BOOTSTRAP_TEXT_BASE
#endif
#if (FLASH_SIZE == 16)
#define CONFIG_SYS_MAX_FLASH_SECT	256	/* max number of sectors on one chip */
#elif (FLASH_SIZE == 8)
#define CONFIG_SYS_MAX_FLASH_SECT	128	/* max number of sectors on one chip */
#else
#define CONFIG_SYS_MAX_FLASH_SECT	64	/* max number of sectors on one chip */
#endif

#if (CONFIG_SYS_MAX_FLASH_SECT * CFG_FLASH_SECTOR_SIZE) != CFG_FLASH_SIZE
#	error "Invalid flash configuration"
#endif

#define CONFIG_ENV_SECT_SIZE	CFG_FLASH_SECTOR_SIZE
#define CONFIG_ENV_SIZE		CFG_ENV_PART_SIZE
#define CONFIG_ENV_ADDR		(CONFIG_SYS_FLASH_BASE + CONFIG_SYS_MONITOR_LEN)
#define CONFIG_ENV_OVERWRITE

#define CFG_ENV_PART_ADDR		0x9f030000
#define CFG_ENV_PART_SIZE		0x10000

/*-----------------------------------------------------------------------
 * Partition Configuration
 */
#undef	CONFIG_BOOTARGS
#undef CONFIG_BOOTARGS_RD
#undef CONFIG_BOOTARGS_FL

#define __gen_nand_cmd(cmd, offs, file, eraseCmd, writeCmd, eraseSize)	\
	#cmd "=tftp ${loadaddr} ${dir}" #file ";"						\
	#eraseCmd " " #offs " " #eraseSize ";"							\
	#writeCmd " ${fileaddr} " #offs " ${filesize}\0"

#define gen_nand_cmd(cmd, offs, file, partSize)			\
	__gen_nand_cmd(cmd, offs, file, nand erase, nand write, partSize)

#ifndef CONFIG_ZFLASH_CMD
#define __gen_cmd(cmd, offs, file, eraseCmd, writeCmd, eraseSize)	\
	#cmd "=tftp ${loadaddr} ${dir}" #file ";"						\
	#eraseCmd " " #offs " +" #eraseSize ";"							\
	#writeCmd " ${fileaddr} " #offs " ${filesize}\0"

#define gen_cmd(cmd, offs, file, partSize)							\
	__gen_cmd(cmd, offs, file, erase, cp.b, partSize)
#else
#define __gen_cmd(cmd, offs, file, eraseCmd, writeCmd, eraseSize)	\
	#cmd "=tftp ${loadaddr} ${dir}" #file ";"						\
	#eraseCmd " " #offs " " #eraseSize ";"							\
	#writeCmd " ${fileaddr} " #offs " ${filesize}\0"

#define gen_cmd(cmd, offs, file, partSize)							\
	__gen_cmd(cmd, offs, file, zflash erase, zflash write, partSize)
#endif

#define __gen_img_env_val(name, addr, size)	\
	#name "_paddr=" #addr "\0"			\
	#name "_psize=" #size "\0"

#define gen_img_env_val(name, addr, size)	\
	__gen_img_env_val(name, addr, size)


#define CFG_LOADER_PART_ADDR		CONFIG_SYS_FLASH_BASE

  #define CFG_LOADER_PART_SIZE		0x30000
  #define CFG_ENV_PART_ADDR		0x9f030000
  #define CFG_ENV_PART_SIZE		0x10000
  #define CFG_RFDATA_PART_ADDR      	0x9f040000
  #define CFG_RFDATA_PART_SIZE      	0x10000
  #define CFG_ROOTFSDATA_PART_ADDR  	0x9f050000
  #define CFG_ROOTFSDATA_PART_SIZE  	0x60000
  #define CFG_ROMD_PART_ADDR		0x9f0b0000
  #define CFG_ROMD_PART_SIZE		0x60000
  #define CFG_ROMDHDR_PART_SIZE     	0x20
  #define CFG_HEADER_PART_ADDR      	0x9f110000
  #define CFG_HEADER_PART_SIZE      	0x10000
  #define CFG_HEADER_IMG_SIZE		0x10000
  #define CFG_ROOTFS_PART_ADDR		0x9f120000
  #define CFG_ROOTFS_PART_SIZE		0xee0000
 



 

  #define LOADER_IMG_ENV_VAL	gen_img_env_val(ldr, CFG_LOADER_PART_ADDR, CFG_LOADER_PART_SIZE)
  #define ENV_IMG_ENV_VAL	gen_img_env_val(env, CFG_ENV_PART_ADDR, CFG_ENV_PART_SIZE)
  #define RFDATA_IMG_ENV_VAL	gen_img_env_val(rfdat, CFG_RFDATA_PART_ADDR, CFG_RFDATA_PART_SIZE)
  #define RTFSDATA_IMG_ENV_VAL	gen_img_env_val(rfsdat, CFG_ROOTFSDATA_PART_ADDR, CFG_ROOTFSDATA_PART_SIZE)
  #define HEADER_IMG_ENV_VAL    gen_img_env_val(hdr, CFG_HEADER_PART_ADDR, CFG_HEADER_PART_SIZE)
  #define ROOTFS_IMG_ENV_VAL	gen_img_env_val(rfs, CFG_ROOTFS_PART_ADDR, CFG_ROOTFS_PART_SIZE)
  #define ROMD_IMG_ENV_VAL	gen_img_env_val(romd, CFG_ROMD_PART_ADDR, CFG_ROMD_PART_SIZE)
  #define HEADER1_IMG_ENV_VAL   gen_img_env_val(hdr1, CFG_HEADER1_PART_ADDR, CFG_HEADER1_PART_SIZE)
  #define ROOTFS1_IMG_ENV_VAL	gen_img_env_val(rfs1, CFG_ROOTFS1_PART_ADDR, CFG_ROOTFS1_PART_SIZE)
  #define BU1_IMG_ENV_VAL	gen_img_env_val(bu1, CFG_BU1_PART_ADDR, CFG_BU1_PART_SIZE)

  #define UPDATE_LOADER_CMD     gen_cmd(lu, ${ldr_paddr}, u-boot.bin, ${ldr_psize})
  #define UPDATE_ROOTFS_CMD     gen_cmd(lf, ${rfs_paddr}, ${img_prefix}rootfs.jffs2, ${rootfs_psize})

  #define IMG_ENV_VAL           LOADER_IMG_ENV_VAL ENV_IMG_ENV_VAL RFDATA_IMG_ENV_VAL \
                                RTFSDATA_IMG_ENV_VAL ROMD_IMG_ENV_VAL HEADER_IMG_ENV_VAL \
				ROOTFS_IMG_ENV_VAL
  #define MTDPARTS_DEFAULT      "mtdparts=spi0.0:${ldr_psize}(u-boot)${readonly},${env_psize}(env)${readonly},${rfdat_psize}(RFdata)${readonly},${rfsdat_psize}(rootfs_data),${romd_psize}(romd),${hdr_psize}(header),${rfs_psize}(rootfs)"
  #define ROOTFS_MTD_NO		"mtdblock6"
  #define UPGRADE_IMG_CMD	UPDATE_LOADER_CMD UPDATE_ROOTFS_CMD

  #define BOOT_FLASH_CMD        "boot_flash=fsload ${loadaddr} /boot/vmlinux.lzma.itb;bootm ${loadaddr}\0"
  #define BOOTARG_DEFAULT	"board=" CONFIG_BOARD_NAME " root=/dev/" ROOTFS_MTD_NO " rootfstype=jffs2 noinitrd ${bootmode}


/* ROOTFS_MTD_NO, MTDPARTS_DEFAULT, BOOT_FLASH_CMD, IMG_ENV_VAL, UPGRADE_IMG_CMD */
#define	CONFIG_EXTRA_ENV_SETTINGS					\
    "uboot_env_ver=" CONFIG_ENV_VERSION "\0" \
    "img_prefix=nbg6616-\0"	\
    "loadaddr=80400000\0" \
    "fdtaddr=80400000\0" \
    "fdt_addr_r=803F8000\0" \
    "readonly=ro\0" \
    "setmtdparts=setenv mtdparts " MTDPARTS_DEFAULT "\0" \
    "flashargs=setenv bootargs " BOOTARG_DEFAULT "\0"  \
    "addtty=setenv bootargs ${bootargs} console=ttyS0,${baudrate}\0" \
    "addmtd=setenv bootargs ${bootargs} ${mtdparts}\0" \
    BOOT_FLASH_CMD \
    "bootcmd=run boot_flash\0" \
    IMG_ENV_VAL \
    UPGRADE_IMG_CMD \
    "countrycode=ff\0" \
    "serialnum=S100Z47000001\0" \
    "hostname=NBG6616\0"
/*-----------------------------------------------------------------------
 * JFFS2 Filesystem Configuration
 */
#define CONFIG_CMD_JFFS2
#define CONFIG_CMD_JFFS2_ULOAD
#define CONFIG_JFFS2_SUMMARY

#define CONFIG_JFFS2_PART_OFFSET	(CFG_ROOTFS_PART_ADDR-CONFIG_SYS_FLASH_BASE)
// Default using remaining flash space if you ignore 'CONFIG_JFFS_PART_SIZE'
#define CONFIG_JFFS2_PART_SIZE		CFG_ROOTFS_PART_SIZE
/*-----------------------------------------------------------------------
 * Networking Configuration
 */
#define CONFIG_SERVERIP 192.168.1.33
#define CONFIG_IPADDR 192.168.1.1
#define CONFIG_ETHADDR 00:AA:BB:CC:DD:00
#define CONFIG_NET_MULTI
/*-----------------------------------------------------------------------
 * PCI Configuration
 */
#define CONFIG_PCI
/*
 * Command
 */
#define CONFIG_CMD_MTDPARTS			
#define CONFIG_ZFLASH_CMD
#define CONFIG_CMD_ASKENV
#define CONFIG_CMD_PING

#if TEXT_BASE != 0x9F000000
#define CONFIG_SKIP_LOWLEVEL_INIT
#endif

/*
 * Serial Port
 */
#define CONFIG_DEBUG_UART_BASE 			0x18020000
#define CONFIG_BAUDRATE                 115200
#define CONFIG_SYS_BAUDRATE_TABLE \
	{9600, 19200, 38400, 57600, 115200}


/*
 * Diagnostics
 */
#define CONFIG_SYS_MEMTEST_START        0x80200000
#define CONFIG_SYS_MEMTEST_END          0x83800000
#define CONFIG_CMD_MEMTEST

#endif  /* __CONFIG_H */
