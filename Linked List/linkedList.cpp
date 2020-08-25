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

void display(ListNode* head2) {

	// the head inside this function is copy of the head
	// inside the main funciton

	// ListNode* temp = head;

	while (head2 != NULL) {
		cout << head2->val << " -> ";
		head2 = head2->next;
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
	ListNode* temp = head;

	while (temp != NULL) {
		if (temp->val == key) {
			return true;
		}
		temp = temp->next;
	}

	return false;
}

void deleteAtAnyIndex(ListNode* &head, int pos) {
	if (head == NULL or head->next == NULL or pos <= 1) {
		deleteAtHead(head);
		return;
	}

	if (pos >= size(head)) {
		deleteAtTail(head);
		return;
	}

	int jump = 1;
	ListNode* temp = head;

	while (jump < pos - 1) {
		jump++;
		temp = temp->next;
	}

	ListNode* toBeDeleted = temp->next;
	temp->next = temp->next->next;
	delete toBeDeleted;
}

ListNode* midPoint(ListNode* head) {

	ListNode* slow = head;
	ListNode * fast = head;

	// ODD.            // EVEN
	while (fast->next != NULL and fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

ListNode* reverseRecursive(ListNode* head) {
	// BASE CASE
	if (head == NULL or head->next == NULL) {
		return head;
	}

	ListNode* newHead = reverseRecursive(head->next);

	// my Work
	ListNode* curr = head;
	curr->next->next = curr;
	curr->next = NULL;
	return newHead;
}

ListNode* reverseIterative(ListNode* head) {

	ListNode* prev = NULL;
	ListNode* curr = head;

	while (curr != NULL) {
		ListNode* n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
	}

	return prev;
}

ListNode* merge(ListNode* a, ListNode* b) {
	//BASE CASE
	if (a == NULL) {
		return b;
	}

	if (b == NULL) {
		return a;
	}

	ListNode* newHead;

	if (a->val < b->val) {
		newHead = a;
		newHead->next = merge(a->next, b);
	} else {
		newHead = b;
		newHead->next = merge(a, b->next);
	}

	return newHead;
}

// Submit this on leetcode 148 (Sort List)
ListNode* mergeSort(ListNode* head) {
	// HOMEWORK
	return NULL;
}

// try submitting on leetcode 25 (slightly different)
ListNode* kReverse(ListNode* head, int k) {
	if (head == NULL or head->next == NULL) {
		return head;
	}

	ListNode* prev = NULL;
	ListNode* curr = head;

	int steps = 1;

	while (steps <= k and curr != NULL) {
		ListNode* n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
		steps++;
	}

	head->next = kReverse(curr, k);

	ListNode* newHead = prev;
	return newHead;
}

// 141. Linked List Cycle (HomeWork)

int main() {

	// ListNode* head = NULL;

	// // insertAtTail(head, 789);
	// // display(head);

	// insertAtHead(head, 2);
	// insertAtHead(head, 4);
	// insertAtHead(head, 6);
	// insertAtHead(head, 9);

	// // // cout << "First Traversal" << endl;
	// display(head);

	// ListNode* newHead = reverseRecursive(head);

	// display(newHead);

	// ListNode* againHead = reverseIterative(newHead);

	// display(againHead);

	// deleteAtHead(head);

	// deleteAtTail(head);

	// display(head);

	// insertAtAnyIndex(head, 987, 3);

	// display(head);

	// ListNode* mid = midPoint(head);
	// cout << mid->val << endl;

	// deleteAtAnyIndex(head, 3);

	// display(head);

	// mid = midPoint(head);
	// cout << mid->val << endl;

	// // cout << size(head) << endl;

	// insertAtTail(head, 23);
	// insertAtTail(head, 45);

	// display(head);

	// cout << "Second Traversal" << endl;
	// display(head);

	// ************ MERGE 2 SORTED LIST ***************

	// ListNode* head1 = NULL;

	// insertAtTail(head1, 1);
	// insertAtTail(head1, 3);
	// insertAtTail(head1, 5);
	// insertAtTail(head1, 8);
	// insertAtTail(head1, 9);

	// ListNode* head2 = NULL;

	// insertAtTail(head2, 2);
	// insertAtTail(head2, 4);
	// insertAtTail(head2, 6);
	// insertAtTail(head2, 7);

	// cout << "First Linked List ******************" << endl;
	// display(head1);

	// cout << "Second Linked List ******************" << endl;
	// display(head2);

	// ListNode* mergedList = merge(head1, head2);

	// cout << "Merged Linked List ******************" << endl;
	// display(mergedList);

	// ************ MERGE SORT ***************

	// ListNode* head = NULL;

	// insertAtTail(head, 1);
	// insertAtTail(head, 6);
	// insertAtTail(head, 5);
	// insertAtTail(head, 3);
	// insertAtTail(head, 4);
	// insertAtTail(head, 2);

	// cout << "Unsorted Linked List *****************" << endl;
	// display(head);

	// head = mergeSort(head);

	// cout << "Sorted Linked List ***************" << endl;
	// display(head);

	//********** K REVERSE **************

	ListNode* head = NULL;

	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	insertAtTail(head, 6);
	insertAtTail(head, 7);
	insertAtTail(head, 8);
	// insertAtTail(head, 9);

	cout << "Before ***************" << endl;
	display(head);

	head = kReverse(head, 3);

	cout << "After ******************" << endl;
	display(head);

	// string str = "Pransjdfbjndknfwndkldjnfkwndkwndbwav";

	// cout << sizeof(str) << endl; // 24
	// cout << str.length() << endl; // 6
	// cout << str.size() << endl; // 6

	return 0;
}
