#include<stdio.h>
#include<stdlib.h>

struct _retire_info
{
    int months;
    double contribution;
    double rate_of_return;
    
};

typedef struct _retire_info retire_info;

void print_monthly_info(int months, double balance) {
  printf("Age %3d month %2d you have $%.2lf\n", months / 12, months % 12, balance);

  return;
}

double accountbalance(double balance, retire_info restire_state)
{
    return (balance* restire_state.rate_of_return +restire_state.contribution + balance);
}

void retirement( int startAge, // in months
                double initial, // initial savings in dollars
                retire_info working,
                retire_info retired) // //info about being retired
{
double current_Balance = initial;
 int total_months = startAge - 1;
 for (int i = 0; i < working.months; i++) {
    total_months += 1;
     print_monthly_info(total_months, current_Balance);
     current_Balance= accountbalance(current_Balance , working);

 }

   for (int j = 0; j < retired.months; j++) {
    total_months += 1;
    print_monthly_info(total_months, current_Balance);
    current_Balance = accountbalance(current_Balance, retired);
  }



}



int main() {
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045 / 12.0;
  
  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01 / 12.0;

  retirement(327, 21345, working, retired);

  return 0;
}
