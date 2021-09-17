class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void swap1(int &a, int &b){
        int temp=a;
        a=b;
        b=temp;
    }

    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        // code here 
        int n=arr.size();
        int l=0, r=n-1;
        
        int i=0;
        for(i=0; i<=r; i++){
            
            if(arr[i] < a){
                swap1(arr[i], arr[l]);
                l++;
            }
            
            else if(arr[i] > b){
                swap1(arr[i], arr[r]);
                r--;
                // we are doing i--, as on swaping we have to check that arr[r] element is less than 'a' or not i.e the above 'if' condition
                i--;
            }
        }
    }
};
