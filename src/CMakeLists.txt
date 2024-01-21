set(HEADERS plotting.h
)

set(SOURCES main.cpp
            plotting.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC matplot)
