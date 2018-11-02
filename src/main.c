/*
 * Programmer: Henrik A. Christensen     Date Completed: 02-11-2018
 * Instructor: Kurt Nørmark              Class:          Imperative Programming
 *
 * Write a program to take a product code from Millie's Mail-Order Catalog
 * seperate it into its component part.
 *
 * An MMOC product code begins with one or more letters identifying the warehouse
 * where the product is stored.
 * Next come the one or more digits that are the product ID.
 * The final field of the string starts with a capital letter and represents
 * qualifiers such as size, color and so on.
 *
 * Example: ATL1203S14
 *
 * Product: 1203
 * Qualifier: S14
 * Warehouse: ATL (Atlanta)
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *talloc(size_t num_chars);
void prod_code_scan(const char prod_code[], char *warehouse, char *id, char *qualifier, size_t len_prod_code);

int main(void)
{
  char *warehouse, *prod_id, *qualifier;
  char prod_code[] = "ATL1203S14";
  size_t len_prod_code = strlen(prod_code);

  warehouse = talloc(len_prod_code);
  prod_id = talloc(len_prod_code);
  qualifier = talloc(len_prod_code);

  prod_code_scan(prod_code, warehouse, prod_id, qualifier, len_prod_code);

  printf("\nWarehouse: %s", warehouse);
  printf("\nID: %s", prod_id);
  printf("\nQualifier: %s", qualifier);

  free(warehouse);
  free(prod_id);
  free(qualifier);

  return EXIT_SUCCESS;
}

/**
 * Allocate num_bytes and checks if allocation is possible
 * @param[in] num_chars Numbers of characters to allocate memory for
 * @return char *
*/
char *talloc(size_t num_chars)
{
  char *p = (char*)calloc(num_chars, sizeof(char));
  if (p == NULL)
  {
    printf("\nCouldn't allocate memory");
    exit(EXIT_FAILURE);
  }
  return p;
}

/**
 * Splits a production code into 3 pieces (warehouse location, item id, qualifier)
 * @param[in] Production code to split
 * @param[out] warehouse The items location
 * @param[out] id The items id
 * @param[out] qualifier The items qualifier
 * @param[in] len_prod_code The length of the production code
*/
void prod_code_scan(const char prod_code[], char *warehouse, char *id, char *qualifier, size_t len_prod_code)
{
  int i = 0;
  size_t len_warehouse = 0, len_id = 0, len_qua = 0;

  while (len_qua < 1)
  {
    if (isdigit(prod_code[i]) && len_warehouse < 1)
    {
      len_warehouse = i;
      strncpy(warehouse, &prod_code[0], len_warehouse);
    }
    else if (len_warehouse > 0 && !isdigit(prod_code[i]) && isupper(prod_code[i]))
    {
      len_id = i - len_warehouse;
      strncpy(id, &prod_code[strlen(warehouse)], len_id);
    }
    else if (len_id > 0)
    {
      len_qua = len_prod_code - (len_id + len_warehouse);
      strncpy(qualifier, &prod_code[len_warehouse + len_id], len_qua);
    }

    i++;
  }
}
