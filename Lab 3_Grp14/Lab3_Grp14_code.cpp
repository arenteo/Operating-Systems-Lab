#include <iostream>
#include "Lab3_Grp14_struct.hpp"
#include <string>

using namespace std;

int main(void){

    IntNode item;
    IntStack g;

    int func;
    int exit=0;
    int y, z;

    do {
        cout<<"Enter function: 1-Push 2-Pop\n";
        cout<<"                3-Peek 4++-Quit\n";
        cin>>func;

        if(func > 3){
            cout << "not valid option, will quit";
            exit++;
        }

        switch (func){
            case 1: 
                cout << "enter integer value:" << endl;
                cin >> z;
                g.push(z);
                break; 
            case 2:
                cout << "removing: " << g.peek() << endl; 
                g.pop();
                break;
            case 3:
                cout << g.peek() << endl;
                break;
        } 
    } while (exit == 0);
}

