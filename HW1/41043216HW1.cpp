#include <iostream>

using namespace std;
int acker(int m , int n){
    if(m == 0){
        return n + 1;
    }
    else if(n == 0 ){
        return acker(m - 1 , 1);
    }
    else{
        return acker(m - 1 , acker(m , n - 1));
    }
} 
int acker2(int m , int n){
	int **data; 
    data = new int*[m+1];
    for(int i = 0; i < m+1; i++)
        data[i] = new int[n+1];
// row for m , col for n
    for (int row = 0 ; row < m+1 ; row++){
        for (int col = 0 ; col <= n+1 ; col++){
            if(row == 0){                                   
                data[row][col] = col + 1;
                cout <<data[row][col]<< endl;
            }else if(col == 0 && row > 0){                         
                data[row][col] =data[row - 1][1];
                cout <<data[row][col]<< endl;
            }else{                    
                int tmp = data[row][col-1];                   
                int sum;
                 
                if (row-1 == 0){                                 
                    sum = tmp + 1;
                }else if (tmp <= n){                            
                    sum = data[row-1][data[row][col-1]];
                }else{                                         
                    sum = (tmp-n)*(row-1) + data[row-1][n];
                }
 
                data[row][col] = sum;
                cout <<data[row][col]<< endl;
            }
        }
    }
    return data[m][n];

    for(int i = 0; i < m; i++)
        delete [] data[i];
    delete [] data;
}
int binary(int bin[] , int len){
	bool flag = true;
	for(int i = 0 ; i < len ; i++){
    	if(bin[i] == 0){
    		flag = false;
		}
	}
	for(int i = len-1 ; i >= 0 ; i--){
		if(bin[i] == 0){
			bin[i] = 1;
			break;
		}
		else{
			bin[i] = 0;
		}
		
	}
	if(flag == false) return 0;
	else return 1;
}

int powerset(char arr[] , int len){
	int test = 0;
	int *bin;
	bin = new int[len];
	for(int i = 0 ; i < len ; i++){
    	bin[i] = 0;
	}
	do{
		cout <<"{";
		bool flag = false;
		for(int i = 0 ; i < len ; i++){
    		if(bin[i] == 1){
    			if(flag == true){
    				cout << ",";
				}
    			cout << arr[i];
    			flag = true;
			}
		}
		cout <<"}";
		test = binary(bin,len);
	}while(test == 0);
	
}
int main(void){
	int M = 0 , N = 0 , C = 0;
	cout << "enter M & N" << endl << "M:";
	cin >> M;
	cout << "N:";
	cin >> N;
    cout << acker(M,N) << endl;
    cout << acker2(M,N) << endl;
    cout << "enter the amount of element" << endl;
    cin >> C;
    cout << "enter the element one by one" << endl << "example: A(press enter) -> B(press enter) -> C(press enter)" << endl;
    char *arr;
    arr = new char[C];
    for(int i = 0 ; i < C ; i++){
    	cin >> arr[i];
	}
	powerset(arr,C);
    return 0;
}