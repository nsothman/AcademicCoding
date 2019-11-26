#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "the1_recursive.h"

#define MAX_CUST_REQUIREMENT 1000
#define MAX_SHIP_TYPE_COUNT 10
#define MAX_CUST_COUNT 10

int min_ships_required_recursive(int shipTypes[], int shipTypeCount, int customerRequirement)
{
  int x, tempResult;
  if (customerRequirement == 0)
  {
    return 0;
  }

  int result = MAX_CUST_REQUIREMENT;

  for (i = 0; x < shipTypeCount; x++)
  {
    if (shipTypes[x] <= customerRequirement)
    {
      tempResult = min_ships_required_recursive(shipTypes, shipTypeCount, customerRequirement - shipTypes[x]) + 1;

      if (tempResult < result)
      {
        result = tempResult;
      }
    }
  }
   return result;
}
