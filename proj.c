#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include <signal.h>
#include<unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include "logic.h"
#define max 30

node1 *circuit[max];	//main circuit
led *opt[5];	//pointers to output led in the circuit

gboolean on_button_press(GtkWidget* widget, GdkEventButton *event, GdkWindowEdge edge);
void getallwidgets( GtkBuilder *builder );


//some global variables that will be used in the circuit
int img , hor , ver , count, ocount;
int xclick[2], yclick[2], numberclk;
char *start = "xyz";
int snode[2], l;






//main function

int main( int argc, char *argv[]){
	
	gtk_init( &argc, &argv );
	builder = gtk_builder_new_from_file("logic.glade");
	
	getallwidgets( builder );
	g_signal_connect( window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	count = 0;
	ocount = 0;
	numberclk = 0;
	img = 0;
	gtk_builder_connect_signals(builder, NULL);
	hor = 30;
	ver = 150;
	l = 10;
	snode[0] = 40;
	snode[1] = 40;



	gtk_widget_show_all( window );
	gtk_main();
	return EXIT_SUCCESS;
}







//opens new file


void on_buttonopenfile_file_set( GtkFileChooserButton *b , gpointer data){
	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"Nothing Happens with this bUtton");
	GtkWidget *image;
	char *filename;
	filename = gtk_file_chooser_get_filename(  GTK_FILE_CHOOSER( b ) );
	image = gtk_image_new_from_file( filename );
	gtk_container_add( GTK_CONTAINER( fixed1 ), image );
	gtk_widget_show(image);
	gtk_fixed_move( GTK_FIXED(fixed1 ), image, hor , ver );
}

//should save the existing file, but not yet able to do it

void on_buttonsavefile_file_set( GtkFileChooserButton *b, gpointer data){
	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"You Have clicked save file button");
	GtkWidget *image;
	char *filename;
	filename = gtk_file_chooser_get_filename(  GTK_FILE_CHOOSER( b ) );
	image = gtk_image_new_from_file( filename );
	gtk_container_add( GTK_CONTAINER( fixed1 ), image );
	gtk_widget_show(image);
	gtk_fixed_move( GTK_FIXED(fixed1 ), image, hor , ver );
}


//new file
void on_buttonnewfile_file_set( GtkFileChooserButton *b, gpointer data){
	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"You have clicked new file");
	int new;
	new = main( 1, &start );
	gtk_builder_connect_signals(builder, NULL);

}




