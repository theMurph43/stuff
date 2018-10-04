#include <stdio.h>
#include <stdlib.h>

typedef struct ListItem{
	struct ListItem* prev;
	struct ListItem* next;
	int info;
}ListItem;

typedef struct ListItemObj{
	struct ListItem* prev;
	struct ListItem* next;
	int info;
}ListItem;

typedef struct ListHead {
	struct ListItem* first;
	struct ListItem* last;
	int size;
}ListHead;

//funcion prototypes ###################################################
ListHead* List_init();
ListItem* List_insert(ListHead* head, ListItem* prev, ListItem* item);
int Find_item(ListItem* item, ListHead* head);


//function implementation ##############################################

ListHead* List_Init(ListHead* head){
	head->size = 0 ;
	head->first = 0;
	head->last = 0;
	return head;
}

//return item position in list, 0 if not in list
int Find_item(ListItem* item, ListHead* head){
	int counter = 1;
	struct ListItem* current = head->first;
	
	if (item->info == current->info){
		printf(">> easy, it's the first element\n");
		return 1;
	}
	
	while (current->next){
		current = current->next;
		counter ++;

		if (item->info == current->info){
			printf(">> element in %dth position\n", counter);
			return counter;
		}
	}
	printf (">> sorry, is not in list!\n");
	return 0;
}


ListItem* List_insert(ListHead* head, ListItem* prev, ListItem* item){
	
	//check if prev is in list
	
	//check if the element is already in list
	
	//insert element
	ListItem* aux = head->first;
	printf ("\nPushing element in list... ");
	while(1){
		if (aux == prev){
			ListItem* next = prev->next;
			prev->next = item;
			item->prev = prev;
			next->prev = item;
			item->next = next;
			head->size++;
			printf ("Done.\n");
			return item;
		}
		aux = aux->next;
	}
	return 0;
}

//::::::::::: M A I N ::::::::::::::::::::::::::::::::::::::::::::::::::

int main (){
	
	struct ListItem* i1 = (ListItem*)malloc(sizeof(ListItem));
	struct ListItem* i2 = (ListItem*)malloc(sizeof(ListItem));
	struct ListItem* i3 = (ListItem*)malloc(sizeof(ListItem));
	struct ListItem* i4 = (ListItem*)malloc(sizeof(ListItem));
	struct ListItem* k = (ListItem*)malloc(sizeof(ListItem));
	
	struct ListHead* head = (ListHead*)malloc(sizeof(ListHead));
	List_Init(head);
	head->first = i1;
	head->last = i4;
	head->size = 4;
	
	i1->prev = 0;
	i1 ->next = i2;
	i1->info = 101;
	
	i2->prev = i1;
	i2 ->next = i3;
	i2->info = 102;
	
	i3->prev = i2;
	i3 ->next = i4;
	i3->info = 103;
	
	i4->prev = i3;
	i4 ->next = 0;
	i4->info = 104;
	
	k->prev = 0;
	k ->next = 0;
	k->info = 500;
	
	//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	
	printf("searching for i4 in list ... \n");
	int ret = Find_item ( i4 , head );
	
	List_insert( head , i2 , k );
	printf("\nsearching for k in list ... \n");
	ret = Find_item ( k , head );
	
	printf("\nsearching for i4 in list ... \n");
	ret = Find_item ( i4 , head );
}














