add_library(simple_decoder simple_decoder.cpp)
target_include_directories(simple_decoder
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include
        PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/dr_libs)

if(ANDROID)
    set(VERSION_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/versionscript")
    target_link_options(simple_decoder
            PRIVATE
            -Wl,--version-script=${VERSION_SCRIPT})
endif()
