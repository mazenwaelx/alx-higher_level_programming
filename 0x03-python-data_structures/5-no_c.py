#!/usr/bin/env python3
def no_c(my_string):
    for i in range(len(my_string)):
        if 'c' or 'C':
            my_string.pop()
