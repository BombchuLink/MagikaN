#SOURCES specifies which files to compile as part of the project
SOURCES += \
	main.c

OBJS = $(addprefix obj/, $(addsuffix .o, $(SOURCES)))
DEPENDENCIES = $(addprefix obj/, $(addsuffix .o.d, $(SOURCES)))

CC = gcc
COMPILER_FLAGS = -std=c99 -ggdb3 -Og -Wall -Wextra -Wpedantic
TARGET = Magika-N

All: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
