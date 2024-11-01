#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/account.h"
#include "../model/order.h"

// Enum STATUS for DefaultAPI_ordersGet
typedef enum  { stock_trading_api_ordersGet_STATUS_NULL = 0, stock_trading_api_ordersGet_STATUS_open, stock_trading_api_ordersGet_STATUS_filled, stock_trading_api_ordersGet_STATUS_canceled } stock_trading_api_ordersGet_status_e;


// Retrieve details of a specific account
//
account_t*
DefaultAPI_accountsAccountIdGet(apiClient_t *apiClient, char *accountId);


// Create a new trading account
//
account_t*
DefaultAPI_accountsPost(apiClient_t *apiClient, account_t *account);


// Cancel an existing order
//
void
DefaultAPI_ordersDelete(apiClient_t *apiClient, order_t *order);


// Retrieve a list of orders
//
list_t*
DefaultAPI_ordersGet(apiClient_t *apiClient, stock_trading_api_ordersGet_status_e status);


// Place a new order
//
order_t*
DefaultAPI_ordersPost(apiClient_t *apiClient, order_t *order);


// Update an existing order
//
void
DefaultAPI_ordersPut(apiClient_t *apiClient, order_t *order);


