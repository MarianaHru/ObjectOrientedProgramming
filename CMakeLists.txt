cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_TOOLCHAIN_FILE /Users/tarasgrudzinskij/Documents/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(GTest_DIR /Users/tarasgrudzinskij/Documents/vcpkg/installed/x64-osx/share/gtest)
find_package(GTest CONFIG REQUIRED)

# lab3_1
project(lab3_1_unit_test)

# Використовуємо C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Підключаємо Google Test
find_package(GTest REQUIRED)

# Перевіряємо, чи знайшовся Google Test
if(NOT GTest_FOUND)
    message(FATAL_ERROR "Google Test not found! Install it or provide its path.")
endif()

add_executable(lab3_1_unit_test 
    lab3_1/lab3_1_unit_test.cpp 
    lab3_1/Liquid.cpp 
    lab3_1/Alcohol.cpp 
)

# Визначаємо макрос UNIT_TESTING
target_compile_definitions(lab3_1_unit_test PRIVATE UNIT_TESTING)

# Додаємо заголовочні файли
target_include_directories(lab3_1_unit_test PRIVATE ${GTEST_INCLUDE_DIRS} lab3_1)

# Лінкуємо Google Test і pthread
target_link_libraries(lab3_1_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# Додаємо команду для запуску тестів
enable_testing()
add_test(NAME Lab3_1_UnitTests COMMAND lab3_1_unit_test)



