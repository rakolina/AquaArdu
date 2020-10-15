AquaArdu
========

Aquarium Automation

Specific purpose of this setup is to pause filtration for a segment of time while the automated feeder drops food. Depending on how long your fish spend eating, the food will not be eaten by the filtration sysytem! Win and win.
 
 Hardware: 
 smart wall relay, 
 standard wired aquarium filter, 
 DIY feeder made from a standard battery operated spin fish feeder spinned by a small motor actuator, (3D printer design from thingiverse)
 arduino uno + bluetooth antenna + momentary button with LED indicator light
 
Use this to control a wall power relay with arduino uno wired to LED momentary button.

On button push start timer for 5 minutes (300000 ms). When interval 
ends, turn relay back on.

At every button push 5 minutes is added on, previous duration is thrown out.

Button stays on when relay is on, flashes when relay is off with timer going, stays off
when relay is permanently off (no timer going).
