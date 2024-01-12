#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to represent items in the order
struct items {
    char item[20];
    float price;
    int qty;
};

// Structure to represent orders
struct orders {
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};

// Function to generate the bill header
void generateBillHeader(char name[50], char date[50]) {
    printf("\n\n");
    printf("\t    ADV. Restaurant");
    printf("\n\t   -----------------");
    printf("\nDate:%s", date);
    printf("\nInvoice To: %s", name);
    printf("\n");
    printf("---------------------------------------\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n---------------------------------------");
    printf("\n\n");
}

// Function to generate the bill body (item details)
void generateBillBody(char item[30], int qty, float price) {
    printf("%s\t\t", item);
    printf("%d\t\t", qty);
    printf("%.2f\t\t", qty * price);
    printf("\n");
}

// Function to generate the bill footer (total)
void generateBillFooter(float total) {
    printf("\n");
    float dis = 0.1 * total;
    float netTotal = total - dis;
    float cgst = 0.09 * netTotal;
    float grandTotal = netTotal + 2 * cgst; // netTotal + cgst + sgst
    printf("---------------------------------------\n");
    printf("Sub Total\t\t\t%.2f", total);
    printf("\nDiscount @10%s\t\t\t%.2f", "%", dis);
    printf("\n\t\t\t\t-------");
    printf("\nNet Total\t\t\t%.2f", netTotal);
    printf("\nCGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\nSGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\n---------------------------------------");
    printf("\nGrand Total\t\t\t%.2f", grandTotal);
    printf("\n---------------------------------------\n");
}

int main() {
    system("clear");
    start:
    char username[10], user[10];
    int password = 1234, pass;
    strcpy(username, "Mohan");
    printf("Enter the username:");
    scanf("%s", &user);
    printf("Enter the password");
    scanf("%d", &pass);
    if (strcmp(user, username) == 0 && pass == password)
        printf("Welcome,%s", user);
    else {
        printf("Enter correct credentials!!\n");
        goto start;
    }
    system("clear");
    int opt, n;
    struct orders ord;
    struct orders order;
    char saveBill = 'y', contFlag = 'y';
    char name[50];
    FILE *fp;
    // Dashboard
    while (contFlag == 'y') {
        system("clear");
        float total = 0;
        int invoiceFound = 0;
        printf("\t============ADV. RESTAURANT============");
        printf("\n\nPlease select your preferred operation");
        printf("\n\n1.Generate Invoice");
        printf("\n2.Show all Invoices");
        printf("\n3.Search Invoice");
        printf("\n4.Delete Invoice");
        printf("\n5.Exit");

        printf("\n\nYour choice:\t");
        scanf("%d", &opt);
        fgetc(stdin);
switch (opt) {
    case 1:
        // Case for generating a new invoice
        system("clear");
        printf("\nPlease enter the name of the customer:\t");
        fgets(ord.customer, 50, stdin);
        ord.customer[strlen(ord.customer) - 1] = 0;
        strcpy(ord.date, __DATE__);
        // Displaying menu and taking order details
        printf("\nidly      Rs.40");
        // ... (Displaying other menu items and prices)
        printf("\nPlease enter the number of items:\t");
        scanf("%d", &n);
        ord.numOfItems = n;
        for (int i = 0; i < n; i++) {
            // Taking details for each item in the order
            printf("Enter the item number %d\n", i + 1);
            scanf("%s", ord.itm[i].item);
            printf("Please enter the quantity:\t");
            scanf("%d", &ord.itm[i].qty);
            // Calculating total based on item prices and quantities
            if (strcmp(ord.itm[i].item, "vada") == 0) {
                ord.itm[i].price = 10;
                total += ord.itm[i].qty * ord.itm[i].price;
            } 
            // ... (Similar calculations for other menu items)
        }
        // Generating and displaying the bill
        generateBillHeader(ord.customer, ord.date);
        for (int i = 0; i < ord.numOfItems; i++) {
            generateBillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
        }
        generateBillFooter(total);
        // Asking if the user wants to save the invoice
        printf("\nDo you want to save the invoice [y/n]:\t");
        scanf("%s", &saveBill);

        if (saveBill == 'y') {
            // Saving the order details to a file
            fp = fopen("RestaurantBill.dat", "a+");
            fwrite(&ord, sizeof(struct orders), 1, fp);
            if (fwrite != 0)
                printf("\nSuccessfully saved");
            else
                printf("\nError saving");
            fclose(fp);
        }
        break;

    case 2:
        // Case for showing all previous invoices
        system("clear");
        fp = fopen("RestaurantBill.dat", "r");
        printf("\n  *Your Previous Invoices*\n");
        while (fread(&order, sizeof(struct orders), 1, fp)) {
            float tot = 0;
            generateBillHeader(order.customer, order.date);
            for (int i = 0; i < order.numOfItems; i++) {
                generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
                tot += order.itm[i].qty * order.itm[i].price;
            }
            generateBillFooter(tot);
        }
        fclose(fp);
        break;

    case 3:
        // Case for searching for a specific invoice by customer name
        printf("Enter the name of the customer:\t");
        fgets(name, 50, stdin);
        name[strlen(name) - 1] = 0;
        system("clear");
        fp = fopen("RestaurantBill.dat", "r");
        printf("\t*Invoice of %s*", name);
        while (fread(&order, sizeof(struct orders), 1, fp)) {
            float tot = 0;
            if (!strcmp(order.customer, name)) {
                generateBillHeader(order.customer, order.date);
                for (int i = 0; i < order.numOfItems; i++) {
                    generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
                    tot += order.itm[i].qty * order.itm[i].price;
                }
                generateBillFooter(tot);
                invoiceFound = 1;
            }
        }
        if (!invoiceFound) {
            printf("Sorry the invoice for %s does not exist", name);
        }
        fclose(fp);
        break;

    case 4:
        // Case for deleting a specific invoice by customer name
        char name_[50];
        printf("Enter the name of the customer to delete their invoice:");
        scanf("%s", &name_);
        FILE *fp = fopen("RestaurantBill.dat", "r+");
        FILE *ft = fopen("temp.dat", "a+");
        while (fread(&order, sizeof(struct orders), 1, fp)) {
            if (strcmp(order.customer, name_) != 0) {
                fwrite(&order, sizeof(struct orders), 1, ft);
            }
        }
        remove("RestaurantBill.dat");
        rename("temp.dat", "RestaurantBill.dat");
        fclose(fp);
        fclose(ft);
        printf("\nInvoice deleted successfully");
        break;

    case 5:
        // Case for exiting the program
        printf("\n\t\t Bye Bye :)\n\n");
        exit(0);
        break;

    default:
        // Default case for handling invalid options
        printf("Sorry invalid option");
        break;
}
        printf("\nDo you want to perform another operation?[y/n]:\t");
        scanf("%s", &contFlag);
    }
    printf("\n\t\t Bye Bye :)\n\n");
    printf("\n\n");

    return 0;
}