//wire funtion
void on_buttonwire1_clicked( GtkButton *b, gpointer data ){		//creates wire done
	int c,p, u ;
	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"WIre button clicked just now!!!");
	GtkWidget *image[100];	

	if( ( numberclk != 0 ) &&  !(numberclk % 2 ) ){
		if( xclick[1] < xclick[0]){
			if( yclick[1] < yclick[0] ){
		
				for( c = xclick[1] , u = 0 ; c < (xclick[0] - 50) ; c = c+ 10){
					
					image[u] = gtk_image_new_from_file( "wirefield.png" );
					gtk_container_add( GTK_CONTAINER( fixed1 ), image[u] );
					gtk_fixed_move( GTK_FIXED(fixed1 ), image[u], c , yclick[1] );
					gtk_widget_show(image[u]);
					u++;
				}
				for( p = yclick[1] , u = 0 ; p < yclick[0]  ; p = p + 10){
					
					image[u] = gtk_image_new_from_file( "wirefield.png" );
					gtk_container_add( GTK_CONTAINER( fixed1 ), image[u] );
					gtk_fixed_move( GTK_FIXED(fixed1 ), image[u], (xclick[ 0 ] - 50) , p );
					gtk_widget_show(image[u]);
					u++;
				}
				for( c = (xclick[0] - 50) , u = 0 ; c < xclick[ 0 ] ; c = c+ 10){
					
					image[u] = gtk_image_new_from_file( "wirefield.png" );
					gtk_container_add( GTK_CONTAINER( fixed1 ), image[u] );
					gtk_fixed_move( GTK_FIXED(fixed1 ), image[u], c , yclick[0] );
					gtk_widget_show(image[u]);
					u++;
				}
			}
			else{
		
				for( c = xclick[1] , u = 0 ; c < (xclick[0] - 50) ; c = c+ 10){
					
					image[u] = gtk_image_new_from_file( "wirefield.png" );
					gtk_container_add( GTK_CONTAINER( fixed1 ), image[u] );
					gtk_fixed_move( GTK_FIXED(fixed1 ), image[u], c , yclick[1] );
					gtk_widget_show(image[u]);
					u++;
				}
				for( p = yclick[1] , u = 0 ; p > yclick[0]  ; p = p - 10){
					
					image[u] = gtk_image_new_from_file( "wirefield.png" );
					gtk_container_add( GTK_CONTAINER( fixed1 ), image[u] );
					gtk_fixed_move( GTK_FIXED(fixed1 ), image[u], (xclick[ 0 ] - 50) , p );
					gtk_widget_show(image[u]);
					u++;
				}
				for( c = (xclick[0] - 50) , u = 0 ; c < xclick[ 0 ] ; c = c+ 10){
					
					image[u] = gtk_image_new_from_file( "wirefield.png" );
					gtk_container_add( GTK_CONTAINER( fixed1 ), image[u] );
					gtk_fixed_move( GTK_FIXED(fixed1 ), image[u], c , yclick[0] );
					gtk_widget_show(image[u]);
					u++;
				}
			}
		}
		else{
			if( yclick[1] < yclick[0] ){
		
				for( c = xclick[0] , u = 0 ; c < (xclick[1] - 50) ; c = c + 10){
					
					image[u] = gtk_image_new_from_file( "wirefield.png" );
					gtk_container_add( GTK_CONTAINER( fixed1 ), image[u] );
					gtk_fixed_move( GTK_FIXED(fixed1 ), image[u], c , yclick[0] );
					gtk_widget_show(image[u]);
					u++;
				}
				for( p = yclick[1] , u = 0 ; p < yclick[0]  ; p = p + 10){
					
					image[u] = gtk_image_new_from_file( "wirefield.png" );
					gtk_container_add( GTK_CONTAINER( fixed1 ), image[u] );
					gtk_fixed_move( GTK_FIXED(fixed1 ), image[u], (xclick[1] - 50 ) , p );
					gtk_widget_show(image[u]);
					u++;
				}
				for( c = (xclick[1] - 50) , u = 0 ; c < xclick[ 1 ] ; c = c + 10){
					
					image[u] = gtk_image_new_from_file( "wirefield.png" );
					gtk_container_add( GTK_CONTAINER( fixed1 ), image[u] );
					gtk_fixed_move( GTK_FIXED(fixed1 ), image[u], c , yclick[1] );
					gtk_widget_show(image[u]);
					u++;
				}
			}
			else{
		
				for( c = xclick[0] , u = 0 ; c < (xclick[1] - 50) ; c = c+ 10){
					
					image[u] = gtk_image_new_from_file( "wirefield.png" );
					gtk_container_add( GTK_CONTAINER( fixed1 ), image[u] );
					gtk_fixed_move( GTK_FIXED(fixed1 ), image[u], c , yclick[0] );
					gtk_widget_show(image[u]);
					u++;
				}
				for( p = yclick[0] , u = 0 ; p < yclick[1]  ; p = p + 10){
					
					image[u] = gtk_image_new_from_file( "wirefield.png" );
					gtk_container_add( GTK_CONTAINER( fixed1 ), image[u] );
					gtk_fixed_move( GTK_FIXED(fixed1 ), image[u], (xclick[ 1 ] - 50) , p );
					gtk_widget_show(image[u]);
					u++;
				}
				for( c = (xclick[1] - 50) , u = 0 ; c < xclick[ 1 ] ; c = c+ 10){
					
					image[u] = gtk_image_new_from_file( "wirefield.png" );
					gtk_container_add( GTK_CONTAINER( fixed1 ), image[u] );
					gtk_fixed_move( GTK_FIXED(fixed1 ), image[u], c , yclick[1] );
					gtk_widget_show(image[u]);
					u++;
				}
			}
		}
	}		
	
	hor = (hor + 10);
	ver = (ver + 10 );
	return ;
}



