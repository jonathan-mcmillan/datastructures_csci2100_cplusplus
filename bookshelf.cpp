#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
list<int> bookNumbers;
list<int> bookSizes;
list<int> bookAlreadyOn;
int currentSize = 0;

void addBook(int bookNumber, int bookSize, int shelfWidth) {
	currentSize = currentSize + bookSize;
	while (currentSize > shelfWidth) {
		currentSize = currentSize - bookSizes.front();
		bookSizes.pop_front();
		bookNumbers.pop_front();
	}
	bookSizes.push_back(bookSize);
	bookNumbers.push_back(bookNumber);
}

void removeBook(int bookNumber) {
	list<int>::iterator it1 = bookSizes.begin();
	list<int>::iterator it2;
	for(it2 = bookNumbers.begin(); it2 != bookNumbers.end(); it2++){
		if(*it2 == bookNumber){
			it2 = bookNumbers.erase(it2);
			currentSize = currentSize - *it1;
			it1 = bookSizes.erase(it1);
			break;
		}
		it1++;
	}
}

void printReset() {
	
	while (!bookNumbers.empty()) {
		cout << bookNumbers.back() << " ";
		bookNumbers.pop_back();
		bookSizes.pop_back();
	}
	currentSize = 0;
	cout << endl;
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
