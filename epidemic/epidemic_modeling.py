# Import python modules we need
#%matplotlib inline
import numpy as np
import scipy as sp
import matplotlib as  mpl
from matplotlib import pyplot as plt
mpl.rc('font',size=16)


# Returns beta and gamma based on recovery time 
# and infectious power R.
"""
Here we choose recovery_time as 14 days which is
official time to self-quarantine for COVID19.
Infectious power of the disease is between 2 and 5.
R = 5 means nothing is done, and it can be as low as
2 if people are careful. In this example, we use R=5
"""
def define_beta_gamma(R=5,recovery_time=14):
    gamma = 1./recovery_time
    beta = R*gamma
    return beta,gamma

beta,gamma = define_beta_gamma()
print("beta = {}\ngamma = {}".format(beta,gamma))

# Define initial condition
i0 = 1e-8 
r0 = 0 
s0 = 1 - i0

# Solve SIR differential equations using scipy
num_times = 180 # simulate for half a year
times = np.arange(num_times)
Us = np.empty((num_times,3))
Us[0] = np.array([s0,i0,r0])

def rhs(t, U, beta, gamma):
    s,i,r = U[0],U[1],U[2]
    return np.array([-beta*s*i,beta*s*i-gamma*i,gamma*i])

from scipy.integrate  import ode
integrator = ode(rhs)

# set initial conditions and parameters
beta,gamma = define_beta_gamma(R=5,recovery_time=14)
integrator.set_initial_value(Us[0],0)
integrator.set_f_params(beta,gamma)

# Integrate ODE
for i in range(len(times)-1):
    t = times[i+1]
    integrator.integrate(t)
    Us[i+1] = integrator.y

s,i,r = Us[:,0],Us[:,1],Us[:,2]
plt.plot(times,s,label='susceptible')
plt.plot(times,i,label='infected')
plt.plot(times,r,label='recovered')
plt.legend(loc='center right')
plt.xlabel('time (days)')
plt.ylabel('fraction of total population')
plt.savefig('SIR.pdf')
plt.clf()

# Plot with the y-axis on a log scale
plt.semilogy(times,s,label='susceptible')
plt.plot(times,i,label='infected')
plt.plot(times,r,label='recovered')
plt.legend(loc='lower right')
plt.xlabel('time (days)')
plt.ylabel('fraction of total population')
plt.savefig('SIR_log.pdf')
plt.clf()

# Now we condier SIRD model
# Fraction of people who have the disease who die. 
# For COVID19, it is about 3%
R1 = 3./100.
# No one die at the initial
d0 = 0

# Solve SIDR differential equation
num_times = 180 # simulate for half a year
times = np.arange(num_times)
Us = np.empty((num_times,4))
Us[0] = np.array([s0,i0,r0,d0])

def rhs(t, U, beta, gamma, sigma):
    s,i,r,d = U[0],U[1],U[2],U[3]
    return np.array([-beta*s*i,
                     beta*s*i-(gamma+sigma)*i,
                     gamma*i,
                     sigma*i
                    ])
integrator = ode(rhs)

# set initial conditions and parameters
beta,gamma = define_beta_gamma(R=3.4,recovery_time=14)
sigma = R1*gamma
integrator.set_initial_value(Us[0],0)
integrator.set_f_params(beta,gamma,sigma)

# Integrate ODE
for i in range(len(times)-1):
    t = times[i+1]
    integrator.integrate(t)
    Us[i+1] = integrator.y

s,i,r,d = Us[:,0],Us[:,1],Us[:,2],Us[:,3]

plt.plot(times,s,label='susceptible')
plt.plot(times,i,label='infected')
plt.plot(times,r,label='recovered')
plt.plot(times,d,label='dead')
plt.legend(loc='center left')
plt.xlabel('time (days)')
plt.ylabel('fraction of total population')
plt.savefig('SIRD.pdf')
plt.clf()

# Plot with the y-axis on a log scale
plt.semilogy(times,s,label='susceptible')
plt.plot(times,i,label='infected')
plt.plot(times,r,label='recovered')
plt.plot(times,d,label='dead')
plt.legend(bbox_to_anchor=[0.985,0.7])
plt.xlabel('time (days)')
plt.ylabel('fraction of total population')
plt.savefig('SIRD_log.pdf')

