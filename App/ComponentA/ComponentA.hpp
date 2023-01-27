// ======================================================================
// \title  ComponentA.hpp
// \author sekirei
// \brief  hpp file for ComponentA component implementation class
// ======================================================================

#ifndef ComponentA_HPP
#define ComponentA_HPP

#include "App/ComponentA/ComponentAComponentAc.hpp"

namespace App {

  class ComponentA :
    public ComponentAComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ComponentA
      //!
      ComponentA(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object ComponentA
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ComponentA
      //!
      ~ComponentA();

      //! Handler implementation for in_f32
      //!
      void in_f32_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 val 
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------




    };

} // end namespace App

#endif
