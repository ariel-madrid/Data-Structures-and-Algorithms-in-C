//Autor: Ariel Argomedo - Computer Science Student at Universidad de Santiago de Chile

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
	int value;
	struct Nodo* next;
}Nodo;

typedef struct List
{
	Nodo* head;
}List;

//This function insert values at the end of the current linked list.
//If there is no value and the list is empty, the value will be placed at the beginning of the list.
void insertEnd(List* list,int value)
{
	if (list->head == NULL)
	{
		Nodo* tmp = (Nodo*)malloc(sizeof(Nodo));
		tmp->value = value;
		tmp->next = NULL;

		list->head = tmp;
	}else
	{
		Nodo* current = list->head;

		while(current->next != NULL)
		{
			current = current->next;
		}

		Nodo* tmp = (Nodo*)malloc(sizeof(Nodo));
		tmp->value = value;
		tmp->next = NULL;

		current->next = tmp; 
	}
}

//This is not the most efficient method to sort a list, but is the simple to understand.
void sortLinkedList(List* list,int param)
{
	if (param > 1 || param < 0)
	{
		printf("Non valid parameter\n");
		return;
	}
	Nodo* current = list->head;
	Nodo* next;

	while(current != NULL)
	{
		next = current->next;
		while(next != NULL)
		{
			if(param == 0)
			{
				if (current->value < next->value)
				{
					int tmp = current->value;
					current->value = next->value;
					next->value = tmp;
				}
			}else 
			{
				if (current->value > next->value)
				{
					int tmp = current->value;
					current->value = next->value;
					next->value = tmp;
				}
			}

			next = next->next;
		}
		current = current->next;
	}
}

//Params: Linked list whit values.
void showLinkedList(List* list)
{
	if (list->head == NULL)
	{
		printf("Here is nothing to see.\n");
		return;
	}

	//Current node set as the head of the linked list.
	Nodo* current = list->head;
	while(current != NULL)
	{
		printf("%d-",current->value);
		current = current->next;
	}
}

int main()
{
	//Asign space in memory to our new linked list.
	List* list = (List*)malloc(sizeof(List));

	//Set as NULL the head of the linked list when this is recently created.
	list->head = NULL;

	//Insert values to the linked list.
	insertEnd(list,1);
	insertEnd(list,2);
	insertEnd(list,3);
	insertEnd(list,4);
	insertEnd(list,5);

	//If the value of param is equal to 0, the linked list will be ordered in ascendant order.
	//When the value be equal to 1, the linked list will be ordered in descendant order.
	sortLinkedList(list,2);

	//Show the linked list.
	showLinkedList(list);
	return 0;
}