CC = gcc -Wall
TARGET = executable
SRCDIR = .
EXCDIR = Exchange_Library
VECDIR = Vector_Library
ARGS = Example_Files/Values_Example

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(SOURCES:.c=.o)

EXC_SOURCES := $(wildcard $(EXCDIR)/*.c)
EXC_OBJECTS := $(EXC_SOURCES:.c=.o)

VEC_SOURCES := $(wildcard $(VECDIR)/*.c)
VEC_OBJECTS := $(VEC_SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS) $(EXC_OBJECTS) $(VEC_OBJECTS)
	$(CC) $^ -o $@

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@

$(EXCDIR)/%.o: $(EXCDIR)/%.c
	$(CC) -c $< -o $@

$(VECDIR)/%.o: $(VECDIR)/%.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXC_OBJECTS) $(VEC_OBJECTS)

cleanall: clean
	rm -f  $(TARGET)

run: $(TARGET)
	./$(TARGET) $(ARGS)