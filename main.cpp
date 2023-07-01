#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double Support(int arr1[10],int arr2[10],int n){
    int intersect =0;
    float s=0.0;
    for(int i=0 ;i<n ; i++){
        if(arr1[i]==1 && arr2[i]==1)
            intersect = intersect+1;
    }
    s =(float)intersect/(float)n;
    return s;

};

double Confidence(int arr1[10],int arr2[10],int n){
    float intersect =0;
    float s=0.0;
    float length = 0.0;
    for(int i=0 ;i<n ; i++){
        if(arr1[i]==1 && arr2[i]==1)
            intersect = intersect+1;
    }
    for(int i=0;i<n ; i++){
        if(arr1[i]==1){
            length = length+1;
        }
    }
    s =intersect/length;
    return s;
};
double Lift(int arr1[10],int arr2[10],int n){
    float intersect =0;
    float s=0.0;
    float length1 = 0.0;
    float length2 = 0.0;
    for(int i=0 ;i<n ; i++){
        if(arr1[i]==1 && arr2[i]==1)
            intersect = intersect+1;
    }
    for(int i=0;i<n ; i++){
        if(arr1[i]==1){
            length1 = length1+1;
        }
    }
    for(int i=0;i<n ; i++){
        if(arr2[i]==1){
            length2 = length2+1;
        }
    }
    float Len =length1 *length2;
    s =intersect *n;
    float result = s /Len;
    return result;
};
int main(){
  int milk[10];
  int egg[10];
  int apple[10];
  int bread[10];
  int n;
  cout<<"Enter the number of customer: ";
  cin >> n;
  cout<<"Enter data:"<<endl;
  cout<< "id Milk Egg Apple Bread "<<endl;
  for(int i=0 ;i<n ; i++){
    cout<<" ID"<<i<<" ";
    cin>>milk[i]; cin>>egg[i]; cin>>apple[i]; cin>>bread[i];
  }
  cout<<"Support = " << Support(milk,egg,n)<<endl;
  cout<<"Confidence = " << Confidence(milk,egg,n)<<endl;
  cout<<"Lift = " << Lift(milk,egg,n)<<endl;
  return 0;
}
