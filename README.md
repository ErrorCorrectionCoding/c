# ErrorCorrectionCoding - C

## Usage

Read "CMakeLists.txt".

## Develop

1. Implement the methods declared in `inc/template.h` in `src/YOUR_FILE_NAME.c`. Refer to `golay_24_12_8.c` for an example.
2. Add tests in CMakeLists.txt.

```cmake
# minor computation
# test all scenarios

add_executable(${NAME} test/test_overall.c)
target_link_libraries(${NAME} PRIVATE ${SRC})
add_test(
  NAME ${NAME}
  COMMAND ${NAME} "NUMBER_OF_ERRORS"
)

# extensive computation
# test random scenarios

add_executable(${NAME} test/test_rand.c)
target_link_libraries(${NAME} PRIVATE ${SRC})
add_test(
  NAME ${NAME}
  COMMAND ${NAME} "NUMBER_OF_ERRORS" "TIMES_OF_SIM_MESSAGE" "TIMES_OF_SIM_ERRORS"
)
```