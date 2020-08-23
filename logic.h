#include<gtk/gtk.h>

#define AND 5
#define OR 10
#define NOT 15
#define NAND 20
#define NOR 25
#define XOR 30
#define XNOR 35

typedef struct node1{		//node of the circuit
	GtkWidget *image, *button1, *button2;
	int value, type;
	struct node1 *ip1, *ip2;
	int xplace, yplace;
}node1;


typedef struct led{
	node1 *output;
	GtkWidget *image;
	int ledxplace, ledyplace;
}led;

//global declarations of widgets
GtkWidget *window, *buttonnewfile, *buttonopenfile, *buttonsavefile, *buttonand, *buttonor, *buttonnot, *buttonswitch, *buttonled, *buttonrun, *buttonstop, *buttonnand, *buttonnor, *buttonxor, *buttonxnor, *buttonwire1, *label, *fixed1, *buttonconnect, *deleteledbutton;

GtkBuilder *builder;

void checkoutput( led *king );

void changeimage( led *king );

void valueset( node1 *temp );

int checknearby(int xtemp,int ytemp );

int selectled( int xtemp, int ytemp);

void line(int ax, int ay, int bx, int by );