//function which adds a new and gate to the circuit
void on_buttonand_clicked( GtkButton *b, gpointer data ){
	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"AND button clicked");
	node1 *temp;
	temp = (node1 *)malloc( sizeof(node1));

	if( !temp ){
		printf("No memory Allocated!!!\n");
		return;
	}

	int m, n;
	m = hor;
	n = ver;
	//display of the node
	temp->button1 = gtk_toggle_button_new_with_label("");
	temp->button2 = gtk_toggle_button_new_with_label("");

	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->button1 );
	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->button2 );
	temp->image = gtk_image_new_from_file( "and1.png" );

	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->image );
	gtk_fixed_move( GTK_FIXED(fixed1 ), temp->image, hor+30 , ver+20 );


	gtk_widget_set_size_request( temp->button1, 2, 5);
	gtk_widget_set_size_request( temp->button2, 2, 5);
	g_signal_connect(G_OBJECT( window ), "button-press-event", G_CALLBACK(on_button_press), NULL);
	gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);
	
	gtk_fixed_move( GTK_FIXED( fixed1 ), temp->button1, m-10, n);
	gtk_fixed_move( GTK_FIXED( fixed1 ), temp->button2, m-10, n+35 );

	gtk_widget_show( temp->button1 );
	gtk_widget_show( temp->button2 );
	
	gtk_widget_show( temp->image );

	temp->ip1 = NULL;
	temp->ip2 = NULL;
	temp->type = AND;
	temp->xplace = ( hor + 40 );
	temp->yplace = ( ver + 10 );	//setting the initial conditions before adding the node

	circuit[ count ] = temp;	//including the element in the circuit
	count = count + 1;
	
	//printf( " Vlaue of count now is %d\n", count );	
	return;
	
}


//function which adds new or gate to the circuit
void on_buttonor_clicked( GtkButton *b, gpointer data ){
	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"OR button clicked");
	node1 *temp;
	temp = (node1 *)malloc( sizeof(node1));


	if( !temp ){
		printf("No memory Allocated!!!\n");
		return;
	}
	int m, n;
	m = hor;
	n = ver;

	temp->button1 = gtk_toggle_button_new_with_label("");
	temp->button2 = gtk_toggle_button_new_with_label("");
	
	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->button1 );
	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->button2 );
	
	temp->image = gtk_image_new_from_file( "or1.png" );

	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->image );
	gtk_fixed_move( GTK_FIXED(fixed1 ), temp->image, hor+30 , ver+20 );


	gtk_widget_set_size_request( temp->button1, 2, 5);
	gtk_widget_set_size_request( temp->button2, 2, 5);
	
	g_signal_connect(G_OBJECT( window ), "button-press-event", G_CALLBACK(on_button_press), NULL);
	gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);
	
	gtk_fixed_move( GTK_FIXED( fixed1 ), temp->button1, m-10, n);
	gtk_fixed_move( GTK_FIXED( fixed1 ), temp->button2, m-10, n+35 );
	

	gtk_widget_show( temp->button1 );
	gtk_widget_show( temp->button2 );
	
	gtk_widget_show( temp->image );

	temp->ip1 = NULL;
	temp->ip2 = NULL;
	temp->type = OR;
	temp->xplace = ( hor + 40 );
	temp->yplace = ( ver + 10 );

	circuit[ count ] = temp;	//including the element in the circuit
	count = count + 1;
	
	return;
}



//function that adds not gate to the circuit

void on_buttonnot_clicked( GtkButton *b, gpointer data ){
	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"NOT button clicked");
	node1 *temp;
	temp = (node1 *)malloc( sizeof(node1));


	if( !temp ){
		printf("No memory Allocated!!!\n");
		return;
	}

	int m, n;
	m = hor;
	n = ver;

	temp->button1 = gtk_toggle_button_new_with_label("");
	temp->button2 = gtk_toggle_button_new_with_label("");
	

	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->button1 );
	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->button2 );
	
	temp->image = gtk_image_new_from_file( "not1.png" );

	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->image );
	gtk_fixed_move( GTK_FIXED(fixed1 ), temp->image, hor+30 , ver+20 );


	gtk_widget_set_size_request( temp->button1, 2, 5);
	gtk_widget_set_size_request( temp->button2, 2, 5);
	
	g_signal_connect(G_OBJECT( window ), "button-press-event", G_CALLBACK(on_button_press), NULL);
	gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);
	
	gtk_fixed_move( GTK_FIXED( fixed1 ), temp->button1, m-10, n);
	gtk_fixed_move( GTK_FIXED( fixed1 ), temp->button2, m-10, n+35 );
	

	gtk_widget_show( temp->button1 );
	gtk_widget_show( temp->button2 );
	
	gtk_widget_show( temp->image );



	temp->ip1 = NULL;
	temp->ip2 = NULL;
	temp->type = NOT;
	temp->xplace = ( hor + 40 );
	temp->yplace = ( ver + 10 );


	circuit[ count ] = temp;	//including the element in the circuit
	count = count + 1;
	
	return;
}


//ideally should  work as switch but not working in this case
void on_buttonswitch_clicked( GtkButton *b, gpointer data ){
	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"Switch button clicked just now!!! BUT SORRY THERE NOTHING TO BE DONE WITH THIS BUTTON!!!\nDirectly click the gate you want to test!!!");

}



//adds new led output in the circuit
void on_buttonled_clicked( GtkButton *b, gpointer data ){
	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"LED button clicked");
	led *temp;
	temp = ( led *)malloc(sizeof(led));


	if( !temp ){
		printf("No memory Allocated!!!\n");
		return;
	}

	temp->output = NULL;
	temp->image = gtk_image_new_from_file( "ledoff.png" );
	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->image );
	gtk_fixed_move( GTK_FIXED(fixed1 ), temp->image, hor , ver - 50 );
	gtk_widget_show(temp->image);
	temp->ledxplace = hor;
	temp->ledyplace = (ver - 50);
	
	opt[ocount] = temp;
	ocount = ocount + 1;
	return;
	
	
}

//adds a new nand gate to the circuit
void on_buttonnand_clicked( GtkButton *b, gpointer data ){
	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"NAND button clicked");
	node1 *temp;
	temp = (node1 *)malloc( sizeof(node1));

	
	if( !temp ){
		printf("No memory Allocated!!!\n");
		return;
	}
	int m, n;
	m = hor;
	n = ver;

	temp->button1 = gtk_toggle_button_new_with_label("");
	temp->button2 = gtk_toggle_button_new_with_label("");
	

	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->button1 );
	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->button2 );
	
	temp->image = gtk_image_new_from_file( "nand1.png" );

	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->image );
	gtk_fixed_move( GTK_FIXED(fixed1 ), temp->image, hor+30 , ver+20 );


	gtk_widget_set_size_request( temp->button1, 2, 5);
	gtk_widget_set_size_request( temp->button2, 2, 5);
	
	g_signal_connect(G_OBJECT( window ), "button-press-event", G_CALLBACK(on_button_press), NULL);
	gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);
	
	gtk_fixed_move( GTK_FIXED( fixed1 ), temp->button1, m-10, n);
	gtk_fixed_move( GTK_FIXED( fixed1 ), temp->button2, m-10, n+35 );
	

	gtk_widget_show( temp->button1 );
	gtk_widget_show( temp->button2 );
	
	gtk_widget_show( temp->image );

	temp->ip1 = NULL;
	temp->ip2 = NULL;
	temp->type = NAND;
	temp->xplace = ( hor + 40 );
	temp->yplace = ( ver + 10 );

	circuit[ count ] = temp;	//including the element in the circuit
	count = count + 1;

	return;
}


