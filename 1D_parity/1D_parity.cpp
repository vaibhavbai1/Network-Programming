#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"enter frame size: ";
    cin>>size;
    int p[size];
    int i=0, count=0;
    int parity;
    cout<<"enter frame bits: "<<endl;
    for(i=0;i<size-1;i++){
        cin>>p[i];
        if(p[i]==0 || p[i]==1){
            if(p[i]==1){
                count++;
            }
            continue;
        }
        else{
            cout<<"ERROR"<<endl;
            return 0;
        }
    }
    cout<<"enter 0 for odd parity and 1 for even parity: ";
    cin>>parity;

    cout<<"Input Frame:  ";
    for(i=0;i<size-1;i++){
        cout<<p[i]<<"   ";
    }
    cout<<endl;
    
    if(parity==1){
        if(count%2==0){
            p[size-1]=0;
        }
        else{
            p[size-1]=1;
        }
    }
    else if(parity==0){
        if(count%2!=0){
            p[size-1]=0;
        }
        else{
            p[size-1]=1;
        }
    }
    else{
        cout<<"wrong input"<<endl;
        return 0;
    }
    
    cout<<"Output Frame: ";
    for(i=0;i<size;i++){
        cout<<p[i]<<"   ";
    }
    return 0;
}



