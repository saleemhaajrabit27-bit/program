
Longest Palindromic Substring :

#include <string.h>
#include <stdlib.h>

int expandAroundCenter(char* s, int left, int right, int n) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
 
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n < 1) return "";

    int start = 0, end = 0;

    for (int i = 0; i < n; i++) {
   
        int len1 = expandAroundCenter(s, i, i, n);
      
        int len2 = expandAroundCenter(s, i, i + 1, n);

        int len = (len1 > len2) ? len1 : len2;

      
        if (len > (end - start)) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    int resultLen = end - start + 1;
    char* result = (char*)malloc((resultLen + 1) * sizeof(char));
    
    for (int i = 0; i < resultLen; i++) {
        result[i] = s[start + i];
    }
    result[resultLen] = '\0'; 

    return result;
}