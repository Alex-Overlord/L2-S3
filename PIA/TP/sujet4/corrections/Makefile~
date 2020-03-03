CXX		= g++
CXX_FLAGS	= -g -O0 -ansi -pedantic -Wall 

LD_FLAGS 	=

PROGS		= option

SOURCES		= option.cpp

HEADERS		= option.h

DEPFILE		= .depend

ifeq ($(wildcard $(DEPFILE)), )

all: $(DEPFILE)
	make

else

all: $(PROGS)
include $(DEPFILE)

endif

include $(DEPFILE)

.SUFFIXES: .cpp .h .o 

$(PROGS): $(SOURCES:.cpp=.o)
	$(CXX) $(LD_FLAGS) $^ -o $@

.cpp.o:
	$(CXX) $(CXX_FLAGS)$< -c

$(DEPFILE): $(SOURCES)
	$(CXX) -MM $^ > $@ 

clean:
	rm -f *~ $(SOURCES:.cpp=.o) $(PROGS)
