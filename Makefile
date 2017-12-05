GPP=g++
CPPFLAGS= -Wall -Werror -Wunused -pedantic -std=gnu++03
simulation : main.o cache.o instruction.o simulation.o
	$(GPP) -o simulation main.o cache.o instruction.o simulation.o
%.o:%.cpp
	$(GPP) $(CPPFLAGS) -c $<
.PHONY: clean depend
clean:
	rm -f *~  *.o simulation
depend:
	makedepend main.cpp cache.cpp instruction.cpp simulation.cpp
