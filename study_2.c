#include <stdio.h>
#include <stdlib.h>
int count;

int iFact(int n){
    int r = 1;
    for (int i = 1; i<=n;i++){
        r *= i;
    }
    return r;
}

int rFact(int n){
    if(n  == 1){
        return 1;
    }
    else{
        return n * rFact(n-1);
    }
}
int qs1(){
    
    int N;
    scanf("%d",&N);
    printf("%d\n",iFact(N));
    printf("%d",rFact(N));
    return 0;
}

int iPower(int x,int n){
    int r = 1;
    for (int i = 1; i<=n;i++){
        r *= x;
    }
    return r;
}
int rPower(int x,int n){
    if(n  == 0){
        return 1;
    }
    else if(n%2 == 0){
        return rPower(x*x,n/2);
    }
    else{
        return x*rPower(x*x,(n-1)/2);
    }
}
int qs2(){
    int X,N;

    scanf("%d %d",&X,&N);
    printf("%d\n",iPower(X,N));
    printf("%d",rPower(X,N));
    return 0;
}

int iFib(int n){
    int pp = 0;
    int p = 1;
    int result = 0;
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    for( int i = 2;i<=n;i++){
        result = p+pp;
        pp=p;
        p = result;
    }
    return result;
}
int rFib(int n){
    count++;
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else{
        return rFib(n-1) + rFib(n-2);
    }
}
int qs3(){
    int N;
    scanf("%d",&N);
    printf("%d\n",iFib(N));
    printf("%d %d",rFib(N),count);
    
    return 0;
}

void hanoi(int n, char from, char tmp, char to){
    if (n == 1){
        printf("원판 1을 %c에서 %c로 옮긴다\n",from ,to);
    }
    else{
        hanoi(n-1,from, to, tmp); // from에서 to를 거쳐서 tmp로 이동
        printf("원판 %d을 %c에서 %c로 옮긴다\n",n,from, to);
        hanoi(n-1,tmp,from,to); // tmp에서 from을 거쳐 to로 이동
    }
}
int qs4(){
    hanoi(6,'A','B','C');
    return 0;

}
int main(){
    //qs1();
    //qs2();
    //qs3();
    qs4();
    return 0;
}