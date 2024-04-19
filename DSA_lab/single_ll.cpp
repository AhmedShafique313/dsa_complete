#include <iostream>
#include <new>
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
    if (start == NULL)
    {

        start=new node;
        start->data=value;
        start->next=NULL;
        length=length+1;
    }
    else
    {
        cout<<"Linked list already exist, Please try to add instead of creating linked list"<<endl;
    }
    return;
}

// traverse function
void traverse()
{
    if (length==0)
    {
       return;
    }
    else
    {
        node *temp;
        temp = start;
        while (temp->next!=NULL)
        {
            cout<<temp->data<<"-";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
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

// main function
int main()
{
    int choice;
    do
    {
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
            creating_node(input_value);
            break;
        }
        case 2:{
            traverse();
            break;
        }
        case 3:{
            //int input_value;
            cout<<"Enter the value of new node that you want to add: : ";//cin>>input_value;
            cout<<endl;
            //creating_node(input_value);
            break;
        }
        case 4:{
            //int input_value;
            cout<<"Enter the value of new node that you want to add: : ";//cin>>input_value;
            cout<<endl;
            //creating_node(input_value);
            break;
        }
        case 5:{
            //int input_value;
            cout<<"Enter the value of new node that you want to add: : ";//cin>>input_value;
            cout<<endl;
            //creating_node(input_value);
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }while(choice!=5);
    return 0;
}