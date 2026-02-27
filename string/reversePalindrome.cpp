#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

void reverseString(string &s){
  int len=s.size();
    int i=0;
    int j=len-1;
    // cout<<s;
   
    while(i<=j){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
}

bool palindrome( string &s){
    string s1=s;
      reverseString(s);

      if(s1==s) return true;
      else return false;
}

int main(){


    string s="MAAM";
    reverseString(s);
    cout<<s<<endl;
    cout<<palindrome(s);

    return 0;
}

// Reverse a string

// Check if string is palindrome

// Check if two strings are anagram

// Count frequency of characters

// Find first non-repeating character

// Remove duplicate characters

// Convert lowercase to uppercase and vice versa

// Count vowels and consonants

// Check if string contains only digits

// Find length of last word

// Reverse words in a sentence

// Check if one string is rotation of another

// Remove all spaces from string

// Print all substrings

// Find largest odd number in string