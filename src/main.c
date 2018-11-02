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
void prod_code_scan(const char prod_code[], char *warehouse, char *id, char *qualifier);

int main(void)
{
  char *warehouse, *prod_id, *qualifier;
  char prod_code[] = "ATL1203S14";
  size_t max_chars = strlen(prod_code);

  warehouse = talloc(max_chars);
  prod_id = talloc(max_chars);
  qualifier = talloc(max_chars);

  prod_code_scan(prod_code, warehouse, prod_id, qualifier);

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
 * @param[out] The items location
 * @param[out] The items id
 * @param[out] The items qualifier
*/
void prod_code_scan(const char prod_code[], char *warehouse, char *id, char *qualifier)
{
  int i = 0;

  while (strlen(qualifier) < 1)
  {
    if (isdigit(prod_code[i]) && strlen(warehouse) < 1)
      strncpy(warehouse, &prod_code[0], i);
    else if (strlen(warehouse) > 0 && !isdigit(prod_code[i]) && isupper(prod_code[i]))
      strncpy(id, &prod_code[strlen(warehouse)], i - strlen(warehouse));
    else if (strlen(id) > 0)
      strncpy(qualifier, &prod_code[strlen(warehouse) + strlen(id)], strlen(prod_code) - strlen(id) - strlen(warehouse));

    i++;
  }
}
