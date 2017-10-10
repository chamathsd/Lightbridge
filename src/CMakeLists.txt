include(${CMAKE_CURRENT_LIST_DIR}/core/CMakeLists.txt)

include_directories("${CMAKE_CURRENT_LIST_DIR}/core/public")

# Adds this file to IDE source group, DO NOT MODIFY
target_sources(Lightbridge PUBLIC "${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt")