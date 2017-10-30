#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {

    int shelfWidth;
    while (cin >> shelfWidth && shelfWidth != -1) {
        list<int> bookshelf;          // IDs for the books currently on the shelf, from left to right
        int total(0);                 // cumulative width of all books on the shelf
        vector<int> width(101, 0);    // width for known books, indexed by book ID
        vector<list<int>::iterator> locate(101, bookshelf.end());    // positions of books on the shelf, index by ID

        // run the simulation and output the results...
    }
}
