  //Es necesario empezar con esta linea!
#include <pebble.h>

  //Crear los elementos
Window *window;
TextLayer *title_layer;
TextLayer *text_layer;
 
void window_load(Window *window)
{
  //Configuración de los elementos de la ventana
  title_layer = text_layer_create(GRect(0, 0, 144, 168));
  text_layer_set_background_color(title_layer, GColorBlack);
  text_layer_set_text_color(title_layer, GColorWhite);
  text_layer_set_font(title_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));

  //La linea siguiente es para mostrar el texto en el frente de la ventana
  layer_add_child(window_get_root_layer(window), (Layer*) title_layer);
  text_layer_set_text(title_layer, "Titulo!");

  //Configuración de los elementos de la ventana
  text_layer = text_layer_create(GRect(0, 30, 144, 30));
  text_layer_set_background_color(text_layer, GColorClear);
  text_layer_set_text_color(text_layer, GColorWhite);
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));

  //La linea siguiente es para mostrar el texto en el frente de la ventana *este se verá por sobre el anterior
  layer_add_child(window_get_root_layer(window), (Layer*) text_layer);
  text_layer_set_text(text_layer, "12345678901234");

}
void window_unload(Window *window)
{
  //Esto es una vez que la ventana se cierra para liberar espacio se eliminana los elementos
	
}
 
void init()
{
  //Iniciamos la funcionalidad
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  //Esto hace que la ventana se quede y no haga loop
  window_stack_push(window, true);
}
 
void deinit()
{
  //Desiniciamos o Cerramos la funcionalidad
  text_layer_destroy(text_layer);
  window_destroy(window);
}
 
int main(void)
{
  init();
  app_event_loop();
  deinit();
}
