CC      = gcc
CFLAGS  = -g -Wall -Wextra
TARGET  = multiplicacao_de_matrizes
SRC     = multiplicacao_de_matrizes.c
 
PERF_EVENTS = task-clock,cycles,instructions,cache-references,cache-misses
 
all: $(TARGET) multiplicacao_de_matrizes_bloco
 
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

multiplicacao_de_matrizes_bloco: multiplicacao_de_matrizes_bloco.c
	$(CC) $(CFLAGS) multiplicacao_de_matrizes_bloco.c -o multiplicacao_de_matrizes_bloco
 
perf: $(TARGET)
	perf stat -e $(PERF_EVENTS) ./$(TARGET)

perf2: $(TARGET)
	perf stat -e $(PERF_EVENTS) ./multiplicacao_de_matrizes_bloco
 
clean:
	rm -f $(TARGET)
 
.PHONY: all perf clean
