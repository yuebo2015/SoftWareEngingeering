/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Nov 2017 10:24:39 PM CST
 ************************************************************************/
#include "test.h"
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	MenuConfig("version", "Display Version.", Version);
	MenuConfig("quit", "Exit from main function.", Quit);
	MenuConfig("ls", "List all files in current direction.", Ls);
	ExecuteMenu();
	
    return 0;
}

int Version(int argc, char *argv[])
{
    printf("Version is 1.0.\n");
}

int Quit(int argc, char *argv[])
{
    exit(0);
}

int Ls(int argc, char *argv[])
{
    char cmd[256] = {0};
    int loopi;

    for (loopi = 0; loopi < argc; loopi++)
    {
        strcat(cmd, argv[loopi]);
        strcat(cmd, " ");
    }
    system(cmd);
}
