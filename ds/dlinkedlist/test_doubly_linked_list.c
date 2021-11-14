#include <stdio.h>
#include "doubly_linked_list.h"
#include <string.h>

void testDoubly();
void testDoubly2();

typedef struct 
{
    size_t idNum;
} person_t;


static int IsMatch(void* data, void* param)
{
    person_t* p = (person_t*)data;

    if (p->idNum == *(size_t*)param)
    {
        return 1;
    }

    return 0;
}


static int print(void* data, void* param)
{

	(void)param;
	printf("%lu\n", *(size_t*)data);
	return 1;
}

static int Minus(void* data, void* param)
{

	*(size_t*)data = *(size_t*)data - *(size_t*)param;
	return 1;
}

int main() {

    dlist_t *list = DListCreate();
    
	dlist_iter_t iter = DListBegin(list);
	dlist_iter_t iter2 = DListBegin(list);
	dlist_iter_t iter3 = DListBegin(list);
	int a = 5;
	char b [15] = "Dumbeldore";
	int c = 100;
	
	size_t test1;
	person_t p1, p2, p3;
    	dlist_iter_t iter4, iter5;
	dlist_t* list2;
	
	if(!(DListIterIsEqual(iter, iter2) == 1))
	{
		printf("fail in %d\n", __LINE__);
	}
		
	
	
    	if(!(DListCount(list) == 0))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	DListInsert(iter, &a);
	
	if(!(DListCount(list) == 1))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	if(!(*(int*)DListIterGetData(iter) == 5))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	iter = DListIterNext(iter);
	DListInsert(iter, b); /*a, b */
	
	if(!(DListCount(list) == 2))
	{
		printf("fail in %d\n", __LINE__);
	}
	

	if(!(strcmp((char*)DListIterGetData(iter),"Dumbeldore" ) == 0))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	DListInsert(iter, &c);/*a, c, b*/
	
	if(!(DListCount(list) == 3))
	{
		printf("fail in %d\n", __LINE__);
	}
	

	if(!(*(int*)DListIterGetData(iter) == 100))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	iter = DListIterNext(iter);
	
	if(!(strcmp((char*)DListIterGetData(iter),"Dumbeldore" ) == 0))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	iter2 = DListIterNext(iter2);
	DListRemove(iter2);/*a, b*/
	
	if(!(DListCount(list) == 2))
	{
		printf("fail in %d\n", __LINE__);
	}

	if(!(strcmp((char*)DListIterGetData(iter2),"Dumbeldore" ) == 0))
	{
		printf("fail in %d\n", __LINE__);
	}
	DListRemove(iter3);/*b*/
	
	if(!(strcmp((char*)DListIterGetData(iter3),"Dumbeldore" ) == 0))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	if(!(DListCount(list) == 1))
	{
		printf("fail in %d\n", __LINE__);
	}


	DListDestroy(list);
	
	
	/****************************************************/
	
	p1.idNum = 111;
	p2.idNum = 445;
	p3.idNum = 123;
	
	list2 = DListCreate();
	
	DListInsert(DListEnd(list2), &p1);
    	DListInsert(DListEnd(list2), &p2);
    	DListInsert(DListEnd(list2), &p3);
    	
    	if(!(DListCount(list2) == 3))
	{
		printf("fail in %d\n", __LINE__);
	}
    	
	iter4 = DListBegin(list2);
	iter5 = DListIterNext(iter4);
	iter5 = DListIterNext(iter5);
	

	
	test1 = 445;
	
	iter4 = DListFind(DListBegin(list2), iter5, IsMatch, &test1);
	

	
	if(!(((person_t*)DListIterGetData(iter4))->idNum == 445))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	test1 = 123;
	iter4 = DListFind(DListBegin(list2), DListEnd(list2), IsMatch, &test1);
	
	if(!(((person_t*)DListIterGetData(iter4))->idNum == 123))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	DListForEach(DListBegin(list2), DListEnd(list2), print, NULL);
	
	puts(" ");
	test1 = 20;
	DListForEach(DListBegin(list2), DListEnd(list2), Minus, &test1);
	
	DListForEach(DListBegin(list2), DListEnd(list2), print, NULL);
	
	if(!(DListCountForEach(list2) == 3))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	DListDestroy(list2);
	
	testDoubly();
	testDoubly2();
   return 0;
}

void testDoubly()
{
	 dlist_t *list = DListCreate();
    
	dlist_iter_t iter = DListBegin(list);
	int a = 5;
	char b [15] = "Dumbeldore";
	int c = 100;
	DListInsert(iter, &c);
	DListInsert(iter, b);
	DListInsert(iter, &a);/*a,b,c*/
	iter = DListIterNext(iter);
	iter = DListIterNext(iter);
	
	if(!(*(int*)DListIterGetData(iter) == 100))
	{
		printf("fail in %d\n", __LINE__);
	}

	iter = DListIterPrev(iter);

	if(!(strcmp((char*)DListIterGetData(iter),"Dumbeldore" ) == 0))
	{
		printf("fail in %d\n", __LINE__);
	}

	iter = DListIterPrev(iter);

	if(!(*(int*)DListIterGetData(iter) == 5))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	iter = DListIterNext(iter);
	DListRemove(iter);
	
	if(!(*(int*)DListIterGetData(iter) == 100))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	DListDestroy(list);
	
}

void testDoubly2()
{
	dlist_t *list = DListCreate();
	dlist_t *list2 = DListCreate();
		
	dlist_iter_t iter = DListBegin(list);
	dlist_iter_t iter2 = DListBegin(list2);
	dlist_iter_t iter3 = DListBegin(list2);
	int a = 5;
	char b [15] = "Dumbeldore";
	int c = 100;
	
	int x = 300;
	char y [20] = "Harry Potter";
	int z = 450;
	
	DListPushFront(list, &c);
	DListPushFront(list, b);
	DListPushBack(list, &a);/*b,c,a*/
	
	
	if(!(*(int*)DListPopBack(list) == 5))
	{
		printf("fail in %d\n", __LINE__);
	}


	if(!(strcmp((char*)DListPopFront(list),"Dumbeldore" ) == 0))
	{
		printf("fail in %d\n", __LINE__);
	}

	/*c is left*/
	
	if(!(DListCount(list) == 1))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	if(!(*(int*)DListIterGetData(DListBegin(list)) == 100))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	DListPushFront(list, b);
	DListPushBack(list, &a);/*b,c,a*/
	
	DListPushFront(list2, &x);
	DListPushFront(list2, y);
	DListPushBack(list2, &z);/*y,x,z*/
	
	iter = DListIterNext(iter);
	iter2 = DListIterNext(iter2);
	iter3 = DListIterNext(iter);
	iter = DListSplice(iter2, iter, iter3); 
	iter = DListIterNext(iter);
	
	if(!(*(int*)DListIterGetData(iter) == 300))
	{
		printf("fail in %d\n", __LINE__);
	}

	iter2 = DListBegin(list2);
	
	if(!(strcmp((char*)DListIterGetData(iter2),"Harry Potter" ) == 0))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	iter2 = DListIterNext(iter2);

	if(!(*(int*)DListIterGetData(iter2) == 100))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	iter2 = DListIterNext(iter2);
	
	if(!(*(int*)DListIterGetData(iter2) == 5))
	{
		printf("fail in %d\n", __LINE__);
	}
	iter2 = DListIterNext(iter2);
	if(!(*(int*)DListIterGetData(iter2) == 300))
	{
		printf("fail in %d\n", __LINE__);
	}
	
	DListDestroy(list);
	DListDestroy(list2);
}



