#include "StackOfDoubles.h"
#include "ListOfDoubles.h"
#include <iostream>

int main(){
	StackOfDoubles stack = StackOfDoubles();
	stack.push(12.5);
	stack.push(16.7);
	stack.push(19.9);

	stack.pop();
	stack.top();

	std::cout <<"printing the stack " << std::endl << stack;

	ListOfDoubles list = ListOfDoubles();
	list.insert(13.4);
	list.insert(17.8);
	list.insert(20.0);

	std::cout << "printing list " << list << std::endl;

	StackOfDoubles copiedStack = StackOfDoubles(stack);

	std::cout << "copied stack " << std::endl << copiedStack << std::endl;

	stack.pop();
	std::cout << "printing the stack " << std::endl << stack;
	std::cout << "copied stack " << std::endl << copiedStack << std::endl;

	std::system("pause");
	return 0;
}