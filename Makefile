CXX = g++
CXXFLAGS = -Wall -Wextra -MMD -Iinclude -Iinclude/events -Iinclude/display -Iinclude/strategy
EXEC = bb7k

EVENTS = src/events/buyproperty.o src/events/collectrent.o src/events/event.o src/events/nh.o src/events/sendtotimline.o src/events/timline.o src/events/modifymoney.o src/events/rollrent.o src/events/slc.o src/events/showmsg.o src/events/tuition.o src/events/rollrimcup.o
EVENTS_DEP = ${EVENTS:.o=.d}

DISPLAY = src/display/textdisplay.o
DISPLAY_DEP = ${DISPLAY:.o=.d}

STRATEGY =  src/strategy/human.o src/strategy/strategy.o
STRATEGY_DEP = ${STRATEGY:.o=.d}
	
OBJECTS = src/behavior.o src/cell.o src/facility.o src/main.o src/property.o src/board.o src/dice.o src/group.o src/player.o
OBJECTS_DEP = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS} ${EVENTS} ${DISPLAY} ${STRATEGY}
	${CXX} ${CXXFLAGS} ${OBJECTS} ${EVENTS} ${DISPLAY} ${STRATEGY} -o ${EXEC}

-include ${OBJECTS_DEP}  ${EVENTS_DEP} ${DISPLAY_DEP} ${STRATEGY_DEP}

.PHONY: clean

clean:
	rm ${OBJECTS_DEP} ${EVENTS_DEP} ${DISPLAY_DEP} ${STRATEGY_DEP}
	rm ${OBJECTS} ${EVENTS} ${DISPLAY} ${STRATEGY}
	rm ${EXEC}
