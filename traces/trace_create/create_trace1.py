#!/usr/bin/env python

"""create_trace1.py: creates a blokc IO trace file"""

import random

MAX_LBA = 1000000000000
START_TIME = 0
NUM_VOLUMES = 2
NUM_COMMANDS = 10

RANDOM_SEED = 1234

random.seed(RANDOM_SEED)

header = "Time_ms Volume Cmd Lba Len"

cmds = {'RD','WR'}


print header

this_time = START_TIME

for i in range(NUM_COMMANDS):
	this_lba = random.randint(1024,2048)
	this_volume = random.randint(0,1)
	this_time = this_time + random.randint(1,100) 
	this_len = 8
	this_cmd = 'RD'
	print str(this_time)+" "+str(this_volume)+" "+this_cmd+" "+str(this_lba)+" "+str(this_len)


exit (0)	 




