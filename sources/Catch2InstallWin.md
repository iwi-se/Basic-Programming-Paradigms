## Building Catch2 on Windows

1. Execute the following commands in PowerShell:

```
git clone https://github.com/catchorg/Catch2.git
cd Catch2
mkdir build
cd build
cmake -G "MinGW Makefiles" -DBUILD_TESTING=OFF ..
mingw32-make

```

2. Open PowerShell as Admin and navigate to Catch2/build/

3. Execute the following command:

```
mingw32-make install

``````



