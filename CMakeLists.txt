cmake_minimum_required(VERSION 3.2)

project(MyApp)

add_executable(App UserInterface.cpp)

add_library(mylib Car.h Car.cpp Database.h Database.cpp)

target_link_Libraries(App PRIVATE mylib)

