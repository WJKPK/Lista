#ifndef LISTA_FUNCC_H_
#define LISTA_FUNCC_H_

typedef struct nodeS
{
	int dane;
	struct nodeS* next; //wskaźnik do struktury
} nodeS;

typedef struct listS
{
	nodeS* head;
} listS;

//Deklaracje funkcji
	int pop_last(listS* header, int* a);
	int insert(listS* header, int i);
	int pop_first(listS* header, int* a);
	int clear(listS* header);
	int print(const listS* header);
	listS* init(void);

#endif /* LISTA_FUNCC_H_ */
