# Water_Quality_Monitoring_Project
This project for Gary Mahoney and Dr. Wei Wu, a collaboration between Scott Heggen, Wei Wu and Rodney Grant. It is meant to allow for the measuring and recording of the quality of water in lakes. The project consists of code written in the Arduino ide, and uses schematics and PCB's made in eagle autocad software. This is a school project funded by Berea College.

## Specifications
The board we are creating is made for an Arduino Pro Mini, and acts as a shield for it. Therefore the legs of the Pro will need to be soldered going up and have the board sit on top of the Arduino. The board is 1.04 inches across by 1.79 inches long. 

## Required Components
To use this project you will need: 
- An Arduino Pro Mini
- To be able to mill a PCB/ have the milled PCB 
- A 4.7K ohm resistor and a Digital Temperature probe
- An Arduino Micro SD adapter.  
- An analog light sensor
- A real time clock
- 2 1K to 500K Potentiometers
- A set of molex connectors
- A 6 Pin 90 degree Female header terminal.   

## Getting Started
To use the project you need to install the Arduino programming software. Open the code folder of the project, and copy the contents of the arduino libraries folder into the libraries folder of your arduino software, typically located in yourUserName\Documents\Arduino\libraries. Plug in your Arduino Mini Pro and open the Arduino Software. In the software go to "tools" -- "board" -- "Arduino Pro or Pro Mini". Then Go to open and select the Gary_Node_Temp.ino file located in the Arduino Code folder inside the Code folder of the Project. Then Go to "tools" -- "port" and select the port with the arduino connected, you can unplug and replug the arduino to see which port it connects to. Finally verify and upload the code onto the arduino. If the code will not verify, make sure the libraries are located in the correct folder.  

## The Board
Note if you already have the PCB, you can skip the milling section.  

### Milling the Board
...

### Soldering the board 
To solder the board you will need a soldering iron, solder, a milled PCB, and all of the required components listed above. 
You will need to solder the components for the board according to their location on the color coded diagram found under Board Layout. 

For the following components you will need to solder female ended molexes connectors to the board in place of the components, and solder male headed molex connectors to the ends of the components. They will then plug into each other.
- Temperature Probe
- Real Time Clock
- Power Switch
- Light Sensor

For the following components you will need to solder the components themselves to the board directly.
- Power Switch
- 4.7K Resistor
- 2 Potentiometers

For the Micro SD Writer you need to solder a 90 degree 6 pin female header terminal.

### Board Layout
![Board Layout](https://github.com/Grantrd/Water_Project/blob/master/Images/Board_Layout.png "Board")

