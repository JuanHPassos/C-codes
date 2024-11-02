CC = gcc
CFLAGS = -std=c99 -Wall
TARGET = bubble_sort

all: $(TARGET)

$(TARGET): bubble_sort.c
	$(CC) $(CFLAGS) bubble_sort.c -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET) < input3.in
