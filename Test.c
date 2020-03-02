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
    GtkWidget *tool_bar;

    gtk_init (&argc, &argv);

    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET (window), 500, 400);
    gtk_window_set_title (GTK_WINDOW (window), "encEdit");
    g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);

    tool_bar = gtk_toolbar_new();

    GtkWidget *file_button;
    file_button = gtk_tool_item_new();


    gtk_widget_show (window);
    gtk_main ();
    return 0;
}


/*static gboolean button_press( GtkWidget *widget, GdkEvent *event ){

    if (event->type == GDK_BUTTON_PRESS) {
        gtk_menu_popup_at_widget(GTK_MENU (widget),*root_menu, 0, 0,NULL);
        return TRUE;
    }

    return FALSE;
}*/


static void menuitem_response( gchar *string )
{
    printf ("%s\n", string);
}
