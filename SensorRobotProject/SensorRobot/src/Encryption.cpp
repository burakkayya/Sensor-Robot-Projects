#include "Encryption.h"
/*!
 \param x an integer argument.
    \return encrypted code
*/
int Encryption::encrypt(int x) 
{
   int  temp = x; 
   int a;
   int  integer1, integer2, integer3, integer4;
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
           integer4 = temp % 10;
            temp = temp / 10;
        }
        if (i == 1)
        {
           integer3 = temp % 10;
            temp = temp / 10;
        }
        if (i == 2)
        {
            integer2 = temp % 10;
            temp = temp / 10;
        }
        if (i == 3)
        {
             integer1 = temp;
        
        }
    }

      
       int encryptint1 = (integer1 + 7) % 10;
    
       int  encryptint2 = (integer2 + 7) % 10;
    
       int encryptint3 = (integer3 + 7) % 10;
    
      int  encryptint4 = (integer4 + 7) % 10;
     

     a= encryptint1 * 1000 + encryptint2 * 100 + encryptint3 * 10 + encryptint4;
     return a;
}

/*!
 \param x an integer argument.
    \return encrypted code
*/
int Encryption::decrypt(int x) 
{
    int  temp = x;
    int a;
    int  integer1, integer2, integer3, integer4;

    for (int i = 0; i < 4; i++) 
    {
        if (i == 0)
        {
            integer4 = temp % 10;
            temp = temp / 10;
        }
        if (i == 1)
        {
            integer3 = temp % 10;
            temp = temp / 10;
        }
        if (i == 2)
        {
            integer2 = temp % 10;
            temp = temp / 10;
        }
        if (i == 3)
        {
             integer1 = temp;

        }
    }

       
       int encryptint1 = ((integer1 + 10) - 7)%10;
   
       int  encryptint2 = ((integer2 + 10) - 7)%10;
   
        int encryptint3 = ((integer3 + 10) - 7)%10;

        int encryptint4 = ((integer4 + 10) - 7)%10;

        a = encryptint1 * 1000 + encryptint2 * 100 + encryptint3 * 10 + encryptint4;
        return a;
}