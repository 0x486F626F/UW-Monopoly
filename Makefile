FLAGS = -Wall -Iinclude/events -Iinclude

event.o:
	g++ ${FLAGS} -c code/event.cc

behavior.o:
	g++ ${FLAGS} -c code/behavior.cc

buyproperty.o:
	g++ ${FLAGS} -c code/buyproperty.cc

collectrent.o:
	g++ ${FLAGS} -c code/collectrent.cc

group.o:
	g++ ${FLAGS} -c code/group.cc

nh.o:
	g++ ${FLAGS} -c code/nh.cc

property.o:
	g++ ${FLAGS} -c code/property.cc

sendtotimline.o:
	g++ ${FLAGS} -c code/sendtotimline.cc

strategy.o:
	g++ ${FLAGS} -c code/strategy.cc

timline.o:
	g++ ${FLAGS} -c code/timline.cc

board.o:
	g++ ${FLAGS} -c code/board.cc

cell.o:
	g++ ${FLAGS} -c code/cell.cc

dice.o:
	g++ ${FLAGS} -c code/dice.cc

facility.o:
	g++ ${FLAGS} -c code/facility.cc

human.o:
	g++ ${FLAGS} -c code/human.cc

modifymoney.o:
	g++ ${FLAGS} -c code/modifymoney.cc

player.o:
	g++ ${FLAGS} -c code/player.cc

rollrent.o:
	g++ ${FLAGS} -c code/rollrent.cc

slc.o:
	g++ ${FLAGS} -c code/slc.cc

textdisplay.o:
	g++ ${FLAGS} -c code/textdisplay.cc


.PHONY: clean

clean:
	rm *.o
