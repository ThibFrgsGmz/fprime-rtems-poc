####
# leon3-rtems5.cmake:
#
# Toolchain file setup for building F prime for the LEON3 hardware platform.
#
####
include_guard()
set(CMAKE_SYSTEM_NAME         RTEMS)
set(CMAKE_SYSTEM_VERSION      5.1)
set(CMAKE_SYSTEM_PROCESSOR    leon3)
set(CMAKE_TRY_COMPILE_TARGET_TYPE
    "STATIC_LIBRARY"
    CACHE STRING "Try Static Lib Type" FORCE)

# Adapt the path according to the developer setup, it seems that only absolute paths work
set(TOOLCHAIN_PATH "/home/sekirei/rcc-1.3.0-gcc" CACHE PATH "Toolchain path")

# Check toolchain directory exists
IF(NOT EXISTS "${TOOLCHAIN_PATH}")
    message(FATAL_ERROR "Toolchain not found at ${TOOLCHAIN_PATH}.")
endif()
message(STATUS "Using toolchain at: ${TOOLCHAIN_PATH}")

set(CROSS_PREFIX "sparc-gaisler-rtems5")
set(CROSS_SUFFIX "")

# Specify the cross toolchain executables
set(CMAKE_ASM_COMPILER "${TOOLCHAIN_PATH}/bin/${CROSS_PREFIX}-gcc${CROSS_SUFFIX}"     CACHE PATH "assembler"  FORCE)
set(CMAKE_C_COMPILER   "${TOOLCHAIN_PATH}/bin/${CROSS_PREFIX}-gcc${CROSS_SUFFIX}"     CACHE PATH "gcc"        FORCE)
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_PATH}/bin/${CROSS_PREFIX}-g++${CROSS_SUFFIX}"     CACHE PATH "g++"        FORCE)
set(CMAKE_LINKER       "${TOOLCHAIN_PATH}/bin/${CROSS_PREFIX}-ld${CROSS_SUFFIX}"      CACHE PATH "linker"     FORCE)
set(CMAKE_AR           "${TOOLCHAIN_PATH}/bin/${CROSS_PREFIX}-ar${CROSS_SUFFIX}"      CACHE PATH "archive"    FORCE)

set(CMAKE_NM           "${TOOLCHAIN_PATH}/bin/${CROSS_PREFIX}-nm${CROSS_SUFFIX}"      CACHE PATH "nm"         FORCE)
set(CMAKE_OBJCOPY      "${TOOLCHAIN_PATH}/bin/${CROSS_PREFIX}-objdump${CROSS_SUFFIX}" CACHE PATH "objcopy"    FORCE)
set(CMAKE_OBJDUMP      "${TOOLCHAIN_PATH}/bin/${CROSS_PREFIX}-objcopy${CROSS_SUFFIX}" CACHE PATH "objdump"    FORCE)
set(CMAKE_STRIP        "${TOOLCHAIN_PATH}/bin/${CROSS_PREFIX}-strip${CROSS_SUFFIX}"   CACHE PATH "strip"      FORCE)
set(CMAKE_SIZE         "${TOOLCHAIN_PATH}/bin/${CROSS_PREFIX}-size${CROSS_SUFFIX}"    CACHE PATH "size"       FORCE)
set(CMAKE_RANLIB       "${TOOLCHAIN_PATH}/bin/${CROSS_PREFIX}-ranlib${CROSS_SUFFIX}"  CACHE PATH "ranlib"     FORCE)

set(BSP_FLAG "-qbsp=leon3")
set(ISA_FLAG "-mcpu=leon3")
set(COMMON_FLAGS "-g -msoft-float ${ISA_FLAG} ${BSP_FLAG} -mflat")

set(C_FLAGS "")
set(CXX_FLAGS "")
set(ASM_FLAGS "")
set(LD_FLAGS "")

set(DEF_FLAGS "")

set(CMAKE_C_FLAGS           "${COMMON_FLAGS} ${C_FLAGS} ${DEF_FLAGS}")
set(CMAKE_CXX_FLAGS         "${COMMON_FLAGS} ${CXX_FLAGS} ${DEF_FLAGS}")
set(CMAKE_ASM_FLAGS         "${COMMON_FLAGS} ${ASM_FLAGS} ${DEF_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS  "${COMMON_FLAGS} ${LD_FLAGS}")

set(CMAKE_FIND_ROOT_PATH "${TOOLCHAIN_PATH}")
# Specify paths to root of toolchain package,
# for searching for libraries, executables, etc. in the build host directories
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# For libraries and headers in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

foreach(lang IN ITEMS C CXX)
  # Specify the C and C++ standard required for ALL targets
  set(CMAKE_${lang}_STANDARD
      11
      CACHE
        INTERNAL
        "The ${lang} standard whose features are requested to build this target."
  )
  # Force the specified language standard: if the compiler does not support the
  # specified standard, it will generate an error. Without this CMake will be
  # resilient and will fall back to the last standard the compiler supports
  # instead.
  set(CMAKE_${lang}_STANDARD_REQUIRED ON)
  # Disable all C and C++ extensions on ALL targets. This forces the use of
  # -std=c17 and -std=c++17 instead of -std=gnu17 and -std=gnu++17
  set(CMAKE_${lang}_EXTENSIONS
      OFF
      CACHE INTERNAL "${lang} compiler extensions OFF")

  # Set -ffunction-sections and -fdata-sections so that each method has its own
  # text section. This allows the linker to remove unused section when the flag
  # -Wl,-gc-sections is provided at link time.
  string(APPEND CMAKE_${lang}_FLAGS " -ffunction-sections")
  string(APPEND CMAKE_${lang}_FLAGS " -fdata-sections")
endforeach()
