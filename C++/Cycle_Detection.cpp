#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <cmath>


using namespace std;
//https://www.hackerrank.com/challenges/three-month-preparation-kit-detect-whether-a-linked-list-contains-a-cycle/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=three-month-preparation-kit&playlist_slugs%5B%5D=three-month-week-eight
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
bool has_cycle(SinglyLinkedListNode* head) 
{
    if(head == NULL)
        return false;
    SinglyLinkedListNode* turtle = head;
    SinglyLinkedListNode* rabbit = head;
    //Note: Careful for rabbit!=NULL && rabbit->next!=NULL
    while(rabbit!=NULL && rabbit->next!=NULL)
    {
        turtle = turtle->next;
        rabbit = rabbit->next->next;
        if(turtle == rabbit)
            return true;
    }
    return false;

}


int main(int argc, char const *argv[])
{
	//".......","...O.O.","....O..","..O....","OO...OO","OO.O..."
	vector<int> head1 = {1,2,3};
	vector<int> head2 = {1,2,4};
	SinglyLinkedListNode* ans;
	string s = "aaabbbcc";
    cout<<has_cycle(vector2lst(head1))
	//print(ans);
	
	return 0;
}