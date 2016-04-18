#include <stdbool.h>
#include <stddef.h>
#include "lru.h"

// This is the test driver for lru.c
// The program will create a set of objects of various lengths
// It will insert objects into the LRU
// it will invalidate objects in the LRU
// it will count elements in the LRU at various points
  

int main ( int argc, char ** argv){

	uint16_t num_cache_elements = 100;
	struct lru * cache_lru = NULL;
	lru_create(&cache_lru, num_cache_elements);

	lru_delete(cache_lru);

	return 0;
}
