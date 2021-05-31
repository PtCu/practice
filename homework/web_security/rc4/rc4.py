
def ksa(key):
    S = [x for x in range(256)]
    j = 0
    key = [ord(x) for x in key]
    for i in range(256):
        j = (j+S[i]+int(key[i % len(key)])) % 256
        S[i], S[j] = S[j], S[i]
    return S


def encrypt(S, origin):
    i, j = 0, 0
    secure = []
    for char in origin:
        i = (i+1) % 256
        j = (j+S[i]) % 256
        S[i], S[j] = S[j], S[i]
        output = format(ord(chr(S[(S[i]+S[j]) % 256] ^ ord(char))), 'x')
        secure.append(output)

    return secure

def decrypt(S,ciphertext):
    i=j=0
    plaintext=''
    for char in ciphertext:

        i=(i+1)%256
        j=(j+S[i]) %256
        S[i],S[j]=S[j],S[i]

        c=chr(int(char,16) ^ S[(S[i] + S[j]) % 256])
        plaintext+=c
    return plaintext


def prompt():
    print("1.加密")
    print("2.解密")
    print("请输入选项：")


def encrypt_word():
    file = open('homework/web_security/rc4/original.txt', "r")
    origin = file.read()
    file.close()
    key = input("\n输入密钥 ")
    S = ksa(key)
    encrypted = encrypt(S, origin)
    encrypted_str = ""
    for x in encrypted:
        encrypted_str += x+" "
    file = open("homework/web_security/rc4/secure.txt", "w", encoding='utf-8')
    file.write(str(encrypted_str))
    print("密文为", encrypted_str)


def decrypt_word():
    encrypted = input("输入密文:\n").split(" ")
    key = input("\n输入密钥 ")
    key=ksa(key)
    resolved = decrypt(key, encrypted)
    file = open("homework/web_security/rsa/ans.txt", "w", encoding='utf-8')
    file.write(str(resolved))
    print("明文为：", resolved)


def main():
    prompt()
    while True:
        c = input(">>>")
        if c == '1':
            encrypt_word()
        if c == '2':
            decrypt_word()
        if c == '3':
            exit(0)
        prompt()


if __name__ == '__main__':
    main()
