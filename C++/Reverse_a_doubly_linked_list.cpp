#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <cmath>


using namespace std;
//https://www.hackerrank.com/challenges/three-month-preparation-kit-reverse-a-linked-list/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=three-month-preparation-kit&playlist_slugs%5B%5D=three-month-week-seven
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

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist)
{

    DoublyLinkedListNode* pre = NULL;
    DoublyLinkedListNode* head = llist;

    while(head!=NULL)
    {
        DoublyLinkedListNode* temp = head->next;
        head->next = pre;
        head->prev = temp;
        pre = head;
        head = head->prev;
        
    }
    llist = pre;
    return llist;

}
DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {

    DoublyLinkedListNode* pre = NULL;
    DoublyLinkedListNode* head = llist;

    while(head!=NULL)
    {
        DoublyLinkedListNode* temp = head->next;
        head->next = pre;
        head->prev = temp;
        pre = head;
        head = head->prev;
        
    }
    llist = pre;
    return llist;

}
int main(int argc, char const *argv[])
{
	//".......","...O.O.","....O..","..O....","OO...OO","OO.O..."
	vector<int> r = {100,90,90,80,75,70};
	vector<int> p = {50,65,77,90,102};
	vector<int> ans;
	string s = "aaabbbcc";
    int n;
	ans = reverse(r,p);
	print(ans);
	
	return 0;
}