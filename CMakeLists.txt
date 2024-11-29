cmake_minimum_required(VERSION 2.8.12)

project(ErrorCorrectionCoding)

# ==================== COMPILE OPTIONS ==================== #

add_compile_options(
  "-O3"
  "$<$<CONFIG:DEBUG>:-Wall;-Werror;-fsanitize=address;-O0;-g;-ggdb>"
)
add_link_options("$<$<CONFIG:DEBUG>:-fsanitize=address>")

# ==================== INCLUDE ==================== #

include_directories(${CMAKE_SOURCE_DIR}/inc)

# ==================== SOURCE ==================== #

add_library(field STATIC src/common/field.c)
add_library(bch STATIC src/bch/bch.c)
add_library(golay_24_12_8 STATIC src/golay/golay_24_12_8.c)

# ==================== TEST ==================== #

enable_testing()

add_executable(test_field test/test_field.c)
target_link_libraries(test_field PRIVATE field)
add_test(
  NAME test_field
  COMMAND test_field
)

add_executable(test_bch test/test_bch.c)
target_link_libraries(test_bch PRIVATE field bch)
add_test(
  NAME test_bch
  COMMAND test_bch
)

add_executable(test_overall_golay_24_12_8 test/test_overall.c)
target_link_libraries(test_overall_golay_24_12_8 PRIVATE golay_24_12_8)
add_test(
  NAME test_overall_golay_24_12_8
  COMMAND test_overall_golay_24_12_8 "2"
)

add_executable(test_rand_golay_24_12_8 test/test_rand.c)
target_link_libraries(test_rand_golay_24_12_8 PRIVATE golay_24_12_8)
add_test(
  NAME test_rand_golay_24_12_8
  COMMAND test_rand_golay_24_12_8 "3" "100" "100"
)