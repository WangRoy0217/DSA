#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <cmath>


using namespace std;
//https://www.hackerrank.com/challenges/three-month-preparation-kit-merge-two-sorted-linked-lists/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=three-month-preparation-kit&playlist_slugs%5B%5D=three-month-week-eight
void print(vector<int> v)
{
	for(auto& i:v)
	{
		cout<<i<<",";
	}
}

struct DoublyLinkedListNode {
     int data;
      DoublyLinkedListNode* next;
      DoublyLinkedListNode* prev;
 };
 typedef DoublyLinkedListNode DoublyLinkedListNode;

struct SinglyLinkedListNode 
{
    int data;
    SinglyLinkedListNode* next;

};
typedef SinglyLinkedListNode SinglyLinkedListNode;



void printlst(SinglyLinkedListNode* lst)
{
    SinglyLinkedListNode* ptr = lst;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"->";
        ptr= ptr->next;
    }
    cout<<endl;
}
SinglyLinkedListNode* vector2lst(vector<int> &arr)
{
    int index = arr.size()-1;
    SinglyLinkedListNode* pre = NULL;
    while(index >= 0)
    {
        SinglyLinkedListNode* NewNode = new SinglyLinkedListNode();
        NewNode->next = pre;
        NewNode->data = arr[index];
        pre = NewNode;
        index--;
    }

    return pre;
}
SinglyLinkedListNode* MergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    if(head1->data < head2->data)
    {
        head1->next = MergeLists(head1->next,head2);
        return head1;
    }
    else
    {
        head2->next = MergeLists(head1, head2->next);
        return head2;
    }
}
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;

    SinglyLinkedListNode* temp1 = head1;
    SinglyLinkedListNode* temp2 = head2;
    
    if(temp1->data > temp2->data)
        swap(temp1,temp2);
    head1 = temp1;
    while(temp1!=NULL && temp2!=NULL)
    {
        SinglyLinkedListNode* pre = NULL;
        while(temp1!=NULL && temp1->data <= temp2->data)
        {
            pre = temp1;
            temp1 = temp1->next;
        }
        pre->next = temp2;
        swap(temp1, temp2);

    }
    return head1;
}


int main(int argc, char const *argv[])
{
	//".......","...O.O.","....O..","..O....","OO...OO","OO.O..."
	vector<int> head1 = {1,2,3};
	vector<int> head2 = {3,4};
	SinglyLinkedListNode* ans;
	string s = "aaabbbcc";
    
	ans = MergeLists(vector2lst(head1),vector2lst(head2));
    printlst(ans);
	//print(ans);
	
	return 0;
}