cmake_minimum_required(VERSION 3.17)
project(11_TutCMake3)
set(CMAKE_CXX_STANDARD 11)
add_executable(ejecutable main.cpp)

# configure_file(${CMAKE_CURRENT_LIST_DIR}/config/config.json ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_custom_command(TARGET ejecutable POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy 
    ${CMAKE_CURRENT_LIST_DIR}/config/config.json 
    ${CMAKE_CURRENT_BINARY_DIR}
)

install(TARGETS ejecutable 
    RUNTIME DESTINATION bin 
    LIBRARY DESTINATION lib
)

install(FILES ${CMAKE_CURRENT_LIST_DIR}/config/config.json 
    DESTINATION bin/config
)

install(PROGRAMS ${CMAKE_CURRENT_LIST_DIR}/scripts/launcher.bat
    DESTINATION bin
)

