#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
public:
    Node *top = NULL;

    void push(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        if (is_empty())
        {
            top = newnode;
            newnode->next = NULL;
            return;
        }
        Node *temp = top;
        top = newnode;
        newnode->next = temp;
    }
    int pop()
    {
        int item;
        Node *temp = top;
        item = top->data;
        top = top->next;
        delete temp;

        return item;
    }
    void display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
    bool search(int value)
    {
        Node *temp = top;
        bool found = false;
        while (temp != NULL)
        {
            if (temp->data == value)
                found = true;
            temp = temp->next;
        }
        return found;
    }
    bool is_empty()
    {

        return (top == NULL);
    }
    int peek()
    {
        int item;
        item = top->data;
        return item;
    }
    int count()
    {
        int counter = 0;
        Node *temp = top;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
};

int main()
{

    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.display();
    st.pop();
    st.display();

    cout << "\nChoose a process by typing the process number : \n";
    cout << "\n1.push  \t2.pop   \t3.search   \t4.peek   \t5.count     \n";
    int pNum;
    int item;
    cin >> pNum;
    switch (pNum)
    {
    case 1:
        cout << "Enter the num to push in the stack : \n ";
        cin >> item;
        st.push(item);
        break;
    case 2:
        int index;
        cout << "pop item from the stack : \n";
        st.pop();
        break;
    case 3:
        cout << "\nEnter item to search: ";
        cin >> item;
        if (st.search(item))
        {
            cout << "the item is found\n";
        }
        else
            cout << " item not found\n";
        break;
    case 4:
        cout << "\nthe item in the top is : " << st.peek() << endl;

        break;
    case 5:
        cout << "\ncount stack is : ";
        st.count();

        break;
    case 6:

        break;
    default:
        break;
    }
    st.display();

    return 0;
}
