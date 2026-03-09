#include "PmergeMe.hpp"

namespace
{
    std::vector<size_t> createJacobsthal(size_t n)
    {
        std::vector<size_t> jacobsthal;
        jacobsthal.push_back(0);
        jacobsthal.push_back(1);

        size_t next;
        while (true)
        {
            next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
            if (next >= n)
                break;
            jacobsthal.push_back(next);
        }

        return jacobsthal;
    }

    template <typename Container>
    int binarySearch(const Container &arr, int item, int left, int right)
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] == item)
                return mid;
            else if (arr[mid] < item)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    template <typename Container>
    void insertionSort(Container &arr, int left, int right)
    {
        for (int i = left + 1; i <= right; i++)
        {
            int key = arr[i];
            int j = i - 1;

            while (j >= left && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    template <typename Container>
    void fordJohnsonTmplt(Container &arr)
    {
        size_t n = arr.size();

        if (n <= 1)
            return;

        if (n <= 10)
        {
            insertionSort(arr, 0, static_cast<int>(n) - 1);
            return;
        }

        std::vector<std::pair<int, int> > pairs;
        bool hasStraggler = (n % 2 != 0);
        int straggler = hasStraggler ? arr[n - 1] : 0;

        for (size_t i = 0; i < n - (hasStraggler ? 1 : 0); i += 2)
        {
            if (arr[i] > arr[i + 1])
                pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
            else
                pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }

        Container mainChain;
        for (size_t i = 0; i < pairs.size(); i++)
            mainChain.push_back(pairs[i].first);

        fordJohnsonTmplt(mainChain);

        Container result;
        if (!mainChain.empty())
            result.push_back(mainChain[0]);

            
        std::vector<bool> inserted(pairs.size(), false);

        for (size_t i = 0; i < mainChain.size(); i++)
        {
            for (size_t j = 0; j < pairs.size(); j++)
            {
                if (pairs[j].first == mainChain[i] && !inserted[j])
                {
                    int pos = binarySearch(result, pairs[j].second, 0, static_cast<int>(result.size()) - 1);
                    result.insert(result.begin() + pos, pairs[j].second);
                    inserted[j] = true;
                    break;
                }
            }
            if (i < mainChain.size() - 1)
                result.push_back(mainChain[i + 1]);
        }

        if (hasStraggler)
        {
            int pos = binarySearch(result, straggler, 0, static_cast<int>(result.size()) - 1);
            result.insert(result.begin() + pos, straggler);
        }

        arr = result;
    }
}


PmergeMe:: PmergeMe() : _vectorTime(0), _dequeTime(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    _inputVector = other._inputVector;
    _inputDeque = other._inputDeque;
    _sortedVector = other._sortedVector;
    _sortedDeque = other._sortedDeque;
    _vectorTime = other._vectorTime;
    _dequeTime = other._dequeTime;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _inputVector = other._inputVector;
        _inputDeque = other._inputDeque;
        _sortedVector = other._sortedVector;
        _sortedDeque = other._sortedDeque;
        _vectorTime = other._vectorTime;
        _dequeTime = other._dequeTime;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const std::string &str)
{
    if (str.empty())
        return false;
    
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }

    // Check for overflow
    long num = std::atol(str.c_str());
    if (num < 0 || num > 2147483647)
        return false;
    
    return true;
}

bool PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string str(argv[i]);
        
        if (!isValidNumber(str))
            return false;
        
        int num = std::atoi(str.c_str());
        _inputVector.push_back(num);
        _inputDeque.push_back(num);
    }
    
    return true;
}

// Get current time in microseconds
double PmergeMe::getTime()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000000.0 + time.tv_usec);
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t n)
{
    return createJacobsthal(n);
}

int PmergeMe::binarySearchVector(const std:: vector<int> &arr, int item, int left, int right)
{
    return binarySearch(arr, item, left, right);
}

void PmergeMe::insertionSortVector(std:: vector<int> &arr, int left, int right)
{
    insertionSort(arr, left, right);
}

void PmergeMe::fordJohnsonVector(std::vector<int> &arr)
{
    fordJohnsonTmplt(arr);
}

int PmergeMe::binarySearchDeque(const std::deque<int> &arr, int item, int left, int right)
{
    return binarySearch(arr, item, left, right);
}

void PmergeMe::insertionSortDeque(std::deque<int> &arr, int left, int right)
{
    insertionSort(arr, left, right);
}

void PmergeMe::fordJohnsonDeque(std::deque<int> &arr)
{
    fordJohnsonTmplt(arr);
}

void PmergeMe::sortWithVector()
{
    _sortedVector = _inputVector;
    double start = getTime();
    fordJohnsonVector(_sortedVector);
    double end = getTime();
    _vectorTime = end - start;
}

void PmergeMe::sortWithDeque()
{
    _sortedDeque = _inputDeque;
    double start = getTime();
    fordJohnsonDeque(_sortedDeque);
    double end = getTime();
    _dequeTime = end - start;
}

void PmergeMe::displayBefore()
{
    std::cout << "Before:  ";
    for (size_t i = 0; i < _inputVector.size(); i++)
        std::cout << _inputVector[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::displayAfter()
{
    std::cout << "After:   ";
    for (size_t i = 0; i < _sortedVector.size(); i++)
        std::cout << _sortedVector[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::displayTiming()
{
    std::cout << "Time to process a range of " << _inputVector.size()
              << " elements with std::vector :  " << _vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _inputDeque.size()
              << " elements with std::deque :  " << _dequeTime << " us" << std::endl;
}