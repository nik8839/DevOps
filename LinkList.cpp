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

    // Mayank Kumar Shah(21bds037)
    void addToEnd(int value){
        // Create a new node
        Node* newNode = new Node(value);
        // If the list is empty, make the new node the head
        if (head == nullptr) {
            head = newNode;
            return;
        }
        // Otherwise, traverse to the last node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // Add the new node at the end
        temp->next = newNode;
    }

    // Function to add a node in the middle of the linked list
    // Chinmay (21bds014)
    void addToMiddle(int value, int position)
    {

        Node *node = new Node(value);
        Node *prev = nullptr;
        Node *curr = head;
        if (position == 0)
        {
            node->next = head;
            head = node;
        }
        while (node != nullptr && position != 0)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = node;
        node->next = curr;
        return;
    }

    // Function to delete the last node of the linked list
    // Milind (21bds038)
    void deleteFromEnd()
    {
        if (head == nullptr) { // If the list is empty
            cout << "The list is empty, nothing to delete.\n";
            return;
        }
        
        if (head->next == nullptr) { // If there is only one node
            delete head; // Delete the head
            head = nullptr; // Set head to null
            cout << "Last node deleted. The list is now empty.\n";
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        // Delete the last node
        delete current->next;
        current->next = nullptr; // Set the second last node's next to null
        cout << "Last node deleted.\n";
    }

    // Function to delete a node from the middle of the linked list
    // Rahul Singh (21bds054)
    void deleteFromMiddle(int position);

    // Function to reverse the linked list
    // Saksham (21bds058)
    void reverse() {

        Node* current = head; // Pointer to the current node
        Node* prev = nullptr; // Pointer to the previous node
        Node* next = nullptr; // Pointer to the next node

        while (current != nullptr) {
            next = current->next; // Store the next node
            current->next = prev; // Point the current node to the previous node
            prev = current; // Move the previous node to the current node
            current = next; // Move the current node to the next node
        }

        head = prev; // Update the head of the list

        // Display the reversed linked list
        cout << "Reversed Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to delete all even nodes from the linked list
    // Nikhil (21bds044)
<<<<<<< HEAD
    void deleteAllEvenNodes();
=======
    void deleteAllEvenNodes()
    {
                while (head != nullptr && head->data % 2 == 0) {
            Node* temp = head;
            head = head->next; 
            delete temp; 
        }

        
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->data % 2 == 0) {
                
                Node* temp = current->next;
                current->next = current->next->next; 
                delete temp; 
            } else {
                
                current = current->next;
            }
        }
    }
>>>>>>> Nikhil_21bds044

    // Function to delete all odd nodes from the linked list
    // Kartik (21bds025)
    void deleteAllOddNodes(){
        if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        int position = 1;

    // If the head is at an odd position, delete it
        while (temp != nullptr && position % 2 != 0) {
            head = temp->next; // Update head to the next node
            delete temp;       // Delete the current head
            temp = head;       // Move to the next node
            position++;        // Increment position
        }

    // Traverse the rest of the list and delete odd-positioned nodes
        while (temp != nullptr && temp->next != nullptr) {
            if (position % 2 != 0) {
                Node* oddNode = temp->next;
                temp->next = oddNode->next; // Bypass the odd-positioned node
                delete oddNode;             // Delete the odd-positioned node
            } else {
                temp = temp->next;          // Move to the next node
            }
            position++;                      // Increment position
        }

        cout << "All odd-positioned nodes have been deleted.\n";
    }

    // Function to display the linked list
    void display();
};

// Menu function
void menu()
{

    // Pranjal Shinde (21bds062)

    LinkedList list;
    int choice, value, position;

    do
    {
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

        switch (choice)
        {
        case 1:
            cout << "Enter value to add to end: ";
            cin >> value;
            list.addToEnd(value); // Add node to end
            break;
        case 2:
            cout << "Enter value and position to add in middle: ";
            cin >> value >> position;
            list.addToMiddle(value, position); // Add node to middle
            break;
        case 3:
            list.deleteFromEnd(); // Delete from end
            break;
        case 4:
            cout << "Enter position to delete from middle: ";
            cin >> position;
            list.deleteFromMiddle(position); // Delete from middle
            break;
        case 5:
            list.reverse(); // Reverse the linked list
            break;
        case 6:
            list.deleteAllEvenNodes(); // Delete all even nodes
            break;
        case 7:
            list.deleteAllOddNodes(); // Delete all odd nodes
            break;
        case 8:
            list.display(); // Display the linked list
            break;
        case 0:
            cout << "Exiting...\n"; // Exit option
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);
}

// Main function
int main()
{
    menu();
    return 0;
}