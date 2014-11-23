CXX = g++
CXXFLAGS = -Wall -Wextra -MMD -Iinclude
EXEC = bb7k
OBJECTS = src/main.o src/behavior.o src/group.o src/nh.o src/property.o src/strategy.o src/timline.o src/board.o src/cell.o src/dice.o src/facility.o src/human.o src/modifymoney.o src/player.o src/rollrent.o src/slc.o src/textdisplay.o
EVENTS = src/events/buyproperty.o src/events/collectrent.o src/events/event.o src/events/nh.o src/events/sendtotimline.o src/events/timline.o src/events/modifymoney.o src/events/rollrent.o src/events/slc.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
