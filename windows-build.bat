g++ ./main.cpp ./src/*.cpp -I./ext/install-win/include -L./ext/install-win/lib -o ./dist/windows/particle-life_windows.exe -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lwinmm -lgdi32 -fpermissive
cd ./dist/windows/
particle-life_windows.exe
cd ../../