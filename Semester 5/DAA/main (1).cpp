#include <iostream>
using namespace std;

void swapIt(char &a,char &b)
{
    char temp=a;
    a=b;
    b=temp;
}
int findKeys(char arr[],char arrkey[],int size)
{
    arrkey[4]='\0';
    arrkey[0]=arr[0];
    int count=0;
    bool flag=true;
    for(int i=1;i<size;i++)
    {
        if(arrkey[4]!='\0') break;
        else
        {
            for(int j=0;j<=count;j++)
            {
                if(arrkey[j]==arr[i])
                {
                    flag=false;
                    break;
                }
                else
                {
                    flag=true;
                }    
            }
        }
        if(flag==true)
        {
            arrkey[++count]=arr[i];
        }
    }
    return count+1;
}
void bubbleSort(char arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void sortArray(char arr[],char arrkey[],int size,int count)
{
    int key1=-1,key2=-1,key3=-1,key4=-1;
    for(int i=0;i<size;i++)
    {
        
        if(arr[i]==arrkey[0])
        {
            if(count>4)
            {
                key4++;
                swapIt(arr[i],arr[key4]);
            }
            if(count>3)
            {
                key3++;
                swapIt(arr[key3],arr[key4]);
            }    
            if(count>2)
            {
                key2++;
                swapIt(arr[key2],arr[key3]);
            }
            if(count>1)
            {    
                key1++;
                swapIt(arr[key1],arr[key2]);
            }
        }
        if(count)
        if(arr[i]==arrkey[1])
        {
            if(count>4)
            {
                key4++;
                swapIt(arr[i],arr[key4]);
            }
            if(count>3)
            {
                key3++;
                swapIt(arr[key3],arr[key4]);
            }    
            if(count>2)
            {
                key2++;
                swapIt(arr[key2],arr[key3]);
            }
        }
        else if(arr[i]==arrkey[2])
        {
            if(count>4)
            {
                key4++;
                swapIt(arr[i],arr[key4]);
            }
            if(count>3)
            {
                key3++;
                swapIt(arr[key3],arr[key4]);
            }    
        }
        else if(arr[i]==arrkey[3])
        {
            if(count>4)
            {
                key4++;
                swapIt(arr[i],arr[key4]);
            }
        }
        else
        {
            continue;
        }
        
    }
}
void displayArray(char arr[],int size)
{
    for(int j=0;j<size;j++)
    {
        cout<<arr[j]<<" ";
    }
}
int main()
{
    const int N=5;
    char arr[N]={'X','Y','A','B','B'};
    char arrkey[5];
    int count=findKeys(arr,arrkey,N);
    cout<<"This is the unsorted input array \n";
    displayArray(arrkey,N);
    cout<<"\nThis is the array of keys found from the input array \n";
    displayArray(arrkey,count);
    cout<<"\nThis is the sorted array of keys \n";
    bubbleSort(arrkey,count);
    displayArray(arrkey,count);
    sortArray(arr,arrkey,N,count);
    cout<<"\nThis is the sorted input array \n";
    displayArray(arr,N);
    
    return 0;
}
