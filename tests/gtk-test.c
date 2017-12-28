#include <gtk/gtk.h>
#include "../src/cmk-gtk.h"

int main(int argc, char **argv)
{
	gtk_init(&argc, &argv);

	// Create window
	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Cmk-Gtk Test");
	gtk_widget_set_size_request(window, 20, 20);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_widget_set_valign(vbox, GTK_ALIGN_FILL);
	gtk_widget_set_halign(vbox, GTK_ALIGN_FILL);
	gtk_widget_show(vbox);

	GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_widget_show(box);
	//gtk_widget_set_valign(box, GTK_ALIGN_CENTER);
	gtk_widget_set_halign(box, GTK_ALIGN_CENTER);

	// Add widget
	CmkLabel *button = cmk_label_new_with_text("abcdefghijklm nopqrstuvwxyz");
	PangoLayout *layout = cmk_label_get_layout(button);
	pango_layout_set_ellipsize(layout, PANGO_ELLIPSIZE_END);
	//gtk_box_pack_start(GTK_BOX(box
	gtk_box_set_center_widget(GTK_BOX(box), CMK_GTK(button));
	//gtk_container_add(GTK_CONTAINER(vbox), CMK_GTK(button));
	gtk_widget_set_valign(CMK_GTK(button), GTK_ALIGN_CENTER);
	gtk_widget_set_halign(CMK_GTK(button), GTK_ALIGN_CENTER);
	gtk_widget_show(CMK_GTK(button));

	cmk_label_set_global_font_properties(96,
		pango_font_description_from_string("noto sans 11"),
		pango_font_description_from_string("noto sans mono 11"),
		false);

	//gtk_container_add(GTK_CONTAINER(vbox), box);
	gtk_box_set_center_widget(GTK_BOX(vbox), box);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	gtk_widget_show(window);

	gtk_main();
	return 0;
}