/* CS360_Gabriel_Brehm */

#include "colors.inc"  
#include "textures.inc" 
#include "glass.inc"

camera {location <4,5,-6> look_at <0,3,0>} 
light_source {<900,500,300>, White} 
plane {y, 0 texture {Copper_Metal}} 
sphere {<0,0,0>, 1.5 pigment {Clear} finish {F_Glass4}} 