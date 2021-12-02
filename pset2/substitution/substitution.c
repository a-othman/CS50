// Notes the code runs perefectly only one of the tests is not running properly though when I run it in the terminal,
// it runs smoothly
// the case where error occures: encrypts all alphabetic characters using DWUSXNPQKEGCZFJBTLYROHIAVM as key
    // expected "ciphertext: Rq...", not "ciphertext: p\..." 
// the plain text provided to the code in this test case: The quick brown fox jumps over the lazy dog
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool key_correct(string key);
bool unique(string key);
const char* cypher_msg(string key, string plaintext);



int main(int argc, string argv[])
{
    // ensuring user is calling the program using the right format
    if (argc !=2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        string key= argv[1];
        // ensuring the user entered a correct key (26 unique chars)
        if (key_correct(key)== false)
        {
            printf("please ensure that key has 26 unique alpabet char\n");
            return 1;
        }
        else
        {
            // prompt the user for the message to encrypt
            string plaintext= get_string("plaintext: ");

            // printf("");
            printf("ciphertext: %s\n", cypher_msg(key, plaintext));
            
            return 0;
        }        
    }
}


// this function ensure that the provided key is correct (has 26 unique chars, all alphabet)
bool key_correct(string key)
{
    // test the length of the key and its uniquness and returning false is either is false
    if (strlen(key) != 26 || unique(key)== false)
    {
        return false;
    }
    else 
    {   //ensure that each char in the key is an alphabet
        for (int i=0, n= strlen(key); i< n; i++)
        {
            if (isalpha(key[i])== false)
            {
                return false;
            }

        }
    }
    return true;
}

// function testing that each char in a string occurs only once
bool unique(string key)
{
    for (int i=0, n= strlen(key); i< n-1; i++)
	{
	    for (int j= i+1; j<n; j++ )
	    {
	        if (key[i]== key[j])
	        {
	            return false;
	        }
	    }
	}
	return true;
}

// converting a plain test into a ciphered message given the ket
const char* cypher_msg(string key, string plaintext)
{

    int n= strlen(plaintext);
    char *alphabet_small= "abcdefghijklmnopqrstuvwxyz";
    char *alphabet_capital= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int index;
    char *c;
    char replace;
    char encrypted_message[n];

    for (int i=0; i< n; i++)
    {
        if (isupper(plaintext[i])!= 0 && isalpha(plaintext[i])!= 0)
        {
            c= strchr(alphabet_capital, plaintext[i]);
            index= (int) (c- alphabet_capital);
            replace= toupper(key[index]);
            strncat(encrypted_message, &replace, 1);
        }
        else if (isupper(plaintext[i])== 0 && isalpha(plaintext[i])!= 0)
        {
            c= strchr(alphabet_small, plaintext[i]);
            index= (int) (c- alphabet_small);
            replace= tolower(key[index]);

            strncat(encrypted_message, &replace, 1);
        }
        else if (isalpha(plaintext[i])== 0)
        {
            // printf("Entered third if\n");
            strncat(encrypted_message, &plaintext[i], 1);
        }
        
    }
    // printf("%s", encrypted_message);
    char *msg= encrypted_message;
    // char a= '\';
    // char b= '0';
    // strncat(encrypted_message, &a, 1);
    // strncat(encrypted_message, &b, 1);
    
    printf("%s\n", msg );
    return msg;
}












