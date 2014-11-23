CXX = g++
CXXFLAGS = -Wall -Wextra -MMD
EXEC = bb7k
OBJECTS = main.o behavior.o buyproperty.o collectrent.o event.o group.o nh.o property.o sendtotimline.o strategy.o timline.o board.o cell.o dice.o facility.o human.o modifymoney.o player.o rollrent.o slc.o textdisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
