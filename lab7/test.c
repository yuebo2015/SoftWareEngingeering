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
	MenuConfig("MyCMD", "self-cmd with argment.", MyCMD);
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

int MyCMD(int argc, char *argv[])
{
	int ch;

	while ((ch = getopt(argc, argv, "a:b:c:d:")) != -1)
	{
		switch (ch)
		{
			case 'a':
				printf("%s \n", optarg);
				break;
			case 'b':
				printf("%s \n", optarg);
				break;
			case 'c':
				printf("%s \n", optarg);
				break;
			case 'd':
				printf("%s \n", optarg);
				break;
			default:
				printf("Wrong argments \n");
				break;
		}
	}
}
