ODIR=../obj

_OBJ = harley/game.o littleoak/littleoak.o littleoak/mia.o harley/main.o harley/map.o harley/player.o harley/tile.o possum/game.o possum/scene.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/harley/%.o: harley/%.cpp
	g++ -g -c -o $@ $< -I.

$(ODIR)/littleoak/%.o: littleoak/%.cpp
	g++ -g -c -o $@ $< -I.

.PHONY: harley clean

harley: $(OBJ)
	g++ -o ../bin/debug/Harley $^ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

clean:
	rm $(OBJ)
