// Maximum and minimum of an array using minimum number of comparisons

#include <iostream>

using namespace std;
struct Pair{
    int min;
    int max;
};

struct Pair getMinMAx(int a[], int n){
    struct Pair minmax;
    
    if(n==1){
        minmax.min = a[0];
        minmax.max = a[0];
        return minmax;
    }
    
    if(a[0]>a[1]){
        minmax.min = a[1];
        minmax.max = a[0];
    }
    else{
        minmax.min = a[0];
        minmax.max = a[1];
    }
    
    for(int i=2; i<n; i++){
        if(a[i]>minmax.max){
            minmax.max = a[i];
        }
        else if(a[i]<minmax.min){
            minmax.min = a[i];
        }
    }
    
    return minmax;
}

int main()
{
    int arr[]= {10, 8, 2, 15, 18,75};
    int n = 6;
    struct Pair minmax = getMinMAx(arr, n);
    cout << "Minimum element is "
         << minmax.min << endl;
    cout << "Maximum element is "
         << minmax.max;

    return 0;
}

// Better approach ============================================================================================================

#include <iostream>

using namespace std;

int main()
{
    int n;
    
    cout<<"Enter size of array: ";
    cin>>n;
    int a[n];
    
    cout<<"Enter "<<n<<" elements of array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    int i =0,min,max;
    
    // check whether EVEN no. of elements are present
    if(n%2 == 0){
        if(a[0] > a[1]){
            min = a[1];
            max = a[0];
        }
        else{
            min = a[0];
            max = a[1];
        }
        i=2;
    }
    
    // check whether ODD no. of elements are present
    else{
        min = a[0];
        max = a[0];
        i =1;
    }
    
    while(i < (n-1)){
        
        if(a[i] > a[i+1]){   //  odd -> 3*(n-1)/2 ,  even -> 1 + 3*(n-2)/2 => (n-2) as 2 elements are already checked before entering while loop, thus we add 1 at start
            
            if(a[i] > max){
                max = a[i];
            }
            if(a[i+1] < min){
                min = a[i+1];
            }
        }
        
        else{
            
            if(a[i+1] > max){
                max = a[i+1];
            }
            if(a[i] < min){
                min = a[i];
            }
        }
        
        // since we are checking 2 elements at a time
        i = i + 2;
    }
    
    cout<<"Maximum: "<<max<<endl;
    cout<<"Minimum: "<<min<<endl;
    return 0;
}
