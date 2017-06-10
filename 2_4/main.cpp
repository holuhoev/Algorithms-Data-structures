
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#include "linked_list.h"
#include "dna_repairer.h"


using namespace std;

static const char* INP_FILENAME = "/Users/evgenijlebedev/Downloads/prj-1.0/src/tests/test.in";

int main (int argc, char* argv[])
{
    try{
        xi::LinkedList<int> linkedList;

        xi::Node<int>* node1 = linkedList.insertNewElement(10, nullptr);
        xi::Node<int>* node2 = linkedList.insertNewElement(20, node1);
        xi::Node<int>* node3 = linkedList.insertNewElement(30, node2);
        xi::Node<int>* node4 = linkedList.insertNewElement(40, node3);
        xi::Node<int>* node5 = linkedList.insertNewElement(50, node4);
        vec
        linkedList.deleteNodes(node2,node5);

//        DNARepairer dnarepairer;
//
//        dnarepairer.readFile(INP_FILENAME);
//
//
//        cout << "Broken DNAs" << endl;
//        dnarepairer.printDNAStorage();
//
//        dnarepairer.repairDNA();
//
//        cout << "\nGood as it is" << endl;
//        dnarepairer.printDNAStorage();

    }
    catch(exception &e) {
        cout << e.what();
    }
    catch (...){
        cout << "Something wrong happend." << endl;
    }
    cout << endl;

    return EXIT_SUCCESS;
}

