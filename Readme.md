# CppTemplateApplication

## Description:
This is a template for creating a C++ program with GoogleTest framework


## Build and run
```bash
mkdir -p build
cd build
cmake ..
# or cmake -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_CC_COMPILER=/usr/bin/clang ..
# or cmake -DCMAKE_CXX_COMPILER=/usr/bin/g++-6 -DCMAKE_CC_COMPILER=/usr/bin/gcc ..
make
./CppTemplateApplication
```


## Testing
```bash
mkdir -p build
cd build
cmake ..
make
make test
# or
./unit-tests
```
