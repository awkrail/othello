othello: othello.cc board.cc
	g++ -o bin/othello othello.cc board.cc

clean:
	rm -f *.o
