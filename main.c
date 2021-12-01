/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.
                              ali sa
                      https://onlinegdb.com/jkK66Oo-qC
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//get string length
int str_len(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
//reverse characters in a string
void str_reverse(char *str)
{
    int i, j;
    char temp;
    int leng=str_len(str);
    for (i = 0, j = leng - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

//long long int to string
void str_itoa(int64_t n, char *str)
{
    int i = 0;
    int sign;
    if (n<0L)
    {
        n = -n;
        sign =-1;
    }

    do
    {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        str[i++] = '-';
    str[i] = '\0';
    str_reverse(str);
}
// Language: c
//double to string
void ftoa(double n, char *res, int afterpoint)
{
	// Extract integer part
	int ipart = (int)n;

	// Extract floating part
	double fpart = n - (double)ipart;

	// convert integer part to string
	//
	str_itoa(ipart, res);
    int i = str_len(res);
	// check for display option after point
	if (afterpoint != 0) {
		res[i] = '.'; // add dot

		// Get the value of fraction part upto given no.
		// of points after dot. The third parameter is needed
		// to handle cases like 233.007
		fpart = fpart * pow(10, afterpoint);
		//fpart = round(fpart,afterpoint);
		//sprintf(res + i + 1,"%6d",(int)fpart);

		str_itoa((int64_t)fpart, res + i + 1);
	}
}
//rounding up double number
double str_round(double x, unsigned int digits) {
  if (digits > 0) {
    return str_round(x*10.000000000000, digits-1)/10.0;
  }
  else {
    return round(x);
  }
}
//just extract the fractional part to string
void str_getFractionString(double n,char *str,int percision)
{
    double fractpart = 0;
    if(n<0) fractpart=n*-1;
    else fractpart=n;
    fractpart=str_round(fractpart, percision);
    int64_t ftointpart=0;
    int i=0;
    for(i=0;i<percision && fractpart!=0;i++)
    {
        fractpart = fractpart*10;
        
        ftointpart =ftointpart*10+(int64_t) fractpart;
        fractpart =fractpart - (int64_t) fractpart;
        fractpart=str_round(fractpart, percision);
        
    }
    
    str_itoa(ftointpart,str);
    int frac_point = str_len(str); 
    
    
    int k=0;
    for(k=0;k<i;k++)
    {
        str[k]='0';
    }
    str[k]=0;
    
    k= i-frac_point;
    str_itoa(ftointpart,str+k);
}
//double to string with percision if percision is more than number it'll be ignored
void str_ftoa(double n,char *str,int percision)
{
    double num = 0;
    int16_t dec_part = (int64_t )n;
    double fraction_part = n - (int64_t )n;
    
    int negative=0;
    if(n<0)
    {
        dec_part =dec_part*-1;
        str[0]='-';
        negative=1;
    }
    
    str_itoa(dec_part,str+negative);
    int len = str_len(str);
    
    str[len]='.';
    str_getFractionString(fraction_part ,str+len+1,percision);
}



int main()
{
    
    char str[50]={0};
    double num = -10.9850056929;
    
    str_ftoa(num,str,12);
    
    printf("Hello World  %s\n",str);

    return 0;
}
