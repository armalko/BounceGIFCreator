cmake_minimum_required(VERSION 3.17)
project(2d_graphics)

set(CMAKE_CXX_STANDARD             20)
set(CMAKE_MODULE_PATH              "${CMAKE_SOURCE_DIR}/tools/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS  ON)
set(CMAKE_CXX_STANDARD 20)

find_package(PNG)

set(Clang_DIR "/usr/lib/llvm-16/lib/cmake/clang")
set(LLVM_DIR "/usr/lib/llvm-16/lib/cmake/llvm")

add_executable(2d_graphics main.cpp vector.cpp vector.h point.cpp point.h image.cpp image.h screen.cpp screen.h triange.cpp triange.h computer.cpp computer.h geometry.cpp geometry.h)

set(CMAKE_PREFIX_PATH "/usr/local/Cellar/imagemagick/7.1.1-21/")
set(CMAKE_CXX_FLAGS "-Xpreprocessor -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_CHANNEL_MASK_DEPTH=32 -DMAGICKCORE_QUANTUM_DEPTH=16 -Xpreprocessor -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_CHANNEL_MASK_DEPTH=32 -DMAGICKCORE_QUANTUM_DEPTH=16 -Xpreprocessor -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_CHANNEL_MASK_DEPTH=32 -DMAGICKCORE_QUANTUM_DEPTH=16 -I/usr/local/Cellar/imagemagick/7.1.1-21/include/ImageMagick-7 -Xpreprocessor -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_CHANNEL_MASK_DEPTH=32 -DMAGICKCORE_QUANTUM_DEPTH=16 -Xpreprocessor -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_CHANNEL_MASK_DEPTH=32 -DMAGICKCORE_QUANTUM_DEPTH=16 -Xpreprocessor -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_CHANNEL_MASK_DEPTH=32 -DMAGICKCORE_QUANTUM_DEPTH=16 -I/usr/local/Cellar/imagemagick/7.1.1-21/include/ImageMagick-7")
set(CMAKE_LINK_DEF_FILE_FLAG "-Xpreprocessor -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_CHANNEL_MASK_DEPTH=32 -DMAGICKCORE_QUANTUM_DEPTH=16 -Xpreprocessor -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_CHANNEL_MASK_DEPTH=32 -DMAGICKCORE_QUANTUM_DEPTH=16 -Xpreprocessor -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_CHANNEL_MASK_DEPTH=32 -DMAGICKCORE_QUANTUM_DEPTH=16 -I/usr/local/Cellar/imagemagick/7.1.1-21/include/ImageMagick-7 -Xpreprocessor -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_CHANNEL_MASK_DEPTH=32 -DMAGICKCORE_QUANTUM_DEPTH=16 -Xpreprocessor -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_CHANNEL_MASK_DEPTH=32 -DMAGICKCORE_QUANTUM_DEPTH=16 -Xpreprocessor -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_CHANNEL_MASK_DEPTH=32 -DMAGICKCORE_QUANTUM_DEPTH=16 -I/usr/local/Cellar/imagemagick/7.1.1-21/include/ImageMagick-7")
find_package(ImageMagick COMPONENTS Magick++ REQUIRED)
target_include_directories(2d_graphics PRIVATE ${ImageMagick_INCLUDE_DIRS})
target_link_libraries(2d_graphics ${ImageMagick_LIBRARIES} ${PNG_LIBRARY})

target_include_directories(2d_graphics PRIVATE ${PNG_INCLUDE_DIRS})

