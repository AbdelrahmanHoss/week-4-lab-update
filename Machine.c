#include <stdio.h>
#include <math.h>

/* defining ingredient quantities and prices for each coffee type*/

#define espresso_beans 8
#define espresso_water 30
#define espresso_milk 0
#define espresso_choco_syrup 0
#define espresso_price 3.5

#define cappuccino_beans 8
#define cappuccino_water 30
#define cappuccino_milk 70
#define cappuccino_choco_syrup 0
#define cappuccino_price 4.5

#define mocha_beans 8
#define mocha_water 39
#define mocha_milk 160
#define mocha_choco_syrup 10
#define mocha_price 5.5

#define low_threshold_beans 8
#define low_threshold_water 30
#define low_threshold_milk 30
#define low_threshold_choco_syrup 10

#define password 1234

int beans = 100 , water = 500 , milk = 500 , chocolate = 100;
double total_amount = 0.0;

void display_menu(){
    printf("1. order coffee\n");
    printf("2. admin mode\n");
    printf("3. exit\n");
}

void check_ingredients() {
    if (beans <= low_threshold_beans) {
        printf("Alert: Low on coffee beans!\n");
    }
    if (water <= low_threshold_water) {
        printf("Alert: Low on water!\n");
    }
    if (milk <= low_threshold_milk) {
        printf("Alert: Low on milk!\n");
    }
    if (chocolate <= low_threshold_choco_syrup) {
        printf("Alert: Low on chocolate syrup!\n");
    }
}

void process_payment(double price) {
    double paid = 0.0, coin;
    printf("insert coins (1 AED or 0.5 AED):\n");
    while (paid < price) {
        scanf("%lf", &coin);
        if (coin == 1 || coin == 0.5) {
            paid += coin;
            printf("inserted: %.2f, total: %.2f\n", coin, paid);
        } else {
            printf("invalid coin\n");
        }
    }
}

void order_coffee()
{
    int coffee_type;
    printf("select coffee type\n");
    printf("1. espresso %.2f\n", espresso_price);
    printf("2. cappuccino %.2f\n", cappuccino_price);
    printf("3. mocha %.2f\n", mocha_price);
    printf("enter your choice: ");
    scanf("%d", &coffee_type);

switch (coffee_type){

    case 1:
      if (beans >= espresso_beans && water >= espresso_water){
        printf(" confirm order of espresso for %.2f yes or no?", espresso_price);
        char confirm;
        scanf("%c", &confirm);
        if (confirm == 'yes'){
            process_payment(espresso_price);
             beans -= espresso_beans;
            water -= espresso_water;
            total_amount += espresso_price;
            printf("enjoy!");
            check_ingredients();
        }
}
    else { printf(" no enough ingredients for esspresso");}
    break;

    case 2:
        if (beans >= cappuccino_beans && water >= cappuccino_water && milk >= cappuccino_milk){
             printf(" confirm order of cappuccino for %.2f yes or no?", cappuccino_price);
        char confirm;
        scanf("%c", &confirm);
        if (confirm == 'yes'){
            process_payment(cappuccino_price);
            beans -= cappuccino_beans;
            water -= cappuccino_water;
            milk -= cappuccino_milk;
            total_amount += cappuccino_price;
            printf("enjoy!");
            check_ingredients();
        

        }
        }
     else { printf(" no enough ingredients for cappuccino");}
    break;

    case 3:
        if (beans >= mocha_beans && water >= mocha_water && milk >= mocha_milk && chocolate >= mocha_choco_syrup){
            printf(" confirm order of mocha for %.2f yes or no?", mocha_price);
        char confirm;
        scanf("%c", &confirm);
        if (confirm == 'yes'){
            process_payment(mocha_price);
            beans -= mocha_beans;
            water -= mocha_water;
            milk -= mocha_milk;
            chocolate -= mocha_choco_syrup;
            total_amount += mocha_price;
            printf("enjoy!");
            check_ingredients();
        
        } 
        }
     else { printf(" no enough ingredients for mocha");}
    break; 
}
   

}

void replenish_ingredients() {
    beans = 100;
    water = 500;
    milk = 500;
    chocolate = 100;
    printf("ingredients replenished\n");
}

void change_prices() {
    printf("current prices\n");
    printf("1. espresso: %.2f\n", espresso_price);
    printf("2. cappuccino: %.2f\n", cappuccino_price);
    printf("3. mocha: %.2f\n");
 ....
}



void admin_mode(){
    int entered_password;
    printf("enter admin password: ");
    scanf("%d", &entered_password);
    if (entered_password != password) {
        printf("incorrect password\n");
        return;
    }
    change_price();
}
    



 int main()
 {
    int choice;
    while (1) {
    display_menu();
    printf ("enter your choice: ");
    scanf ("%d", &choice);
    switch (choice)
     {
        case 1:
        order_coffee();
        break;

        case 2:
        admin_mode();
        break;
        
        case 3:
        printf("total sales amount: %.2f\n", total_amount);
        break;

        case 0:
        printf("exiting the program\n");
        return 0;

    }
    }
    return 0;
 }







