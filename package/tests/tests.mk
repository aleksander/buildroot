PACKAGE_DIR = $(TOPDIR)/package/tests

define TESTS_BUILD_CMDS
	$(TARGET_CC) $(PACKAGE_DIR)/test_uclibc_poll.c -o $(@D)/test_uclibc_poll -lpthread
endef

define TESTS_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/test_uclibc_poll $(TARGET_DIR)/sbin
endef

$(eval $(generic-package))
