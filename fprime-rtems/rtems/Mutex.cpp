#include <Os/Mutex.hpp>
#include <Fw/Types/Assert.hpp>
#include <rtems.h>

/*
 * Define all of the RTEMS semaphore attributes
 *    In RTEMS, a MUTEX is defined as a binary semaphore
 *    It allows nested locks, priority wait order, and supports priority inheritance
 */
#define OSAL_MUTEX_ATTRIBS (RTEMS_PRIORITY | RTEMS_BINARY_SEMAPHORE | RTEMS_INHERIT_PRIORITY)

namespace Os {
    Mutex::Mutex(void) {
        rtems_status_code                status;
        rtems_name                       r_name;
        status = rtems_semaphore_create(r_name, 1, OSAL_MUTEX_ATTRIBS, 0, &this->m_handle);
        FW_ASSERT(status == RTEMS_SUCCESSFUL, rtems_status_text(status));
    }
    
    Mutex::~Mutex(void) {
        status = rtems_semaphore_delete(this->m_handle);
        FW_ASSERT(status == RTEMS_SUCCESSFUL, rtems_status_text(status));
    }
    
    void Mutex::lock(void) {
        status = rtems_semaphore_obtain(this->m_handle, RTEMS_WAIT, RTEMS_NO_TIMEOUT);
        FW_ASSERT(status == RTEMS_SUCCESSFUL, rtems_status_text(status));
    }

    void Mutex::unLock(void) {
        status = rtems_semaphore_release(this->m_handle);
        FW_ASSERT(status == RTEMS_SUCCESSFUL, rtems_status_text(status));
    }
}

