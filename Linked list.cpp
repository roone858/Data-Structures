#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};
class linkedlist
{
public:
	Node *head;
	linkedlist() { head = NULL; }
	bool search(int value)
	{
		Node *temp = head;
		while (temp->next != NULL)
		{
			if (temp->data == value)
				return true;
			temp = temp->next;
		}
		return false;
	}
	int count()

	{
		Node *temp = head;
		int count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
	bool is_empty()
	{
		return (head == NULL);
	}
	void display()
	{
		Node *temp = head;
		while (temp != NULL)
		{

			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << endl;
	}
	void push(int value)
	{
		Node *newnode = new Node();
		newnode->data = value;
		if (is_empty())
		{
			newnode->next = NULL;
			head = newnode;
			return;
		}
		newnode->next = head;
		head = newnode;
	}
	void insert_after(int value, int data)
	{
		Node *temp = head;
		Node *newnode = new Node();
		newnode->data = data;
		if (is_empty())
		{
			append(data);
			return;
		}

		while (temp->data != value)
			temp = temp->next;
		newnode->next = temp->next;
		temp->next = newnode;
	}
	void append(int value)
	{
		Node *newnode = new Node();
		newnode->data = value;
		if (is_empty())
		{
			newnode->next = NULL;
			head = newnode;
		}
		else
		{
			Node *temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = newnode;
			newnode->next = NULL;
		}
	}
	void delete_end()
	{
		Node *temp = head;
		while (temp->next->next != NULL)
			temp = temp->next;
		Node *old = temp->next;
		delete old;
		temp->next = NULL;
	}
	void delete_first()
	{
		Node *temp = head;
		head = temp->next;
		delete temp;
	}
	void delete_item(int value)
	{
		Node *temp = head;
		Node *old = new Node();
		if (count() > 1 && search(value))
		{
			while (temp != NULL)
			{
				old = temp->next;
				if (old->data == value)
				{
					temp->next = old->next;
					delete old;
					return;
				}
				temp = temp->next;
			}
		}
		else if (count() == 1 && temp->data == value)
		{
			head = NULL;
			delete temp;
			cout << " list now is empty ";
		}
		else
		{
			cout << "the value is not in the list.\n";
		}
	}
	int value_count(int value)
	{
		Node *temp = head;
		int count = 0;
		while (temp != NULL)
		{
			if (temp->data == value)
				count++;
			temp = temp->next;
		}
		return count;
	}
	void replace(int value, int newdata)
	{
		Node *temp = head;

		while (temp != NULL)
		{

			if (temp->data == value)
			{

				temp->data = newdata;
			}
			temp = temp->next;
		}
	}
};
int main()
{
	linkedlist list;

	if (list.is_empty())
		cout << "list is empty" << endl;
	else
		cout << "lis  is not empty" << endl;
	list.display();
	cout << "how many item you want add : ";
	int length;
	cin >> length;

	for (int i = 0; i < length; i++)
	{
		int value;
		cout << "enter item : ";
		cin >> value;
		list.append(value);
	}

	list.display();

	cout << "\nChoose a process by typing the process number : \n";
	cout << "\n1.append   \t2.push    \t3.insert-after   \t4.delete-end   \n5.delete-first    \t6.delete-item    \t7.replace \n";
	int pNum;
	int item;
	cin >> pNum;
	switch (pNum)
	{
	case 1:
		cout << "\nEnter item to append : ";
		cin >> item;
		list.append(item);
		break;
	case 2:
		cout << "\nEnter item to push : ";
		cin >> item;
		list.push(item);
		break;
	case 3:
		cout << "\nEnter item to insert after value : ";
		cout << "\nitem : ";
		cin >> item;
		cout << "\nvalue : ";
		int x;
		cin >> x;
		list.insert_after(x, item);
		break;
	case 4:
		list.delete_end();
		break;
	case 5:
		list.delete_first();
		break;
	case 6:
		cout << "\nEnter item to delete : ";
		cin >> item;
		list.delete_item(item);
		break;
	case 7:
		cout << "\nEnter item to replace with old value : ";
		cout << "\nitem : ";
		cin >> item;
		cout << "\nold value : ";
		int r;
		cin >> r;
		list.replace(r, item);
		break;
	default:
		break;
	}

	list.display();
	return 0;
}
