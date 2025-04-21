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




# # lab3_3_A
# project(lab3_3_A_unit_test)

# # Використовуємо C++17
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Підключаємо Google Test
# find_package(GTest REQUIRED)

# # Перевіряємо, чи знайшовся Google Test
# if(NOT GTest_FOUND)
#     message(FATAL_ERROR "Google Test not found! Install it or provide its path.")
# endif()

# add_executable(lab3_3_A_unit_test 
#     lab3_3_A/lab3_3_A_unit_test.cpp 
#     lab3_3_A/Money.cpp
#     lab3_3_A/MoneyPrivate.cpp 
#     lab3_3_A/MoneyPublic.cpp 
# )

# # Визначаємо макрос UNIT_TESTING
# target_compile_definitions(lab3_3_A_unit_test PRIVATE UNIT_TESTING)

# # Додаємо заголовочні файли
# target_include_directories(lab3_3_A_unit_test PRIVATE ${GTEST_INCLUDE_DIRS} lab3_3_A)

# # Лінкуємо Google Test і pthread
# target_link_libraries(lab3_3_A_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# # Додаємо команду для запуску тестів
# enable_testing()
# add_test(NAME Lab3_3_A_UnitTests COMMAND lab3_3_A_unit_test)




# # lab3_3_B
# project(lab3_3_B_unit_test)

# # Використовуємо C++17
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Підключаємо Google Test
# find_package(GTest REQUIRED)

# # Перевіряємо, чи знайшовся Google Test
# if(NOT GTest_FOUND)
#     message(FATAL_ERROR "Google Test not found! Install it or provide its path.")
# endif()

# add_executable(lab3_3_B_unit_test 
#     lab3_3_B/lab3_3_B_unit_test.cpp 
#     lab3_3_B/Money.cpp
#     lab3_3_B/Pair.cpp 
# )

# # Визначаємо макрос UNIT_TESTING
# target_compile_definitions(lab3_3_B_unit_test PRIVATE UNIT_TESTING)

# # Додаємо заголовочні файли
# target_include_directories(lab3_3_B_unit_test PRIVATE ${GTEST_INCLUDE_DIRS} lab3_3_B)

# # Лінкуємо Google Test і pthread
# target_link_libraries(lab3_3_B_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# # Додаємо команду для запуску тестів
# enable_testing()
# add_test(NAME Lab3_3_B_UnitTests COMMAND lab3_3_B_unit_test)



# # lab3_3_C
# project(lab3_3_C_unit_test)

# # Використовуємо C++17
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Підключаємо Google Test
# find_package(GTest REQUIRED)

# # Перевіряємо, чи знайшовся Google Test
# if(NOT GTest_FOUND)
#     message(FATAL_ERROR "Google Test not found! Install it or provide its path.")
# endif()

# add_executable(lab3_3_C_unit_test 
#     lab3_3_C/lab3_3_C_unit_test.cpp 
#     lab3_3_C/Money.cpp
#     lab3_3_C/Object.cpp 
# )

# # Визначаємо макрос UNIT_TESTING
# target_compile_definitions(lab3_3_C_unit_test PRIVATE UNIT_TESTING)

# # Додаємо заголовочні файли
# target_include_directories(lab3_3_C_unit_test PRIVATE ${GTEST_INCLUDE_DIRS} lab3_3_C)

# # Лінкуємо Google Test і pthread
# target_link_libraries(lab3_3_C_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# # Додаємо команду для запуску тестів
# enable_testing()
# add_test(NAME Lab3_3_C_UnitTests COMMAND lab3_3_C_unit_test)



# # lab3_3_D
# project(lab3_3_D_unit_test)

# # Використовуємо C++17
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Підключаємо Google Test
# find_package(GTest REQUIRED)

# # Перевіряємо, чи знайшовся Google Test
# if(NOT GTest_FOUND)
#     message(FATAL_ERROR "Google Test not found! Install it or provide its path.")
# endif()

# add_executable(lab3_3_D_unit_test 
#     lab3_3_D/lab3_3_D_unit_test.cpp 
#     lab3_3_D/Liquid.cpp
#     lab3_3_D/AlcoholPublic.cpp 
#     lab3_3_D/AlcoholPrivate.cpp
# )

# # Визначаємо макрос UNIT_TESTING
# target_compile_definitions(lab3_3_D_unit_test PRIVATE UNIT_TESTING)

# # Додаємо заголовочні файли
# target_include_directories(lab3_3_D_unit_test PRIVATE ${GTEST_INCLUDE_DIRS} lab3_3_D)

# # Лінкуємо Google Test і pthread
# target_link_libraries(lab3_3_D_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# # Додаємо команду для запуску тестів
# enable_testing()
# add_test(NAME Lab3_3_D_UnitTests COMMAND lab3_3_D_unit_test)





# # lab3_3_E
# project(lab3_3_E_unit_test)

# # Використовуємо C++17
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Підключаємо Google Test
# find_package(GTest REQUIRED)

# # Перевіряємо, чи знайшовся Google Test
# if(NOT GTest_FOUND)
#     message(FATAL_ERROR "Google Test not found! Install it or provide its path.")
# endif()

# add_executable(lab3_3_E_unit_test 
#     lab3_3_E/lab3_3_E_unit_test.cpp 
#     lab3_3_E/Liquid.cpp
#     lab3_3_E/Alcohol.cpp 
#     lab3_3_E/Object.cpp
# )

# # Визначаємо макрос UNIT_TESTING
# target_compile_definitions(lab3_3_E_unit_test PRIVATE UNIT_TESTING)

# # Додаємо заголовочні файли
# target_include_directories(lab3_3_E_unit_test PRIVATE ${GTEST_INCLUDE_DIRS} lab3_3_E)

# # Лінкуємо Google Test і pthread
# target_link_libraries(lab3_3_E_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# # Додаємо команду для запуску тестів
# enable_testing()
# add_test(NAME Lab3_3_E_UnitTests COMMAND lab3_3_E_unit_test)



# lab3_6
project(lab3_6_unit_test)

# Використовуємо C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Підключаємо Google Test
find_package(GTest REQUIRED)

# Перевіряємо, чи знайшовся Google Test
if(NOT GTest_FOUND)
    message(FATAL_ERROR "Google Test not found! Install it or provide its path.")
endif()

add_executable(lab3_6_unit_test 
    lab3_6/lab3_6_unit_test.cpp 
    lab3_6/B.cpp 
    lab3_6/D1.cpp 
    lab3_6/D2.cpp
    lab3_6/D3.cpp
    lab3_6/D4.cpp
)

# Визначаємо макрос UNIT_TESTING
target_compile_definitions(lab3_6_unit_test PRIVATE UNIT_TESTING)

# Додаємо заголовочні файли
target_include_directories(lab3_6_unit_test PRIVATE ${GTEST_INCLUDE_DIRS} lab3_6)

# Лінкуємо Google Test і pthread
target_link_libraries(lab3_6_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# Додаємо команду для запуску тестів
enable_testing()
add_test(NAME Lab3_6_UnitTests COMMAND lab3_6_unit_test)



