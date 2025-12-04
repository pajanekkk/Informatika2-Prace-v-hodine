from os.path import join, realpath, dirname

cesta = join(dirname(realpath(__file__)), "test.txt")

suma = 0    


with open(cesta, "r", encoding="utf-8") as f:
    for radek in f:
        radek = radek.strip()
        cisla = []
        for i in range(12,0,-1):
            cisla.append(max(radek[:-i]))
            index_nejvetsiho = radek.find(cisla[-1])
            radek = radek[index_nejvetsiho+1:]
        suma += int(''.join(cisla))
        print(int(''.join(cisla)))

print(suma)