list_cisel = []

while True:
    vstup = input("Zadej cislo: ")
    list_cisel.append(vstup)
    if vstup == 'stop':
        break

def vypis_statistiku(seznam):
    cisla = []
    for x in seznam:
        try:
            cislo = int(x)
            cisla.append(cislo)
        except(ValueError, TypeError):
            continue

    total = sum(cisla)
    max_hodn = max(cisla)
    min_hodn = min(cisla)
    prumer = total / len(cisla)
    sudy = 0
    lichy = 0
    for x in cisla:
        if int(x).is_integer():
            if int(x) % 2 == 0:
                sudy += 1
            else:
                lichy += 1
    print(f"Suma je: {total}")
    print(f"Max hodnota je: {max_hodn}")
    print(f"Min hodnota je: {min_hodn}")
    print(f"Prumer seznamu je: {prumer}")
    print(f"Lichy: {lichy} a Sudy: {sudy}")
vypis_statistiku(list_cisel)