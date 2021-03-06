FUNCTION (POCO_COMPILE_PAGES)

	CMAKE_PARSE_ARGUMENTS (PCOMP "" "PATH" "" ${ARGN})

	FILE (GLOB PAGECOMP_FILES ${CMAKE_BINARY_DIR}/bin/cpspc*)
	IF (NOT EXISTS ${PAGECOMP_FILES})
		SET (Poco_PCOMP_DIRECTORY "Utility/PageCompiler")
		EXECUTE_PROCESS (COMMAND ${CMAKE_COMMAND} --config "Release" .
			-G "${CMAKE_GENERATOR}"
			-B "${CMAKE_BINARY_DIR}/${Poco_PCOMP_DIRECTORY}"
			WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/${Poco_PCOMP_DIRECTORY}
		)
		EXECUTE_PROCESS (COMMAND ${CMAKE_COMMAND} --build . WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/${Poco_PCOMP_DIRECTORY})
	ENDIF ()
	
	FILE (GLOB_RECURSE TRASH_FILES ${CMAKE_SOURCE_DIR}/${PCOMP_PATH}/*.cpp ${CMAKE_SOURCE_DIR}/${PCOMP_PATH}/*.h)
	IF (TRASH_FILES)
		FILE (REMOVE ${TRASH_FILES})
	ENDIF ()

	FILE (GLOB_RECURSE PAGE_SOURCE_FILES ${CMAKE_SOURCE_DIR}/${PCOMP_PATH}/*.cpsp RELATIVE ${CMAKE_SOURCE_DIR}/${PCOMP_PATH} ${CMAKE_BINARY_DIR})
	LIST (FILTER PAGE_SOURCE_FILES EXCLUDE REGEX "[_]")
	FOREACH (PAGE_SOURCE_FILE_IN ${PAGE_SOURCE_FILES})
		FILE (RELATIVE_PATH PAGE_SOURCE_FILE_IN_REL ${CMAKE_CURRENT_SOURCE_DIR} ${PAGE_SOURCE_FILE_IN})
		STRING (REPLACE ".in" "" PAGE_SOURCE_FILE ${PAGE_SOURCE_FILE_IN_REL})
		EXECUTE_PROCESS (COMMAND ${CMAKE_BINARY_DIR}/bin/cpspc ${PAGE_SOURCE_FILE_IN})
	ENDFOREACH ()

ENDFUNCTION ()