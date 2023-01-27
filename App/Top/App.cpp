
#include <App/Top/AppTopologyAc.hpp>
#include "App.hpp"
#include "App/ComponentA/ComponentA.hpp"

App::TopologyState state;

namespace App {
    void Initialize() {
        state = App::TopologyState();
        App::setup(state);
    }
    void Deinitialize() {
        App::teardown(state);
    }
    void run_one_cycle() {
    
        App::componentA.in_f32_handler(0, 3.0f);
    }
}