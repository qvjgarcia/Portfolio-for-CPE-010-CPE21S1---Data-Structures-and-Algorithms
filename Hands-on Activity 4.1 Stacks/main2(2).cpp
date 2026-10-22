#include <iostream>
#include <string>

struct Node{
    char data;
    Node* next;
};

// Top starts as nullptr because the list is empty
Node* top = nullptr;

bool isEmpty(){
    if(top == nullptr) return true;
    return false;
}

void push(char c){
    Node* newNode = new Node();
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

char pop(){
    if(isEmpty()){
        return '\0';
    }
    Node* temp = top;
    char poppedData = temp->data;
    top = top->next;
    delete temp;
    return poppedData;
}

int main(){
    std::string expr;

    std::cout << "Enter expression: ";
    std::cin >> expr;

    bool isValid = true;

    for(int j = 0; j < expr.length(); j++){
        char ch = expr[j];

        if(ch == '(' || ch == '{' || ch == '['){
            push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(isEmpty()){
                isValid = false;
                break;
            }

            char popped = pop();

            if((ch == ')' && popped != '(') ||
               (ch == '}' && popped != '{') ||
               (ch == ']' && popped != '[')){
                isValid = false;
                break;
            }
        }
    }

    if(!isEmpty()){
        isValid = false;
    }

    if(isValid){
        std::cout << "Result: Expression is VALID." << std::endl;
    }else {
        std::cout << "Result: Expression is INVALID (Unbalanced Symbols)." << std::endl;
    }

    return 0;
}