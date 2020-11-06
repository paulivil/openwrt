/*
 * Copyright (c) 2016 The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#ifndef _ATH_FLASH_H
#define _ATH_FLASH_H

#define display(_x)


/*
 * primitives
 */

#define ath_be_msb(_val, _i) (((_val) & (1 << (7 - _i))) >> (7 - _i))

#define ath_spi_bit_banger(_byte)	do {				\
	int i;								\
	for(i = 0; i < 8; i++) {					\
		ath_reg_wr_nf(ATH_SPI_WRITE,				\
			ATH_SPI_CE_LOW | ath_be_msb(_byte, i));		\
		ath_reg_wr_nf(ATH_SPI_WRITE,				\
			ATH_SPI_CE_HIGH | ath_be_msb(_byte, i));	\
	}								\
} while (0)

#define ath_spi_go()	do {				\
	ath_reg_wr_nf(ATH_SPI_WRITE, ATH_SPI_CE_LOW);	\
	ath_reg_wr_nf(ATH_SPI_WRITE, ATH_SPI_CS_DIS);	\
} while (0)


#define ath_spi_send_addr(__a) do {			\
	ath_spi_bit_banger(((__a & 0xff0000) >> 16));	\
	ath_spi_bit_banger(((__a & 0x00ff00) >> 8));	\
	ath_spi_bit_banger(__a & 0x0000ff);		\
} while (0)

#define ath_spi_delay_8()	ath_spi_bit_banger(0)
#define ath_spi_done()		ath_reg_wr_nf(ATH_SPI_FS, 0)

extern unsigned long 
flash_get_geom (flash_info_t *flash_info)
{  
    int i;  
  
    flash_info->flash_id  = FLASH_M25P64;  
    flash_info->size      = (CFG_MAX_FLASH_BANKS * CFG_MAX_FLASH_SECT *  
                            CFG_FLASH_SECTOR_SIZE);  
    flash_info->sector_count = CFG_MAX_FLASH_SECT;  
  
    for (i = 0; i < flash_info->sector_count; i++) {  
        flash_info->start[i] = CFG_FLASH_BASE + (i * CFG_FLASH_SECTOR_SIZE);  
        flash_info->protect[i] = 0;  
    }  
  
    printf ("flash size %dMB\n", flash_info->size/(1024*1024));  
    return (flash_info->size);  
}  

#endif /* _ATH_FLASH_H */