#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;   // Data contained in the node
    Node *next; // Pointer to the next node

    Node(int value) : data(value), next(nullptr) {} // Constructor
};

// Linked List class
class LinkedList
{
private:
    Node *head; // Pointer to the head of the list

public:
    LinkedList() : head(nullptr) {} // Constructor

    // Function to add a node at the end of the linked list
    void addToEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to add a node in the middle of the linked list
    void addToMiddle(int value, int position) {
        Node *node = new Node(value);
        Node *prev = nullptr;
        Node *curr = head;
        if (position == 0) {
            node->next = head;
            head = node;
            return;
        }
        while (curr != nullptr && position != 0) {
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = node;
        node->next = curr;
    }

    // Function to delete the last node of the linked list
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "The list is empty, nothing to delete.\n";
            return;
        }
        
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Last node deleted. The list is now empty.\n";
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
        cout << "Last node deleted.\n";
    }

    // Function to delete a node from the middle of the linked list
    void deleteFromMiddle(int position) {
        if (head == nullptr) {
            cout << "The list is empty, nothing to delete.\n";
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;

        if (position == 0) {
            head = curr->next;
            delete curr;
            cout << "Node at position 0 deleted.\n";
            return;
        }

        for (int i = 0; curr != nullptr && i < position; i++) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Position out of bounds.\n";
            return;
        }

        prev->next = curr->next;
        delete curr;
        cout << "Node at position " << position << " deleted.\n";
    }

    // Function to reverse the linked list
    void reverse() {
        Node* current = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;

        cout << "Reversed Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to delete all even nodes from the linked list
    void deleteAllEvenNodes();

    // Function to delete all odd nodes from the linked list
    void deleteAllOddNodes() {
        if (head == nullptr) {
            cout << "The list is empty.\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        int position = 1;

        while (temp != nullptr && position % 2 != 0) {
            head = temp->next;
            delete temp;
            temp = head;
            position++;
        }

        while (temp != nullptr && temp->next != nullptr) {
            if (position % 2 != 0) {
                Node* oddNode = temp->next;
                temp->next = oddNode->next;
                delete oddNode;
            } else {
                temp = temp->next;
            }
            position++;
        }

        cout << "All odd-positioned nodes have been deleted.\n";
    }

    // Function to display the linked list
    void display() {
        if (head == nullptr) {
            cout << "The list is empty.\n";
            return;
        }
        cout << "Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Menu function
void menu() {
    LinkedList list;
    int choice, value, position;

    do {
        cout << "Choose an action:\n";
        cout << "1. Add to End\n";
        cout << "2. Add to Middle\n";
        cout << "3. Delete from End\n";
        cout << "4. Delete from Middle\n";
        cout << "5. Reverse Linked List\n";
        cout << "6. Delete All Even Nodes\n";
        cout << "7. Delete All Odd Nodes\n";
        cout << "8. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to add to end: ";
            cin >> value;
            list.addToEnd(value);
            break;
        case 2:
            cout << "Enter value and position to add in middle: ";
            cin >> value >> position;
            list.addToMiddle(value, position);
            break;
        case 3:
            list.deleteFromEnd();
            break;
        case 4:
            cout << "Enter position to delete from middle: ";
            cin >> position;
            list.deleteFromMiddle(position);
            break;
        case 5:
            list.reverse();
            break;
        case 6:
            list.deleteAllEvenNodes();
            break;
        case 7:
            list.deleteAllOddNodes();
            break;
        case 8:
            list.display();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);
}

// Main function
int main() {
    menu();
    return 0;
}
