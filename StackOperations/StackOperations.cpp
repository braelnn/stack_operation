#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> elements;   // holds the stack's elements 

public:
    Stack() {
        cout << "Stack created." << endl;
    }

        ~Stack() {
        cout << "Stack has been destroyed." << endl;
    }

    // adds an element to the top of the stack
    void push(int value) {
        elements.push_back(value);
        cout << value << " Element inserted into the stack." << endl;
    }

    // removes the element from the top of the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Push some elements into the stack" << endl;
            return;
        }
        cout << elements.back() << "Element removed from the stack." << endl;
        elements.pop_back();
    }

    // returns the top element without removing it
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty, no top element." << endl;
            return -1;  
        }
        return elements.back();
    }

    // checks if the stack is empty
    bool isEmpty() {
        return elements.empty();
    }

    // returns the number of elements in the stack
    int size() {
        return elements.size();
    }

    // prints the stack contents from top to bottom
    void printStack() {
        if (isEmpty()) {
            cout << "[ empty ]" << endl;
            return;
        }
        cout << "Stack contents (top -> bottom): ";
        for (int i = elements.size() - 1; i >= 0; i--) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }

    // getter
    vector<int> getElements() {
        return elements;
    }

    // setter
    void setElements(vector<int> newElements) {
        elements = newElements;
    }
};

int main() {
    Stack stack1;
    int choice, value;

    cout << "Stack Operations Menu in C++" << endl;
    do {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. isEmpty\n5. Size\n6. Print Stack\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack1.push(value);
            break;
        case 2:
            stack1.pop();
            break;
        case 3:
            cout << "Top element: " << stack1.top() << endl;
            break;
        case 4:
            cout << "Is empty? " << (stack1.isEmpty() ? "Yes" : "No") << endl;
            break;
        case 5:
            cout << "Size: " << stack1.size() << endl;
            break;
        case 6:
            stack1.printStack();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 0);

    return 0;
}