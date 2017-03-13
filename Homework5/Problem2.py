from sys import argv
from avg import Calculate


def main():

    script, records = argv

    target = open(records, 'r')

    o1 = Calculate(target)

    o1.cal_avg(target)



if __name__ == "__main__" : 
    main()

