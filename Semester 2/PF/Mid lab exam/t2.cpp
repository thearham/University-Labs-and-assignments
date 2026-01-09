#include<iostream>
using namespace std;

int coffee_produced[5];
void ask_user();
int total_production(int []);
int min_production(int []);
void descending_order(int []);

int main(){	
    int op;
	char cont='y';
	
	cout << "\n1. Input coffee productions of 5 different countries.";
	cout << "\n2. Calculates the total production.";
	cout << "\n3. Display the minimum coffee production amongst 5 countries.";
	cout << "\n4. Sort productions in descending order"; 
	cout << "\n5. Exit";

	while(cont=='y'){
		cout<<"\nEnter any option : ";
		cin>>op;
		cout<<endl;
		
		if(op==1){
			ask_user();
		}
		else if(op==2){
			cout<<"Sum of Production : "<< total_production(coffee_produced);
		}
		else if(op==3){
			cout<<"The minimum production : "<< min_production(coffee_produced);
		}
		else if(op==4){
			descending_order(coffee_produced);
		}
		else if(op==5){
			cout<<"Exiting......";
			break;
			return 0;
		}
		else{
			cout<<"Invalid input.........";
		}
		cout<<endl;
		cout<<"Enter Y to continue : ";
		cin>>cont;
	}
    return 0;
}

void ask_user(){
	cout<<"Enter the amount of coffee production in tons : ";
    for(int i=0;i<5;i++){
        cin>>coffee_produced[i];
    }
    cout<<endl;
    cout<<"Prodeuction of cofee : ";
    for(int i=0;i<5;i++){
        cout<<coffee_produced[i]<<" ";
    }
}
int total_production(int array[]){
	int total = 0;
	for(int i = 0; i<5; i++){
		total += array[i];
	}
	return total;
}
int min_production(int array[]){
	int min = array[0];
    for(int i=1;i<5;i++){
        if(array[0]>=array[i]){
            min=array[i];
        }
    }
	return min;
}
void descending_order(int array[]){
	int temp = 0;
	for(int i=0;i<5;i++){
       for(int j=i+1;j<5;j++){
           if(array[i]<=array[j]){
               temp=array[i];
               array[i]=array[j];
               array[j]=temp;
           }
       }
   }
   cout<<"production in decending order : ";
   for(int i = 0; i < 5; i++){
	   cout << array[i] << " ";
   }
}