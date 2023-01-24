class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k==1){
            return n;
        }
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        int size=n,j=k,i=0;
        while(size>1){
            while(j>1 || arr[i]==0){
                if(arr[i]==0 && i==n-1)
                    i=0;
                else if(i==n-1){
                    i=0;
                    j--;
                }
                else if(arr[i]==0)
                    i++;
                else{
                    i++;
                    j--;
                }
            }
            arr[i]=0;
            j=k;
            size--;
        }
        int a;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                a=arr[i];
                break;
            }
        }
        return a;
    }
};
