class KthLargest
{
public:
  priority_queue<int, vector<int>, greater<int>> minheap;
  int size;
  KthLargest(int k, vector<int> &nums)
  {
    size = k;

    for (int x : nums)
      add(x);
  }

  int add(int val)
  {

    if (minheap.size() < size)
      minheap.push(val);
    else
    {
      if (val > minheap.top())
      {
        minheap.pop();
        minheap.push(val);
      }
    }
    return minheap.top();
  }
};