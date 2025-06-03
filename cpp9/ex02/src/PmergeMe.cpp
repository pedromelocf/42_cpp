#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	_vector = other._vector;
	_deque = other._deque;
	_vectorTime = other._vectorTime;
	_dequeTime = other._dequeTime;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
		_vectorTime = other._vectorTime;
		_dequeTime = other._dequeTime;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::validateInput(const std::string &input)
{
	if (input.empty())
		return (false);

	for (size_t i = 0; i < input.length(); ++i) {
		if (!isdigit(input[i]))
			return (false);
	}

	try {
		long num = std::atol(input.c_str());
		if (num < 0 || num > INT_MAX)
			return (false);
	} catch(const std::exception &e) {
		return (false);
	}

	return (true);
}

void PmergeMe::parseArgs(char **argv)
{
	_vector.clear();
	_deque.clear();

	std::set<int> uniqueValues;
	int i = 1;
	while (argv[i])
	{
		std::string arg = argv[i];
		std::istringstream iss(arg);
		std::string token;

		while (iss >> token)
		{
			if (!validateInput(token))
				throw std::runtime_error(std::string("Error"));
			int num = atoi(token.c_str());
			if (uniqueValues.find(num) != uniqueValues.end())
				continue ;
			uniqueValues.insert(num);
			_vector.push_back(num);
			_deque.push_back(num);
		}
		i++;
	}

	if (_vector.empty())
		throw std::runtime_error(std::string("Error"));
}

void PmergeMe::processArgs(char **argv) {

	parseArgs(argv);

	std::cout << "Before: " ;
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	clock_t start = std::clock();
	fordJohnsonSortVector(_vector);
	clock_t end = std::clock();
	_vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	start = std::clock();
	fordJohnsonSortDeque(_deque);
	end = std::clock();
	_dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: " ;
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::displayElapsedTime() {

	std::cout << "Time to process a range of " << _vector.size() 
		<< " elements with std::vector: " 
		<< std::fixed << std::setprecision(5) << _vectorTime << " us" << std::endl;
	
	std::cout << "Time to process a range of " << _deque.size() 
		<< " elements with std::deque: " 
		<< std::fixed << std::setprecision(5) << _dequeTime << " us" << std::endl;
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr) {

	if (arr.size() == 1)
		return;

	std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() - 1; i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

	bool hasOdd = (arr.size() % 2 != 0);
    int oddElement = 0;
    if(hasOdd) {
    	oddElement = arr[arr.size() - 1];
	}

	std::vector<int> largerElements;
	for (size_t i = 0; i < pairs.size(); i++)
        largerElements.push_back(pairs[i].first);

	fordJohnsonSortVector(largerElements);

	std::vector<int> result;
	result.push_back(pairs[0].second);
    result.push_back(largerElements[0]);

	std::vector<int> jacobsthalIndices;
	int j1 = 1, j2 = 3;
    jacobsthalIndices.push_back(1);
	while (j2 < static_cast<int>(pairs.size()))
    {
        jacobsthalIndices.push_back(j2);
        int temp = j2;
        j2 = 2 * j1 + j2;
        j1 = temp;
	}

	for (size_t i = 1; i < pairs.size(); i++) {
        if (std::find(jacobsthalIndices.begin(), jacobsthalIndices.end(), i) == jacobsthalIndices.end())
            jacobsthalIndices.push_back(i);
    }

	for (size_t idx = 0; idx < jacobsthalIndices.size(); idx++) {
        int i = jacobsthalIndices[idx];

        if (i == 0 || i >= static_cast<int>(pairs.size()))
            continue ;
        
        int largerElement = largerElements[i];
        int smallerElement = pairs[i].second;

        std::vector<int>::iterator smallerIt = std::lower_bound(result.begin(), result.end(), smallerElement);
        result.insert(smallerIt, smallerElement);

        std::vector<int>::iterator largerIt = std::lower_bound(result.begin(), result.end(), largerElement);
        result.insert(largerIt, largerElement);
    }

	if (hasOdd) 
        result.insert(std::lower_bound(result.begin(), result.end(), oddElement), oddElement);

    arr = result;
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr) {

	if (arr.size() == 1)
			return;

	std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() - 1; i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

	bool hasOdd = (arr.size() % 2 != 0);
    int oddElement = 0;
    if (hasOdd) {
    	oddElement = arr[arr.size() - 1];
	}

	std::deque<int> largerElements;
	for (size_t i = 0; i < pairs.size(); i++)
        largerElements.push_back(pairs[i].first);

	fordJohnsonSortDeque(largerElements);

	std::deque<int> result;
	result.push_back(pairs[0].second);
    result.push_back(largerElements[0]);

	std::deque<int> jacobsthalIndices;
	int j1 = 1, j2 = 3;
    jacobsthalIndices.push_back(1);
	while (j2 < static_cast<int>(pairs.size()))
    {
        jacobsthalIndices.push_back(j2);
        int temp = j2;
        j2 = 2 * j1 + j2;
        j1 = temp;
	}

	for (size_t i = 1; i < pairs.size(); i++) {
        if (std::find(jacobsthalIndices.begin(), jacobsthalIndices.end(), i) == jacobsthalIndices.end())
            jacobsthalIndices.push_back(i);
    }

	for (size_t idx = 0; idx < jacobsthalIndices.size(); idx++) {
        int i = jacobsthalIndices[idx];

        if (i == 0 || i >= static_cast<int>(pairs.size()))
            continue ;
        
        int largerElement = largerElements[i];
        int smallerElement = pairs[i].second;

        std::deque<int>::iterator smallerIt = std::lower_bound(result.begin(), result.end(), smallerElement);
        result.insert(smallerIt, smallerElement);

        std::deque<int>::iterator largerIt = std::lower_bound(result.begin(), result.end(), largerElement);
        result.insert(largerIt, largerElement);
    }

	if (hasOdd) 
        result.insert(std::lower_bound(result.begin(), result.end(), oddElement), oddElement);

    arr = result;
}