#include <stdlib.h>
#include "strPtr.h"


#include <stdlib.h>
#include "strPtr.h"


int strgLen(const char *s) {
    if (s==NULL)
    {
        return -1;
    }
    int length = 0;
    while(s[length]!=0)
    {
        length++;
    }


    return length;
   
}


void strgCopy(char *d, char *s) {
   
    if(s==NULL || d == NULL)
    {
        return;
    }
    int i;
    for(i=0; s[i]!=0; i++)
    {
        d[i]=s[i];
    }
    d[i] = 0;
}


void strgChangeCase(char *s) {
    if(s==NULL)
    {
        return;
    }


    int i=0;
    if(s[i]!=0)
    {
        if(s[i+1]<48 || s[i+1]>57)
        {
            if(s[i] >64 && s[i] <91)
            {
                s[i] = s[i] + 32;
            }
            else if(s[i]>96 && s[i]<123)
            {
                s[i] = s[i] -32;
            }
        }
    }


    for(i=1; s[i+1]!=0; i++)
    {
        if(s[i-1]<48 || s[i-1]>57)
        {
            if(s[i+1]<48 || s[i+1]>57)
            {
                if(s[i] >64 && s[i] <91)
                {
                    s[i] = s[i] + 32;
                }
                else if(s[i]>96 && s[i]<123)
                {
                    s[i] = s[i] -32;
                }
            }
        }
    }


   if(s[0]!=0)
   {
        i++;
        if(i>0&&(s[i-1]<48 || s[i-1]>57))
        {
            if(s[i] >64 && s[i] <91)
            {
                s[i] = s[i] + 32;
            }
            else if(s[i]>96 && s[i]<123)
            {
                s[i] = s[i] -32;
            }    
        }
   }


}


int strgDiff(char *s1, char *s2) {
    int counter1 = 0;
    int i=0;
    if(s1==NULL || s2==NULL)
    {
        return -2;
    }
    for( i=0; s1[i]!=0 && s2[i]!=0; i++)
    {
        if(s1[i]!=s2[i])
        {
            return counter1;
        }
        counter1++;
    }


    if(s1[i]==0 && s2[i]==0)
    {
        return -1;
    }


    return counter1;
}


void strgInterleave(char *s1, char *s2, char *d) {
    if(s1==NULL||s2==NULL||d==NULL)
    {
        return;
    }
    int i = 0;
    int i2 =0;
    int j = 0;
    while(s1[i]!=0 && s2[i2]!=0)
    {
        d[j] = s1[i];
        j++;
        d[j] = s2[i2];
        j++;
        i++;
        i2++;
    }


    while(s1[i]!=0)
    {
        d[j]=s1[i];
        i++;
        j++;
    }


    while(s2[i2]!=0)
    {
        d[j]=s2[i2];
        i2++;
        j++;
    }


    d[j] = 0;
}


void strgReverseLetters(char *s) {
    if(s==NULL)
    {
        return;
    }


   
    int len = strgLen(s);
    int left =0;
    int right = len -1;


    while(left<right)
    {
        while(left<right && !((s[left]>64&&s[left]<91)||(s[left]>96&&s[left]<123)))
        {
            left++;
        }
        while(left<right && !((s[right]>64&&s[right]<91)||(s[right]>96&&s[right]<123)))
        {
            right--;
        }


        if(left<right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right]=temp;
            left++;
            right--;
        }
    }
}






/**
 * Create all test cases inside of the main function below.
 * Run the test cases by first compiling with "make" and then
 * running "./bin/strPtr"
 *
 * Before submmiting your assignment, please comment out your
 * test cases for the TAs.
 * Comment out if using criterion to test.
 */
 
