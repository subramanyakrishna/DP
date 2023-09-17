
//Using Memoization
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int t[1001][1001];
    int helper(int W, int wt[], int val[], int n) 
    { 
       if(W == 0 || n == 0) return 0;
       if(t[W][n] !=-1) return t[W][n];
       
       if(wt[n-1] <= W) return t[W][n] = max(val[n-1]+helper(W-wt[n-1],wt,val,n-1) , helper(W,wt,val,n-1));
       else return t[W][n] = helper(W,wt,val,n-1);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       memset(t,-1,sizeof(t));
       return helper(W,wt,val,n);
    }
};
//Using top down  
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int t[n+1][W+1];
       int i=0,j=0;
       while(i < n+1)  t[i++][0] = 0;
       while(j < W+1)  t[0][j++] = 0;
       
       for(i=1;i<n+1;i++){
           for(j=1;j<W+1;j++){
               if(wt[i-1] <= j) {
                   t[i][j] = max(val[i-1]+ t[i-1][j-wt[i-1]]  , t[i-1][j]);
               }
               else t[i][j] =  t[i-1][j];
           }
       }
       return t[n][W];
    }
};