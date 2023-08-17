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
GtkWidget *floydButton;
GtkWidget *tbdButton1;
GtkWidget *tbdButton2;
GtkWidget *tbdButton3;
GtkWidget *tbdButton4;

static gboolean on_button_enter(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    printf("entra");
    const gchar *tooltip_text = (const gchar *)user_data;
    gtk_widget_set_tooltip_text(widget, tooltip_text);
    return TRUE;
}

//Main
int main(int argc, char *argv[]){
    GtkBuilder *builder; //GTK builder
    gtk_init(&argc, &argv); //start gtk


    builder = gtk_builder_new(); //create gtk ui builder
    gtk_builder_add_from_file(builder, "Menu_UI.glade", NULL); //LOAD UI FILE

    //ASIGN VARIABLES
    window = GTK_WIDGET(gtk_builder_get_object(builder, "MyWindow")); //load window named MyWindow

    floydButton = GTK_WIDGET(gtk_builder_get_object(builder, "floyd_button"));
    tbdButton1 = GTK_WIDGET(gtk_builder_get_object(builder, "tbd_button1"));
    tbdButton2 = GTK_WIDGET(gtk_builder_get_object(builder, "tbd_button2"));
    tbdButton3 = GTK_WIDGET(gtk_builder_get_object(builder, "tbd_button3"));
    tbdButton4 = GTK_WIDGET(gtk_builder_get_object(builder, "tbd_button4"));
    
    g_signal_connect(floydButton, "enter-notify-event", G_CALLBACK(on_button_enter), "Descripción del algoritmo de Floyd");
    g_signal_connect(tbdButton1, "enter-notify-event", G_CALLBACK(on_button_enter), "Este algoritmo aún no está disponible");
    g_signal_connect(tbdButton2, "enter-notify-event", G_CALLBACK(on_button_enter), "Este algoritmo aún no está disponible");
    g_signal_connect(tbdButton3, "enter-notify-event", G_CALLBACK(on_button_enter), "Este algoritmo aún no está disponible");
    g_signal_connect(tbdButton4, "enter-notify-event", G_CALLBACK(on_button_enter), "Este algoritmo aún no está disponible");

    //gtk essentials
    gtk_builder_connect_signals(builder, NULL);
    g_object_unref(builder);

    gtk_widget_show_all(window); //show window
    gtk_main(); //run

    return 0;
}



void exit_app(){
    printf("Exit app \n");
    gtk_main_quit(); // command to quit gtk program
}

void tbd_button_clicked(){
    printf("Archivo pending ejecutandose");
}

void floyd_button_clicked(){
    printf("Algoritmo de las rutas más cortas ejecutandose");
}