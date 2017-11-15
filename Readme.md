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

## Code Coverage
To generate code coverage reports from the unit tests run the below steps.
The CodeCoverage.cmake file used gcov from the gcc installation and lcov
which has to be installed separately to generate an html coverage report.

```bash
mkdir -p build
cd build
cmake ..
make
make sliding-tiles_coverage
# open the file coverage/index.html with a browser
```
