using namespace std; 

struct IntNode{
    int value;
    IntNode* next;
};

typedef struct {
    IntNode* top=NULL;    
    void push(int data){
        IntNode* newNode = new IntNode;
        newNode->value = data;
        newNode->next = top;
        top = newNode;
    }

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
        }
        return top->value;
    }
} IntStack;

