#include <iostream>
using namespace std;


void colwaveprint(int a[3][5],int row,int col){
	for(int i=0;i<col;i++){
		if(i%2==0){
			//eve
			for(int j=0;j<row;j++){
				cout<<a[j][i]<<" ";
			}
		}
		else{
			for(int j=row-1;j>=0;j--){
				cout<<a[j][i]<<" ";
			}
		}
	}
}

int main()
{
	int a[3][5]={

		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};
	colwaveprint(a,3,5);

	
	return 0;
}