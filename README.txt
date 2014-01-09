2014.01.09
rpipes (raspbery pi temperature monitor)

Looks for logical low on gpio(x) to indicate
temperature is below a calibrated threshold.
As of this writing, the trigger mechanism consists
of a bimetal coil-- taken from a guage type wall 
thermometer ($4.00)-- as a switch conecting a 
pullup resistor to gnd.

Requires a Raspberry Pi V2, and the components below.

   Schematic (view with mono-spaced font)
 
        +3.3V
         |        
         \     
         /     
         \ 100K
         /     
         \     
         |     
         +-- Gpio(X)
         |     
         +
          \    
           \ bimetal coil
         +
         |
         |
         |
        GND

The remainder of the readme file has been deleted.... oh... snap!
It's up to contestants in the CSI-280 raspberry pi challange to 
complete this README file and get the code running on a raspberry
pi in Foster 202.

The initial code uploaded to http://github.com/abthefish/rpipes
has been successfully tested on a *hint* correctly configured *hint*
raspbery pi v2.  One minor-- and obvious-- change is required to main.c 
for the raspi to correctly email the warning message.

Any student who has contributed meaningful(*) code to this project
on github will share equally in the (to be determined) presigious
prize!

Regards and Good Luck,
Ray

(*) meaningful means I will use /your/ commit on the monitor in my house.
