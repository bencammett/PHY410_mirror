import math
import matplotlib.pyplot as plt

# velocities (km/s) and distances (Mpc)

final_r = [ 1.6333, 0.8850, 0.9,
            0.9,    0.271,  1.0,
            0.033,  0.214,  1.1 ]

final_v = [ +673, +396, +500,
            -30,  -159, +920,
            +230, -130, +500 ]

plt.scatter( final_r , final_v )
plt.ylabel('Radial Velocity (km/s)')
plt.xlabel('Distance (Mpc)')
plt.title("Velocity-Distance Relation: Hubble's Law")
plt.grid(True)

n = len(final_r)

s_x = 0
s_y = 0
s_xx = 0
s_xy = 0
sigma2 = 0
for i in range (0, n ): 
   s_x += final_r[i]
   s_y += final_v[i]
   s_xx += final_r[i]**2
   s_xy += final_r[i]*final_v[i]
denom = n * s_xx - s_x**2
if abs( denom ) < 0.000001 : 
      print 'Error! Denomominator is zero!'
      exit()

 
a = (s_xx * s_y - s_x * s_xy) / denom
b = (n*s_xy - s_x * s_y) / denom   


if n > 2 : 
      sigma = math.sqrt(sum((final_v[i] - (a+b*final_r[i]))**2 for i in range(n)) / (n-2))
      sigma_a = math.sqrt(sigma**2 * s_xx / denom)
      sigma_b = math.sqrt(sigma**2 * n / denom)
else :
      sigma = 0.
      sigma_a = 0.
      sigma_b = 0.


print ' Least squares fit of', n, 'data points'
print ' -----------------------------------'
print " Hubble's constant slope   b = {0:6.2f} +- {1:6.2f}  km/s/Mpc".format( b, sigma_b)
print " Intercept with r axis     a = {0:6.2f} +- {1:6.2f}  km/s".format( a, sigma_a)
print ' Estimated v error bar sigma =', round(sigma, 1), 'km/s'


plt.show()


