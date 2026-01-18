#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

// Test from the PDF
void	test_subject(void)
{
	std::cout << "=== subject Test ===" << std::endl;

	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

// Test exceptions
void	testExceptions(void)
{
	std::cout << "=== Exception Tests ===" << std::endl;

	// Test: Span is full
	try
	{
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);  // Should throw
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Test: Not enough numbers (empty)
	try
	{
		Span sp(5);
		sp.shortestSpan();  // Should throw
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Test: Not enough numbers (only one)
	try
	{
		Span sp(5);
		sp.addNumber(42);
		sp.longestSpan();  // Should throw
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

// Test with 10,000 numbers
void	testLargeSpan(void)
{
	std::cout << "=== Large Span Test (10,000 numbers) ===" << std::endl;

	Span sp(10000);

	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		sp.addNumber(rand());
	}

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

// Test with 100,000 numbers
void	testVeryLargeSpan(void)
{
	std::cout << "=== Very Large Span Test (100,000 numbers) ===" << std::endl;

	Span sp(100000);

	for (int i = 0; i < 100000; i++)
	{
		sp.addNumber(i * 2);  // Even numbers: 0, 2, 4, 6, ... 
	}

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Should be 2
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Should be 199998
	std::cout << std::endl;
}

// Test addRange with vector
void	testAddRangeVector(void)
{
	std::cout << "=== Add Range Test (vector) ===" << std::endl;

	std::vector<int> numbers;
	numbers.push_back(100);
	numbers.push_back(200);
	numbers.push_back(300);
	numbers.push_back(400);
	numbers.push_back(500);

	Span sp(10);
	sp. addRange(numbers.begin(), numbers.end());

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // 100
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // 400
	std::cout << std::endl;
}

// Test addRange with list
void	testAddRangeList(void)
{
	std::cout << "=== Add Range Test (list) ===" << std::endl;

	std::list<int> numbers;
	numbers.push_back(5);
	numbers.push_back(10);
	numbers.push_back(15);
	numbers.push_back(20);

	Span sp(10);
	sp.addRange(numbers.begin(), numbers. end());

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // 5
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // 15
	std::cout << std::endl;
}

// Test addRange with array
void	testAddRangeArray(void)
{
	std::cout << "=== Add Range Test (array) ===" << std::endl;

	int arr[] = {1, 5, 10, 50, 100};
	int size = sizeof(arr) / sizeof(arr[0]);

	Span sp(10);
	sp.addRange(arr, arr + size);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

// Test copy constructor and assignment operator
void	testCopyAndAssignment(void)
{
	std::cout << "=== Copy and Assignment Test ===" << std::endl;

	Span original(5);
	original.addNumber(1);
	original.addNumber(2);
	original.addNumber(3);

	// Test copy constructor
	Span copy(original);
	std::cout << "Copy - Shortest: " << copy.shortestSpan() << std::endl;
	std::cout << "Copy - Longest: " << copy.longestSpan() << std::endl;

	// Test assignment operator
	Span assigned(10);
	assigned = original;
	std::cout << "Assigned - Shortest: " << assigned.shortestSpan() << std::endl;
	std::cout << "Assigned - Longest: " << assigned.longestSpan() << std::endl;

	std::cout << std::endl;
}

int	main(void)
{
	test_subject();
	testExceptions();
	testLargeSpan();
	testVeryLargeSpan();
	testAddRangeVector();
	testAddRangeList();
	testAddRangeArray();
	testCopyAndAssignment();

	return (0);
}