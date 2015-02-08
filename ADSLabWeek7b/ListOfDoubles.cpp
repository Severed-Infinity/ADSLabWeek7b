#include <iostream>
#include "ListOfDoubles.h"
using namespace std;

ListOfDoubles::ListOfDoubles()
{
}

ListOfDoubles::~ListOfDoubles()
{
	DoubleListNode *temp = head;
	while (temp != nullptr){
		head = head->next;
		delete temp;
		temp = head;
	}
	delete temp;
}

ListOfDoubles::ListOfDoubles(const ListOfDoubles &cList){
	if (cList.head == nullptr){
		return;
	}
	head = new DoubleListNode(cList.head->data);
	DoubleListNode* iter = head;
	DoubleListNode* iterCopy = cList.head;

	while (iterCopy != nullptr){
		iter->next = new DoubleListNode(iterCopy->data);
		iterCopy = iterCopy->next;
		iter = iter->next;
	}
}

void ListOfDoubles::insert(double newDouble){
	DoubleListNode *newNode = new DoubleListNode(newDouble);
	newNode->next = NULL;
	if (head == NULL){
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}

}

void ListOfDoubles::displayList(){
	cout << "Printing list of Doubles...." << endl;
	DoubleListNode* iter = head;
	if (iter != NULL){
		while (iter != tail) {
			cout << iter->data << endl;
			iter = iter->next;
		}
		cout << iter->data << endl << endl;
	}
}

double ListOfDoubles::deleteMostRecent(){
	double deletedDouble = 0.0;

	if (head == NULL)
		return deletedDouble;
	if (head->next == NULL) {
		deletedDouble = head->data;
		delete head;
		head = NULL;
		tail = NULL;
		return deletedDouble;
	}
	DoubleListNode* leading = head;
	DoubleListNode* trailing = NULL;

	while (leading->next != NULL){
		trailing = leading;
		leading = leading->next;
	}
	deletedDouble = leading->data;
	leading = NULL;
	delete leading;
	tail = trailing;
	tail->next = NULL;

	return deletedDouble;
}

double ListOfDoubles::deleteDouble(int position){
	int count = 0;
	double deletedDouble = 0.0;
	DoubleListNode* previous = NULL;
	DoubleListNode* current = head;

	while (++count != position){
		previous = current;
		if (current == NULL)
			return deletedDouble;
		current = current->next;
	}
	if (current == head){
		deletedDouble = current->data;
		head = current->next;
		delete current;
		return deletedDouble;
	}
	if (current == tail){
		deletedDouble = current->data;
		tail = previous;
		tail->next = NULL;
		current = NULL;
		delete current;
		return deletedDouble;
	}

	deletedDouble = current->data;
	previous->next = current->next;
	current = NULL;
	delete current;
	return deletedDouble;
}

double ListOfDoubles::getTail(){
	return tail->data;
}

std::ostream& operator<<(std::ostream &ostr, const ListOfDoubles &pList){
	ListOfDoubles::DoubleListNode* iter = pList.head;
	while (iter != nullptr){
		ostr << iter->data << "\t";
		iter = iter->next;
	}
	ostr << std::endl;
	return ostr;
}