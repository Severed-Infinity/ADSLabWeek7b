#ifndef STACK_OF_DOUBLES_H
#define STACK_OF_DOUBLES_H

#include <ostream>
#include "ListOfDoubles.h"

class StackOfDoubles {
public:
	StackOfDoubles();
	//StackOfDoubles(ListOfDoubles data);
	StackOfDoubles(const StackOfDoubles &cStack);
	~StackOfDoubles();
	void push(const double &item);
	void pop();
	const double top();
	friend std::ostream& operator<<(std::ostream& ostr, const StackOfDoubles &stack);
	const StackOfDoubles& operator=(const StackOfDoubles &cStack);

private:
	ListOfDoubles data;
	int currentItemPosition;
};

StackOfDoubles::StackOfDoubles() {
	data = ListOfDoubles();
	currentItemPosition = 0;
}

StackOfDoubles::StackOfDoubles(const StackOfDoubles &cStack){
	data = ListOfDoubles(cStack.data);
	currentItemPosition = cStack.currentItemPosition;
}

StackOfDoubles::~StackOfDoubles() {
	//data = nullptr;
	//delete[] data;
}

void StackOfDoubles::push(const double &item){
	data.insert(item);
	currentItemPosition++;
}

void StackOfDoubles::pop(){
	data.deleteMostRecent();
	--currentItemPosition;
}

const double StackOfDoubles::top(){
	return data.getTail();
}

std::ostream& operator<<(std::ostream& ostr, const StackOfDoubles &stack){
	ostr << stack.data << std::endl;
	return ostr;
}

const StackOfDoubles& StackOfDoubles::operator=(const StackOfDoubles &cStack){
	if (this != &cStack){
		//delete[] data;
		data = cStack.data;
		currentItemPosition = cStack.currentItemPosition;
	}
	return *this;
}
#endif