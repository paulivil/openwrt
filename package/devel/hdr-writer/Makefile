include $(TOPDIR)/rules.mk



PKG_NAME:=hdr-writer
PKG_VERSION:=0.0.1
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE:=hdr-writer-$(PKG_VERSION).tar.gz
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=@GITHUB/paulivil/openwrt/tree/master/package/devel/hdr-writer.git
PKG_HASH:=skip
PKG_SOURCE_VERSION:=skip


PKG_CAT:=zcat

include $(INCLUDE_DIR)/package.mk

define Package/hdr-writer/Default
  SECTION:=devel
  CATEGORY:=Zyxel Packages
  #URL:=
endef



define Package/hdr-writer
TITLE:=Utility for writing a ZyXEL firmware header
$(call Package/hdr-writer/Default)
endef

define Package/hdr-writer/description
  ELF32 binary to prefix the factory image with a Zyxel compatible header
endef

define Build/hdr-writer/InstallDev
 $(call Build/hdr-writer/InstallDev/Default,installdev)
endef

define Build/hdr-writer/InstallDev
	$(INSTALL_DIR) $(STAGING_DIR)/bin/
	$(CP) $(PKG_INSTALL_DIR) $(STAGING_DIR_HOST)/bin/
endef



$(eval $(call BuildPackage,hdr-writer))


