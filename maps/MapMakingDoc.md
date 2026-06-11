#This is a document that is made for you to see how to make a map. 
If you are uninterested, then there are two standard maps for you. "square.txt", "longsquare.txt" and "default_map". These at baddumbassmaps aren't good, but you can check them out.

##How do I make a map? What do i need to know?
Every map has one similar thing. They have values at the top, 0 and 1s, and values at the top. So, what do they mean?

Values at the top (X Y) mean how wide or long your map should be in numbers (should be integers). Y is UP - DOWN, vertical; X is RIGHT - LEFT, horizontal. 

Values at the middle ( 0 1 0 1 0 ) mean what the map is. Walls are 1, floor is 0. I fill them first. Borders always have to be square like. The size is always loaded in like a square. Don't make them just 1D lines or TRIANGLES. Also make spaces between each number.
RECOMMENDATION: each time the width ends when you're typing the values in the middle, make a new line.

Values at the bottom (X Y) mean where the player will spawn. You can write floating point numbers in. As i said, Y is UP - DOWN, vertical; X is RIGHT - LEFT, horizontal.

New values at the bottom that are below the older bottom values (X Y) mean where the player will look. This thing is kinda dangerous and can break your map, So I recommend using these values:
1 0 - Looking right
-1 0 - Looking left
0 1 - Looking down
0 -1 - Looking up

ALSO: don't make ANY comments or extra additions. It may break the loading algorithm.

##So, what? What do i do?
You just have to fill the values in the middle with what you want your program to look like. Then, count the width and height of your map, type them in like:
width height

and then write where the player will spawn like this:
width height

And then write where the player will look like this:
width height

##What if i want to add something else than just walls?
I didn't make this raycaster to be able to render ANYTHING except walls. You are free to edit the project, though.


