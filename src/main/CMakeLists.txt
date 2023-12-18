set(TARGET ${CMAKE_PROJECT_NAME})

set(SOURCES
    main.cpp
)

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE ${SOURCES})
