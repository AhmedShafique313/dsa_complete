#include<iostream>
#include<new>
using namespace std;

/*
				Implementing Stacks
*/

struct node
{
	int value;
	node* below;
};
// Global Variables
node* top = NULL;
int len = 0;

void push(int x)
{
	node* tmp;
	tmp = new node;
	tmp->value = x;
	
	if(top == NULL)
		tmp->below = NULL;
	else
		tmp->below = top;
	
	top = tmp;
	len ++;
	return;
}

void pop()
{
	if(top == NULL)
		cout << "There is nothing is in the stack";
	else
	{
		node* tmp;
		tmp = top;
		cout << "Poping value: ";
		cout << top->value << endl;
		top = tmp -> below;
		delete tmp;
		len --;
	}
	return;
}

void traverse()
{
	if(len == 0)
		cout << "Dear User! stack is empty." << endl;
	else
	{
		node* current;
		current = top;
		int a = 1;
		cout << "[";
		while(current->below != NULL)
		{
			cout <<  current->value << " ";
			current = current->below;
			a++;
		}
		cout <<  current->value;
		cout << "]" << endl;
	}
}

void choose()
{
	bool Y = 1;
	int a, v;
	while(Y == 1)
	{
		cout << "Dear User, There are series of actions that You would like to do:-" << endl;
		cout << "[1] push (x)" << endl;
		cout << "[2] pop ()" << endl;
		cout << "[3] end - stop the process." << endl;
		
		cout << "User: ";
		cin >> a;
		switch(a)
		{
			case 1:
				cout << "Enter Value to push in the stack: ";
				cin >> v;
				push(v);
				break;
			case 2:
				cout << "poping is Done" << endl;
				break;
			case 3:
				cout << "Best of Luck " << endl;
				traverse();
				Y = 0;
				break;
			default:
				cout << "Enter only Number 1 to 3" << endl;
				break;
		}
	}
}

int main(void)
{
	choose();
	delete[] top;
	return 0;
}



