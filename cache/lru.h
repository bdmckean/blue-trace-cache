#ifndef LRU_H
#define LRU_H

#include <stdbool.h>
#include <stdint.h>

struct lru_element {
	uint64_t key;
	uint64_t length;
	uint32_t stats;
	void * data;
	struct lru_element * next;
	struct lru_element * prev;
	struct lru_element * next_hash;
	struct lru_element * prev_hash;
	};

struct lru {
	struct lru_element * head;
	struct lru_element * tail;
	uint32_t num_elements;
	struct lru_element * free_head;
	struct lru_element * free_tail;
	uint32_t num_free_elements;
	uint32_t element_size;
	};


extern bool lru_insert (uint64_t key, void * data, uint64_t length);
extern bool lru_hit(uint64_t key, uint16_t hit_type);
extern bool lru_invalidate(uint64_t key);
extern bool lru_create(struct lru ** lru, uint16_t count);
extern void lru_delete(); 

#endif
	
