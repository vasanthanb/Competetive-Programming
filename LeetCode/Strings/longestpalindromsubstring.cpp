#include<bits/stdc++.h>

using namespace std;

void solve(string &s,int &size,int &index,int i,int j){
    int n=s.size();
    while(i>=0&&j<n){// we will check if i and j are in range
        if(s[i]==s[j]){ // if s[i]==s[j] it is true that means j-i+1 lenght of sting is palindrome and we have to check for i-- and j++      
        // that means i will move left anf j will move right
            if(j-i+1>=size){// if j-i+1 (size of current palindrome string) is greater than size then we will update and size and index;
                size=j-i+1;
                index=i;
            }
            i--;
            j++;
        }
        else{// not equal then we will break and return 
            break;
        }
    }
}

string longestPalindrome(string s) {
    int size=0;  // it will store max length of palindrome string
    int index=-1;  // it will store index of palindrome string
    int n=s.size();   
    for(int i=0;i<n;i++){    // itrating over string 
        solve(s,size,index,i,i);   // when palindrome string is of odd length
        solve(s,size,index,i,i+1);   // when palindrome string is of even length
    }
    return s.substr(index,size);// making ans string from index and size
}

int main() {
    string input;
    getline(cin, input);
    string lsubstring = longestPalindrome(input);
    cout << lsubstring << endl;
    return 0;
}