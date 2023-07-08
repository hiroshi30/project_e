@echo off

rmdir build /q /s
echo DELETING build COMPLETE

mkdir build
echo CREATING build COMPLETE

cmake -S . -B build -G "MinGW Makefiles"
cmake --build build --config Release
echo BUILDING COMPLETE

copy external\SDL2-2.26.5\x86_64-w64-mingw32\bin\SDL2.dll SDL2.dll
echo COPING SDL2.dll COMPLETE

copy build\libengine.dll libengine.dll
echo COPING libengine.dll COMPLETE

copy build\game.exe game.exe
echo COPING game.exe COMPLETE

copy build\engine_tests.exe engine_tests.exe
echo COPING engine_tests.exe COMPLETE