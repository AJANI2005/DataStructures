cmake_minimum_required(VERSION 3.10)
project(wxWidgetsApp)

# Find wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base)

# Enable necessary include/linking options
include(${wxWidgets_USE_FILE})

# Add executable
add_executable(wxApp main.cpp)

# Link wxWidgets libraries
target_link_libraries(wxApp PRIVATE ${wxWidgets_LIBRARIES})

