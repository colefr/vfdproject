# vfdproject
*A modular, tile-able solution for IV-11 Vacuum Fluorescent Display tubes.*

by Cole Frauzel, August 2022

![4x IV-11 VFDs, front and center, illumied with numbers](/img/4tubes_on_front.jpg)

## What is it?
I had these old Soviet tubes for a long time. I had bought them years ago on eBay, back before the price of retro-numbers for retro-clocks inflated dramatically. At last, I needed to put them to use. But Vacuum Fluorescent Displays aren't just LED 7-segments. They're vacuum tubes of course! And they need some special treatment. And so I designed the circuit, grabbed some IC's and began the project: to make a modular, tile-able solution for VFDs that was tinkerable and easy to understand.

![An unpopulated tube board](/img/board_unpopulated.jpg)

## The board
The board is of my own design, and is about as simple as it can be. The tubes demand two voltages: +1.25VDC for the *cathode* and +25VDC for the *grid* and the segments, which are the *anodes*. The tube is a true triode vacuum tube.

On the board is of course the tube, with its radial pins. Above are two ICs: a *high-side-driver* to steer the +25V to the segements, and a good-ol' 74HC595 shift register. The shift register setup lets you theoretically tile as many of these board together as you wish. (I of course only had four.)

![The power board](/img/power_board.jpg)

## Power
The whole setup needs three stable voltages. +1.25VDC and +25VDC for the tubes, and +5VDC for the shift registers and the microcontroller (in this case an ATTINY85). Power comes in at +12VDC and is bucked down to the lower voltages and boosted to the higher by the three boards. The DC jack is mounted on a quick 3D-printed solution also of my own design.

![3D Printed DC jack holder](/img/3dprint.jpg)

## Assembly
With chips and tubes soldered in place (forgive me! no sockets here!), the boards are bussed together with some simple wire. The PCBs themselves are attached to eachother by standoffs, which unintentionally gives this interesting "step-up-step-down" profile.

![The soldered undersides](/img/underside.jpg)

## Completion
Version 1 is now complete and functionnal. Not without some debugging, though! In software, of course. The multimeter and I were well acquainted during setup, ensuring no discontinuity (not continuity where there shouldn't be!)

![The back of the tubes, dating them to the early 90's](/img/backside.jpg)

## Success
To celebrate, I printed this cheeky plaque, YouTube-Style. Though you won't find me there!

![Cole's Lab](/img/coleslab.jpg)




