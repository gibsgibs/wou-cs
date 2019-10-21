#Gabriel Brehm
#CS360
#Lab02

'''
This is a class that is used to make a sphere object. It is part of the fulfillment of requirment 4.
'''
class Sphere:
    '''
    You see this constructor? It is a nice constructor. This is part of the fulfillment or requirment 5.
    '''
    def __init__(self, list, radius, color, finish):
        self.center = list       #instance data member for the center of the sphere
        self.radius = radius     #instance data member for the radius of the sphere
        self.color = color       #instance data member for the color of the sphere
        self.finish = finish     #instance data member for the finish of the sphere
        self.name = "Eugene"
    '''
    You might be wondering why self.name = "Eugene" is the last item in my list of member variables.
    Well, let me tell you. Not only is this project important for school, it is important to me. I have spent
    more than 15+ hours coding this bad boy. It is my child, and every child deserves a name. So, when you see that
    happy little color ball floating around the magic orb, just remember: his name is Eugene. This is part of
    the fulfillment for requirment 5.
    '''
    
    '''
	This function has both a list, and a keyword variable as an argument. It and the function after it
    are also both instance methods. Thus, they are part of the fulfillment of requirments 5, 6 and 7.
    '''
    def changeCenter(self, list = [0,0,0]): 
        self.center = list

    def changeColor(self, color):
        self.color = color

def sphereToString(sphereOb):
    return "sphere//newSphere\n{ <" + str(sphereOb.center[0]) + "," + str(sphereOb.center[1]) + "," + str(sphereOb.center[2]) + ">" + str(sphereOb.radius) + " pigment{" + str(sphereOb.color) + "}finish{" + str(sphereOb.finish) + "}}"
	
