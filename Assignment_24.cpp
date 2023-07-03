/*
<aside>
💡 1. **Roman to Integer**

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

```
SymbolValue
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, `2` is written as `II` in Roman numeral, just two ones added together. `12` is written as `XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

- `I` can be placed before `V` (5) and `X` (10) to make 4 and 9.
- `X` can be placed before `L` (50) and `C` (100) to make 40 and 90.
- `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

</aside>
*/
#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
        unordered_map<char, int> m;
        
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
        }
        return ans;
}



/*
<aside>
💡 2. **Longest Substring Without Repeating Characters**

Given a string `s`, find the length of the **longest substring** without repeating characters.

</aside>
*/
int lengthOfLongestSubstring(string s) {
        int ans=0,l=0,r=0;
        int  n =s.size();
        vector<int> map(256,-1);
        while(r<n){
            if(map[s[r]]!=-1){
                l=max(map[s[r]]+1,l);
            }
            map[s[r]]=r;
            ans= max(ans,r-l+1);
            r++;
        }
        return ans;
}


/*
<aside>
💡 3. **Majority Element**

Given an array `nums` of size `n`, return *the majority element*.

The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

</aside>
*/    
int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;

        for(auto i: mp){
            if(i.second>nums.size()/2)
            ans=i.first;
        }
        return ans;
}


/*
<aside>
💡 4. **Group Anagram**

Given an array of strings `strs`, group **the anagrams** together. You can return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1**

</aside>
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        unordered_map<string,vector<string>>mp;

        for(int i=0; i<n; i++){
            string temp = strs[i];
            sort(begin(temp) , end(temp));
            mp[temp].push_back(strs[i]);
        }

        for(auto it : mp){
            result.push_back(it.second);
        }
        return result;
}


/*
<aside>
💡 5. **Ugly Numbers**

An **ugly number** is a positive integer whose prime factors are limited to `2`, `3`, and `5`.

Given an integer `n`, return *the* `nth` ***ugly number***.

</aside>
*/


int nthUglyNumber(int n) {

    vector<int> ans(n);
 
	
    int x=0,y=0,z=0;
    ans[0]=1;
    for(int i=1;i<n;i++)
    {
        ans[i]=min(ans[x]*2,min(ans[y]*3,ans[z]*5));
        if(ans[i]==2*ans[x])x++;
        if(ans[i]==3*ans[y])y++;
        if(ans[i]==5*ans[z])z++;
        
        
    }
    return ans[n-1];
}




/*
<aside>
💡 6. **Top K Frequent Words**

Given an array of strings `words` and an integer `k`, return *the* `k` *most frequent strings*.

Return the answer **sorted** by **the frequency** from highest to lowest. Sort the words with the same frequency by their **lexicographical order**.

</aside>
*/

vector<string> topKFrequent(vector<string>& words, int k) {
    int x=words.size();
    unordered_map<string, int> mp;
    for(int i=0; i<x; i++)mp[words[i]]++; 
    map<int, vector<string>> p;
	
    for(auto i: mp){
        if(p.find(i.second)==p.end()){
            p[i.second]={i.first};
            continue;
        }
         p[i.second].push_back(i.first);
    }   
vector<pair<int, vector<string>>> v;
for(auto i: p)v.push_back({i.first, i.second}); //making pair of fre and words
sort(v.begin(), v.end(), greater<pair<int, vector<string>>>()); //for most freq. words
    for(int i=0; i<v.size(); i++)  sort(v[i].second.begin(), v[i].second.end()); //sorting the words in increasing order
vector<string> ans;
int i=0;
while(k>0 and i<v.size()){
    for(int j=0; j<v[i].second.size() and k>0; j++, k--)ans.push_back(v[i].second[j]);
    i++;
}
return ans;
    
}

/*
<aside>
💡 7. **Sliding Window Maximum**

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return *the max sliding window*.

</aside>

*/

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
    vector<int> ans;
    priority_queue<pair<int, int>> heap;


    for (int i=0; i<k; i++) heap.push({nums[i], i});
        
    ans.push_back(heap.top().first);

    for(int i=k; i<nums.size(); i++) {

        heap.push({nums[i], i});

        while (heap.top().second <= i-k) heap.pop();

        ans.push_back(heap.top().first);
    }

    return ans;
}



/*
<aside>
💡 8. **Find K Closest Elements**

Given a **sorted** integer array `arr`, two integers `k` and `x`, return the `k` closest integers to `x` in the array. The result should also be sorted in ascending order.

An integer `a` is closer to `x` than an integer `b` if:

- `|a - x| < |b - x|`, or
- `|a - x| == |b - x|` and `a < b`
</aside>
*/

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue <pair<int,int>> maxpq;
        
        for(int i=0;i<arr.size();i++){
            maxpq.push({abs(arr[i]-x),arr[i]});
            if(maxpq.size()>k)
                maxpq.pop();
        }
        vector<int> result;
        while(maxpq.size()>0){
            result.push_back(maxpq.top().second);
            maxpq.pop();
        }
        sort(result.begin(),result.end());
        return result;
}
