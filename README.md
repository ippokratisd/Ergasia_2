# Ergasia_2
Στον φακελο Makefile δημιουργειτε το e-shop.ο για compilation ποu αποτελειτε απο το e-shop.c και e-shop.h
Στον φακελο e-shop.c που εκει δομειτε το προγραμa c ξεκινοντας με ολλες τις απαραιτητες σηναρτησης η οποιες ειναι 
η init_catalog(products catalog[]) που ειναι η εναρξη του καταλογου,το void successful_order(int purchase, int product, products catalog[], int fd_response[2]) για της επιτιχης παραγγελειες,
η unsuccessful_order(int customer, int product, products catalog[], int fd_response[2]) για της αποτυχημενες παραγγελειες, 
η unsuccessful_order(int customer, int product, products catalog[], int fd_response[2]) για την αποθηκευση των τυχεων αριθμων για της παραγγελειες μεσο της διοχετευσης fd_order
η customer_order(int customer, int fd_response[2]) για την αποθηκευση της επιτυχημες/αποτυχημενης παραγγελιας στην διοχετευση fd_order
η customer_order_result(int customer, int fd_response[2]) για την εμφανιση της παρραγγελιας μεσω της διοχετευση fd_response
η info(products catalog[], int total_orders, float total_revenue, int successful_orders) εμφανιζει τα στατιστικα του καταστηματος
Στο main body ξεκιναμε τις διοχετευσης fd_response, fd_order και κλεινουμε στα καταληλα σημεια τα αχρησιμοποιητα μελη. Επειτα δημιουργουμε 5 θυγατρτικες διεργασιες που αντιστοιχουν σε καθε πελατη και κανουμε αντιστοιχα μεβαση της οδηγιες την καθε παρραγελια. Τελος επεξεργαζεται το αποτελεσμα της παραγγελιας και κλεινει ολες τις θυγατρικες εργασιες
