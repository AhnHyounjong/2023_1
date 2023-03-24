#include <stdio.h>
#include <stdlib.h>

#define N 20

typedef struct Poly{
    int degree;
    int coef[N];
}Poly;

typedef struct Poly2{
    int coef;
    int expon;
}Poly2;

Poly addPoly(Poly A, Poly B){
    Poly C;
    int Apos = 0, Bpos = 0, Cpos = 0;
    int degA = A.degree;
    int degB = B.degree;
    C.degree = (degA >= degB) ? degA : degB;
    
    while(Apos <= A.degree && Bpos <= B.degree){
        if (degA > degB){
            C.coef[Cpos] = A.coef[Apos];
            Apos++;
            Cpos++;
            degA--;
        }
        else if(degA == degB){
            C.coef[Cpos] = A.coef[Apos] + B.coef[Bpos];
            Apos++; Bpos++; Cpos++; degA--; degB--;
        }
        else{
            C.coef[Cpos] = B.coef[Bpos];
            Bpos++;
            Cpos++;
            degB--;
        }
    }
    return C;
}
void printPoly(Poly P){
    for(int i = 0, j = P.degree ; i < P.degree ; i++,j--){
        printf("%2dx^%d +",P.coef[i],j);
    }
    printf("%2d\n",P.coef[P.degree]);
    printf("\b\b \n");
}

int qs1(){
    Poly a, b, c;
    scanf("%d %d",&a.degree, &b.degree);
    for(int i = 0; i<=a.degree;i++){
        scanf("%d",&a.coef[i]);
    }
    for(int i = 0; i<=b.degree;i++){
        scanf("%d",&b.coef[i]);
    }
    printPoly(a);
    printPoly(b);
    printf("a + b\n");
    c = addPoly(a,b);
    printPoly(c);
    return 0;
}


Poly2 terms[N] = {{8,3},{7,1},{1,0},{10,3},{3,2},{1,0}}; // 이 방법을 사용하는 것은 좋지 않은 방법이다
int avail = 6;

void printPoly2(int s, int e){
    for(int i = s ; i<e ; i++){
        printf("%2dx^%d +",terms[i].coef, terms[i].expon);
    }
    printf("%2d\n",terms[e].coef);

    printf("\b\b \n");
}

char compare(int a, int b){
    if(a>b){
        return '>';
    }
    else if(a == b){
        return '=';
    }
    else{
        return '<';
    }
}

void attach(float coef, float expon){
    if(avail >N){
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail++].expon = expon;
}

 void addPoly2(int As, int Ae, int Bs, int Be, int *Ce){
    int tempCoef;
    while((As <= Ae) && (Bs <= Be)){
        switch(compare(terms[As].expon, terms[Bs].expon))
        {
        case '>':
            attach(terms[As].coef, terms[As].expon);
            As++;
            break;
        case '=':
            tempCoef = terms[As].coef + terms[Bs].coef;
            if (tempCoef != 0){
                attach(tempCoef, terms[As].expon);
            }
            As++, Bs++;
            break;
        case '<':
            attach(terms[Bs].coef, terms[Bs].expon);
            Bs++;
            break;
        }
    }
    //밑에 for문의 경우 As가 Ae보다 작다면 As를 계속 늘리면서 아래 구문을 실행해라
    for(; As <= Ae;As++){
        attach(terms[As].coef,terms[As].expon);
    }
    for(; Bs <= Be; Bs++){
        attach(terms[Bs].coef,terms[Bs].expon);
    }
    *Ce = avail -1;
}

int qs2(){
    int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
    printPoly2(As, Ae);
    printPoly2(Bs, Be);
    Cs = avail;
    addPoly2(As, Ae, Bs, Be, &Ce);
    printPoly2(Cs,Ce);

    return 0;
}

int main(){
    //qs1();
    //qs2();
    return 0;
}