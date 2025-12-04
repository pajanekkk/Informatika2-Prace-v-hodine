
def sifruj(text, posuv):    
    encoded = ""
    for char in text:
        if not char.isalpha():
            encoded += " "
            continue
        x = ord(char)
        encoded += chr(x + posuv)

    print(encoded)

vstup = input("Zadej frazi pro encode: ")
posun = int(input("Zadej posunuti: "))

sifruj(vstup, posun)