
def ksa(key):
    S = [x for x in range(256)]
    j=0
    key=[ord(x) for x in key]
    for i in range(256):
        j=(j+S[i]+int(key[i % len(key)]))%256
        S[i],S[j]=S[j],S[i]
    return S

def prga(S,ciphertext):
    i=j=0
    plaintext=''
    for char in ciphertext:

        i=(i+1)%256
        j=(j+S[i]) %256
        S[i],S[j]=S[j],S[i]

        c=chr(int(char,16) ^ S[(S[i] + S[j]) % 256])
        plaintext+=c
    return plaintext



ciphertext=input("Input the ciphertext:\n")
key=input("Input the secret key: ")
cipherlist=ciphertext.split(' ')
key=ksa(key)

print(prga(key,cipherlist))