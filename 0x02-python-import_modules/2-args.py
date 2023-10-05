#!/usr/bin/python3

if __name__ == "__main__":
    import sys
    argv = sys.argv[1:]
    num_arguments = len(argv)

    print("{} argument{}:".format(num_arguments, 's' if num_arguments != 1 else ''))
    for i, arg in enumerate(argv):
        print("{}: {}".format(i + 1, arg))
