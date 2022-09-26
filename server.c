#include"server.h"
#include<stdlib.h>
#include<string.h>
ST_accountsDB_t data[255]={{50.55,0,"kkkkkkkkkkkkkkkkk"},
{50000.0,0,"mohmmed mostafa mo"},{49.0,1,"ahmed mostafa mohme"}};

ST_transaction_t data_ST_transaction_t[255]={0};

ST_accountsDB_t *accountRefrence;
EN_serverError_t isValidAccount(ST_cardData_t *cardData){
int i=0;
    while (i<=255){

   if( strcmp(cardData->primaryAccountNumber,data[i].primaryAccountNumber)== 0 )
   break;
i++;
   };
   if (i>=255)
    return DECLINED_STOLEN_CARD;
   if(i<255)
   {

   accountRefrence=&(data[i]);

      return SERVER_OK;
};
}

EN_serverError_t isAmountAvailable(ST_transaction_t *transData,ST_accountsDB_t *accountRefrence)
{
if((transData->terminalData.transAmount)<=(accountRefrence->balance))
return SERVER_OK;
else
    return LOW_BALANCE;
};
EN_serverError_t saveTransaction(ST_transaction_t *transData){
    int i=0;
    while (i<=255){

   if( strcmp(transData->cardHolderData.primaryAccountNumber,data[i].primaryAccountNumber)== 0 )
   break;
i++;
   }; if (i>=255)
    return SAVING_FAILED;
   if(i<255)
   {

   data[i].balance=(data[i].balance)-(transData->terminalData.transAmount);

printf("balnse is %f\n",data[i].balance);
      return SERVER_OK;
};

};

EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence)
{

EN_accountState_t x;

x=(accountRefrence->state);

if(x==0){

      return SERVER_OK;}
      else
        return BLOCKED;
};

EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t *transData)
{
int i=0;
    while (i<=255){

   if( strcmp((transData->cardHolderData.primaryAccountNumber),(data[i].primaryAccountNumber) )== 0 )
   break;
i++;
   }; if (i>=255)
    return TRANSACTION_NOT_FOUND;
   if(i<255)
   {
data_ST_transaction_t[i].transactionSequenceNumber=(data_ST_transaction_t[i].transactionSequenceNumber)++;

      return SERVER_OK;
};
};

EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{ST_accountsDB_t *acunt;
   EN_serverError_t x=1;
    ST_cardData_t *y;
   x=isValidAccount(&(transData->cardHolderData));
  acunt=accountRefrence;
   if(x==0){
        x=isBlockedAccount(acunt);
 if (x==0){
        x=isAmountAvailable(transData,acunt);
 if (x==0){
saveTransaction(transData);
getTransaction(transData->transactionSequenceNumber,transData);

return SERVER_OK;
};};};
};
