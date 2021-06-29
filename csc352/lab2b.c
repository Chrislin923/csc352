#include <stdio.h>

int main(){
        int x;
        printf("Please enter the weight you’d like to convert: ");
        scanf("%d",&x);
        printf("\nHere is the weight on other planets:\n");
        int y  = 0.38 * x;
        printf("\nMercury\t\t%3d lbs\n", y);
        y = 0.91 * x;
        printf("Venus\t\t%3d lbs\n", y);
        y = 0.38 * x;
        printf("Mars\t\t%3d lbs\n", y);
        y = 2.54 * x;
        printf("Jupiter\t\t%3d lbs\n", y);
        y = 1.08 * x;
        printf("Saturn\t\t%3d lbs\n", y);
        y = 0.91 * x;
        printf("Uranus\t\t%3d lbs\n", y);
	y = 1.19 * x;
        printf("Neptune\t\t%3d lbs\n\n",y);
        return 0;
}
