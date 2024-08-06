set(testCifrasSignificativas_1_SRCS
    testCifrasSignificativas_1.cpp
)

set(testCifrasSignificativas_2_SRCS
    testCifrasSignificativas_2.cpp
)

add_executable(testCifrasSignificativas_1 ${testCifrasSignificativas_1_SRCS})
add_executable(testCifrasSignificativas_2 ${testCifrasSignificativas_2_SRCS})

target_compile_options(testCifrasSignificativas_1 PRIVATE -fexceptions -Woverloaded-virtual)
target_compile_options(testCifrasSignificativas_2 PRIVATE -fexceptions -Woverloaded-virtual)
