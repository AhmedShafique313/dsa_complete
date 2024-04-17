#include <iostream>
#include <fstream>
using namespace std;

// Define Node structure
struct Node {
    int value;
    Node *next;
};

// Global variable for the start of the linked list
Node *head = nullptr;

// Function prototypes
void create(int data);
void insert(int data);
void remove(int data);
int listLength();
void printList();
void saveListToFile();

// Function to create the very first node
void create(int data) {
    Node *newNode = new Node;
    newNode->value = data;
    newNode->next = nullptr;
    head = newNode;
}

// Function to insert numbers in sorted order
void insert(int data) {
    if (head == nullptr || data < head->value) {
        Node *newNode = new Node;
        newNode->value = data;
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *current = head;
    Node *prev = nullptr;
    while (current != nullptr && current->value < data) {
        prev = current;
        current = current->next;
    }
    Node *newNode = new Node;
    newNode->value = data;
    newNode->next = current;
    prev->next = newNode;
}

// Function to delete a node
void remove(int data) {
    Node *current = head;
    Node *prev = nullptr;
    while (current != nullptr && current->value != data) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Node not found" << endl;
        return;
    }
    if (prev == nullptr) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    delete current;
    cout << "Deleted node with value " << data << endl;
}

// Function to find the length of the linked list
int listLength() {
    int count = 0;
    Node *current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to traverse and print elements of the linked list
void printList() {
    Node *current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to store the linked list to a file
void saveListToFile() {
    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        Node *current = head;
        while (current != nullptr) {
            outputFile << current->value << " ";
            current = current->next;
        }
        outputFile.close();
        cout << "Linked list saved to output.txt" << endl;
    } else {
        cout << "Unable to open output.txt for writing" << endl;
    }
}

int main() {
    // Create and populate the linked list from an external file
    ifstream inputFile("sli.txt");
    if (inputFile.is_open()) {
        int num;
        while (inputFile >> num) {
            if (head == nullptr) {
                create(num);
            } else {
                insert(num);
            }
        }
        inputFile.close();
    } else {
        cout << "Unable to open numbers.txt" << endl;
        return 1;
    }

    // Actions loop
    int choice;
    do {
        cout << "Choose an action:" << endl;
        cout << "1. Add a node" << endl;
        cout << "2. Delete a node" << endl;
        cout << "3. Enumerate the elements of the list" << endl;
        cout << "4. Length of the list" << endl;
        cout << "5. End and store the current linked list" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                insert(data);
                break;
            }
            case 2: {
                int data;
                cout << "Enter data to delete: ";
                cin >> data;
                remove(data);
                break;
            }
            case 3:
                cout << "Elements of the list: ";
                printList();
                break;
            case 4:
                cout << "Length of the list: " << listLength() << endl;
                break;
            case 5:
                saveListToFile();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}