#include <iostream>
#include <new>
#include <fstream>
using namespace std;

struct node 
{
    int data ;
    node* previous ;
    node * next ;
};

//  to declare 'len' and 'start'
int length = 0;
node* start = NULL;

void create (int value) {
    if (length == 0) {
        start = new node;
        start->data = value;
        start->previous = NULL; // Use nullptr instead of NULL for better clarity
        start->next = NULL;
        length = length + 1; // Don't forget semicolon at the end of the statement
    }
    else {
        cout << "List not empty. Try Again." << endl; // Fixed the error message string
    }
    return;
}
void traverse(){
if (length == 0 )
     cout<<"List is empty"<<endl;
else{
     node* temp;
     temp = start;
    do{
     cout<< temp -> data << endl;
     temp = temp -> next;
    }
    while(temp != NULL);
}
return;
}
void remove (int value){
    if (length == 0) {
        cout << "List is empty." << endl;
        return;
    }

    node* current = start;
    node* previous = NULL;
    while (current != NULL) {
        if (current->data == value ) {
            if (current == start) {
                start = current->next;
                if (start != NULL)
                    start->previous = NULL;
            } else {
                previous->next = current->next;
                if (current->next != NULL)
                    current->next->previous = previous;
            }
            delete current;
            length = length-1;
            cout << "Node with value " << value << " deleted." << endl;
            return;
        }
    }

}


// Function to create a new node and add it to the linked list
void add(int value) {
    node* newNode = new node;
    newNode->data = value;
    newNode->previous = NULL;
    newNode->next = start;
    if (start != NULL)
        start->previous = newNode;
    start = newNode;
    length = length + 1;
}

// Function to delete a node with a given value from the linked list
void deleteNode(int value) {
    if (length == 0) {
        cout << "List is empty." << endl;
        return;
    }

    node* current = start;
    node* previous = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (current == start) {
                start = current->next;
                if (start != NULL)
                    start->previous = NULL;
            } else {
                previous->next = current->next;
                if (current->next != NULL)
                    current->next->previous = previous;
            }
            delete current;
            length=length-1;
            cout << "Node with value " << value << " deleted." << endl;
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Node with value " << value << " not found." << endl;
}

// Function to traverse and print the linked list in increasing or decreasing order
void traverse(bool increasingOrder) {
    if (length == 0) {
        cout << "List is empty." << endl;
        return;
    }

    node* current;
    if (increasingOrder) {
        current = start;
        cout << "List elements in increasing order: ";
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
    } else {
        current = start;
        while (current->next != NULL)
            current = current->next;
        cout << "List elements in decreasing order: ";
        while (current != NULL) {
            cout << current->data << " ";
            current = current->previous;
        }
    }
    cout << endl;
}

// Function to return the length of the linked list
int length_of_linked_list() {
    return length;
}

// Function to save the linked list to an output file
void saveListToFile() {
    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        node *temp = start;
        while (temp != nullptr) {
            outputFile << temp->data << " ";
            temp = temp->next;
        }
        outputFile.close();
    } else {
        cout << "Unable to open output.txt for writing" << endl;
    }
}

int main() {
    ifstream inputFile("input.txt");
    if (inputFile.is_open()) {
        int num;
        while (inputFile >> num) {
            if (start == NULL) {
                create(num);
            } else {
                add(num);
            }
        }
        inputFile.close();
    } else {
        cout << "Unable to open numbers.txt" << endl;
        return 1;
    }
    // User interaction loop
    int choice;
    do {
        cout << "---------------------------------------------------------------------" << endl;
        cout << "Dear User " << endl;
        cout << "Choose an action:" << endl;
        cout << "[1]. Add a node" << endl;
        cout << "[2]. Delete a node" << endl;
        cout << "[3]. Enumerate the elements of the list" << endl;
        cout << "[4]. Length of the list" << endl;
        cout << "[5]. End and save to file" << endl;
        cout << "Enter your choice: ";cin >> choice;cout<<endl;
        switch (choice) {
            case 1: {
                int newValue;
                cout << "Enter the value to add: ";cin >> newValue;cout<<endl;
                add(newValue);
                break;
            }
            case 2: {
                int newValue;
                cout << "Enter the value to add: ";cin >> newValue;cout<<endl;
                deleteNode(newValue);
                break;
            }
            case 3: {
                int order;
                cout << "Enumerate the elements of the list:" << endl;
                cout << "1. Deccreasing order" << endl;
                cout << "2. Increasing order" << endl;
                cout << "Enter your choice: ";cin >> order;cout<<endl;
                traverse(order == 1);
                break;
            }
            case 4: {
                cout << "Length of the list: " << length_of_linked_list() << endl;
                break;
            }
            case 5: {
                saveListToFile();
                cout << "Linked list saved to output.txt. Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 5);

    return 0;
}