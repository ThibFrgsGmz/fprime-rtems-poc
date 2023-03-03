module App {

  topology App {
    instance componentA
    instance componentB
    instance componentC

    connections ComponentBenchmark {
      componentA.out_f32 -> componentB.in_f32
    }

  }
}
