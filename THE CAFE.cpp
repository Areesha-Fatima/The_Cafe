#include<stdio.h>
#include<string.h>
// These are Function declarations
void start();
void selct();
void menucard();
void contact();
void aboutUs();
void billing();
void end();

// Using Structure to store user information
struct info
{
	char name[50];
	int age;
	char ch;
} s[1];

main(){
int i;

// Loop to get user information (though loop runs once as array size is 1)
for(i=0;i<1;i++)
	printf("Please Enter Your Name: ");
	scanf("%[^\n]%*c",&s[i].name);
	printf("Enter Your Age: ");
	scanf("%d",&s[i].age);
	printf("Enter Gender(M/F): ");
	scanf("%s",&s[i].ch);
	
	// Displaying welcome message based on gender
	if(s[i].ch=='m' ||s[i].ch=='M'){
		printf("\n\n\t<======== WELCOME TO THE  CAFE Mr. %s ========>\n\n\t",s[i].name);
	}
	else{
		printf("\n\n\t<======== WELCOME TO THE CAFE Miss. %s ========>\n\n\t",s[i].name);
	}
	// Starting the main menu
	start();
	
	return 0;
}
// Function to display the main menu and handle user choices
void start(){
	int num;
	printf("\n1.Display Menu\n2.Contact\n3.About us\n4.Exit");
	printf("\nSelect your preferred choice:");
	scanf("%d",&num);
	switch(num){
		case 1:
			menucard();
			break;
			case 2:
				contact();
				break;
				case 3:
					aboutUs();
					break;
					case 4:
						end();
						break;
						default:
							printf("\nINVALID.Please Enter Correct Option\n");
							start();
	}
}
// Function to display the menu and handle order placement or going back to the main menu
void selct(){
	int s;
	printf("\nEnter 1 To Place Order:\nEnter 0 To Go Back:");
	scanf("%d",&s);
	switch (s){
		case 0:
			start();
			break;
			case 1:
				billing();
				break;
				default:
					printf("\nINVALID.Enter correct option\n");
					selct();
					
	}
}
// Function to display the menu card
void menucard(){
	printf("\n\n\t*****MENU*****\n\n\t");
	printf("\nS#         Items         price");
	printf("\n1.   Club Sandwich    Rs.350/-");
	printf("\n2.   Plain Fries      Rs.100/-");
	printf("\n3.   Lava Fries       Rs.200/-");
	printf("\n4.   Donuts(pack of 6) Rs.400/-");
	printf("\n5.   Cake Slice       Rs.90/-");
	printf("\n6.   Pizza Slice      Rs.90/-");
	printf("\n7.   Coffee           Rs.120/-");
	printf("\n8.   Cold Coffee      Rs.120/-");
	printf("\n9.   Kashmeri Chai    Rs.130/-");
	printf("\n10.  Chai\Tea         Rs.110/-");
	
	selct();
}
// Function to display contact information
void contact(){
	printf("\n\n\t******FOR DELIVERY******\n\n\t");
	printf("\nContact Us: 030-067-061");
	printf("\nVisit Our Website:");
	printf("\nwww.A_Cafe.com");
	printf("\n\n");
	
	start();
}
// Function to display information about the cafe
void aboutUs(){
	printf("\n\n\t*****ALI CAFE*****\n\n\t");
	printf("\nEstablished in 2016, Review 3 stars ");
	printf("\n\tTIMINGS:");
	printf("\nMon to Fri:    3:00PM-11:00PM");
	printf("\nSat to Sun:    3:00PM-1:00AM");
	printf("\nBranches in Karachi and Islamabad.");
	printf("\n\n");
	
	start();
}
// Function to display a thank you message
void end(void)
{
	printf("\n\t***THANK YOU!***\n\t");
	printf("\n\t**SEE YOU AGAIN**\n\t");
}
// Function to handle the billing process
void billing(){
    char ch;
    int Snum;
    int qty;
    int total = 0;
    int n, i;
    char paymentMethod[10];

    printf("\nPlease Enter how many items you want to order:");
    scanf("%d", &n);
    
    do {
    	// Loop to get item serial number and quantity
        for (i = 0; i < n; i++) {
            printf("\nEnter the serial number of the item:");
            scanf("%d", &Snum);
            printf("\nEnter the quantity of the selected item:");
            scanf("%d", &qty);
            // Calculate total based on item serial number
            if (Snum == 1) {
                total = total + 350 * qty;
            } else if (Snum == 2) {
                total = total + 100 * qty;
            } else if (Snum == 3) {
                total = total + 200 * qty;
            } else if (Snum == 4) {
                total = total + 400 * qty;
            } else if (Snum == 5) {
                total = total + 90 * qty;
            } else if (Snum == 6) {
                total = total + 90 * qty;
            } else if (Snum == 7) {
                total = total + 120 * qty;
            } else if (Snum == 8) {
                total = total + 120 * qty;
            } else if (Snum == 9) {
                total = total + 130 * qty;
            } else if (Snum == 10) {
                total = total + 110 * qty;
            } else {
                printf("\nINVALID. Please Enter Correct Option");
            }
        }
        // Ask if the user wants to continue ordering
        printf("\nDo you want to continue your order? ");
        printf("YES or no [Y/N]:");
        scanf("%s", &ch);
    } while (ch == 'y' || ch == 'Y');
    
    // Get the payment method and apply discount if applicable
    printf("\nEnter payment method (cash/card): ");
    scanf("%s", paymentMethod);
    
    int discount = 0;
    if (strcmp(paymentMethod, "cash") == 0) {
        discount = total * 0.1;
    }
    int discounted_total = total - discount;
    
    //displaying the bill ( with discount and without discount )
    printf("\n\t###############################\n\t");
    printf("\n\tYOUR TOTAL BILL BEFORE DISCOUNT: %d\n\t", total);
    if (discount > 0) {
        printf("\n\tYOUR TOTAL BILL AFTER 10%% DISCOUNT: %d\n\t", discounted_total);
    }
    printf("\n\t###############################\n\t");
    
    printf("\n\t\t*THANK YOU FOR YOUR ORDER!*");
    printf("\n\t\t\t*SEE YOU AGAIN!*");
}
