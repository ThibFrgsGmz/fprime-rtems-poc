module App {

  module Default {
    constant queueSize = 10
    constant stackSize = 64 * 1024
  }

  instance componentC: App.ComponentC base id 0x0100 \
    queue size Default.queueSize \
    # stack size Default.stackSize \
    # priority 100

  instance componentA: App.ComponentA base id 0x4A00
  instance componentB: App.ComponentB base id 0x4A00

}
