#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<string> solutions;

void solve(string goal, string intial, string curSeq, string output,string moves){
	if(goal == output){
		solutions.push(moves);
	}
	if(intial.length() > 0){ //pop
		solve(goal, intial.substr(1,intial.length()-1), (curSeq+intial[0]), output, (moves+"+"));
	}
	if(curSeq.length() > 0){ //push
		solve(goal, intial, curSeq.substr(0, curSeq.length()-1), (output+curSeq[curSeq.length()-1]), (moves+="-"));
	}
}

int main(){
	int num, i = 0;
	cin >> num;
	while(i < num){
		string input, goal;
		cin >> input >> goal;
		solve(goal, input, "", "", "");
		cout << "Output for " << input << " " << goal << endl;
		cout << "[" << endl;
		while(!solutions.empty()){
			cout << solutions.top() << endl;
			solutions.pop();
		}
		cout << "]" << endl;
		i = i+1;
	}

	return 0;
}
