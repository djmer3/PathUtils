add_test( example.add /home/dean/dev_ws/PathUtils/build/test/path_tests [==[--gtest_filter=example.add]==] --gtest_also_run_disabled_tests)
set_tests_properties( example.add PROPERTIES WORKING_DIRECTORY /home/dean/dev_ws/PathUtils/build/test)
set( path_tests_TESTS example.add)
