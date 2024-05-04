cmake_minimum_required(VERSION 3.5)

project(icp24)

set(Qt5_DIR /opt/homebrew/Cellar/qt@5/5.15.13_1/lib/cmake/Qt5)

# Find the Qt libraries
find_package(Qt5 COMPONENTS Core Widgets Network REQUIRED)

# Add header files directory
include_directories(header)

# Add source files
set(SOURCE_FILES
    src/main.cpp
    src/ARobot.cpp
    src/backend.cpp
    src/barrierC.cpp
    src/editcontroler.cpp
    src/gameButton.cpp
    src/RCRobot.cpp
    src/robot.cpp
    src/window.cpp
)

# Tell CMake to create the executable
add_executable(icp24 ${SOURCE_FILES})

# Link Qt libraries
target_link_libraries(icp24 Qt5::Core Qt5::Widgets Qt5::Network)
