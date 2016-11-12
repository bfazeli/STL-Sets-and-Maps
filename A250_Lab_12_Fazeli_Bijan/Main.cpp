/*
Fazeli, Bijan
Lauguico, Marco
CS A250
November 9, 2016

Lab 12: STL Sets and Maps
*/

#include <iostream>
#include <map>
#include <set>

using namespace std;

// prototype
int countClumps(const multiset<int>& mSet);
bool linearIn(const multimap<int, int>& map);
void multiples(set<int>& set, int multiplicator);

int main() 
{
	multiset<int> set1 = { 1, 2, 2, 3, 4, 4 };
	multiset<int> set2 = { 1, 1, 2, 2, 2 };
	multiset<int> set3 = { 3, 3, 3, 3, 3 };
	multiset<int> set4 = { 1, 2, 3 };
	multiset<int> set5 = { 2, 2, 6, 6, 6, 7, 8, 8, 9, 9 };
	multiset<int> set6 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 9 };
	multiset<int> set7 = { 1, 3, 5, 7, 7, 8, 9 };
	multiset<int> set8 = {};

	multiset<int> multiArray [] = {
		set1, set2, set3, set4, set5, set6, set7, set8
	};

	multimap<int, int> multiMapArray[] = {
		{ {1,2}, {2,4}, {2,1}, {4,2}, {6,1}, {7,4} },
		{ {1,2}, {2,4}, {2,1}, {4,2}, {6,1}, {7,4} },
		{ {1,2}, {2,6}, {4,2}, {4,6}, {6,4} },
		{ {2,4}, {2,3}, {4,6}, {4,7}, {6,5}, {6,2} },
		{ {3,6}, {4,6}, {5,6}, {6,6} },
		{ {3,3}, {3,3}, {3,3}, {3,3}, {3,4} },
		{ {3,3}, {3,3}, {3,3}, {3,4}, {4,3} }
	};

	for (int i = 0; i < 8; i++) cout << countClumps(multiArray[i]) << endl;

	set<int> setSet = {};
	multiples(setSet, 3);

	set<int>::const_iterator iter;
	for (iter = setSet.cbegin(); iter != setSet.cend(); ++iter)
	{
		cout << *iter << " ";
	}

	cout << endl;
	system("pause");
	return 0;
}

// Implementation
int countClumps(const multiset<int>& mSet)
{
	if (mSet.empty()) return 0;

	multiset<int>::const_iterator it = mSet.cbegin();
	int index = 0;
	int count = 0;
	int temp = *it;
	int current;
	for (it; it != mSet.cend(); ++it)
	{
		current = *it;
		if (temp == current) ++count;
		else
		{
			temp = *it;
			count = 1;
		}

		if (count == 2) ++index;
	}

	return index;
}

bool linearIn(const multimap<int, int>& map)
{
	for (multimap<int, int>::const_iterator it = map.cbegin(), end = map.cend();
		it != end;
		++it)
		if (map.find(it->second) == end) return false;
	return true;
}
void multiples(set<int>& set, int multiplicator) 
{
	for (int i = 1, count = 0; count < 10; ++i)
		if (((i*multiplicator) - multiplicator) % 10 != 0)
		{
			set.insert(i*multiplicator);
			++count;
		}
}