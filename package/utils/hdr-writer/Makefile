include $(TOPDIR)/rules.mk



PKG_NAME:=hdr-writer
PKG_VERSION:=0.0.1
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE:=hdr-writer-$(PKG_VERSION).tar.gz
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=@GITHUB/paulivil/openwrt/tree/master/package/utils/hdr-writer
PKG_MIRROR_HASH:=skip


PKG_CAT:=zcat

include $(INCLUDE_DIR)/package.mk

define Package/hdr-writer/Default
  SECTION:=utils
  CATEGORY:=Zyxel Packages
  TITLE:=Firmware header writer
  #DESCRIPTION:=This variable is obsolete. use the Package/name/description define instead!
  #URL:=
endef

define Package/hdr-writer/description
  ELF32 program to prefix the factory image with a Zyxel compatible header
endef

define Package/hdr-writer/Install
endef

define Package/Install
	$(call Package/InstallDev)
endef

define Package/InstallDev
	$(INSTALL_DIR) $(STAGING_DIR)/bin/
	$(CP) $(PKG_INSTALL_DIR) $(STAGING_DIR_HOST)/bin/
endef



$(eval $(call BuildPackage,hdr-writer))


