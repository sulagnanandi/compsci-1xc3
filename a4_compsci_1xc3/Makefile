CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

OBJ = main.o myDSlib.o
TARGET = myprogram

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c myDSlib.h
	$(CC) $(CFLAGS) -c main.c

myDSlib.o: myDSlib.c myDSlib.h
	$(CC) $(CFLAGS) -c myDSlib.c

clean:
	rm -f $(OBJ) $(TARGET)