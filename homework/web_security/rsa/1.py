def ksa(key):
    S = [x for x in range(256)]
    j=0
    key=[ord(x) for x in key]
    for i in range(256):
        j=(j+S[i]+int(key[i % len(key)]))%256
        S[i],S[j]=S[j],S[i]
    return S

def prga(S,plaintext):
    i,j=0,0
    ciphertext=[]
    for char in plaintext:

        i=(i+1)%256
        j=(j+S[i]) %256
        S[i],S[j]=S[j],S[i]

        hexed=format(ord(chr(S[(S[i]+S[j])%256] ^ ord(char))),'x')
        ciphertext.append(hexed)

    return ciphertext




key = input("\nInput Key: ")
S=ksa(key)
ciphertext=prga(S, input('\nInput the text you want to encrypt:\n'))
print("\nYour ciphertext is:" )
for x in ciphertext:
    print(x, end=' ')
print("\n")