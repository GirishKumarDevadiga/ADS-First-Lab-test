#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../Headers/stock.h"
#include "../Headers/appconst.h"

TradingQ tradingq_new() {
   TradingQ q1 = { NULL, NULL, 0 };
   return q1;
}

TradingTransactions tradingtransaction_new() {
   TradingTransactions q1 = { NULL, NULL, 0 };
   return q1;
}

uint32_t tradingq_length(const TradingQ *tradingq) {
    assert(tradingq != NULL);
    return tradingq-> length;
}

static Node* _get_new_node_(PersonShare val) {
     Node *newnode = (Node*)malloc(sizeof(Node));
     newnode->data = val;
     newnode->next = NULL;
     
     return newnode;
}

static TransactionNode* _get_transaction_node_(Transactions val) {
     TransactionNode *transactionnode = (TransactionNode*)malloc(sizeof(TransactionNode));
     transactionnode->data = val;
     transactionnode->next = NULL;
     
     return transactionnode;
}


static TradingTransactions* transactions_addnode_rear(TradingTransactions *transactions, Node *newnode, int8_t transactiontype){
    assert(transactions != NULL);
    Transactions val = {newnode->data.sharename, newnode->data.date, newnode->data.price, newnode->data.quantity};
    
    TransactionNode *transactionnode = _get_transaction_node_(val);
    
    if(transactions->rear != NULL){
	       transactionnode->next = transactions->rear;
	       
	       transactions->rear = transactionnode;
	    } else {
	       transactions->rear = transactions->front = transactionnode;
	    }

    
    return transactions;
}


TradingQ* tradingq_addnode_rear(TradingQ *tradingq, TradingTransactions *transactions, PersonShare val, newnode, int8_t dequelength) {
    assert(tradingq != NULL);
    Node *newnode = _get_new_node_(val);
    
    if (dequelength > 0){
     for(int i = 0; i <= dequelength; ++i){
        tradingq = tradingq_delnode_front(TradingQ *tradingq, TradingTransactions *transactions);
     }
  }
      
    
    if(tradingq->length < MAX_SHARE){
           
	    if(tradingq->rear != NULL){
	       newnode->next = tradingq->rear;
	       
	       tradingq->rear = newnode;
	    } else {
	       tradingq->rear = tradingq->front = newnode;
	    }
	    
	   transactions = transactions_addnode_rear(transactions, newnode, 1);
	   
           ++tradingq->length;
    
    }
    
    assert((TradingQ->length == 1 && TradingQ->front == TradingQ->rear) ||
           (TradingQ->length > 1 && TradingQ->front != TradingQ->rear));
    
    return tradingq;
}

TradingQ* tradingq_delnode_front(TradingQ *tradingq, TradingTransactions *transactions,  int32_t quantity) {
       assert(tradingq != NULL);
       Node *last, *cur;
       
       assert(quantity <= tradingq->front->data.quantity);
       
       if(quantity < tradingq->front->data.quantity){
        tradingq->front->data.quantity - quantity;
        transactions = transactions_addnode_rear(transactions, tradingq->front, 0);
       }
       else {
       
       if(tradingq->front != NULL) {
          last = tradingq->front;
          if(tradingq->rear == tradingq->front){
             tradingq->rear = tradingq->front = NULL;
          } else {
             for(cur = tradingq->rear; cur->next != last; cur = cur->next);
             tradingq->front = cur;
             cur->next = NULL;
          }
          --tradingq->length;
          transactions = transactions_addnode_rear(transactions, last, 0);
          free(last);
          
       }
       }
       

       
       return tradingq;
}

uint32_t tradingq_lookup(const TradingQ *tradingq, char company_name[20]){
      assert(tradingq != NULL);
      Node *cur;
      
      for(cur = tradingq->rear; cur != NULL; cur = cur->next){
           if (cur->data.sharename == company_name){
             break;
           }
      }
      
      return (cur != NULL);
      
}





















