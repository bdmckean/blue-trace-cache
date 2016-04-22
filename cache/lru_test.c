#include <stdbool.h>	// bool
#include <stdio.h>	// fopen, printf
#include <stdlib.h>    // exit
#include "lru.h"

// This is the test driver for lru.c
// The program will create a set of objects of various lengths
// It will insert objects into the LRU
// it will invalidate objects in the LRU
// it will count elements in the LRU at various points
  
void usage(void)
{
	printf("Usage: cache_sim trace-file-name\n\n");

}


int main ( int argc, char ** argv){

	uint16_t num_cache_elements = 100;
	struct lru * cache_lru = NULL;

	lru_create(&cache_lru, num_cache_elements);

	lru_delete(cache_lru);

	FILE *fp;
	char line[256];
	// test that there is a filename in the argsting
	if ( argc != 2) { usage(); exit (1); }	
	// open file
	if ((fp = fopen(argv[1], "r")) == NULL) { 
		printf("could not open file name %s\n\n", argv[1]);
		exit (1);
	}  
	while(fgets(line, sizeof(line),fp)){
		printf("echo -- %s\n",line);

	}

	fclose(fp);	
	return (0);
}
