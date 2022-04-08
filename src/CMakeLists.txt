cmake_minimum_required(VERSION 3.13)
project(markov_text_gen)

add_executable(markov_text_gen main.cpp)

if(MSVC)
  target_compile_options(markov_text_gen PRIVATE /W4 /WX)
else()
  target_compile_options(markov_text_gen PRIVATE -Wall -Wextra -Wpedantic)
endif()