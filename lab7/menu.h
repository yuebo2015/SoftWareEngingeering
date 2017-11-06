/*************************************************************************
	> File Name: menu.h
	> Author: YB
	> Mail: xxxx@whu.edu.com
	> Created Time: Mon 06 Nov 2017 09:55:38 PM CST
 ************************************************************************/
#include "linktable.h"

#ifndef _MENU_H
#define _MENU_H

/* data struct and its operations */
typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)(int argc, char *argv[]);
} tDataNode;

int SearchCondition(tLinkTableNode * pLinkTableNode, void *args);

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tLinkTable * head, char * cmd);

/* show all cmd in listlist */
int ShowAllCmd(tLinkTable * head);

int Help();

/* add cmd to menu  */
int MenuConfig(char *cmd, char *desc, int (*handler)(int argc, char *argv[]));                               
  
/* Menu Engine Execute */
int ExecuteMenu();

#endif
