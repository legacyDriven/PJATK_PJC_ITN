cmake_minimum_required(VERSION 3.24)
project(Sniezko)

set(CMAKE_CXX_STANDARD 17)
#add_executable(Sniezko TaskOne.cpp Sniezko.cpp)

add_executable(Sniezko zad2/TaskTwo.cpp zad3/TaskThree.cpp zad1/TaskOne.cpp zad4/TaskFour.cpp zad5/TaskFive.cpp zad6/TaskSix.cpp zad10/TaskTen.cpp)

# Macro to define language options
macro(define_language_option LANG_NAME)
    target_compile_definitions(Sniezko PRIVATE ${LANG_NAME})
endmacro()
#define_language_option(ENG)  # Set the language to English

define_language_option(POL)  # Set the language to Polish
