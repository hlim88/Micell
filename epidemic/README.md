## Simple epidemic modeling via SIR(D) model

In this example, we describe the one of the simplest way of modeling 
infectious disease using SIR(D) model. 

First, we condiser SIR model, where the SID stands for
- **S**usceptible
- **I**nfectious
- **R**ecovered

Let's **N** be the total number of people. Then, the sum of people over all three **S**, **I**, and **R** should be equal to **N**.
In general, **S**, **I**, **R**, and **N** can all be functions of time and space. However, we assume that they are the only function of time
for simplicity. Furthermore, we also assume that there are no births or deaths so **N** is a constant. 
Note that an important assumption of this model is that people who recover from the disease are immune and cannot carry it or be re-infected.

So far, we assumed that the disease is not fatal i.e. no death. However, how about the fatal disease? To answer this question, we 
add an additional category **D** which is deceased. Now, our model turns into SIRD model.

Based on these assumptions, we have set of ordinary differential equations (ODE) for both SIR and SIRD models and we integrate numerically.
(Detailed explanations of equations can be found in the litereatures.)

Initial conditions and parameters are described in python script. 

## Excute the code
You need python version 3 to execute the code
```
python epidemic_modeling.py
```

## References
[Original Kermack and McKendrick work](https://royalsocietypublishing.org/doi/10.1098/rspa.1927.0118)

[Triplebyte tutorial](https://triplebyte.com/blog/modeling-infectious-diseases)

[Sasaki's work on SIR](https://www.lewuathe.com/covid-19-dynamics-with-sir-model.html)
