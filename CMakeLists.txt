cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(Lightbridge)

add_executable(Lightbridge src/system/private/lightbridge.cpp)

include(src/CMakeLists.txt)

macro(GroupSources curdir)
    file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir} ${PROJECT_SOURCE_DIR}/${curdir}/*)
    foreach(child ${children})
	    if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
    	    GroupSources(${curdir}/${child})
        else()
			string(REPLACE "/" "\\" groupname ${curdir})
			string(REPLACE "src" "Source" groupname ${groupname})
			source_group(${groupname} FILES ${PROJECT_SOURCE_DIR}/${curdir}/${child})
		endif()
	endforeach()
endmacro()

# Execute the macro
GroupSources(src)