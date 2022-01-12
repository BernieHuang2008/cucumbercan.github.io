import time
import RPi.GPIO as GPIO


def wait(sec=1.0):
    time.sleep(sec)
    return True


def SetX(lst, Size=9):
    l = []
    for _ in range(Size):
        l.append(0)

    for i in range(len(lst)):
        if lst[i] == '1':
            l[i % Size] = 1
    return l


def bin_(Command="XY72", lst=None, fps=1.0):
    if lst is None:
        lst = [[
            ['0', '0', '0', '1', '1', '1', '1', '0', '0'], ['0', '0', '1', '0', '0', '0', '0', '0', '0'],
            ['0', '1', '0', '0', '0', '0', '0', '0', '0'], ['0', '1', '0', '0', '0', '0', '0', '0', '0'],
            ['0', '1', '0', '0', '0', '0', '0', '0', '0'], ['0', '1', '0', '0', '1', '1', '1', '1', '0'],
            ['0', '0', '1', '0', '0', '0', '0', '1', '0'], ['0', '0', '0', '1', '1', '1', '1', '0', '0']]]

    if Command == "XY72":
        X = 9
    elif Command == "XY70":
        X = 10

    GPIO.setmode(GPIO.BOARD)
    Pin_list = [7, 11, 12, 13, 15, 16, 18, 22, 29, 31, 32, 33, 35, 36, 37, 38, 40]
    GPIO.setup(Pin_list, GPIO.OUT, initial=GPIO.LOW)

    for lst2 in lst:
        tic = time.time()
        while 1:
            toc = time.time()
            if toc - tic >= fps:
                break

            for index in range(len(lst2)):
                lst3 = lst2[index]

                lx = SetX(lst3, X)

                Pin_x = Pin_list[:X]
                Pin_y = Pin_list[X:][index]

                for i in range(len(lx)):
                    if lx[i] == '0':
                        Pin_x.pop(i)

                GPIO.output(Pin_x, 1)
                GPIO.output(Pin_y, 1)


# #####################################<<< STRPrint >>>###################################################### #


def search(x):
    x.low()

    dist = {'a': ['0000', '0000', '0000', '0111', '1001', '1011', '1101'],
            'b': ['1000', '1000', '1000', '1110', '1001', '1001', '0110'],
            'c': ['0000', '0000', '0000', '0111', '1000', '1000', '0111'],
            'd': ['0001', '0001', '0001', '0111', '1001', '1101', '1011'],
            'e': ['0000', '0000', '0110', '1001', '1110', '1000', '0111'],
            'f': ['0011', '0100', '0100', '1111', '0100', '0100', '0100'],
            'g': ['0111', '1001', '1001', '0111', '0001', '0001', '1110'],
            'h': ['000', '100', '100', '100', '111', '101', '101'],
            'i': ['010', '000', '110', '010', '010', '010', '111'],
            'j': ['001', '000', '011', '001', '001', '001', '110'],
            'k': ['1000', '1000', '1001', '1010', '1100', '1010', '1001'],
            'l': ['1100', '0100', '0100', '0100', '0100', '0100', '0011'],
            'm': ['00000', '00000', '00000', '11010', '10101', '10101', '10101'],
            'n': ['0000', '0000', '0000', '1110', '1001', '1001', '1001'],
            'o': ['0000', '0000', '0000', '0110', '1001', '1001', '0110'],
            'p': ['1110', '1001', '1001', '1110', '1000', '1000', '1000'],
            'q': ['0111', '1001', '1001', '0111', '0001', '0001', '0001'],
            'r': ['0000', '0000', '1011', '1101', '1000', '1000', '1000'],
            's': ['0000', '0000', '0111', '1000', '0111', '0001', '1110'],
            't': ['0000', '0000', '0100', '1111', '0100', '0100', '0011'],
            'u': ['0000', '0000', '0000', '1001', '1001', '1001', '0110'],
            'v': ['000', '000', '000', '101', '101', '101', '010'],
            'w': ['00000', '00000', '00000', '10101', '10101', '10101', '01010'],
            'x': ['00000', '00000', '10001', '01010', '00100', '01010', '10001'],
            'y': ['1001', '1001', '0111', '0001', '0001', '0001', '1110'],
            'z': ['00000', '00000', '11111', '00010', '00100', '01000', '11111'],
            '0': ['0000', '0110', '1001', '1001', '1001', '1001', '0110'],
            '1': ['000', '010', '110', '010', '010', '010', '111'],
            '2': ['00000', '00000', '11110', '00001', '01110', '10000', '11111'],
            '3': ['0000', '0000', '1110', '0001', '0110', '0001', '1110'],
            '4': ['00000', '00000', '00110', '01010', '10010', '11111', '00010'],
            '5': ['0000', '0000', '1110', '1000', '1110', '0001', '1110'],
            '6': ['0000', '0000', '0110', '1000', '1110', '1001', '0110'],
            '7': ['0000', '0000', '1111', '0010', '0111', '0001', '0110'],
            '8': ['0000', '0000', '0110', '1001', '0110', '1001', '0110'],
            '9': ['0000', '0000', '0110', '1001', '0111', '0001', '0110'],
            '.': ['00', '00', '00', '00', '00', '00', '10'],
            ' ': ['00', '00', '00', '00', '00', '00', '00']}

    return dist.get(x, ['1111', '1111', '1111', '1111', '1111', '1111', '1111'])


def str_(string, Command="XY70"):
    bin_l = []
    com_list = ['00000', '00000', '00000', '00000', '00000', '00000', '00000']
    Plus = 0
    if Command == "XY72":
        com_list.append('00000')
        Plus = 1
        X = 9
    elif Command == "XY70":
        X = 10

    for x in string:
        for i in range(len(com_list)):
            com_list[i + Plus] += '0'
            com_list[i + Plus] += search(x)[i]

    if Plus == 1:
        com_list[0] = '0' * len(com_list[1])

    l1 = []
    l2 = []
    for i in range(len(com_list[1])):
        for j in range(len(com_list)):
            l2.append(list(com_list[j][i:X + i]))
        l1.append(l2)
        l2.clear()
        l2 = []

    bin_(Command, l1, 0.5)
