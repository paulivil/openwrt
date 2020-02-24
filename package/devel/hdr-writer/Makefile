include $(TOPDIR)/rules.mk



PKG_NAME:=hdr-writer
PKG_VERSION:=1.0
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE:=hdr-writer-$(PKG_VERSION).tar.gz
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/paulivil/hdr-writer.git
PKG_MIRROR_HASH:=c61d0860dcf7177cf492472f54d8fdee73ccf656d575239a47c73815cf0a889f
PKG_SOURCE_VERSION:=def029a
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
	
	$(INSTALL_DIR) $(STAGING_DIR_HOST)/bin
	$(CP) ./files/genImgHdr $(STAGING_DIR_HOST)/bin/genImgHdr
endef

define Package/hdr-writer/install
	$(INSTALL_DIR)					$(1)/usr/bin
	$(INSTALL_BIN) ./files/genImgHdr	$(1)/usr/bin/genImgHdr
endef



$(eval $(call BuildPackage,hdr-writer))


