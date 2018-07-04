#include<iostream>
#include<string>
using namespace std;

string generator_poly = "1001";
int r;

string sender(string m)
{
    string message = m;
    int size = message.size();
    r = generator_poly.size() - 1;
    string appendzeros="";
    for (int i=0; i<r; i++)
        appendzeros+="0";
    message+=appendzeros;
    cout<<"\nAfter appending zeros: "<<message<<endl;

    //divide
    for(int i=0; i<m.size(); i++)
    {
        if(message.compare(i,1,"1")==0) {
                for(int j=0,k=i; j<generator_poly.size(); j++,k++)
                {
                    if((message.compare(k,1,"1")==0 && generator_poly.compare(j,1,"1")==0) ||
                       (message.compare(k,1,"0")==0 && generator_poly.compare(j,1,"0")==0))
                        {
                            message.replace(k,1,"0");
                        }
                    else {
                            message.replace(k,1,"1");
                    }
                }
        }
        else {
            continue;
        }
    }

    cout<<"\nAfter division: "<<message;

    string crc="";
    for(int j=m.size(); j<m.size()+r; j++)
        crc+=message[j];
    cout<<"\nCRC: "<<crc;

    string transmit=m+crc;
    cout<<"\nTransmitted data: "<<transmit<<endl;
    return transmit;
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

void receiver(string message)
{
    cout<<"\nReceived data: "<<message;

    //divide
    for(int i=0; i<message.size()-r; i++)
    {
        if(message.compare(i,1,"1")==0) {
                for(int j=0,k=i; j<generator_poly.size(); j++,k++)
                {
                    if((message.compare(k,1,"1")==0 && generator_poly.compare(j,1,"1")==0) ||
                       (message.compare(k,1,"0")==0 && generator_poly.compare(j,1,"0")==0))
                        {
                            message.replace(k,1,"0");
                        }
                    else {
                            message.replace(k,1,"1");
                    }
                }
        }
        else {
            continue;
        }
    }

    cout<<"\nRemainder on division: "<<message<<endl;
    int flag=0;
    for(int i=0; i<message.size(); i++)
        if (message.compare(i,1,"1")==0) {
            flag=1;
            break;
        }
    if(flag==0)
        cout<<"\nNo error detected in received message."<<endl;
    else
        cout<<"\nError has been detected in received message."<<endl;
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
