#include<iostream>
using namespace std;

string encode()
{
    int count=0;
    string data, result, delim="01111110";
    cout<<"Enter data"<<endl;
    cin>>data;
    result+=delim;
    for(int i=0; i<data.length(); i++)
    {
        if(data[i]=='1')
            count++;
        else
            count=0;
        result+=data[i];
        if(count==5)
        {
            result+="0";
            count=0;
        }
    }
    result+=delim;
    cout<<"On encoding: "<<result;
    return result;
}

int decode(string data)
{
    int count=0;
    string result, delim="01111110";
    for(int i=8; i<data.length()-8; i++)
    {
        if(data[i]=='1')
            count++;
        else
            count=0;
        result+=data[i];
        if(count==5)
        {
            i++;
            count=0;
        }
    }
    cout<<"On decoding: "<<result<<endl;
    return 0;
}

int main()
{
    string r=encode();
    cout<<"\nSent above data ..."<<endl;
    decode(r);
    return 0;
}
