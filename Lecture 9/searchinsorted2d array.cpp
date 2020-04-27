// searchinsorted2d array
#include <iostream>
using namespace std;

void search(int a[][4],int row,int col,int key){
	int statr=0;
	int statc=col-1;
	while(statr<row && statc>=0){
		if(a[statr][statc]==key){
			cout<<"Found the element at index "<<statr<<" "<<statc;
			return;
		}
		else if(key>a[statr][statc]){
			statr++;
		}
		else{
			statc--;
		}
	}
	cout<<"Elemet not found";
	
}






int main()
{
	
	int a[4][4]={

		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};

	int key=14;
	search(a,4,4,key);
	return 0;
}