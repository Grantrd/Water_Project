# Water_Quality_Monitoring_Project

This project for Gary Mahoney and Dr. Wei Wu, a collaboration between Scott Heggen, Wei Wu and Rodney Grant. 
It is meant to allow for the measuring and recording of the quality of water in lakes. The project consists of code
written in arduino, and using schematics and PCB's made in eagle cad software, and a custom milled pcb. This is a 
school project funded by Berea College. 

## Required Components
To use this project you will need: 
- To be able to mill a PCB
- A 4.7K ohm resistor and a Digital Temperature probe
- An Arduino Micro SD adapter.  
- An analog light sensor
- A real time clock
- 2 1K to 500K Potentiometers
- A set of molex connectors  


## Getting Started

To use the project you need to install the Arduino programming software. Open the code folder of the project, and copy the contents of the arduino libraries folder into the libraries folder of your arduino software, typically located in yourUserName\Documents\Arduino\libraries. Plug in your Arduino Mini Pro and open the Arduino Software. In the software go to "tools" -- "board" -- "Arduino Pro or Pro Mini". Go to open and select the Gary_Node_Temp.ino file located inside the Ard_code_328P in the code folder of the Project. Then Go to "tools" -- "port" and select the port with the arduino connected, you can unplug and replug the arduino to see which port it connects to. Finally verify and upload the code onto the arduino. If the code will not verify, make sure the libraries are located in the correct folder.  

## The Board

Note if you already have the PCB, you can skip the milling section.  

### Milling the Board

### Soldering the board 
To solder the board you will need the milled PCB, and all of the required components listed above. 


![Board Layout](https://github.com/Grantrd/Water_Project/blob/master/Documentation/Assembly.png "Board")
