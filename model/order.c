#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "order.h"


char* order_type_ToString(stock_trading_api_order_TYPE_e type) {
    char* typeArray[] =  { "NULL", "buy", "sell" };
    return typeArray[type];
}

stock_trading_api_order_TYPE_e order_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "buy", "sell" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* order_status_ToString(stock_trading_api_order_STATUS_e status) {
    char* statusArray[] =  { "NULL", "open", "filled", "canceled" };
    return statusArray[status];
}

stock_trading_api_order_STATUS_e order_status_FromString(char* status){
    int stringToReturn = 0;
    char *statusArray[] =  { "NULL", "open", "filled", "canceled" };
    size_t sizeofArray = sizeof(statusArray) / sizeof(statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(status, statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

order_t *order_create(
    char *order_id,
    char *symbol,
    double quantity,
    stock_trading_api_order_TYPE_e type,
    stock_trading_api_order_STATUS_e status,
    char *account_id
    ) {
    order_t *order_local_var = malloc(sizeof(order_t));
    if (!order_local_var) {
        return NULL;
    }
    order_local_var->order_id = order_id;
    order_local_var->symbol = symbol;
    order_local_var->quantity = quantity;
    order_local_var->type = type;
    order_local_var->status = status;
    order_local_var->account_id = account_id;

    return order_local_var;
}


void order_free(order_t *order) {
    if(NULL == order){
        return ;
    }
    listEntry_t *listEntry;
    if (order->order_id) {
        free(order->order_id);
        order->order_id = NULL;
    }
    if (order->symbol) {
        free(order->symbol);
        order->symbol = NULL;
    }
    if (order->account_id) {
        free(order->account_id);
        order->account_id = NULL;
    }
    free(order);
}

cJSON *order_convertToJSON(order_t *order) {
    cJSON *item = cJSON_CreateObject();

    // order->order_id
    if (!order->order_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "orderId", order->order_id) == NULL) {
    goto fail; //String
    }


    // order->symbol
    if (!order->symbol) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "symbol", order->symbol) == NULL) {
    goto fail; //String
    }


    // order->quantity
    if (!order->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", order->quantity) == NULL) {
    goto fail; //Numeric
    }


    // order->type
    if (stock_trading_api_order_TYPE_NULL == order->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", typeorder_ToString(order->type)) == NULL)
    {
    goto fail; //Enum
    }


    // order->status
    if (stock_trading_api_order_STATUS_NULL == order->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", statusorder_ToString(order->status)) == NULL)
    {
    goto fail; //Enum
    }


    // order->account_id
    if (!order->account_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "accountId", order->account_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

order_t *order_parseFromJSON(cJSON *orderJSON){

    order_t *order_local_var = NULL;

    // order->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(orderJSON, "orderId");
    if (!order_id) {
        goto end;
    }

    
    if(!cJSON_IsString(order_id))
    {
    goto end; //String
    }

    // order->symbol
    cJSON *symbol = cJSON_GetObjectItemCaseSensitive(orderJSON, "symbol");
    if (!symbol) {
        goto end;
    }

    
    if(!cJSON_IsString(symbol))
    {
    goto end; //String
    }

    // order->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(orderJSON, "quantity");
    if (!quantity) {
        goto end;
    }

    
    if(!cJSON_IsNumber(quantity))
    {
    goto end; //Numeric
    }

    // order->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(orderJSON, "type");
    if (!type) {
        goto end;
    }

    stock_trading_api_order_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = order_type_FromString(type->valuestring);

    // order->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(orderJSON, "status");
    if (!status) {
        goto end;
    }

    stock_trading_api_order_STATUS_e statusVariable;
    
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = order_status_FromString(status->valuestring);

    // order->account_id
    cJSON *account_id = cJSON_GetObjectItemCaseSensitive(orderJSON, "accountId");
    if (!account_id) {
        goto end;
    }

    
    if(!cJSON_IsString(account_id))
    {
    goto end; //String
    }


    order_local_var = order_create (
        strdup(order_id->valuestring),
        strdup(symbol->valuestring),
        quantity->valuedouble,
        typeVariable,
        statusVariable,
        strdup(account_id->valuestring)
        );

    return order_local_var;
end:
    return NULL;

}
