#include <stdio.h>
#include <math.h>

int main(){
    float s=1,pi;
    int i,x=1;

    for(i; i<50; i++){
        if(i % 2 == 0){
            s = s -(1/(x+2))*(1/(x+2))*(1/(x+2));

            x=x+2;
        }else{
            s = s +(1/(x+2))*(1/(x+2))*(1/(x+2));
            x=x+2;
        }
    }

    pi = cbrtf(s*32);
    printf("valor de pi: %fl", pi);

    return 0;
}