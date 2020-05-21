#include <iostream>
#include <vector>

using namespace std;

class ListNode {
public:
	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

void insertAtHead(ListNode* &head, int data) {
	// new node (dynamic node)
	// cout << "Insert Function is started" << endl;
	ListNode* n = new ListNode(data);
	n->next = head;
	head = n;
	// cout << "Insert Function is ending" << endl;
}

void display(ListNode* &head) {

	// the head inside this function is copy of the head
	// inside the main funciton

	ListNode* temp = head;

	while (temp != NULL) {
		cout << temp->val << " -> ";
		temp = temp->next;
	}

	cout << "NULL" << endl;
}

int size(ListNode* head) {

	ListNode* temp = head;
	int len = 0;

	while (temp != NULL) {
		len++;
		temp = temp->next;
	}

	return len;
}

void insertAtTail(ListNode* &head, int data) {
	if (head == NULL) {
		// no node inside the linked list
		// no difference between insert at head and tail
		insertAtHead(head, data);
		return;
	}

	ListNode* n = new ListNode(data);

	ListNode* temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	// now you are at the last node of your current linked list
	temp->next = n;
}

int main() {

	ListNode* head = NULL;

	insertAtTail(head, 789);

	display(head);

	// insertAtHead(head, 2);
	// insertAtHead(head, 4);
	// insertAtHead(head, 6);
	// insertAtHead(head, 9);

	// // cout << "First Traversal" << endl;
	// display(head);

	// // cout << size(head) << endl;

	// insertAtTail(head, 23);
	// insertAtTail(head, 45);

	// display(head);

	// cout << "Second Traversal" << endl;
	// display(head);


	// string str = "Pransjdfbjndknfwndkldjnfkwndkwndbwav";

	// cout << sizeof(str) << endl; // 24
	// cout << str.length() << endl; // 6
	// cout << str.size() << endl; // 6

	return 0;
}