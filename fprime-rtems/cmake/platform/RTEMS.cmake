####
# FreeRTOS.cmake:
#
# Platform setup for all FreeRTOS based targets. The goal is to add in FreRTOS specific types.
####
add_definitions(-DTGT_OS_TYPE_RTEMS)
set(TGT_OS_TYPE_RTEMS ON)

# include(${CMAKE_CURRENT_LIST_DIR}/Support/${CMAKE_SYSTEM_NAME}/${TGT_HW_TYPE}.cmake)

