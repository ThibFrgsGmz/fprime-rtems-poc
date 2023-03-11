set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/instances.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/topology.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/App.cpp"
)

# Note: supply non-explicit dependencies here
set(MOD_DEPS
  fprime-rtems/rtems
  Os
)

register_fprime_module()