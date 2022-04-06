#include "libs.h"
#include <cstdio>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc <= 1) {
    printf("usage: ./cscap <scap file>\n");
    exit(1);
  }

  CScapInspector inspector = ScapInspNew();
  ScapInspHostAndPortResolve(inspector, 0);
  printf("Opening file %s\n", argv[1]);
  ScapInspOpen(inspector, argv[1]);
  printf("Opened file...\n");
  ScapSetSnapLen(inspector, 0);

  CScapEvent evt = 0;

  while (true) {
    int res = ScapInspNext(inspector, &evt);
    if (res == C_SCAP_TIMEOUT) {
      printf("Scap timeout...\n");
    } else if (res == C_SCAP_EOF) {
      printf("EOF...\n");
      break;
    } else if (res != C_SCAP_SUCCESS) {
      printf("Failure...");
      break;
    }
    printf("Syscall: %s\n", ScapEvGetName(evt));
  }
  ScapInspClose(inspector);
  ScapInspFree(inspector);
}
