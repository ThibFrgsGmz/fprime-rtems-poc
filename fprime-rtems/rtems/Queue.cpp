#include <Os/Queue.hpp>
#include <stdio.h>
#include <rtems.h>

namespace Os {
    
    Queue::Queue(): m_handle(0) {
        
    }

    Queue::QueueStatus Queue::createInternal(const Fw::StringBase &name, NATIVE_INT_TYPE depth, NATIVE_INT_TYPE msgSize) {

        this->m_name = "QV_";
        this->m_name += name;

        // MSG_Q_ID handle = msgQCreate(depth,msgSize,MSG_Q_PRIORITY);
        // this->m_handle = handle == NULL?0:(POINTER_CAST)handle;
        // if (NULL == handle) {
        //     return QUEUE_UNINITIALIZED;
        // }

        rtems_status_code                status;
        rtems_name                       r_name;
        status = rtems_message_queue_create (
            r_name, depth, msgSize, RTEMS_FIFO | RTEMS_LOCAL, &this->m_handle);

        if (status != RTEMS_SUCCESSFUL)
        {
            FW_ASSERT(status == RTEMS_SUCCESSFUL, rtems_status_text(status));
            return QUEUE_UNINITIALIZED;
        }

        Queue::s_numQueues++;
        return QUEUE_OK;
    }
    
    Queue::~Queue() {
        rtems_status_code                status;
        status = rtems_message_queue_delete(this->m_handle);
        FW_ASSERT(status == RTEMS_SUCCESSFUL, rtems_status_text(status));
        // (void)msgQDelete((MSG_Q_ID) this->m_handle);
    }

    Queue::QueueStatus Queue::send(const U8* buffer, NATIVE_INT_TYPE size, NATIVE_INT_TYPE priority, QueueBlocking block) {

        if (this->m_handle == 0) {
            return QUEUE_UNINITIALIZED;
        }
        
        if (buffer == nullptr) {
            return QUEUE_EMPTY_BUFFER;
        }
        
        rtems_status_code                status;
        rtems_id                         rtems_queue_id;
        rtems_queue_id = this->m_handle;
        status = rtems_message_queue_send(rtems_queue_id, data, size);

        FW_ASSERT(status == RTEMS_SUCCESSFUL, rtems_status_text(status));

        if (status != RTEMS_SUCCESSFUL) {
            switch (status) {
                case RTEMS_TOO_MANY:
                    return QUEUE_FULL;
                default:
                    return QUEUE_UNKNOWN_ERROR;
                }
        }
        return QUEUE_OK;
    }

    Queue::QueueStatus Queue::receive(U8* buffer, NATIVE_INT_TYPE capacity, NATIVE_INT_TYPE &actualSize, NATIVE_INT_TYPE &priority, QueueBlocking block) {
        
        if (this->m_handle == 0) {
            return QUEUE_UNINITIALIZED;
        }

        rtems_status_code status;
        rtems_interval ticks;
        rtems_id rtems_queue_id = this->m_handle;

        if (block == QUEUE_NONBLOCKING) {
            option_set = RTEMS_WAIT;
            ticks      = RTEMS_NO_TIMEOUT;
        }
        else {
            option_set = RTEMS_NO_WAIT;
            ticks      = RTEMS_NO_TIMEOUT;
        }

        status = rtems_message_queue_receive(rtems_queue_id, buffer, &capacity, option_set, ticks);

        FW_ASSERT(status == RTEMS_SUCCESSFUL, rtems_status_text(status));

        if (status != RTEMS_SUCCESSFUL) {
            capacity = 0;
            switch (status) {
                case RTEMS_UNSATISFIED:
                    return QUEUE_SIZE_MISMATCH;
                case RTEMS_TIMEOUT:
                    return QUEUE_NO_MORE_MSGS;
                default:
                    return QUEUE_UNKNOWN_ERROR;
            }
        }
        return QUEUE_OK;
    }

    NATIVE_INT_TYPE Queue::getNumMsgs(void) const {

        uint32_t = number_pending_msg;
        rtems_status_code status = rtems_message_queue_get_number_pending(this->m_handle, &number_pending_msg);

        FW_ASSERT(status == RTEMS_SUCCESSFUL, rtems_status_text(status));

        if (status != RTEMS_SUCCESSFUL) {
            return -1;
        }
        return static_cast<NATIVE_INT_TYPE>(number_pending_msg);
    }

}
