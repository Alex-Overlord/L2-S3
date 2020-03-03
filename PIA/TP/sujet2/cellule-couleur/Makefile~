CC 		= g++
CC_FLAGS 	= -g -O0 -ansi -pedantic -Wall
LD_FLAGS 	=
PROGS		= itv
SOURCES		= itv-main.cpp itv.cpp 
HEADERS 	= itv.h

all: $(PROGS)

.SUFFIXES: .cpp .h .o

$(PROGS): $(SOURCES:.cpp=.o)
	$(CC) $(LD_FLAGS) $^-o $@

-cpp.o:
	$(CC) $(CC_FLAGS) $< -c

clean:
	rm -f *~ $(SOURCES:.cpp=.o) $(PROGS)
