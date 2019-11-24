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
        ifstream file("plain.txt");
        ifstream k("key.txt");
        ofstream outfile("cipher.txt");
		string plaintext;
		int key;
		cout<<"Enter the plaintext: \n\n\n";
		/*while(file.good()){
            getline(file,plaintext);
		}*/
		getline(file,plaintext);
		cout<<plaintext<<endl;

		cout<<"\n\nEnter the key: ";
		k>>key;
		cout<<key<<endl;
		key=key%26;
		string encryption="";
		for(int i=0;i<plaintext.size();i++){
			if(islower(plaintext[i]))
				encryption+=(plaintext[i]-'a'+key)%26+'a';
			else if(isupper(plaintext[i]))
				encryption+=(plaintext[i]-'A'+key)%26+'A';
			else encryption+=plaintext[i];
		}
		//outfile<<encryption<<endl;
		cout<<" \n\n\nYou got the cipher text is:: \n "<<encryption<<endl;
		outfile<<encryption;
		file.close();
		k.close();
		outfile.close();

	}else if(choice==2)
	{

        ifstream file("cipher.txt");
        ifstream k("key.txt");
        ofstream fileout("recoveredPlaintext.txt");

		string decryptedMessage="";
		string ciphertext;
		int key;
		cout<<"Enter the ciphertext:\n";//<<endl;
        getline(file,ciphertext);
        cout<<ciphertext<<endl;
		cout<<"\nEnter the key: ";//<<endl;
		k>>key;
		cout<<key<<endl;
		key=key%26;
		decryptedMessage=decryption(ciphertext,key);
		fileout<<decryptedMessage;
		cout<<"\nYou got the plaintext:\n "<<decryptedMessage<<endl;
		file.close();
		k.close();
		fileout.close();

	}
	else if(choice==3)
	{
        ifstream file("cipher.txt");
        ofstream fileout("brute.txt");
		string ciphertext;
		string bruteText;
		cout<<"-- It is the time for  bruteforce attack--"<<endl;
		cout<<"The cipher text:\n";//<<endl;

		getline(file,ciphertext);
		cout<<ciphertext<<endl;

		for(int findkey=0;findkey<26;findkey++){
			bruteText="";
			string cipher=ciphertext;
			bruteText=decryption(cipher,findkey);
			fileout<<"key= "<<findkey<<"  :   "<<bruteText<<endl<<endl;
			cout<<"key= "<<findkey<<"  :   "<<bruteText<<endl<<endl;

		}
		file.close();
		fileout.close();
	}
	else if(choice==4)
        break;
  }


	return 0;
}

