#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
        int numNames;
                int numtimes = 0;
        string name;
                queue<string> first;
        stack<string> last;
        while (true) {
                cin >> numNames;
                if(numNames == 0){
                                        break;
                }
                                numtimes++;
                for (int i = 0; i != numNames; i++) {
                        cin >> name;
                        if (i % 2 == 1) {
                                                        last.push(name);
                        }
                        else {
                                first.push(name);
                        }
                }

                                cout << "SET " << numtimes << endl;

                                while (!first.empty()) {
                                        cout << first.front() << endl;
                                        first.pop();
                                }
                while(!last.empty()){
                        cout << last.top() << endl;
                        last.pop();
                }
        }
    return 0;
}

