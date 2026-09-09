CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = Issue-Tracker

SRC = source/main.c source/issue.c source/file.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	del $(TARGET)