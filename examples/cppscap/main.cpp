#include <sinsp.h>
#include <cstdio>
#include <csignal>
#include <stdlib.h>

bool static s_running;

void signal_handler(int /*i*/) { s_running = false; }

int main(int argc, char **argv) {
  struct sigaction sigHandler {};
  sigHandler.sa_handler = signal_handler;
  sigemptyset(&sigHandler.sa_mask);
  sigHandler.sa_flags = 0;

  sigaction(SIGINT, &sigHandler, nullptr);
  sigaction(SIGTERM, &sigHandler, nullptr);

  if (argc > 2) {
    printf("usage: ./cppscap [<scap file>]\n");
    exit(1);
  }

  printf("Starting cppscap\n");

  sinsp *inspector = new sinsp();
  inspector->set_hostname_and_port_resolution_mode(false);
  if (argc == 2) {
    printf("Opening file %s\n", argv[1]);
    inspector->open(argv[1]);
    printf("Opened file...\n");
  } else {
     printf("Starting live capture\n");
     try {
        inspector->open();
     } catch (sinsp_exception const&) {
        printf("Unable to start live capture\n");
        exit(1);
     }
     printf("Started live capture...\n");
  }

  inspector->set_snaplen(0);
  
  sinsp_evt *evt = 0;
  s_running = true;
  while (s_running) {
    int res = inspector->next(&evt);
    if (res == SCAP_TIMEOUT) {
      // perform timeout checks
    } else if (res == SCAP_EOF) {
      printf("EOF...\n");
      break;
    } else if (res != SCAP_SUCCESS) {
      printf("Failure...\n");
      break;
    } else {
      printf("Syscall: %s\n", evt->get_name());
    }
  }
  inspector->close();
  delete inspector;
}
