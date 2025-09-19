cmake_minimum_required(VERSION 4.0)
project(PleaseCrash)

set(CMAKE_CXX_STANDARD 20)

set(MSDF_ATLAS_BUILD_STANDALONE OFF)
set(MSDF_ATLAS_USE_VCPKG OFF)
set(MSDF_ATLAS_USE_SKIA OFF)
set(MSDF_ATLAS_INSTALL ON)
set(BUILD_SHARED_LIBS ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fsanitize=address")
#set(CMAKE_LINK_FLAGS "${CMAKE_LINK_FLAGS} /fsanitize=address")
add_subdirectory("include/msdf-atlas-gen")

add_executable(PleaseCrash main.cpp)

#target_compile_options(${PROJECT_NAME} PRIVATE /fsanitize=address)
#target_link_libraries(${PROJECT_NAME} PRIVATE
#        clang_rt.asan_dynamic-x86_64
#        clang_rt.asan_dynamic_runtime_thunk-x86_64
#)
#target_link_options(${PROJECT_NAME} PRIVATE /wholearchive:clang_rt.asan_dynamic_runtime_thunk-x86_64.lib)

get_filename_component(CLANG_DIR "${CMAKE_CXX_COMPILER}" DIRECTORY)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CLANG_DIR}/clang_rt.asan_dynamic-x86_64.dll"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

find_package(Freetype REQUIRED)
target_link_libraries(PleaseCrash PRIVATE Freetype::Freetype msdfgen::msdfgen msdfgen::msdfgen-ext msdfgen::msdfgen-core msdf-atlas-gen::msdf-atlas-gen)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_BINARY_DIR}/include/msdf-atlas-gen/msdf-atlas-gen.dll"  # adjust to where your DLL actually is
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_BINARY_DIR}/include/msdf-atlas-gen/msdf-atlas-gen.pdb"  # adjust to where your DLL actually is
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_BINARY_DIR}/include/msdf-atlas-gen/msdfgen/brotlicommon.dll"  # adjust to where your DLL actually is
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_BINARY_DIR}/include/msdf-atlas-gen/msdfgen/brotlidec.dll"  # adjust to where your DLL actually is
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_BINARY_DIR}/include/msdf-atlas-gen/msdfgen/bz2d.dll"  # adjust to where your DLL actually is
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_BINARY_DIR}/include/msdf-atlas-gen/msdfgen/freetyped.dll"  # adjust to where your DLL actually is
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_BINARY_DIR}/include/msdf-atlas-gen/msdfgen/libpng16d.dll"  # adjust to where your DLL actually is
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_BINARY_DIR}/include/msdf-atlas-gen/msdfgen/msdfgen-core.dll"  # adjust to where your DLL actually is
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_BINARY_DIR}/include/msdf-atlas-gen/msdfgen/msdfgen-core.pdb"  # adjust to where your DLL actually is
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_BINARY_DIR}/include/msdf-atlas-gen/msdfgen/msdfgen-ext.dll"  # adjust to where your DLL actually is
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_BINARY_DIR}/include/msdf-atlas-gen/msdfgen/msdfgen-ext.pdb"  # adjust to where your DLL actually is
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_BINARY_DIR}/include/msdf-atlas-gen/msdfgen/zlibd1.dll"  # adjust to where your DLL actually is
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)