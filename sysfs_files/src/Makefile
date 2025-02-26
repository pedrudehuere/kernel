KDIR ?= /lib/modules/`uname -r`/build
obj-m = sysfs_files.o

default:
	$(MAKE) -C $(KDIR) M=$$PWD

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean

