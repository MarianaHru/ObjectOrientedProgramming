cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_TOOLCHAIN_FILE /Users/tarasgrudzinskij/Documents/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(GTest_DIR /Users/tarasgrudzinskij/Documents/vcpkg/installed/x64-osx/share/gtest)
find_package(GTest CONFIG REQUIRED)


# Додаємо тести для lab1_1
add_executable(lab1_1_unit_test lab1_1/lab1_1_unit_test.cpp lab1_1/lab1_1.cpp)

target_compile_definitions(lab1_1_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab1_1_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)


# Додаємо тести для lab1_2
# add_executable(lab1_2_unit_test lab1_2/lab1_2_unit_test.cpp lab1_2/lab1_2.cpp)

# target_compile_definitions(lab1_2_unit_test PRIVATE UNIT_TESTING)
# target_link_libraries(lab1_2_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# Додаємо тести для lab1_2
add_executable(lab1_2_unit_test 
    lab1_2/lab1_2_unit_test.cpp 
    lab1_2/lab1_2.cpp 
    lab1_2/List.cpp  # Додаємо List.cpp
)

target_compile_definitions(lab1_2_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab1_2_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)



# # Додаємо тести для lab1_3
# add_executable(lab1_3_unit_test lab1_3/lab1_3_unit_test.cpp lab1_3/lab1_3.cpp)

# target_compile_definitions(lab1_3_unit_test PRIVATE UNIT_TESTING)
# target_link_libraries(lab1_3_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

cmake_minimum_required(VERSION 3.10)

project(lab1_3_unit_test)

# Використовуємо C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Підключаємо Google Test
find_package(GTest REQUIRED)

# Додаємо вихідні файли
add_executable(lab1_3_unit_test 
    lab1_3/lab1_3_unit_test.cpp 
    lab1_3/Money.cpp
)

# Додаємо визначення для тестування
target_compile_definitions(lab1_3_unit_test PRIVATE UNIT_TESTING)

# Підключаємо заголовочні файли
target_include_directories(lab1_3_unit_test PRIVATE ${GTEST_INCLUDE_DIRS})

# Лінкуємо з Google Test та pthread
target_link_libraries(lab1_3_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# Додаємо команду для запуску тестів після компіляції
enable_testing()
add_test(NAME MoneyTests COMMAND lab1_3_unit_test)





cmake_minimum_required(VERSION 3.10)

project(lab1_5_unit_test)

# Використовуємо C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Підключаємо Google Test
find_package(GTest REQUIRED)

# Перевіряємо, чи знайшовся Google Test
if(NOT GTest_FOUND)
    message(FATAL_ERROR "Google Test not found! Install it or provide its path.")
endif()

# Додаємо вихідні файли (перевір ім'я Alcohol.cpp!)
add_executable(lab1_5_unit_test 
    lab1_5/lab1_5_unit_test.cpp 
    lab1_5/Liquid.cpp
    lab1_5/Alcohol.cpp  # Виправлено з Alchol.cpp
)

# Визначаємо макрос UNIT_TESTING
target_compile_definitions(lab1_5_unit_test PRIVATE UNIT_TESTING)

# Додаємо заголовочні файли
target_include_directories(lab1_5_unit_test PRIVATE ${GTEST_INCLUDE_DIRS})

# Лінкуємо Google Test і pthread
target_link_libraries(lab1_5_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# Додаємо команду для запуску тестів
enable_testing()
add_test(NAME Lab1_5_UnitTests COMMAND lab1_5_unit_test)






cmake_minimum_required(VERSION 3.10)

project(lab1_6_unit_test)

# Використовуємо C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Підключаємо Google Test
find_package(GTest REQUIRED)

# Перевіряємо, чи знайшовся Google Test
if(NOT GTest_FOUND)
    message(FATAL_ERROR "Google Test not found! Install it or provide its path.")
endif()

# Додаємо вихідні файли (виправлено ім'я Alcohol.cpp)
add_executable(lab1_6_unit_test 
    lab1_6/lab1_6_unit_test.cpp 
    lab1_6/Alcohol.cpp  
)

# Визначаємо макрос UNIT_TESTING
target_compile_definitions(lab1_6_unit_test PRIVATE UNIT_TESTING)

# Додаємо заголовочні файли
target_include_directories(lab1_6_unit_test PRIVATE ${GTEST_INCLUDE_DIRS})

# Лінкуємо Google Test і pthread
target_link_libraries(lab1_6_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# Додаємо команду для запуску тестів
enable_testing()
add_test(NAME Lab1_6_UnitTests COMMAND lab1_6_unit_test)
