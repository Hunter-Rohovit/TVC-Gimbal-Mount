import os
import math
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

file_path = "C:\\Users\\hroho\\Desktop\\Thrust Vector Control Mount\\StaticFireTest3\\StaticFire3.txt"
with open(file_path, 'r') as file:
    test_data = file.read()

lines = test_data.rsplit("\n")

#data points for each load cell 
loadPoint1 = []
loadPoint2 = []
loadPoint3 = []
#sum of the 3 load cells to find thrust from engine
totalForce = []

#set initial t-0 time
timeZeroValue = 65
#testDuration in datapoints (80 datapoints = 1 sec)
testDuration = 240
#distance from center to loadpoints in centimeters
distance = 8.78

#pulling the data from the text file and filling all 4 arrays
lineNum = 1;
for line in lines:
    if lineNum<timeZeroValue:
        lineNum+=1
        continue
    if lineNum == timeZeroValue+240:
        break
    forces = line.rsplit(" ")
    forces.pop(3)
    loadPoint1.append(float(forces[0]))
    loadPoint2.append(float(forces[1]))
    loadPoint3.append(float(forces[2]))
    totalForce.append(float(forces[0]) + float(forces[1]) + float(forces[2]))
    lineNum+=1

#Finding total impulse. Impulse = integral(Force*dt). 
#To find impulse: find average thrust, multiply by time duration
sum = 0
for force in totalForce:
    sum+=force
avgForce = sum/240
totalImpulse = avgForce*3
#Finding Max Thrust and Time Occurred
maxThrust = 0
maxTime = 0                    
t = 0
for force in totalForce:
    t+=0.0125
    if force>maxThrust:
        maxThrust = force
        maxTime = t

#Finding X-Y coordinates for Center of Force
x = []
y = []
for i in range(240):
    sum = loadPoint1[i]+loadPoint2[i]+loadPoint3[i]
    xPos = (-loadPoint1[i]*math.cos(math.pi/6)+loadPoint3[i]*math.cos(math.pi/6))/sum
    x.append(xPos)
    yPos = (-loadPoint1[i]*math.sin(math.pi/6)-loadPoint3[i]*math.sin(math.pi/6)+loadPoint2[i])/sum
    y.append(yPos)

#Find Max and Min X-Distance
maxX = 0
minX = 10
for xDis in x:
    if(xDis>maxX):
        maxX=xDis
    if(xDis<minX):
        minX=xDis
xRange = maxX-minX
#Find Max and Min Y-Distance
maxY = 0
minY = 10
for yDis in y:
    if(yDis>maxY):
        maxY=yDis
    if(yDis<minY):
        minY=yDis
yRange = maxY-minY

#create the time data = 3 second duration with interval of 0.0125 seconds
start = 125
end = 30000
interval = 125
numSamples = int((end-start)/interval)+1
time = np.linspace(start,end,numSamples, endpoint = False)
forceData = np.array(totalForce)
forceX = np.array(x)[50:]
forceY = np.array(y)[50:]
#convert the time from ms to s
i = 0
for t in time:
    time[i] = float(t)/10000
    i+=1                           
        
#Graphing
figure, axis = plt.subplots(2)
figure.set_figwidth(12)
figure.set_figheight(12)
figure.set_facecolor("#262626")

#Thrust vs. Time
axis[0].plot(time, forceData, color='#0784b5')
axis[0].set_xlim(left = 0)
axis[0].set_ylim(bottom = 0)
axis[0].set_facecolor("#262626")
axis[0].set_xlabel("Time (s)", color = "#FFFFFF")
axis[0].set_ylabel("Thrust (N)", color = "#FFFFFF")
axis[0].spines['bottom'].set_color('#FFFFFF')
axis[0].spines['top'].set_color('#262626') 
axis[0].spines['right'].set_color('#262626')
axis[0].spines['bottom'].set_color('#FFFFFF')
start, end = axis[0].get_ylim()
axis[0].yaxis.set_ticks(np.arange(start, end, 1))
axis[0].tick_params(axis='x', colors='#FFFFFF', grid_alpha = 0.5)
axis[0].tick_params(axis='y', colors='#FFFFFF', grid_alpha = 0.5)
axis[0].grid(linewidth = 0.5)
impulse = "Total Impulse: "+ str(totalImpulse)[0:6] + " N-s"
thrust = "Max Thrust: " +str(maxThrust)[0:6] + " N at t =" + str(maxTime)[0:4] + "s"
axis[0].text(1.9,15, impulse, fontsize = 10, color = '#FFFFFF')
axis[0].text(0.2,15, thrust, fontsize = 10, color = '#FFFFFF')

#ScatterPlot
sc = axis[1].scatter([],[], s=15, color = '#0784b5')
axis[1].set_xlim(left = -0.5)
axis[1].set_xlim(right = 0.5)
axis[1].set_ylim(bottom = -0.2)
axis[1].set_ylim(top = 0.2)
axis[1].set_facecolor("#262626")
axis[1].spines['left'].set_position('center')
axis[1].spines['bottom'].set_position('center')
axis[1].spines['top'].set_color('#262626') 
axis[1].spines['right'].set_color('#262626')
axis[1].spines['bottom'].set_color('#FFFFFF')
axis[1].spines['left'].set_color('#FFFFFF')
start2, end2 = axis[1].get_ylim()
axis[1].yaxis.set_ticks(np.arange(start2, end2, 0.5))
axis[1].tick_params(axis='x', colors='#FFFFFF', grid_alpha = 0.5)
axis[1].tick_params(axis='y', colors='#FFFFFF', grid_alpha = 0.5)
axis[1].grid(linewidth = 0.5)
axis[1].set_xlabel("X (cm)", color = "#FFFFFF", loc = 'left',)
axis[1].set_ylabel("Y (cm)", color = "#FFFFFF", loc = 'bottom', )
axis[1].text(0.1,-0.24, "Y-Range: "+str(yRange)[0:6] + " cm", fontsize = 10, color = '#FFFFFF')
axis[1].text(-0.3,-0.24, "X-Range: "+str(xRange)[0:6] + " cm", fontsize = 10, color = '#FFFFFF')

#animations
fill = None
vertical_line = plt.Line2D([time[0],time[0]], [0, forceData[0]], color = '#FFFFFF', linewidth = 0.7, visible = True)
axis[0].add_line(vertical_line)
marker = axis[0].scatter([time[0]], [forceData[0]], marker = 'v', color = '#FFFFFF')
def update_scatter_and_line(num, sc, vertical_line, marker):
    global fill
    sc.set_offsets(np.c_[forceX[:num], forceY[:num]])
    vertical_line.set_data([time[num], time[num]], [0, forceData[num]])
    marker.set_offsets([time[num], forceData[num]])
    if fill:
        fill.remove()
    fill = axis[0].fill_between(time[:num], forceData[:num], color='#0784b5', alpha=0.2)
    return sc, vertical_line, fill, marker
ani = animation.FuncAnimation(figure, update_scatter_and_line, frames = len(time), fargs=(sc, vertical_line, marker), interval = 10, blit=True)

#show graphs
plt.show()