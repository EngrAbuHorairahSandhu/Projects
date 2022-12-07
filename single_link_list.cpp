#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    void insert(int x);
    void insert(int x, int y);
    void print();
    void delet(int y);
};

Node *head;

void Node :: delet(int y)
{
	Node *temp = new Node();
	temp = head;
	if(y == 1)
	{
		temp = temp->next;
		delete temp;
	}
	else
	{
		Node *temp1 = new Node();
		temp1 = head;
		for(int i = 0; i < y-2; i++)
		{
			temp = temp->next;
		}
		temp1 = temp->next;
		temp->next = temp1->next;
		delete temp1;
	}
}
void Node :: insert(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Node ::insert(int x, int y)
{
    Node *temp = new Node();
    temp->data = x;

    if (y == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        Node *temp1 = new Node();
        temp1 = head;
        for (int i = 0; i < y - 2; i++)
        {
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;


    }
}

void Node :: print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    head = NULL;
    Node obj;
    int size, num, pos;
    cout << "Enter size of list = ";
    cin >> size;
    // for main list creation
    for (int i = 0; i < size; i++)
    {
        cout << "Enter number = ";
        cin >> num;
        obj.insert(num);
    }
    obj.print();
    cout << "\n\nEnter position of new node = ";
    cin >> pos;
    cout << "Enter new number/data on node = ";
    cin >> num;
    obj.insert(num, pos);
    obj.print();
    cout<<"\nEnter position of node to delete = ";
    cin>>pos;
    obj.delet(pos);
	obj.print();
    return 0;
}