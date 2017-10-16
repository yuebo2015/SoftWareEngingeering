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

int Help();
int Quit();
int Ls();

/* data struct and its operations */
typedef struct DataNode
{
	tLinkTable *pNext;
	char *cmd;
	char *desc;
	int (*handler)();
} tDataNode;

tDataNode *FindCmd(tLinkTable *head, char *cmd)
{
	tDataNode *pNode = (tDataNode *)GetLinkTableHead(head);

	while (pNode != NULL)
	{
		if (strcmp(pNode->cmd, cmd) == 0)
		{
			return pNode;
		}
		pNode = (tDataNode *)GetNextLinkTableNode(head, (tLinkTableNode *)pNode);
	}
	return NULL;
}

/* show all cmd in link list */
int ShowAllCmd(tLinkTable *head)
{
	tDataNode *pNode = (tDataNode *)GetLinkTableHead(head);

	while (pNode != NULL)
	{
		printf("%s - %s\n", pNode->cmd, pNode->desc);
		pNode = (tDataNode *)GetNextLinkTableNode(head, (tLinkTableNode *)pNode);
	}
	return 0;
}

int InitMenuData(tLinkTable **ppLinkTable)
{
	*ppLinkTable =  CreateLinkTable();
	 tDataNode *pNode = (tDataNode *)malloc(sizeof(tDataNode));
	 pNode->cmd = "help";
	 pNode->desc = "Menu List";
	 pNode->handler = Help;
	 AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);
	 pNode = (tDataNode *)malloc(sizeof(tDataNode));
	 pNode->cmd = "version";
	 pNode->desc = "Menu Program 1.0";
	 pNode->handler = NULL;
	 AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);
	 pNode = (tDataNode *)malloc(sizeof(tDataNode));
	 pNode->cmd = "quit";
	 pNode->desc = "Quit from Menu Program V1.0";
	 pNode->handler = Quit;
	 AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);
	 pNode = (tDataNode *)malloc(sizeof(tDataNode));
	 pNode->cmd = "ls";
	 pNode->desc = "list all file in current directory";
	 pNode->handler = Ls;
	 AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

	 return 0;
}

tLinkTable *head = NULL;

int main(int argc, char *argv[])
{
	printf( "******************************DESCRIPTION************************\n"
            "*\t\t\t\t\t\t\t\t*\n"
            "*\tThis menu program is coded by YB. Version 1.0\t\t*\n"
            "*\t\t\t\t\t\t\t\t*\n"
            "*\thelp\t\tShow this help list\t\t\t*\n"
            "*\tls\t\tList files\t\t\t\t*\n"
            "*\tquit\t\tQuit menu program\t\t\t*\n"
            "*\tversion\t\tshow release version\t\t\t*\n"
            "*\t\t\t\t\t\t\t\t*\n"
                "*****************************************************************\n\n");
                
	InitMenuData(&head);

	while (1)
	{
		char cmd[CMD_MAX_LEN];
		printf(">>>");
		scanf("%s", cmd);
		tDataNode *p = FindCmd(head, cmd);
		if (p == NULL)
		{
			printf("This is a wrong cmd!\n");
			continue;
		}
		printf("%s - %s\n", p->cmd, p->desc);
		if (p->handler != NULL)
		{
			p->handler();
		}
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

int Ls()
{
	system("ls");
}