//int main(int argc, char* argv[]){
   // (void)argc;
 //   (void)argv;
    /** CREATE TEST CASES HERE **/
    // strgLen - 10 test cases
   // printf("%d\n", strgLen("Stony Brook"));        // expect 11
   // printf("%d\n", strgLen("CSE 220"));            // expect 7
  //  printf("%d\n", strgLen("C"));                  // expect 1
   // printf("%d\n", strgLen(""));                   // expect 0
  //  printf("%d\n", strgLen(NULL));                 // expect -1
   // printf("%d\n", strgLen("System Fundamental")); // expect 18
    //printf("%d\n", strgLen("1"));                  // expect 1
    //printf("%d\n", strgLen("Hello World"));        // expect 11
    //printf("%d\n", strgLen("123456789"));          // expect 9
    //printf("%d\n", strgLen("a"));                  // expect 1
   
    // strgCopy - 10 test cases
    //char d1[50]; strgCopy("Computer Science", d1); printf("%s\n", d1);     // expect Computer Science
    //char d2[50]; strgCopy("CSE-220", d2); printf("%s\n", d2);              // expect CSE-220
    //char d3[50]; strgCopy("", d3); printf("%s\n", d3);                     // expect empty
    //char d4[50]; strgCopy("System Fundamental", d4); printf("%s\n", d4);   // expect System Fundamental
    //char d5[50]; strgCopy("1", d5); printf("%s\n", d5);                    // expect 1
    //char d6[50]; strgCopy("Test", d6); printf("%s\n", d6);                 // expect Test
    //char d7[50]; strgCopy("ABC", d7); printf("%s\n", d7);                  // expect ABC
    //char d8[50]; strgCopy("123", d8); printf("%s\n", d8);                  // expect 123
    //char d9[50]; strgCopy("Hello!", d9); printf("%s\n", d9);               // expect Hello!
    //char d10[50]; strgCopy("x", d10); printf("%s\n", d10);                 // expect x
   
    // strgChangeCase - 10 test cases
    //char s1[] = "Stony Brook"; strgChangeCase(s1); printf("%s\n", s1);                // expect sTONY bROOK
    //char s2[] = "CSE220"; strgChangeCase(s2); printf("%s\n", s2);                     // expect csE220
    //char s3[] = "a1b"; strgChangeCase(s3); printf("%s\n", s3);                        // expect a1b
    //char s4[] = "System Fundamental220"; strgChangeCase(s4); printf("%s\n", s4);      // expect sYSTEM fUNDAMENTAl220
    //char s5[] = "1"; strgChangeCase(s5); printf("%s\n", s5);                          // expect 1
    //char s6[] = ""; strgChangeCase(s6); printf("%s\n", s6);                           // expect empty
    //char s7[] = "ABC"; strgChangeCase(s7); printf("%s\n", s7);                        // expect abc
    //char s8[] = "abc"; strgChangeCase(s8); printf("%s\n", s8);                        // expect ABC
    //char s9[] = "1a2b3c"; strgChangeCase(s9); printf("%s\n", s9);                     // expect 1a2b3c
    //char s10[] = "Hello"; strgChangeCase(s10); printf("%s\n", s10);                   // expect hELLO
   
    // strgDiff - 10 test cases
    //printf("%d\n", strgDiff("Hello", "Hello"));      // expect -1
    //printf("%d\n", strgDiff("CSE-220", "CSE220"));   // expect 3
    //printf("%d\n", strgDiff("CSE220", "SE220"));     // expect 0
    //printf("%d\n", strgDiff("", ""));                // expect -1
    //printf("%d\n", strgDiff(NULL, "test"));          // expect -2
    //printf("%d\n", strgDiff("test", NULL));          // expect -2
    //printf("%d\n", strgDiff("abc", "abd"));          // expect 2
    //printf("%d\n", strgDiff("same", "same"));        // expect -1
    //printf("%d\n", strgDiff("short", "shorter"));    // expect 5
    //printf("%d\n", strgDiff("a", "b"));              // expect 0
   
    // strgInterleave - 10 test cases
    //char r1[50]; strgInterleave("abc", "123", r1); printf("%s\n", r1);          // expect a1b2c3
    //char r2[50]; strgInterleave("abcdef", "123", r2); printf("%s\n", r2);       // expect a1b2c3def
    //char r3[50]; strgInterleave("cse", "12345", r3); printf("%s\n", r3);        // expect c1s2e345
    //char r4[50]; strgInterleave("", "123", r4); printf("%s\n", r4);             // expect 123
    //char r5[50]; strgInterleave("1234", "cs", r5); printf("%s\n", r5);          // expect 1c2s34
    //char r6[50]; strgInterleave("", "", r6); printf("%s\n", r6);                // expect empty
    //char r7[50]; strgInterleave("abc", "", r7); printf("%s\n", r7);             // expect abc
    //char r8[50]; strgInterleave("a", "1", r8); printf("%s\n", r8);              // expect a1
    //char r9[50]; strgInterleave("AB", "12", r9); printf("%s\n", r9);            // expect A1B2
    //char r10[50]; strgInterleave("x", "yz", r10); printf("%s\n", r10);          // expect xyz
   
    // strgReverseLetters - 10 test cases
    //char v1[] = "Hello"; strgReverseLetters(v1); printf("%s\n", v1);            // expect olleH
    //char v2[] = "ab-cd"; strgReverseLetters(v2); printf("%s\n", v2);            // expect dc-ba
    //char v3[] = "a1b2c"; strgReverseLetters(v3); printf("%s\n", v3);            // expect c1b2a
    //char v4[] = "ABC"; strgReverseLetters(v4); printf("%s\n", v4);              // expect CBA
    //char v5[] = "a"; strgReverseLetters(v5); printf("%s\n", v5);                // expect a
    //char v6[] = "12345"; strgReverseLetters(v6); printf("%s\n", v6);            // expect 12345
    //char v7[] = ""; strgReverseLetters(v7); printf("%s\n", v7);                 // expect empty
    //char v8[] = "a b c"; strgReverseLetters(v8); printf("%s\n", v8);            // expect c b a
    //char v9[] = "Test123"; strgReverseLetters(v9); printf("%s\n", v9);          // expect tseT123
    //char v10[] = "aB-Cd"; strgReverseLetters(v10); printf("%s\n", v10);         // expect dC-Ba
   
    /** ---------------------- **/
  //  return 0;
//}
