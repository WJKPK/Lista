/*Testy do zrobienia:
 * test: init>clear
 * 1xinsert>clear
 * multiple insert>clear
 Lista
 */

#include <stdio.h>
#include <stdlib.h>
#include "Lista_funcc.h"
#include <criterion/criterion.h>


int main(void)
{
	list* HEAD = init();
	insert(HEAD, 5);
	insert(HEAD, 3);
	insert(HEAD, 3);
	insert(HEAD, 10);
	pop_first(HEAD);
	insert(HEAD, 10);
	pop_last(HEAD);
	print(HEAD);
	clear(HEAD);
	free(HEAD);
	return 0;
}


Test(clear_tests, ClearWithLotInserts)
{
	list* HEAD = init();

   insert(HEAD,3);
   insert(HEAD,3);
   insert(HEAD,3);
   insert(HEAD,3);
   clear(HEAD);

   cr_assert_null(HEAD->head,"Lista po uzyciu funkcji clear nie jest zakonczona NULLem");

   free(HEAD);
}

Test(print_tests, PrintAfterInit)
{
	list* HEAD = init();
	int i = print(HEAD);

	cr_expect(i,"Blad funkcji print dla braku NODE'ow");

	free(HEAD);
}

Test(clear_tests, OnlyInitAndClear)
{
	list* HEAD = init();
	clear(HEAD);

	cr_assert_null(HEAD->head,"Zainicjalizowana lista po użyciu clear() nie jest zakończona NULLem");

	free(HEAD);
}

Test(pop_tests, PopFirstNode)
{
	list* HEAD = init();
	int rand_val = 3;
	insert(HEAD,rand_val);
	pop_first(HEAD);

	cr_assert_null(HEAD->head,"HEAD wskazuje na NULL po użyciu pop() na jednoelementowej liście");

	free(HEAD);
}

Test(pop_tests, PopMultipleNode)
{
	list* HEAD = init();
	int rand_val = 3;
	for(int i=0; i<6; i++)
	{
		insert(HEAD,i*rand_val);
	}
	pop_first(HEAD);
	pop_first(HEAD);

	cr_assert_not_null(HEAD->head,"HEAD wskazuje na NULL po użyciu pop() na wieloelementowej liście (a nie powinien)");

	clear(HEAD);
	free(HEAD);
}

Test(pop_tests, PopLastPointtoNull)
{
	list* HEAD = init();
	insert(HEAD, 4);
	node* adr_2 = HEAD->head->next; //adres wskazywany przez pierwszy node
	insert(HEAD, 5);
	node* adr_3 = HEAD->head->next->next; //adres wskazywany przez drugi node
	pop_last(HEAD);

	cr_assert_null(adr_2, "Po wykonaniu push_last() lista nie kończy się NULLem");
	cr_expect(adr_2==adr_3,"Po wykonaniu push_last() nie zostaje nadpisany adres w przedostatnim node");

	clear(HEAD);
	free(HEAD);
}
