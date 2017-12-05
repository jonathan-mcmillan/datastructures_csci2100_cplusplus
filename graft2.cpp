#include <iostream>
#include <string>
using namespace std;

int getDepth(string input){
	int num = 0;
        int Depth = 0;
        for(int i = 0; i < input.length() ; i++){
                if(input[i] == 'd'){
                        num++;
                        if(num > Depth){
                                Depth = num;
                        }
                }
                else{
                        num--;
                }
        }
        return Depth;
}

string getModinput(string input){
	string modInput = "";
	
	return modInput;	
}

int main(){
        bool tf = true;
        int numTrial = 1;
        while(tf){
                string input;
                cin >> input;
                if(input[0] == '#'){
                        tf = false;
                }
                else{
                        cout << "Tree " << numTrial << ": " << getInitDepth(input) << "=>" << getDepth(getModInput(input)) << endl;
                        numTrial++;
                }
        }

        return 0;
}
