#Gabriel Brehm
#CS360
#Lab02

'''
A camera class. This, along with the creation and alteration of my camera are rather 
integral to the code. This is part of the fulfillment of requirments 4.
'''
class Camera:
    def __init__(self, locationVec, lookVec):
        self.locationVec = locationVec			#instance data member
        self.lookVec = lookVec					#instance data member number 2
		
    def changeLocation(self, x, y, z):			#Instance method
        self.locationVec = "<" + str(x) + ", " + str(y) + ", " + str(z) + ">"
		
    def changeLookat(self, x, y, z):			#instance method number 2
        self.lookVec = "<" + str(x) + ", " + str(y) + ", " + str(z) + ">"

'''
	I tried to make this a class method, but I would consistently get a typeerror about 
	concatinating a 'method' with a string. Sorry for failing. 
'''
def cameraToString(cameraOb):					
    return r"camera{location" + cameraOb.locationVec + "look_at" + cameraOb.lookVec + "}"