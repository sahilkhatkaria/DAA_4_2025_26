#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int heap[MAX];
int heapSize = 0;
int K = 3;

void heapifyUp(int i)
{
    while (i > 0 && heap[(i - 1) / 2] > heap[i])
    {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}

void heapifydown(int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[smallest] > heap[left])
        smallest = left;

    if (right < heapSize && heap[smallest] > heap[right])
        smallest = right;

    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        heapifydown(smallest);
    }
}

void insert(int val)
{
    heap[heapSize] = val;
    heapSize++;
    heapifyUp(heapSize - 1);
}

void processScore(int score)
{

    if (heapSize < K)
    {
        insert(score);
    }
    else if (score > heap[0])
    {
        heap[0] = score;
        heapifydown(0);
    }

    if (heapSize < K)
        cout << -1 << "\n";
    else
        cout << heap[0] << "\n";
}

int main()
{

    processScore(10);
    processScore(20);
    processScore(5);
    processScore(15);
    processScore(25);
    processScore(8);

    return 0;
}
