#include <iostream>
#include <vector>
using namespace std;
// 1. parent(i): Function to return the parent node of node i
// 2. leftChild(i): Function to return index of the left child of node i
// 3. rightChild(i): Function to return index of the right child of node i
// 4. shiftUp(int i): Function to shift up the node in order to maintain the
// heap property
// 5. shiftDown(int i): Function to shift down the node in order to maintain the
// heap property.
// int s=-1, current index value of the array H[].
int H[10009];
int s = -1;
int parent(int i)
{
	return (i - 1) / 2;
}
int leftChild(int i)
{
	return ((2 * i) + 1);
}
int rightChild(int i)
{
	return ((2 * i) + 2);
}
void shiftUp(int i)
{
	while (i > 0 && H[parent(i)] < H[i])
	{
		swap(H[parent(i)], H[i]);
		i = parent(i);
	}
}
void shiftDown(int i)
{
	int maxIndex = i;
	int l = leftChild(i);

	if (l <= s && H[l] > H[maxIndex])
	{
		maxIndex = l;
	}
	int r = rightChild(i);

	if (r <= s && H[r] > H[maxIndex])
	{
		maxIndex = r;
	}
	if (i != maxIndex)
	{
		swap(H[i], H[maxIndex]);
		shiftDown(maxIndex);
	}
}
void insert(int p)
{
	s = s + 1;
	H[s] = p;
	shiftUp(s);
}

class Solution
{
public:
	int extractMax()
	{
		int temp = H[0];
		int last = H[s];
		s--;
		H[0] = last;
		shiftDown(0);
		return temp;
	}
};
int main()
{
	int siz, ele;
	Solution s;
	cout<<"Enter heap size: ";
	cin>>siz;
	cout<<"Enter heap elements: ";
	for(int i = 0;i<siz;i++){
		cin>>ele;
		insert(ele);
	}
	cout<<"Node with maximum proiority: "<<s.extractMax()<<endl;
	cout<<"Priority queue after extracting maximum: ";
	for(int i = 0;i<siz-1;i++){
		cout<<s.extractMax()<<" ";
	}
	cout<<endl;
}