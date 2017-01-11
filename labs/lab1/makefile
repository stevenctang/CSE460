message: main.o message.o
	g++ -o message message.o main.o
message.o: message.cpp
	g++ -c message.cpp
main.o: main.cpp
	g++ -c main.cpp
clean: message.o main.o
	rm message message.o main.o