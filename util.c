/* See LICENSE file for copyright and license details. */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wordexp.h>
#include "util.h"

void
die(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	if (fmt[0] && fmt[strlen(fmt)-1] == ':') {
		fputc(' ', stderr);
		perror(NULL);
	} else {
		fputc('\n', stderr);
	}

	exit(1);
}

void *
ecalloc(size_t nmemb, size_t size)
{
	void *p;

	if (!(p = calloc(nmemb, size)))
		die("calloc:");
	return p;
}
// war crimes
char *shell_to_realpath(const char *cmd){
	const char *new_cmd;
	char *to_return;
	wordexp_t wx;

	wordexp(cmd, &wx, 0);
	new_cmd=wx.we_wordv[0];

	to_return = malloc(strlen(new_cmd)+1);
	strcpy(to_return, new_cmd);
	wordfree(&wx);
	return to_return;
}
