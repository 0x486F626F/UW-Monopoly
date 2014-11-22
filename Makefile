FLAGS = -Wall -Iinclude/events -Iinclude

*.o:
	g++ ${FLAGS} -c code/*.cc



.PHONY: clean

clean:
	rm *.o
