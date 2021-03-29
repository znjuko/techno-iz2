BUILD_DIR?=build

build-project:
	rm -rf $(BUILD_DIR) && mkdir $(BUILD_DIR) && cd build && cmake .. && make

format-code:
	./formatter.sh ./

run-test-template:
	./$(BUILD_DIR)/tests/unit/$(name)/$(name)_test

run-storage-test:
	make run-test-template name=storage dir=storage

run-file-test:
	make run-test-template name=file dir=file

run-file-calc:
	make run-test-template name=length_calculator dir=length_calculator

run-collector-sync:
	make run-test-template name=collector/sync dir=collector_sync

run-collector-async:
	make run-test-template name=collector/async dir=collector_async

run-all-tests:
	make run-file-calc && make run-file-test && make run-storage-test && make run-collector-async && make run-collector-sync

vg-check:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --undef-value-errors=no --verbose ./$(BUILD_DIR)/tests/unit/$(dir)/$(name)_test

vg-check-tests:
	make vg-check name=storage && make vg-check name=file && make vg-check name=length_calculator

generate-test-data:
	python3 ./generator.py tests/unit/productivity/sync/data/file.txt && python3 ./generator.py tests/unit/productivity/async/data/file.txt