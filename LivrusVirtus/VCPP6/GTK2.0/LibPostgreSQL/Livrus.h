#ifndef LIVRUS_H
#define LIVRUS_H

#include "resource.h"

#ifdef G_OS_WIN32
  char *package_prefix;
  char *package_datadir;
#endif

int main(int argc, char *argv[]);

#endif