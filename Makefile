src = $(wildcard *.cpp)
obj = $(src:.c=.o)
RANGE_V3 = /home/vera/c++/range-v3/include
LIBFLAGS= -I$(RANGE_V3)
ADDCPP= $(wildcard $(IncDirectories)/*.cpp)
LDFLAGS = -std=c++17  -pthread -lboost_system -lboost_regex -lboost_filesystem -lboost_iostreams -lstdc++fs

run: $(obj)
	g++ -o $@ $^ $(LDFLAGS) $(LIBFLAGS) && ./run
	

.PHONY : all
all : imageDuplicate
imageDuplicate: $(obj)
	g++ -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f imageDuplicate