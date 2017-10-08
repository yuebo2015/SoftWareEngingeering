/*****************************************************************************/
/* Copyright (C) yuebowhu@163.com, YB, 2017-2018                             */
/*                                                                           */
/*                                                                           */
/* FILE NAME                :   linkList.h                                   */
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

/* data structure and its operations */


typedef struct DataNode
{
    char *cmd;
    char *desc;
    int (*handler)();
    struct DataNode *next;
} tDataNode;

/* find a cmd in the link list and return the datanode pointer */
tDataNode *FindCmd(tDataNode *head, char *cmd);
/* show all cmd in link list */
int ShowAllCmd(tDataNode *head);
/* help to how to use cmd */
int Help();
/* quit current menu */
int Quit();
/* list flies in current directory */
int List();
/* show version */
int Version();
/* handle exception */
int HandleException();

static tDataNode head[] =
{
    {"help", "this is help cmd!", Help, &head[1]},
    {"ls", "list files in current direction", List, &head[2]},
    {"quit", "exit from current menu", Quit, &head[3]},
    {"version", "menu program v1.0", Version, NULL}
};

