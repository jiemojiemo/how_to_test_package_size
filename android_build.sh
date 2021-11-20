ANDROID_NDK_HOME=/Users/bytedance/android-ndk-r21e

cmake -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake \
      -DANDROID_ABI=arm64-v8a \
      -DBUILD_SHARED_LIBS=ON \
      -S . -B android_64_build

cmake --build android_64_build -- -j 10
