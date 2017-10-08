/*****************************************************************************/
/* Copyright (C) yuebowhu@163.com, YB, 2017-2018                             */
/*                                                                           */
/*                                                                           */
/* FILE NAME                :   linkList.c                                       */
/* PRINCIPAL AUTHOR         :   YUEBO                                        */
/* SUBSYSTEM NAME           :   menu                                         */
/* MODULE NAME              :   menu                                         */
/* LANGUAGE                 :   C                                            */
/* TARGET ENVIRONMENT       :   ANY                                          */
/* DATE OF FIRST RELEASE    :   2017/10/08                                   */
/* DESCRIPTION              :   This is a menu program                       */
/*****************************************************************************/

/*
 * Revision log:
 *
 * Created by YB, 2017/10/08
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"

tDataNode *FindCmd(tDataNode *head, char *cmd)
{
	if (head == NULL || cmd == NULL)	
	{
		return NULL;
	}
	tDataNode *p = head;
	while (p != NULL)
	{
		if (strcmp(p->cmd, cmd) == 0)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}



int ShowAllCmd(tDataNode *head)
{
	printf("Menu List:\n");
	tDataNode *p = head;
	while (p != NULL)
	{
		printf("%s - %s\n", p->cmd, p->desc);
		p = p->next;
	}
	return 0;
}



int Help()
{
	ShowAllCmd(head);
    return 0;
}

int Quit()
{
    exit(0);
}


int List()
{
    system("ls");
    return 0;
}

int Version()
{
	printf("version 1.0\n");
	return 0;
}

int HandleException()
{
    printf("Wrong cmd, please input again.\n");
    return 0;
}
