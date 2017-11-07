/*************************************************************************
	> File Name: test.h
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Nov 2017 12:22:04 AM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

#ifndef _TEST_H

int Version(int argc, char *argv[]);

int Quit(int argc, char *argv[]);

/* just print argment according to option */
int MyCMD(int argc, char *argv[]);

#define _TEST_H
#endif
