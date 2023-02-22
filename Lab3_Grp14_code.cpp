#include <iostream>
#include "Lab3_Grp14_struct.hpp"
using namespace std;

int main(void){
    IntNode head;
    IntNode initialNode; 

    IntNode item;
    item.value = 5;

    //link nodes to each other
    initialNode.next = item;
    initialNode.next = head;
    head.next = initialNode;

    //print values
    cout << item.value << endl;
    
    //Memory deallocation
    //delete newNode;
    //IntNode* newNode = NULL;
}