#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include "lru.h"


bool lru_insert(uint64_t key, void * data, uint64_t length){
	return false;
}
bool lru_find(uint64_t key, uint16_t hit_type){
	return false;
}

bool lru_invalidate(uint64_t key){
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
	w->key = 1;
	w->data = NULL;

	for ( int i = 1; i < count; i++){
		struct lru_element *x = malloc(sizeof(struct lru_element));
		if (x == NULL ) { lru_delete(*lru); return -1;}
		
		w->next = x;
		x->prev = w;
		x->next = NULL;
		x->key = w->key + 1;
		x->data = NULL; 
		(*lru)->free_tail = x;
		w = x;
	}
	return 0;
}

