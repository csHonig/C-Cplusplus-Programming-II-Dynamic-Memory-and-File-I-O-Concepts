output:	C2A2E1_main-Driver.o C2A2E1_CountIntBitsF.o
	gcc C2A2E1_main-Driver.o C2A2E1_CountIntBitsF.o -o output

C2A2E1_main-Driver.o: C2A2E1_main-Driver.c C2A2E1_CountBitsM.h
	gcc -c C2A2E1_main-Driver.c

C2A2E1_CountIntBitsF.o: C2A2E1_CountIntBitsF.c
	gcc -c C2A2E1_CountIntBitsF.c

run:
	output.exe