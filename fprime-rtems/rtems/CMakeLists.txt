
# set(MOD_DEPS
#         "${CMAKE_THREAD_LIBS_INIT}"
#         Fw/Cfg
#         Fw/Types
#         Fw/Logger
#         Utils/Hash
#         )

# set(SOURCE_FILES
#       "Event.cpp"
#       "InterruptLock.cpp"
#       "Log.cpp"
#       "Mutex.cpp"
#       "Queue.cpp"
#       "TaskCommon.cpp"
#       "TaskId.cpp"
#       "TaskLock.cpp"
#       "WatchdogTimerCommon.cpp"
#       "${FPRIME_FRAMEWORK_PATH}/Os/Posix/IntervalTimer.cpp"
#     )

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

# register_fprime_module()