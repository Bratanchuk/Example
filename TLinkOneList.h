 /*
 element->element....
 Однонаправленный список 

private _Node* getElementBy(Type name); недостаток: при char* не сработает из-за сравнение,
если конечно  char* не будет упакован и переопределен оператор сравнения
*/

#pragma once
#ifndef TLINKONELIST_H
#define TLINKONELIST_H

#include "Property.h"

template<typename Type>
struct Node
{
	public Node(Type value){ data = value; next = NULL; }
	private Type data;
	public Set(Type){ data = value; }
	public Get(Type&){ return data; }

	/*public void operator delete (void* obj)
	{
			//free(obj);
		//delete ((Node*)obj)->data;
		delete obj;
	}*/
	
	public Node<Type> *next;
};

template<typename Type>
class TLinkOneList
{
	private Type Empty;
	//по умолчанию возвращает значение operator []
	public void DefaultEmpty(Type e){ Empty = e; };
	public void FreeDefaultEmpty(){ if(Empty != NULL)  delete Empty; };

	typedef Node<Type> _Node;
	private _Node *Head;
	private _Node *Tail;
	public read_property(int, Count, set{ Count = value; }, get{ return Count; }, TLinkOneList)
	
	private _Node* getElement(int index);
	private _Node* getElementBy(Type name, _Node* &outprev); // не додуман
	private _Node* getElementBy(Type name){ _Node*empty; return getElementBy(name, empty); };

	public inline int End(){ return Count - 1; };
	public void AddFirst(Type data);
	public void AddBack(Type data);
	public void Add(Type data){ AddBack(data); }

	public bool Insert(int index, Type data);
	public template<typename ArrayType>
			void CopyTo(ArrayType array, int len, int shift = 0);
	public bool Delete(int index);
	public bool Remove(Type name);
	public void Clear();
	public void ClearEx();

	//SET GET
	public Type& operator [](int index)
	{
		_Node *cur = getElement(index);
		if (cur == NULL)
		{
			Type empty = Empty;
			return empty;
		}		
		return *cur;
	}

	public Type& operator [](Node<Type> *index)
	{
		_Node *cur = getElementBy(*index);
		if (cur == NULL)
		{
			Type empty = Empty;
			return empty;
		}
		return *cur;
	}

	public _Node* InverseList();

	public TLinkOneList();
	public ~TLinkOneList();
};

#endif
