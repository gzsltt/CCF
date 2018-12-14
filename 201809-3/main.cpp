#include <iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main()
{
    int row,selectnum;
    cin>>row>>selectnum;
    getchar();
    int i,j,k;
    string* text=new string[row];
    int sum;
    int *num=new int[100];
    for(i=0;i<row;i++)
    {
        getline(cin,text[i]);
    }
    string* selector=new string[selectnum];
    for(i=0;i<selectnum;i++)
    {
        getline(cin,selector[i]);
    }
    for(i=0;i<selectnum;i++)
    {
        sum=0;
        for(j=0;j<row;j++)
        {
            string::size_type contain=text[j].find(selector[i]);
            string::size_type div=selector[i].find("div");
            if(contain!=string::npos)
            {
                num[sum]=j+1;
                sum+=1;
            }
        }
        cout<<sum;
        for(k=0;k<sum;k++)
        {
            cout<<" "<<num[k];
        }
        cout<<endl;
}
}
