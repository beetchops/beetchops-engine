# beetchops-engine

### prepare

1. `$ apt install g++ cmake`

### build

1. `$ git clone https://github.com/beetchops/beetchops-engine`
2. `$ cd beetchops-engine`
3. `$ cmake -S . -B build`
4. `$ cmake --build build`

> Built executable `beetchops-engine` is located in `./build/bin/`

### test

1. `$ cmake --build build --target test`

### run

1. `$ ./build/bin/beetchops-engine`
