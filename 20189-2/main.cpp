#include <iostream>

using namespace std;

int main()
{
    int n;
    int i;
    int j;
    int sum=0;
    cin>>n;
    int *a=new int[n];
    int *b=new int[n];
    int *c=new int[n];
    int *d=new int[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>b[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>c[i];
        cin>>d[i];
        for(j=0;j<n;j++)
        {
            if(a[j]<c[i])
            {
                if(b[j]>c[i])
                {
                if(b[j]<d[i])
                {
                    sum+=b[j]-c[i];
                }
                else
                {
                    sum+=d[i]-c[i];
                }
                }
            }
            else
            {
                if(d[i]>a[j]){
                if(b[j]<d[i])
                {
                    sum+=b[j]-a[j];
                }
                else
                {
                    sum+=d[i]-a[j];
                }
                }
            }
        }
    }
    cout<<sum;
}
