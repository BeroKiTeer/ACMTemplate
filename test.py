import pygame
def snz(jcs,smj):
    while True:
        print('jcs,if you love smj?Yes or No')
        str = input()
        if str == 'Yes':
            print('married')
        elif str == 'q':
            break
        else:
            print('sucide')
    return
snz('jcs','smj')