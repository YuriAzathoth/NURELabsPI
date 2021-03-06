# -*- cmake -*-

# - Find Apache Runtime
# Find the APACHE includes and libraries
# This module defines
#  APACHE_INCLUDE_DIR and APACHEUTIL_INCLUDE_DIR, where to find APACHE.h, etc.
#  APACHE_LIBRARIES and APACHEUTIL_LIBRARIES, the libraries needed to use APACHE.
#  APACHE_FOUND and APACHEUTIL_FOUND, If false, do not try to use APACHE.
# also defined, but not for general use are
#  APACHE_LIBRARY and APACHEUTIL_LIBRARY, where to find the APACHE library.

FIND_PATH(APACHE_INCLUDE_DIR httpd.h
/usr/local/include/apache2
/usr/include/apache2
)

SET(APACHE_NAMES ${APR_NAMES} httpd-1)
FIND_LIBRARY(APACHE_LIBRARY
  NAMES ${APR_NAMES}
  PATHS /usr/lib /usr/local/lib
  )

IF (APACHE_INCLUDE_DIR AND APACHE_LIBRARY)
    SET(APACHE_FOUND "YES")
ELSE (APACHE_INCLUDE_DIR AND APACHE_LIBRARY)
  SET(APACHE_FOUND "NO")
ENDIF (APACHE_INCLUDE_DIR AND APACHE_LIBRARY)


IF (APACHE_FOUND)
      MESSAGE(STATUS "Found APACHE: ${APACHE_INCLUDE_DIR}")
ENDIF (APACHE_FOUND)

MARK_AS_ADVANCED(
  APACHE_INCLUDE_DIR
  )

