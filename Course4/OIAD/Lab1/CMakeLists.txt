SET (TARGET_NAME Lab1)

FILE (GLOB SOURCE_FILES *.cpp)
FILE (GLOB HEADER_FILES *.h)

ADD_EXECUTABLE (${TARGET_NAME} ${SOURCE_FILES} ${HEADER_FILES})

FILE (GLOB TEXT_FILES data/*.txt)
FILE (COPY ${TEXT_FILES} DESTINATION ${CMAKE_RESOURCE_OUTPUT_DIRECTORY})
