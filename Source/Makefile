FILES=ability.cpp attack.cpp battle.cpp harley.cpp main.cpp map.cpp overworld.cpp player.cpp tile.cpp

Harley.exe: $(FILES)
	cl /EHsc $(FILES) /link SDL2 /link SDL2_image /link /out:../bin/Debug/Harley.exe
	
Harley: $(FILES)
	g++ -o ../bin/Debug/Harley $(FILES) -lSDL2 -lSDL2_image
