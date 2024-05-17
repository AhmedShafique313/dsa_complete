#include<iostream>
#include<new>
using namespace std;

struct node
{
	int value;
	node* behind;
};

// some global variables
node* front = NULL;
node* back = NULL;
int len = 0;

void insert(int v)
{
	node* current;
	current = new node;
	current->value = v;
	current->behind = NULL;
	if(front == NULL && back == NULL)
	{
		front = current; // remain the same
		back = current;  // this value can change
	}
	else
	{
		back->behind = current;
		back = current;
	}
	len ++;
	return ;
}

void process()
{
	if(front == NULL)
		cout << "Dear User! There is noting to Delete." << endl;
	else
	{
		node* tmp;
		tmp = front;
	
		front = tmp->behind;
		delete tmp;
		len --;
	}
	return;
}

void traverse()
{
	if(len == 0 || front == NULL)
		cout << "There is noting to Delete" << endl;
	else
	{
		node* tmp;
		tmp = front;
		cout << "[ ";
		while(tmp->behind != NULL)
		{
			cout << tmp->value << " ";
			tmp = tmp -> behind;
		}
		cout << tmp->value << " ]\n";
	}
	return;
}

void option()
{
	bool M = 1;
	int a, b;
	while(M)
	{
		cout << "The user a series of actions that he/she would like to do	" << endl;
		cout << "[1] insert\n";
		cout << "[2] process\n";
		cout << "[3] travsers\n";
		cout << "[4] end - stop the process\n";

		cout << "User: ";
		cin >> a;
		switch(a)
		{
			case 1:
				cout << "Enter value:		";
				cin >> b;
				insert(b);
				break;
			case 2:
				cout << "Dear User! The top value is deleted\n";
				process();
				break;
			case 3:
				cout << "Len = " << len << endl;
				traverse();
				break;
			case 4:
				cout << "Ok! Good Luck" << endl;
				M = 0;
				break;
			default:
				cout << "Dear User! Enter only Numbers in the range of 1-4" << endl;
				break;
		}
	}
	return;
}

int main(void)
{
	option();
	
	delete front;
	delete back;
	return 0;
}
