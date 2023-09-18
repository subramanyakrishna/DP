

//memoisation

bool helper(vector<int>arr, int sum , int n, int **t){
        if(sum==0) return true;
        if(n==0) return false;
        if(t[n-1][sum] != -1) return t[n-1][sum];
        if(arr[n-1] > sum) return t[n-1][sum] = helper(arr,sum,n-1,t);
        
        return t[n-1][sum] = helper(arr,sum-arr[n-1],n-1,t) || helper(arr,sum,n-1,t);
    } 
    bool isSubsetSum(vector<int>arr, int sum){
        
        int **t = new int * [arr.size()+1];
        for(int i=0;i<arr.size()+1;i++){
            t[i] = new int[sum+1];
            for(int j = 0; j< sum+1 ; j++)
            t[i][j] = -1;
        }
        return helper(arr,sum,arr.size(),t);
}

//top down 
bool isSubsetSum(vector<int>arr, int sum){
        int n =arr.size() ; 
        bool t[n+1][sum+1];
        for(int i=0;i<n+1;i++) t[i][0] = true;
        for(int i=1;i<sum+1;i++) t[0][i] = false;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]>j) t[i][j] = t[i-1][j];
                else t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
            }
        }
        return t[n][sum];
        
    }