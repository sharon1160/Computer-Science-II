
//////////////////////////////////////////////////////////////////////////////////////////

//**********************************************************
// Author: D.S. Malik
//
// This program tests the various operations on an ordered
// linked list.
//**********************************************************
#include <iostream>
#include "orderedLinkedList.h"

using namespace std;

int main()
{
    orderedLinkedList<int> list1, list2;
    int num; //Line 6
    cout << "Enter numbers ending "<< "with -999." << endl;//se pide que ingrese una
    cin >> num; //Line 8                                //lista de numeros que termine en -999
    while (num != -999) //Line 9
    { //
        list1.insert(num); //se va insertando numeros diferentes a -999
        cin >> num;
    } //
    cout << endl; //Line 14
    cout << "list1: "; //Line 15
    list1.print(); //Line 16
    cout << endl; //Line 17
    list2 = list1; //probar el operador de asignación
    cout << "list2: "; //Line 19
    list2.print(); //Line 20
    cout << endl; //Line 21
    cout << "Enter the number to be "<< "deleted: "; //Line 22
    cin >> num; //Line 23
    cout << endl; //Line 24
    list2.deleteNode(num); //Line 25
    cout << "After deleting "<< num << ", list2: " << endl; //Line 26
    list2.print(); //Line 27
    cout << endl; //Line 28
    return 0; //Line 29
}

