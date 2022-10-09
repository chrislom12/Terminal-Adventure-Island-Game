output: *.o
	g++ -g -std=c++11 -o main *.o
*.o: *.cpp
	g++ -g -std=c++11 -c *.cpp
run:
	./main
clean:
	rm -f *.o main
fix:
	find . -type f | xargs -n 5 touch