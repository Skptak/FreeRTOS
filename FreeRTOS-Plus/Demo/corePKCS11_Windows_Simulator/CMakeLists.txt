# First round of a CMakeLists.txt for the Hercules RM57L843 MCU
cmake_minimum_required(VERSION 3.9)

set(CMAKE_CROSSCOMPILING "TRUE" CACHE STRING "Set Cross Compiling to true" FORCE)

# As many of us use Macs, leaving the stripping of MacOSX features.
set(CMAKE_OSX_DEPLOYMENT_TARGET "" CACHE STRING "Force unset of the deployment target for iOS" FORCE)
set(CMAKE_OSX_SYSROOT "" CACHE STRING "Force unset of the deployment target for iOS" FORCE)

# Need to set the compiler before declaring the project for the test build
set(CMAKE_C_COMPILER "clang")
#set(CMAKE_ASM_COMPILER "arm-none-eabi-gcc")

# Set the system processor and name before declaring the project
# Needs to be set here otherwise it will fail the test compilation
#set(CMAKE_SYSTEM_NAME "Generic" CACHE STRING "Target system is a generic ARM Processor.")
#set(CMAKE_SYSTEM_PROCESSOR "armv7-r" CACHE STRING "Target system is an ARM7r processor")

## TODO: See if there are different CMAKE flags that can be set to do this instead of this
# Set the ASM flags, then add the extra ones for the CFlags
#set(CMAKE_ASM_FLAGS "-mcpu=cortex-r5 -mfpu=vfpv3-d16 -Og -g -ggdb -Wall")
#set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -specs=\"nosys.specs\" -specs=\"nano.specs\" -MMD -MP")
#set(CMAKE_C_FLAGS "${CMAKE_ASM_FLAGS} -marm -mfloat-abi=hard")

project(PKCS11_Demo C ASM)
cmake_minimum_required(VERSION 3.5)

# -> BUILD_DIR := build
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR} CACHE STRING "")

# For debug, no change detected ...
set(CMAKE_VERBOSE_MAKEFILE ON)

# Get the absolute path to the Demo Directory
set(DEMO_DIR_REL "${CMAKE_CURRENT_SOURCE_DIR}/")
get_filename_component(DEMO_DIR ${DEMO_DIR_REL} ABSOLUTE)

# Get the absolute path to the Repository Root
set(REPO_ROOT_DIR_REL "${DEMO_DIR}/../../../")
get_filename_component(REPO_ROOT_DIR ${REPO_ROOT_DIR_REL} ABSOLUTE)

# Get the absolute path to the FreeRTOS-Kernel Directory
set(FR_KERNEL_DIR_REL "${REPO_ROOT_DIR}/FreeRTOS/Source")
get_filename_component(FR_KERNEL_DIR ${FR_KERNEL_DIR_REL} ABSOLUTE)

# Get the absolute path to the Port Directory
set(PORT_DIR_REL "${FR_KERNEL_DIR_REL}/portable/ThirdParty/GCC/Posix")
get_filename_component(PORT_DIR ${PORT_DIR_REL} ABSOLUTE)

# Get the absolute path to the Heap Directory
set(HEAP_DIR_REL "${FR_KERNEL_DIR_REL}/portable/MemMang")
get_filename_component(HEAP_DIR ${HEAP_DIR_REL} ABSOLUTE)

# Get the absolute path to FreeRTOS-Plus/Source Directory
set(FR_PLUS_SOURCE_DIR_REL "${REPO_ROOT_DIR}/FreeRTOS-Plus/Source")
get_filename_component(FR_PLUS_SOURCE_DIR ${FR_PLUS_SOURCE_DIR_REL} ABSOLUTE)

# Get the absolute path to the corePKCS11 Directory
set(COREPKCS11_DIR_REL "${FR_PLUS_SOURCE_DIR}/corePKCS11/source")
get_filename_component(COREPKCS11_DIR ${COREPKCS11_DIR_REL} ABSOLUTE)

