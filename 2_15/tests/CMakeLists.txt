add_executable(btree_test_start
        individual.h
        btree1_tests.cpp
        adapters1_tests.cpp
    ${CMAKE_SOURCE_DIR}/../../src/utils.h
    ${CMAKE_SOURCE_DIR}/../../src/btree.h
    ${CMAKE_SOURCE_DIR}/../../src/btree.cpp
    ${CMAKE_SOURCE_DIR}/../../src/btree_adapters.h
)

target_link_libraries(btree_test_start ${gtest_LIB} ${gtest_main_LIB})
