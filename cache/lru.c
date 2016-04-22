#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include "lru.h"


bool lru_insert(struct cache_block *cb){
	return false;
}

bool lru_find(uint64_t lba, uint64_t length, struct cache_block *cb){
	return false;
}

bool lru_invalidate(uint64_t lba, uint64_t length){
	return false;
}

void lru_delete(struct lru * lru){
	struct lru_element *x, *y;
	if (lru == NULL) return;
	x = lru->head;
	while (x != NULL) {
		y = x;
		x = x->next;
		free(y);
	}
	x = lru->free_head;
	while (x != NULL) {
		y = x;
		x = x->next;
		free(y);
	}
	free(lru);
}

bool lru_create(struct lru **lru, uint16_t count){
	if (*lru != NULL) return -1;
	*lru = (struct lru *)malloc(sizeof(struct lru));
	if (*lru == NULL) return -1;
	
	(*lru)->num_elements = (*lru)->num_free_elements = count;
	(*lru)->head = NULL;
	(*lru)->tail = NULL;
	(*lru)->free_head = NULL;
	(*lru)->free_tail = NULL;

		
	struct lru_element *w = malloc(sizeof(struct lru_element));
	if (w == NULL || count < 1) { lru_delete(*lru); return -1;}
	(*lru)->free_head = w;
	(*lru)->free_tail = w;
	w->next = NULL;
	w->prev = NULL;

	for ( int i = 1; i < count; i++){
		struct lru_element *x = malloc(sizeof(struct lru_element));
		if (x == NULL ) { lru_delete(*lru); return -1;}
		
		w->next = x;
		x->prev = w;
		x->next = NULL;
		(*lru)->free_tail = x;
		w = x;
	}
	return 0;
}

