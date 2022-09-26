#include <stdio.h>
#include"card.h"
#include"terminal.h"
#include"server.h"
int main(){
    EN_cardError_t x1,x2,x3;
    EN_terminalError_t y1,y2,y3,y4;
    EN_serverError_t z1;
    EN_transState_t  a1;
    ST_cardData_t x;
    ST_terminalData_t y;

   x1= getCardHolderName(&x);
  x2= getCardExpiryDate(&x);
  x3=getCardPAN(&x);

  y1=getTransactionDate(&y);
 y2 =isCardExpired(x,y);
 if(y2==0){
    setMaxAmount(&y);
    y3= getTransactionAmount(&y);
    y4= isBelowMaxAmount(&y);


   ST_transaction_t z={x,y,0,0};
    if((y4==0)&&(y3==0)){


       a1= recieveTransactionData(&z);
       if(a1==0)
printf("accept\n");
else
    printf("error\n");

    }
    else
        printf("error\n");

 };
return 0;
}

