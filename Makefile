CC=g++
CFLAGS= -std=c++11 -Wall -I./include
SOURCES= src/*.cpp
TARGET= quiz
LDFLAGS= -o $(TARGET)

all:
	$(CC) $(CFLAGS) $(SOURCES) $(LDFLAGS)
