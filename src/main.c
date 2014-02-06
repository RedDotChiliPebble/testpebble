  //Es necesario empezar con esta linea!
#include <pebble.h>

  //Crear los elementos
Window *window;
TextLayer *title_layer;
TextLayer *subtitle_layer;
TextLayer *body_layer;
TextLayer *subbody_layer;
 
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
  subtitle_layer = text_layer_create(GRect(0, 30, 144, 30));
  text_layer_set_background_color(subtitle_layer, GColorClear);
  text_layer_set_text_color(subtitle_layer, GColorWhite);
  text_layer_set_font(subtitle_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));

  //La linea siguiente es para mostrar el texto en el frente de la ventana *este se verá por sobre el anterior
  layer_add_child(window_get_root_layer(window), (Layer*) subtitle_layer);
  text_layer_set_text(subtitle_layer, "12345678901234");

  //Configuración de los elementos de la ventana
  body_layer = text_layer_create(GRect(0, 60, 144, 60));
  text_layer_set_background_color(body_layer, GColorClear);
  text_layer_set_text_color(body_layer, GColorWhite);
  text_layer_set_font(body_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18));

  //La linea siguiente es para mostrar el texto en el frente de la ventana *este se verá por sobre el anterior
  layer_add_child(window_get_root_layer(window), (Layer*) body_layer);
  text_layer_set_text(body_layer, "12345678901234567890 12345678901234567890");

  //Configuración de los elementos de la ventana
  subbody_layer = text_layer_create(GRect(0, 105, 144, 90));
  text_layer_set_background_color(subbody_layer, GColorClear);
  text_layer_set_text_color(subbody_layer, GColorWhite);
  text_layer_set_font(subbody_layer, fonts_get_system_font(FONT_KEY_GOTHIC_14));

  //La linea siguiente es para mostrar el texto en el frente de la ventana *este se verá por sobre el anterior
  layer_add_child(window_get_root_layer(window), (Layer*) subbody_layer);
  text_layer_set_text(subbody_layer, "123456789012345678901234 123456789012345678901234");

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
  text_layer_destroy(title_layer);
  text_layer_destroy(subtitle_layer);
  text_layer_destroy(body_layer);
  text_layer_destroy(subbody_layer);
  window_destroy(window);
}
 
int main(void)
{
  init();
  app_event_loop();
  deinit();
}
