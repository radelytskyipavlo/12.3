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
    if (first == NULL)
    {
        Elem* tmp = new Elem;
        tmp->info = value;
        tmp->next = NULL;
        tmp->prev = NULL;
        first = tmp;
        last = tmp;
    }
    else
    {
        Elem* tmp = new Elem;
        tmp->info = value;
        tmp->next = NULL;
        tmp->prev = last;
        last->next = tmp;
        last = tmp;
    }
}

Info dequeue(Elem*& first, Elem*& last)
{
    if (first == NULL)
    {
        cerr << "Queue is empty!" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        Info value = first->info;
        Elem* tmp = first->next;
        delete first;
        first = tmp;
        if (first == NULL)
            last = NULL;
        else
            first->prev = NULL;
        return value;
    }
}

void D(Elem* current, int count)
{
    if (current != NULL && current->next != NULL)
    {
        if (count % 2 == 1)
        {
            Info tmp = current->info;
            current->info = current->next->info;
            current->next->info = tmp;
        }
        D(current->next->next, count + 2);
    }
}

void recursive_enqueue(Elem*& first, Elem*& last, Info value, Info current)
{
    if (current == value)
        return;
    enqueue(first, last, current);
    recursive_enqueue(first, last, value, current + 1);
}

void recursive_dequeue(Elem*& first, Elem*& last)
{
    if (first != NULL)
    {
        cout << dequeue(first, last) << ' ';
        recursive_dequeue(first, last);
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    Elem* first = NULL,
        * last = NULL;

    recursive_enqueue(first, last, 20, 0);
    D(first, 1);
    recursive_dequeue(first, last);

    cout << endl;

    return 0;
}
