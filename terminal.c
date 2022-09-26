
#include"terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData){
    printf("pleas enter Transaction Date \n");
    gets(termData->transactionDate);
uint8_t i=0;
while(termData->transactionDate[i]!=0)
    {++i;

    };

    if((i==10)&&(termData->transactionDate[2]==termData->transactionDate[5])){
return  OK;
}

else {

return WRONG_DATE;


};
}
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData){
uint8_t x,y,z,u;

x=termData.transactionDate[9]+termData.transactionDate[8]*10;

z=termData.transactionDate[4]+termData.transactionDate[3]*10;

y=cardData.cardExpirationDate[4]+cardData.cardExpirationDate[3]*10;

u=cardData.cardExpirationDate[1]+cardData.cardExpirationDate[0]*10;
if(x<y)
    return  OK;
else if((x==y)&&(z<=u))
    return  OK;
else
     return EXPIRED_CARD;
};
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
printf("pleas enter Transaction amount ");
scanf("%f",&(termData->transAmount));

if(termData->transAmount<=0)
{
    return INVALID_AMOUNT;
}
else

    return OK;};
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
float x,y;
x=termData->maxTransAmount;
y=termData->transAmount;
x=x-y;
if(x>=0){
     return OK;
}
else
{
    return EXCEED_MAX_AMOUNT;
}
};
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData){

(*termData).maxTransAmount=5000;

if(termData->maxTransAmount>0)
    return OK;

else
    return INVALID_MAX_AMOUNT;


};


