#include <iostream>
#include <fstream>
using namespace std;
int *regrow(int*,int,int);
void copy(int *, int *, int);
bool armstrong(int);
void display(int*,int);

int main()
{
    ifstream fin("data.txt");
    int *ptr=nullptr;
    int *arm_strong=nullptr;
    int num=0;
    int size=0;
    int n_size=0;
    if(!fin.eof())
    {
        while(fin>>num)
        {
            ptr=regrow(ptr,size,num);
            size++;
        }
        fin.close();
        for(int i=0;i<size;i++)
        {
            if(armstrong(ptr[i])==true)
            {
                arm_strong=regrow(arm_strong,n_size,ptr[i]);
                n_size++;
            }
        }
        delete[]ptr;
        ptr=nullptr;
        display(arm_strong,n_size);
        delete[]arm_strong;
        arm_strong=nullptr;
    }
    else
    {
        cout<<"Error Opening in File."<<endl;
    }
    return 0;
}
int * regrow(int *old_a, int size,int num)
{
    int *temp=nullptr;
    if(size==0)
    {
        old_a=new int[1];
        old_a[size]=num;
        return old_a;
    }
    else
    {
        temp=new int[size+1];
        copy(old_a,temp,size);
        temp[size]=num;
        delete[] old_a;
        old_a=nullptr;
        return temp;
    }
}
void copy(int *old_a, int *new_a, int s)
{
    for(int i=0;i<s;i++)
    {
        new_a[i]=old_a[i];
    }
}
bool armstrong(int value)
{
    int original=0;
    int temp=0;
    int sum=0;
    original=value;
    while(original!=0)
    {
        temp=original%10;
        sum=sum+(temp*temp*temp);
        original=original/10;
        
    }
    if(sum==value)
    {
       return true;
    }
    else
    {
        return false;
    }
}
void display(int *ptr,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<ptr[i]<<" ";
    }
}
