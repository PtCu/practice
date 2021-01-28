//https://oi-wiki.org/math/sieve/
void phi_table(int n, int *phi)
{
    for (int i = 2; i <= n; ++i)
        phi[i] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (!phi[i])    //i是质数
        {
            for (int j = i; j <= n; j += i)
            {
                if (!phi[j]) //j是质数
                    phi[j] = j;
                phi[j] = phi[i] / i * (i - 1);
            }
        }
    }
}