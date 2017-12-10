#include "stdafx.h"
//#include "TLINKONELIST.h"
#pragma once
#ifndef TLINKONELIST_CPP	
#define TLINKONELIST_CPP

template<typename Type>
TLinkOneList<Type>::TLinkOneList()
{
	/*if (Head != NULL)
		ZeroMemory(this, sizeof(TLinkOneList));//*/
}

template<typename Type>
TLinkOneList<Type>::~TLinkOneList()
{
}

template<typename Type>
Node<Type>* TLinkOneList<Type>::getElement(int index)
{
	if ((Count <= index)||(index < 0))//Error
		return NULL;

	_Node *current = NULL;

	if (index == End())
		current = Tail;
	else
	{
		current = Head;
		while (index > 0)
		{
			current = current->next;
			index--;
		}
	}

	return current;
}

template<typename Type>
Node<Type>* TLinkOneList<Type>::getElementBy(Type name, Node<Type>* &outprev)
{
	if (Count == NULL)//Error
		return NULL;

	_Node *current = NULL;

	current = Head;
	outprev = NULL;

	int index = Count;
	while (index > 0)
	{
		if (name == *current)
			return current;

		outprev = current;
		current = current->next;
		index--;
	}

	return NULL;
}

template<typename Type>
void TLinkOneList<Type>::AddFirst(Type data)
{
	_Node *node = new _Node(data);

	if (Head != NULL)
	{
		node->next = Head;
		Head = node;
	}
	else{
		Head = node;
		Tail = Head;
	}
	
	Count++;
}

template<typename Type>
void TLinkOneList<Type>::AddBack(Type data)
{
	_Node *node = new _Node(data);

	if (Tail != NULL)
	{		
		Tail->next = node;
		Tail = node;
	}
	else{
		Tail = node;
		Head = Tail;
	}

	Count++;
}

template<typename Type>
bool TLinkOneList<Type>::Insert(int index, Type data)
{
	if (index == 0)
	{
		AddFirst(data);
		return true;
	}
	
	index = index - 1;

	if (index == End())
	{
		AddBack(data);
		return true;
	}	

	_Node *current = getElement(index);
	if (current == NULL)
		return false;

	_Node *node = new _Node(data);
	node->next = current->next;
	current->next = node;

	Count++;

	return true;
}

template<typename Type>
template<typename ArrayType>
void TLinkOneList<Type>::CopyTo(ArrayType array, int len, int shift = 0)
{
	_Node *current = Head;

	int index = 0, i=0;
	while (index < Count)
	{
		i = shift + index;
		if (i < len)
			array[i] = *current;
		else
			return;

		current = current->next;
		index++;
	}
}

template<typename Type>
bool TLinkOneList<Type>::Delete(int index)
{
	if (Count == index)
		return false;

	_Node *delvar;
	if (index == 0)
	{
		delvar = Head;
		Head = delvar->next;

		if (Count == 1)
			Tail = NULL;
	}
	else
	{
		_Node *current;
		current = getElement(index - 1);

		if (current == NULL)
			return false;

		delvar = current->next;
		current->next = current->next->next;

		if (current->next == NULL) Tail = current;
	}
		
	delete delvar;
	Count--;
	
	return true;
}

template<typename Type>
bool TLinkOneList<Type>::Remove(Type name)
{	
	_Node *prev = NULL;
	_Node * current = getElementBy(name, prev);
	if (current == NULL) return false;

	if (prev == NULL)
	{
		return Delete(0);
	}
	else
	{
		prev->next = prev->next->next;
		delete current;
		if (prev->next == NULL) Tail = prev;
	}

	Count--;

	return true;
}

template<typename Type>
void TLinkOneList<Type>::Clear()
{
	_Node *current = NULL;

	while (Count > 0)
	{ 	
		current = Head;	
		Head = current->next;
		delete current;
		Count--;
	}

	Head = NULL;
	Tail = NULL;
}

template<typename Type>
void TLinkOneList<Type>::ClearEx()
{
	_Node *current = NULL;

	while (Count > 0)
	{
		current = Head;
		Head = current->next;
		delete[] *current;
		delete current;
		Count--;
	}

	Head = NULL;
	Tail = NULL;
}

template<typename Type>
Node<Type>* TLinkOneList<Type>::InverseList()
{
	_Node *past;
	_Node *current;

	int i = 0, j = 2;
	while (j <= Count)
	{
		past = Head->next;
		current = Head;
		current->next = past->next;
		past->next = current;

		Head = past;
		i = Count - j;
		while (i > 0)
		{
			past->next = current->next;
			past = past->next;
			current->next = past->next;
			past->next = current;

			i--;
		}
		if (current->next == NULL)
			Tail = current;
	j++;
	}

	return Head;
}

#endif