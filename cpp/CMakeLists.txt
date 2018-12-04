cmake_minimum_required(VERSION 3.0.0)
project(aoc VERSION 0.1.0)

set_property(GLOBAL PROPERTY CXX_STANDARD 17)

MACRO(SUBDIRLIST result curdir prefix)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/${prefix}*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_LIST_DIR} "day_")

FOREACH(subdir ${SUBDIRS})
  ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()