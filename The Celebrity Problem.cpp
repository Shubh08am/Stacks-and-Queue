
class Solution 
{
    public:
    
    bool relationExist(vector<vector<int> >& M, int first_Person,int second_Person) {
        if(M[first_Person][second_Person]==1) return 1;
        
         return 0;
    }
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>s;
        //push person's
        for(int i=0;i<n;i++) {
            s.push(i);
        }
        //take two person and see for relation between them
        while(s.size()>1){
            int first_Person = s.top();
            s.pop();
            
            int second_Person = s.top();
            s.pop();
            
            if(relationExist(M,first_Person,second_Person)){
                //first_Person knows second_Person that means second_Person can be a celebrity
                s.push(second_Person);
            }
            else if(relationExist(M,second_Person,first_Person)){
                //second_Person knows first_Person that means first_Person can be a celebrity
                s.push(first_Person);
            }
        }
        //single element in stack see and verify for it
        int val = s.top();
        
        int zeroCount = 0 ; 
        bool rowCheck = 0 ; 
        
        for(int i=0;i<n;i++){
            if(M[val][i]==0) zeroCount++;
        }
        
        //in row all 0's exist
        if(zeroCount == n) {
            rowCheck = 1;
        }
        
        int oneCount = 0 ; 
        bool columnCheck = 0 ; 
        
        for(int i=0;i<n;i++){
            if(M[i][val]==1) oneCount++;
        }
        
        //in column all 1's exist except diagonal one
        if(oneCount == n-1) {
            columnCheck = 1;
        }
        
        if(columnCheck==0 || rowCheck==0) return -1;
        
        return val;
    }
};
