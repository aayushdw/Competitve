#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

vector<int> enigma(string raw, string key)
{
	vector<int> code;
	for(int i = 0; i < raw.size(); i++)
		code.push_back( raw[i] );
	for(int i = 0; i < raw.size(); i++)
		for(int j = 0; i+j < raw.size() && j < key.size(); j++)
			code[i+j] ^= key[j];
	return code;
}

string decode(string encoded, string key)
{
	string x;
	for(int i=0;i<encoded.size()/3;i++)
		cout << encoded.substr(3*i,3) << " ";
	return x;
}

int main()
{
	string raw, key;
	cin >> raw;
	cin >> key;
	vector<int> code = enigma( raw, key );
	for(int i = 0; i < code.size(); i++)
		printf("%03d",code[i]);
	printf("\n");

	string encoded;
	cin >> encoded;
	cout<< decode(encoded,key) << endl;

	return 0;
}