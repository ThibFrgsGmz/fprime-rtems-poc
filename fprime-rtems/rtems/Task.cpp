#include <Os/Task.hpp>
#include <Fw/Types/Assert.hpp>
#include <rtems.h>

namespace Os {
    
    Task::Task() : m_handle(0), m_identifier(0), m_affinity(-1), m_started(false), m_suspendedOnPurpose(false) {
    }

    Task::TaskStatus Task::start(const Fw::StringBase &name, NATIVE_INT_TYPE identifier, NATIVE_INT_TYPE priority, NATIVE_INT_TYPE stackSize, taskRoutine routine, void* arg, NATIVE_INT_TYPE cpuAffinity) {

        rtems_status_code               status;
        rtems_name                      r_name;
        rtems_mode                      r_mode;
        rtems_attribute                 r_attributes;
        this->m_name = "TV_";
        this->m_name += name;
        this->m_identifier = identifier;
        this->m_started = false;
        this->m_affinity = cpuAffinity; // ThreadX does not support AMP/SMP on STM32H7(ARM Cortex-Mx) platform.

        /*
        ** RTEMS task names are 4 byte integers.
        ** It is convenient to use the OSAL task ID in here, as we know it is already unique
        ** and trying to use the real task name would be less than useful (only 4 chars)
        */
        r_name = static_cast<rtems_name>(identifier);
        r_mode = RTEMS_PREEMPT | RTEMS_NO_ASR | RTEMS_NO_TIMESLICE | RTEMS_INTERRUPT_LEVEL(0);
        r_attributes = RTEMS_LOCAL;
        r_attributes |= RTEMS_FLOATING_POINT; /* See if the user wants floating point enabled. If so, then set the correct option. */

        // If a registry has been registered, register task
        if (Task::s_taskRegistry) {
            Task::s_taskRegistry->addTask(this);
        }

        status = rtems_task_create(r_name, priority, stackSize, r_mode, r_attributes, &this->m_handle);

        FW_ASSERT(status == RTEMS_SUCCESSFUL, rtems_status_text(status));

        if (status != RTEMS_SUCCESSFUL)
        {
            return TASK_UNKNOWN_ERROR;
        }
        
        status = rtems_task_start(this->m_handle, (rtems_task_entry)routine, (rtems_task_argument)r_name);

        FW_ASSERT(status == RTEMS_SUCCESSFUL, rtems_status_text(status));

        if (status != RTEMS_SUCCESSFUL)
        {
            rtems_task_delete(this->m_handle);
            return TASK_UNKNOWN_ERROR;
        }

        Task::s_numTasks++;
        return TASK_OK;    
    }

    Task::~Task() {
        if (Task::s_taskRegistry) {
            Task::s_taskRegistry->removeTask(this);
        }
        rtems_task_delete(this->m_handle);
    }

    /* TODO: implement the function */
    // int32 OS_Milli2Ticks(uint32 milli_seconds, int *ticks)
    // {
    //     uint64 num_of_ticks;
    //     int32  return_code = OS_SUCCESS;

    //     num_of_ticks = (((uint64)milli_seconds * OS_SharedGlobalVars.TicksPerSecond) + 999) / 1000;

    //     /* Check against maximum int32 (limit from some OS's) */
    //     if (num_of_ticks <= INT_MAX)
    //     {
    //         *ticks = (int)num_of_ticks;
    //     }
    //     else
    //     {
    //         return_code = OS_ERROR;
    //         *ticks      = 0;
    //     }

    //     return return_code;
    // }

    Task::TaskStatus Task::delay(NATIVE_UINT_TYPE milliseconds)
    {
        int   tick_count;
        int32 return_code = TASK_OK;
        Task::TaskStatus status = TASK_DELAY_ERROR;

        // return_code = OS_Milli2Ticks(milli_second, &tick_count);

        if (return_code != TASK_OK)
        {
            /*
            * Always want to do some form of delay, because if
            * this function becomes a no-op then this might create a
            * tight loop that doesn't ever yield the CPU - effectively
            * locking the system in an RTOS environment.
            */
            tick_count = 10;
        }

        rtems_task_wake_after((rtems_interval)tick_count);
        return return_code;
    }

    void Task::suspend(bool onPurpose) {
        (void) onPurpose;
        rtems_status_code status = rtems_task_suspend(this->m_handle);
        FW_ASSERT(status == RTEMS_SUCCESSFUL);
    }

    void Task::resume(void) {
        rtems_status_code status = rtems_task_resume(this->m_handle);
        FW_ASSERT(status == RTEMS_SUCCESSFUL);
    }

    bool Task::isSuspended(void) {
        return(rtems_task_is_suspended(this->m_handle) == RTEMS_SUCCESSFUL) ? false : true;
    }

    TaskId Task::getOsIdentifier(void) {
        TaskId T;
        return T;
    }

    Task::TaskStatus Task::join (void **value_ptr) {
        // No task join in taskLib.  Return error if used.
        return TASK_JOIN_ERROR;
    }
}