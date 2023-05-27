// ======================================================================
// \title  ComponentB.cpp
// \author sekirei
// \brief  cpp file for ComponentB component implementation class
// ======================================================================

#include <cstdio>
#include <App/ComponentB/ComponentB.hpp>
#include <FpConfig.hpp>

namespace App {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ComponentB ::
    ComponentB(
        const char *const compName
    ) : ComponentBComponentBase(compName)
  {

  }

  void ComponentB ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    ComponentBComponentBase::init(instance);
  }

  ComponentB ::
    ~ComponentB()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ComponentB ::
    in_f32_handler(
        const NATIVE_INT_TYPE portNum,
        F32 val
    )
  {
    printf("Hello world Component B | input= %f\n", val);
    this->out_f32_out(0, val);
  }

} // end namespace App
