#!/usr/bin/python3

if __name__ == "__main__":
    import variable_load_5
    
    word = dir(variable_load_5)
    
    for name in word:
        if name != 'a':
            continue
        else:
            print(name)
