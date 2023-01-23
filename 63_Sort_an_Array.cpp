
vector <int> arr(50001);

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
    void mergeSort(vector <int> &nums,int l,int h){
        if(l<h){
            int mid=l+(h-l)/2;
            mergeSort(nums,l,mid);
            mergeSort(nums,mid+1,h);
            merge(nums,l,mid,h);
        }
    }
    void merge(vector <int> &nums,int l,int mid,int h){
        int i=l;
        int j=mid+1;
        int k=l;
        while(i<=mid && j<=h){
            if(nums[i]<=nums[j])
                arr[k++]=nums[i++];
            else
                arr[k++]=nums[j++];
        }
        while(i<=mid)
            arr[k++]=nums[i++];
        while(j<=h)
            arr[k++]=nums[j++];
        for(int y=l;y<=h;y++)
            nums[y]=arr[y];
    }
};
