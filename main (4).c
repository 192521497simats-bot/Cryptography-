from math import gcd

cipher = input("Enter Ciphertext: ").upper()

for a in range(1, 26):
    if gcd(a, 26) == 1:
        inv = next(i for i in range(26) if (a * i) % 26 == 1)

        for b in range(26):
            plain = ""
            for ch in cipher:
                if ch.isalpha():
                    x = ord(ch) - 65
                    p = (inv * (x - b)) % 26
                    plain += chr(p + 65)
                else:
                    plain += ch

            print(f"a={a}, b={b} -> {plain}")