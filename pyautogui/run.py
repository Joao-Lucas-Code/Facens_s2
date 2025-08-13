import pyautogui
from time import sleep
cont = 0 # Inicio da contagem
for c in range(11): # Tamanho da contagem
    pyautogui.moveTo(x=267, y=109)
    sleep(0.4)
    pyautogui.click(x=267, y=109)
    sleep(0.5)
    pyautogui.write(f"aula_{cont}.html")
    pyautogui.press("enter")

    pyautogui.moveTo(x=267, y=109)
    sleep(0.4)
    pyautogui.click(x=267, y=109)
    sleep(0.5)
    pyautogui.write(f"aula_{cont}.css")
    pyautogui.press("enter")
    cont+=1