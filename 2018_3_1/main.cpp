#include <iostream>
using namespace std;

int main()
{
    int num,times=2,sum=0;
    while(1)
    {
        cin>>num;
        if(num==1)
        {
            times=2;
            sum+=num;
        }
        else if(num==2)
        {
            sum+=times;
            times+=2;
        }
        else if(num==0)
        {
            break;
        }
    }
    cout<<sum;
}
