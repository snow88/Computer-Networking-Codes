#include<iostream>
#include<string.h>
using namespace std;

char str[30];
string dictionary[100];
int idx = -1;
int result[30];
int r = -1;

int searchdictionary(string str)
{
    for (int i=0; i<=idx; i++)
    {
        if (dictionary[i].compare(str) == 0)
            return i;
    }
    return -1;
}

void compress(char str[])
{
    string p = "";
    for (int k=0; k<=strlen(str); k++)
    {
        string temp = p + str[k];
        int i = searchdictionary(temp);
        if (i != -1)
        {
            p = temp;
        }
        else
        {
            r++;
            result[r] = searchdictionary(p);
            if (k!=strlen(str))
            {
                idx++;
                dictionary[idx] = temp;
            }
            p = str[k];
        }
    }

    cout<<"\nAfter compression:"<<endl;
    for (int i=0; i<=r; i++)
        cout<<result[i]<<" ";

    cout<<"\n\nDictionary:"<<endl;
    for (int i=0; i<=idx; i++)
    {
        cout<<i<<"      "<<dictionary[i]<<endl;
    }
}

void decompress(int result[])
{
    cout<<"\nOn decompressing:"<<endl;
    for (int i=0; i<=r; i++)
        cout<<dictionary[result[i]];
    cout<<endl;
}

int main()
{
    int n;
    string ch;
    cout<<"Enter the number of different characters used in the string"<<endl;
    cin>>n;
    cout<<"Enter the different characters one-by-one"<<endl;
    for (int i=0; i<n; i++)
    {
        cin>>ch;
        idx++;
        dictionary[idx] = ch;
    }
    cout<<"Enter input string"<<endl;
    cin>>str;

    compress(str);
    decompress(result);

    return 0;
}
