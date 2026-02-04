#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int heap[MAX];
int heapSize = 0;

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
  {
    smallest = left;
  }

  if (right < heapSize && heap[smallest] > heap[right])
  {
    smallest = right;
  }

  if (smallest != i)
  {
    swap(heap[smallest], heap[i]);
    heapifydown(smallest);
  }
}

void insert(int val)
{
  heap[heapSize] = val;
  heapSize++;
  heapifyUp(heapSize - 1);
}

void deletelement()
{
  heap[0] = heap[heapSize - 1];
  heapSize--;
  heapifydown(0);
}

int search(int key)
{
  for (int i = 0; i < heapSize; i++)
  {
    if (heap[i] == key)
      return i;
  }
  return -1;
}

void deleteValue(int key)
{
  int index = search(key);
  if (index == -1)
    return;

  heap[index] = heap[heapSize - 1];
  heapSize--;

  heapifydown(index);
  heapifyUp(index);
}

int main()
{

  insert(2);
  insert(1);
  insert(0);
  insert(5);
  insert(3);

  deletelement();
  deleteValue(3); // delete a specific value

  for (int i = 0; i < heapSize; i++)
    cout << heap[i] << " ";

  return 0;
}
