// spiral print
#include <iostream>
using namespace std;

void spiralprint(int a[][4],int row,int col){
	int start_row=0;
	int start_col=0;
	int end_row=row-1;
	int end_col=col-1;

	int noofelementprinted=0;

	while(noofelementprinted<row*col){
		//st left to right
		for(int i=start_col;i<=end_col;i++){
			cout<<a[start_row][i]<<" ";
			noofelementprinted++;
		}
		start_row++;

		if(noofelementprinted==row*col){
			break;
		}

		//top to down
		for(int i=start_row;i<=end_row;i++){
			cout<<a[i][end_col]<<" ";
			noofelementprinted++;
		}

		end_col--;
		if(noofelementprinted==row*col){
			break;
		}

		//right to left
		for(int i=end_col;i>=start_col;i--){
			cout<<a[end_row][i]<<" ";
			noofelementprinted++;
		}

		end_row--;
		if(noofelementprinted==row*col){
			break;
		}

		//downn to top
		for(int i=end_row;i>=start_row;i--){
			cout<<a[i][start_col]<<" ";
			noofelementprinted++;
		}
		start_col++;

	}
}



int main()
{
	int a[4][4]={

		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};

	spiralprint(a,4,4);

	
	return 0;
}