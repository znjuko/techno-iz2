BUILD_DIR?=build

build-project:
	rm -rf $(BUILD_DIR) && mkdir $(BUILD_DIR) && cd build && cmake .. && make

format-code:
	./formatter.sh ./

run-test-template:
	./$(BUILD_DIR)/tests/unit/$(name)/$(name)_test

run-storage-test:
	make run-test-template name=storage

run-file-test:
	make run-test-template name=file

run-file-calc:
	make run-test-template name=length_calculator

run-all-tests:
	make run-file-calc && make run-file-test && make run-storage-test

vg-check:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --undef-value-errors=no --verbose ./$(BUILD_DIR)/tests/unit/$(name)/$(name)_test

vg-check-tests:
	make vg-check name=storage && make vg-check name=file && make vg-check name=length_calculator
