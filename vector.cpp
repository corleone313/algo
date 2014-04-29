#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(void){
	vector<string> sv(10, "hello");
	vector<int> si1;
	vector<int> si2(si1);
	vector<char> sc(10);
	cout << "before push sv:" << "\t"
		<< sv.empty()
		<< "\t" << sv.size()
		<< "\t" << sv[sv.size() - 1] << endl;
	sv.push_back("diaosi");
	cout << "after push sv:" << "\t"
		<< sv.empty()
		<< "\t" << sv.size()
		<< "\t" << sv[sv.size() - 1] << endl;

	cout << "sizeof v : " << "\t"
		<< sizeof(sv) << endl;


	//循环插入知道null
	string word;
	cin >> word;
	while(word != "*"){
		sv.push_back(word);
		cin>>word;
	}
	int length = sv.size();
	int i;
	for(i=0; i<length; i++){
		cout << sv[i] << endl;
	}
	return 0;
}
