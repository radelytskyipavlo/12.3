#include <iostream>
#include <Windows.h>
using namespace std;
typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};
void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem; // 1
    tmp->info = value; // 2
    tmp->next = NULL; // 3
    if (last != NULL)
        last->next = tmp; // 4
    tmp->prev = last; // 5
    last = tmp; // 6
    if (first == NULL)
        first = tmp; // 7
}
Info dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->next; // 1
    Info value = first->info; // 2
    delete first; // 3
    first = tmp; // 4
    if (first == NULL)
        last = NULL; // 5
    else
        first->prev = NULL; // 6
    return value;
}
void D(Elem* first, Elem* last)
{
    int count = 1;
    Elem* current = first;
    while (current != NULL && current->next != NULL)
    {
        if (count % 2 == 1) 
        {
            Info tmp = current->info;
            current->info = current->next->info;
            current->next->info = tmp;
        }
        current = current->next->next; 
        count += 2;
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    Elem* first = NULL,
        * last = NULL;

    cout << endl;
    for (int i = 0; i < 20; i++)
        enqueue(first, last, i);
    D(first, last);
    while (first != NULL)
    {
        cout << dequeue(first, last) << ' ';
    }


    cout << endl;

}

