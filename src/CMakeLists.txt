set(HEADERS plotting.h
            DouglasPeucker.h
            Point.h
)

set(SOURCES main.cpp
            plotting.cpp
            DouglasPeucker.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC matplot)
