#include<iostream>
#define MAX 999                  //to map infinity
using namespace std;

int v;
int g[20][20];
int d[20];                          //storing min. distance path for a node
int par[20];                      //parent of a router to print min path

void printdistancevector()
{
    cout<<"Distance Vectors,"<<endl;
    for (int i=0; i<v; i++)
    {
        cout<<"For router "<<i<<":"<<endl;
        for (int j=0; j<v; j++)
            cout<<j<<"   "<<g[i][j]<<endl;
        cout<<endl;
    }
}

void printpath(int s)
{
    cout<<"\n\nMinimum cost paths from source router "<<s<<":"<<endl;
    for (int i=0; i<v; i++)
    {
        if (i==s)
            continue;

        int dest=i;   //destination
        cout<<dest;
        while(par[dest]!=-1)
        {
            cout<<"<-"<<par[dest];
            dest=par[dest];
        }
        cout<<"\nCost: "<<d[i]<<endl;
        cout<<endl;
    }
}

void bellmanford(int s)
{
    cout<<endl;
    printdistancevector();

    for (int i=0; i<v; i++)     //initialize
    {
        par[i]= -1;
        if (i==s)
            d[i]=0;
        else
            d[i]=MAX;
    }

    for (int m=0; m<v; m++)         //compute final min cost array
    {
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<v; j++)         // for each edge i->j
            {
                if (d[j] > d[i] + g[i][j])
                {
                    d[j] = d[i] + g[i][j];
                    par[j]=i;
                }
            }
        }
    }

    cout<<"\nAfter exchanging of all distance vectors,"<<endl;
    cout<<"d"<<endl;
    for(int i=0; i<v; i++)
        cout<<d[i]<<" ";
    cout<<"\npar"<<endl;
    for(int i=0; i<v; i++)
        cout<<par[i]<<" ";

    printpath(s);
}

int main()
{
    cout<<"Enter no. of routers (nodes)"<<endl;
    cin>>v;
    cout<<"Enter link information"<<endl;
    int k;
    for (int i=0; i<v; i++)
    {
        cout<<"For router "<<i<<":"<<endl;
        for (int j=0; j<=i; j++)              //symmetric matrix
        {
            if (i==j)
                g[i][j]=0;
            else
            {
                cout<<"If router "<<i<<" is connected to router "<<j<<", enter cost of link, else enter -1:"<<endl;
                cin>>k;
                if (k==-1) {
                    g[i][j]=MAX;
                    g[j][i]=MAX;
                }
                else {
                    g[i][j]=k;
                    g[j][i]=k;
                }
            }
        }
    }

    int s;
    cout<<"\nEnter source router"<<endl;
    cin>>s;
    bellmanford(s);

    return 0;
}

