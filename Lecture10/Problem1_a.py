from trapezoid import *
from simpson import *
from math import *



n1 = 1
n2 = 0

while n1 % 2 != 0 :
    n1 = int(raw_input( "Enter number of intervals desired for trapezoidal rule (must be even)" ))

# a = 0
# b = 2 * atan(1.0)
a = 0
b = log(e)   # log by default base e: https://docs.python.org/2/library/math.html

ans1 = trapezoid(exp, a, b, n1)
print 'Trapezoidal rule = ' + str(ans1)

ans2 = adaptive_trapezoid(exp, a, b, 0.0001, True) # can add ,True to show steps, can change 0.0001
print 'Adaptive trapezoidal rule = ' + str(ans2)

ans3 = simpson(exp, a, b, n1)
print 'Simpson rule = ' + str(ans3)

print 'Result should be: e - 1 = ' + str(e - 1)   # to check result
