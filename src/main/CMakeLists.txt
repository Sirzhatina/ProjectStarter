set(TARGET ${CMAKE_PROJECT_NAME})

set(SOURCES
    CmdParser.ixx
    main.cpp
    ProjMaker.ixx
    utility.ixx
)

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE ${SOURCES})
