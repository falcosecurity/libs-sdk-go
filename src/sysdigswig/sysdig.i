%module sysdigswiglib 
%{
#define __STDC_FORMAT_MACROS
#define OUT
#include "sinsp.h"
%}
%include std_string.i
%include std_vector.i
%include "sinsp.h"
