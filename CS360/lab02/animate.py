#Gabriel Brehm
#CS360
#Lab02

import os
import re
import math

def fileToString(fileName):
    fin = open(fileName)
    stringName = fin.read() # Read the entire file into a string
    fin.close()
    return stringName

	
def createMovie():
    print( 'Encoding movie' )
    os.system('mencoder.exe mf://temp*.png -mf type=png:fps=25 -ovc lavc -lavcopts \
    vcodec=msmpeg4:vbitrate=2160000:keyint=5:vhq -o movie.avi ' )

def cameraHelix(radius, strPattern):
    for i in range(1000):
        x = (radius * math.sin(math.radians(1.05 * (i + 1))))
        y = (i / 50) + 1  
        z = (radius * math.cos(math.radians(1.05 * (i + 1))))
        outfile = 'temp.pov'
        temp_sdl = re.sub(strPattern, "camera{location<" + str(x) + "," + str(y) + "," + str(z) + ">", sdl_new)
    
        fout = open( outfile, 'w' )	
        fout.write( temp_sdl )
        fout.close()    
	
        pov_cmd = ' pvengine.exe +I%s +O%s -D -V +A +H600 +W800 /exit'
        cmd = pov_cmd % ('temp.pov', "temp" + str(i+1).zfill(4) + ".png")
        os.system(cmd)
    createMovie()

sdl = fileToString('base.pov')
sdl_new = sdl

pattern = r"camera\s*{\s*location\s*<(\-*\d+),(\-*\d+),(\-*\d+)>"

cameraHelix(15, pattern) 





