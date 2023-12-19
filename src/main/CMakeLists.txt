set(TARGET ${CMAKE_PROJECT_NAME})

set(SOURCES
    App.hpp
    main.cpp
    ProjectVariables.hpp
)

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE ${SOURCES})

target_link_libraries(${TARGET} PRIVATE cxxopts::cxxopts)

configure_file(${CMAKE_SOURCE_DIR}/About.h.in About.h @ONLY)
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})