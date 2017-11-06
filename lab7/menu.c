
/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Mengning                                                             */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/08/31                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Mengning, 2014/08/31
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"
#include "menu.h"
#include <string.h>

#define CMD_MAX_LEN         128
#define DESC_LEN            1024
#define CMD_NUM             10
#define TRUE		        1
#define FALSE		        0
#define CMD_MAX_ARGV_NUM    100

tLinkTable *head = NULL;

int SearchCondition(tLinkTableNode * pLinkTableNode, void *args)
{
	char *cmd = (char *)args;
    tDataNode * pNode = (tDataNode *)pLinkTableNode;
    if(strcmp(pNode->cmd, cmd) == 0)
    {
        return  SUCCESS;  
    }
    return FAILURE;	       
}

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tLinkTable * head, char * cmd)
{
    return  (tDataNode*)SearchLinkTableNode(head, SearchCondition, cmd);
}

/* show all cmd in listlist */
int ShowAllCmd(tLinkTable * head)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}

int Help(int argc, char *argv[0])
{
    ShowAllCmd(head);
    return 0; 
}

int ExecuteMenu()
{
     while(TRUE)
    {
        int argc = 0;
        char *argv[CMD_MAX_ARGV_NUM];
    	char cmd[CMD_MAX_LEN];
        char *pcmd = NULL;
        printf("Input a cmd number > ");
        /* scanf("%s", cmd); */
        pcmd = fgets(cmd, CMD_MAX_LEN, stdin);
        if (pcmd == NULL)
        {
            continue;
        }
        /* conver cmd to argc/argv */
        pcmd = strtok(pcmd, " ");
        while (pcmd != NULL && argc < CMD_MAX_ARGV_NUM)
        {
            argv[argc] = pcmd;
            argc++;
            pcmd = strtok(NULL, " ");
        }
        if (argc == 1)
        {
            int len = strlen(argv[0]);
            *(argv[0] + len -1) = '\0';
        }
        
        tDataNode *p = FindCmd(head, (char *)argv[0]);
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n ");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc); 
        if(p->handler != NULL) 
        { 
            p->handler(argc, argv);
        }
    }   
}

/* add cmd to menu */
int MenuConfig(char *cmd, char *desc, int (*handler)())
{
    tDataNode *pNode = NULL;
    if (head == NULL)
    {
        head = CreateLinkTable();
        pNode = (tDataNode *)malloc(sizeof(tDataNode));
        pNode->cmd = "help";
        pNode->desc = "Menu List";
        pNode->handler = Help;
        AddLinkTableNode(head, (tLinkTableNode *)pNode);
    }
    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = cmd;
    pNode->desc = desc;
    pNode->handler = handler;
    AddLinkTableNode(head, (tLinkTableNode *)pNode);

    return 0;
}
