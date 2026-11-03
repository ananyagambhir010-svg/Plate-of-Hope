#include <stdio.h>
#include <string.h>
#define MAX 50
struct Food 
{
  int id;
  char name[50];
  int quantity;
  int expiryHours;
};
struct Recipient {
    int id;
    char name[50];
    int requiredQuantity;
    int urgency;
    int receivedQuantity;
};
struct Food food[MAX];
struct Recipient recipient[MAX];
int foodCount = 0;
int recipientCount = 0;
void addFood()
{
  if (foodCount >= MAX)
  {
    printf("\nMaximum food donations reached.\n");
    return;
  }
  food[foodCount].id = foodCount + 1;
  printf("\nEnter food name: ");
  scanf(" %[^\n]", food[foodCount].name);
  printf("Enter quantity (in portions): ");
  scanf("%d", &food[foodCount].quantity);
  printf("Enter expiry time (in hours): ");
  scanf("%d", &food[foodCount].expiryHours);
  foodCount++;
  printf("\nFood donation added successfully!\n");
}
void addRecipient()
{
  if (recipientCount >= MAX)
  {
    printf("\nMaximum recipients reached.\n");
    return;
  }
  recipient[recipientCount].id = recipientCount + 1;
  printf("\nEnter recipient/organization name: ");
  scanf(" %[^\n]", recipient[recipientCount].name);
  printf("Enter required quantity: ");
  scanf("%d", &recipient[recipientCount].requiredQuantity);
  printf("Enter urgency level (1-Low, 2-Medium, 3-High): ");
  scanf("%d", &recipient[recipientCount].urgency);
  recipient[recipientCount].receivedQuantity = 0;
  recipientCount++;
  printf("\nRecipient added successfully!\n");
}
void displayFood()
{
  int i;
  if (foodCount == 0)
  {
    printf("\nNo food donations available.\n");
    return;
  }
  printf("\n========== FOOD DONATIONS ==========\n");
  for (i = 0; i < foodCount; i++)
  {
    printf("\nFood ID       : %d", food[i].id);
    printf("\nFood Name     : %s", food[i].name);
    printf("\nQuantity      : %d portions", food[i].quantity);
    printf("\nExpiry Time   : %d hours", food[i].expiryHours);
    printf("\n------------------------------------");
  }
  printf("\n");
}
void displayRecipients()
{
  int i;
  if (recipientCount == 0)
  {
    printf("\nNo recipients available.\n");
    return;
  }
  printf("\n========== RECIPIENTS ==========\n");
  for (i = 0; i < recipientCount; i++)
  {
    printf("\nRecipient ID      : %d", recipient[i].id);
    printf("\nName              : %s", recipient[i].name);
    printf("\nRequired Quantity : %d", recipient[i].requiredQuantity);
    printf("\nUrgency Level     : %d", recipient[i].urgency);
    printf("\nReceived Quantity : %d", recipient[i].receivedQuantity);
    printf("\n--------------------------------");
  }
  printf("\n");
}
void redistributeFood()
{
  int i, j;
  int remainingFood;
  int requiredFood;
  int distributed;
  if (foodCount == 0 || recipientCount == 0)
  {
    printf("\nPlease add food and recipients first.\n");
    return;
  }
  printf("\n========== FOOD REDISTRIBUTION ==========\n");
  for (i = 0; i < foodCount; i++)
  {
    remainingFood = food[i].quantity;
    for (j = 0; j < recipientCount; j++)
    {
      requiredFood = recipient[j].requiredQuantity - recipient[j].receivedQuantity;
      if (requiredFood > 0 && remainingFood > 0)
      {
        if (remainingFood <= requiredFood)
        {
          distributed = remainingFood;
        }
        else
        {
          distributed = requiredFood;
        }
        recipient[j].receivedQuantity = recipient[j].receivedQuantity + distributed;
        remainingFood = remainingFood - distributed;
        printf("\nFood: %s", food[i].name);
        printf("\nGiven to: %s", recipient[j].name);
        printf("\nQuantity Distributed: %d portions",distributed);
        printf("\n----------------------------------------\n");
      }
    }
  }
  printf("\nFood redistribution completed!\n");
}
void expiryWarning()
{
  int i;
  if (foodCount == 0)
  {
    printf("\nNo food donations available.\n");
    return;
  }
  printf("\n========== EXPIRY WARNINGS ==========\n");
  for (i = 0; i < foodCount; i++)
  {
    if (food[i].expiryHours <= 4)
    {
      printf("\nURGENT: %s expires in %d hours!",food[i].name,food[i].expiryHours);
    }
    else if (food[i].expiryHours <= 12)
    {
      printf("\nWARNING: %s expires in %d hours.",food[i].name,food[i].expiryHours);
    }
    else
    {
      printf("\n%s has sufficient expiry time.",food[i].name);
    }
  }
  printf("\n");
}
void finalReport()
{
  int i;
  int totalFood = 0;
  int totalReceived = 0;
  printf("\n========== FINAL REPORT ==========\n");
  for (i = 0; i < foodCount; i++)
  {
    totalFood = totalFood + food[i].quantity;
  }
  for (i = 0; i < recipientCount; i++)
  {
    totalReceived = totalReceived + recipient[i].receivedQuantity;
  }
  printf("\nTotal Food Donated: %d portions",totalFood);
  printf("\nTotal Food Distributed: %d portions",totalReceived);
  printf("\nFood Remaining: %d portions",totalFood - totalReceived);
  printf("\n\nRecipient Status:\n");
  for (i = 0; i < recipientCount; i++)
  {
    printf("\n%s", recipient[i].name);
    printf("\nRequired : %d",recipient[i].requiredQuantity);
    printf("\nReceived : %d",recipient[i].receivedQuantity);
    if (recipient[i].receivedQuantity >= recipient[i].requiredQuantity)
    {
      printf("\nStatus   : Requirement Fulfilled");
    }
    else
    {
      printf("\nStatus   : More Food Required");
    }
      printf("\n--------------------------------");
}
  printf("\n");
}
int main()
{
  int choice;
  do
  {
    printf("\n\n========================================");
    printf("\n     FOOD WASTE REDISTRIBUTION SYSTEM");
    printf("\n========================================");
    printf("\n1. Add Food Donation");
    printf("\n2. Add Recipient");
    printf("\n3. Display Food Donations");
    printf("\n4. Display Recipients");
    printf("\n5. Redistribute Food");
    printf("\n6. Check Expiry Warnings");
    printf("\n7. Generate Final Report");
    printf("\n8. Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
      case 1:
      addFood();
      break;
      case 2:
      addRecipient();
      break;
      case 3:
      displayFood();
      break;
      case 4:
      displayRecipients();
      break;
      case 5:
      redistributeFood();
      break;
      case 6:
      expiryWarning();
      break;
      case 7:
      finalReport();
      break;
      case 8:
      printf("\nThank you for using the system!\n");
      break;
      default:
      printf("\nInvalid choice! Please try again.\n");
    }
  } 
  while (choice != 8);
  return 0;
}
