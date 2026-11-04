#include <stdio.h>

#include <string.h>


int main()

{

    char data[100], divisor[30], temp[100], rem[30], codeword[130];

    int i, j, dataLen, divLen;


    printf("Enter Data Bits: ");

    scanf("%s", data);


    printf("Enter Generator Polynomial: ");

    scanf("%s", divisor);


    dataLen = strlen(data);

    divLen = strlen(divisor);


    strcpy(temp, data);



    for(i = 0; i < divLen - 1; i++)

        temp[dataLen + i] = '0';


    temp[dataLen + divLen - 1] = '\0';


    strcpy(rem, temp);


    for(i = 0; i < dataLen; i++)

    {

        if(rem[i] == '1')

        {

            for(j = 0; j < divLen; j++)

            {

                rem[i + j] = (rem[i + j] == divisor[j]) ? '0' : '1';

            }

        }

    }



    strcpy(codeword, data);

    for(i = 0; i < divLen - 1; i++)

        codeword[dataLen + i] = rem[dataLen + i];


    codeword[dataLen + divLen - 1] = '\0';


    printf("\nCRC Remainder : ");

    for(i = dataLen; i < dataLen + divLen - 1; i++)

        printf("%c", rem[i]);


    printf("\nCodeword      : %s\n", codeword);


    return 0;

}

