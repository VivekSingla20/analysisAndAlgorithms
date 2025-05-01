#include<bits/stdc++.h>
using namespace std;
int n,m;
int G[100][100];
int x[100];
bool Give(int k,int i){
    for (int j = 1; j <= n; j++) {
    if(G[k][j]&&x[j]==i) return false;
}
return true;
}

void mColouring(int k){
  for(int i = 1;i<=m;i++){
    if(Give(k,i)){
       x[k] = i;
       if(k==n){
        cout<<"Result:";
        for(int i =1;i<=n;i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
       }
       else{
        mColouring(k+1);
       }
        x[k]=0; 
    }
  
  }
}

int main(){
    
    cout<<"Enter the number of nodes:";
    cin>>n;
    cout<<"\nEnter the number of Colours:";
    cin>>m;
   
    cout << "Enter adjacency matrix (0/1 for edge presence):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                G[i][j] = 0; 
            } else {
                cout << "G["<<i<<","<<j<<"]:";
                cin >> G[i][j];
            }
        }
    }

    cout << "\nAll valid colorings:\n";
    mColouring(1);
   
    return 0;

}