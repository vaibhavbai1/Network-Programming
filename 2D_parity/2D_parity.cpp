#include<iostream>
using namespace std;
void add_parity(int &p , int parity, int count){
    if(parity==1){
        if(count%2==0){
            p=0;
        }
        else{
            p=1;
        }
    }
    else if(parity==0){
        if(count%2!=0){
            p=0;
        }
        else{
            p=1;
        }
    }
}
int main(){
    int size;
    cout<<"enter frame size: ";
    cin>>size;
    int p[size][size];
    int i=0, j=0, countR=0, countC=0;
    int parity;
    cout<<"enter frame bits: "<<endl;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-1;j++){
            cin>>p[i][j];
            if(p[i][j]==0 || p[i][j]==1){
                continue;
            }
            else{
                cout<<"ERROR"<<endl;
                return 0;
            }
        }
    }

    cout<<"enter 0 for odd parity and 1 for even parity: ";
    cin>>parity;
    if(parity==1 || parity==0){}
    else{
        cout<<"WRONG INPUT"<<endl;
        return 0;
    }

    cout<<"Input Frame:  "<<endl;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-1;j++){
            cout<<p[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(i=0;i<size-1;i++){
        countR=0;
        countC=0;
        for(j=0;j<size-1;j++){
            if(p[i][j]==1){
                countR++;
            }
            if(p[j][i]==1){
                countC++;
            }
        }
        add_parity(p[i][size-1],parity,countR);
        add_parity(p[size-1][i],parity,countC);
    }

    countR=0;
    countC=0;
    for(i=0;i<size-1;i++){
        if(p[size-1][i]==1){
            countR++;
        }
        if(p[i][size-1]==1){
            countC++;
        }
    }
    add_parity(p[size-1][size-1],parity,countR);
    add_parity(p[size-1][size-1],parity,countC);

    cout<<"Output Frame:  "<<endl;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            cout<<p[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}