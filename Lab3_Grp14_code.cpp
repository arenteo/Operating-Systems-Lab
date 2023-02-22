#include <iostream>
#include "Lab3_Grp14_struct.hpp"
#include <string>

using namespace std;

int main(void){
    IntNode head;
    IntNode initialNode; 
    IntNode item;

    int func;
    int exit=0;
    int y;

    while (exit == 0) {
        cout<<"Enter function: 1-Push 2-Pop\n";
        cin>>func;
        if (func == 1)
        {
            cout << "enter value: " << endl;
            cin >> item.value;
            cout << item.value;
        } else if (func == 2)
        {
            Stack g;
            cout <<"top is: "<< g.peek() << endl;
        } else
        {
            cout << "Not valid option, will exit";
            exit += 1;
        } 
        
        // switch (func){
        //     case 1: 
        //         cout << "enter value: " << endl;
        //         cin >> item.value;
        //         //push()
        //         break; 
        //     case 2:
        //         //pop()
        //         break;
        //     case 3:
        //         Stack g;
        //         cout << g.peek() << endl;
        //         break;
        //     case 4:
        //         cout << "Not valid option, will exit";
        //         exit += 1;
        //         break;

        // } 
    }


    // initialNode.next = &item;
    // initialNode.next = &head;
    // head.next = &initialNode;
    
    //Memory deallocation
    //delete newNode;
    //IntNode* newNode = NULL;
}

