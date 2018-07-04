#include<iostream>
#include<string>
using namespace std;

string chksum(string byte1, string byte2)
{
    string checksum="";
    if (byte1.size()!=byte2.size())
        return "9";
    int carry = 0;
    for (int i=byte1.size()-1; i>=0; i--)
    {
        if (byte1.compare(i,1,"0")==0 && byte2.compare(i,1,"0")==0 && carry==0)
        {
            checksum = "0"+checksum;
            carry=0;
        }
        else if (byte1.compare(i,1,"0")==0 && byte2.compare(i,1,"0")==0 && carry==1)
        {
            checksum = "1"+checksum;
            carry=0;
        }
        else if (byte1.compare(i,1,"0")==0 && byte2.compare(i,1,"1")==0 && carry==0)
        {
            checksum = "1"+checksum;
            carry=0;
        }
        else if (byte1.compare(i,1,"0")==0 && byte2.compare(i,1,"1")==0 && carry==1)
        {
            checksum = "0"+checksum;
            carry=1;
        }
        else if (byte1.compare(i,1,"1")==0 && byte2.compare(i,1,"0")==0 && carry==0)
        {
            checksum = "1"+checksum;
            carry=0;
        }
        else if (byte1.compare(i,1,"1")==0 && byte2.compare(i,1,"0")==0 && carry==1)
        {
            checksum = "0"+checksum;
            carry=1;
        }
        else if (byte1.compare(i,1,"1")==0 && byte2.compare(i,1,"1")==0 && carry==0)
        {
            checksum = "0"+checksum;
            carry=1;
        }
        else if (byte1.compare(i,1,"1")==0 && byte2.compare(i,1,"1")==0 && carry==1)
        {
            checksum = "1"+checksum;
            carry=1;
        }
    }

    cout<<"\nOn adding: "<<checksum<<endl;

    if (carry!=0) {
        for (int i=checksum.size()-1; i>=0; i--) {
            if (checksum.compare(i,1,"0")==0 && carry==0) {
                checksum.replace(i,1,"0");
                carry=0;
            }
            else if (checksum.compare(i,1,"1")==0 && carry==0) {
                checksum.replace(i,1,"1");
                carry=0;
            }
            else if (checksum.compare(i,1,"0")==0 && carry==1) {
                checksum.replace(i,1,"1");
                carry=0;
            }
            else if (checksum.compare(i,1,"1")==0 && carry==1) {
                checksum.replace(i,1,"0");
                carry=1;
            }
        }
    }

    cout<<"On accounting for carry: "<<checksum<<endl;

    for(int i=0; i<checksum.size(); i++) {
        if (checksum.compare(i,1,"1")==0)
            checksum.replace(i,1,"0");
        else
            checksum.replace(i,1,"1");
    }
    cout<<"On complementing (i.e. checksum): "<<checksum<<endl;
    return checksum;
}

string sender(string byte1, string byte2)
{
    string m = chksum(byte1, byte2);
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

void receiver(string byte1, string byte2, string checksum)
{
    string m = chksum(byte1, byte2);
    int flag=0;
    for (int i=0; i<checksum.size(); i++)
    {
        if ((checksum.compare(i,1,"1")==0 && m.compare(i,1,"0")==0) || (checksum.compare(i,1,"0")==0 && m.compare(i,1,"1")==0)) {
            flag =1;
            break;
        }
    }

    if (flag==0)
        cout<<"\nNo error detected"<<endl;
    else
        cout<<"\nError detected"<<endl;
}

int main()
{
    string byte1, byte2;
    int p1;
    cout<<"Enter byte 1 of data to send: ";
    cin>>byte1;
    cout<<"\nEnter byte 2 of data to send: ";
    cin>>byte2;
    string checksum = sender(byte1, byte2);
    cout<<"\nEnter error index for byte1 (-1 for no error): ";
    cin>>p1;
    byte1=adderror(byte1, p1);
    cout<<"Error incorporated."<<endl;
    cout<<"\nReceived message: "<<endl;
    cout<<"Byte1: "<<byte1<<endl;
    cout<<"Byte2: "<<byte2<<endl;
    cout<<"Checksum: "<<checksum<<endl;
    receiver(byte1, byte2, checksum);

    return 0;
}

