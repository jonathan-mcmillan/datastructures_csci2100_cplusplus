#include <string>
#include <iostream>
#include <queue>
using namespace std;

int getNumLeft(int numBeds, string a) {
	int numLeft = 0;
	int numTanning = 0;
	int customers[26] = {0};
	queue<int> waiting;
	queue<int> helper;

	for (int i = 0; i < (int)a.length(); i++) {
		int customer = a[i] + '0' - 113;
		if (customers[customer] == 0) {
			if (numTanning < numBeds) {
				customers[customer] = 1;	//in bed tanning = 1
				numTanning++;
			}
			else {
				customers[customer] = 3;	//waiting for tanning bed
				waiting.push(customer);		//added to waiting queue
			}
		}
		else if (customers[customer] == 1) {
			numTanning--;
			customers[customer] = 2;	//left the salon
			if (!waiting.empty()) {		//add person from queue to the bed
				customers[waiting.front()] = 1;
				waiting.pop();
			}
		}
		else {		//person waiting is leaving
			numLeft++;
			while (waiting.front() != customer) {
				helper.push(waiting.front());
				waiting.pop();
			}
			waiting.pop();		//pop person leaving
			if (!helper.empty()) {
				while (!waiting.empty()) {
					helper.push(waiting.front());
					waiting.pop();
				}
				swap(waiting, helper);
			}
		}
	}
	return numLeft;
}

int main() {
	int numBeds, numLeft;
	string a;

	cin >> numBeds >> a;
	while(numBeds != 0){
		numLeft = getNumLeft(numBeds, a);
		if (numLeft != 0) {
			cout << numLeft << " customer(s) walked away." << endl;
		}
		else {
			cout << "All customers tanned successfully" << endl;
		}
		cin >> numBeds >> a;
	}
}
