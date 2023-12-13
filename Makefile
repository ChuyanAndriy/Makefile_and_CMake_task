all: App

Lab1: libmylib.a UserInterface.o
	g++ -o App UserInterface.o -L. -lmylib
	
libmylib.a: Car.o Database.o
	ar cr libmylib.a Car.o Database.o

Car.o: Car.cpp Car.h
	g++ -c Car.cpp

Database.o: Database.cpp Database.h
	g++ -c Database.cpp
	
UserInterface.o: UserInterface.cpp
	g++ -c UserInterface.cpp

clean:
	rm -rf *.o *.a Lab1
