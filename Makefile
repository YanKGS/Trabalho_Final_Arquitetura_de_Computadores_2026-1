CC      = gcc
CFLAGS  = -g -Wall -Wextra
TARGET  = multiplicacao_de_matrizes
SRC     = multiplicacao_de_matrizes.c
 
PERF_EVENTS = task-clock,cycles,instructions,cache-references,cache-misses
 
all: $(TARGET) multiplicacao_de_matrizes_bloco multiplicacao_de_matrizes_bloco_2 multiplicacao_de_matrizes_2 cache cacheline

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

multiplicacao_de_matrizes_2: multiplicacao_de_matrizes_2.c
	$(CC) $(CFLAGS) multiplicacao_de_matrizes_2.c -o multiplicacao_de_matrizes_2

multiplicacao_de_matrizes_bloco: multiplicacao_de_matrizes_bloco.c
	$(CC) $(CFLAGS) multiplicacao_de_matrizes_bloco.c -o multiplicacao_de_matrizes_bloco

multiplicacao_de_matrizes_bloco_2: multiplicacao_de_matrizes_bloco_2.c
	$(CC) $(CFLAGS) multiplicacao_de_matrizes_bloco_2.c -o multiplicacao_de_matrizes_bloco_2

cacheline: cacheline.c
	$(CC) $(CFLAGS) cacheline.c -o cacheline
cache: cache.c 
	$(CC) $(CFLAGS) cache.c -o cache

perf: $(TARGET)
	perf stat -e $(PERF_EVENTS) ./$(TARGET)

perf1: multiplicacao_de_matrizes_2
	perf stat -e $(PERF_EVENTS) ./multiplicacao_de_matrizes_2

perf2: multiplicacao_de_matrizes_bloco
	perf stat -e $(PERF_EVENTS) ./multiplicacao_de_matrizes_bloco
 
perf3: multiplicacao_de_matrizes_bloco_2
	perf stat -e $(PERF_EVENTS) ./multiplicacao_de_matrizes_bloco_2

clean:
	rm -f $(TARGET) multiplicacao_de_matrizes_bloco_2 multiplicacao_de_matrizes_bloco multiplicacao_de_matrizes_2 cacheline cache
 
.PHONY: all perf clean
