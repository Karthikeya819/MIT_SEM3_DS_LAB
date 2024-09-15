/*
Vignesh and his wife Lata are facing a cash crisis.  They go to the nearby ATM to get some cash. 
There are 3 ATMs inside the same room. People are standing in queue outside, and go inside the room in groups 
of 3 to the ATMs, fetch their money and come out. Lata has an irrational fear in getting money from ATM that 
her ATM pin will somehow be stolen and her money will be lost. So she will always like to go into room with 
Vignesh. Vignesh is standing at position K in line, immediately followed by lata (at position K+1). Can you 
tell whether Vignesh and Lata both will be able to get money in such a way that Lata does not feel insecure?
Using queue, find whether they can get money for the given set of N and K. Input: the first line contains an 
integer T denoting the number of test cases. T test cases follow. The only line of each test case contains 
two spaces separated integers N and K , Where N denotes number of people in the queue. And K denotes the 
position of Vignesh.
*/

#include <stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    int Output[T];
    int i = 0;
    while(T--){
        int N,K;
        scanf("%d %d",&N,&K);
        Output[i++] = ((K - 1)/3) == (((K+1)-1)/3);
    }
    for(int j = 0;j<i;j++)printf("%s \n",(Output[j])?"Yes":"No");
    return 0;
}