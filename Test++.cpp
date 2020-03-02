#include <stdio.h>
#include <gtk/gtk.h>

static gboolean button_press (GtkWidget *, GdkEvent *);
static void menuitem_response (gchar *);

struct menuButton{
    GtkWidget *button;
    GtkWidget *menu;
};

int main( int argc,char *argv[] ){

    GtkWidget *window;
    gtk_init (&argc, &argv);

    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET (window), 500, 400);
    gtk_window_set_title (GTK_WINDOW (window), "encEdit");
    g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);



    gtk_widget_show_all(window);
    gtk_main ();
    return 0;
}


/*static gboolean button_press( GtkWBidget *widget, GdkEvent *event ){

    if (event->type == GDK_BUTTON_PRESS) {
        gtk_menu_popup_at_widget(GTK_MENU (widget),*root_menu, 0, 0,NULL);
        return TRUE;
    }
    return FALSE;{
            "label": "gcc Gtk",
            "type": "shell",
            "command": "gcc `pkg-config --cflags gtk+-3.0` -o Test Test.c `pkg-config --libs gtk+-3.0`",
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
}*/


static void menuitem_response( gchar *string )
{
    printf ("%s\n", string);
}
