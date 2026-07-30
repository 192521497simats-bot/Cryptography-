matrix = [
['M','F','H','I','K'],
['U','N','O','P','Q'],
['Z','V','W','X','Y'],
['E','L','A','R','G'],
['D','S','T','B','C']
]

def pos(ch):
    if ch == 'J':
        ch = 'I'
    for i in range(5):
        for j in range(5):
            if matrix[i][j] == ch:
                return i, j

text = "Must see you over Cadogan West Coming at once"

text = ''.join(c.upper() for c in text if c.isalpha()).replace('J','I')

prepared = ""
i = 0

while i < len(text):
    a = text[i]
    if i+1 < len(text):
        b = text[i+1]
        if a == b:
            prepared += a+'X'
            i += 1
        else:
            prepared += a+b
            i += 2
    else:
        prepared += a+'X'
        i += 1

cipher = ""

for i in range(0,len(prepared),2):

    a,b = prepared[i],prepared[i+1]

    r1,c1 = pos(a)
    r2,c2 = pos(b)

    if r1==r2:
        cipher += matrix[r1][(c1+1)%5]
        cipher += matrix[r2][(c2+1)%5]

    elif c1==c2:
        cipher += matrix[(r1+1)%5][c1]
        cipher += matrix[(r2+1)%5][c2]

    else:
        cipher += matrix[r1][c2]
        cipher += matrix[r2][c1]

print("Prepared:",prepared)
print("Cipher:",cipher)