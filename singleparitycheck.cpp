#include<iostream>
#include<string>
using namespace std;

string sender(string m)
{
    int onecount =0;
    for (int i=0; i<m.size(); i++)
    {
        if (m.compare(i, 1, "1")==0)
            onecount++;
    }

    if (onecount%2!=0)
        m+="1";
    else
        m+="0";
    cout<<"After adding parity: "<<m<<endl;
    return m;
}

string adderror(string message, int p)
{
    if (p==-1)
        return message;
    if (message.compare(p,1,"1")==0)
        message.replace(p,1,"0");
    else
        message.replace(p,1,"1");
    return message;
}

void receiver(string m)
{
    cout<<"\nReceived message: "<<m<<endl;
    int onecount =0;
    for (int i=0; i<m.size(); i++)
    {
        if (m.compare(i, 1, "1")==0)
            onecount++;
    }

    if (onecount%2!=0)
        cout<<"Error detected"<<endl;
    else
        cout<<"No error detected"<<endl;
}

int main()
{
    string message;
    int p;
    cout<<"Enter data to send: ";
    cin>>message;
    string sentmessage = sender(message);
    cout<<"\nEnter error index (-1 for no error): ";
    cin>>p;
    sentmessage=adderror(sentmessage, p);
    cout<<"Error incorporated."<<endl;
    receiver(sentmessage);

    return 0;
}
