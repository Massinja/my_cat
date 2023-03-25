CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

SOURCES = my_cat.c
OBJFILES = $(SOURCES:.c=.o)
TARGET = my_cat
all: $(TARGET)


$(TARGET): $(OBJFILES) 
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)


.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJFILES)
