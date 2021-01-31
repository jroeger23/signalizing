add_executable(signalizing_test
  main.cpp
  signalizing/conv2d/core.cpp
)
target_link_libraries(signalizing_test PRIVATE signalizing Catch2::Catch2)
target_compile_features(signalizing_test PRIVATE cxx_std_20)

catch_discover_tests(signalizing_test)