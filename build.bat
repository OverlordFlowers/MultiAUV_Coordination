CD build
cmake .. -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER="C:\MinGW\bin\g++.exe" -DCMAKE_C_COMPILER="C:\MinGW\bin\gcc.exe"
mingw32-make
.\MultiAUV.exe
CD ..