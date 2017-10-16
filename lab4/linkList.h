#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_

#define SUCCESS 0
#define FAILURE (-1)


/*
 * LinkTable Node Type
 */
typedef struct LinkTableNode
{
    struct LinkTableNode *pNext;
} tLinkTableNode;

/*
 * LinkTable Node Type
 */
typedef struct LinkTable
{
    tLinkTableNode *pHead;
    tLinkTableNode *pTail;
    int sumOfNode;
} tLinkTable;

/*
 * Create a LinkTable
 */ 
tLinkTable *CreateLinkTable();

/*
 * Delete a LinkTable(tLinkTable *pLinkTable)
 */
int DeleteLinkTable(tLinkTable *pLinkTable);

/*
 * AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pLinkTableNode)
 */
int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pLinkTableNode);

/*
 * DeleteLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pLinkTableNode)
 */
int DeleteLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pLinkTableNode);

/*
 * GetLinkTableHead(tLinkTable *pLinkTable)
 */
tLinkTableNode *GetLinkTableHead(tLinkTable *pLinkTable);

/*
 * GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pLinkTableNode)
 */
tLinkTableNode *GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pLinkTableNode);


#endif /* _LINK_TABLE_H_ */
