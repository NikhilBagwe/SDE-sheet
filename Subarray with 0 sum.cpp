// BRUTE =======================================================================================================================================

int main()
{
    int a[]={4,2,-3,1,6};
    int n=5;
    
    int curSum=0;
    
    for(int i=0; i<n; i++){
        if(a[i] == 0){
            cout<<"yes";
            break;
        }
        // add the ith element to curSum
        curSum += a[i];
        for(int j=i+1; j<n;j++){
            // then add all the remaining elemnts to the right of ith element to curSum and check when curSum==0
            curSum += a[j];
            if(curSum == 0){
                cout<<"yes";
                break;
            }
        }
        curSum = 0;
    }

    return 0;
}
