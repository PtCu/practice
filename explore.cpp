int a[10001];
const int n = 500;

int main()
{
    char s[] = "abc";
    char *const p = s;
    const char *q = s;

    p++;
    q++;
    p[0] = 'd';
    q[0] = 'd';
}