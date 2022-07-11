#include <stdio.h>
#include <math.h>
double result;
int convertBinaryToDecimal(long long n,int width)
{
    int sign;
    int reg_sign,bit;
    int reg;
    long long temp,n_new;
    int c;
    int exp;
    if(width==8)
    {
        n_new = 0;
        sign = (n/10000000) % 10;
        if(sign==1)
        {
            temp=1;
            c=1;
            for(int i=0;i<8;i++)
            {
                if(n%10)
                {
                    if(c)
                    {
                        n_new += temp;
                        c=0;
                    }
                    else
                    {
                        c=0;
                    }
                }
                else
                {
                    if(c)
                    {
                        c=1;
                    }
                    else
                    {
                        n_new += temp;
                    }
                }
                n=n/10;
                temp = temp*10;
            }
            n = n_new;
            
        }
        printf("n=%d\n",n);
        reg_sign = (n/1000000) % 10;
        if(reg_sign==1)
        {
            reg = 0;
            bit = 1;
            temp = 100000;
           
            while(bit==1)
            {
                bit = (n/temp) % 10;
                temp = temp/10;
                reg += bit;
            }
            result = 1;
            bit = 5-reg;
            printf("reg=%d\n",reg);

            while(bit>0)
            {
                printf("n=%d\n",n);
                result += (n % 10) * pow(2,(-bit));
                printf("frac=%f\n",result);
                bit -= 1;
                n = n/10;
            }
            
            result = result * pow(2,reg);
            printf("frac=%f\n",result);

        }
        else
        {
            reg = 0;
            bit = 0;
            temp = 100000;
            while(bit==0)
            {
                bit = (n/temp) % 10;
                temp = temp/10;
                reg += 1;
            }
            result = 1;
            printf("reg=%d\n",reg);
            bit = 6-reg;
            while(bit>0)
            {
                printf("n=%d\n",n);
                result += (n % 10) * pow(2,(-bit));
                printf("frac=%f\n",result);
                bit -= 1;
                n = n/10;
            }
           
            result = result * pow(2,-reg);
            printf("frac=%f\n",result);
        }
        if(sign)
        {
            result=-result;
        }
    }
    else if(width=16)
    {
        
    }

}
int main()
{
    long long n;
    int width;

    scanf("%lld", &n);
    scanf("%d", &width);
    convertBinaryToDecimal(n,width);
    printf("result= %f",result);
}

