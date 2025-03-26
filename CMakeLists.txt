cmake_minimum_required(VERSION 3.16)
project(passwordgen LANGUAGES CXX)

 
find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()
add_executable(passwordgen passwordgen.cpp)
target_link_libraries(passwordgen ${wxWidgets_LIBRARIES})