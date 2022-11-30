#include <bits/stdc++.h>

using namespace std;
void printvec(vector<int> &v)
  {
  	for(auto &i:v)
  		cout<<i<<",";
  	cout<<endl;
  }
class MinHeap {
public:
  // Return the min element.
	MinHeap(vector<int> &v)
	{
		data_.assign(v.begin(), v.end());
	}
  int peek() const { return data_[0]; }
 
  // Extract the min element.
  int pop() {
    // Swap the min element with the last one. O(1)
    swap(data_.back(), data_[0]);
    // Get the min element. O(1)
    int min_el = data_.back();
    // Evict the min element. O(1)
    data_.pop_back();
    // Maintain heap property. θ(logn)
    heapifyDown(0);
    return min_el;
  }
 
  // Add a new element to the heap.
  void push(int key) {
    // Add the element to the end of the array. O(1)
    data_.push_back(key);
    // Maintain heap property. θ(logn)
    heapifyUp(data_.size() - 1);
  }
 
  // Return the size of the heap.
  int size() const { return data_.size(); }
  
  void heapifyDown(int index) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    // Stop if has no left child.
    if (left >= data_.size()) return;
    // Get the min child.
    int min_child = 
      (right < data_.size() && data_[right] < data_[left]) ? right : left;
    // Stop if less or euqal to min child.
    if (data_[index] <= data_[min_child])
      return;
    // Swap with min child.
    swap(data_[index], data_[min_child]);
    // Continue heapifyDown on min_child.
    heapifyDown(min_child);
  }
  void heapifyUp(int index) {
    // Stop at root.
    if (index == 0) return;
    int parent = (index - 1) / 2;
    // Stop if greater or euqal to parent.
    if (data_[index] >= data_[parent]) return;
    // Swap with parent.
    swap(data_[index], data_[parent]);
    // Continue heapifyUp on parent.
    heapifyUp(parent);
  }
  vector<int> data_;
private:
  
 
  
 
  
};
 
int main() {
  vector<int> data{5,7,3,5,3,4,3,1};
  MinHeap heap(data);

  for(int i=(data.size()-1)/2;i>=0;i--)
  {
  	heap.heapifyDown(i);
  }
  printvec(heap.data_);
  cout<<endl;

  
  vector<int> output;
  while (heap.size())
  {
    output.push_back(heap.pop());
    printvec(heap.data_);
   }
  printvec(output);
  //assert(output == vector<int>({1,3,3,3,4,5,5,7}));
  
}
