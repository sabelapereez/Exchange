CC = gcc -Wall
LIBS = -lm
HEADER_FILES_DIR = .
INCLUDES = -I $(HEADER_FILES_DIR)
OUTPUT = executable
LIB_HEADERS = $(HEADER_FILES_DIR)/dynamicvector.h $(HEADER_FILES_DIR)/exchange.h
SRCS = main.c dynamicvector.c exchange.c
OBJS = $(SRCS:.c=.o)
$(OUTPUT): $(OBJS)
	$(CC) -o $(OUTPUT) $(OBJS) $(LIBS)

%.o: %.c $(LIB_HEADERS)
	$(CC) -c -o $@ $< $(INCLUDES)

cleanall: clean
	rm -f $(OUTPUT)

clean:
	rm -f *.o *~