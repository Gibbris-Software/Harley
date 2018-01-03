ODIR=../obj

_OBJ = game.o littleoak.o main.o map.o player.o tile.o possum/game.o possum/scene.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp
	g++ -g -c -o $@ $<

.PHONY: harley clean

harley: $(OBJ)
	g++ -o ../bin/debug/Harley $^ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

clean:
	rm $(OBJ)
