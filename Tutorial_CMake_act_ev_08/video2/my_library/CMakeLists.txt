add_library(my_library SHARED my_library.h my_library.cpp)

target_include_directories(my_library PUBLIC ${CMAKE_CURRENT_LIST_DIR})