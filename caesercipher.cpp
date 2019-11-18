#include<bits/stdc++.h>
using namespace std;

string decryption(string ciphert,int &k)
{
	string recoveredPlaintext="";
	int keyd=k;
	for(int i=0;i<ciphert.size();i++){
			if(islower(ciphert[i])){
				int r;
				r=ciphert[i]-'a'-keyd;
				if(r<0)
					r+=26;
				recoveredPlaintext+=(r)%26+'a';
			}
			else if(isupper(ciphert[i]))
			{
				int r;
				r=ciphert[i]-'A'-keyd;
				if(r<0)
					r+=26;
				recoveredPlaintext+=(r)%26+'A';
			}
			else recoveredPlaintext+=ciphert[i];
		}
	return recoveredPlaintext;
}
int main()
{
	cout<<"---------------------------------Let's begin --------------------------"<<endl;
	int choice;
	
	while(true){
	cout<<"\n\n\n ----Choose one option------ "<<endl;
	cout<<"1.Encryption\n2.Decryption\n3.Brute force\n4.Exit"<<endl;
	cin>>choice;
	if(choice==1){
		string plaintext;
		int key;
		cout<<"Enter the plaintext: "<<endl;
		cin.ignore();
		getline(cin,plaintext);
		cout<<"Enter the key "<<endl;
		cin>>key;
		key=key%26;
		string encryption="";
		for(int i=0;i<plaintext.size();i++){
			if(islower(plaintext[i]))
				encryption+=(plaintext[i]-'a'+key)%26+'a';
			else if(isupper(plaintext[i]))
				encryption+=(plaintext[i]-'A'+key)%26+'A';
			else encryption+=plaintext[i];
		}
		cout<<" You got the cipher text is::  "<<encryption<<endl;
		
	}else if(choice==2)
	{
		
		string decryptedMessage="";
		string ciphertext;
		int key;
		cout<<"Enter the ciphertext: "<<endl;
		cin.ignore();
		getline(cin,ciphertext);
		cout<<"Enter the key "<<endl;
		cin>>key;
		key=key%26;	
		decryptedMessage=decryption(ciphertext,key);
		cout<<"You got the plaintext:: "<<decryptedMessage<<endl;
		
	}
	else if(choice==3)
	{
		
		string ciphertext;
		string bruteText;
		cout<<"-- It is the time for  bruteforce attack--"<<endl;
		cout<<"The cipher text:"<<endl;
		cin.ignore();
		getline(cin,ciphertext);
		
		for(int findkey=0;findkey<26;findkey++){
			bruteText="";
			string cipher=ciphertext;
			bruteText=decryption(cipher,findkey);
			cout<<" key is= "<<findkey<<" meaningful plaintext is:: "<<bruteText<<endl;
			
		}
	}else break;
	
	}
	return 0;
}