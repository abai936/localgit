#include <stdio.h>
#include <string.h>
#include <unistd.h>

// This program stores the inventory list for an electronics project

struct Component {
    char name[30];
    char units[5];
    int quantity;
    float rating;
};

int main() {
    int n;
    
    printf("Hi! Please check your components list before uploading...\n");
    printf("For example, if you have LEDs with the same features, write the name as 'LED'.\n");
    sleep(1);
    
    printf("\nHow many unique components do you have?\n");
    scanf("%d", &n);
    
    // Clear the leftover newline character from the buffer
    while (getchar() != '\n');
    
    // Create an array of 'n' components
    struct Component inventory[n];
    
    for (int i = 0; i < n; i++) {
        printf("\n--- Component %d ---\n", i + 1);
        
        printf("What is the name of the component?\n");
        fgets(inventory[i].name, 30, stdin);
        
        // Remove the trailing newline added by fgets
        inventory[i].name[strcspn(inventory[i].name, "\n")] = 0;
        
        printf("How many do you have?\n");
        scanf("%d", &inventory[i].quantity);
        
        printf("What is the value/rating of that component?\n");
        scanf("%f", &inventory[i].rating);
        
        printf("What is the SI unit of the component? (ex: A, V, uF, Ohm)\n");
        // No '&' is needed here because 'units' is a char array
        scanf("%s", inventory[i].units);
        
        // Clear the buffer again before the next loop's fgets
        while (getchar() != '\n');
    }
    
    printf("\n=============================================\n");
    printf("              INVENTORY LIST                 \n");
    printf("=============================================\n");
    
    for (int i = 0; i < n; i++) {
        printf("Name     : %s\n", inventory[i].name);
        printf("Quantity : %d\n", inventory[i].quantity);
        printf("Rating   : %.2f %s\n", inventory[i].rating, inventory[i].units);
        printf("---------------------------------------------\n");
    }
    
    return 0;
}