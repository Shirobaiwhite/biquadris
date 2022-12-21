CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -g -MMD -L/usr/X11R6/lib
EXEC = biquadris
OBJECTS = biquadris.o cell.o board.o textdisplay.o block.o graphicdisplay.o window.o player.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean
