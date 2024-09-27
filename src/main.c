#include <http.h>

static void on_response(http_s *h);

int main(int argc, char const *argv[]) {
  http_connect("http://example.com/foo", NULL,
               .on_response = on_response);
  fio_start(.threads = 1);
  return 0;
}

static void on_response(http_s *h) {
  if (h->status_str == FIOBJ_INVALID) {
    /* first response is always empty, nothing was sent yet */
    http_finish(h);
    return;
  }
  /* Second response is actual response */
  FIOBJ r = http_req2str(h);
  fprintf(stderr, "%s\n", fiobj_obj2cstr(r).data);
  fio_stop();
}

