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

set(MOD_DEPS
    Os
)

register_fprime_module(fprime-rtems_rtems)
