SET (TARGET_NAME IoTService)

IF (WIN32)
	ADD_EXECUTABLE (${TARGET_NAME} main.cpp w32.cpp w32.h)
ELSE ()
	ADD_EXECUTABLE (${TARGET_NAME} main.cpp gnu.cpp gnu.h)
ENDIF ()
TARGET_INCLUDE_DIRECTORIES (${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
TARGET_LINK_LIBRARIES (${TARGET_NAME} PRIVATE ${Poco_LIBRARIES})

INSTALL (TARGETS ${TARGET_NAME})
