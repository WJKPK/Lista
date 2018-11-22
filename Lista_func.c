#include <stdio.h>
#include <stdlib.h>
#include "Lista_funcc.h"

listS* init(void)
{
	listS* start = (listS*)malloc(sizeof(start));
	if (start == NULL)
		{
			return NULL;
		}
	start->head = NULL;
	return start;
}

int insert(listS* header, const int i)
{
	if (header == NULL)
	{
		return -1;
	}
	
	if (header->head == NULL)
	{
		header->head = (nodeS*)malloc(sizeof(nodeS));
		if (header->head == NULL)
		{
			return -1;
		}
		header->head->dane = i;
		header->head->next = NULL;
		return 0;
	}

	nodeS* currPtr = header->head;

	while (currPtr->next!=NULL)
	{
		currPtr = currPtr->next;
	}

	currPtr->next=(nodeS*)malloc(sizeof(nodeS));
	if (currPtr->next == NULL)
			{
				return -1;
			}
	currPtr->next->dane = i;
	currPtr = currPtr->next;
	currPtr->next = NULL;
	return 0;
}

int pop_first(listS* restrict header, int* restrict c)
{
	if (header == NULL)
	{
		return -1;
	}
	if (header->head == NULL)
	{
		return -1;
	}

	if(c!=NULL)
	{
		*c = header->head->dane;
	}
	nodeS* currPtr = header->head;
	header->head = header->head->next;
	free(currPtr);
	return 0;
}

int pop_last(listS* restrict header,int* restrict c)
{
	if (header == NULL)
	{
		return -1;
	}

	if (header->head == NULL)
	{
		return -1;
	}

	if (header->head->next == NULL)
	{
		if(c!=NULL)
		{
			*c = header->head->dane;
		}

		free(header->head);
		header->head=NULL;
		return 0;
	}

	nodeS* currPtr = header->head;
	nodeS* nextPtr= currPtr->next;

	while (nextPtr->next!=NULL)
	{
		nextPtr = nextPtr->next;
		currPtr = currPtr->next;
	}

	if (c!=NULL)
	{
		*c = nextPtr->dane;
	}
	free(nextPtr);
	currPtr->next = NULL;
	return 0;
}

int clear(listS* restrict header)
{
	if (header == NULL)
	{
		return -1;
	}
	nodeS*currPtr=header->head;
	while (currPtr!= NULL)
	{
		nodeS* nextPtr = currPtr->next;
		free(currPtr);
		currPtr=nextPtr;
	}
	free(header);
	header->head=NULL;
	return 0;
}



