othello: othello.cc board.cc player.cc
	g++ -o bin/othello othello.cc board.cc player.cc

clean:
	rm -f *.o