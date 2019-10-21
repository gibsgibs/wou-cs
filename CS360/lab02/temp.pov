/* CS360_Gabriel_Brehm */

#include "colors.inc"  
#include "textures.inc" 
#include "glass.inc"

light_source
{
    <900,500,300> 
    White
}     

camera{location<-7.500000000000002,20.98,12.990381056766578>
    look_at <0,3,0>

} 

sky_sphere 
{
    pigment 
    {
        gradient y
        color_map {
        [0.5  color CornflowerBlue]
        [1.0  color MidnightBlue]
    }
    scale 2
    translate -1
    }
}

plane
{        
    y, 0
    texture {Copper_Metal}
    finish {reflection 0.25}    
}

union //sphere shapes
{ 
    sphere
    {
        <0,0,0> 1.5     
        pigment {Clear}
        finish {F_Glass4}
                
    } 
    
    union
    {
        difference
        { 
            intersection
            {
                sphere
                {
                    <0,0,0>, 1.45
                    texture{Chrome_Metal}
                    finish {reflection 0.5} 
                }             
                
                box
                {
                    <-1,-1,-1>, <1,1,1>
                    texture{Chrome_Metal}
                    finish {reflection 0.5} 
                } 
            }
                
            sphere
            {
                <1,0,0>,  .5
                pigment {Pink_Granite}
                finish {reflection 0.5}
            }
            sphere
            {
                <0,0,1>,  .5
                pigment {Jade}  
                finish {reflection 0.5}
            } 
            sphere
            {
                <-1,0,0>,  .5
                pigment {Blood_Marble}
                finish {reflection 0.5}
            }
            sphere
            {
                <0,0,-1>,  .5
                pigment {Blue_Agate}
                finish {reflection 0.5}
            } 
            sphere
            {
                <0,1,0>,  .5
                pigment {Sapphire_Agate}
                finish {reflection 0.5}
            } 
            sphere
            {
                <0,-1,0>,  .5
                pigment {Red_Marble}
                finish {reflection 0.5}
            }
        }
        scale 0.5 
    } 
    translate <0,3.348995,0>
}
                         
union //stand
{
    torus
    {                            
        1, 0.1  
        pigment{Silver}
        finish {reflection .4}
        translate <0,2,0> 
        texture {DMFDarkOak}    
    } 
    
    cylinder
    {
        <1,2,0>, <1.5,0,0> 0.1  
        pigment{Silver}
        finish {reflection 0.5}
        texture {DMFDarkOak}
    }
    
    sphere
    {
        <1.5,0,0>, 0.1
        pigment{Silver}
        finish {reflection 0.5}
        texture {DMFDarkOak}
    }
     
    cylinder
    {
        <-1,2,0>, <-1.5,0,0> 0.1  
        pigment{Silver}
        finish {reflection 0.5} 
        texture {DMFDarkOak}
    }
    
    sphere
    {
        <-1.5,0,0>, 0.1
        pigment{Silver}
        finish {reflection 0.5}
        texture {DMFDarkOak}
    }
     
    cylinder
    {
        <0,2,1>, <0,0,1.5> 0.1  
        pigment{Silver}
        finish {reflection 0.5}   
        texture {DMFDarkOak}
    }
    
    
    sphere
    {
        <0,0,1.5>, 0.1
        pigment{Silver}
        finish {reflection 0.5}
        texture {DMFDarkOak}
    }
      
    cylinder
    {
        <-0,2,-1>, <0,0,-1.5> 0.1  
        pigment{Silver}
        finish {reflection 0.5}  
        texture {DMFDarkOak}
    }
    
    sphere
    {
        <0,0,-1.5>, 0.1
        pigment{Silver}
        finish {reflection 0.5}
        texture {DMFDarkOak}
    }
    translate <0,0.1,0>
}
