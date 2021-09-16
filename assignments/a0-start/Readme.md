# assignment0

# 2D Spheres
![Screenshot (11)](https://user-images.githubusercontent.com/89857301/132784351-b24c5b41-165b-445e-94d6-98d2a040e415.png)  
Draws a red 2D circle and then a green circle in front of the red one.  
The thing that I found the most useful was how to manipulate the z value when pushing objects backward. I was initially using a really low z value (like 10) and was wondering why it wasn't working. I realized you need to go bigger.

# 3D Sphere
https://user-images.githubusercontent.com/89857301/132786069-3bc6d27d-7b41-4630-9bf0-bcdb678422f6.mp4  

Creates a 3D circle that moves when the space bar is pressed then returns to its original position when 'R' is pressed.  
I had a bit of trouble with this, just sorting out the logic and stuff, but I got it after a little bit. However I couldn't figure out how to meaninfully use the randomUnitVector() function. I tried setting my velocity value to  
vel = randomUnitVector(), then  
vel = vec3(randomUnitVector())  
because I wasn't noticing any significant difference. It was minutely moving and would shift back to (0,0,0) when pressing 'R'. However I feel like it wasn't showing the actual code so I hardcoded a velocity.
