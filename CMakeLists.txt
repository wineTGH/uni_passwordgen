cmake_minimum_required(VERSION 3.5)
project(PasswordGenerator)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find wxWidgets package
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Set source files
set(SOURCES
    src/passwordgen_app.cpp
    src/passwordgen_frame.cpp
    src/passwordgen.cpp
)

# Set headers
set(HEADERS
    src/passwordgen_app.h
    src/passwordgen_frame.h
    src/passwordgen.h
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link wxWidgets libraries
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

# Set include directories
target_include_directories(${PROJECT_NAME} PRIVATE src)