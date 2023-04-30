CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11 -O2
LIBS = -lm

SRCS = main.c myBmpGris.c Outils.c Reconnaissance_forme.c
OBJS = $(SRCS:.c=.o)
TARGET = ImageRecognition

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(TARGET)
