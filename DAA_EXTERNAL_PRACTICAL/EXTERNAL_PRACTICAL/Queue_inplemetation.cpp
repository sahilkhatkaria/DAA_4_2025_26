#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

void init(Queue &q) {
    q.front = q.rear = NULL;
}

void push(Queue &q, int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;

    if (q.rear == NULL) {
        q.front = q.rear = temp;
        return;
    }

    q.rear->next = temp;
    q.rear = temp;
}

int pop(Queue &q) {
    if (q.front == NULL) {
        cout << "Queue is empty\n";
        return -1;
    }

    Node* temp = q.front;
    int val = temp->data;

    q.front = q.front->next;

    if (q.front == NULL) {
        q.rear = NULL;
    }

    delete temp;
    return val;
}

int top(Queue &q) {
    if (q.front == NULL) {
        cout << "Queue is empty\n";
        return -1;
    }
    return q.front->data;
}


bool isEmpty(Queue &q) {
    return q.front == NULL;
}


int main() {

    return 0;
}