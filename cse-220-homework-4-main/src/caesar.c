#include <stdlib.h>
#include "caesar.h"
#include "strPtr.h"


/**
 *  Feel free to use the functions that you made in strPtr.c
*/

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

int encryptCaesar(const char *plaintext, char *ciphertext, int key) {
    if(plaintext==NULL || ciphertext==NULL)
    {
        return -2;
    }
    if(strgLen(plaintext) == 0)
    {
        char undef[] = "undefined__EOM__";
        int j;
        for(j = 0; undef[j] != '\0'; j++) 
        {
            ciphertext[j] = undef[j];
        }
        ciphertext[j] = '\0';

        return 0;
    }

    int i = 0;
    for(i=0; i<strgLen(plaintext); i++)
    {
        if(plaintext[i]>64 && plaintext[i]<91)
        {
            int shift = (i+key) %26;
            ciphertext[i] = ((plaintext[i]-65+shift)%26) +65;
        }
        else if (plaintext[i]>96 && plaintext[i]<123)
        {
            int shift = (i+key) %26;
            ciphertext[i] = ((plaintext[i]-97+shift)%26) +97;


        }
        else if(plaintext[i]>47 && plaintext[i]<58)
        {
            int shift = (key + 2*i)%10;
            ciphertext[i] = ((plaintext[i]-48+shift)%10) + 48;
        }
        else
        {
            ciphertext[i]=plaintext[i];
        }
    }


    ciphertext[i] = '_';
    ciphertext[i+1] = '_';
    ciphertext[i+2] = 'E';
    ciphertext[i+3] = 'O';
    ciphertext[i+4] = 'M';
    ciphertext[i+5] = '_';
    ciphertext[i+6] = '_';
    ciphertext[i+7] = 0;


    return i;


}


int decryptCaesar(const char *ciphertext, char *plaintext, int key) {
    if(ciphertext==NULL||plaintext==NULL)
    {
        return -2;
    }

    if(strgLen(plaintext) == 0) 
    {
        return 0;
    }


    int eom = -1;
    for(int i=0; ciphertext[i]!=0;i++)
    {
        if(ciphertext[i] == '_' &&ciphertext[i+1] == '_'&& ciphertext[i+2] == 'E'&&ciphertext[i+3] == 'O'
            &&ciphertext[i+4] == 'M'&&ciphertext[i+5] == '_'&&ciphertext[i+6] == '_')
        {
            eom = i;
            break;
        }
    }


    if(eom==-1)
    {
        return -1;
    }


    for(int i =0; i<eom; i++)
    {
        if(ciphertext[i]>64 && ciphertext[i]<91)
        {
            int shift = (i+key) %26;
            plaintext[i] = ((ciphertext[i]-65-shift + 26)%26) +65;
        }
        else if (ciphertext[i]>96 && ciphertext[i]<123)
        {
            int shift = (i+key) %26;
            plaintext[i] = ((ciphertext[i]-97-shift+26)%26) +97;


        }
        else if(ciphertext[i]>47 && ciphertext[i]<58)
        {
            int shift = (key + 2*i)%10;
            plaintext[i] = ((ciphertext[i]-48-shift+10)%10) + 48;
        }
        else
        {
            plaintext[i]=ciphertext[i];
        }
    }


    plaintext[eom] = 0;


    return eom;
}




/**
 * Create all test cases inside of the main function below.
 * Run the test cases by first compiling with "make" and then
 * running "./bin/caesar"
 *
 * Before submmiting your assignment, please comment out your
 * test cases for the TAs.
 * Comment out if using criterion to test.
 */
int main(int argc, char* argv[]){
    (void)argc;
    (void)argv;
    /** CREATE TEST CASES HERE **/


    // Part A: Encryption - 10 test cases
    //char c1[50]; printf("%d\n", encryptCaesar("abc", c1, 2)); printf("%s\n", c1);           // expect 3, ceg__EOM__
    //char c2[50]; printf("%d\n", encryptCaesar("Ayb", c2, 3)); printf("%s\n", c2);           // expect 3, Dcg__EOM__
    //char c3[50]; printf("%d\n", encryptCaesar("Cse220", c3, 1)); printf("%s\n", c3);        // expect 6, Duh911__EOM__
    //char c4[50]; printf("%d\n", encryptCaesar("CS", c4, 0)); printf("%s\n", c4);            // expect 2, CT__EOM__
    //char c5[50]; printf("%d\n", encryptCaesar("", c5, 5)); printf("%s\n", c5);              // expect 0, __EOM__
    //char c6[50]; printf("%d\n", encryptCaesar(NULL, c6, 1));                                // expect -2
    //char c7[50]; printf("%d\n", encryptCaesar("System Fundamentals", c7, 1)); printf("%s\n", c7);  // expect 19, Tavxjs Ndxomzscjrdl__EOM__
    //char c8[50]; printf("%d\n", encryptCaesar("Hello World", c8, 5)); printf("%s\n", c8);   // expect 11
    //char c9[50]; printf("%d\n", encryptCaesar("a", c9, 1)); printf("%s\n", c9);             // expect 1, b__EOM__
    //char c10[50]; printf("%d\n", encryptCaesar("Test123", c10, 2)); printf("%s\n", c10);    // expect 7


    // Part B: Decryption - 10 test cases
    //char p1[50]; printf("%d\n", decryptCaesar("ceg__EOM__", p1, 2)); printf("%s\n", p1);           // expect 3, abc
    //char p2[50]; printf("%d\n", decryptCaesar("Dcg__EOM__", p2, 3)); printf("%s\n", p2);           // expect 3, Ayb
    //char p3[50]; printf("%d\n", decryptCaesar("Duh911__EOM__", p3, 1)); printf("%s\n", p3);        // expect 6, Cse220
    //char p4[50]; printf("%d\n", decryptCaesar("CT__EOM__", p4, 0)); printf("%s\n", p4);            // expect 2, CS
    //char p5[50]; printf("%d\n", decryptCaesar("__EOM__", p5, 5)); printf("%s\n", p5);              // expect 0, empty
    //char p6[50]; printf("%d\n", decryptCaesar("noEOM", p6, 1));                                    // expect -1
    //char p7[50]; printf("%d\n", decryptCaesar(NULL, p7, 1));                                       // expect -2
    //char p8[50]; printf("%d\n", decryptCaesar("Tavxjs Ndxomzscjrdl__EOM__", p8, 1)); printf("%s\n", p8);  // expect 19, System Fundamentals
    //char p9[50]; printf("%d\n", decryptCaesar("b__EOM__", p9, 1)); printf("%s\n", p9);             // expect 1, a
    //char p10[50]; printf("%d\n", decryptCaesar("CT__EOM____EOM__", p10, 0)); printf("%s\n", p10);  // expect 2, CS (stops at first EOM)                                                 // expect -2
       
    /** ---------------------- **/
    return 0;
}
