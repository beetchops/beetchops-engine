# beetchops-engine

### prerequisites

1. `$ apt install g++ cmake`
2. install [spdlog](https://github.com/gabime/spdlog) library: 
    - `$ git clone https://github.com/gabime/spdlog.git`
    - `$ cd spdlog`
    - `$ cmake -S . -B build`
    - `# cmake --build build --target install`

### build

1. `$ git clone https://github.com/beetchops/beetchops-engine`
2. `$ cd beetchops-engine`
3. `$ cmake -S . -B build`
4. `$ cmake --build build`

> Built executable `beetchops-engine` is located in `./build/bin/`

### run

1. `$ ./build/bin/beetchops-engine`
