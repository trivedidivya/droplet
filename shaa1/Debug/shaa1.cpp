#include "Energia.h"

#line 1 "C:/Users/divya/workspace_v8/shaa1/shaa1.ino"

#include <stdio.h>
#include <string.h>


#include <stdint.h>
void setup();
void loop();
void binary_converter(char *p, int z);

#line 7
using namespace std;

#include "sha1.h"
#include "sha1.c"




struct student
{
     int id;
     char name[30];
     char pass[6];
};struct student record[2];

int P[3][50];
int B[3][10];
char string[20];
char result[21];
char hexresult[41];
size_t offset;
void setup()
{   Serial.begin(9600);

     record[0].id=1;
     strcpy(record[0].name, "Divya");
     strcpy(record[0].pass, "DTpas");

     record[1].id=2;
     strcpy(record[1].name, "Madavi");
     strcpy(record[1].pass, "Mdpas");

     record[2].id=3;
     strcpy(record[2].name, "Ajeeth");
     strcpy(record[2].pass, "Ajpas");

} 

void loop()
{ delay(500);
  int p,y;

 
  for(p=0; p<2; p++)
       {
      
     
     

       strcpy(string,record[p].pass);
       SHA1( result, string, strlen(string) );
  
       for( offset = 0; offset < 20; offset++)
           {
             sprintf( ( hexresult + (2*offset)), "%02x", result[offset]&0xff);
           }
      
      binary_converter(hexresult, p);
     
      delay(500);
       }
     delay(500);
for(y=0; y<2; y++)
   { int f=0, i=0, j, d;
  for(j=0;j<50;j++)
       {
          if(P[y][j]> 0)
            {  d = f - P[y][j];
               f = P[y][j];
               if(abs(d)>0)
                 {
                   B[y][i]=P[y][j];
                   
                   i++;
                 }
            }
       }
     }
for(y=0; y<2; y++)
   { Serial.write(record[y].name);
     Serial.print("     ");
    for(int k=0; k<10; k++)
            {
                Serial.print(B[y][k]);
            }
            delay(1000);
            Serial.println("");
   }

}

void binary_converter(char *p, int z)
        {
    int i=0;
    char binary[1000];
    strcpy(binary,"");
        while (p[i])
    {
        switch (p[i])
        {
        case '0':
            strcpy(binary,strcat(binary,"0000"));
            
            break;
        case '1':
            strcpy(binary,strcat(binary,"0001"));
            
            break;
        case '2':
            strcpy(binary,strcat(binary,"0010"));
            
            break;
        case '3':
            strcpy(binary,strcat(binary,"0011"));
            
            break;
        case '4':
            strcpy(binary,strcat(binary,"0100"));
            
            break;
        case '5':
            strcpy(binary,strcat(binary,"0101"));
            
            break;
        case '6':
            strcpy(binary,strcat(binary,"0110"));
            
            break;
        case '7':
            strcpy(binary,strcat(binary,"0111"));
            
            break;
        case '8':
            strcpy(binary,strcat(binary,"1000"));
            
            break;
        case '9':
            strcpy(binary,strcat(binary,"1001"));
            
            break;
        case 'A':
            strcpy(binary,strcat(binary,"1010"));
            
            break;
        case 'B':
            strcpy(binary,strcat(binary,"1011"));
            
            break;
        case 'C':
            strcpy(binary,strcat(binary,"1100"));
            
            break;
        case 'D':
            strcpy(binary,strcat(binary,"1101"));
            
            break;
        case 'E':
            strcpy(binary,strcat(binary,"1110"));
            
            break;
        case 'F':
            strcpy(binary,strcat(binary,"1111"));
            
            break;
        case 'a':
            strcpy(binary,strcat(binary,"1010"));
            
            break;
        case 'b':
            strcpy(binary,strcat(binary,"1011"));
            
            break;
        case 'c':
            strcpy(binary,strcat(binary,"1100"));
            
            break;
        case 'd':
            strcpy(binary,strcat(binary,"1101"));
            
            break;
        case 'e':
            strcpy(binary,strcat(binary,"1110"));
            
            break;
        case 'f':
            strcpy(binary,strcat(binary,"1111"));
            
            break;
        default:
            printf("\n Invalid hexa digit %c ", binary[i]);
            
        }
        i++;
    }

    int str_len = strlen(binary);
    for(i = 1; i < str_len; i++)
    {
       
        if(i % 8 == 0)
        {
           
        }
    }
   
    int j=0;
    for(i = 1; i < str_len; i++)
    {
        if((i-1) % 2 == 0)
            {
             if(binary[i - 1] == '0' && binary[i] == '0')
             { 
               P[z][j] = 1; j++;  }
             else if(binary[i - 1] == '0' && binary[i] == '1')
             { 
               P[z][j] = 2; j++;  }
             else if(binary[i - 1] == '1' && binary[i] == '0')
             { 
               P[z][j] = 3; j++;  }
             else if(binary[i - 1] == '1' && binary[i] == '1')
             { 
               P[z][j] = 4; j++;  }
            }
    }
    Serial.println("\n");
}






