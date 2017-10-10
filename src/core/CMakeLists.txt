target_sources(Lightbridge
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/private/integrator.cpp"
		"${CMAKE_CURRENT_LIST_DIR}/private/scene.cpp"
		"${CMAKE_CURRENT_LIST_DIR}/private/sceneparser.cpp"
	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/public/integrator.h"
		"${CMAKE_CURRENT_LIST_DIR}/public/scene.h"
		"${CMAKE_CURRENT_LIST_DIR}/public/sceneparser.h"
)

# Adds this file to IDE source group, DO NOT MODIFY
target_sources(Lightbridge PUBLIC "${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt")