
#include<stdio.h>
#include<stdlib.h>
#include "logic.h"
#include<gtk/gtk.h>

//sets the value of the output
void checkoutput( led *king ){
	node1 *temp = NULL;
	
	temp = king->output;

	if( temp == NULL ){
		printf("Nothing was given to temp\n" );
		return;
	}
	valueset( temp );
	return;
}		

//changes the output when value is set			
void changeimage( led *king ){

	char filename1[] = "ledon.png";
	char filename2[] = "ledoff.png";
	if( king->output->value == 0 ){
		if( king->image )
			gtk_container_remove( GTK_CONTAINER(fixed1), king->image );

		king->image = gtk_image_new_from_file( filename2 );
		gtk_container_add( GTK_CONTAINER( fixed1 ), king->image );
		gtk_fixed_move( GTK_FIXED(fixed1 ), king->image, king->ledxplace , king->ledyplace );
		gtk_widget_show( king->image );
	}
		
	if( king->output->value == 1 ){
		if( king->image )
			gtk_container_remove( GTK_CONTAINER(fixed1), king->image );

		king->image = gtk_image_new_from_file( filename1 );
		gtk_container_add( GTK_CONTAINER( fixed1 ), king->image );
		gtk_fixed_move( GTK_FIXED(fixed1 ), king->image, king->ledxplace , king->ledyplace );
		gtk_widget_show( king->image );
	}

	return;
}


//runs the circuit		
void valueset( node1 *temp ){
	int n1, n2;
	if( temp->ip1 == NULL ){
		n1 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON( temp->button1 ));
		n2 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON( temp->button2 ));
	}
	else{
		valueset( temp->ip1 );
		n1 = temp->ip1->value;
		
		if( temp->ip2){
			valueset( temp->ip2 );
			n2 = temp->ip2->value;
		}

	}
	

	switch( temp->type ){
		case AND:
			printf( " value of input 1\t%d\t %d\t value of input 2\t type and\n", n1, n2);
			temp->value = ( n1 && n2 );
			break;
		case OR:
			printf( " value of input 1\t%d\t %d\t value of input 2\t type or\n", n1, n2);
			temp->value = ( n1 || n2 );
			break;
		case NOT:
			printf( " value of input 1\t%d\t %d\t value of input 2\t type not\n", n1, n2);
			temp->value = ( !(n1) );
			break;
		case NAND:
			printf( " value of input 1\t%d\t %d\t value of input 2\ttype nand\n", n1, n2);
			temp->value = (	!( n1 && n2 ) );
			break;
		case NOR:
			printf( " value of input 1\t%d\t %d\t value of input 2\t type nor\n", n1, n2);
			temp->value = 	!( n1 || n2 );
			break;
		case XOR:
			printf( " value of input 1\t%d\t %d\t value of input 2\t type xor\n", n1, n2);
			temp->value = 	( ( n1 && ( !n2 ) ) || ( ( !n1 ) && n2) );
			break;
		case XNOR:
			printf( " value of input 1\t%d\t %d\t value of input 2\t type xnor\n", n1, n2);
			temp->value = ( !( ( n1 && ( !n2 ) ) || ( ( !n1 ) && n2) ) );
			break;
		default:
			printf("Did not match any case while computing!!!\n");
			break;
	}
	return;
}


