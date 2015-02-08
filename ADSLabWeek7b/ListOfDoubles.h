#ifndef LIST_OF_DOUBLES_H
#define LIST_OF_DOUBLES_H

class ListOfDoubles
{
public:
	ListOfDoubles();
	ListOfDoubles(const ListOfDoubles &cList);
	~ListOfDoubles();
	void insert(double newDouble);
	void displayList();
	double getTail();
	double deleteMostRecent();
	double deleteDouble(int position);
	friend std::ostream& operator<<(std::ostream &ostr, const ListOfDoubles &pList);

private:
	class DoubleListNode {
	public:
		DoubleListNode(const double & data) :data(data) {};
		double data;
		DoubleListNode* next;
	};
private:
	DoubleListNode* head;
	DoubleListNode* tail;
};
#endif