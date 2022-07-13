[![Build Status](https://api.travis-ci.com/KRVPerera/WatchSeedr.svg?branch=main)](https://travis-ci.com/KRVPerera/WatchSeedr)

# WatchSeedr


## Installing emsdk 

```bash
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
git pull
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh
```

## Build instructions 

### Normal
```bash
mkdir build
cd build
cmake ..
make -j
cd ../target
```

### Webassembly build

```bash
mkdir build_emscripten && cd build_emscripten
emcmake cmake ..
make -j
./run_webassembly.py
(visit localhost:8000)
```
