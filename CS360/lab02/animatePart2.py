#Gabriel Brehm
#CS360
#Lab02

'''
Sorry about all of the comments, Becka. I fear, in my attempt to ease your taversal of my code,
I have only hindered you. Good luck, we're all counting on you.

P.S. The comments become funnier as you go. Don't forget to read the ones in sphere.py!
'''

import os
import re
import math
import camera   #look at
import sphere   #these
import methods  #modules - This is the fulfillment for requirement 3.

sdl = methods.fileToString('base.pov')
sdl_new = sdl
outfile = 'temp2.pov'

'''
Here we have the utilization of a tuple, so we can use an indexed number to assign a color to
an object. This is part of the fulfillment of requirment 6.
'''
colors = ("Red","Orange","Yellow","Green","Blue")

'''
This is a dictionary that assigns a number to a finish. It is basically a way to do the same
thing as the tuple above, but in a slightly different way. This is part of the fulfillment 
of requirment 6
'''       
finishes = {1: "F_Glass4", 2: "Glass3", 3: "Glass"}

'''
Here we use the camera class to create a new camera object. This is part of the fulfillment
of requirment 4.
'''
newCam = camera.Camera("<0.6466,0.5,8.4987>", "<0,3.5,0>")

'''
This is using our reular expessions to replace the oiginal camera with the new camera we
just created. This is part of the fulfillment of requirement 2.
'''
sdl_new = re.sub(methods.cameraPattern, camera.cameraToString(newCam), sdl_new)

'''
Here we are making a list for use in the creation of a sphere object. This is part of the
fulfillment of part 6.
'''
list1 = [0.0811,-0.4,2.9989]     #declaring a list to use for the sphere

'''
Here we are using our second class to create a sphere object. This is part of the fulfillment
of requirement 4.
'''
sphere1 = sphere.Sphere(list1, 0.3, colors[4], finishes[1])
sdl_new += sphere.sphereToString(sphere1)

frameCount = 0      #declaring variables for use in the following two loop
index = 0
colorIndex = 0
while sphere1.center <= [0.0811,3.328995,2.9989]:
    '''
    We are making use of a keyword argument that is simultaneously a list: can I hear a
    "part of the fulfillment of parts 6 AND 7?"
    '''
    sphere1.changeCenter(list = [0.0811, (index / 50) - 0.4, 2.9989])
    
    if frameCount % 10 == 0:    #fun color changing spheres we have going on
        colorIndex += 1         
        sphere1.changeColor(colors[colorIndex % 5])
        
    '''
    What have we here? More use of regular expressions to change what is in the .pov file?
    Sounds like part of the fulfillment of requirement 2.
    '''
    sdl_new = re.sub(methods.newSpherePattern, sphere.sphereToString(sphere1), sdl_new, 1)
  
    fout = open( outfile, 'w' )	
    fout.write( sdl_new )
    fout.close()  
    pov_cmd = ' pvengine.exe +I%s +O%s -D -V +A +H600 +W800 /exit'
    cmd = pov_cmd % ('temp2.pov', "temp2" + str(frameCount+1).zfill(4) + ".png")
    os.system(cmd)
    index += 1
    frameCount += 1

'''
I would put more comments down in the following for loop, but I have already labeled the requireed 
features in the lab. Basically, it is a loop that move the sphere from the position it was in around 
the orb, while the camera moves in a helix shape at a slower rate in the same diretion. the sphere is 
also changing colors.
'''
    
radius = 3 
radius2 = 8
for i in range(700): #that's a lotta frames!
    sphere1.changeCenter(list = [(radius * math.sin(math.radians(1.55 * (i + 1)))), 3.348995, (radius * math.cos(math.radians(1.55 * (i + 1))))])
    
    if frameCount % 10 == 0: #more color fun
        colorIndex += 1
        sphere1.changeColor(colors[colorIndex % 5])
        
    sdl_new = re.sub(methods.newSpherePattern, sphere.sphereToString(sphere1), sdl_new)
    newCam.changeLocation((radius2 * math.sin(math.radians(1.05 * (i + 1)))) + 0.5, (i / 60) + 0.5, (radius2 * math.cos(math.radians(1.05 * (i + 1)))) + 0.5)
    sdl_new = re.sub(methods.cameraPattern, camera.cameraToString(newCam), sdl_new)
    fout = open( outfile, 'w' )	
    fout.write( sdl_new )
    fout.close()  

    pov_cmd = ' pvengine.exe +I%s +O%s -D -V +A +H600 +W800 /exit'
    cmd = pov_cmd % ('temp2.pov', "temp2" + str(frameCount+1).zfill(4) + ".png")
    os.system(cmd)	
    frameCount += 1

methods.createMovie() #utilization of the createMovie function imported from methods.py.






