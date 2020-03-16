#!/bin/sh
# Copyright (C) 2009-2013 OpenWrt.org

. /lib/functions.sh
. /lib/functions/leds.sh

get_status_led() {
	local board=$(board_name)

	case $board in
	nbg6616)
		status_led="$board:green:power"
		;;
	nbg6716)
		status_led="$board:white:power"
		;;
	esac
}

set_state() {
	get_status_led

	case "$1" in
	preinit)
		status_led_blink_preinit
		;;
	failsafe)
		status_led_blink_failsafe
		;;
	preinit_regular)
		status_led_blink_preinit_regular
		;;
	upgrade)
		status_led_blink_preinit_regular
		;;
	done)	
		;;
	esac
}
