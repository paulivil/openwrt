#
# Copyright (C) 2006-2012 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk

PKG_NAME:=mkimage
<<<<<<< HEAD
PKG_VERSION:=2012.04.01

PKG_SOURCE:=u-boot-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=http://
PKG_MD5SUM:=192bb231082d9159fb6e16de3039b6b2
PKG_CAT:=bzcat
=======
PKG_VERSION:=2020.04

PKG_SOURCE:=u-boot-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:= \
	https://mirror.cyberbits.eu/u-boot \
	https://ftp.denx.de/pub/u-boot \
	ftp://ftp.denx.de/pub/u-boot
PKG_HASH:=fe732aaf037d9cc3c0909bad8362af366ae964bbdac6913a34081ff4ad565372
>>>>>>> 418362b1cc106b9aca3905150199f60548906fff

HOST_BUILD_DIR:=$(BUILD_DIR_HOST)/u-boot-$(PKG_VERSION)

include $(INCLUDE_DIR)/host-build.mk

define Host/Prepare
	$(Host/Prepare/Default)
	rm -f \
		$(HOST_BUILD_DIR)/include/errno.h \
		$(HOST_BUILD_DIR)/include/malloc.h
endef

define Host/Compile
	rm -f $(HOST_BUILD_DIR)/tools/.depend
	touch $(HOST_BUILD_DIR)/include/config.h
	$(MAKE) -C $(HOST_BUILD_DIR) BUILD_DIR= BIN_FILES-y="mkimage" HOSTLDFLAGS="-static" tools
endef

define Host/Install
	$(CP) $(HOST_BUILD_DIR)/tools/mkimage $(STAGING_DIR_HOST)/bin/
endef

define Host/Clean
	rm -f $(STAGING_DIR_HOST)/bin/mkimage
endef

$(eval $(call HostBuild))
