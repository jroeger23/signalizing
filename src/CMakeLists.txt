add_library(signalizing STATIC
  stub.cpp
)

target_include_directories(signalizing PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)

target_compile_features(signalizing PUBLIC cxx_std_20)