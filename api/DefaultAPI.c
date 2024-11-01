#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "DefaultAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)

// Functions for enum STATUS for DefaultAPI_ordersGet

static char* ordersGet_STATUS_ToString(stock_trading_api_ordersGet_status_e STATUS){
    char *STATUSArray[] =  { "NULL", "open", "filled", "canceled" };
    return STATUSArray[STATUS];
}

static stock_trading_api_ordersGet_status_e ordersGet_STATUS_FromString(char* STATUS){
    int stringToReturn = 0;
    char *STATUSArray[] =  { "NULL", "open", "filled", "canceled" };
    size_t sizeofArray = sizeof(STATUSArray) / sizeof(STATUSArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(STATUS, STATUSArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

/*
// Function ordersGet_STATUS_convertToJSON is not currently used,
// since conversion to JSON passes through the conversion of the model, and ToString. The function is kept for future reference.
//
static cJSON *ordersGet_STATUS_convertToJSON(stock_trading_api_ordersGet_status_e STATUS) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "status", ordersGet_STATUS_ToString(STATUS)) == NULL) {
        goto fail;
    }
    return item;
    fail:
    cJSON_Delete(item);
    return NULL;
}

// Function ordersGet_STATUS_parseFromJSON is not currently used,
// since conversion from JSON passes through the conversion of the model, and FromString. The function is kept for future reference.
//
static stock_trading_api_ordersGet_status_e ordersGet_STATUS_parseFromJSON(cJSON* STATUSJSON) {
    stock_trading_api_ordersGet_status_e STATUSVariable = 0;
    cJSON *STATUSVar = cJSON_GetObjectItemCaseSensitive(STATUSJSON, "status");
    if(!cJSON_IsString(STATUSVar) || (STATUSVar->valuestring == NULL))
    {
        goto end;
    }
    STATUSVariable = ordersGet_STATUS_FromString(STATUSVar->valuestring);
    return STATUSVariable;
end:
    return 0;
}
*/


// Retrieve details of a specific account
//
account_t*
DefaultAPI_accountsAccountIdGet(apiClient_t *apiClient, char *accountId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/accounts/{accountId}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/accounts/{accountId}");


    // Path Params
    long sizeOfPathParams_accountId = strlen(accountId)+3 + strlen("{ accountId }");
    if(accountId == NULL) {
        goto end;
    }
    char* localVarToReplace_accountId = malloc(sizeOfPathParams_accountId);
    sprintf(localVarToReplace_accountId, "{%s}", "accountId");

    localVarPath = strReplace(localVarPath, localVarToReplace_accountId, accountId);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Account details");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Account not found");
    //}
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    account_t *elementToReturn = account_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_accountId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Create a new trading account
//
account_t*
DefaultAPI_accountsPost(apiClient_t *apiClient, account_t *account)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/accounts")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/accounts");




    // Body Param
    cJSON *localVarSingleItemJSON_account = NULL;
    if (account != NULL)
    {
        //string
        localVarSingleItemJSON_account = account_convertToJSON(account);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_account);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","Account created successfully");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request data");
    //}
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    account_t *elementToReturn = account_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_account) {
        cJSON_Delete(localVarSingleItemJSON_account);
        localVarSingleItemJSON_account = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Cancel an existing order
//
void
DefaultAPI_ordersDelete(apiClient_t *apiClient, order_t *order)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/orders")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/orders");




    // Body Param
    cJSON *localVarSingleItemJSON_order = NULL;
    if (order != NULL)
    {
        //string
        localVarSingleItemJSON_order = order_convertToJSON(order);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_order);
    }
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Order canceled successfully");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Order not found");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_order) {
        cJSON_Delete(localVarSingleItemJSON_order);
        localVarSingleItemJSON_order = NULL;
    }
    free(localVarBodyParameters);

}

// Retrieve a list of orders
//
list_t*
DefaultAPI_ordersGet(apiClient_t *apiClient, stock_trading_api_ordersGet_status_e status)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/orders")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/orders");




    // query parameters
    char *keyQuery_status = NULL;
    stock_trading_api_ordersGet_status_e valueQuery_status ;
    keyValuePair_t *keyPairQuery_status = 0;
    if (status)
    {
        keyQuery_status = strdup("status");
        valueQuery_status = (status);
        keyPairQuery_status = keyValuePair_create(keyQuery_status, (void *)strdup(ordersGet_STATUS_ToString(
        valueQuery_status)));
        list_addElement(localVarQueryParameters,keyPairQuery_status);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","List of orders");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No orders found");
    //}
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    if(!cJSON_IsArray(DefaultAPIlocalVarJSON)) {
        return 0;//nonprimitive container
    }
    list_t *elementToReturn = list_createList();
    cJSON *VarJSON;
    cJSON_ArrayForEach(VarJSON, DefaultAPIlocalVarJSON)
    {
        if(!cJSON_IsObject(VarJSON))
        {
           // return 0;
        }
        char *localVarJSONToChar = cJSON_Print(VarJSON);
        list_addElement(elementToReturn , localVarJSONToChar);
    }

    cJSON_Delete( DefaultAPIlocalVarJSON);
    cJSON_Delete( VarJSON);
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_status){
        free(keyQuery_status);
        keyQuery_status = NULL;
    }
    if(keyPairQuery_status){
        keyValuePair_free(keyPairQuery_status);
        keyPairQuery_status = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Place a new order
//
order_t*
DefaultAPI_ordersPost(apiClient_t *apiClient, order_t *order)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/orders")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/orders");




    // Body Param
    cJSON *localVarSingleItemJSON_order = NULL;
    if (order != NULL)
    {
        //string
        localVarSingleItemJSON_order = order_convertToJSON(order);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_order);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","Order placed successfully");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request data");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Insufficient funds");
    //}
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    order_t *elementToReturn = order_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_order) {
        cJSON_Delete(localVarSingleItemJSON_order);
        localVarSingleItemJSON_order = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update an existing order
//
void
DefaultAPI_ordersPut(apiClient_t *apiClient, order_t *order)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/orders")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/orders");




    // Body Param
    cJSON *localVarSingleItemJSON_order = NULL;
    if (order != NULL)
    {
        //string
        localVarSingleItemJSON_order = order_convertToJSON(order);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_order);
    }
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PUT");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Order updated successfully");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Order not found");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_order) {
        cJSON_Delete(localVarSingleItemJSON_order);
        localVarSingleItemJSON_order = NULL;
    }
    free(localVarBodyParameters);

}

