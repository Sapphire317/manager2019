CC = gcc
CFLAGS = -W -Wall
TARGET = user
OBJECTS = menu.o user.o main.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ 

clean : 
	rm *.o user
