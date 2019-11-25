#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
typedef long long ll;
using namespace std;
int poww(int a,int b,int mod)
{
    int k=1;
    for(int i=0;i<b;i++){
        k=k*a;
        k=k%mod;
    }
    return k;
}

int main()
{
    FIO;
    ll c,m;
    int p=11,q=13;
    int n=p*q;
    int totient=(p-1)*(q-1);
    //public key
    //e stands for encrypt

    int e=7;
    while(e<totient){
        if(__gcd(e,totient)==1)break;
        else e++;
    }
    int d=e;
    while(((d*e)%totient)!=1){
        d++;
    }
    cout<<"\n e = "<<e<<" d = "<<d<<endl;

    string msg,encryptedMessage="",decryptedMessage="";
    int choice;
    while(1){
    cout<<"\n1.Encryption.\n2.Decryption\n3.Exit"<<endl;
    cin>>choice;
    if(choice==1){
        cout<<"Enter the message data"<<endl;
    ifstream file("plaintext.txt");
    getline(file,msg);
    cout<<msg<<endl;
    file.close();
    vector<char>v1;
    for(int i=0; i<msg.size();i++){

        int r=(int)(msg[i]);
        //cout<<"\n 43 line "<<r<<endl;
        int c=poww(r,e,n);
       // cout<<"\n 44 line "<<c<<" "<<(char)c<<endl;

        encryptedMessage+=(char(c));
     //   v1.push_back((char)c);

    }
    cout<<"\n the cipher text is:\n"<<encryptedMessage<<endl;

    ofstream fileout("ciphertext.txt");
    fileout<<encryptedMessage;
    fileout.close();
   // for(char ch:v1)cout<<ch;
    //cout<<endl;


    }
    else if(choice==2){
    string cipher;
    cout<<"\nEnter the cipher text "<<endl;
    ifstream file1("ciphertext.txt");
    getline(file1,cipher);
    cout<<cipher<<endl;
    file1.close();
    for(int i=0; i<cipher.size();i++){
        int r=(int)(cipher[i]);
        m=poww(r,d,n);
       // cout<<"\n 54 line "<<m<<" "<<(char)m<<endl;
        decryptedMessage+=((char)m);

    }
    ofstream fileout1("recoveredPlaintext.txt");
    fileout1<<decryptedMessage;
    cout<<"\n\n the decrypted message :\n"<<decryptedMessage<<endl;
    fileout1.close();
    }
    else {
     break;
    }

    }




    return 0;
}
