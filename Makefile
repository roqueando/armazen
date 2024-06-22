TARGET = armazen
TEST_TARGET = armazen-test
BUILDDIR = build
BUILD_DEBUG_DIR = debug

run: $(BUILDDIR)/Makefile
	@cd $(BUILDDIR) && ./$(TARGET)

test: $(BUILDDIR)/Makefile
	@cd $(BUILDDIR)/tests && ./$(TEST_TARGET)

build: $(BUILDDIR)/Makefile
	@$(MAKE) -C $(BUILDDIR)

debug: $(BUILD_DEBUG_DIR)/Makefile
	@$(MAKE) -C $(BUILD_DEBUG_DIR)

$(BUILDDIR)/Makefile:
	@mkdir -p $(BUILDDIR)
	@cd $(BUILDDIR) && cmake ..

$(BUILD_DEBUG_DIR)/Makefile:
	@mkdir -p $(BUILD_DEBUG_DIR)
	@cd $(BUILD_DEBUG_DIR) && cmake -DCMAKE_BUILD_TYPE=Debug ..

clean:
	@$(MAKE) -C $(BUILDDIR) clean
	@rm -rf $(BUILDDIR)

.PHONY: build clean
