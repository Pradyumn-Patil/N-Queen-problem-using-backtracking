#include <bits/stdc++.h>
#include <chrono>
using namespace std;

vector< pair<int,int> > vec;
int n,total_count=0,mat[1009][1009]={0};

bool check (int r1,int c1,int r2,int c2){	
	
	if(r1+c1 == r2+c2 || r1-c1 == r2-c2)
		return false;
	if(r1==r2 || c1==c2)
		return false;
		
	return true;
}

void printit(){
	cout << endl;
	memset(mat,0,sizeof(mat));
	for(int i=0; i<n; i++)
		mat[vec[i].first][vec[i].second]=1;
		
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout << mat[i][j]<<" ";
		cout << "\n";
	}
}

void solve(int col){
	
	for (int i=0; i<n; i++){		//trying on different rows
	
		int ch=1;
		
		for (int j=0; j<col; j++){	//checking with previosly placed queens
			if( !check(vec[j].first, vec[j].second, i, col) ){
				ch=0;
				break;
			}
		}		
		if	(ch) {		// if no problem with previously placed queens
			vec[col]=make_pair(i,col);
			if(col == n-1){
				total_count++;
				printit();
			}
			else
				solve( col+1 );	
		}
	}
}

int main(){
	
	cin >> n;
	auto t1 = std::chrono::high_resolution_clock::now();
	vec.resize(n);
	cout << "The possible combinations are:\n";
	solve(0);
    auto t2 = std::chrono::high_resolution_clock::now();
	cout << "\nTotal combinations are " << total_count << endl;
    auto dur = t2 - t1;
    float time = dur.count() ;
    cout<<"execution time = "<<time/1000000000<<" seconds"<<endl ;
    return 0;
}