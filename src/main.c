/*
 * Programmer: Henrik A. Christensen     Date Completed: in progress
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
 * Size: 14
 * Warehouse: ATL (Atlanta)
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int i;
  char warehouse[25], prod_id[25], qualifier[25];
  char str_in[] = "ATL1203S14";

  for (i = 0; i < strlen(warehouse); i++)
  {
    warehouse[i] = '\0';
    prod_id[i] = '\0';
    qualifier[i] = '\0';
  }

  while (strlen(qualifier) < 1)
  {
    if (isdigit(str_in[i]) && strlen(warehouse) < 1)
      strncat(warehouse, &str_in[0], i);
    else if (strlen(warehouse) > 0 && !isdigit(str_in[i]) && isupper(str_in[i]))
      strncat(prod_id, &str_in[strlen(warehouse)], i - strlen(warehouse));
    else if (strlen(prod_id) > 0)
      strncat(qualifier, &str_in[strlen(warehouse) + strlen(prod_id)], strlen(str_in) - strlen(prod_id) - strlen(warehouse));

    i++;
  }

  printf("\nWarehouse: %s", warehouse);
  printf("\nID: %s", prod_id);
  printf("\nQualifier: %s", qualifier);

  return EXIT_SUCCESS;
}
