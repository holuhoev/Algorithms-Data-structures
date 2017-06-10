////////////////////////////////////////////////////////////////////////////////
// Module Name:  linked_list.h/cpp
// Authors:      Sergey Shershakov, Leonid Dworzanski
// Version:      0.2.0
// Date:         06.02.2017
// Copyright (c) The Team of "Algorithms and Data Structures" 2014–2017.
//
////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>

namespace xi {

template<class T>
LinkedList<T>::LinkedList()
{
    //Creation of the dummy/sentinel element
    _preHead = new Node<T>;
    _preHead->next = nullptr;

}

template<class T>
LinkedList<T>::~LinkedList()
{
    deleteNodes(_preHead, getLast());
    // на забудьте удалить иск. элемент, например так:
    delete _preHead;
}

// TODO: Write your code here

template<class T>
Node <T>* LinkedList<T>::insertNewElement(const T &val, Node <T>* pAfter)
{

    Node<T>* node = new Node<T>;
    node->value = val;

    if (!pAfter)
        pAfter = _preHead;

    //Создание нового элемента и вставка его в список после pAfter
    if (pAfter)
    {
        Node<T>* next = pAfter->next;
        node->next = pAfter->next;

        pAfter->next = node;
    }

    return node;
}

template<class T>
int LinkedList<T>::size()
{
    int size = 0;
    Node<T>* node = _preHead->next;

    //go through all the elements and count
    while (node)
    {
        node = node->next;
        ++size;
    }

    return size;
}

template<class T>
void LinkedList<T>::addElementToEnd(T &value)
{
    Node<T>* tempNode = getLast();
    insertNewElement(value, tempNode);
}

template<class T>
void LinkedList<T>::deleteNextNode(Node <T>* pNodeBefore)
{
    if (pNodeBefore && pNodeBefore->next)
    {
        Node<T>* temp = pNodeBefore->next->next;

        delete pNodeBefore->next;

        pNodeBefore->next = temp;
    }
}

template<class T>
void LinkedList<T>::deleteNodes(Node <T>* pNodeBefore, Node <T>* pNodeLast)
{
    while (pNodeBefore->next != pNodeLast)
    {
        deleteNextNode(pNodeBefore);
    }

    // delete last node
    deleteNextNode(pNodeBefore);
}

template<class T>
void LinkedList::moveNodeToEnd(Node<T>* pNodeBefore)
{
    moveNodeAfter(getLast(),pNodeBefore);
}

template<class T>
void LinkedList::moveNodesToEnd(Node<T>* pNodeBefore, Node<T>* pNodeLast)
{
    moveNodesAfter(getLast(),pNodeBefore,pNodeLast);
}

template<class T>
void LinkedList::moveNodesAfter(Node <T>* pNode, Node <T>* pNodeBefore, Node <T>* pNodeLast)
{
    //save next element
    Node<T>* temp = pNode->next;

    pNode->next = pNodeBefore->next;

    //"delete" from previous list
    pNodeBefore->next = pNodeLast->next;

    //connect with list
    pNodeLast->next = temp;
}

template<class T>
void LinkedList::moveNodeAfter(Node <T>* pNode, Node <T>* pNodeBefore)
{
    if (pNodeBefore && pNodeBefore->next)
    {
        Node<T>* temp = pNode->next;

        pNode->next = pNodeBefore->next;

        //"delete" from previous list
        pNodeBefore->next = pNodeBefore->next->next;

        pNode->next->next = temp;
    }
}

template<class T>
Node <T>* LinkedList::getLast()
{
    Node<T>* tempNode = _preHead;

    //get last element
    while (tempNode->next)
        tempNode = tempNode->next;

    return tempNode;
}

} // namespace xi