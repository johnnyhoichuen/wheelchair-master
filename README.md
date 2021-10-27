# wheelchair-test-master

## Background: 
I'm working on a university research project that targets at building an autonomous wheelchair. The current stage aims at reverse engineering a part of the wheelchair controller so to skip all the circuit designs, etc.  

## Original System: 
![original system](https://github.com/johnnyhoichuen/wheelchair-master/blob/main/images/Original%20system.jpeg)

The original wheelchair controller contains a Renesas R7F0C019L2 MCU [[1](http://www.jingbei.com/product-details-pdf.aspx?url=2484)] (I2C Master/Controller) and a Melexis MLX90393 Magnetic Position Sensor [[2](https://www.melexis.com/en/product/MLX90393/Triaxis-Micropower-Magnetometer)] (Slave/Target). The position sensor will send the position of a joystick mounted on the the wheelchair controller, according to periodic requests from the master MCU. 

However, as the wheelchair is bought from some vendor, I am **not able to change anything on the master MCU**.

## Target System (not this github project is about): 
![target system](https://github.com/johnnyhoichuen/wheelchair-master/blob/main/images/Target%20system.jpeg)

Replace the position sensor by an external MCU (eg. Arduino) so I can control the wheelchair through other means (eg. control by phone through bluetooth, or other positioning algorithm with the aid of sensors like LIDAR), without controlling the joystick manually.

## Test System (this project): 
![test system](https://github.com/johnnyhoichuen/wheelchair-master/blob/main/images/Test%20system.jpeg)
As the master MCU cannot be programmed or controlled directly, I need to build a system to verify the response from the slave MCU is correct.

------
## Data collected from both Orginal system and Test system 

#### [Link](https://docs.google.com/spreadsheets/d/14Tjfw3A1X9E1SeXIhwHKWUtzOc3ze9VOgDJX1UsS4KU/edit?usp=sharing)

------
### Here's the thing I've done:

#### Part 1. Record the I2C signals in the original system (Master's requests, slave's responses)
#### Part 2. Impletemented the copied signals on the test system
#### Part 3. (Not yet finished) Connect the arduino slave with the original MCU

---

### Issues in part 3:

![image of weird signals](https://github.com/johnnyhoichuen/wheelchair-master/blob/main/images/Weird%20signals.jpeg)
- Whenever the master requested multiple bytes from the slave when signals will appear. However, when the master requested 1 byte only, it works fine.
- [Discussion on Arduino forum for this issue](https://forum.arduino.cc/t/i2c-slave-sending-multiple-bytes-failed/918934)

---

#### [1]: [Datasheet of R7F0C019L2](http://www.jingbei.com/product-details-pdf.aspx?url=2484)
#### [2]: [Datasheet and other info of MLX90393](https://www.melexis.com/en/product/MLX90393/Triaxis-Micropower-Magnetometer)
