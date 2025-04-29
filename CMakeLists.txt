cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_TOOLCHAIN_FILE /Users/tarasgrudzinskij/Documents/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(GTest_DIR /Users/tarasgrudzinskij/Documents/vcpkg/installed/x64-osx/share/gtest)
find_package(GTest CONFIG REQUIRED)

# lab5_1_A
project(lab5_1_A_unit_test)

# Використовуємо C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Підключаємо Google Test
find_package(GTest REQUIRED)

# Перевіряємо, чи знайшовся Google Test
if(NOT GTest_FOUND)
    message(FATAL_ERROR "Google Test not found! Install it or provide its path.")
endif()

add_executable(lab5_1_A_unit_test 
    lab5_1_A/lab5_1_A_unit_test.cpp 
    lab5_1_A/lab5_1_A.cpp
    lab5_1_A/Fraction.cpp  
    
)

# Визначаємо макрос UNIT_TESTING
target_compile_definitions(lab5_1_A_unit_test PRIVATE UNIT_TESTING)

# Додаємо заголовочні файли
target_include_directories(lab5_1_A_unit_test PRIVATE ${GTEST_INCLUDE_DIRS} lab5_1_A)

# Лінкуємо Google Test і pthread
target_link_libraries(lab5_1_A_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# Додаємо команду для запуску тестів
enable_testing()
add_test(NAME Lab5_1_A_UnitTests COMMAND lab5_1_A_unit_test)


# lab5_1_B
project(lab5_1_B_unit_test)

# Використовуємо C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Підключаємо Google Test
find_package(GTest REQUIRED)

# Перевіряємо, чи знайшовся Google Test
if(NOT GTest_FOUND)
    message(FATAL_ERROR "Google Test not found! Install it or provide its path.")
endif()

add_executable(lab5_1_B_unit_test 
    lab5_1_B/lab5_1_B_unit_test.cpp 
    lab5_1_B/lab5_1_B.cpp
    lab5_1_B/Money.cpp  
    lab5_1_B/MoneyException.cpp 
    
)

# Визначаємо макрос UNIT_TESTING
target_compile_definitions(lab5_1_B_unit_test PRIVATE UNIT_TESTING)

# Додаємо заголовочні файли
target_include_directories(lab5_1_B_unit_test PRIVATE ${GTEST_INCLUDE_DIRS} lab5_1_B)

# Лінкуємо Google Test і pthread
target_link_libraries(lab5_1_B_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# Додаємо команду для запуску тестів
enable_testing()
add_test(NAME Lab5_1_B_UnitTests COMMAND lab5_1_B_unit_test)
