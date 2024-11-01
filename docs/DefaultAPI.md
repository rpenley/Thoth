# DefaultAPI

All URIs are relative to *https://api.stocktrading.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**DefaultAPI_accountsAccountIdGet**](DefaultAPI.md#DefaultAPI_accountsAccountIdGet) | **GET** /accounts/{accountId} | Retrieve details of a specific account
[**DefaultAPI_accountsPost**](DefaultAPI.md#DefaultAPI_accountsPost) | **POST** /accounts | Create a new trading account
[**DefaultAPI_ordersDelete**](DefaultAPI.md#DefaultAPI_ordersDelete) | **DELETE** /orders | Cancel an existing order
[**DefaultAPI_ordersGet**](DefaultAPI.md#DefaultAPI_ordersGet) | **GET** /orders | Retrieve a list of orders
[**DefaultAPI_ordersPost**](DefaultAPI.md#DefaultAPI_ordersPost) | **POST** /orders | Place a new order
[**DefaultAPI_ordersPut**](DefaultAPI.md#DefaultAPI_ordersPut) | **PUT** /orders | Update an existing order


# **DefaultAPI_accountsAccountIdGet**
```c
// Retrieve details of a specific account
//
account_t* DefaultAPI_accountsAccountIdGet(apiClient_t *apiClient, char *accountId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**accountId** | **char \*** |  | 

### Return type

[account_t](account.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DefaultAPI_accountsPost**
```c
// Create a new trading account
//
account_t* DefaultAPI_accountsPost(apiClient_t *apiClient, account_t *account);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**account** | **[account_t](account.md) \*** |  | 

### Return type

[account_t](account.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DefaultAPI_ordersDelete**
```c
// Cancel an existing order
//
void DefaultAPI_ordersDelete(apiClient_t *apiClient, order_t *order);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order** | **[order_t](order.md) \*** |  | 

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DefaultAPI_ordersGet**
```c
// Retrieve a list of orders
//
list_t* DefaultAPI_ordersGet(apiClient_t *apiClient, stock_trading_api_ordersGet_status_e status);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**status** | **stock_trading_api_ordersGet_status_e** |  | [optional] 

### Return type

[list_t](order.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DefaultAPI_ordersPost**
```c
// Place a new order
//
order_t* DefaultAPI_ordersPost(apiClient_t *apiClient, order_t *order);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order** | **[order_t](order.md) \*** |  | 

### Return type

[order_t](order.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DefaultAPI_ordersPut**
```c
// Update an existing order
//
void DefaultAPI_ordersPut(apiClient_t *apiClient, order_t *order);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order** | **[order_t](order.md) \*** |  | 

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