//Function which adds a new nor gate to the circuit
void on_buttonnor_clicked( GtkButton *b, gpointer data ){
	
	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"NOR button clicked");
	node1 *temp;
	temp = (node1 *)malloc( sizeof(node1));
	
	
	if( !temp ){
		printf("No memory Allocated!!!\n");
		return;
	}
	int m, n;
	m = hor;
	n = ver;

	temp->button1 = gtk_toggle_button_new_with_label("");
	temp->button2 = gtk_toggle_button_new_with_label("");
	

	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->button1 );
	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->button2 );
	
	temp->image = gtk_image_new_from_file( "nor1.png" );

	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->image );
	gtk_fixed_move( GTK_FIXED(fixed1 ), temp->image, hor+30 , ver+20 );


	gtk_widget_set_size_request( temp->button1, 2, 5);
	gtk_widget_set_size_request( temp->button2, 2, 5);
	
	g_signal_connect(G_OBJECT( window ), "button-press-event", G_CALLBACK(on_button_press), NULL);
	gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);
	
	gtk_fixed_move( GTK_FIXED( fixed1 ), temp->button1, m-10, n);
	gtk_fixed_move( GTK_FIXED( fixed1 ), temp->button2, m-10, n+35 );
	

	gtk_widget_show( temp->button1 );
	gtk_widget_show( temp->button2 );
	
	gtk_widget_show( temp->image );

	temp->ip1 = NULL;
	temp->ip2 = NULL;
	temp->type = NOR;
	
	temp->xplace = ( hor + 40 );
	temp->yplace = ( ver + 10 );

	circuit[ count ] = temp;	//including the element in the circuit
	count = count + 1;
	return;
	

}


//function which adds a xor gate to the circuit
void on_buttonxor_clicked( GtkButton *b, gpointer data ){
	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"XOR button clicked");
	node1 *temp;
	temp = (node1 *)malloc( sizeof(node1));

	
	if( !temp ){
		printf("No memory Allocated!!!\n");
		return;
	}
	int m, n;
	m = hor;
	n = ver;

	temp->button1 = gtk_toggle_button_new_with_label("");
	temp->button2 = gtk_toggle_button_new_with_label("");
	
	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->button1 );
	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->button2 );
	
	temp->image = gtk_image_new_from_file( "xor1.png" );

	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->image );
	gtk_fixed_move( GTK_FIXED(fixed1 ), temp->image, hor+30 , ver+20 );


	gtk_widget_set_size_request( temp->button1, 2, 5);
	gtk_widget_set_size_request( temp->button2, 2, 5);
	
	g_signal_connect(G_OBJECT( window ), "button-press-event", G_CALLBACK(on_button_press), NULL);
	gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);
	
	gtk_fixed_move( GTK_FIXED( fixed1 ), temp->button1, m-10, n);
	gtk_fixed_move( GTK_FIXED( fixed1 ), temp->button2, m-10, n+35 );
	
	gtk_widget_show( temp->button1 );
	gtk_widget_show( temp->button2 );
	
	gtk_widget_show( temp->image );


	temp->ip1 = NULL;
	temp->ip2 = NULL;
	temp->type = XOR;
	temp->xplace = ( hor + 40 );
	temp->yplace = ( ver + 10 );

	circuit[ count ] = temp;	//including the element in the circuit
	count = count + 1;
	
	return;

}


//Function which adds a new xnor gate to the circuit
void on_buttonxnor_clicked( GtkButton *b, gpointer data ){
	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"XNOR button clicked");
	node1 *temp;
	temp = (node1 *)malloc( sizeof(node1));

	
	if( !temp ){
		printf("No memory Allocated!!!\n");
		return;
	}
	int m, n;
	m = hor;
	n = ver;

	temp->button1 = gtk_toggle_button_new_with_label("");
	temp->button2 = gtk_toggle_button_new_with_label("");
	

	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->button1 );
	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->button2 );
	
	temp->image = gtk_image_new_from_file( "xnor1.png" );

	gtk_container_add( GTK_CONTAINER( fixed1 ), temp->image );
	gtk_fixed_move( GTK_FIXED(fixed1 ), temp->image, hor+30 , ver+20 );


	gtk_widget_set_size_request( temp->button1, 2, 5);
	gtk_widget_set_size_request( temp->button2, 2, 5);
	
	g_signal_connect(G_OBJECT( window ), "button-press-event", G_CALLBACK(on_button_press), NULL);
	gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);
	
	gtk_fixed_move( GTK_FIXED( fixed1 ), temp->button1, m-10, n);
	gtk_fixed_move( GTK_FIXED( fixed1 ), temp->button2, m-10, n+35 );
	

	gtk_widget_show( temp->button1 );
	gtk_widget_show( temp->button2 );
	
	gtk_widget_show( temp->image );
	
	temp->ip1 = NULL;
	temp->ip2 = NULL;
	temp->type = XNOR;
	temp->xplace = ( hor + 40 );
	temp->yplace = ( ver + 10 );

	circuit[ count ] = temp;	//including the element in the circuit
	count = count + 1;
	
	return;
}



