#include <iostream>
#include <vector>

template<typename T>
void merge(std::vector<T>& A, size_t left, size_t mid, size_t right)
{
	size_t i = left;
	size_t j = mid + 1;

	std::vector<T> sorted;

	while (i <= mid && j <= right)
	{
		if (A[i] <= A[j])
			sorted.push_back(A[i++]);
		else
			sorted.push_back(A[j++]);
	}

	if (i > mid)
	{
		while (j <= right)
			sorted.push_back(A[j++]);
	}
	else if (j > right)
	{
		while (i <= mid)
			sorted.push_back(A[i++]);
	}

	size_t k = 0;
	for (size_t i = left; i <= right; i++)
		std::swap(A[i], sorted[k++]);
}

template<typename T>
void MergeSort(std::vector<T>& A, size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = (left + right) / 2;
		MergeSort(A, left, mid);
		MergeSort(A, mid + 1, right);
		merge(A, left, mid, right);
	}
}

int main()
{
	long long int num;
	std::cin >> num;
	std::vector<long int> A;
	for (size_t i = 0; i < num; ++i)
	{
		long int x = 0;
		std::cin >> x;
		A.push_back(x);
	}

	MergeSort(A, 0, A.size() - 1);
	for (auto& x : A)
		std::cout << x << '\n';

	return 0;
}
