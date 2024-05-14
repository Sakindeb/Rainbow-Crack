//SIT703-2018
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calc_success_probability(unsigned long N, unsigned long t, unsigned long m)
{
  unsigned long i, L=m;
  float P = 1.0-(float)m/(float)N;
  unsigned long arr[t];
  arr[1] = m;

  for (i=2; i<=t-1; i++)
  {
    (unsigned long)arr[i] = N * (1.0 - pow(1.0-1.0/(float)N, arr[i-1]) );
    L = L + arr[i] ;
  }
  P = 1.0 - pow(1.0-1.0/(float)N, L);

  return P;
}

int main(int argc, char* argv[])
{
  if(argc != 4)
  {
    printf("Usage: calc_success_probability N t m\n");
    exit(0);
    }
  printf ("The probability of using (N=%d, t=%d, m=%d) is %f\n",
    atoi(argv[1]), atoi(argv[2]), atoi(argv[3]),
    calc_success_probability(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])));

  return 0;
}
