def spocitej_znaky(text):
    text = text.lower()

    slovnik = {}

    for znak in text:

        if znak == ' ':
            continue

        if znak in slovnik:
            slovnik[znak] += 1
        else:
            slovnik[znak] = 1
    return slovnik

vstup = input("Zadej vstup: ")

vysledek = spocitej_znaky(vstup)
print(f"{vstup}")
print(f"Cetnost: {vysledek}")