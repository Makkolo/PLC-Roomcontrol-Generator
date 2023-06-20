# PLC-Roomcontrol-Generator
Basic command window program that generates Global variable list, datatypes, generalized roomcontrol function blocks, neccesary functions and KNX-, HVAC-, Roomcontrol program. KNX program uses wagoAppKnx library, Everything else is indeppendent.
Generates XML file based on the [IEC 61131-3 standard](https://plcopen.org/technical-activities/xml-exchange), and should be compatible with all IEC 61131-3 programs like for example codesys 3.5.
All programs except for the HVAC program (ST), are generated in CFC for better visualization.

## Generated program structure
* GVL containing all rooms as datatypes including all content specified by Room content code.
  - Variable format used: GVLname.VariableName_RoomName
* DTU for all the different room content codes used.
* HVAC program that combines all HVAC signals to one signal. (ST)
* FB for all the different room content codes used. If row 3 is set to 1, a generalized room control program is generated inside the FB. (CFC)
* Roomcontrol program that calls a sepperate function block for each room with enough content for room control. (CFC)
* KNX program that reads and sends all knx variables, with ocasional force sending of outputs. (CFC)
* Functions used in generalized roomcontrol function block (ST)

## Input format
### .txt file
Currently uses a txt file as input. The txt file needs to be split with tabs and lines, like this:
| Global variable list name | Variable name (before room name) | | | |
| ------------------------- | -------------------------------- |
| Room name | Room content code | Room control content code | Generate room generalized room control function blocks? (0/1) | Description/comment |
| Room name | Room content code | Room control content code | Generate room generalized room control function blocks? (0/1) | Description/comment |

### Content code
Room content code and room control content code uses a code in the following sequence:
| Motion | HVAC | Temperature | Co2 | Heating 0-100% | Heating on/off | Cooling 0-100% | Cooling on/off | Setpoint out | Setpoint feedback | Humidifier status (on/off) | Humidifier alarm (Al/Ok) | Room mode out (Byte) | Humidity |
| ------------- | ----------- | --- | -------------- | -------------- | -------------- | -------------- | ------------ | ----------------- | -------------------------- | ------------------------ | -------------------- | -------- |
| 0-9 |  0-9 |  0-9 |  0-9 |  0-9 |  0-9 |  0-9 |  0-9 |  0-9 |  0-9 |  0-9 |  0-9 |  0-9 |  0-9 |  0-9 | 

Each vaulue can be 0-9 and represents the number of devices. If not all values are set, the rest of the sequence will be equal to 0. 
For example. content code `22101` will have 2 motion sensors and HVAC signals, 1 temperature sensor, and one heating output 0-100%

### Difference between row 2 and 3
Row 2 is content code which is used to generate the datatype and KNX program.

Row 3 is Room control content code which is used to generate the Room control program and function block. Normaly set to the same as row 2, unless you have content that you dont want to be included in the roomcontrol program.

## How to use
1. Download the last release and store it somewhere.
2. Create a .txt file in the same folder and fill it in acording to the input format. (reccomended to create the input in excel and then copy it into the .txt file)
3. Run the downloaded file and input the name of the .txt file when asked for.
4. After succesful generation, the output .xml file is stored in the same folder and the path is copied.
5. Open the PLC program and find the import button (import PLC open xml in some programs)
6. CTRL + V and then enter to use the generated xml file.
7. Choose the content to import, and press import.

## Example
Input file:

<img width="351" alt="image" src="https://github.com/grisMort/PLC-Roomcontrol-Generator/assets/115706031/0df43f2a-e4ea-4f86-945e-23a1b0376204">

Command window:

<img width="396" alt="image" src="https://github.com/grisMort/PLC-Roomcontrol-Generator/assets/115706031/067d9baf-693a-4a73-b25b-4cb95ab0f096">


Import dialog in codesys 3.5:

<img width="512" alt="image" src="https://github.com/grisMort/PLC-Roomcontrol-Generator/assets/115706031/8f01174f-b88e-41bf-8c0c-b19e7305bd0e">

Imported items (libraries not included):

<img width="207" alt="image" src="https://github.com/grisMort/PLC-Roomcontrol-Generator/assets/115706031/931d2217-8a81-490c-93df-63ed89b75602">

GVL (add retain persistent if wanted):

<img width="319" alt="image" src="https://github.com/grisMort/PLC-Roomcontrol-Generator/assets/115706031/af2ca576-ba97-48a8-8147-57a32b5f9be3">

one of the Datatypes: 

<img width="214" alt="image" src="https://github.com/grisMort/PLC-Roomcontrol-Generator/assets/115706031/cbb7bed1-eacd-4ad1-a62e-8165f81175be">

HVAC program: 

<img width="294" alt="image" src="https://github.com/grisMort/PLC-Roomcontrol-Generator/assets/115706031/930c3a16-b241-4aae-bea7-ba95fccdb66f">

One of the FB's as of release 1.0: 

<img width="1468" alt="image" src="https://github.com/grisMort/PLC-Roomcontrol-Generator/assets/115706031/81b16d65-66bf-48ca-ac17-bbe33030473f">

Roomcontrol program:

<img width="578" alt="image" src="https://github.com/grisMort/PLC-Roomcontrol-Generator/assets/115706031/d6cda86a-d1ab-4b3b-9641-041593d06a76">

KNX program:

<img width="1252" alt="image" src="https://github.com/grisMort/PLC-Roomcontrol-Generator/assets/115706031/76aaab96-fbf2-49cd-8a08-2ee24118c3b5">

PID and Hyst funtion not up to date.

