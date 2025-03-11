cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_TOOLCHAIN_FILE /Users/tarasgrudzinskij/Documents/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(GTest_DIR /Users/tarasgrudzinskij/Documents/vcpkg/installed/x64-osx/share/gtest)
find_package(GTest CONFIG REQUIRED)


# Додаємо тести для lab1_1
add_executable(lab1_1_unit_test lab1_1/lab1_1_unit_test.cpp lab1_1/lab1_1.cpp)

target_compile_definitions(lab1_1_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab1_1_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)
