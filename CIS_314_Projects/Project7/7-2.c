//
//  7-2.c
//  
//
//  Created by Creston Wilson on 3/10/18.
//

#include <stdio.h>
#include <stdlib.h>

void inner2(float *u, float *v, int length, float *dest)
{
    int i;
    float sum0 = 0.0f;
    float sum1 = 0.0f;
    float sum2 = 0.0f;
    float sum3 = 0.0f;
    for( i = 0; i < length; i+=4)
    {
        sum0 += u[i] + v[i];
        sum1 += u[i+1] + v[i+1];
        sum2 += u[i+2] + v[i+2];
        sum3 += u[i+3] + v[i+3];
    }
    
    for (; i<length; i++) {
        sum0 += u[i] + v[i];
    }
    
    *dest = sum0 + sum1 + sum2 + sum3
}

void main()
{
    float dest[1] = {0.0f};
    float u[3] = {3.0, 2.0, 2.0};
    float v[3] = {3.0, 2.0, 2.0};
    
    inner2(u, v, 3, dest);
    
    printf("%f", dest);
}
