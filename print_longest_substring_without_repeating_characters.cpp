/*
Given a string, print the longest substring without repeating characters. 
For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6. 
For “BBBB” the longest substring is “B”, with length 1. 
The desired time complexity is O(n) where n is the length of the string.

Approach:
keep track of the visited characters. whenever a repeated character is found. check whether its length is greater than max length.
in that case update start and current length of the string. 
repeated the above steps to get the output. 
This approach can also be used to find the length of the longest substring without repeating characters.

Solution: 
*/

#include<bits/stdc++.h>
using namespace std;

string longestSubsrtingWithUniqueCharacters(string ip) {
    int start, st = 0, max_len = 0, cur_len, i;
    unordered_map<char, int> search;
    
    search[ip[0]] = 0;
    
    for(i = 1; i < ip.size(); ++i) {
        if(search.find(ip[i]) == search.end()) search[ip[i]] = i;
        
        else {
            if(search[ip[i]] >= st) {
                
                cur_len = i - st;
                
                if(max_len < cur_len) {
                    max_len = cur_len;
                    start = st;
                }
                
                st = search[ip[i]] + 1;
            }
        }
        search[ip[i]] = i;
    }
    if(max_len < i - st) {
        max_len = i = st;
        start = st;
    }
    return ip.substr(start, max_len);
}

int main() {
    string ip;
    cin >> ip;
    
    string ans = longestSubsrtingWithUniqueCharacters(ip);
    
    cout << ans;
    return 0;
}

