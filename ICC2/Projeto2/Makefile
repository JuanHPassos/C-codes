CC = gcc
CFLAGS = -std=c99 -Wall
TARGET = mergesort

all: $(TARGET)

$(TARGET): mergesort.c
	$(CC) $(CFLAGS) mergesort.c -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET) < input3.in
