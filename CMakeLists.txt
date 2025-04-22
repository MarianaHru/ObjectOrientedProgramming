cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_TOOLCHAIN_FILE /Users/tarasgrudzinskij/Documents/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(GTest_DIR /Users/tarasgrudzinskij/Documents/vcpkg/installed/x64-osx/share/gtest)
find_package(GTest CONFIG REQUIRED)

# lab4_1
project(lab4_1_unit_test)

# Використовуємо C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Підключаємо Google Test
find_package(GTest REQUIRED)

# Перевіряємо, чи знайшовся Google Test
if(NOT GTest_FOUND)
    message(FATAL_ERROR "Google Test not found! Install it or provide its path.")
endif()

add_executable(lab4_1_unit_test 
    lab4_1/lab4_1_unit_test.cpp 
    lab4_1/lab4_1.cpp 
    
)

# Визначаємо макрос UNIT_TESTING
target_compile_definitions(lab4_1_unit_test PRIVATE UNIT_TESTING)

# Додаємо заголовочні файли
target_include_directories(lab4_1_unit_test PRIVATE ${GTEST_INCLUDE_DIRS} lab4_1)

# Лінкуємо Google Test і pthread
target_link_libraries(lab4_1_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# Додаємо команду для запуску тестів
enable_testing()
add_test(NAME Lab4_1_UnitTests COMMAND lab4_1_unit_test)



# lab4_2
project(lab4_2_unit_test)

# Використовуємо C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Підключаємо Google Test
find_package(GTest REQUIRED)

# Перевіряємо, чи знайшовся Google Test
if(NOT GTest_FOUND)
    message(FATAL_ERROR "Google Test not found! Install it or provide its path.")
endif()

add_executable(lab4_2_unit_test 
    lab4_2/lab4_2_unit_test.cpp 
    lab4_2/lab4_2.cpp 
    
)

# Визначаємо макрос UNIT_TESTING
target_compile_definitions(lab4_2_unit_test PRIVATE UNIT_TESTING)

# Додаємо заголовочні файли
target_include_directories(lab4_2_unit_test PRIVATE ${GTEST_INCLUDE_DIRS} lab4_2)

# Лінкуємо Google Test і pthread
target_link_libraries(lab4_2_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# Додаємо команду для запуску тестів
enable_testing()
add_test(NAME Lab4_2_UnitTests COMMAND lab4_2_unit_test)




