#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
private:
    vector<int> heap;

    void heapify_down(int index)
    {
        while (index < heap.size())
        {
            int left = 2 * index + 1, right = 2 * index + 2, smallest = index;
            if (left < heap.size() and heap[smallest] > heap[left])
                smallest = left;
            if (right < heap.size() and heap[smallest] > heap[right])
                smallest = right;
            if (smallest != index)
            {
                swap(heap[smallest], heap[index]);
                index = smallest;
            }
            else
                break;
        }
    }

    void heapify_up(int index)
    {
        while (index != 0 and heap[(index - 1) / 2] > heap[index])
        {
            swap(heap[(index - 1) / 2], heap[index]);
            index = (index - 1) / 2;
        }
    }

public:
    MinHeap() {}
    MinHeap(vector<int> arr) : heap(arr)
    {
        heapify();
    }

    void heapify()
    {
        for (int i = (heap.size() - 1) / 2; i >= 0; i--)
            heapify_down(i);
    }

    void push(int num)
    {
        heap.push_back(num);
        heapify_up(heap.size() - 1);
    }

    void pop()
    {
        if (empty())
            throw runtime_error("Heap Empty. No elements to pop");
        swap(heap.back(), heap.front());
        heap.pop_back();
        heapify_down(0);
    }

    int top()
    {
        if (empty())
            throw runtime_error("Heap Empty. No elements to peek");
        return heap.front();
    }

    bool empty()
    {
        return heap.size() == 0;
    }
    void print()
    {
        for(auto i:heap)
        cout<<i<<" ";
    }
};

int main()
{
    vector<int> arr = {3, 5, 1, 7}; // 0,1,2,2,3,3,5,7,9
    MinHeap  pq(arr);
    pq.print();
    while (not pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return (0);
}

