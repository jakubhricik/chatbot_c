# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror 
LDLIBS=
OUTPUT=chatbot

# targets
all: $(OUTPUT)

$(OUTPUT): chatbot.o
	$(CC) $(CFLAGS) chatbot.o $(LDLIBS) -o $(OUTPUT)

chatbot.o: chatbot.c chatbot.h
	$(CC) $(CFLAGS) -c chatbot.c $(LDLIBS) -o chatbot.o

# remove compiled files
clean:
	rm -rf $(OUTPUT) *.o


