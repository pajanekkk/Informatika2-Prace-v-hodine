studenti = []

def pridej_studenta(jmeno, znamky):
    student = {
        "jmeno": jmeno,
        "znamky": znamky
    }
    studenti.append(student)
    print(f"Student {jmeno} byl pridan do seznamu se znamkami: {znamky}")


def nejlepsi_student(seznam=studenti):
    nejlepsi = seznam[0]
    for s in seznam[1:]:
        if sum(s["znamky"]) / len(s["znamky"]) < sum(nejlepsi["znamky"]) / len(nejlepsi["znamky"]):
            nejlepsi = s
    print(f"Nejlepší: {nejlepsi['jmeno']}")


pridej_studenta("Petr", [1, 2, 3, 4])
pridej_studenta("Pavel", [2, 2, 2, 2])
pridej_studenta("Adéla", [1, 1, 1, 1])

nejlepsi_student()
