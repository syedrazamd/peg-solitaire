#include <bits/stdc++.h>
#include <emscripten.h>
EMSCRIPTEN_KEEPALIVE
extern "C" {
using namespace std;
    int n;
    int pegs=0;
    bool solve(vector<vector<char>> &board,vector<vector<int>> &moves, int pegs) {
	if(pegs==1){
	    return true;
	}
		for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
				if(board[i][j]=='.' && i<n-2 && board[i+2][j]=='_' && board[i+1][j]=='.' ) {
				board[i][j]='_';
				board[i+1][j]='_';
				board[i+2][j]='.';
				moves.push_back({i,j});
				moves.push_back({i+2,j});
				pegs--;
                if(solve(board,moves,pegs)){
                    return true;
                }
                
				moves.pop_back();
				moves.pop_back();
				pegs++;
				board[i][j]='.';
				board[i+2][j]='_';
				board[i+1][j]='.';
                
			}
			if(board[i][j]=='.' && i>=2  && board[i-2][j]=='_' && board[i-1][j]=='.' ) {
				board[i][j]='_';
				board[i-1][j]='_';
				board[i-2][j]='.';
				moves.push_back({i,j});
				moves.push_back({i-2,j});
				pegs--;
				
				if(solve(board,moves,pegs)){
                    return true;
                }
				
				moves.pop_back();
				moves.pop_back();
				pegs++;
				board[i][j]='.';
				board[i-1][j]='.';
				board[i-2][j]='_';
				
			}
			if(board[i][j]=='.' && j<n-2 && board[i][j+1]=='.' && board[i][j+2]=='_') {
				board[i][j]='_';
				board[i][j+1]='_';
				board[i][j+2]='.';
				moves.push_back({i,j});
				moves.push_back({i,j+2});
				pegs--;
				if(solve(board,moves,pegs)){
                    return true;
                }
				
				moves.pop_back();
				moves.pop_back();
				pegs++;
				board[i][j]='.';
				board[i][j+1]='.';
				board[i][j+2]='_';
				
			}
			if(board[i][j]=='.' && j>=2 && board[i][j-2]=='_' && board[i][j-1]=='.') {
				board[i][j]='_';
				board[i][j-1]='_';
				board[i][j-2]='.';
				moves.push_back({i,j});
				moves.push_back({i,j-2});
				pegs--;
				if(solve(board,moves,pegs)){
                    return true;
                }
				
			    moves.pop_back();
				moves.pop_back();
				pegs++;
				board[i][j]='.';
				board[i][j-2]='_';
				board[i][j-1]='.';
				
			}
		}
	}
			return false;
}
int main()
{
    cin>>n;
    cout << "n = " << n << endl;
cout << "pegs = " << pegs << endl;
    if(n%2==0){
        cout<<"Not possible to get a single peg"<<endl;
    }
    else{
	vector<vector<char>> board(n,vector<char>(n));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if((j<=n/2-2 && i<=n/2-2) || (j>n/2+1 && i>n/2+1) || (j>n/2+1 && i<=n/2-2) || (j<=n/2-2 && i>n/2+1)) {
				board[i][j]='X';
			}
			else {board[i][j]='.';
            pegs++;
                 }
		}
	}
	board[n/2][n/2]='_';
	vector<vector<int>> moves;
        pegs-=1;
    bool ans=solve(board,moves,pegs);
    if(ans){
    for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<board[i][j];
		}
		cout<<endl;
	}
        int i=0;
	for(auto x:moves){
        if(i%2==0){
            cout<<"-->"<<endl;
        }
	    cout<<"("<<x[0]+1<<","<<x[1]+1<<")";
        i++;
	}
        
    }
    else cout<<"No solution found"<<endl;
    }
}
}