#include <iostream>
using namespace std;
class Array
{
private:
    int size;
    int length;
    int *arr; //<<< pointer

public:
    Array(int arrsize) // Constructor MEANS
    {                  // when you create object[array] from the class we will do that :-

        size = arrsize;      // size is equal to the input value [from user]
        length = 0;          // there is no items in [empty] but has size
        arr = new int[size]; // here we created new array with const size and Empty [lenght=0]
    }
    void Fill()         // when we call func
    {                   // Remember the size is already set
        int numOfItems; // take the length from user
        cout << "how many items you want to fill ? \n";
        cin >> numOfItems;
        length = numOfItems;
        if (numOfItems > size) // check if the lenth is less or equal than size
        {
            cout << " you can not fill over size \n";
            return;
        }
        else
        {
            for (int i = 0; i < numOfItems; i++)
            {
                cout << "Enter item " << i << endl;
                cin >> arr[i];
            }
        }
        cout << "\n";
    }
    void display()
    {
        cout << "size is " << size << "  \t";
        cout << "length is " << length << "\n";
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << "\n";
    }
    int getsize()
    {

        return size;
    }
    int getlength()
    {

        return length;
    }
    void Search(int key)
    {

        int index = -1;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == key)
                index = i;
        }
        if (key == -1)
            cout << "item not found \n ";
        else
            cout << "item position in index " << index << endl;
        cout << "\n";
    };
    void append(int num)
    {
        arr[length] = num;
        length++;
    }
    void insert(int index, int newitem)
    {
        if (index >= 0 && index < length)
        {
            for (int i = length; i > index; i--)
                arr[i] = arr[i - 1];

            arr[index] = newitem;
            length++;
        }
        else
        {
            cout << "Error - index  out of the range size \n";
        }
    }
    // Delete index not value
    // if u want delete value you must search about index of value and then delete index
    void Delete(int index)
    {
        if (index >= 0 && index < size)
        {
            for (int i = index; i < length; i++)
                arr[i] = arr[i + 1];

            length--;
        }
        else
        {
            cout << "error";
        }
    }
    void Enlarge(int newsize)
    {

        int *old = arr;                  // copy the old array [arr] to the pointer called old
        arr = new int[newsize];          // Then we recreate the old array [arr] using newsize
        for (int i = 0; i < length; i++) // Then copy the old to the recreated array [arr] with the new size
            arr[i] = old[i];
        delete[] old; // here delete old array from the memory
    }
};

int main()
{
    int size;
    cout << "Enter the array size : \n";
    cin >> size;
    Array arr1(size); // create the array

    arr1.display();
    arr1.Fill();
    cout << "\nChoose a process by typing the process number : \n";
    cout << "\n1.search   \t2.insert    \t3.append   \t4.delete-index   \n5.Enlarge    \t6.REFILL   \n";
    int pNum;
    int item;
    cin >> pNum;
    switch (pNum)
    {
    case 1:
        cout << "Enter the num to search : \n ";
        cin >> item;
        arr1.Search(item);
        break;
    case 2:
        int index;
        cout << "Enter index to add new item : \n";
        cin >> index;
        cout << "Enter the new item : \n";
        cin >> item;
        arr1.insert(index, item);
        break;
    case 3:
        cout << "\nEnter item to append: ";
        cin >> item;
        arr1.append(item);
        break;
    case 4:
        cout << "\nEnter index to delete: ";
        cin >> item;
        arr1.Delete(item);
        break;
    case 5:
        cout << "\nEnter the new size : ";
        cin >> item;
        arr1.Enlarge(item);
        break;
    case 6:
        arr1.Fill();
        break;
    default:
        break;
    }

    arr1.display();

    return 0;
}
