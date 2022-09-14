cmake_minimum_required(VERSION 3.9) 

project(Mandelbrot LANGUAGES C)

find_package(PkgConfig REQUIRED)
find_package(OpenMP REQUIRED)

pkg_search_module(PNG REQUIRED libpng)
# pkg_search_module(GLIB REQUIRED glib-2.0)
pkg_search_module(GLIB REQUIRED mingw-w64-x86_64-glib2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Xpreprocessor -O3") 

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

# See: https://cliutils.gitlab.io/modern-cmake/chapters/packages/OpenMP.html
target_link_libraries(${PROJECT_NAME} ${GLIB_LDFLAGS} ${PNG_LDFLAGS} OpenMP::OpenMP_C "-lm")
