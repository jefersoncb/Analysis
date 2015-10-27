
##############################################################
# The main rule
##############################################################
a.out: main.o
	g++ -o a.out main.o 

##############################################################
# The individual components
#      main.o     : the driver program
##############################################################
main.o: main.cpp sortHeap.h sortBubble.h \
		sortSelection.h sortQuick.h
	g++ -c main.cpp

