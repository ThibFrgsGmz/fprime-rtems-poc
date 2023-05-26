set(SOURCE_FILES
    "Mutex.cpp"
    "Queue.cpp"
    "Task.cpp"
    "TaskId.cpp"
    )

if(CMAKE_SYSTEM_VERSION MATCHES 4.[789])
#   list(APPEND SOURCE_FILES
#         "4.x/Task.cpp"
#         "4.x/WatchdogTimer.cpp"
#       )
    message(SYSTEM VERSION ==== > 4.x)
elseif(CMAKE_SYSTEM_VERSION MATCHES 5.[0-9])
#   list(APPEND SOURCE_FILES
#         "5.x/Task.cpp"
#         "4.x/WatchdogTimer.cpp"
#       )
    message(SYSTEM VERSION ==== > 5.x)
endif()

# Basic source files used in every OSAL layer.  Contains common code and helpers.
set(SOURCE_FILES
    "${FPRIME_FRAMEWORK_PATH}/Os/IntervalTimerCommon.cpp"
    "${FPRIME_FRAMEWORK_PATH}/Os/TaskString.cpp"
    "${FPRIME_FRAMEWORK_PATH}/Os/TaskCommon.cpp"
    "${FPRIME_FRAMEWORK_PATH}/Os/QueueCommon.cpp"
    "${FPRIME_FRAMEWORK_PATH}/Os/QueueString.cpp"
    "${FPRIME_FRAMEWORK_PATH}/Os/IPCQueueCommon.cpp"
    "${FPRIME_FRAMEWORK_PATH}/Os/SimpleQueueRegistry.cpp"
    "${FPRIME_FRAMEWORK_PATH}/Os/MemCommon.cpp"
    "${FPRIME_FRAMEWORK_PATH}/Os/ValidateFileCommon.cpp"
    "${FPRIME_FRAMEWORK_PATH}/Os/ValidatedFile.cpp"
    "${FPRIME_FRAMEWORK_PATH}/Os/FileCommon.cpp"
)

set(MOD_DEPS
    Os
)

register_fprime_module(fprime-rtems_rtems)

if (${CMAKE_SYSTEM_NAME} STREQUAL "RTEMS")
    add_dependencies(Os fprime-rtems_rtems)
    target_link_libraries(Os PRIVATE fprime-rtems_rtems)
    target_link_libraries(fprime-rtems_rtems PRIVATE Os)
endif()