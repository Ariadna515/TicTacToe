#rm -fr build
cmake -S . -B build
cmake --build build
cd build 
ctest