#!/usr/bin/python3
for num in range(97, 123):
    if num == 101 and num == 113:
        continue
    else:
        print("{}".format(chr(num)), end="")
