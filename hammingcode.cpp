#include<iostream>
#include<string>
using namespace std;

string sender(string message)
{
    if (message.size()!=8) {
        cout<<"Incorrect message size"<<endl;
        return "";
    }
    string m="";
    m+="  ";
    m+=message[0];
    m+=" ";
    for (int i=1; i<=3; i++)
        m+=message[i];
    m+=" ";
    for (int i=4; i<=7; i++)
        m+=message[i];
    cout<<"Message(with spaces for parity bits):"<<m<<endl;
    int p1=0, p2=0, p4=0, p8=0;
    string ps0="0", ps1="0", ps3="0", ps7="0";

    int onecount=0;
    if (m.compare(2,1,"1")==0)
        onecount++;
    if (m.compare(4,1,"1")==0)
        onecount++;
    if (m.compare(6,1,"1")==0)
        onecount++;
    if (m.compare(8,1,"1")==0)
        onecount++;
    if (m.compare(10,1,"1")==0)
        onecount++;
    if (onecount%2!=0)
        p1=1;

    onecount=0;
    if (m.compare(2,1,"1")==0)
        onecount++;
    if (m.compare(5,1,"1")==0)
        onecount++;
    if (m.compare(6,1,"1")==0)
        onecount++;
    if (m.compare(9,1,"1")==0)
        onecount++;
    if (m.compare(10,1,"1")==0)
        onecount++;
    if (onecount%2!=0)
        p2=1;

    onecount=0;
    if (m.compare(4,1,"1")==0)
        onecount++;
    if (m.compare(5,1,"1")==0)
        onecount++;
    if (m.compare(6,1,"1")==0)
        onecount++;
    if (m.compare(11,1,"1")==0)
        onecount++;
    if (onecount%2!=0)
        p4=1;

    onecount=0;
    if (m.compare(8,1,"1")==0)
        onecount++;
    if (m.compare(9,1,"1")==0)
        onecount++;
    if (m.compare(10,1,"1")==0)
        onecount++;
    if (m.compare(11,1,"1")==0)
        onecount++;
    if (onecount%2!=0)
        p8=1;

    cout<<"p8: "<<p8<<endl;
    cout<<"p4: "<<p4<<endl;
    cout<<"p2: "<<p2<<endl;
    cout<<"p1: "<<p1<<endl;

    if (p1 == 1)
        ps0="1";
    if (p2 == 1)
        ps1="1";
    if (p4 == 1)
        ps3="1";
    if (p8 == 1)
        ps7="1";
    m.replace(0,1,ps0);
    m.replace(1,1,ps1);
    m.replace(3,1,ps3);
    m.replace(7,1,ps7);

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
    cout<<m<<endl;
    int p1=0, p2=0, p4=0, p8=0;

    int onecount=0;
    if (m.compare(0,1,"1")==0)
        onecount++;
    if (m.compare(2,1,"1")==0)
        onecount++;
    if (m.compare(4,1,"1")==0)
        onecount++;
    if (m.compare(6,1,"1")==0)
        onecount++;
    if (m.compare(8,1,"1")==0)
        onecount++;
    if (m.compare(10,1,"1")==0)
        onecount++;
    if (onecount%2!=0)
        p1=1;

    onecount=0;
    if (m.compare(1,1,"1")==0)
        onecount++;
    if (m.compare(2,1,"1")==0)
        onecount++;
    if (m.compare(5,1,"1")==0)
        onecount++;
    if (m.compare(6,1,"1")==0)
        onecount++;
    if (m.compare(9,1,"1")==0)
        onecount++;
    if (m.compare(10,1,"1")==0)
        onecount++;
    if (onecount%2!=0)
        p2=1;

    onecount=0;
    if (m.compare(3,1,"1")==0)
        onecount++;
    if (m.compare(4,1,"1")==0)
        onecount++;
    if (m.compare(5,1,"1")==0)
        onecount++;
    if (m.compare(6,1,"1")==0)
        onecount++;
    if (m.compare(11,1,"1")==0)
        onecount++;
    if (onecount%2!=0)
        p4=1;

    onecount=0;
    if (m.compare(7,1,"1")==0)
        onecount++;
    if (m.compare(8,1,"1")==0)
        onecount++;
    if (m.compare(9,1,"1")==0)
        onecount++;
    if (m.compare(10,1,"1")==0)
        onecount++;
    if (m.compare(11,1,"1")==0)
        onecount++;
    if (onecount%2!=0)
        p8=1;

    int err_pos = p1*1 + p2*2 + p4*4 + p8*8;
    cout<<"p8: "<<p8<<endl;
    cout<<"p4: "<<p4<<endl;
    cout<<"p2: "<<p2<<endl;
    cout<<"p1: "<<p1<<endl;
    if (err_pos ==0)
        cout<<"No error"<<endl;
    else
        {
            cout<<"Error at position "<<err_pos<<endl;
            cout<<"i.e. Error at index "<<err_pos-1<<endl;
        }
}

int main()
{
    string msg;
    int p;
    cout<<"\nEnter data (8 bits) to send: ";
    cin>>msg;
    msg = sender(msg);
    cout<<"Message at sender, after incorporating parity bits: "<<msg<<endl;
    cout<<"\nEnter error index (0 to 12) for message (-1 for no error): ";
    cin>>p;
    msg = adderror(msg, p);
    cout<<"Error incorporated."<<endl;
    cout<<"After incorporating error: "<<msg<<endl;
    cout<<"\nReceived message: "<<endl;
    receiver(msg);
    return 0;
}


