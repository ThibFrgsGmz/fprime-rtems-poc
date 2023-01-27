// ======================================================================
// \title  ComponentB.hpp
// \author sekirei
// \brief  hpp file for ComponentB component implementation class
// ======================================================================

#ifndef ComponentB_HPP
#define ComponentB_HPP

#include "App/ComponentB/ComponentBComponentAc.hpp"

namespace App {

  class ComponentB :
    public ComponentBComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ComponentB
      //!
      ComponentB(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object ComponentB
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ComponentB
      //!
      ~ComponentB();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for in_f32
      //!
      void in_f32_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 val 
      );


    };

} // end namespace App

#endif
