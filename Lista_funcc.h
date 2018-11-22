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
	int pop_last(listS* restrict header, int* restrict a);
	int insert(listS* restrict header, int i);
	int pop_first(listS* restrict header, int* restrict a);
	int clear(listS* restrict header);
	listS* init(void);

#endif /* LISTA_FUNCC_H_ */
