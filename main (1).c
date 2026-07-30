def create_matrix(key):
    key = key.upper().replace("J", "I")
    matrix = []
    used = set()

    for ch in key + "ABCDEFGHIKLMNOPQRSTUVWXYZ":
        if ch.isalpha() and ch not in used:
            used.add(ch)
            matrix.append(ch)

    return [matrix[i:i+5] for i in range(0, 25, 5)]


def find(matrix, ch):
    if ch == 'J':
        ch = 'I'
    for i in range(5):
        for j in range(5):
            if matrix[i][j] == ch:
                return i, j


def prepare(text):
    text = ''.join(c.upper() for c in text if c.isalpha()).replace('J', 'I')
    result = ""
    i = 0

    while i < len(text):
        a = text[i]
        if i + 1 < len(text):
            b = text[i + 1]
            if a == b:
                result += a + 'X'
                i += 1
            else:
                result += a + b
                i += 2
        else:
            result += a + 'X'
            i += 1

    return result


def encrypt(matrix, text):
    cipher = ""

    for i in range(0, len(text), 2):
        a, b = text[i], text[i + 1]
        r1, c1 = find(matrix, a)
        r2, c2 = find(matrix, b)

        if r1 == r2:
            cipher += matrix[r1][(c1 + 1) % 5]
            cipher += matrix[r2][(c2 + 1) % 5]
        elif c1 == c2:
            cipher += matrix[(r1 + 1) % 5][c1]
            cipher += matrix[(r2 + 1) % 5][c2]
        else:
            cipher += matrix[r1][c2]
            cipher += matrix[r2][c1]

    return cipher


key = input("Enter Keyword: ")
plaintext = input("Enter Plaintext: ")

matrix = create_matrix(key)
prepared = prepare(plaintext)

print("\nPlayfair Matrix:")
for row in matrix:
    print(*row)

print("\nPrepared Text:", prepared)
print("Cipher Text:", encrypt(matrix, prepared))