#include <iostream>

using namespace std;

int main()
{
    int n,l,t;
    cin>>n>>l>>t;
    int *speed=new int[n];
    int *position=new int[n];
    int i,j,k,q;
    for(i=0;i<n;i++)
    {
        speed[i]=1;
        cin>>position[i];
    }
    for(i=0;i<t;i++)
    {
        for(j=0;j<n;j++)
        {
            if(position[j]==0||position[j]==l)
            {
                speed[j]=-speed[j];
            }
            for(q=0;q<n;q++)
            {
            if((position[j]==position[q])&&j!=q)
            {
                speed[j]=-speed[j];
            }
            }
        }
          for(k=0;k<n;k++)
    {
        position[k]+=speed[k];
    }
    }
              for(k=0;k<n;k++)
    {
        cout<<position[k]<<" ";
    }
}
