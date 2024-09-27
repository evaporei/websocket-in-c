#include <http.h>

void on_open(ws_s *ws) {
    fprintf(stderr, "ON OPENNN\n");
    websocket_write(ws, (fio_str_info_s){.data = "{ \"type\": \"ping\" }", .len = 18}, 1);
}
void on_message(ws_s *ws, fio_str_info_s msg, uint8_t is_text) {
    fprintf(stderr, "ON MESSAGE: %s\n", msg.data);
}
void on_shutdown(ws_s *ws) {
    fprintf(stderr, "ON SHUTDOWN\n");
}

int main(int argc, char const *argv[]) {
  websocket_connect("localhost:6666",
               .on_message = on_message,
               .on_open = on_open,
               .on_shutdown = on_shutdown);
  fio_start(.threads = 1);
  return 0;
}
