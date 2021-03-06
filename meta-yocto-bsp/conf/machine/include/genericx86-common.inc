include conf/machine/include/x86-base.inc
require conf/machine/include/qemuboot-x86.inc
MACHINE_FEATURES += "wifi efi pcbios"

PREFERRED_PROVIDER_virtual/kernel ?= "linux-yocto"
PREFERRED_PROVIDER_virtual/xserver ?= "xserver-xorg"
XSERVER ?= "${XSERVER_X86_BASE} \
            ${XSERVER_X86_EXT} \
            ${XSERVER_X86_I915} \
            ${XSERVER_X86_I965} \
            ${XSERVER_X86_FBDEV} \
            ${XSERVER_X86_VESA} \
            ${XSERVER_X86_MODESETTING} \
           "

MACHINE_EXTRA_RRECOMMENDS += "kernel-modules linux-firmware eee-acpi-scripts"

GLIBC_ADDONS = "nptl"

EXTRA_OECONF_append_pn-matchbox-panel-2 = " --with-battery=acpi"

IMAGE_FSTYPES += "wic wic.bmap"
WKS_FILE ?= "genericx86.wks"
do_image_wic[depends] += "gptfdisk-native:do_populate_sysroot"
do_image_wic[recrdeptask] += "do_bootimg"
