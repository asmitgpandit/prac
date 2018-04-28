#include <iostream>

using namespace std;


bool isPresent(char* needle, char* haystack)
{
    
    
    char* i = haystack;
    char* j = needle;
    
    while(*i)
    {
        
        while(*j == *i)
        {
            i++;
            j++;
            
        }
        if (*j == '\0')
        {
            return true;
        }
        else
        {
            j = needle;
        }
        
        i++;
    }
    return false;
}

bool isAnangram(const char* str1, const char* str2)
{
    char h1[26] = {0}, h2[26] = {0};
    const char* p = str1;

    while(*p)
    {
        if((*p >= 'a') && (*p <='z'))
            h1[(*p - 'a')]++;
        else if ((*p >= 'A') && (*p <='Z'))
            h1[(*p - 'A')]++;
        else
            cout<<"Illegal character\n";

        ++p;
    }
    p = str2;
    while(*p)
    {
        if((*p >= 'a') && (*p <='z'))
            h2[(*p - 'a')]++;
        else if ((*p >= 'A') && (*p <='Z'))
            h2[(*p - 'A')]++;
        else
            cout<<"Illegal character\n";
        ++p;
    }

    for(int i=0; i<26; i++)
    {
        if (h1[i] != h2[i])
            return false;
    }
    return true;
}


bool isPalindrome(const char* str)
{
    const char* p = str;
    int len = 0;

    while(*p != '\0')
    {
        len++;
        p++;
        
    }
    for (int i = 0; i < len/2; ++i)
    {
        if (str[i] != str[len-i-1])
            return false;
    }
    return true;
}

int main()
{
     // if (isPresent("cat","capastrophic"))
     //    cout<<"Present !";
     // else
     //     cout<<"Not present";


    // if (isAnangram("abc","ccb"))
    //     cout<<"Anagram !\n";
    //  else
    //      cout<<"Not Anagram\n";

    if (isPalindrome("madami"))
        cout<<"Palindrome !\n";
     else
         cout<<"Not Palindrome\n";
    
    return 0;
}

