// File TaskId.cpp
#include <rtems.h>
#include <Os/TaskId.hpp>

namespace Os
{
    TaskId::TaskId(void)
    {
        id = rtems_task_self();
    }
    TaskId::~TaskId(void)
    {
    }

    bool TaskId::operator==(const TaskId& T) const
    {
        return (T.id == id);
    }

    bool TaskId::operator!=(const TaskId& T) const
    {
        return (T.id != id);
    }

    TaskIdRepr TaskId::getRepr(void) const
    {
        return this->id;
    }
}
