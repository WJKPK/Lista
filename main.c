
#include <stdio.h>
#include <stdlib.h>
#include "Lista_funcc.h"
#include <criterion/criterion.h>


int main(void)
{
	listS* starter = init();
	insert(starter, 5);
	insert(starter, 3);
	insert(starter, 3);
	insert(starter, 10);
	pop_first(starter);
	insert(starter, 10);
	pop_last(starter);
	print(starter);
	clear(starter);
	free(starter);
	return 0;
}


Test(clear_tests, ClearWithLotInserts)
{
	listS* starter = init();

   insert(starter,3);
   insert(starter,3);
   insert(starter,3);
   insert(starter,3);
   clear(starter);

   cr_assert_null(starter->head,"Lista po uzyciu funkcji clear nie jest zakonczona NULLem");

   free(starter);
}

Test(print_tests, PrintAfterInit)
{
	listS* starter = init();
	int i = print(starter);

	cr_expect(i,"Blad funkcji print dla braku NODE'ow");

	free(starter);
}

Test(clear_tests, OnlyInitAndClear)
{
	listS* starter = init();
	clear(starter);

	cr_assert_null(starter->head,"Zainicjalizowana listSa po użyciu clear() nie jest zakończona NULLem");

	free(starter);
}

Test(pop_tests, PopFirstNode)
{
	listS* starter = init();
	int rand_val = 3;
	insert(starter,rand_val);
	pop_first(starter);

	cr_assert_null(starter->head,"starter wskazuje na NULL po użyciu pop() na jednoelementowej liście");

	free(starter);
}

Test(pop_tests, PopMultipleNode)
{
	listS* starter = init();
	int rand_val = 3;
	for(int i=0; i<6; i++)
	{
		insert(starter,i*rand_val);
	}
	pop_first(starter);
	pop_first(starter);

	cr_assert_not_null(starter->head,"starter wskazuje na NULL po użyciu pop() na wieloelementowej liście (a nie powinien)");

	clear(starter);
	free(starter);
}

Test(pop_tests, PopLastPointtoNull)
{
	listS* starter = init();
	insert(starter, 4);
	nodeS* adr_2 = starter->head->next; //adres wskazywany przez pierwszy nodeS
	insert(starter, 5);
	nodeS* adr_3 = starter->head->next->next; //adres wskazywany przez drugi nodeS
	pop_last(starter);

	cr_assert_null(adr_2, "Po wykonaniu push_last() listSa nie kończy się NULLem");
	cr_expect(adr_2==adr_3,"Po wykonaniu push_last() nie zostaje nadpisany adres w przedostatnim nodeS");

	clear(starter);
	free(starter);
}
