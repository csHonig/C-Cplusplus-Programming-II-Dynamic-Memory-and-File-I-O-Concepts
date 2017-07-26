

output: C2A2E2_Rotate.o C2A2E2_main-Driver.o C2A2E2_CountIntBitsF.o
	g++ -o output C2A2E2_Rotate.o C2A2E2_main-Driver.o C2A2E2_CountIntBitsF.o 

C2A2E2_Rotate.o: C2A2E2_Rotate.cpp
	g++ -c C2A2E2_Rotate.cpp

C2A2E2_main-Driver.o: C2A2E2_main-Driver.cpp
	g++ -c C2A2E2_main-Driver.cpp

C2A2E2_CountIntBitsF.o: C2A2E2_CountIntBitsF.cpp
	g++ -c C2A2E2_CountIntBitsF.cpp

all: run

run: 
	output.exe


