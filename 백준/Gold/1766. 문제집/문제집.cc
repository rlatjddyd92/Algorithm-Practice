#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct BOOK
{
	int iCountPreBook = 0;
	queue<int> queueNextBook;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iBooks = 0;
	int iOrder = 0;

	cin >> iBooks >> iOrder;

	vector<BOOK> vecBooks;
	vecBooks.resize(iBooks + 1);

	for (int i = 1; i <= iOrder; ++i)
	{
		int iPreBook = 0;
		int iNextBook = 0;

		cin >> iPreBook >> iNextBook;

		++vecBooks[iNextBook].iCountPreBook;
		vecBooks[iPreBook].queueNextBook.push(iNextBook);
	}

	priority_queue<int> queueFrontBook;

	for (int i = 1; i <= iBooks; ++i)
	{
		if (vecBooks[i].iCountPreBook == 0)
			queueFrontBook.push(-i);
	}

	while (!queueFrontBook.empty())
	{
		int iNowBook = -queueFrontBook.top();
		queueFrontBook.pop();

		cout << iNowBook << " ";

		while (!vecBooks[iNowBook].queueNextBook.empty())
		{
			int iNext = vecBooks[iNowBook].queueNextBook.front();
			vecBooks[iNowBook].queueNextBook.pop();
			if (vecBooks[iNext].iCountPreBook > 0)
				--vecBooks[iNext].iCountPreBook;

			if (vecBooks[iNext].iCountPreBook == 0)
				queueFrontBook.push(-iNext);
		}
	}

	vecBooks.clear();

	return 0;
}