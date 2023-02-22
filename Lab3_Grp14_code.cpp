#include <iostream>
#include "Lab3_Grp14_struct.hpp"
using namespace std;

int main(void){
    IntNode head;
    IntNode initialNode; 

    IntNode item;

    cin >> item.value;
    cout << item.value << endl;

    initialNode.next = &item;
    initialNode.next = &head;
    head.next = &initialNode;
    
    //Memory deallocation
    //delete newNode;
    //IntNode* newNode = NULL;
}