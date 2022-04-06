#include <sinsp.h>
#define __STDC_FORMAT_MACROS
#include "libs.h"

CScapInspector ScapInspNew() {
  sinsp *inspector = new sinsp();
  return (void *)inspector;
}

void ScapInspFree(CScapInspector ins) {
  sinsp *inspector = (sinsp *)ins;
  delete inspector;
}

int ScapInspNext(CScapInspector ins, CScapEvent *ev) {
  sinsp *inspector = (sinsp *)ins;
  sinsp_evt **evt = (sinsp_evt **)ev;
  return inspector->next(evt);
}

void ScapInspHostAndPortResolve(CScapInspector ins, int resolve) {
  sinsp *inspector = (sinsp *)ins;
  inspector->set_hostname_and_port_resolution_mode((resolve == 1));
}

void ScapSetSnapLen(CScapInspector ins, int snaplen) {
  sinsp *inspector = (sinsp *)ins;
  inspector->set_snaplen(snaplen);
}

int ScapInspOpen(CScapInspector ins, char *file) {
  sinsp *inspector = (sinsp *)ins;
  int res = 1;
  try {
    inspector->open(file);
  } catch (sinsp_exception e) {
    res = 0;
  }
  return res;
}
void ScapInspClose(CScapInspector ins) {
  sinsp *inspector = (sinsp *)ins;
  try {
    inspector->close();
  } catch (sinsp_exception e) {
  }
}
