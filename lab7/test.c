/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Nov 2017 10:24:39 PM CST
 ************************************************************************/
#include "test.h"

int main(int argc, char *argv[])
{
	MenuConfig("version", "Display Version.", Version);
	MenuConfig("quit", "Exit from main function.", Quit);
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

