#include <iostream> 
#include <vector> 
using namespace std;
// Hàm Bubble Sort
void bubbleSort(vector<int>&arr){
    int n=arr.size();
    bool swapped;
    for (int i=0; i<n-1;i++){
        swapped=false;
        for (int j =0; j<n-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=true;
            }
        }
        if (!swapped)
        break;
    }
}
int main(){
    vector<int>arr={5,2,9,1,5};
    bubbleSort(arr);
    cout<<"Ket qua sau BubbleSort: ";
    for(int x:arr) cout<<x<<"";
    cout<<endl;
    return 0;
}