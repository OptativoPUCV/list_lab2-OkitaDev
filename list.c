#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

//1
List * createList() 
{
  List * lista = malloc (sizeof(List));
	lista->head = NULL;
	lista->tail = NULL;
	lista->current = NULL;
	return lista;
}

//2
void * firstList(List * list) 
{
	list->current = list->head;
  return (void *) list->current->data;
}


void * nextList(List * list) 
{
	if(list->current == NULL || list->current->next == NULL) return NULL;
	list->current = list->current->next;
	return (void *) list->current->data;
}

//3
void * lastList(List * list) 
{
	list->current = list->tail;
  return (void *) list->current->data;
}

void * prevList(List * list) 
{
  if(list->current == NULL || list->current->prev == NULL) return NULL;
	list->current = list->current->prev;
	return (void *) list->current->data;
}

//4
void pushFront(List * list, const void * data) 
{
	Node * nodo = createNode(data);
	
	nodo->next = list->head;
	
	if(list->tail == NULL) 
		list->tail = nodo;
	
	list->head = nodo;
	nodo->prev =NULL; //Al ser el primero, el anterior que el debe estar vacio

}

//5
void pushBack(List * list, const void * data) 
{
  list->current = list->tail;
  pushCurrent(list,data);

}


void pushCurrent(List * list, const void * data) 
{
	Node * nodo = createNode(data);
	
	nodo->next = list->current->prev;
	
	if(list->current->next == NULL) 
		list->current->next = nodo;
	else
		list->current->prev = nodo;
	
	list->current->prev = nodo;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) 
{
	Node * temporal = list->current;

	while(temporal->next != list->current)
		temporal = temporal->next;

	return (void *) temporal->data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}