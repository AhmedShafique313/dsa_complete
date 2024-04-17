#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
};

ListNode* head = nullptr;

void createNode(int data) {
    ListNode* newNode = new ListNode;
    newNode->data = data;
    newNode->next = nullptr;
    head = newNode;
}

void insertNode(int data) {
    if (head == nullptr || data < head->data) {
        ListNode* newNode = new ListNode;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        return;
    }

    ListNode* current = head;
    ListNode* prev = nullptr;
    while (current != nullptr && current->data < data) {
        prev = current;
        current = current->next;
    }
    ListNode* newNode = new ListNode;
    newNode->data = data;
    newNode->next = current;
    prev->next = newNode;
}

void deleteNode(int data) {
    ListNode* current = head;
    ListNode* prev = nullptr;
    while (current != nullptr && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Not found" << endl;
        return;
    }
    if (prev == nullptr) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    delete current;
    cout << "Deleted " << data << ", new List: ";
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " - ";
        temp = temp->next;
    }
    cout << endl;
}

int getListLength() {
    int count = 0;
    ListNode* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void printList() {
    cout << "Items included are: ";
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr)
            cout << " - ";
        current = current->next;
    }
    cout << endl;
}

void readFileAndCreateList(string filename) {
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        int num;
        while (inputFile >> num) {
            if (head == nullptr) {
                createNode(num);
            } else {
                insertNode(num);
            }
        }
        inputFile.close();
    } else {
        cout << "Unable to open " << filename << endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Dear User, the program requires one argument: Name of file containing list of numbers." << endl;
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    cout << "Dear User, reading file \"" << filename << "\"" << endl;
    readFileAndCreateList(filename);
    cout << "Linked List created." << endl;

    printList();

    while (true) {
        cout << "What would you like to do next? Options are:" << endl;
        cout << "(1) add a node," << endl;
        cout << "(2) delete a node," << endl;
        cout << "(3) enumerate the elements of the list," << endl;
        cout << "(4) length of the list, and" << endl;
        cout << "(5) stop the process" << endl;

        cout << "User: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter the number to add: ";
                cin >> data;
                insertNode(data);
                printList();
                break;
            }
            case 2: {
                int data;
                cout << "Enter the number to delete: ";
                cin >> data;
                deleteNode(data);
                break;
            }
            case 3:
                printList();
                break;
            case 4:
                cout << "OK. Length: " << getListLength() << endl;
                break;
            case 5:
                cout << "Stopping the process." << endl;
                exit(EXIT_SUCCESS);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}