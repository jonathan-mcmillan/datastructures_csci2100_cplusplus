#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
list<int> bookNumbers;
list<int> bookSizes;
int currentSize = 0;

void addBook(int bookNumber, int bookSize, int shelfWidth) {
	cout << "Entered addBook" << endl;
	currentSize = currentSize + bookSize;
	while (currentSize > shelfWidth) {
		currentSize = currentSize - bookSizes.front();
		bookSizes.pop_front();
		bookNumbers.pop_front();
	}
	bookSizes.push_back(bookSize);
	bookNumbers.push_back(bookNumber);
	cout << "Added " << bookNumber << endl;
}

void removeBook(int bookNumber) {
	cout << "Entered removeBook" << endl;
	list<int>::iterator it1, it2;
	it1 = bookSizes.begin();
	it2 = bookNumbers.begin();

	if(find(bookNumbers.begin(), bookNumbers.end(), bookNumber) != bookNumbers.end()){
		while (true) {
			if (*it1 == bookNumber) {
				it1 = bookNumbers.erase(it1);
				currentSize = currentSize - *it2;
				it2 = bookSizes.erase(it2);
				break;
			}
		 	if(*it1 == bookNumbers.back()){
				break;
			}
			else{
				it1++;
				it2++;
			}
		}
	}
	cout << "Left removeBooks" << endl;
}

void printReset() {
	cout << "Entered printReset" << endl;
	while (!bookNumbers.empty()) {
		cout << bookNumbers.back();
		bookNumbers.pop_back();
		bookSizes.pop_back();
	}
	currentSize = 0;
}

int main() {
	int numTimes;
	while (true) {
		int shelfWidth;
		cin >> shelfWidth;
		numTimes++;
		if (shelfWidth == -1) {
			break;
		}
		else {
			while (true) {
				string input;
				cin >> input;
				if (input == "E") {
					cout << "PROBLEM " << numTimes << ": ";
					printReset();
					break;
				}
				else {
					int bookNumber;
					cin >> bookNumber;
					if (input == "R") {
						removeBook(bookNumber);
					}
					else if (input == "A") {
						int bookSize;
						cin >> bookSize;
						addBook(bookNumber, bookSize, shelfWidth);
					}
				}
			}
		}
	}
	return 0;
}
