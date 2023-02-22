#include <iostream>
#include "IntNode.hpp"
#include "IntStack.hpp"
using namespace std;

int main(void){
    IntNode head;
    IntNode initialNode; 

    IntNode item;

    initialNode.next = item;
    initialNode.next = head;
    head.next = initialNode;
    
    //Memory deallocation
    //delete newNode;
    //IntNode* newNode = NULL;
}