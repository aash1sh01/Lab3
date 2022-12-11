default:
	make pipes_proc1
	make pipes_proc2
	make pipes_proc3
pipes_proc1: pipes_processes1.c
	gcc pipes_processes1.c -D_SVID_SOURCE -D_GNU_SOURCE -Wall -std=c99 -Werror=cpp -pedantic  -o pipes_proc1
	
pipes_proc2: pipes_processes2.c
	gcc pipes_processes2.c -D_SVID_SOURCE -D_GNU_SOURCE -Wall -std=c99 -Werror=cpp -pedantic  -o pipes_proc2

pipes_proc3: pipes_processes3.c
	gcc pipes_processes3.c -g -D_SVID_SOURCE -D_GNU_SOURCE -Wall -std=c99 -Werror=cpp -pedantic  -o pipes_proc3