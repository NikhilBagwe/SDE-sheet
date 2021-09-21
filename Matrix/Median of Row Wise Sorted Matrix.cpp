int main()
{
    int r = 3, c = 3;
    vector<vector<int>> matrix {{1, 3, 5},
                                {2, 6, 9},
                                {3, 6, 9}};

    // 
    int startVal=0,endVal=2000,midVal=0;
    int n=r*c;
    
    while(startVal<=endVal)
    {
        midVal=(endVal+startVal)/2;
        int ans=0;
        cout<<"startVal: "<<startVal<<" "<<"midVal: "<<midVal<<" "<<"endVal: "<<endVal<<endl;
        
        // Find the 'ans' for each row so to find how many elements are present that are less than or equal to midVal
        for(int i=0;i<r;i++)
        {
            // Apply binary search for each row
            int l=0,h=c-1;
            while(l<=h)
            {
                // this formula is used when we apply binary search on index instead of applying it on numbers present on those index
                int m=l+(h-l)/2;
                if(matrix[i][m]<=midVal) l=m+1;
                else h=m-1;
            }
            ans+=l; // It's small 'L' not 1 so dont do ans++.
            cout<<ans<<" ";
        }
        cout<<endl;
        if(ans<=n/2) startVal=midVal+1; // if(ans <= 4)
        else endVal=midVal-1;
    }
  
    // when startval and endVal becomes same we get the median
    cout<<startVal;
    return 0;
}
