#ifndef TRN_APPLICATION_H
#define TRN_APPLICATION_H

#include "game.h"
#include "window.h"

#ifdef __GNUC__
#  define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
#else
#  define UNUSED(x) UNUSED_ ## x
#endif

typedef struct
{
  TrnWindow* window;
  TrnGame* game;
} TrnGUI;

TrnGUI* trn_gui_new(int numberOfRows, int numberOfColumns, int delay);
void trn_gui_destroy(TrnGUI* gui);
gboolean on_key_press_event(GtkWidget *window,
                            GdkEventKey *event,
                            TrnGUI* gui);
gboolean on_preview_expose_event(GtkWidget *matrix, GdkEventExpose *event, TrnGUI* gui);
gboolean on_matrix_expose_event(GtkWidget *matrix, GdkEventExpose *event, TrnGUI* gui);

void trn_gui_update_view(TrnGUI* gui);
void trn_gui_update_labels(TrnGUI* gui);

#endif
