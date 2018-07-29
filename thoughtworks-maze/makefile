maze:MazeFactory.o main.o
	g++ MazeFactory.o main.o -o maze
MazeFactory.o:MazeFactory.cpp
	g++ -c MazeFactory.cpp -o MazeFactory.o
main.o:main.cpp
	g++ -c main.cpp -o main.o
clean:
	rm -rf *.o maze