//Here the Function starts running
void on_buttonrun_clicked( GtkButton *b, gpointer data ){
	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"RUN button clicked, GO ahead and enjoy simulating the logic gates!!!");
	int i;
	
	for( i = 0; i < ocount; i++){
		if(opt[i]->output == NULL){
			printf("opt->output was empty\n");
			return;
		}
		
		checkoutput( opt[i] );
	}
	
	for( i = 0; i < ocount; i++){
		if( opt[i] )
		changeimage( opt[i] );
	}

	return;
}



//stop button, but nothing is to be done with this button
void on_buttonstop_clicked( GtkButton *b, gpointer data ){
	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"Stop button activated but nothing is going to stop !!!");
}


//connects a led to gate or a gate to gate
void on_buttonconnect_clicked( GtkButton *b, gpointer data ){
	node1 *temp1=NULL, *temp2=NULL;
	led *ltemp=NULL;

	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"if not working then first select the gates or led you want to connect !!!");
	
	if( l < 6 ){
		xclick[0] = opt[l]->ledxplace ;
		yclick[0] = (opt[l]->ledyplace + 30);
		ltemp = opt[l];
		l = 10;
	}
	if( snode[0] < 30){
		xclick[1] = circuit[ snode[0] ]->xplace + 10;
		yclick[1] = circuit[ snode[0] ]->yplace + 30;
	
		temp1 = circuit[ snode[0] ];
		snode[0] = 40;
		//printf("Set value of snode 0 to default\n");
		if( snode[1] < 30 ){
			xclick[0] = circuit[ snode[1] ]->xplace + 10;
			yclick[0] = circuit[ snode[1] ]->yplace + 30;
			temp2 = circuit[ snode[1] ];
			snode[1] = 40;
			//printf("Set value of snode 1 to default\n");
		}
	}
	numberclk = 2;
	if( temp1 ){
		if( ltemp ){
			ltemp->output = temp1 ;
		}
		else{
			if( temp2 ){
				if( temp2->ip1 == NULL ){
					temp2->ip1 = temp1;
				}
				else if( temp2->ip2 == NULL ){
					temp2->ip2 = temp1;
				}
			}
		}
	}
	
	on_buttonwire1_clicked( b, data );
	temp1 = NULL;
	temp2 = NULL;
	ltemp = NULL;
	return;

}



void on_deleteledbutton_clicked( GtkButton* b, gpointer data ){
	gtk_label_set_text( GTK_LABEL( label ), (const gchar *)"led delete button pressed just now !!!");

	int i, m;
	led *temp;
	i = selectled( hor, ver );
	//printf("Selected one led for delete at %d\n", i);

	if( i < 10){
		temp = opt[i];
		for( m =i ; m < ocount; m++ ){
			if( opt[m +1])
				opt[m] = opt[m + 1];
			//printf("Shifted something\n");
		}
		opt[ m ] = NULL;
		gtk_widget_hide( temp->image );
		free( temp->output );
		free( temp );
		ocount = ocount - 1;
		
	}
}

