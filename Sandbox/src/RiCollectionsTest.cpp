#include "RiCollectionsTest.h"
#include <array>

void TestCollections()
{
	rilib::collections::array<int, 20> a( { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 });

	for (auto i : a)
	{
		std::cout << i << '\n';
	}

	auto* b = new rilib::collections::array<int, 5>();

	for (auto i : *b)
	{
		std::cout << i << '\n';
	}

	for (size_t i = 0; i < 5; ++i)
	{
		std::cout << (*b)[i] << '\n';
	}
}
