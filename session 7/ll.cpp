#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert at head
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at tail
    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete a value
    void deleteValue(int val) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* prev = head;
        Node* curr = head->next;

        while (curr && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }

        if (!curr) {
            cout << "Value not found\n";
            return;
        }

        prev->next = curr->next;
        delete curr;
    }

    // Display list
    void display() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

};

int main() {
    LinkedList ll;

    ll.insertAtHead(10);
    ll.insertAtTail(30);
    ll.insertAtHead(5);

    ll.display();

    ll.deleteValue(30);
    ll.display();

    return 0;
}
