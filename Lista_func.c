#include <stdio.h>
#include <stdlib.h>
#include "Lista_funcc.h"

listS* init() //Funkcja inicjalizacji listSy
{
	listS* start = (listS*)malloc(sizeof(start));
	start->head = NULL;
	return start;
}

int insert(listS* header, int i) //Funkcja dodajaca jeden NODE zawierajacego liczbe naturalna oraz adres nastepnej komorki pamieci
{
	if (header == NULL)
	{
		return -1;
	}
	
	if (header->head == NULL)
	{
		header->head = (nodeS*)malloc(sizeof(nodeS));
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
	currPtr->next->dane = i;
	currPtr = currPtr->next;
	currPtr->next = NULL;
	return 0;
}

int pop_first(listS* header, int* c) //Funkcja usuwajaca pierwszy NODE w dostepnej liscie.
{
	if (header->head == NULL)
	{
		return -1;
	}

	if (c!=NULL)
	{
		*c = header->head->dane;
	}
	nodeS* currPtr = header->head;
	header->head = header->head->next;
	free(currPtr);
	return 0;
}

int pop_last(listS* header,int* c) //Funkcja usuwajaca ostatni NODE w dostepnej liscie. Jezeli nie ma NODE'ow informuje ze nie ma nic do usuniecia.
{
	if (header->head == NULL)
	{
		return -1;
	}

	if (header->head->next == NULL)
	{
		if (c!=NULL)
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

int clear(listS* header) //Funkcja usuwajaca cala liste
{
	if (header == NULL)
	{
		return -1;
	}
	nodeS*currPtr=(nodeS*)header->head;
	while (currPtr!= NULL)
	{
		nodeS* nextPtr = (nodeS*)currPtr->next;
		free(currPtr);
		currPtr=nextPtr;
	}
	header->head=NULL;
	free(header);
	return 0;
}

int print(const listS* header) //Funkcja printujaca cala liste
{
	if (header->head == NULL)
		{
			printf("Nie ma nic do druku");
			return -1;
		}

	nodeS* currPtr=(nodeS*)header->head;

	while (currPtr!= NULL) //jeżeli adres Node'a nie jest równy zero
	{
		nodeS* nextPtr = (nodeS*)currPtr->next;
		printf("Wartość w tym Node: %d\n",currPtr->dane);
		printf("Adres następnego Node: %p\n",currPtr->next);
		currPtr=nextPtr;
	}
	return 0;
}
