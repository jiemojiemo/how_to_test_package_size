cmake -DCMAKE_TOOLCHAIN_FILE="cmake/ios.toolchain.cmake" \
      -DARCHS="armv7;arm64" \
      -S . -B ios_build

cmake --build ios_build -- -j 10