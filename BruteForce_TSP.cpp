#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int Row = 20;
const int Column = 20;
int Path[Row][Column];
bool Vertex[Row];

void InitPath(int init){
    for(int i = 0; i < Row; i++) {
		for(int j = 0; j < Column; j++) {
			Path[i][j] = init;
		}
	}
}

void addPath(char p1, char p2,int cost){
    Path[p1-'A'][p2-'A'] = cost;
    Path[p2-'A'][p1-'A'] = cost;
    Vertex[p1-'A'] = true;
    Vertex[p2-'A'] = true;
}

void TSP_BF(int Path[Row][Column], int start) {
	vector<int> V;
	vector<int> ans;
    int min_cost = INT_MAX;

    for(int i = 0;i < Row;i++){
        if(Vertex[i] && i != start){
            V.pb(i);
	}
    }
	do {
		bool flag = true;
			int curr_cost = 0;
			int temp = start;
			for (int i = 0; i < V.size() && flag; i++){
				if(Path[temp][V[i]] != -1){
					curr_cost += Path[temp][V[i]];
				    	temp = V[i];
		    		}else{
					flag = false;
		   		}
			}
		if(Path[temp][start] != -1 && flag){
		    curr_cost += Path[temp][start];
		    if(min_cost > curr_cost){
			min_cost = curr_cost;
			ans = V;
		    }
		}
	} while (next_permutation(V.begin(), V.end()));

    cout<<"Path : "<< char(start+'A') <<" ";
    for(auto i : ans)
        cout<< char(i+'A')<<" ";
    cout<<char(start+'A')<<endl;
	cout << "Cost : " << min_cost;
}

int main(){
    InitPath(-1);
    addPath('S','A',6);
    addPath('S','B',14);
    addPath('S','C',10);
    addPath('A','B',6);
    addPath('A','D',24);
    addPath('B','C',4);
    addPath('B','E',15);
    addPath('C','F',18);
    addPath('D','E',4);
    addPath('E','F',4);
    addPath('D','G',9);
    addPath('E','G',9);
    addPath('F','G',9);
    TSP_BF(Path, 'S'-'A');
    return 0;
}
