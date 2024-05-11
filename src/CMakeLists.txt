add_library (
    willdb
    schema.h
    schema.cpp
    value.h
)

add_executable(
    entry
    entrypoint.cpp
)

target_link_libraries(
    entry
    willdb
)