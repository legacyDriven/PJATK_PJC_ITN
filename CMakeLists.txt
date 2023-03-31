cmake_minimum_required(VERSION 3.24)
project(Sniezko)

set(CMAKE_CXX_STANDARD 17)
#add_executable(Sniezko TaskOne.cpp Sniezko.cpp)

add_executable(Sniezko TaskTwo.cpp Sniezko.cpp)

# Macro to define language options
macro(define_language_option LANG_NAME)
    target_compile_definitions(Sniezko PRIVATE ${LANG_NAME})
endmacro()
#define_language_option(ENG)  # Set the language to English

define_language_option(POL)  # Set the language to Polish
