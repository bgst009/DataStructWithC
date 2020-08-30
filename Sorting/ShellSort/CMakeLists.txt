cmake_minimum_required(VERSION 3.17)

project(ShellSort)

SET(SRC_DIR TestShellSort.c ShellShort.h ShellShort.c  Helper.h header.h)

add_executable(ShellSort ${SRC_DIR})