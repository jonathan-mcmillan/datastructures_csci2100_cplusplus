#include <iostream>
#include <string>

using namespace std;

string modInput = "";

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
void getModInput(string input){
	for(int i = 0; i < input.size(); i++){
		if(input[i] == 'd')
                	continue;
                else if(input[i] == 'u'){
                        if(input[i+1] == 'd'){
                        	input.replace(i, 2, "du");
                                i = i-1;
                        }
                        else if(input[i+1] == 'u')
                               	continue;
                }
	}
        modInput = input;
        return;
}
/*
void getModInput(string input, int i){
	cout << "input: " << input << endl;
	if(i == input.size()){
	        cout << "setting modInput to input" << endl;
	        modInput = input;
       		cout << "input: " << input << " modInput: " << modInput << endl;
	        return;
	}
	else{
		if(input[i] == 'd')
			getModInput(input, i+1);
		else if(input[i] == 'u'){
			if(input[i+1] == 'd'){
				input.replace(i, 2, "du");
				getModInput(input, i);
			}
			else if(input[i+1] == 'u')
				getModInput(input, i+1);
		}
	}
}
*/
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
			getModInput(input);
                        cout << "Tree " << numTrial << ": " << getDepth(input) << "=>" << getDepth(modInput) << endl;
                        numTrial++;
			modInput = "";
                }
        }

        return 0;
}
