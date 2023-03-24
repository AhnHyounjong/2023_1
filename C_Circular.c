/* 
- 특별한 언급이 없으면 문제의 조건에 맞지 않는 입력은 입력되지 않는다고 가정하라. 
- 특별한 언급이 없으면, 각 줄의 맨 앞과 맨 뒤에는 공백을 출력하지 않는다.
- 출력 예시에서 □는 각 줄의 맨 앞과 맨 뒤에 출력되는 공백을 의미한다.
- 입출력 예시에서 ↦ 이 후는 각 입력과 출력에 대한 설명이다.
*/
#include <stdio.h>
#include <stdlib.h>

//qs1//
int sum(int a){
    if(a <= 1){
        return 1;
    }
    return sum(a-1)+a;
}
int qs1(){
    int N;

    scanf("%d",&N);
    printf("%d",sum(N));
    return 0;
}

//qs2//
void high_num(int a){
    if(a < 10){
        printf("%d\n",a);
    }
    else{
        high_num(a/10);
        printf("%d\n",(a%10));
    }
}
int qs2(){
    int a;
    scanf("%d",&a);
    high_num(a);
    return 0;
}

//qs3//
void low_num(int a){
    if(a < 10){
        printf("%d\n",a);
    }
    else{
        printf("%d\n",(a%10));
        low_num(a/10);
    }
}
int qs3(){
    int a;
    scanf("%d",&a);
    low_num(a);
    return 0;
}

//qs4//
int find_max_num(int *n, int num){
    if (num == 1){
        return n[0];
    }
    else{
        if(n[num]>find_max_num(n,num-1)){ //배열 n에서 자신이 입력한 num의 자리에 있는 수를 num-1하면서 찾아 내려간다.
            return n[num]; //그러다가 가장 큰 수가 나타나면반환
        }
        else{
            return find_max_num(n,num-1); //num의 값을 조건문에 걸릴 떼까지 내림
        }
    }
}

int qs4(){
    int arr[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int a;
    scanf("%d",&a);
    for(int i = 0; i<a;i++){
            scanf("%d",&arr[i]);
        }
    printf("%d",find_max_num(arr,a));
    
    return 0;
}

//qs5//
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
int qs5(){
    int a;
    scanf("%d",&a);
    hanoi(a,'A','B','C');
    return 0;

}

//qs6//
int gcd(int a,int b){
    if(b == 0){
        return(a);
    }else{
        return(gcd(b,a%b));
    }
}
int qs6(){
    int a, b;
    int tmp = 0;
    scanf("%d %d",&a, &b);
    if(b > a){
        tmp = a;
        a = b;
        b = tmp;
    }
    if(b<a){
        a = a;
        b = b;
    }
    printf("%d",gcd(a,b));
    return 0;
}
int main(){
    //qs1();
    //qs2();
    //qs3();
    //qs4();
    //qs5();
    qs6();
    return 0;
}