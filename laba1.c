#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#define N 100

static const char *optString = "hf:s:";

static const struct option longOpts[] = {
	{ "help", no_argument, NULL, 'h' },
	{ "file", required_argument, NULL, 'f' },
	{ "string", required_argument, NULL, 's' },
	{ NULL, no_argument, NULL, 0 }
};

void func_r(FILE *file, char *str);
