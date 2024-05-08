cmake_minimum_required(VERSION 3.5)

project(icp24)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(Qt5_DIR /opt/homebrew/Cellar/qt@5/5.15.13_1/lib/cmake/Qt5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable all warnings
add_compile_options(-Wall)

# Treat warnings as errors
add_compile_options(-Werror)

# Enable pedantic mode
add_compile_options(-pedantic)
# Find the Qt libraries
find_package(Qt5 COMPONENTS Core Widgets Network REQUIRED)

# Add source files
set(SOURCE_FILES
  src/ARobot.cpp
  src/barrierC.cpp
  src/editController.cpp
  src/gameButton.cpp  # Include gameButton.cpp
  src/RCRobot.cpp
  src/robot.cpp
  src/window.cpp
  src/main.cpp
  header/ARobot.h
  header/barrierC.h
  header/editController.h
  header/gameButton.h
  header/RCRobot.h
  header/robot.h
  header/window.h
)

# Tell CMake to create the executable
add_executable(icp24 ${SOURCE_FILES})

# Link Qt libraries
target_link_libraries(icp24 Qt5::Core Qt5::Widgets Qt5::Network)
