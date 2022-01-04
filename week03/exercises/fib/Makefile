TARGET=fib
SOURCE = $(wildcard ./*.cpp)
OBJECT = $(patsubst ./%.cpp,./%.o,$(SOURCE))

CC = clang++
CFLAGS = -c -Wall

$(TARGET):$(OBJECT)
	$(CC) $(OBJECT) -o $@ 
%.o:%.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY:clean
clean:
	rm -f *.o $(TARGET)