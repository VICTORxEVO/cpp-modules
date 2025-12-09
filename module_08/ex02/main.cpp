#include <iostream>
#include <list>
#include "MutantStack.hpp"

// Test from the PDF
void	testPDF(void)
{
	std::cout << "=== PDF Test (MutantStack) ===" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "Elements: ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	std::stack<int> s(mstack);
	std::cout << std::endl;
}

// Same test with std::list for comparison
void	testList(void)
{
	std::cout << "=== PDF Test (std::list) ===" << std::endl;

	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Top: " << lst.back() << std::endl;

	lst.pop_back();

	std::cout << "Size: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();

	++it;
	--it;

	std::cout << "Elements: ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

// Test reverse iterators
void	testReverseIterator(void)
{
	std::cout << "=== Reverse Iterator Test ===" << std::endl;

	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);

	std::cout << "Forward:  ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Reverse:  ";
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
	{
		std::cout << *rit << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

// Test const iterators
void	testConstIterator(void)
{
	std::cout << "=== Const Iterator Test ===" << std::endl;

	MutantStack<int> mstack;
	mstack.push(10);
	mstack.push(20);
	mstack.push(30);

	const MutantStack<int> &constRef = mstack;

	std::cout << "Const iteration: ";
	for (MutantStack<int>::const_iterator it = constRef.begin(); it != constRef.end(); ++it)
	{
		std::cout << *it << " ";
		// *it = 100;  // This would cause a compile error (const!)
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

// Test copy constructor and assignment
void	testCopyAndAssignment(void)
{
	std::cout << "=== Copy and Assignment Test ===" << std::endl;

	MutantStack<int> original;
	original.push(1);
	original.push(2);
	original.push(3);

	// Test copy constructor
	MutantStack<int> copy(original);
	std::cout << "Copy elements: ";
	for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Test assignment operator
	MutantStack<int> assigned;
	assigned.push(100);
	assigned = original;
	std::cout << "Assigned elements: ";
	for (MutantStack<int>::iterator it = assigned.begin(); it != assigned.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Verify deep copy (modifying original doesn't affect copies)
	original.push(999);
	std::cout << "Original after push(999): ";
	for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Copy (unchanged): ";
	for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

// Test with different types
void	testDifferentTypes(void)
{
	std::cout << "=== Different Types Test ===" << std::endl;

	// String stack
	MutantStack<std::string> strStack;
	strStack.push("Hello");
	strStack.push("World");
	strStack.push("!");

	std::cout << "String stack: ";
	for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Float stack
	MutantStack<float> floatStack;
	floatStack.push(1.1f);
	floatStack.push(2.2f);
	floatStack.push(3.3f);

	std::cout << "Float stack: ";
	for (MutantStack<float>::iterator it = floatStack.begin(); it != floatStack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

// Test modifying elements through iterator
void	testModifyThroughIterator(void)
{
	std::cout << "=== Modify Through Iterator Test ===" << std::endl;

	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	std::cout << "Before: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Double each element
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		*it *= 2;
	}

	std::cout << "After (*= 2): ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

// Test stack operations still work
void	testStackOperations(void)
{
	std::cout << "=== Stack Operations Test ===" << std::endl;

	MutantStack<int> mstack;

	std::cout << "Empty?  " << (mstack.empty() ? "Yes" : "No") << std::endl;

	mstack.push(42);
	mstack.push(21);
	mstack.push(84);

	std::cout << "Empty? " << (mstack.empty() ?  "Yes" : "No") << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "After pop - Top: " << mstack.top() << std::endl;
	std::cout << "After pop - Size: " << mstack.size() << std::endl;

	std::cout << std::endl;
}

int	main(void)
{
	testPDF();
	testList();
	testReverseIterator();
	testConstIterator();
	testCopyAndAssignment();
	testDifferentTypes();
	testModifyThroughIterator();
	testStackOperations();

	return (0);
}