# Get the absolute path to the Config Files
set(FR_CONFIG_PATHS_REL "${REPO_ROOT_DIR}/FreeRTOS-Plus/VisualStudio_StaticProjects")
get_filename_component(FR_CONFIG_PATHS ${FR_CONFIG_PATHS_REL} ABSOLUTE)

include_directories(
    # Config Files
    ${FR_CONFIG_PATHS}/FreeRTOS-Kernel
    ${FR_CONFIG_PATHS}/corePKCS11
    ${FR_CONFIG_PATHS}/MbedTLS
    # Kernel Includes
    ${FR_KERNEL_DIR}/include
    # Port Includes
    ${PORT_DIR}/utils
    ${PORT_DIR}
    # corePKCS11 Includes
    ${COREPKCS11_DIR}/include
    ${COREPKCS11_DIR}/portable/os
    ${COREPKCS11_DIR}/dependency/3rdparty/mbedtls_utils
    #Demo Includes
    ${DEMO_DIR}
    ${DEMO_DIR}/examples
    
)

# Demo Source Files 
FILE(GLOB DEMO_SOURCES
    ${DEMO_DIR}/main.c
    ${DEMO_DIR}/examples/demo_helpers.c
    ${DEMO_DIR}/examples/management_and_rng.c
    ${DEMO_DIR}/examples/mechanisms_and_digests.c
    ${DEMO_DIR}/examples/objects.c
    ${DEMO_DIR}/examples/sign_and_verify.c
)

# FreeRTOS-Kernel Source Files
FILE(GLOB FREERTOS_KERNEL_SOURCES
    ${FR_KERNEL_DIR}/event_groups.c
    ${FR_KERNEL_DIR}/list.c
    ${FR_KERNEL_DIR}/queue.c
    ${FR_KERNEL_DIR}/stream_buffer.c
    ${FR_KERNEL_DIR}/tasks.c
    ${FR_KERNEL_DIR}/timers.c
    # Posix GCC Port
    ${PORT_DIR}/port.c
    ${PORT_DIR}/utils/wait_for_event.c
    # FREERTOS Heap
    ${HEAP_DIR}/heap_4.c
)

# corePKCS11 Source Files
FILE(GLOB COREPKC11_SOURCES
    ${COREPKCS11_DIR}/core_pkcs11.c
    ${COREPKCS11_DIR}/core_pki_utils.c
    ${COREPKCS11_DIR}/portable/core_pkcs11_mbedtls.c
    ${COREPKCS11_DIR}/portable/os/core_pkcs11_pal_utils.c
    ${COREPKCS11_DIR}/portable/os/posix/core_pkcs11_pal.c
    ${COREPKCS11_DIR}/dependency/3rdparty/mbedtls_utils/mbedtls_utils.c
)
# On Mac the C_LINK flags by default adds "-Wl,-search_paths_first -Wl,-headerpad_max_install_names" which
# Causes the executable that gets built to strip the symbols, so force set it to empty here.
#set(CMAKE_C_LINK_FLAGS "")
#set(CMAKE_EXE_LINKER_FLAGS "-Wl,-Map,\"RTOSDemo.map\" -Wl,-T\"${BOARD_FILES_DIR}/source/sys_link.ld\"")

# Debug
message("Project: ${PROJECT_NAME}")
message("Demo Sources: ${DEMO_SOURCES}")
message("FreeRTOS Sources: ${FREERTOS_KERNEL_SOURCES}")
message("corePKCS11 Sources: ${COREPKC11_SOURCES}")

# Create Blinky Demo executable
add_executable(POSIX_COREPKCS11_DEMO.out
    ${FREERTOS_KERNEL_SOURCES}
    ${COREPKC11_SOURCES}
    ${DEMO_SOURCES}
)

# These options are set in the FreeRTOSConfig.h file

