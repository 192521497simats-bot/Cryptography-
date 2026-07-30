key = "CIPHER"

cipher = ""

for ch in key:
    if ch not in cipher:
        cipher += ch

for ch in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
    if ch not in cipher:
        cipher += ch

print("Plain : ABCDEFGHIJKLMNOPQRSTUVWXYZ")
print("Cipher:", cipher)

text = input("\nEnter Plaintext: ")

result = ""

for ch in text:
    if ch.isalpha():
        if ch.isupper():
            result += cipher[ord(ch)-65]
        else:
            result += cipher[ord(ch.upper())-65].lower()
    else:
        result += ch

print("Encrypted:", result)