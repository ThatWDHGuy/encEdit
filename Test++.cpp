#include <stdio.h>
#include <gtk/gtk.h>
#include <cstring>

static gboolean button_press (GtkWidget *, GdkEvent *);
static void menuitem_response (gchar *);
static void open_new(){

};

static void menu_response(GtkWidget *menu_item, gpointer data){
    if (strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "New") == 0){ // strings are equal    
        g_print("\'New\' pressed\n");

    } else if (strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "Exit") == 0){ // strings are equal    
        g_print("\'Exit\' pressed\n");
        gtk_main_quit();
    } else if (strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "About") == 0){ // strings are equal    
        g_print("\'About\' pressed\n");
    }
};

int main(int argc,char *argv[]){

    GtkWidget *window, *menu_bar, *menu_item, *file_menu, *help_menu , *box, *button, *text_box;
    gtk_init (&argc, &argv);

    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET (window), 500, 400);
    gtk_window_set_title (GTK_WINDOW (window), "encEdit");
    g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);

    menu_bar = gtk_menu_bar_new();
    file_menu = gtk_menu_new();
    help_menu = gtk_menu_new();

    menu_item = gtk_menu_item_new_with_label("File");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), file_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);

    menu_item = gtk_menu_item_new_with_label("Help");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), help_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);

    menu_item = gtk_menu_item_new_with_label("New");
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);
    g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), NULL);

    menu_item = gtk_menu_item_new_with_label("Exit");
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);
    g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), NULL);

    menu_item = gtk_menu_item_new_with_label("About");
    gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), menu_item);
    g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), NULL);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    button = gtk_button_new_with_label("Yo"); // can be replaced by info bar at bottom
    text_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    gtk_box_pack_start(GTK_BOX(box), menu_bar, 0,0,0);
    gtk_box_pack_start(GTK_BOX(box), text_box, 1,1, 0);
    gtk_box_pack_start(GTK_BOX(box), button, 0,1,0);

    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show_all(window);
    gtk_main ();
    return 0;
};