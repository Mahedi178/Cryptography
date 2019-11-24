#include<bits/stdc++.h>
using namespace std;
string letter="ABCDEFGHIJKLMNOPQRTSUVWXYZabcdefghijklmnopqrstuvwxyz";
string key="MNOPQRTSUVWXYZGHIJKLABCDEFmnopqrstuvwxyzghijklabcdef";
map<char,char>mp1,mp2;
map<char,int>mp3;
int main()
{
	cout<<"Let's begin-----------------mono-alphabetic cipher--------------"<<endl;
	for(int i=0;i<letter.size();i++){
		mp1.insert({letter[i],key[i]});
		mp2.insert({key[i],letter[i]});
	}
	//for(auto it:mp1)cout<<it.first<<" "<<it.second<<endl;
	int choice;
	while(true){

    cout<<"\n\n\n1.Encryption. \n2.Decryption \n3.Frequency analysis and breaking down the substitution cipher\n4.Exit"<<endl;
    cin>>choice;
    if(choice==1){




    string plaintext;
	char ch1,ch2;
	string encryptedMessage="";
	cout<<"Enter the plaintext:"<<endl;
	ifstream file("plaintext.txt"); //for reading file.

	//<<endl;

	getline(file,plaintext);
	cout<<plaintext;
	file.close();

	for(int i=0;i<plaintext.size();i++){
		if(isalpha(plaintext[i]))
			encryptedMessage+=mp1[plaintext[i]];
		else encryptedMessage+=plaintext[i];
	}
    cout<<"\n\n\nThe encrypted message is:\n "<<encryptedMessage<<endl;
	ofstream fileOut("ciphertext.txt");
	fileOut<<encryptedMessage;
    fileOut.close();



    }
    else if(choice==2)
    {


	cout<<"\n\n\nNow it time for decryption "<<endl;
	ifstream file2("ciphertext.txt");

	string ciphertext,decryptedMessage="";
	cout<<"\nEnter the ciphertext: ";//<<endl;
	getline(file2,ciphertext);
	file2.close();

	cout<<"\n\nThe ciphertext is: "<<endl;
	cout<<ciphertext;
	for(int i=0;i<ciphertext.size();i++){
		if(isalpha(ciphertext[i]))
			decryptedMessage+=mp2[ciphertext[i]];
		else decryptedMessage+=ciphertext[i];

	}
	cout<<endl<<endl;
	ofstream fileout("recoveredPlaintext.txt");
	fileout<<decryptedMessage;
	cout<<"\nThe recovered plainText:\n "<<decryptedMessage<<endl;
	fileout.close();


    }
    else if(choice==3){



    cout<<"\n\n Now it is time for frequency analysis"<<endl;
	string freq;
	ifstream fileout1("ciphertext.txt");
	getline(fileout1,freq);
	fileout1.close();
	cout<<"\n\n The cipher text for frequency analysis"<<endl;


	transform(freq.begin(),freq.end(),freq.begin(),::tolower);//it transform all uppercase into lowercase
	cout<<freq<<endl;
	for(int i=0;i<freq.size();i++){
		if(islower(freq[i]))mp3[freq[i]]++;
		else if(isupper(freq[i])){
			char ch=freq[i];
			ch=tolower(ch);
			mp3[ch]++;
	}
	}
	ofstream frequency("frequency.txt");
	cout<<"\nThe frequency of each letter is "<<endl;
	for(auto it:mp3){
            frequency<<it.first<<" "<<it.second<<endl;
            cout<<it.first<<" "<<it.second<<endl;
	}
	frequency.close();
	cout<<endl;
	string ciphertext=freq;
	cout<<"\nNow it is time for braking down the cipher:\n"<<endl;
	cout<<"\nThe cipher text is:\n"<<ciphertext<<endl;
	replace(ciphertext.begin(),ciphertext.end(),'m','A');
	replace(ciphertext.begin(),ciphertext.end(),'k','S');
	replace(ciphertext.begin(),ciphertext.end(),'c','W');
	replace(ciphertext.begin(),ciphertext.end(),'q','E');
	replace(ciphertext.begin(),ciphertext.end(),'x','L');
	replace(ciphertext.begin(),ciphertext.end(),'j','R');
	replace(ciphertext.begin(),ciphertext.end(),'a','U');
	replace(ciphertext.begin(),ciphertext.end(),'l','T');
	replace(ciphertext.begin(),ciphertext.end(),'g','O');
	replace(ciphertext.begin(),ciphertext.end(),'n','B');
	replace(ciphertext.begin(),ciphertext.end(),'r','F');
	replace(ciphertext.begin(),ciphertext.end(),'t','H');
	replace(ciphertext.begin(),ciphertext.end(),'z','N');
	replace(ciphertext.begin(),ciphertext.end(),'u','I');
	replace(ciphertext.begin(),ciphertext.end(),'f','Z');
	replace(ciphertext.begin(),ciphertext.end(),'p','D');
	replace(ciphertext.begin(),ciphertext.end(),'h','P');
    replace(ciphertext.begin(),ciphertext.end(),'d','X');
    replace(ciphertext.begin(),ciphertext.end(),'y','M');
    replace(ciphertext.begin(),ciphertext.end(),'s','G');
    replace(ciphertext.begin(),ciphertext.end(),'o','C');
    replace(ciphertext.begin(),ciphertext.end(),'e','Y');
    replace(ciphertext.begin(),ciphertext.end(),'v','J');
    replace(ciphertext.begin(),ciphertext.end(),'b','V');
    replace(ciphertext.begin(),ciphertext.end(),'w','K');
	cout<<"\nThe ciphertext is:\n"<<ciphertext<<endl;

  }
  else if(choice==4){

    break;
  }

}



	return 0;
}
