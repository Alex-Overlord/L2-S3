CXX		= g++
CXX_FLAGS	= -Wall # -g -O0 -ansi -pedantic 

LD_FLAGS 	=

PROGS		= prog

SOURCES		= mainTP5.cpp progListeSC.cpp fichierTP5.cpp

HEADERS		= progListeSC.h fichierTP5.h

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
