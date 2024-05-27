
#include<iostream>
using namespace std;
int main(){
    int x,y;
    cout<<"Enter x:";
    cin>>x; 
    cout<<"Enter y:";
    cin>>y; 
    if(x>=0 && y>=0){
        if(x>y)
            cout<<"1st";
        else
            cout<<"2nd";
    }
    else if(x<0 && y>=0){
        if(-x>y)
            cout<<"4th";
        else
            cout<<"3rd";
    }
    else if(x<0 && y<0){
        if(x>y)
            cout<<"6th";
        else
            cout<<"5th";
    }
    else{
        if(x>-y)
            cout<<"8th";
        else
            cout<<"7th";
    }
    return 0;
}
