#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "carinfo.h"

int main(){
    
    struct Car cr;
    cr = dataInput();
    display1(cr.price, cr.engineCap);
    display2(cr);
    return 0;
}
struct Car dataINput(){

    struct Car cs;
    printf("Enter Brand : ");
    scanf("%20[^/n]%*c", cs.brand);

    printf("Enter Model : ");
    scanf("%20[^/n]%*c", cs.model);

    printf("Enter Price : ");
    scanf("%20[^/n]%*c", cs.price);

    printf("Enter Engine Cap: ");
    scanf("%20[^/n]%*c", cs.enc);


}
void display1(double p , int enc){
    printf("/n DISPLAY-2\n\n");
    printf("PRICE : %.2lf\n", p);
    printf("Engine Cap : %d\n", enc);
}
void display2(struct Car ct){

    printf("/n DISPLAY-2\n\n");
    printf("Brand : %s\n", ct.brand);
    printf("Model : %s\n", ct.model);
    printf("Price : %.2lf\n", ct.price);
    printf("Engine Cap : %d\n", ct.enc);

}
