import random
import math
from sys import exit

# 快速幂
def quick_pow(base, p, k):
    ans = 1
    p = int(p)
    while p != 0:
        if(p & 1):
            ans = (ans*base) % k
        base = (base*base) % k
        p >>= 1
    return ans


# 针对随机取得p，q两个数的素性检测
def Miller_Rabin(n):
    p = n - 1
    r = 0
    while p % 2 == 0:
        r += 1
        p /= 2
    b = random.randint(2, n - 2)
    if quick_pow(b, int(p), n) == 1:
        return True
    for i in range(0, 8):
        if quick_pow(b, (2 ** i) * p, n) == n - 1:
            return True
    return False


# 生成大素数：
def get_prime(keylength):
    while True:
        n = random.randint(0, keylength)
        if n % 2 != 0:
            found = True
            # 如果经过8次素性检测，就认为是素数
            for i in range(0, 8):
                if Miller_Rabin(n):
                    pass
                else:
                    found = False
                    break
            if found:
                return n


# 生成公钥和私钥
def gen_keys(len):
    p = get_prime(len / 2)
    q = get_prime(len / 2)
    n = p * q
    fn = (p - 1)*(q - 1)
    e = get_e(fn)
    d = get_d(e, fn)
    return (n, e, d)


# 随机在（1，fn）选择一个E，  满足gcd（e,fn）=1
def get_e(fn):
    while True:
        e = random.randint(0, fn)
        if math.gcd(e, fn) == 1:
            return e


# 根据选择的e，匹配出唯一的d
def get_d(e, fn):
    return mod_inverse(e, fn)

# ax=1(mod b) 求a模b的乘法逆x


def mod_inverse(a, b):
    arr = [0, 1, ]
    gcd = exgcd(a, b, arr)
    if gcd == 1:
        return(arr[0] % b+b) % b

# 扩展欧几里得算法求逆


def exgcd(a, b, arr):
    if b == 0:
        arr[0] = 1
        arr[1] = 0
        return a
    g = exgcd(b, a % b, arr)
    t = arr[0]
    arr[0] = arr[1]
    arr[1] = t - int(a / b) * arr[1]
    return g


def encrypt_word(m, e, n):
    return quick_pow(m, e, n)


def decrypt_word(c, d, n):
    return quick_pow(c, d, n)


def display():
    print("1.加密")
    print("2.解密")
    print("3.推出")
    print("请输入选项：")


def encrypt_word():
    file = open('homework/web_security/rsa/original.txt', "r")
    origin = file.read()
    file.close()
    n, e, d = gen_keys(1024)
    print("私钥为：（n, d): ", n, d)
    encrypted = ''
    print("明文为:",origin)
    for ch in origin:
        c = chr(encrypt_word(ord(ch), e, n))
        encrypted += c
   # print(s)
    file = open("homework/web_security/rsa/secure.txt", "w", encoding='utf-8')
    file.write(str(encrypted))
    print("密文为",encrypted)


def decrypt_word():
    file = open('homework/web_security/rsa/secure.txt', 'rb')
    secure = file.read().decode('utf-8')
    file.close()
    n, d = map(int, input("输入私钥（n,d）:").split())
    resolved = ''
    for ch in secure:
        c = chr(decrypt_word(ord(ch), d, n))
        resolved += c
    file = open("homework/web_security/rsa/ans.txt", "w", encoding='utf-8')
    file.write(str(resolved))
    print("明文为：",resolved)


if __name__ == '__main__':
    display()
    while True:
        c = input(">>>")
        if c == '1':
            encrypt_word()
        if c == '2':
            decrypt_word()
        if c == '3':
            exit(0)
        display()
