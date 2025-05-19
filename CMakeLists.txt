cmake_minimum_required(VERSION 3.10)
project(PhysicEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==== USER-DEFINED PATHS ====
# Replace these with your actual paths
set(GLFW_INCLUDE_DIR "C:/Users/Professionel/Desktop/Libraries/glfw-3.4.bin.WIN64/include")
set(GLFW_LIB_DIR     "C:/Users/Professionel/Desktop/Libraries/glfw-3.4.bin.WIN64/lib-mingw-w64")
set(GLM_INCLUDE_DIR  "C:/Users/Professionel/Desktop/Libraries/glm-1.0.1/glm")
set(VULKAN_INCLUDE_DIR "D:/Vulkan/Include")
set(VULKAN_LIB_DIR     "D:/Vulkan/Lib")
set(SHADERS_BUILD_FOLDER "build/shaders")
set(SHADERS_FOLDER "shaders/")
set(GLSL_COMPILER "D:/Vulkan/Bin/glslc.exe")

# ==== INCLUDE DIRECTORIES ====
include_directories(
    ${GLFW_INCLUDE_DIR}
    ${GLM_INCLUDE_DIR}
    ${VULKAN_INCLUDE_DIR}
    include
    src
)



file(GLOB_RECURSE SOURCES
    include/Engine/*.hpp
    include/Meshes/*.hpp
    include/Objects/*.hpp
    src/Engine/*.cpp
    src/Meshes/*.cpp
    src/Objects/*.cpp
)

# ==== TARGET ====
add_executable(PhysicEngine ${SOURCES})

# ==== LINK DIRECTORIES ====
target_link_directories(PhysicEngine PRIVATE
    ${GLFW_LIB_DIR}
    ${VULKAN_LIB_DIR}
)

execute_process(
    COMMAND ${GLSL_COMPILER} ${SHADERS_FOLDER}/shader.vert -o ${SHADERS_BUILD_FOLDER}/vert.spv
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    RESULT_VARIABLE GLSLC_RESULT
    OUTPUT_VARIABLE GLSLC_OUTPUT
    ERROR_VARIABLE GLSLC_ERROR
)

execute_process(
    COMMAND ${GLSL_COMPILER} ${SHADERS_FOLDER}/shader.frag -o ${SHADERS_BUILD_FOLDER}/frag.spv
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    RESULT_VARIABLE GLSLC_RESULT
    OUTPUT_VARIABLE GLSLC_OUTPUT
    ERROR_VARIABLE GLSLC_ERROR
)

# ==== LINK LIBRARIES ====
# You may need to adjust the exact Vulkan library name based on your platform
if(WIN32)
    target_link_libraries(PhysicEngine PRIVATE glfw3 vulkan-1)
elseif(APPLE)
    target_link_libraries(PhysicEngine PRIVATE glfw vulkan)
else()
    target_link_libraries(PhysicEngine PRIVATE glfw vulkan)
endif()