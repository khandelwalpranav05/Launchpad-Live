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

void insertAtAnyIndex(ListNode* &head, int data, int pos) {
	// EDGE CASES
	if (pos <= 1 or head == NULL) {
		insertAtHead(head, data);
		return;
	}

	if (pos >= size(head)) {
		insertAtTail(head, data);
		return;
	}

	ListNode* temp = head;

	int jump = 1;
	while (jump < pos - 1) {
		temp = temp->next;
		jump++;
	}

	ListNode* n = new ListNode(data);

	n->next = temp->next;
	temp->next = n;
}

void deleteAtHead(ListNode* &head) {
	//EDGE CASE
	if (head == NULL) {
		return;
	}

	ListNode* toBeDeleted = head;
	head = head->next;
	delete toBeDeleted;
}

void deleteAtTail(ListNode* &head) {
	if (head == NULL) {
		return;
	}

	if (head->next == NULL) { // there is only 1 node in my linked list
		deleteAtHead(head);
		return;
	}

	ListNode* temp = head;

	while (temp->next->next != NULL) {
		temp = temp->next;
	}

	ListNode* toBeDeleted = temp->next;
	temp->next = NULL;
	delete toBeDeleted;
}

bool search(ListNode* head, int key) {
	// TODO
	//HOME WORK
	return true;
}

void deleteAtAnyIndex(ListNode* &head, int pos) {
	// TODO HOME WORK
}

ListNode* midPoint(ListNode* head) {
	// TODO
	// HOMEWORK

	return NULL;
}

int main() {

	ListNode* head = NULL;

	// insertAtTail(head, 789);

	// display(head);

	insertAtHead(head, 2);
	insertAtHead(head, 4);
	insertAtHead(head, 6);
	insertAtHead(head, 9);

	// // cout << "First Traversal" << endl;
	display(head);

	// deleteAtHead(head);

	deleteAtTail(head);

	display(head);

	// insertAtAnyIndex(head, 987, 3);

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
