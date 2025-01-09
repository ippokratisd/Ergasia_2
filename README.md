# Ergasia_2
Στο προτο κοματι τις αργαρσια εχοθμε το Makefile που στο οπιο διμιοργοθμε το e-shop.ο για compilation ποu αποτελιτε απο το e-shop.c και e-shop.h
μετα παμε στο e-shop.c που εκει φτιαχνοθμε το προγραμa c ξεκινοσντασ με ολλες τις απαρετιτες σηναρτισις η οπιες ειναι 
το void init_catalog(products catalog[]) που ειναι η εναρξη του καταλογου,το void successful_order(int purchase, int product, products catalog[], int fd_response[2]) για της επιτιχες παραγγελιες,
το void unsuccessful_order(int customer, int product, products catalog[], int fd_response[2]) για της αποτιχιμενες παραγγελιες, 
το void unsuccessful_order(int customer, int product, products catalog[], int fd_response[2]) για την αποθηκευσι τον τηχεον αριθμον για της παραγγελιες μεσο της διοχετευσης fd_order
το void customer_order_result(int customer, int fd_response[2]) για την αποθηκευση της αποτηχιμενισ ι αποτιχιμενισ παραγγελιας στην διοχετευση fd_response,
το void info(products catalog[], int total_orders, float total_revenue, int successful_orders) για να ενφανιζι καθε στιχιο απο τα προιοντα αναλιτικα
στο τελος μπενουμε στο main body το οπιο περνη το fd_order και fd_response τα βαζη σε pipe οστε να επικινονιση με τους τιχεους αριθμους για να τους περασι 10 παραγγελιες για καθε πελατη στην σινεχια εφανιζη τα στιχια της παραγγελιας για καθε εναν πελατι και στο τελος εκτιπονι τα στατιστικα στιχια
και στο τελος εχουμε το προγραμα e-shop.h που διλονουμε σταθερες για ευκολη αλλαγη των μεταωλιτων,διμιοργοθμε τις δομες για τα προιοντα και διλονοθμε της σιναρτισις
