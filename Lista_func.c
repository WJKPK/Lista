#include <stdio.h>
#include <stdlib.h>
#include "Lista_funcc.h"

list* init() //Funkcja inicjalizacji listy
{
	list* HEAD = malloc(sizeof(HEAD));
	HEAD->head = NULL;
	return HEAD;
}

int insert(list* header, int i) //Funkcja dodajaca jeden NODE zawierajacego liczbe naturalna oraz adres nastepnej komorki pamieci
{
	if (header->head == NULL)
	{
		header->head = malloc(sizeof(node));
		header->head->dane = i;
		header->head->next = NULL;
		return 0;
	}

	node* currPtr = header->head;

	while(currPtr->next!=NULL)
	{
		currPtr = currPtr->next;
	}

	currPtr->next=malloc(sizeof(node));
	currPtr->next->dane = i;
	currPtr = currPtr->next;
	currPtr->next = NULL;
	return 0;
}

int pop_first (list* header) //Funkcja usuwajaca pierwszy NODE w dostepnej liscie. Jezeli nie ma NODE'ow informuje ze nie ma nic do usuniecia.
{
	if (header->head == NULL)
	{
		printf("Lista jest pusta");
		return 0;
	}

	node* currPtr = header->head;
	header->head = header->head->next;
	free(currPtr);
	return 0;
}

int pop_last (list* header) //Funkcja usuwajaca ostatni NODE w dostepnej liscie. Jezeli nie ma NODE'ow informuje ze nie ma nic do usuniecia.
{
	if (header->head == NULL)
	{
		printf("Lista jest pusta");
		return 0;
	}

	if (header->head->next == NULL)
	{
		free(header->head);
		header->head=NULL;
		return 0;
	}

		node* currPtr = header->head;
		node* nextPtr= header->head->next;

		while(nextPtr->next!=NULL)
	{
	nextPtr = nextPtr->next;
	currPtr = currPtr->next;
	}

		free(nextPtr);
		currPtr->next = NULL;
		return 0;
}

int clear (list* header) //Funkcja usuwajaca cala liste
{
	node*currPtr=(node*)header->head;
	while(currPtr!= NULL)
	{
		node* nextPtr = (node*)currPtr->next;
		free(currPtr);
		currPtr=nextPtr;
	}
	header->head=NULL;
	return 0;
}

int print (const list* header) //Funkcja printujaca cala liste
{
	if (header->head == NULL)
		{
			printf("Nie ma nic do druku");
			return 1;
		}

	node* currPtr=(node*)header->head;

	while(currPtr!= NULL) //jeżeli adres Node'a nie jest równy zero
	{
		node* nextPtr = (node*)currPtr->next;
		printf("Wartość w tym Node: %d\n",currPtr->dane);
		printf("Adres następnego Node: %p\n",currPtr->next);
		currPtr=nextPtr;
	}
	return 0;
}
