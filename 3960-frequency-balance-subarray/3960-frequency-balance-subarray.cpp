class Solution {
public:
    int getLength(vector<int>& nums) {
        int ans=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int>freq;
            unordered_map<int,int>cnt;
            for(int j=i;j<n;j++){
                int x=nums[j];
                if(!freq[x]){
                    cnt[1]++;
                }
                else {
                    int f=freq[x];
                    if(cnt[f]==1){
                        cnt.erase(f);
                    }
                    else{
                        cnt[f]--;
                    }
                    cnt[f+1]++;
                }
                freq[x]++;
                if(cnt.size()==1){
                    for(auto z:cnt)if(z.second==1)ans=max(ans,z.first);
                }
                else if(cnt.size()==2){
                    int a,b,c=0;
                    for(auto z:cnt){
                        if(c==0){
                            c=1;
                            a=z.first;
                        }
                        else{
                            b=z.first;
                        }
                    }
                    if(a*2==b || b*2==a)ans=max(ans,j-i+1);
                }
            }
        }
            return ans;
    }
};