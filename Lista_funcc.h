#ifndef LISTA_FUNCC_H_
#define LISTA_FUNCC_H_

typedef struct node
{
	int dane;
	struct node* next; //wskaźnik do struktury
} node;

typedef struct list
{
	node* head;
} list;

//Deklaracje funkcji
	int pop_last (list* header);
	int insert(list* header, int i);
	int pop_first(list* header);
	int clear (list* header);
	int print(const list* header);
	list* init();

#endif /* LISTA_FUNCC_H_ */
