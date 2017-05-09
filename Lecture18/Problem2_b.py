from nacl import *
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

name="Na4Cl4"       # for output files
nNa = 4
nCl = 4
n = nNa + nCl
a = 0.12    # change accordingly

# Na4Cl4_a:
r_Na = [  [ 0, 0, 0 ], [ 2*a, -a/2, 0], [a, a, 0], [3*a/2, a, 0] ]
r_Cl = [  [ a, 0, a/2], [ a, 0, -a/2], [2*a, a/2, 0], [3*a/2, a/6, 0] ]

"""
# Na4Cl4_a:
r_Na = [  [ 0, 0, 0 ], [ 2*a, -a/2, 0], [a, a, 0], [3*a/2, a, 0] ]
r_Cl = [  [ a, 0, a/2], [ a, 0, -a/2], [2*a, a/2, 0], [3*a/2, a/6, 0] ]
"""

"""
# Na4Cl4_b:
r_Na = [  [ 0, 0, 0 ], [ a, a, 0], [a, 0, a], [0, a, a] ]
r_Cl = [  [ 0, 0, a ], [ a, 0, 0 ], [a, a, a], [0, a, 0] ]
"""

"""
# Na4Cl4_c:
r_Na = [  [ 0, 0, 0 ], [ a/2, a/2, 0], [a/2, 0, a/2], [0, a/2, a/2] ]
r_Cl = [  [ 0, 0, a/2], [ a/2, 0, 0 ], [a/2, a/2, a/2], [0, a/2, 0] ]
"""

"""
# Na4Cl4_d:
r_Na = [  [ 0, 0, 0 ], [ 2*a, -a/2, 0], [2*a, a/2, 0], [4*a, 0, 0] ]
r_Cl = [  [ a/2, -a, 0], [ a/2, a, 0 ], [3*a/2, 0, a/4], [3*a/2, 0, -a/4] ]
"""

"""
# Na4Cl4_e:
r_Na = [  [ 0, 0, 0 ], [ 2*a, -a/2, 0], [a, a, 0], [3*a/2, a, 0] ]
r_Cl = [  [ a, 0, a/2], [ a, 0, -a/2], [2*a, a/2, 0], [3*a/2, a/6, 0] ]
"""

"""
# Na4Cl4_f:
r_Na = [  [ 0, 0, 0 ], [ 2*a, -a/2, 0], [a, a, 0], [3*a/2, a, 0] ]
r_Cl = [  [ a, 0, a/2], [ a, 0, -a/2], [2*a, a/2, 0], [3*a/2, a/6, 0] ]
"""

"""
# Na4Cl4_g:
r_Na = [  [ 0, 0, 0 ], [ 2*a, -a/2, 0], [a, a, 0], [3*a/2, a, 0] ]
r_Cl = [  [ a, 0, a/2], [ a, 0, -a/2], [2*a, a/2, 0], [3*a/2, a/6, 0] ]
"""

# Initialize the cluster, add guesses at the
# minimum arrangement. 
cluster = Cluster()

for i in xrange(nNa) :
    r = Vector(r_Na[i])
    cluster.add(Na(r))

for i in xrange(nCl) :
    r = Vector(r_Cl[i])
    cluster.add(Cl(r))

print " " + name + " cluster"
print " Initial potential energy = " + str( cluster.potential_energy() )

# Minimize the function
accuracy = 1e-6

res = cluster.minimize( accuracy )

pe = res[1]
iterations = res[4]

# Print out resulting files, and also
# plot the values in matplotlib
print " Minimized potential energy = " + str(pe) + " eV"
print " Binding energy of cluster  = " + str( pe / 4.0 ) + " eV"
print " Number of function calls = " + str( iterations )

file_name = name + ".data"
outfile = open( file_name, 'w' )
for i in xrange( nNa + nCl - 1) :
    for j in range(i+1,nNa+nCl) :
        rij = cluster.ion(i).r - cluster.ion(j).r
        dr = sqrt( np.dot(rij,rij) )
        s =  "(" + cluster.ion(i).name + ")-(" + cluster.ion(j).name + ")"
        print " " + s + " r_" + str(i) + str(j) + " = " + str( dr ) + " nm"

outfile.write( str(cluster) )
outfile.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

[x,y,z] = cluster.convert()
ax.scatter( x,y,z )
plt.show()
