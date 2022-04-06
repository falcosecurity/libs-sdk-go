#include "sinsp.h"
#include <cstdio>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc <= 1) {
    printf("usage: ./cscap <scap file>\n");
    exit(1);
  }

  sinsp *inspector = new sinsp();
  inspector->set_hostname_and_port_resolution_mode(false);
  printf("Opening file %s\n", argv[1]);
  inspector->open(argv[1]);
  printf("Opened file...\n");
  inspector->set_snaplen(0);
  sinsp_evt *evt = 0;

  while (true) {
    int res = inspector->next(&evt);
    if (res == SCAP_TIMEOUT) {
      printf("Scap timeout...\n");
    } else if (res == SCAP_EOF) {
      printf("EOF...\n");
      break;
    } else if (res != SCAP_SUCCESS) {
      printf("Failure...\n");
      break;
    }
    printf("Syscall: %s\n", evt->get_name());
  }
  inspector->close();
  delete inspector;
}
