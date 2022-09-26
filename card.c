


#include"card.h"


EN_cardError_t getCardHolderName(ST_cardData_t *cardData){
    printf("pleas enter Card Holder Name \n");
    gets(cardData->cardHolderName);

    uint8_t i=0;

while(cardData->cardHolderName[i]!=0)
    {++i;};

if((i<19)||(i>23)){
return WRONG_NAME;

}
else {
return ok;

};
}
EN_cardError_t  getCardExpiryDate(ST_cardData_t *cardData){
    uint8_t i=0;
printf("pleas enter Card Expiry Date \n");
gets(cardData->cardExpirationDate);
while(cardData->cardExpirationDate[i]!=0)
    {++i;};

if(i!=5){

return WRONG_EXP_DATE;
}


else {

return ok;
 };

 }

EN_cardError_t getCardPAN(ST_cardData_t *cardData){
printf("pleas enter Card PAN\n");
gets(cardData->primaryAccountNumber);
uint8_t i=0;

while(cardData->primaryAccountNumber[i]!=0)
    {++i;
   };
if((i<15)||(i>18)){

return WRONG_PAN;}
else {
return ok;
};}
