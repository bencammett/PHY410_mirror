from nacl import *
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

name="Na3Cl3"       # for output files
nNa = 3
nCl = 3
n = nNa + nCl
a = 0.2

"""
# Na3Cl3_a:
r_Cl = [  [ 0, 0, 0 ], [ 2*a, 0, 0], [a, a + a/2, 0] ]
r_Na = [  [ a, -a/2, 0 ], [ 0, a, 0 ], [2*a, a, 0] ]
"""
# Na3Cl3_b:
r_Cl = [  [ a/2, 0, 0 ], [ 2*a, 0, 0], [ 4*a, 0, 0] ]
r_Na = [ [ a + 0.1, 0, 0 ], [ 3*a + 0.1, 0, 0], [ 5*a + 0.1, 0, 0]  ]

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
print " Binding energy of cluster  = " + str( pe / 3.0 ) + " eV"
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
