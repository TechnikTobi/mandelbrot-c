cmake_minimum_required(VERSION 3.1) 

project(Mandelbrot LANGUAGES C)

# exec_program(pkg-config ARGS --cflags glib-2.0 OUTPUT_VARIABLE GLIB_FLAGS)
# exec_program(pkg-config ARGS --libs   glib-2.0 OUTPUT_VARIABLE GLIB_LIBS)
# exec_program(pkg-config ARGS --cflags libpng   OUTPUT_VARIABLE LIBPNG_FLAGS)
# exec_program(pkg-config ARGS --libs   libpng   OUTPUT_VARIABLE LIBPNG_LIBS)

find_package(PkgConfig REQUIRED)
# find_package(PNG REQUIRED)

pkg_search_module(GLIB REQUIRED glib-2.0)
pkg_search_module(PNG REQUIRED libpng)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GLIB_FLAGS} ${LIBPNG_FLAGS} -Xpreprocessor -fopenmp -O3 -I/usr/local/include") 
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GLIB_FLAGS} ${LIBPNG_FLAGS} -Xpreprocessor -O3") 

message(${CMAKE_C_FLAGS})

set(SOURCES
	src/mandelbrot_iteration_checker.c 
	src/generator.c
	src/cli.c
	src/color_map.c
	src/png_writer.c
	src/main.c
	src/mandelbrot_iteration_checker.h
	src/generator.h
	src/cli.h
	src/color_map.h
	src/png_writer.h
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC src/ ${GLIB_INCLUDE_DIRS} ${PNG_INCLUDE_DIRS})

#target_link_libraries(${PROJECT_NAME} ${GLIB_LIBS} ${LIBPNG_LIBS} "-lm")
target_link_libraries(${PROJECT_NAME} ${GLIB_LDFLAGS} ${PNG_LDFLAGS} "-lm")
