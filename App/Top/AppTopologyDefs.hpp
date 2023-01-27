#ifndef AppTopologyDefs_HPP
#define AppTopologyDefs_HPP

#include "Fw/Types/BasicTypes.hpp"

namespace App {
// State for topology construction
struct TopologyState
{
  TopologyState () : hostName (""), portNumber (0) {}
  TopologyState (const char *hostName, U32 portNumber)
      : hostName (hostName), portNumber (portNumber)
  {
  }
  const char *hostName;
  U32 portNumber;
};
}

#endif
