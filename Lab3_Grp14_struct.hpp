typedef struct {
    int value;
    IntNode* next;
} IntNode;


class Stack {
public:
    typedef struct {
        top=NULL;
        newVal;  
    } IntStack;

    //push method
    void push(int value){
        IntNode* newNode = new IntNode;
        newNode->value = newVal;
        newNode->next = top;
        top = newNode;
    }

    //pop method
    void pop(){

    }
}