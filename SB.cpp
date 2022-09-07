#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> boxes(32, vector<int>(12));
int final[32];
int point[32];
int length[32];
int tail;
int k, dimensions;

int LIS(){
    int max_l = -1;
    for (int i = 0; i < k; i++){
        for (int j = 0; j < i; j++){
            bool br = false;
            for (int k = 0; k < dimensions && !br; k++){
                if (boxes[i][k]<=boxes[j][k])       
                {
                    br = true;
                }
                
            }
            if(!br){
                if(length[i] < length[j]+1){
                    length[i] = length[j]+1;
                    point[i] = j;
                }
            }
            
        }
        if(max_l < length[i]){
            tail = i;
            max_l =  length[i];
        }
        
    }

    return max_l;
    
}

void back_trace(int max){
    while(tail != -1){
        final[max-1] = boxes[tail][dimensions]+1;
        tail =  point[tail];
        max--;
        if (max<=0){
            break;
        }
        
    }
}

bool cp(vector<int> &a, vector<int> &b){
    return a.front()<b.front();
}

int main(){
    int tmp;
    while (cin>>k>>dimensions){
        for(int i = 0; i<k; i++){
            point[i] = -1;
            length[i] = 1;
            for (int j = 0; j < dimensions; j++){
                cin >> boxes[i][j];
            }
            sort(boxes[i].begin(), boxes[i].begin()+dimensions);
            boxes[i][dimensions] = i;
            
        }
        sort(boxes.begin(), boxes.begin()+k, cp);
        int max = LIS();
        back_trace(max);
        cout<<max<<endl;
        for (int i = 0; i < max; i++){
            cout << final[i] << " ";
        }

        cout << endl;
        
    }

    return 0;
    
}