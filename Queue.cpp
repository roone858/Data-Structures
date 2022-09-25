#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class queue
{
public:
    Node *front;
    Node *rear = front;

    void enqueue(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        Node *temp = rear;
        rear = newnode;
        newnode->next = temp;
    }
    void display()
    {
        Node *temp = rear;
        while (temp != front)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
    }
    int count()
    {
        int counter = 0;
        Node *temp = rear;
        while (temp != front)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    int dequeue()
    {
        Node *temp = rear;
        while (temp->next->next != front)
            temp = temp->next;

        Node *last = temp->next;
        temp->next = front;
        int lastdata = last->data;
        delete last;
        return lastdata;
    }
    int peek()
    {
        Node *temp = rear;
        while (temp->next != front)
            temp = temp->next;
        int lastdata = temp->data;
        return lastdata;
    }
    void clear()
    {
        rear = front;
    }
};

int main()
{

    queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();

    cout << endl;
    q.dequeue();
    q.display();

    return 0;
}
