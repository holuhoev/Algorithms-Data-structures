////////////////////////////////////////////////////////////////////////////////
// Module Name:  main.cpp
// Authors:      Sergey Shershakov
// Version:      0.1.0
// Date:         01.05.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "rbtree.h"
#include "../tests/def_dumper.h"

using namespace std;


void simplestTest()
{
    using namespace xi;

    // ������ ������� ������ ������
    RBTree<int> tree1;



    RBTreeDefDumper<int,std::less<int> > *dumper = new  RBTreeDefDumper<int,std::less<int> >("/Users/evgenijlebedev/ClionProjects/2_14/log.txt","/Users/evgenijlebedev/ClionProjects/2_14/imgs/");

    tree1.setDumper(dumper);

    //insert 4, 50, 10, 40, 17, 35, 20, 27, 37, 45, 60, 21, 1, 30.
    tree1.insert(4);
    tree1.insert(50);
    tree1.insert(10);
    tree1.insert(40);
    tree1.insert(17);
    tree1.insert(35);
    tree1.insert(20);
    tree1.insert(27);
    tree1.insert(37);
    tree1.insert(45);
    tree1.insert(60);
    tree1.insert(21);
    tree1.insert(1);
    tree1.insert(30);

}


int main()
{
    cout << "Hello, World!" << endl;

    simplestTest();

    return 0;
}