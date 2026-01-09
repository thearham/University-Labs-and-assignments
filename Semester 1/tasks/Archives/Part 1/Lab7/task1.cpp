#include<iostream>
using namespace std;
int main(){
    int n1,n2;
    cout<<"input number 1: ";
    cin>>n1;
    cout<<"input number 2: ";
    cin>>n2;
    cout<<"Even number between " << n1 <<" and " << n2<< " are: " << endl;
    for(int i=n1;i<=n2; i++){
        if(i%2==0){
          cout<<i << endl;
          
        }
    }
    
	system("pause");
    return 0;
}