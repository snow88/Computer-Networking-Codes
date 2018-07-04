#include<iostream>
using namespace std;

string encode(char sdelim, char edelim)
{
    string data, result;
    char sdar[2], edar[2], esc_sdar[3], esc_edar[3];
    cout<<"Enter the data "<<endl;
    cin>>data;

    sdar[0]=esc_sdar[0]=esc_sdar[1]=sdelim;
    edar[0]=esc_edar[0]=esc_edar[1]=edelim;
    sdar[1]=edar[1]=esc_sdar[2]=esc_edar[2]='\0';
    char addchar[2];
    result+=sdar;
    for(int i=0; i<data.length(); i++)
    {
        if(data[i]==sdelim)
            result+=esc_sdar;
        else if(data[i]==edelim)
            result+=esc_edar;
        else{
            addchar[0]=data[i];
            addchar[1]='\0';
            result+=addchar;
        }
    }
    result+=edar;
    cout<<"\nAfter charstuffing: "<<result<<endl;
    return result;
}

int decode(string data, char sdelim, char edelim)
{
    string result="";
    for(int i=1; i<data.length()-1; i++)
    {
        if(data[i]==sdelim || data[i]==edelim)
            {i++;
            result+=data[i];
            }
        else{
            result+=data[i];
        }
    }
    cout<<"\n"<<result<<endl;
    return 0;
}

int main()
{
    char sdelim, edelim;
    cout<<"Enter the starting delimiter "<<endl;
    cin>>sdelim;
    cout<<"Enter the ending delimiter "<<endl;
    cin>>edelim;
    string r=encode(sdelim, edelim);
    cout<<"\nOn decoding: ";
    decode(r, sdelim, edelim);
    return 0;
}
