#ifndef CACHE_H
#define CACHE_H


stuct cache_block {
	void * memAddress;
	int	valid;
	int	dirty;
	int 	lba;	
	int 	read_hits;
	int	read_hit_bytes;
	int	write_hits;
	int 	write_hit_bytes;
	int	wait_count;
	int	use_count;
}






#endif
