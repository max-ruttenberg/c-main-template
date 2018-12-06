#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

#define pr_usage(fmt, ...)			\
    fprintf(stderr, fmt, ##__VA_ARGS__)

static const char *execname = "";

static void base_usage(const char *name, const char *help)
{
    pr_usage("\t%s\t%s\n", name, help);
}

static void argument_usage(const char *argname, const char *arghelp)
{
    base_usage(argname, arghelp);
}

static void option_usage(const char *opname, const char *ophelp)
{
    base_usage(opname, ophelp);
}
static void usage()
{
    pr_usage("usage: %s [OPTIONS] ARG1\n", execname);

    pr_usage("arguments:\n");
    argument_usage("ARG1", "placeholder");

    pr_usage("options:\n");
    option_usage("-h,--help", "Print this help message");    
}

int main(int argc, char *argv[])
{
    static struct option options [] = {
	{ "help" , 0 , 0, 'h' },
	{ /* sentinal */ }
    };
    static const char * opstring = "h";
    int ch;
    
    execname = argv[0];

    // process options
    while ((ch = getopt_long(argc, argv, opstring, options, NULL)) != -1) {
	switch (ch) {
	case 'h':
	    usage();
	    exit(0);
	default:
	    usage();
	    exit(1);
	}
    }

    argc -= optind;
    argv += optind;

    // rest of code here
    
    return 0;
}
