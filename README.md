# Ergasia_2
Στον φακελο Makefile δημιουργειτε το e-shop.ο για compilation ποu αποτελειτε απο το e-shop.c και e-shop.h
Στον φακελο e-shop.c που εκει δομειτε το προγραμa c ξεκινοντας με ολλες τις απαραιτητες σηναρτησης η οποιες ειναι 
η init_catalog(products catalog[]) που ειναι η εναρξη του καταλογου,το void successful_order(int purchase, int product, products catalog[], int fd_response[2]) για της επιτιχης παραγγελειες,
η unsuccessful_order(int customer, int product, products catalog[], int fd_response[2]) για της αποτυχημενες παραγγελειες, 
η unsuccessful_order(int customer, int product, products catalog[], int fd_response[2]) για την αποθηκευση των τυχεων αριθμων για της παραγγελειες μεσο της διοχετευσης fd_order
η customer_order_result(int customer, int fd_response[2]) για την αποθηκευση της επιτυχημες/αποτυχημενης παραγγελιας στην διοχετευση fd_response,
η info(products catalog[], int total_orders, float total_revenue, int successful_orders) για να ενφανιζι καθε στιχιο απο τα προιοντα αναλιτικα
στο τελος μπενουμε στο main body το οπιο περνη το fd_order και fd_response τα βαζη σε pipe οστε να επικινονιση με τους τιχεους αριθμους για να τους περασι 10 παραγγελιες για καθε πελατη στην σινεχια εφανιζη τα στιχια της παραγγελιας για καθε εναν πελατι και στο τελος εκτιπονι τα στατιστικα στιχια
και στο τελος εχουμε το προγραμα e-shop.h που διλονουμε σταθερες για ευκολη αλλαγη των μεταωλιτων,διμιοργοθμε τις δομες για τα προιοντα και διλονοθμε της σιναρτισις
