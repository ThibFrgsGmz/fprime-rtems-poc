set(SOURCE_FILES
    "Mutex.cpp"
    "Queue.cpp"
    "Task.cpp"
    "TaskId.cpp"
    )

list(APPEND SOURCE_FILES
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

register_fprime_module(fprime-rtems_rtems)

target_link_libraries(Os PRIVATE fprime-rtems_rtems)