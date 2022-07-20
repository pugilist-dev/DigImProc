add_library(image image.cpp)

add_executable(bin_main main.cpp)

target_link_libraries(bin_main
						image)