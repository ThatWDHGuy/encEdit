#include <stdio.h>
#include <gtk/gtk.h>

static gboolean button_press (GtkWidget *, GdkEvent *);
static void menuitem_response (gchar *);

int main( int argc,char *argv[] ){

    GtkWidget *window;
    GtkWidget *menu;
    GtkWidget *menu_bar;
    GtkWidget *root_menu;
    GtkWidget *menu_items;
    GtkWidget *vbox;
    GtkWidget *button;
    GtkWidget *textBox;
    char buf[128];
    int i;

    gtk_init (&argc, &argv);

    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET (window), 200, 100);
    gtk_window_set_title (GTK_WINDOW (window), "GTK Menu Test");
    g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
    menu = gtk_menu_new ();

    for (i = 0; i < 3; i++)
        {
            sprintf (buf, "Test-undermenu - %d", i);

            menu_items = gtk_menu_item_new_with_label (buf);

            gtk_menu_shell_append (GTK_MENU_SHELL (menu), menu_items);

	          g_signal_connect_swapped (menu_items, "activate",G_CALLBACK (menuitem_response), (gpointer) g_strdup (buf));
            gtk_widget_show (menu_items);
        }

    root_menu = gtk_menu_item_new_with_label ("Root Menu");

    gtk_widget_show (root_menu);

    gtk_menu_item_set_submenu (GTK_MENU_ITEM (root_menu), menu);

    vbox = gtk_vbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (window), vbox);
    gtk_widget_show (vbox);

    menu_bar = gtk_menu_bar_new ();
    gtk_box_pack_start (GTK_BOX (vbox), menu_bar, FALSE, FALSE, 2);
    gtk_widget_show (menu_bar);

    textBox = gtk_text_view_new();
    gtk_widget_show(textBox);
    gtk_menu_shell_append (GTK_MENU_SHELL (menu_bar), root_menu);

    gtk_widget_show (window);

    gtk_main ();

    return 0;
}


static gboolean button_press( GtkWidget *widget,GdkEvent *event ){

    if (event->type == GDK_BUTTON_PRESS) {
        GdkEventButton *bevent = (GdkEventButton *) event; 
        gtk_menu_popup(GTK_MENU (widget), NULL, NULL, NULL, NULL,bevent->button, bevent->time);
        return TRUE;
    }

    return FALSE;
}


static void menuitem_response( gchar *string )
{
    printf ("%s\n", string);
}
