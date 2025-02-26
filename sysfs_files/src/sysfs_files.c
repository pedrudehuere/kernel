/**
 * @file    sysfs_symlinks.c
 * @author  Andrea Peter
 * @date    2025-02-26
 * @version 0.1
 * @brief  Experiments with sysfs files
 */

#include <linux/device.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sysinfo.h>

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Andrea Peter");
MODULE_DESCRIPTION("sysfs files experiments");
MODULE_VERSION("0.1");

const char *ROOT_DEVICE = "my_device";
struct device *root_device;

static int __init hello_start(void) {
  printk(KERN_INFO "Loading module\n");

  // Create root device in /sys/devices/
  root_device = root_device_register(ROOT_DEVICE);
  if (IS_ERR(root_device)) {
    pr_err("Could not allocate root device\n");
    return PTR_ERR(root_device);
  }
  printk(KERN_INFO "Loaded\n");
  return 0;
}

static void __exit hello_end(void) {
  printk(KERN_INFO "Unloading module\n");
  root_device_unregister(root_device);
  printk(KERN_INFO "Unloaded\n");
}

module_init(hello_start);
module_exit(hello_end);
