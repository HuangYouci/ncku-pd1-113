#include <stdio.h>

void print_month_calendar(int days_in_month,int start_day) {

	    for (int i = 0; i < start_day - 1; i++) {
		            printf("   ");
			        }

	        for (int day = 1; day <= days_in_month; day++) {
			        printf("%2d",day);
				        if ( ( day + start_day - 1 ) % 7 == 0) {
						            printf("\n");
							            }
							else {
											printf(" ");
													}
							    }

		    printf("\n");
}

int main() {
	    int days_in_month,start_day;
	        scanf("%d %d",&days_in_month,&start_day); 
			print_month_calendar(days_in_month,start_day);
			    return 0;
}
