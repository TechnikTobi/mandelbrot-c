cmake_minimum_required(VERSION 3.1) 

project(Mandelbrot)

exec_program(pkg-config ARGS --cflags glib-2.0 OUTPUT_VARIABLE GLIB_FLAGS)
exec_program(pkg-config ARGS --libs   glib-2.0 OUTPUT_VARIABLE GLIB_LIBS)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GLIB_FLAGS}") 

message(${CMAKE_C_FLAGS})

set(SOURCES
	src/mandelbrot_iteration_checker.c 
	src/cli.c
	src/main.c
	src/mandelbrot_iteration_checker.h
	src/cli.h
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC src/)

target_link_libraries(${PROJECT_NAME} ${GLIB_LIBS})
