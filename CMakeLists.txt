project(ProjectName)
set(CMAKE_CXX_STANDARD 17)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES BOJ/Solutions/main.cpp)
# Add executable target with source files listed in SOURCE_FILES variable

message($FileNameWithoutExtension)
add_executable(main BOJ/Solutions/main.cpp)
add_executable(BOJ_Solutions_main BOJ/Solutions/main.cpp)