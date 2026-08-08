class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        vector<int>nums(n+1);
        int m=word2.size();
        int x=m-1;
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            if(x==0){
                nums[i]=nums[i+1];
            }
            else if(word1[i]==word2[x]){
                nums[i]=nums[i+1]+1;
                x--;
            }
            else{
                nums[i]=nums[i+1];
            }
    
        }
        int c=m;
        int j=0;
        int k=0;
        for(int i=0;i<n;i++){
            if(word1[i]==word2[j]){
                c--;
                j++;
                ans.push_back(i);
            }
            else if(nums[i+1]>=c-1 && k==0){
                k=1;
                j++;
                c--;
                 ans.push_back(i);
            }
            if(c==0)break;
        }
        if(c==0){
            return ans;
        }
        return {};

    }
};