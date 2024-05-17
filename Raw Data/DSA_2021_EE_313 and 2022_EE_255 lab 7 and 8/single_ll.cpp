#include <iostream>
#include <new>
#include <fstream>
using namespace std;

// Structure of node
struct node 
{
    int data;
    node *next;
};

// Initialization of node
int length = 0;
node *start = NULL;

// If no linked list then create 
void creating_node(int value)
{
    try
    {
        if (start == NULL)
        {

            start=new node;
            start->data=value;
            start->next=NULL;
            length=length+1;
        }
        else
        {
            throw(value);
        }
    }
    catch(int data)
    {
        cout<<"Linked list already exist, Please try to add instead of creating linked list"<<endl;
    }
    return;
}

// traverse function
void traverse()
{
    try
    {
        if (length==0)
        {
            throw(1);
        }
        else
        {
            node *temp;
            temp = start;
            int len=1;
            while (temp->next!=NULL)
            {
                cout<<"["<<len<<"]: "<<temp->data<<" "<<endl;
                temp=temp->next;
                len = len +1;
            }
            cout<<"["<<len<<"]: "<<temp->data<<" "<<endl;
        }
    }
    catch(...)
    {
        cout<<"Linked list is empty, Try create and add then traverse"<<endl;
    }
    
    return;
}

// Add node in linked list
void add(int value)
{
    if (length==0)
    {
        cout<<"There is no sign of linked list, Try to create linked list first"<<endl;
    }
    else
    {
        node *temp;
        temp = start;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        node * new_node;
        new_node = new node;
        new_node->data=value;
        new_node->next=NULL;
        temp->next=new_node;
        length = length+1;
    }
    
    return;
}

// deleting a node
void deleting(int value)
{
    try
    {
        if (length==0)
        {
            throw(1);
            cout<<"Linked list is empty, deleting is not possible"<<endl;
        }
        else
        {
            node *current, *prev;
            current = start;
            while ((current->next!=NULL) && (current->data!= value))
            {
                prev = current;
                current = current->next;
            }
            if (current->data==value)
            {
                // if it is first node then
                if (current==start)
                {
                    start = current->next;
                }
                else
                {
                    prev->next=current->next;
                }
                delete current;
                length=length-1;
            }
        }
        cout<<"Noting to delete"<<endl;
    }
    catch(...)
    {
        cout<<"Node having value ["<<value<<"] not found, Hence nothing to delete"<<endl;
    }
    return;
}

// length of the node
int size_of_linked_list()
{
    int size=1;
    node *temp = start;
    while (temp->next!=NULL)
    {
        temp=temp->next;
        size = size +1;
    }
    return size;
}

// Function to store the linked list to a file
void saveListToFile() {
    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        node *temp = start;
        while (temp != nullptr) {
            outputFile << temp->data << " ";
            temp = temp->next;
        }
        outputFile.close();
        cout << "Linked list saved to output.txt" << endl;
    } else {
        cout << "Unable to open output.txt for writing" << endl;
    }
}

// main function
int main()
{
    cout<<"Dear User, reading file input.txt"<<endl;
    ifstream inputFile("input.txt");
    if (inputFile.is_open()) {
        int num;
        while (inputFile >> num) {
            if (start == NULL) {
                creating_node(num);
            } else {
                add(num);
            }
        }
        inputFile.close();
    } else {
        cout << "Unable to open numbers.txt" << endl;
        return 1;
    }
    int choice;
    do
    {
        cout<<endl;
        cout << "Choose any single action:" << endl;
        cout << "[1] Add a node?" << endl;
        cout << "[2] Delete a node?" << endl;
        cout << "[3] Enumerate the elements of the list?" << endl;
        cout << "[4] Length of the list?" << endl;
        cout << "[5] End and store the current linked list?" << endl;
        cout<<"-----------------------------------------------------------------------------"<<endl;
        cout << "Enter your choice: ";cin>>choice;cout<<endl;
        switch (choice)
        {
        case 1:{
            int input_value;
            cout<<"Enter the value of node: ";cin>>input_value;cout<<endl;
            add(input_value);
            break;
        }
        case 2:{
            int input_value;
            cout<<"Enter the value of node that you want to delete: ";cin>>input_value;cout<<endl;
            deleting(input_value);
            break;
        }
        case 3:{
            traverse();
            break;
        }
        case 4:{
            cout<<"Length of the single linked list: "<<size_of_linked_list()<<endl;
            break;
        }
        case 5:{
            saveListToFile();
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }while(choice!=5);
    return 0;
}
// to run on CMD use single_ll.exe single_llc.cpp sli.txt