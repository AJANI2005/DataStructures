cmake_minimum_required(VERSION 3.10)
project(wxWidgetsApp)

# Enable compilation database for LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base)

# Enable necessary include/linking options
include(${wxWidgets_USE_FILE})

# Add include directory for header files
include_directories(${CMAKE_SOURCE_DIR})

# Add executable
add_executable(wxApp main.cpp)

# Define UTF-8 support
target_compile_definitions(wxApp PRIVATE wxUSE_UNICODE_UTF8=1)

# Link wxWidgets libraries
target_link_libraries(wxApp PRIVATE ${wxWidgets_LIBRARIES})

