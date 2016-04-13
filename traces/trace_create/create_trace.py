#!/usr/bin/env python

"""create_trace.py: creates a blokc IO trace file"""

import random

MAX_LBA = 1000000000000
START_TIME = 0
NUM_VOLUMES = 2
NUM_COMMANDS = 10

RANDOM_SEED = 1234

random.seed(RANDOM_SEED)

header = "Time_ms Volume Cmd Lba Len"

print header

for i in range(NUM_COMMANDS):
	this_lba = 1
	this_volume = 0
	this_time = START_TIME + 1
	this_len = 8
	this_cmd = 'RD'
	print str(this_time)+" "+str(this_volume)+" "+this_cmd+" "+str(this_lba)+" "+str(this_len)


exit (0)	 




