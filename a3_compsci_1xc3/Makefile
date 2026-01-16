# Compiler
CC = gcc

# Compiler flags:
# -Wall: Enable all warnings
# -g: Include debugging info (optional)
# -O2: Optimization level 2 (optional for better performance)
CFLAGS = -Wall -g -O2

OBJS = test.o myAO.o utility.o

TARGET = myAO

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

test.o: test.c myAO.h utility.h
	$(CC) $(CFLAGS) -c test.c

myAO.o: myAO.c myAO.h
	$(CC) $(CFLAGS) -c myAO.c

utility.o: utility.c utility.h
	$(CC) $(CFLAGS) -c utility.c

clean:
	rm -f $(TARGET) $(OBJS)
