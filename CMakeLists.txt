cmake_minimum_required(VERSION 3.1) 

project(Mandelbrot)

set(SOURCES
	src/mandelbrot_iteration_checker.c 
	src/main.c
	src/mandelbrot_iteration_checker.h
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC src/)
