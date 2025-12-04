import random

cislo = random.randint(1,10)
hra = True

while hra:
    num = input("\033[1mZadej cislo: \033[0m")
    try:
        if num == cislo:
            print("Uhodls to vole")
            hra = False
        else:
            print("posrals to")
    except ValueError:
        print("Zadej platne cislo!")
    except ZeroDivisionError:
        print("Chyba deleni nulou")
    except Exception as e:
        print(e)
