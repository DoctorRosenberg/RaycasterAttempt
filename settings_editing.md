#A short doc if you don't know how to be in settings.txt
Here you'll see how to edit the settings.
Make sure to always make spaces between "thing" " = " and "value".

##ScreenWidth and ScreenHeight
Type in your screen resolution. For example, if it's 1930x1440 (idk if that's a real monitor), write:
`` txt
ScreenWidth = 1930
ScreenHeight = 1440
``

##RotateSpeed
This is how fast you will rotate. I personally set this at 0.5. You can write anything you want, as long as you're comfortable with that.
`` txt
RotateSpeed = 0.5
``

##Fullscreen
Here, you have to write a value. 0 or 1. 0 means 'false', while 1 means 'true'. Obviously.
`` txt
Fullscreen = 1
``

##Map
So, you have to write a path to the map.
I'd recommend putting your map in project directory, and in the 'maps' folder. If you do that, all you have to do is change the txt file name in settings.

from:
`` txt
Map = ./maps/longsquare.txt
``

to this:
`` txt
Map = ./maps/yourmapname.txt
``

if you want to add a folder in maps, you can add its name and the forward slash, like:
`` txt
Map = ./maps/baddumbassmaps/default_map.txt
``


You can try different directories, but i'm lazy to give you a guide for that.

