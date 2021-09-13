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

// OPTIMAL =================================================== O(n) ============== HASHMAP ===============================================================

/*
LOGIC:
eg: a[]={4,2,-3,1,6}
1. At i=0, sum=4 [ WE ARE DOING PREFIX SUM]
2. at i=1, sum=6 
3. At i=2, sum=3 
4. At i=3, sum=4 -> map=[4 6 3 4]
   So now the same number is getting repeated. It means after ind=0 there were some elemnets that on adding to 
   sum, made the sum 0,and also gave the same number 4 on further iterations. So the if(map[sum]) returns true, meaning there is a subarray
   with sum=0.
*/

int main()
{
    int a[]={4,2,-3,1,6};
    int n=5;
    int sum=0, flag=1;
    
    // Store the result of prefix sum
    unordered_map<int, int> mp;
    
    for(int i=0; i<n; i++){
        sum += a[i];
        
        // mp[sum] -> means the the current sum value is already present in the map 
        if(sum==0 || a[i]==0 || mp[sum]){
            flag = 1;
            break;
        }
        
        // increment the prefix sum position in map
        else{
            mp[sum]++;
        }
    }
    
    if(flag == 1) cout<<"Yes";
    else cout<<"No";
    
    return 0;
}
