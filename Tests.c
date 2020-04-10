#include <stdio.h>
#include <stdlib.h>
#include "Lista_funcc.h"
#include <criterion/criterion.h>

Test(init_tests, InitTest)
{
	listS* starter = init();
	cr_assert_not_null(starter,"Funkcja init nie jest w stanie zaalokować pamięci aby utworzyć HEAD");
	cr_expect_null(starter->head, "Funkcja init() nie tworzy nodea wskazującego na null");
	clear(starter);
}

Test(clear_tests, ClearTest)
{
	listS* starter = init();
	int test_c = clear(starter);
	cr_expect(test_c == 0 ,"Funkcja clear nie działa prawidłowo");
}

Test(push_last_tests, insertTest)
{
	listS* starter = init();
	const int ins_val = 4;
	int test_i = push_last(starter,ins_val);
	cr_expect(test_i == 0 ,"Funkcja push_last nie działa prawidłowo");
	cr_expect(starter->head->dane == ins_val ,"Funkcja push_last nie przypisuje odpowiedniej wartości dla pierwszego nodea");
	push_last(starter, 3*ins_val);
	cr_expect(starter->head->next->dane == (3 * ins_val) ,"Funkcja push_last nie przypisuje odpowiedniej wartości dla drugiego nodea nodea");
	clear(starter);
}

Test(push_first_tests, insertTest)
{
	const int maxLoopIteration = 8;
	listS* starter = init();
	int test_i;
	for (int i = 0; i < maxLoopIteration; i++)
	{
		test_i = push_first(starter, i);
		cr_expect(test_i == 0 ,"Funkcja push_first nie działa prawidłowo");
		cr_expect(starter->head->dane == i ,"Funkcja push_first nie przypisuje odpowiedniej wartości dla pierwszego nodea");
	}
	clear(starter);
}

Test(pop_tests, PopFirstNode)
{
	listS* starter = init();
	int x = 0;
	int rand_val = 3;
	push_last(starter,rand_val);
	pop_first(starter, &x);

	cr_assert_null(starter->head, "Starter wskazuje na NULL po użyciu pop() na jednoelementowej liście");
	cr_expect(x == rand_val, "Wartość zwracana przez pop_last() dla listy jednoelementowej nie jest zgodna z oczekiwaną");
	clear(starter);
}

Test(pop_tests, PopMultipleNode)
{
	const int maxLoopIteration = 8;
	listS* starter = init();
	const int rand_val = 3;
	int x = 0;
	for(int i = 0; i < maxLoopIteration; i++)
	{
		push_last(starter,i*rand_val);
		pop_first(starter, &x);
		cr_expect(x==i*rand_val,"Wartość zwracana przez pop_last() dla listy jednoelementowej nie jest zgodna z oczekiwaną");
	}

	cr_assert_null(starter->head,"Starter nie wskazuje na NULL po równej liczbie push_last oraz pop_first()");
	clear(starter);
}

Test(pop_tests, PopLastFirst)
{
	const int my_val = 3;
	int x = 0;
	listS* starter = init();
	push_last(starter, my_val);
	push_last(starter, 2*my_val);

	pop_last(starter, &x);
	cr_expect(x == 2*my_val,"Wartość zwracana przez pop_last() nie jest zgodna z oczekiwaną");

	pop_first(starter, &x);
	cr_expect(x == my_val,"Wartość zwracana przez pop_first() nie jest zgodna z oczekiwaną");
	cr_assert_null(starter->head,"Starter nie wskazuje na NULL po równej liczbie pop_last oraz pop_first()");
	clear(starter);
}
