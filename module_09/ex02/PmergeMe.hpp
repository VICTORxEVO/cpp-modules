#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>

class PmergeMe
{
private: 
    std:: vector<int> _inputVector;
    std::deque<int> _inputDeque;
    std::list<int> _inputList;
    std::vector<int> _sortedVector;
    std::deque<int> _sortedDeque;
    std::list<int> _sortedList;
    
    double _vectorTime;
    double _dequeTime;
    double _listTime;

    bool isValidNumber(const std::string &str);
    double getTime();
    
    void fordJohnsonVector(std::vector<int> &arr);
    void insertionSortVector(std::vector<int> &arr, int left, int right);
    int binarySearchVector(const std::vector<int> &arr, int item, int left, int right);
    
    void fordJohnsonDeque(std::deque<int> &arr);
    void insertionSortDeque(std::deque<int> &arr, int left, int right);
    int binarySearchDeque(const std::deque<int> &arr, int item, int left, int right);

    void fordJohnsonList(std::list<int> &arr);
    
    std::vector<size_t> generateJacobsthal(size_t n);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    bool parseInput(int argc, char **argv);
    void sortWithVector();
    void sortWithDeque();
    void sortWithList();
    void displayBefore();
    void displayAfter();
    void displayTiming();
};

#endif