//function which provides the main information,  the x and y coordinates of the click
gboolean on_button_press(GtkWidget* widget, GdkEventButton *event, GdkWindowEdge edge) {
	int i = 0;
	
	if (event->type == GDK_BUTTON_PRESS) {
		if (event->button == 1) {
        		gtk_window_begin_move_drag(GTK_WINDOW(gtk_widget_get_toplevel(widget)), event->button, event->x_root, event->y_root, event->time);
			numberclk++;
			hor = event->x;
			ver = event->y;
			if( !(numberclk % 2) ){
				xclick[0] = event->x;
				yclick[0] = event->y;
			}
			else {
				xclick[1] = event->x;
				yclick[1] = event->y;
			}

			
			i = checknearby( event->x, event->y );

			
			if( i != 500 ){
				if( snode[0] == 40 ){
					snode[0] = i;
				}
				else{
					if( snode[1] == 40 ){
						snode[1] = i;
					}
				}
			}

			i = selectled( event->x, event->y );
			if( i != 500 ){
					l = i;
	
			}

          		return TRUE;
    		}
	}

	


	return FALSE;
}




//function which checks the nearby gates
int checknearby(int xtemp,int ytemp ){
	
	int i;
		for( i = 0; i < count; i++){
			if( (xtemp > ( (circuit[i]->xplace) - 30 )) && (xtemp < ( (circuit[i]->xplace) + 30 )) ){
				if( (ytemp > ( (circuit[i]->yplace) - 30 )) && (ytemp < ( (circuit[i]->yplace) + 30 )) ){
					printf(" found one widget node near the click\n");
					return i;
				}
			}
		}

	return 500;
}



//function that checks the nearby led
int selectled( int xtemp, int ytemp){

	int m;
		for(m = 0 ; m < ocount; m++){
			if( ( xtemp > (opt[m]->ledxplace) ) && ( xtemp < ( opt[m]->ledxplace) + 150) )
					if( ( ytemp > (opt[m]->ledyplace) ) && ( ytemp < ( opt[m]->ledyplace) + 100) ){
						printf("found one led\n");
						return m;
					}
			}
	return 500;
}


//function to get all widget pointer to the program i.e. to basic settings of window
void getallwidgets( GtkBuilder *builder ){
	

	window = GTK_WIDGET( gtk_builder_get_object( builder, "window" ) );
	buttonopenfile = GTK_WIDGET( gtk_builder_get_object( builder, "buttonopenfile" ) );
	buttonnewfile = GTK_WIDGET( gtk_builder_get_object( builder, "buttonnewfile" ) );
	buttonsavefile = GTK_WIDGET( gtk_builder_get_object( builder, "buttonsavefile" ) );
	buttonwire1 = GTK_WIDGET( gtk_builder_get_object( builder, "buttonwire1" ) );
	buttonand = GTK_WIDGET( gtk_builder_get_object( builder, "buttonand" ) );
	buttonor = GTK_WIDGET( gtk_builder_get_object( builder, "buttonor" ) );
	buttonnot = GTK_WIDGET( gtk_builder_get_object( builder, "buttonnot" ) );
	buttonswitch = GTK_WIDGET( gtk_builder_get_object( builder, "buttonswitch" ) );
	buttonled = GTK_WIDGET( gtk_builder_get_object( builder, "buttonled" ) );
	buttonrun = GTK_WIDGET( gtk_builder_get_object( builder, "buttonrun" ) );
	buttonstop = GTK_WIDGET( gtk_builder_get_object( builder, "buttonstop" ) );
	buttonnand = GTK_WIDGET( gtk_builder_get_object( builder, "buttonnand" ) );
	buttonnor = GTK_WIDGET( gtk_builder_get_object( builder, "buttonnor" ) );
	buttonxor = GTK_WIDGET( gtk_builder_get_object( builder, "buttonxor" ) );
	buttonxnor = GTK_WIDGET( gtk_builder_get_object( builder, "buttonxnor" ) );
	label = GTK_WIDGET( gtk_builder_get_object(builder, "label"));
	fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
	buttonconnect = GTK_WIDGET( gtk_builder_get_object(builder, "buttonconnect"));
	deleteledbutton = GTK_WIDGET( gtk_builder_get_object( builder, "deleteledbutton"));

	
	
	return;
}





