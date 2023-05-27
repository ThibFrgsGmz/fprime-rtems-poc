// ======================================================================
// \title  ComponentA.cpp
// \author sekirei
// \brief  cpp file for ComponentA component implementation class
// ======================================================================


#include <cstdio>
#include <App/ComponentA/ComponentA.hpp>
#include <FpConfig.hpp>

namespace App {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ComponentA ::
    ComponentA(
        const char *const compName
    ) : ComponentAComponentBase(compName)
  {

  }

  void ComponentA ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    ComponentAComponentBase::init(instance);
  }

  ComponentA ::
    ~ComponentA()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ComponentA ::
    in_f32_handler(
        const NATIVE_INT_TYPE portNum,
        F32 val
    )
  {
    printf("Hello world Component A | input= %f\n", val);
    this->out_f32_out(0, val);
  }

} // end namespace App
