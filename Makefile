CC = gcc
CFLAGS = -W -Wall
TARGET = manager 
OBJECTS = menu.o user.o main.o
OBJECTS_D = menu_d.o user_d.o main_d.o

all : $(TARGET)

manager_debug : $(OBJECTS_D)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ 

menu_d.o : menu.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^

user_d.o : user.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^

main_d.o : main.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^

clean : 
	rm *.o manager manager_debug
