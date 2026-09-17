CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = issue_tracker

SRC = source/main.c source/issue.c source/file.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	del $(TARGET)