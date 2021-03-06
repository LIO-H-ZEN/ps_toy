# Copyright (c) 2008-2010 High Performance Computing Center Stuttgart, 
#                         University of Stuttgart.  All rights reserved.
# $COPYRIGHT$
# 
# Additional copyrights may follow
# 
# $HEADER$
#

FILE(GLOB OMPI_F77_FILES "*.c")
FILE(GLOB OMPI_F77_HEADER_FILES "*.h")

# Remove all MPI_File related files if the option is not selected
IF (NOT OMPI_PROVIDE_MPI_FILE_INTERFACE)
  MESSAGE( STATUS "Skipping the MPI I/O interface")
  SET( TMP_SRC "" )
  FOREACH ( FILENAME ${OMPI_F77_FILES})
    GET_FILENAME_COMPONENT(relname ${FILENAME} NAME)
    IF (NOT ${relname} MATCHES "file.*[ch]$")
      IF (NOT ${relname} STREQUAL "register_datarep.c")
        LIST(APPEND TMP_SRC ${FILENAME})
      ENDIF (NOT ${relname} STREQUAL "register_datarep.c")
    ENDIF(NOT ${relname} MATCHES "file.*[ch]$")
  ENDFOREACH(FILENAME ${OMPI_F77_FILES})
  SET( OMPI_F77_FILES ${TMP_SRC})
ENDIF(NOT OMPI_PROVIDE_MPI_FILE_INTERFACE)

SET_SOURCE_FILES_PROPERTIES(${OMPI_F77_FILES} PROPERTIES
  COMPILE_FLAGS "-DOMPI_PROFILE_LAYER=0 -DOMPI_COMPILING_F77_WRAPPERS=1")

IF(OMPI_ENABLE_MPI_PROFILING)
  # As weak symbols are not supported by MS compiler,
  # we have to compile the C source files again for profiler,
  # i.e. add the pre-processor "OMPI_PROFILING_DEFINES" explicitly.
  
  # copy the files to the build directory with a prefix.
  FOREACH(FILE_NAME ${OMPI_F77_FILES})
    GET_FILENAME_COMPONENT(relname ${FILE_NAME} NAME)
    CONFIGURE_FILE(${FILE_NAME}
                   ${PROJECT_BINARY_DIR}/profile/p${relname} [COPYONLY])
  ENDFOREACH(FILE_NAME ${OMPI_F77_FILES})

  FILE(GLOB OMPI_F77_PROFILE_FILES "${PROJECT_BINARY_DIR}/profile/*.c" )

  SET_SOURCE_FILES_PROPERTIES(${OMPI_F77_PROFILE_FILES} PROPERTIES 
    COMPILE_FLAGS "-DOMPI_PROFILE_LAYER=1 -DOMPI_COMPILING_F77_WRAPPERS=1")

  SET(OMPI_F77_FILES ${OMPI_F77_FILES} ${OMPI_F77_PROFILE_FILES})
  SOURCE_GROUP(profile FILES  ${OMPI_F77_PROFILE_FILES})

ELSE(OMPI_ENABLE_MPI_PROFILING)
  MESSAGE( STATUS "Skipping the MPI profiling interface")
ENDIF(OMPI_ENABLE_MPI_PROFILING)


ADD_LIBRARY(libmpi_f77 STATIC ${OMPI_F77_FILES} ${OMPI_F77_HEADER_FILES})
SET_TARGET_PROPERTIES(libmpi_f77 PROPERTIES LINKER_LANGUAGE CXX)
TARGET_LINK_LIBRARIES(libmpi_f77 libmpi)

INSTALL(TARGETS libmpi_f77
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
