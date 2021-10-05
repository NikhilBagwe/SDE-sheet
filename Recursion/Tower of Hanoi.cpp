
// n -> no. of disks
void towerOfHanoi(int n, char source, char helper, char destination){
    if(n == 1){
        cout<<"Move disk 1 from "<<source<<" to "<<destination<<endl;
        return;
    }
    
    // Move the n-1 disks from source rod to helper rod with help of destination rod.
    towerOfHanoi(n-1, source, destination, helper);
    cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
    
    //  Move the n-1 disks from helper rod to destination rod with help of source rod.
    towerOfHanoi(n-1, helper, source, destination);
}

int main()
{
    towerOfHanoi(3,'A','B','C');

    return 0;
}
