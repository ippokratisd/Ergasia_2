//Δηλωση σταθερων για ευκολια αλλαγης μεταβλητων
#define CUSTOMERS 5
#define PRODUCTS_NUMBER 100
#define INITIAL_STOCK 2 

//Δημιουργεια δομης για τα προιοντα
typedef struct {
	int item_count;
	float price;
	char description[100];
	int item_requests;
	int item_sold;
	char failed_customers[CUSTOMERS][50];
}products;

//Δηλωση συναρτησεων 
void init_catalog(products catalog[]);

void successful_order(int purchase, int product, products catalog[], int fd_response[2]);

void unsuccessful_order(int customer, int product, products catalog[], int fd_response[2]);

void info(products catalog[], int total_orders, float total_revenue, int succesful_orders);

void customer_order(int fd_order[2]);

void customer_order_result(int customer, int fd_response[2]);
