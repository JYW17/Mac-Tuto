Target = application
all: $(Target)

$(Target): fraction.o app.o
	c++ -o $(Target) fraction.o app.o

fraction.o: fraction.cpp fraction.h
	c++ -c fraction.cpp

app.o: app.cpp fraction.h
	c++ -c app.cpp

clean:
	rm -f *.o $(Target)
