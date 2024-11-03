CC = gcc
CFLAGS = -std=c99 -Wall
TARGET = inserction_sort

all: $(TARGET)

$(TARGET): inserction_sort.c
	$(CC) $(CFLAGS) inserction_sort.c -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET) < input3.in
