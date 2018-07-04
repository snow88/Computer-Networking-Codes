#include<iostream>
#include<math.h>
using namespace std;

int p, q;
int n, e;
int phi, d;

rsa_mod (double a, int b, int c)
{
    double temp = pow(a,b);
    double mod = fmod(temp, c);
    return mod;
}

receiver_key_initiate()
{
    cout<<"Initiating as receiver..."<<endl;
    cout<<"Enter p (prime no.):  ";
    cin>>p;
    cout<<"Enter q (prime no.):  ";
    cin>>q;

    n = p*q;
    phi = (p-1)*(q-1);
    cout<<"\nn (public):  "<<n<<endl;
    cout<<"phi (private):  "<<phi<<endl;

    cout<<"\nEnter e (relatively prime to phi and <=phi) (public):  ";
    cin>>e;
    cout<<"Calculating d..."<<endl;
    int k=0;
    while(1)
    {
        if ((k*phi+1)%e == 0)
        {
            d = (k*phi+1)/e;
            break;
        }
        k++;
    }
    cout<<"d (private):  "<<d<<endl;
}

double encryptandsend()
{
    cout<<"\nAt Sender..."<<endl;
    double plaintext;
    cout<<"Enter plaintext to send (integer, less than n):  ";
    cin>>plaintext;
    double ciphertext = rsa_mod(plaintext, e, n);
    return ciphertext;
}

void receiveanddecrypt(double ciphertext)
{
    cout<<"\nAt Receiver..."<<endl;
    cout<<"Received ciphertext is:  "<<ciphertext<<endl;
    cout<<"Decrypting..."<<endl;
    double plaintext = rsa_mod(ciphertext, d, n);
    cout<<"Plaintext after decrypting is:  "<<plaintext<<endl;
}

int main()
{
    receiver_key_initiate();
    double m = encryptandsend();
    receiveanddecrypt(m);
    return 0;
}
