/*****************************************************************************/
/* Copyright (C) yuebowhu@163.com, YB, 2014-2015		
/* 
/*
/* FILE NAME				:	menu.c
/* PRINCIPAL AUTHOR			:	YUEBO
/* LANGUAGE					:	C
/* DATE OF FIRST RELEASE	:	2014/08/31
/* DESCRIPTION				: 	This is a menu program
/*****************************************************************************/

/*
 * Revision log:
 *
 * Created by YB, 2014/08/31
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define CMD_MAX_LEN 128
#define DESC_LEN	1024
#define CMD_NUM		10


int Help();
int Quit();
int List();

typedef struct DataNode
{
	char *cmd;
	char *desc;
	int (*handler)();
	struct DataNode *next;
} tDataNode;

static tDataNode head[] =
{
	{"help", "this is help cmd!", Help, &head[1]},
	{"quit", "quit", Quit, &head[2]},
	{"ls", "list files in current direction", List, &head[3]},
	{"version", "menu program v1.0", NULL, NULL}
};


;--------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	/* cmd line begines */
	while (1)
	{
		char cmd[CMD_MAX_LEN];
		printf("Input a cmd number > ");
		scanf("%s", cmd);
		tDataNode *p = head;
		while (p != NULL)
		{
			if (strcmp(p->cmd, cmd) == 0)
			{
				printf("%s - %s\n", p->cmd, p->desc);
				if (p->handler != NULL)
				{
					p->handler();
				}
				break;
			}
			p = p->next;
		}
	}

	return 0;
}

;-------------------------------------------------------------------------------
int Help()
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

int Quit()
{
	exit(0);
}

int List()
{
	system("ls");
	return 0;
}



























