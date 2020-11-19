# Copyright (C) 2011 OpenWrt.org

PART_NAME=firmware

REQUIRE_IMAGE_METADATA=1
platform_check_image() {

	local board=$(board_name)
	local magic_long="$(get_magic_long "$1")"

	[ "$#" -gt 1 ] && return 1

	
	case "$board" in
		nbg6616)
		[ "$magic_long" != "19852003" ] && {
			echo "Invalid image type."
			return 1
		}

		return 0
		;;
}

RAMFS_COPY_BIN='fw_printenv fw_setenv nandwrite'
RAMFS_COPY_DATA='/etc/fw_env.config /var/lock/fw_printenv.lock'

platform_do_upgrade() {
	local board=$(board_name)

	case "$board" in
	glinet,gl-ar300m-nand|\
	glinet,gl-ar300m-nor|\
	zyxel,nbg6616)
		glinet_nand_nor_do_upgrade "$1"
		;;
	glinet,gl-ar750s-nor|\
	glinet,gl-ar750s-nor-nand)
		nand_nor_do_upgrade "$1"
		;;
	*)
		nand_do_upgrade "$1"
		;;
	esac
}
