#include<iostream>
#define MAX 999
using namespace std;

int v;
int g[20][20];
int d[20];
int par[20];
int visited[20];

void print_lsp()
{
    cout<<"Link State Packets,"<<endl;
    for (int i=0; i<v; i++)
    {
        cout<<"For router "<<i<<":"<<endl;
        for (int j=0; j<v; j++)
            cout<<j<<"   "<<g[i][j]<<endl;
        cout<<endl;
    }
}

void print_lsdb()
{
    cout<<"Link State DataBase,"<<endl;
    for (int i=0; i<v; i++)
        cout<<"   "<<i;
    cout<<"\n-------------------"<<endl;
    for (int i=0; i<v; i++)
    {
        cout<<i<<"| ";
        for (int j=0; j<v; j++)
            cout<<g[i][j]<<"   ";
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

 int minkey()
 {
     int min=MAX, pos;
     for (int i=0; i<v; i++)
     {
         if(d[i]<min && visited[i]==0)
            {
                min=d[i];
                pos=i;
            }
     }
     return pos;
 }


void dijkstra(int s)
{
    cout<<endl;
    print_lsp();

    cout<<endl;
    print_lsdb();

    for (int i=0; i<v; i++)     //initialize
    {
        par[i]= -1;
        visited[i]=0;
        if (i==s)
            d[i]=0;
        else
            d[i]=MAX;
    }

    for (int k=0; k<v; k++)
    {
        int u= minkey();
        visited [u]=1;
        for (int j=0; j<v; j++)
        {
            if (g[u][j]+d[u]<d[j])
            {
                d[j]=d[u]+g[u][j];
                par[j]=u;
            }
        }
    }

    cout<<"\nAfter exchanging of all link state packets,"<<endl;
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
    dijkstra(s);

    return 0;
}
