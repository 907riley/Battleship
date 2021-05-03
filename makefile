PA8main: PA8.o PA8main.o
	g++ -o PA8main PA8.o PA8main.o
	
PA8main.o: PA8main.cpp
	g++ -c PA8main.cpp
	
PA8.o: PA8.cpp PA8.h
	g++ -c PA8.cpp
	
all: PA8main
	./a.out

clean:
	rm -f PA8main PA8main.cpp 
