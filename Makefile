CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = main.exe

SRC = source/main.c source/issue.c source/file.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	del $(TARGET)