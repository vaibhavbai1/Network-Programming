#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"enter frame size: ";
    cin>>size;
    int p[size];
    int i=0, count=0;
    cout<<"enter frame bits: "<<endl;
    for(i=0;i<size-1;i++){
        cin>>p[i];
        if(p[i]==0 || p[i]==1){
           continue;
        }
        else{
            cout<<"ERROR"<<endl;
            return 0;
        }
        
    }

    cout<<"Input Frame:  ";
    for(i=0;i<size-1;i++){
        cout<<p[i]<<"   ";
    }
    cout<<endl;

    for(i=0;i<size-1;i++){
        if(p[i]==1){
            if(p[i]==p[i+1] || p[i]==p[i-1]){
                count++;
                if(count==5){
                    break;
                }
            }
        }
        else{
            count=0;
        }
    }
    
    if(count!=5){
        cout<<"No bit stuffing"<<endl;
        cout<<"Output Frame: ";
        for(i=0;i<size-1;i++){
            cout<<p[i]<<"   ";
        }
        return 0;
    }

    for(int j=size-2;j>=1+i;j--){
        p[j+1]=p[j];
    }
    p[i+1]=0;

    cout<<"Output Frame: ";
    for(i=0;i<size;i++){
        cout<<p[i]<<"   ";
    }
    return 0;
}