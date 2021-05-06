/*
Description: This program creates a calendar with reminders
Usage: make --> ./list
        (make clean to clear .o files)
*/

#include "linkedlist.h"

using namespace std;

int main () {
    int selection;
    int input;

    // Using integer here (Since templated, can be any data type, but have to change everything to that type)
    LinkedList<int> list;

    cout << "---------- LINKED LIST ----------" << endl;

    do {
        // Menu
        cout << "Adding elements:" << endl;
        cout << "1. Add element to front" << endl;
        cout << "2. Add element to end" << endl;
        cout << "3. Add element at index" << endl;

        cout << "\nRemoving elements: " << endl;
        cout << "4. Remove element from front" << endl;
        cout << "5. Remove element from end" << endl;
        cout << "6. Remove first of element" << endl;
        cout << "7. Remove all of element" << endl;

        cout << "\nFinding elements: " << endl;
        cout << "8. Check if element exists" << endl;
        cout << "9. Find and return node pointer of data" << endl;
        cout << "10. Find index of value" << endl;

        cout << "\nRetrieving elements: " << endl;
        cout << "11. Retrieve front data" << endl;
        cout << "12. Retrieve end data" << endl;
        cout << "13. Retrieve at index" << endl;

        cout << "\nOther: " << endl;
        cout << "14. Print list" << endl;
        cout << "15. Empty list" << endl;
        cout << "16. Size of list" << endl;
        cout << "17. Generate pre-made linked list" << endl;
        cout << "\n0. Exit" << endl;
        cout << ">> ";
        cin >> selection;

        switch (selection) {
            // 1. Add element to front
            case 1:
                cout << "Enter number: ";
                cin >> input;
                list.AddToFront(input);
                cout << endl;
                break;
            // 2. Add element to end
            case 2:
                cout << "Enter number: ";
                cin >> input;
                list.AddToEnd(input);
                cout << endl;
                break;
            // 3. Add element at index
            case 3: {
                cout << "Enter index: ";
                cin >> input;
                int index = input;
                cout << "Enter number: ";
                cin >> input;
                int num = input;
                list.AddAtIndex(num, index);
                cout << endl;
                break;
            }
            // 4. Remove element from front
            case 4:
                list.RemoveFromFront();
                cout << endl;
                break;
            // 5. Remove element from end
            case 5:
                list.RemoveFromEnd();
                cout << endl;
                break;
            // 6. Remove first of element
            case 6:
                cout << "Enter number to delete: ";
                cin >> input;
                cout << "First element removed" << endl;
                list.RemoveTheFirst(input);
                cout << endl;
                break;
            // 7. Remove all of element
            case 7:
                cout << "Enter number to delete: ";
                cin >> input;
                list.RemoveAllOf(input);
                cout << endl;
                break;
            // 8. Check if element exists
            case 8:
                cout << "Enter number to find: ";
                cin >> input;
                cout << "Exists? " << list.ElementExists(input) << endl;
                cout << endl;
                break;
            // 9. Find and return node pointer of data
            case 9:
                cout << "Enter data: ";
                cin >> input;
                cout << "Data: " << list.Find(input)->getData() << endl;
                cout << endl;
                break;
            // 10. Find index of value
            case 10:
                cout << "Enter number to find: ";
                cin >> input;
                cout << "Index: " << list.IndexOf(input) << endl;
                cout << endl;
                break;
            // 11. Retrieve front data
            case 11:
                cout << "Data: " << list.RetrieveFront() << endl;
                cout << endl;
                break;
            // 12. Retrieve end data
            case 12:
                cout << "Data: " << list.RetrieveEnd() << endl;
                cout << endl;
                break;
            // 13. Retrieve at index
            case 13:
                cout << "Enter index: ";
                cin >> input;
                cout << "Data: " << list.Retrieve(input) << endl;
                cout << endl;
                break;
            // 14. Print list
            case 14:
                list.PrintList();
                cout << endl;
                break;
            // 15. Empty list
            case 15:
                list.Empty();
                cout << endl;
                break;
            // 16. Size of list
            case 16:
                cout << "Size: " << list.Length() << endl;
                cout << endl;
                break;
            // 17. Generate pre-made linked list
            case 17:
                list.AddToEnd(1);
                list.AddToEnd(2);
                list.AddToEnd(3);
                list.AddToEnd(2);
                list.AddToEnd(4);
                list.AddToEnd(2);
                list.AddToEnd(5);
                list.AddToEnd(2);
                list.AddToEnd(6);
                list.AddToEnd(2);
                cout << endl;
                break;
            // 0. Exit
            case 0:
                selection = 0;
                break;
        }
    } while (selection != 0);
}