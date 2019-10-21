#Gabriel Brehm
#CS360
#Lab02

import os
'''
Here we have two function that are at module scope. This is part of the fulfillment
of requirement 3.
'''
def fileToString(fileName):
    fin = open(fileName)
    stringName = fin.read() 					#Read the entire file into a string
    fin.close()
    return stringName
	
def createMovie(): 								#This is the movie making code
    print( 'Encoding movie' )
    os.system('mencoder.exe mf://temp2*.png -mf type=png:fps=25 -ovc lavc -lavcopts \
    vcodec=msmpeg4:vbitrate=2160000:keyint=5:vhq -o moviePart2.avi ' )
      
'''
Below are the two regular expressions used to find the camera, and the newly inserted sphere
(they have a special comment, so that way I did not mess with the spheres that were already
there. They are also at module scope. So, this is part of the fulfillment of requirements 2 and 3. 
'''
cameraPattern = r"camera\s*{\s*location\s*<(\-?0\.?\d+|\-?\d+\.?\d+|\-?\d+),\s*(\-?0\.?\d+|\-?\d+\.?\d+|\-?\d+),\s*(\-?0\.?\d+|\-?\d+\.?\d+|\-?\d+)>\s*look_at\s*<(\-?0\.?\d+|\-?\d+\.?\d+|\-?\d+),\s*(\-?0\.?\d+|\-?\d+\.?\d+|\-?\d+),\s*(\-?0\.?\d+|\-?\d+\.?\d+|\-?\d+)>\s*}"
newSpherePattern = r"sphere//newSphere\s*{\s*<(\-?0\.?\d+|\-?\d+\.?\d+|\-?\d+),\s*(\-?0\.?\d+|\-?\d+\.?\d+|\-?\d+),\s*(\-?0\.?\d+|\-?\d+\.?\d+|\-?\d+)>\s*(\-?0\.?\d+|\-?\d+\.?\d+|\-?\d+)\s*pigment\s*{\s*(\w+)\s*}\s*finish\s*{\s*(\w+)\s*}\s*}"
