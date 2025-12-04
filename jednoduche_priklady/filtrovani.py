def filtruj(vstup, vystup, klicove = "ERROR"):
    with open(vstup, 'r', encoding='utf-8') as soubor_vst:
        radky = soubor_vst.readlines()
    
    filtrovane = [radek for radek in radky if klicove in radek]

    with open(vystup, 'w', encoding='utf-8') as soubor_vyst:
        soubor_vyst.writelines(filtrovane)

    print(f"Nalezeno {len(filtrovane)} radku s {klicove}")

filtruj("jednoduche_priklady/system.log", "jednoduche_priklady/errors_only.txt", 'ERROR')