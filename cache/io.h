#ifndef IO_H
#define IO_H


struct io_buf {
	int volume;
	int lba;
	int length;
	int start_time;
	int end_time;	
	void * callback();
}





#endif
