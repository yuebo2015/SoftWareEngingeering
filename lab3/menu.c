/*****************************************************************************/
/* Copyright (C) yuebowhu@163.com, YB, 2014-2015							 */
/* 																			 */
/*																			 */
/* FILE NAME				:	menu.c										 */
/* PRINCIPAL AUTHOR			:	YUEBO										 */
/* SUBSYSTEM NAME			:	menu										 */
/* MODULE NAME				:	menu										 */
/* LANGUAGE					:	C											 */
/* TARGET ENVIRONMENT		:	ANY											 */
/* DATE OF FIRST RELEASE	:	2017/10/08									 */
/* DESCRIPTION				: 	This is a menu program						 */
/*****************************************************************************/

/*
 * Revision log:
 *
 * Created by YB, 2014/08/31
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"

#define CMD_MAX_LEN 128
#define DESC_LEN	1024
#define CMD_NUM		10
#define TRUE		1


int main(int argc, char *argv[])
{

	char cmd[CMD_MAX_LEN];
	tDataNode *p = head;
    printf( "******************************DESCRIPTION************************\n"
            "*\t\t\t\t\t\t\t\t*\n"
            "*\tThis menu program is coded by YB. Version 1.0\t\t*\n"
            "*\t\t\t\t\t\t\t\t*\n"
            "*\thelp\t\tShow this help list\t\t\t*\n"
            "*\tls\t\tList files\t\t\t\t*\n"
            "*\tquit\t\tQuit menu program\t\t\t*\n"
            "*\tversion\t\tshow release version\t\t\t*\n"
            "*\t\t\t\t\t\t\t\t*\n"
                "*****************************************************************\n\n"
    );	

	/* cmd line begines */
	while (TRUE)
	{
		
		printf(">>>");
		scanf("%s", cmd);
		p = FindCmd(head, cmd);
		if (p != NULL)
		{
			p->handler();
		}
        else
        {
            HandleException(); 
        }


	}

	return 0;
}



















