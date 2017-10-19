include(${CMAKE_CURRENT_LIST_DIR}/core/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/integrators/CMakeLists.txt)

include_directories("${CMAKE_CURRENT_LIST_DIR}/core/public")
include_directories("${CMAKE_CURRENT_LIST_DIR}/integrators/public")

# Adds this file to IDE source group, DO NOT MODIFY
target_sources(Lightbridge PUBLIC "${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt")