#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"

/*
 * Create a LinkTable
 */ 
tLinkTable *CreateLinkTable()
{
	tLinkTable *pLinkTable = (tLinkTable *)malloc(sizeof(tLinkTable));
	pLinkTable->pHead = NULL;
	pLinkTable->pTail = NULL;
	pLinkTable->sumOfNode = 0;

	return pLinkTable;
}


/*
 * AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pLinkTableNode)
 */
int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pLinkTableNode)
{
	if (pLinkTable->sumOfNode == 0)
	{
		pLinkTable->pHead = pLinkTableNode;
		pLinkTable->pTail = pLinkTableNode;
		pLinkTable->sumOfNode = 1;
	}
	else
	{
		pLinkTable->pTail->pNext = pLinkTableNode;
		pLinkTable->pTail = pLinkTableNode;
		pLinkTable->sumOfNode++;
	}

	return 0;
}

/*
 * GetLinkTableHead(tLinkTable *pLinkTable)
 */
tLinkTableNode *GetLinkTableHead(tLinkTable *pLinkTable)
{
	return pLinkTable->pHead;
}

/*
 * GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pLinkTableNode)
 */
tLinkTableNode *GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pLinkTableNode)
{
	return pLinkTableNode->pNext;
}















