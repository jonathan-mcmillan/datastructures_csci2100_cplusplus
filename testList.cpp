#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main(){
	list<int> listOfNumbers;
	
	//Inserting elements at end in list
	listOfNumbers.push_back(5);
	listOfNumbers.push_back(6);

	//Inserting elements at front in list
	listOfNumbers.push_front(2);
	listOfNumbers.push_front(1);

	//Iterating over list elements and display them
	list<int>::iterator it = listOfNumbers.begin();
	while(it != listOfNumbers.end()){
		cout << (*it) << " ";
		it++;
	}
	cout << endl;
	
	//Inserting elemensts in between the list using
	//insert(pos,elem) member function. Let's iterate to
	//3rd position
	it = listOfNumbers.begin();
	it++;
	it++;
	//Iterator 'it' is at 3rd position
	listOfNumbers.insert(it,4);
	
	it = listOfNumbers.begin();
	while(it != listOfNumbers.end()){
		cout << (*it) << " ";
		it++;
	}
	cout << endl;

	it = listOfNumbers.begin();
	it++;
	it++;

	listOfNumbers.erase(it);
	
	it = listOfNumbers.begin();
        while(it != listOfNumbers.end()){
                cout << (*it) << " ";
                it++;
        }
        cout << endl;
/*
	listOfNumbers.remove_if([](int elem){
		if(elem > 3){
			return true;
		}
		else{
			return false;
		}
	});
*/
	listOfNumbers.remove_if([](int elem){return elem > 3;});

	it = listOfNumbers.begin();
        while(it != listOfNumbers.end()){
                cout << (*it) << " ";
                it++;
        }
        cout << endl;
	
	return 0;
}
