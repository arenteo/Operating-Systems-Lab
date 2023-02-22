#include <iostream>
#include "Lab3_Grp14_struct.hpp"
#include <cstring>
using namespace std;

int main(void){
    IntNode head;
    IntNode initialNode; 
    IntNode item;

    string func;
    int exit=0;

    do {
        cout<<"Enter function: 1-Push 2-Pop";
        cin>>func;

        switch (func){
            case 1: 
            cout << "enter value: " << endl;
            cin >> item.value;
            //push()
            break; 
            case 2:
            //if func == pop"
            //pop()
            case 3:
            cout << "Not valid option, will exit";
            exit += 1;
        } 
    } while (exit = 0);
    

    initialNode.next = &item;
    initialNode.next = &head;
    head.next = &initialNode;
    
    //Memory deallocation
    //delete newNode;
    //IntNode* newNode = NULL;
    return 0;
}

