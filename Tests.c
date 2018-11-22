#include <stdio.h>
#include <stdlib.h>
#include "Lista_funcc.h"
#include <criterion/criterion.h>

static int print(const listS* restrict header)
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

Test(clear_tests, ClearTest)
{
	listS* starter = init();
	int test_c = clear(starter);
	cr_expect(test_c == 0 ,"Funkcja clear nie działa prawidłowo");
}

Test(insert_tests, insertTest)
{
	listS* starter = init();
	const int ins_val = 4;
	int test_i = insert(starter,ins_val);
	cr_expect(test_i == 0 ,"Funkcja insert nie działa prawidłowo");
	cr_expect(starter->head->dane == ins_val ,"Funkcja insert nie przypisuje odpowiedniej wartości dla pierwszego nodea");
	insert(starter,3*ins_val);
	cr_expect(starter->head->next->dane == (3*ins_val) ,"Funkcja insert nie przypisuje odpowiedniej wartości dla drugiego nodea nodea");
	clear(starter);
}

Test(pop_tests, PopFirstNode)
{
	listS* starter = init();
	int x =0;
	int rand_val = 3;
	insert(starter,rand_val);
	pop_first(starter, &x);

	cr_assert_null(starter->head,"Starter wskazuje na NULL po użyciu pop() na jednoelementowej liście");
	cr_expect(x==rand_val,"Wartość zwracana przez pop_last() dla listy jednoelementowej nie jest zgodna z oczekiwaną");
	clear(starter);
}

Test(pop_tests, PopMultipleNode)
{
	listS* starter = init();
	const int rand_val = 3;
	int x =0;
	for(int i=0; i<6; i++)
	{
		insert(starter,i*rand_val);
		pop_first(starter, &x);
		cr_expect(x==i*rand_val,"Wartość zwracana przez pop_last() dla listy jednoelementowej nie jest zgodna z oczekiwaną");
	}

	cr_assert_null(starter->head,"Starter nie wskazuje na NULL po równej liczbie insertów oraz pop_first()");
	clear(starter);
}

Test(pop_tests, PopLastFirst)
{
	int my_val = 3;
	int x = 0;
	listS* starter = init();
	insert(starter, my_val);
	insert(starter, 2*my_val);

	pop_last(starter,&x);
	cr_expect(x==2*my_val,"Wartość zwracana przez pop_last() nie jest zgodna z oczekiwaną");

	pop_first(starter,&x);
	cr_expect(x==my_val,"Wartość zwracana przez pop_first() nie jest zgodna z oczekiwaną");

	clear(starter);
}
