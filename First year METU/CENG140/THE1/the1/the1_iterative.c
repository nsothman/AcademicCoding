#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "the1_iterative.h"

#define MAX_CUST_REQUIREMENT 1000
#define MAX_SHIP_TYPE_COUNT 10
#define MAX_CUST_COUNT 10

int min_ships_required_iterative(int shipTypes[], int shipTypeCount, int customerRequirement)
{
    int resultArray[customerRequirement + 1];
		int tempResult, x, y, z;
    resultArray[0] = 0;

    for (x = 1; x <= customerRequirement; x++)
		{
			resultArray[x] = MAX_CUST_REQUIREMENT;
		}

    for (y = 1; y <= customerRequirement; y++)
    {
        for (z = 0; z < shipTypeCount; z++)
          if (shipTypes[z] <= y)
          {
              tempResult = resultArray[y - shipTypes[z]];
              if (tempResult + 1 < resultArray[y])
              {
                resultArray[y] = tempResult + 1;
              }
          }
    }
    return resultArray[customerRequirement];
}
