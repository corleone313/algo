#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

int main(void){
	vector<int> vi;
	int num;
	cin >> num;
	while(num != -1){
		vi.push_back(num);
		cin >> num;
	}
	int length;
	length = vi.size();
	if(length % 2 != 0){
		int i;
		for(i=0; i!=(length - 1); i+=2){
			cout << i << " + " << i + 1
				<< " = " << (vi[i] + vi[i+1]) << endl;
		}
		cout << "size is odds, last`t sum, last is :"
			<< vi[length-1] << endl;
	}
}
