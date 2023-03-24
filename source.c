
#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
    printf("a : %d, b : %d\n",*a,*b);

}
int qs1(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("a : %d, b : %d\n",a,b);

    swap(&a,&b);
    printf("a : %d, b : %d\n",a,b);
    return 0;
}

typedef struct Test{
    int id;
    int money;
}Test;


void add(Test *T,int ammount){
    T->money+= ammount;
    printf("%d : %d\n",(*T).id,(*T).money);

}
int qs2(){
    Test a;

    scanf("%d %d",&a.id,&a.money);
    printf("%d %d\n",a.id,a.money);

    printf("%d : %d\n",a.id,a.money);
    int ammount;
    scanf("%d",&ammount);
    add(&a,ammount);

    return 0;
}
int main(){
    //qs1();
    qs2();
    return 0;
}

