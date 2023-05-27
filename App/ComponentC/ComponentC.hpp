// ======================================================================
// \title  ComponentC.hpp
// \author musubi
// \brief  hpp file for ComponentC component implementation class
// ======================================================================

#ifndef ComponentC_HPP
#define ComponentC_HPP

#include "App/ComponentC/ComponentCComponentAc.hpp"

namespace App {

  class ComponentC :
    public ComponentCComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ComponentC
      //!
      ComponentC(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object ComponentC
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ComponentC
      //!
      ~ComponentC();

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

      //! Handler implementation for in_f32_2
      //!
      void in_f32_2_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 val 
      );


    };

} // end namespace App

#endif
