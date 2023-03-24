#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int qs1(){
    int K,N,M;
    int total;
    total = (K*N);
    scanf("%d%d%d",&K,&N,&M);
    if(M<total){
        printf("%d",total-M);
    }
    else{
        printf("0");
    }
    return 0; 


}

int qs2(){
    int grade = 0;
    scanf("%d",&grade);
    if((0<=grade)&&(grade<=100)){
        if((90<=grade)&&(grade<=100)){
            printf("A");
        }
        else if((80<=grade)&&(grade<90)){
            printf("B");
        }
        else if((70<=grade)&&(grade<80)){
            printf("C");
        }
        else{
            printf("D or F");
        }
    }
    else{
        printf("Wrong Input");
        return 0;
    }
    return 0;
}

int qs3(){
    int grade = 0;
    scanf("%d",&grade);
    if((0>grade)||(grade>100)){
        printf("Wrong Input");
        return 0;
    }
    switch(grade/10){
        case 10:
            printf("A");
            break;
        case 9:
            printf("A");
            break;
        case 8:
            printf("B");
            break;
        case 7:
            printf("C");
            break;
        default :
            printf("D or F");
            break;
    }
    return 0;

}
int qs4(){
    int num;
    int i;
    
    scanf("%d",&num);
    /*
    char* num1 = (char*)malloc(sizeof(int)*num);
    sprintf(num1,"%d",num);

    for ( i = strlen(num1); i >= 0;i--){
        printf("%c\n",num1[i]);
    }
    
    free(num1);
*/
    int n;
    while(n!=0){
        printf("%d\n",n%10);
        n = n/10;
    }
    
    return 0;
}

int qs5(){
    int N;
    int sum1 = 0;
    int sum2 = 0;
    int i,j;
    scanf("%d",&N);

    for (int j = 2; j<=N;j+=2){
    sum2 += j;
    }
    
    
    for (int i = 1; i<=N;i+=2){
    sum1 += i;
    }

    printf("정수의 합 : %d\n",sum2);
    printf("홀수의 합 : %d",sum1);   
    return 0;
}

int sumOfWeghit(int g){
    int cnt = 0;
    for(int i = 1; i <= 10 ; i++){
        for(int j = 1; j<= 10 ; j++){
            for(int k = 1; k<=10;k++){
                if ( g == (i*2) + (j*3) + (k*5)){
                    printf("\n%d  %d  %d", i, j, k);
                    cnt++;
                }
            }
        }
    }
    return cnt;

}
int qs6(){
    int g;
    int sum;
    scanf("%d",&g);
    sum = sumOfWeghit(g);
    if (sum == 0){
        printf("0\n");
    }
    else{
        printf("\n%d",sum);

    }
    return 0;
}
void makeArray(int arr[],int ber){
    for (int i = 0; i<ber;i++){
        arr[i] = rand()%100 + 1;
    }
}
void printArray(int arr[],int ber){
    for (int i = 0; i<ber;i++){
        printf("%d ",arr[i]);
    }
}
void findMax(int arr[],int ber){
    int tmp = arr[0];
    for (int j = 0; j<ber;j++){
        
        if(arr[j]>tmp){
            tmp = arr[j];
        }else{
            tmp = tmp;
        }
    }
    printf("\n%d",tmp);

}
int qs7(){
    int ber;
    int tmp;
    scanf("%d",&ber);
    srand(time(NULL));
    int arr[ber];
    makeArray(arr,ber);
    printArray(arr,ber);
    findMax(arr,ber);
    
    
    return 0;
}

int qs8(){
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0,n6 = 0;
    int num = 0;
    srand(time(NULL));

    for(int i = 1;i<=10000;i++){
        num = rand()%6+1;
        if(num == 1){
            n1+=1;  
        }
        else if(num == 2){
            n2+=1;
        }
        else if(num == 3){
            n3+=1;
        }
        else if(num == 4){
            n4+=1;
        }
        else if(num == 5){
            n5+=1;
        }
        else{
            n6+=1;
        }
    }
    printf("1 : %d\n2 : %d\n3 : %d\n4 : %d\n5 : %d\n6 : %d",n1,n2,n3,n4,n5,n6);
    return 0;
}
int qs9(){
    int arr[3][4] = {0,1,2,3,10,11,12,13,20,21,22,23};
    int cnt = 0;
    for(int i = 0; i<3;i++){
        printf("\n");
        for(int j = 0; j<4;j++){
            printf("%02d ",arr[i][j]);
        }
    }
    return 0;
}

int qs10(){
    int arr[3][4];
    int a;
    int sum = 0;
    for (int i = 0; i<3;i++){
        for (int j = 0; j<4;j++){
            scanf("%d",&a);
            arr[i][j] = a;
        }
    }
    printf("행열 : ");
    for(int r = 0; r<3;r++){
        printf("\n");
        for (int k = 0; k<4; k++){
            printf("%02d ",arr[r][k]);
        }
    }
    printf("\n");
    printf("\n");
    for(int r = 0; r<4;r++){
        for (int k = 0; k<3; k++){
            sum += arr[k][r];
        }
        printf("%d 행의 합 : %d\n",r+1,sum);
        sum = 0;
    }
    sum = 0;
    printf("\n");
    for(int r = 0; r<3;r++){
        for (int k = 0; k<4; k++){
            sum += arr[r][k];
        }
        printf("%d 열의 합 : %d\n",r+1,sum);
        sum = 0;
    }
    return 0;
}
int main(){
    //qs1();
    //qs2();
    //qs3();
    //qs4();
    //qs5();
    //qs6();
    qs7();
    //qs8();
    //qs9();
    //qs10();
    return 0;

}