const int MAX_NUM = 1000;
bool is_prime[MAX_NUM+1];

void SieveEratos(){
  memset(is_prime, true, sizeof(is_prime));
  int sqrtn = int(sqrt(MAX_NUM));

  is_prime[0]= is_prime[1] = false;
  for(int i=2; i<=sqrtn ; ++i)
    if(is_prime[i])
      for(int j= i*i; j<=MAX_NUM ; j+=i)
        is_prime[j] = false;
}
