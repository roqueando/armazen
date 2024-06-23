TARGET = armazen
TEST_TARGET = armazen-test
BUILDDIR = build
BUILD_RELEASE_DIR = release

run: $(BUILDDIR)/Makefile
	@cd $(BUILDDIR) && ./$(TARGET)

test: $(BUILDDIR)/Makefile
	@cd $(BUILDDIR)/tests && ./$(TEST_TARGET)

build: $(BUILDDIR)/Makefile
	@cd $(BUILDDIR) && $(MAKE)

configure: $(BUILDDIR)/Makefile
	@$(MAKE) -C $(BUILDDIR)

release: $(BUILD_RELEASE_DIR)/Makefile
	@$(MAKE) -C $(BUILD_RELEASE_DIR)

$(BUILDDIR)/Makefile:
	@mkdir -p $(BUILDDIR)
	@cd $(BUILDDIR) && cmake -DCMAKE_BUILD_TYPE=Debug ..

$(BUILD_RELEASE_DIR)/Makefile:
	@mkdir -p $(BUILD_RELEASE_DIR) 
	@cd $(BUILD_RELEASE_DIR) && cmake -DCMAKE_BUILD_TYPE=Release ..

clean:
	@$(MAKE) -C $(BUILDDIR) clean
	@rm -rf $(BUILDDIR)

.PHONY: build clean
