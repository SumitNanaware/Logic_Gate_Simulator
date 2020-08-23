logic.o: logic.c logic.h
	gcc  -c `pkg-config gtk+-3.0 --cflags` logic.c `pkg-config gtk+-3.0 --libs`
Gate_Simulator: proj.c logic.o
	gcc -Wno-format `pkg-config gtk+-3.0 --cflags` proj.c logic.o -Wno-deprecated-declarations -Wno-format-security -lm `pkg-config gtk+-3.0 --libs`  -export-dynamic -o Gate_Simulator
