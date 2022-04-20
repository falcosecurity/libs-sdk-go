#include "libs.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SCAP_TIMEOUT_MS 30

static int s_running;

void signal_handler(int i) { s_running = 0; }

int main(int argc, char **argv) {
  signal(SIGINT, signal_handler);
  signal(SIGTERM, signal_handler);

  if (argc > 2) {
    printf("usage: ./cscap [<scap file>]\n");
    exit(1);
  }
  
  printf("Starting cscap\n");
  
  CScapInspector inspector = ScapInspNew();
  ScapInspHostAndPortResolve(inspector, 0);
  if (argc == 2) {
     printf("Opening file %s\n", argv[1]);
     ScapInspOpen(inspector, argv[1]);
     printf("Opened file...\n");
  } else {
     printf("Starting live capture\n");
     int r = ScapInspOpenLive(inspector, SCAP_TIMEOUT_MS);
     if (r == 0) {
        printf("Unable to start live capture\n");
        exit(1);
     }
     printf("Started live capture...\n");
  }
  
  ScapSetSnapLen(inspector, 0);
  
  CScapEvent evt = 0;
  s_running = 1;
  while (s_running) {
    int res = ScapInspNext(inspector, &evt);
    if (res == C_SCAP_TIMEOUT) {
      // perform timeout checks
    } else if (res == C_SCAP_EOF) {
      printf("EOF...\n");
      break;
    } else if (res != C_SCAP_SUCCESS) {
      printf("Failure...");
      break;
    } else {
      printf("Syscall: %s\n", ScapEvGetName(evt));
    }
  }
  ScapInspClose(inspector);
  ScapInspFree(inspector);
}
