*** Settings ***
Suite Setup                   Setup
Suite Teardown                Teardown
Test Setup                    Reset Emulation
Test Teardown                 Test Teardown
Resource                      ${RENODEKEYWORDS}

*** Variables ***
${SCRIPT}                     ${CURDIR}/leon3_rtems.resc
${UART}                       sysbus.uart
${PROMPT}                     SHLL [/] # 

*** Keywords ***
Run Fprime
    
    Execute Command           $prom="${CURDIR}/grlib-gpl-2021.2-b4267/software/leon3/prom.bin"
    Execute Command           $bin="/home/musubi/codelab/fprime-rtems-poc/App/build-artifacts/leon3-rtems5/bin/App"
    
    Execute Script            ${SCRIPT}
    Set Default Uart Timeout  2
    Create Terminal Tester    ${UART}

*** Test Cases ***
Should Boot RTEMS with FPrime
    [Documentation]           Boots RTEMS on the Leon3 platform with FPrime.
    [Tags]                    rtems  fprime
    Run Fprime

    Start Emulation

    Wait For Prompt On Uart   Hello Worldd

