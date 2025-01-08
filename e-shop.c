#include "e-shop.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>





//Εναρξη καταλογου 
void init_catalog(products catalog[])
{
    int i;
    float value;

    for (i = 0; i < PRODUCTS_NUMBER; i++) {
        snprintf(catalog[i].description, sizeof(catalog[i].description), "Product-%d\n", i+1);
        value = rand() % 500 + 1;
        catalog[i].price = value;  
        catalog[i].item_count = INITIAL_STOCK;
        catalog[i].item_requests = 0;
        catalog[i].item_sold = 0;
        for (int j = 0; j < 5; j++) 
        {
            snprintf(catalog[i].failed_customers[j], 50, "N/A");
        }
    }
}


//Συναρτηση για την επιτυχη παραγγελια 
void successful_order(int purchase, int product, products catalog[], int fd_response[2]) 
{
    float total = 0.0f;
    char response[350];
    catalog[product].item_count--;
    catalog[product].item_sold++;
    catalog[product].item_requests++;
    total += catalog[product].price;

    snprintf(response, sizeof(response), "Purchase %d complete, your total: %.2f. %s successfully bought\n", purchase + 1, total, catalog[product].description);
    write(fd_response[1], response, strlen(response) + 1);
    }


//Συναρτηση για την αποτυχημενη παραγγελια
void unsuccessful_order(int customer, int product, products catalog[], int fd_response[2]) 
{
    char response[350];
    catalog[product].item_requests++;

    snprintf(response, sizeof(response), "Products unavailable, request failed.\n");
    snprintf(catalog[product].failed_customers[customer], 50, "Customer_%d", customer + 1 );       
    write(fd_response[1], response, strlen(response) + 1);
}

   
//Συναρτηση που αποθηκευει το τυχαιο αριθμο παρραγγελια μεσω της διοχετευσης fd_order
void customer_order(int fd_order[2]) 
{
     int product = rand() % PRODUCTS_NUMBER;
    write(fd_order[1], &product, sizeof(product));
}


//Συναρτηση που αποθηκευει το το αποτελεσμα (επιτυχης/αποτυχεις παραγγελια) στην διοχετευση fd_response 
 void customer_order_result(int customer, int fd_response[2]) {
    char response[350];
    read(fd_response[0], response, sizeof(response));
    printf("Customer_%d: %s\n", customer + 1, response);
 }


//Συναρτηση για την εμφανηση αναλυτικων στοιχειων για καθε προιον
void info(products catalog[], int total_orders, float total_revenue, int successful_orders) 
{
    int i;
    int failed_requests;
    int total_successful_orders = 0, total_failed_requests = 0;

    printf("========== Products information =========\n\n");
    for (i = 0; i < PRODUCTS_NUMBER; i++) {
        failed_requests = catalog[i].item_requests - catalog[i].item_sold;
        total_successful_orders += catalog[i].item_sold;
        total_failed_requests += failed_requests;

        printf("%s", catalog[i].description);
        printf("Products requested: %d\n", catalog[i].item_requests);
        printf("Products sold: %d\n", catalog[i].item_sold);
        printf("Failed orders: %d\n", failed_requests);
        printf("The customers that didn't get this product, but requested it, were:\n");

        for (int j = 0; j < CUSTOMERS; j++) {
            printf("%s\n", catalog[i].failed_customers[j]);
        }
        printf("\n");
    }
    printf("========== E-shop statistics =========\n");
    printf("%d orders were made, where %d succeeded and %d failed\n", total_orders, total_successful_orders, total_failed_requests);
    printf("The total revenue the e-shop had was: %.2f euro\n", total_revenue);
}

int main(void) {
    srand(time(NULL));
     products catalog[PRODUCTS_NUMBER];
    init_catalog(catalog);
     int product;

    int total_orders = 0;
     int successful_orders = 0;
     float total_revenue = 0.0f;

     int fd_response[2];
    int fd_order[2];

     pipe(fd_order);//διοχετευση της fd_order
     pipe(fd_response);//διοχετευση της fd_response
    
    //Εναρξη βροχου πελατη
      for (int i = 0; i < CUSTOMERS; i++) 
      {
         if (fork() == 0)//Δημιουργεια διεργασιας
         {
             close(fd_order[0]);//Κλεινει το αρχησιμοποιητο της fd_order
             close(fd_response[0]);//Κλεινει το αρχησιμοποιητο
             
             srand(time(NULL) ^ (getpid() << 16)); // Επανεκινηση τον τυχαιων αριθμων για την παραγγελια 
             //Εναρξη βροχου για της 10 παραγγελιες καθε πελατη
             for (int j = 0; j < 10; j++)
                {
                 customer_order(fd_order);
                }
             close(fd_order[1]);//Κλεινουν τα ακρα των παιδιων
             close(fd_response[1]);//Κλεινουν τα ακρα των παιδιων
             exit(0);
         }
    }

    //Ο γονεας κλεινει ολα τα ακρα των παιδιων αφοτου ολες οι διεργασιες τελειωσαν
     close(fd_order[1]);
    close(fd_response[1]);
    //Για καθε πελατη εμφανιζονται τα στοιχεια της καθε παραγγελιας του 
    for (int i = 0; i < CUSTOMERS; i++)
     {
         printf("============== Customer-%d =============\n", i+1);
         printf("\n");
         for (int j = 0; j < 10; j++) 
         {
        read(fd_order[0], &product, sizeof(product));
            if (catalog[product].item_count > 0)
            {
                successful_order(j, product, catalog, fd_response);
                successful_orders++;
                total_revenue += catalog[product].price;
            } else
            {
                 unsuccessful_order(i + 1, product, catalog, fd_response);
            }
             customer_order_result(i, fd_response);
             total_orders++;
             usleep(500000); //Διαλλειμα 0.5 δευτερολεπτων για καθε παραγγελια
        }
         sleep(1);//Διαλλειμα 1 δευτερολεπτο μεταξυ πελατων 
    }

    //Τερματισμος των θυγατρικων εργασιων 
    for (int i = 0; i < CUSTOMERS; i++) 
    {
         wait(NULL);
    }
    //Εκτυπωση στατιστικων στοιχειων 
    info(catalog, total_orders, total_revenue, successful_orders);
     return 0;
}
