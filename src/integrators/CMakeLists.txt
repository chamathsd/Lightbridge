target_sources(Lightbridge
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/private/whitted.cpp"
	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/public/whitted.h"
)

# Adds this file to IDE source group, DO NOT MODIFY
target_sources(Lightbridge PUBLIC "${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt")