CC = gcc
CFLAGS = -Wall
OBJ = game2048.o utility.o
TARGET = game2048

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

game2048.o: game2048.c utility.h
	$(CC) $(CFLAGS) -c game2048.c

utility.o: utility.c utility.h
	$(CC) $(CFLAGS) -c utility.c

clean:
	rm -f $(OBJ) $(TARGET)