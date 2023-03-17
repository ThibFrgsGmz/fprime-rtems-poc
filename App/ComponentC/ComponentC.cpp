// ======================================================================
// \title  ComponentC.cpp
// \author musubi
// \brief  cpp file for ComponentC component implementation class
// ======================================================================


#include <App/ComponentC/ComponentC.hpp>
#include <FpConfig.hpp>

namespace App {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ComponentC ::
    ComponentC(
        const char *const compName
    ) : ComponentCComponentBase(compName)
  {

  }

  void ComponentC ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ComponentCComponentBase::init(queueDepth, instance);
  }

  ComponentC ::
    ~ComponentC()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ComponentC ::
    in_f32_handler(
        const NATIVE_INT_TYPE portNum,
        F32 val
    )
  {
    // TODO
  }

  void ComponentC ::
    in_f32_2_handler(
        const NATIVE_INT_TYPE portNum,
        F32 val
    )
  {
    // TODO
  }

} // end namespace App
