include $(TOPDIR)/rules.mk



PKG_NAME:=hdr-writer
PKG_VERSION:=1.0
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE:=hdr-writer-$(PKG_VERSION).tar.gz
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/paulivil/hdr-writer.git
PKG_MIRROR_HASH:=fb6dfc645bb447ec9e95bd2f5102946092673cf2f2cafde2a4c9b309687bddbb
PKG_SOURCE_VERSION:=1772cf4
PKG_CAT:=zcat

include $(INCLUDE_DIR)/package.mk

define Package/hdr-writer
  SECTION:=devel
  CATEGORY:=Development
  TITLE:=ZyXEL tool for writing a header
  #URL:=
endef

define Package/hdr-writer/description
  ELF32 binary to prefix the factory image with a Zyxel compatible header
endef



define Build/InstallDev
	
	$(INSTALL_BIN) ./files/genImgHdr $(STAGING_DIR_HOST)/bin/
	
endef





$(eval $(call BuildPackage))


