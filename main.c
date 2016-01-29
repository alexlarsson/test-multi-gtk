#include <gtk/gtk.h>

GObject *test_gtk3 (GObject *obj);
GObject *test_gtk2 (GObject *obj);

int
main (int argc, char *argv[])
{
  GObject *label;
  label = test_gtk3 (NULL);
  test_gtk2 (label);
  gtk_main ();
}
