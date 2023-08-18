//Main menu
//by Gloriana y Viviana

//gcc -o menu menuController.c -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic -rdynamic
// ./menu

//Libraries
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <stdio.h>



//variables
GtkWidget *window;

//Main
int main(int argc, char *argv[]){
    GtkBuilder *builder; //GTK builder
    gtk_init(&argc, &argv); //start gtk

    builder = gtk_builder_new(); //create gtk ui builder
    gtk_builder_add_from_file(builder, "Pending.glade", NULL); //LOAD UI FILE



    

    //ASIGN VARIABLES
    window = GTK_WIDGET(gtk_builder_get_object(builder, "MyWindow")); //load window named MyWindow

    

    //gtk essentials
    gtk_builder_connect_signals(builder, NULL);
    g_object_unref(builder);



    gtk_widget_show_all(window); //show window
    gtk_main(); //run

    return 0;
}



void exit_app(){
    //printf("Exit app \n");
    gtk_main_quit(); // command to quit gtk program
}
