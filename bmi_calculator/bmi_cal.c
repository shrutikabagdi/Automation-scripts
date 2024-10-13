#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

float bmi_cal(float weight, float height);
void center();
void bmi_main();
void rhr_main();
void bp_main();

int main() {
    system("cls");
    system("color 3F");
    
    int choice;
    
    while (1) {  // Loop for menu navigation
        system("cls");
        printf("What do you want to do?\n1. BMI(Body Mass Index) | 2. RHR(Resting Heart Rate) | 3. BP(Blood Pressure) | 0. Exit\n");
        scanf("%d", &choice);
        
        system("cls");
        
        switch (choice) {
            case 1:
                bmi_main();
                break;
            case 2:
                rhr_main();
                break;
            case 3:
                bp_main();
                break;
            case 0:
                printf("Thank You!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                getch();
        }
    }
    return 0;
}

void center() {
    int i;
    for (i = 0; i < 13; i++) {
        printf("\n");
    }
    for (i = 0; i < 40; i++) {
        printf(" ");
    }
}

void bmi_main() {
    float weight, height, bmi;
    center();
    
    printf("Enter your height (in cm): ");
    scanf("%f", &height);
    
    system("cls");
    center();
    
    printf("Enter your weight (in kg): ");
    scanf("%f", &weight);
    
    system("cls");
    center();
    
    bmi = bmi_cal(weight, height);
    printf("Your BMI is %.2f\n", bmi);
    center();
    
    if (bmi < 18.5) {
        printf("Weight Status: Underweight");
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        printf("Weight Status: Healthy Weight");
    } else if (bmi >= 25 && bmi <= 29.9) {
        printf("Weight Status: Overweight");
    } else {
        printf("Weight Status: Obesity");
    }
    
    getch();  // Wait for user input before returning to main menu
}

float bmi_cal(float weight, float height) {
    return weight / (height * height) * 10000;
}

void rhr_main() {
    int beat_15, beat_total;
    center();
    
    printf("Feel your pulse and count the number of beats in 15 seconds: ");
    scanf("%d", &beat_15);
    
    system("cls");
    center();
    
    beat_total = beat_15 * 4;
    printf("Your RHR (Resting Heart Rate) is %d bpm\n", beat_total);
    center();
    
    if (beat_total >= 60 && beat_total <= 100) {
        printf("You have a normal resting heart rate.");
    } else if (beat_total < 60) {
        printf("You have a lower than normal heart rate.");
    } else {
        printf("You have a higher than normal heart rate.");
    }
    
    getch();
}

void bp_main() {
    int sp, dp;
    center();
    
    printf("Use a sphygmomanometer to get the readings\n");
    center();
    
    printf("Enter Systolic pressure (Top number): ");
    scanf("%d", &sp);
    
    center();
    printf("Enter Diastolic pressure (Bottom number): ");
    scanf("%d", &dp);
    
    system("cls");
    center();
    
    printf("Your Blood Pressure is %d/%d mmHg\n", sp, dp);
    center();
    
    if ((sp - dp) > 40) {
        printf("Cannot provide accurate results or You may have Hypertension");
    } else if (sp <= 90 && dp <= 60) {
        printf("You have low blood pressure");
    } else if (sp <= 120 && dp <= 80) {
        printf("You have normal blood pressure");
    } else if (sp <= 140 || dp <= 90) {
        printf("You have Pre Hypertension");
    } else if (sp <= 160 || dp <= 100) {
        printf("You have Stage 1 Hypertension");
    } else if (sp <= 180 || dp <= 120) {
        printf("You have Stage 2 Hypertension");
    } else if (sp > 180 || dp > 120) {
        printf("You have Hypertensive Crisis");
    } else {
        printf("Wrong inputs or cannot give accurate results");
    }
    
    getch();
}
