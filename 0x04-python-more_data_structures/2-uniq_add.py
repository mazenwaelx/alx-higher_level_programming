#!/usr/bin/python3


def uniq_add(my_list=[]):
    new_list = []
    sum = 0
    for element in my_list:
        if element not in new_list:
            sum += element
            new_list.append(element)
    return sum
