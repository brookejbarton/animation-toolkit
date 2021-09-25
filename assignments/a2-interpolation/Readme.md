# assignment2

# Gradient


![Screenshot (14)](https://user-images.githubusercontent.com/89857301/134753337-9a5201bd-cd87-44cd-837a-9e5fa4d77b4f.png)

Create a gradient using four initial color vectors.

# Draw Cubic

https://user-images.githubusercontent.com/89857301/134753396-244025e5-f9a5-41c6-a006-052504fdccb2.mp4

When 2 is pressed, a red curve using Casteljau is drawn. When 1 is pressed, a blue curve using Bernstein is drawn.

# Cubic Motion

https://user-images.githubusercontent.com/89857301/134753428-9c9988e8-b160-404c-9813-4eb15507255d.mp4

Animate a sphere so that it follows along a curve and wraps around the screen.

# Screensaver

I couldn't get mine to run. So basically I created structs for each of the three curves to hold the control points associated with each of them.
I used vec4s since there were 4 control points, however each of the control points were themselves vec3. So it was a vec4 containing vec3's. The
issue came when I passed the vec4's (called vecSet) into the Castejau function and tried to separate the pieces of vecSet into their individual B0, B1, etc,
components. I think the error was saying that I can't cast a vec4 to a vec3 but that didn't make since to me since vecSet.x should technically be
a vec3. Right?

# Unique

https://user-images.githubusercontent.com/89857301/134753574-e007e000-5d59-4e19-bda3-a020463e8248.mp4

Not the most cool thing, if I'm being honest, but you seemed to kind of find it interesting when I showed you my incorrect Gradient code. I thought
it would have been cool if it wrapped around the screen but I didn't know how to do that.

I found the programs more approachable this week. Obviously I didn't fully complete them again but I finished more than I was able to last week.
I also feel like I understand the math but lack a bit of coding skills to put them all together.


