#include <gtk/gtk.h>

static void
button_clicked (GtkButton *button,
                GObject *other_label)
{
  g_object_set (other_label, "label", "YEAH!", NULL);
}

GObject *
test_gtk3 (GObject *other_label)
{
  GtkWidget *window, *label, *vbox, *button, *res;
  char *str;
  pid_t pid;

  res = NULL;
  
  pid = getpid ();

  gtk_init (0, NULL);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  vbox = gtk_vbox_new (FALSE, 2);
  gtk_container_add (GTK_CONTAINER (window), vbox);

  str = g_strdup_printf ("This is pid %d, I'm running gtk %d.%d.%d",
                         pid,
                         GTK_MAJOR_VERSION,
                         GTK_MINOR_VERSION,
                         GTK_MICRO_VERSION);
  label = gtk_label_new (str);

  gtk_container_add (GTK_CONTAINER(vbox), label);

  if (other_label == NULL)
    {
      res = label = gtk_label_new ("");
      gtk_container_add (GTK_CONTAINER(vbox), label);
    }
  else
    {
      button = gtk_button_new_with_label ("Really?");
      gtk_container_add (GTK_CONTAINER(vbox), button);
      g_signal_connect (button, "clicked", G_CALLBACK (button_clicked), other_label);
    }

  gtk_widget_show_all (window);
  return G_OBJECT (res);
}
