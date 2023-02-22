using namespace std; 

struct IntNode{
    int value;
    IntNode* next;
};

typedef struct {
    IntNode* top=NULL;  
} IntStack;

class Stack {
public:
    //push method
    void push(int data){
        IntNode* newNode = new IntNode;
        newNode->value = data;
        newNode->next = top;
        top = newNode;
    }

    //pop method
    void pop(){
        if (top == NULL) {
            cout << "Stack is empty" << endl;
        }
        IntNode* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->value;
    }

private:
    IntNode* top;
};