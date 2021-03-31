BUILD_DIR?=build

build-project:
	rm -rf $(BUILD_DIR) && mkdir $(BUILD_DIR) && cd build && cmake .. && make

format-code:
	./formatter.sh ./

run-test-template:
	cd $(BUILD_DIR)/tests/unit/$(dir) && ./$(name)_test

run-storage-test:
	make run-test-template name=storage dir=storage

run-file-test:
	make run-test-template name=file dir=file

run-file-calc:
	make run-test-template name=length_calculator dir=length_calculator

run-collector-sync:
	make run-test-template name=collector_sync dir=collector/sync

run-collector-async:
	make run-test-template name=collector_async dir=collector/async

run-all-tests:
	make run-file-calc && make run-file-test && make run-storage-test && make run-collector-async && make run-collector-sync

vg-check:
	cd $(BUILD_DIR)/tests/unit/$(dir)/ && valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --undef-value-errors=no --verbose ./$(name)_test

vg-check-tests:
	make vg-check dir=storage name=storage  \
		&& make vg-check dir=file name=file  \
			&& make vg-check name=length_calculator dir=length_calculator  \
				&& make vg-check name=collector_sync dir=collector/sync

generate-test-data:
	python3 ./generator.py tests/unit/productivity/sync/data/file.txt && python3 ./generator.py tests/unit/productivity/async/data/file.txt

run-productivity:
	make run-test-template name=productivity_sync_test dir=productivity/sync \
		&& make run-test-template name=productivity_async_test dir=productivity/async

generate-gcov:
	cd $(output) && gcov $(dir)/src/$(lib_dir)/CMakeFiles/$(lib_dir).dir/$(lib_name).c.gcno && cp -rf $(dir)/src/$(lib_dir)/CMakeFiles/$(lib_dir).dir/ .

generate-gcov-storage:
	make generate-gcov  dir=../$(BUILD_DIR)  lib_dir=data_storage  lib_name=storage output=coverage

generate-gcov-file:
	make generate-gcov  dir=../$(BUILD_DIR)  lib_dir=file  lib_name=file output=coverage

generate-gcov-collector:
	make generate-gcov  dir=../$(BUILD_DIR)  lib_dir=collector  lib_name=collector output=coverage

generate-gcov-collector-parallel:
	make generate-gcov  dir=../$(BUILD_DIR)  lib_dir=collector_parallel  lib_name=collector output=coverage

generate-gcov-collector-parallel:
	make generate-gcov  dir=../$(BUILD_DIR)  lib_dir=length_calculator  lib_name=length_calculator output=coverage

generate-coverage-html:
	genhtml $(filename).info --output-directory $(directory)

generate-lcov:
	lcov --capture --directory $(directory) --output-file $(output_filename).info

generate-gcov-all:
	mkdir coverage  \
		&& make generate-gcov-storage  \
			&& make generate-gcov-file  \
				&& make generate-gcov-collector  \
				 	&& make generate-gcov-collector-parallel  \
				 		&& make generate-gcov-collector-parallel

generate-lcov-all:
	make generate-lcov output_filename=coverage/coverage directory=coverage

generate-html-coverage:
	mkdir coverage_output && make generate-coverage-html filename=coverage/coverage directory=coverage_ouput

get-all-coverage:
	make generate-gcov-all && make generate-lcov-all && make generate-html-coverage