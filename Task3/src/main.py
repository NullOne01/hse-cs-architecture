import sys
import time

from data.container import Container


def err_message1():
    print("incorrect command line!")
    print("  Waited:")
    print("     command -f infile outfile01 outfile02")
    print("  Or:")
    print("     command -n number outfile01 outfile02")


def err_message2():
    print("incorrect qualifier value!")
    print("  Waited:")
    print("     command -f infile outfile01 outfile02")
    print("  Or:")
    print("     command -n number outfile01 outfile02")


if __name__ == '__main__':
    if len(sys.argv) != 5:
        err_message1()
        exit()

    print("Start")
    start_time = time.time()

    container = Container()

    if sys.argv[1] == "-f":
        with open(sys.argv[2], 'r') as file:
            container.fill_file(file)
    elif sys.argv[1] == "-n":
        size = int(sys.argv[2])
        if (size < 1) or (size > 10000):
            print(
                f"incorrect number of animals = {size}. Set 0 < number <= 10000")
            exit()
        container.fill_rand(size)
    else:
        err_message2()
        exit()

    with open(sys.argv[3], 'w') as file_out1:
        file_out1.write("Filled container:\n")
        container.print(file_out1)

    container.sort_shell()

    with open(sys.argv[4], 'w') as file_out2:
        file_out2.write("Sorted container:\n")
        container.print(file_out2)

    end_time = time.time()
    cpu_time_used = end_time - start_time

    print(f"Time elapsed (seconds): {cpu_time_used}")
    print("Stop")
