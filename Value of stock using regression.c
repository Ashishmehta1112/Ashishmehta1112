#include <math.h>
#include <stdio.h>
#include <string.h>
/* will use array in future that's why this function will take place and new functions will be made to make it more powerful also polynomial regressional
 algorithms will also be used here to get more accuracy although stocks cannot be exactly predicted but more the data will be given these programs can help us to judge the behaviour of stock*/
/*int add(int size, int array[]) {
  int i = 0;
  int sum = 0;
  for (i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum;
}*/
int main() {
char name[10];
  printf("Enter your name :");
  
 scanf("%s",name);
  fflush(stdin);
  printf("Hi %s :", name);
  
  char stockname[20];
  printf("\nEnter stock name :");
scanf("%s",stockname);
  fflush(stdin);

  printf("Your stock name is  :%s \n", stockname);

  
  printf("Okay so please tell us data for the approximate value of the stock enter day -0 as the day from which you will enter the starting data and with respect to other days so that the calculation would get easier and in a clean format for instance we will take  6   day values ie;from day 0 to day 5  \n");
  
  float day0, day1, day2, day3, day4, day5;
printf("Enter value of stock on day0:");
  
  scanf("%f",&day0);
  fflush(stdin);

  printf( "Enter value of stock on day1:");

  scanf("%f", &day1);
  fflush(stdin);
  printf("Enter value of stock on day2 :");

  scanf("%f", &day2);
  fflush(stdin);
  printf("Enter value of stock on day3 :");

  scanf("%f", &day3);
  fflush(stdin);
  printf("Enter value of stock on day4 :");

  scanf("%f", &day4);
  fflush(stdin);
  printf("Enter value of stock on day5 :");

  scanf("%f", &day5);
fflush(stdin);
  float sum = day0 + day1 + day2 + day3 + day4 + day5;
  float ym = (float)((sum) / 6);

  float sumsqdy = (day0 - ym) * (day0 - ym) + (day1 - ym) * (day1 - ym) +(day2 - ym) * (day2 - ym) + (day3 - ym) * (day3 - ym) +(day4 - ym) * (day4 - ym) + (day5 - ym) * (day5 - ym);
  float sumdy = (day0 - ym) + (day1 - ym) + (day2 - ym) + (day3 - ym) +(day4 - ym) + (day5 - ym);

  float x0 = 1.00, x1 = 2.00, x2 = 3.00, x3 = 4.00, x4 = 5.00, x5 = 6.00;

  float xmean = (x0 + x1 + x2 + x3 + x4 + x5) / 6.00;
  float sumdx = (x0 - xmean) + (x1 - xmean) + (x2 - xmean) + (x3 - xmean) +(x4 - xmean) + (x5 - xmean);
  float sumdxsq = (x0 - xmean) * (x0 - xmean) + (x1 - xmean) * (x1 - xmean)+(x2 - xmean) * (x2 - xmean) + (x3 - xmean) * (x3-xmean)+ (x4 - xmean) * (x4 - xmean) + (x5 - xmean) * (x5 - xmean);

  float regressioncnst;
  float correlationcnst;
  float varx, vary;

  float stdx, stdy;
  float sumdxsumdy = (x0 - xmean) * day0 + (x1 - xmean)*day1+ (x2 - xmean) * day2 + (x3 - xmean) * day3 + (x4 - xmean) * day4 + (x5 - xmean) * day5;
  float dxdysum = sumdxsumdy / 6.00;
  float sumdxsumdy1 = (sumdx * sumdy) / 36.00;
  float ndxsqdxsq = (sumdxsq / 6.00) - (((sumdx / 6.00) * (sumdx / 6.00)));

  float ndysqdysq = (sumsqdy / 6.00) - (((sumdy) * (sumdy)) / 36.00);
  printf("sumsqdy is%f,sumdy is %f", sumsqdy, sumdy);
  stdx = pow(ndxsqdxsq, 0.5);
  stdy = pow(ndysqdysq, 0.5);
  correlationcnst = (dxdysum - sumdxsumdy1) / (stdx * stdy);
  regressioncnst = (correlationcnst) * ((stdy) / (stdx));
  /*printf("variencex%f\n",stdx);
  printf("variencey%f\n",stdy)
;
  printf("correlation%f\n", correlationcnst);
printf("regressioncnst%f\n",regressioncnst);*/
  float dn;
  printf(" Now tell the  day from day 0 for which u want the value of the stock tell in integer like if you want day 19th value of the stock then type 20 ie; N+1 , the price will be based upon the older 6 days data you have given already  \n");

  scanf("%f", &dn);
  fflush(stdin);
  float value = (float)(regressioncnst * dn) - (regressioncnst * ((sumdx / 6.00) + xmean)) +((sumdy / 6.00) + ym);

  printf("According to linear regressional algorithm the value of %s stock comes out to be \n \t %f",stockname, value);

  return 0;
}
