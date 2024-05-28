TARGET = application
CC = g++

all: $(TARGET)

$(TARGET): app.o date.o person.o
	$(CC) -o $(TARGET) app.o date.o person.o

app.o: app.cpp
	$(CC) -c app.cpp
date.o: date.cpp
	$(CC) -c date.cpp
person.o: person.cpp
	$(CC) -c person.cpp

clean:
	rm -f *.o $(TARGET)
