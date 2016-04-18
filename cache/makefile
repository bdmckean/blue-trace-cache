# Makes cache simulator 
#Compiler
CC=gcc
#Compiler Flags
CC_FLAGS -std=c99 -Wall  -g

all: cache_sim 

cache_sim: lru.c lru_test.c lru.h
	$(CC) $(CC_FLAGS) lru.c lru_test.c -o cache_sim

clean:
	rm *.o cache_sim



