This repository holds a Collection of Eagle schematics and board layouts for driving Nixie and VFD display tubes.
These schematics are not yet verified. The IN-12 Shield is tested ok. The modules are still in development.
  
#IN-12-Arduino Shield 

![IN12Shield1](http://www.timeexpander.com/wordpress/wp-content/uploads/Nixie2.jpg)

![IN12Shield2](http://www.timeexpander.com/wordpress/wp-content/uploads/Nixie1.jpg)

A video of the shield running the code sample can be found here: https://youtu.be/qcBPYD-F15M

The shield has 4 IN-12 Nixie tubes. The shield requires external 170V power. 5V is obtained via the shield connector. Pin mapping is as follows

##Parts list:

- 4 x IN-12 tubes.
- 4 x K155ID1.
- 2 x 74HC595.
- 4 x anode resistors. The value of these should be calculated according to tube rating and drive voltage.
- 5 x pushbutton switches (optional).  

###Arduino pin mapping
- D0: SER
- D1: RCLK
- D2: SER
- D8-D12: optional switches.  


# IN-2 Nixie-Modules
Each Module has two Nixie tubes, a shift register and a nixie driver. The modules require external 5V/170V power. The on-board shift registeres allows the modules to be daisy chained.  

##Parts list:
- 2 x IN-2 tubes.
- 2 x K155ID1.
- 1 x 74HC595.
- 2 x anode resistors. The value of these should be calculated according to tube rating and drive voltage.  

![IN2Modules](http://www.timeexpander.com/wordpress/wp-content/uploads/in2-modules-running.jpg)

![IN2Modules_individual](http://www.timeexpander.com/wordpress/wp-content/uploads/in2-modules2.jpg)

![IN2Modules_assembled](http://www.timeexpander.com/wordpress/wp-content/uploads/in2-modules-assembled.jpg)

# TimeExpander Eagle Library
The librar contains Eagle symbol, package and device definitions for K155ID1 (pin compatible with the obsolete 74141) along with the following display tubes:  
- IN-1 
- IN-2
- IN-12
- IV-12
- IV-22

# IN-1-Modules
TBD

# VFD-Modules
TBD

![License](http://mirrors.creativecommons.org/presskit/buttons/88x31/png/by-nc-sa.png)

Hans Jørgen Grimstad
www.TimeExpander.com
