# Ventilation-Project

The web user interface covers up this section of the ABB ventilation control project. The web application enables user interaction with the LPCxpresso microcontroller that controls the fan and reads measurements from various sensors. The following settings can be managed via the web user interface's dashboard: the user can switch between automatic and manual modes; target speed when the user is in manual mode; target speed when the automatic mode is selected. Additionally, on the stats page, the user can view the detailed statistics of the measurement data kept in the database. User sessions, user activity and logins can be inspected on the user statistics page. The project also utilizes a separate *student* and *teacher/admin* account system. 

Created by Metropolia University of Applied Science IT engineering students in the Smart IoT Systems major.

# Contents
- [Description](#description)
- [User manual](#user-manual)
  * [Product specifications](#product-specifications)
  * [Intent use](#intent-use)
  * [Installation](#installation)
  * [Login](#login)
  * [Registration](#registration)
  * [User interface](#user-interface)
  * [Setting up the web interface](#setting-up-the-web-interface)
- [Documentation](#documentation)
  * [Technologies](#technologies)
  * [Accounts](#accounts)
  * [Database access](#database-access)
  * [Controller connection](#controller-connection)
  * [Visual design](#visual-design)
 
# Description
As it is well-known, carbon dioxide supplementation on plant growth and production is a key factor in a healthy greenhouse environment. Carbon dioxide (CO2) is an essential component of photosynthesis (also called carbon assimilation), whose process is of extremely importance in human’s wellbeing as it is the source of energy and food for all organisms. <br> <br>
As there is a need to create a system that helps the healthy growth of plants, especially in enclosed spaces, the project has been developed. Therefore, the project's objective is to create a greenhouse's CO2 fertilization controller system, where the CO2 level is maintained by a controller at the level chosen from the local user interface.  

# User manual
## Product specifications
The hardware used during the project development is shown in the picture below:
![Ventilation System](documentation_pictures/physical%20ventilation%20system.jpg)
                Ventilation System
The system consists of several components:
* __LPC1549 (MCU):__
LPC1549, an ARM-cortex M3 based microcontroller was used in this project, that features a rich peripheral set with very low power consumption. The LPC1549 operate at CPU frequencies of up to 72 MHz. The LPC1549 include up to 256 kB of flash memory, 32 kB of ROM, a 4 kB EEPROM, and up to 36 kB of SRAM. Among the features, mainly, NVIC, Systick Timer, Watchdog timer, communication protocols: I2C, Modbus, and UART, were used for this project.
* __LCD Screen:__
The LCD (Liquid Crystal Display) screen is an electronic display module and has a wide range of applications. A 16x2 LCD display is very basic module which is very commonly used in various devices and circuits, as it can display 16 characters per line and there are 2 such lines. It is used to show the current Co2 levels and display the information provided by the sensors.
* __Rotary Encoder:__
A rotary encoder is a type of position sensor, they measure rotary movements and displacement and can either be absolute or incremental. The systems uses it to get information on position, speed, count or direction that it is placed on, and adjusting the Co2 levels to the user’s input.
* __Arduino Uno:__
Arduino is an open hardware development board that is used to design and build devices that interact with the real world. During the development process, the Arduino Uno has been used to simulate input from the temperature, humidity and CO2 sensors and its purpose is to serve for basic testing of the software. When the product is used with real sensors, the software behaves in the same way as with the simulator and it does not make use of the Arduino Uno.
* __Wifi Module:__
The ESP8266 WiFi Module is a self contained SOC with integrated TCP/IP protocol stack that can give any microcontroller access to your WiFi network. Therefore, this module brings to the system the possibility to connect to internet, which is a key factor in the data transmission.<br>

The sensors used to collect data in the embedded system are the following:
* __GMP252 co2 probe:__ Vaisala's GMP252 co2 probe was used to measure and collect information on the co2 concentration. GMP252 is designed for CO2 measurement in demanding applications that require reliable and accurate performance. The measurement range is 0 - 10 000 ppmCO2 (measurements can be carried out in the 10 000 - 30 000 ppmCO2 range with reduced accuracy). It is an intelligent, stand-alone, ppm-level probe. It's intended for measuring CO2 igreenhouses, among other places.
* __HMP60:__ Another one from Vaisala, HMP60 Humidity and Temperature Probe measures and transmittes temperature and humidity readings. HMP60 series probes use the interchangeable Vaisala INTERCAP® sensor. No recalibration is required after sensor replacement. It is a simple, durable and cost-effective humidity probe suitable for greenhouses.

## Intent use
The software’s purpose is to be used in a greenhouse environment, as shown below:
![Physical Greenhouse](documentation_pictures/physical%20greenhouse%20edited.jpg)

## Installation
To install the web application, clone the repository into your selected directory.
```
git clone https://github.com/nessa01macias/Ventilation-Project.git
```
Downloading as a .zip package is available on the Github interface.
## Login
Log in with your username and password on the localhost:PORT/ route. In case you don't have an account yet, click on the "Register now!" link.
## Registration
You can register an account via the /register route. You will be required to provide a username and a password. To create a teacher/admin account, also provide the secret teacher code. This code is adjustable and changeable on the server side via a .env environment variable. You will be redirected to the login page.
## User interface
When you log in, you will be directed to the dashboard. On this page, you will be able to set the mode (manual or auto) and the corresponding value (fan speed or pressure level) of the ventilation system.

On the top of the page you will find a navigation bar which you can use to access the sensor data, user statistics page or log out.

On the sensors page, you can see the pressure, Co2, speed and temperature measurements on graphs.

On the User stats page, students will see their own account's login details, while teachers will be able to inspect the login frequency on all accounts and their own statistics.
## Setting up the web interface
To connect the web application to the ventilation system's controller, you have to manually set the MQTT connection up (IP address, port number, topics) hardcoded on the server side. The default topic for commands is <em>'controller/settings'</em> and <em>'controller/status'</em> for reading data from the ventilation system.

You will also need to set up your own database URI, your teacher code, as well as your selected port number as an environment variable.
# Documentation

## Technologies
The foundation of the web application is a Node.js server connected to a NoSQL MongoDB database. The visual look of the application is built via Bootstrap and jsDelivr.

The web interface uses a number of modules which will need to be downloaded using npm before using the application. The command for this is

```
npm i <module-name>
```

The used modules are:
- [animatejs](https://www.npmjs.com/package/animejs)
- [express](https://www.npmjs.com/package/express)
- [mqtt](https://www.npmjs.com/package/mqtt)
- [body-parser](https://www.npmjs.com/package/body-parser)
- [passport](https://www.npmjs.com/package/passport)
- [crypto-js](https://www.npmjs.com/package/crypto-js)
- [mongoose](https://www.npmjs.com/package/mongoose)
- [connect-flash](https://www.npmjs.com/package/connect-flash)
- [method-override](https://www.npmjs.com/package/method-override)
- [express-session](https://www.npmjs.com/package/express-session)
- [chart.js](https://www.npmjs.com/package/chartjs)
- [ejs](https://www.npmjs.com/package/ejs)
## Accounts
We handle account management with the help of the `crypto-js` module for password encryption/hashing and MongoDB for storing the account usernames and hashed passwords. Upon login requests, the input password is hashed and compared to the one in the database after querying for the entry with the username. Other than username and password, the database also records whether the user is a teacher in a boolean value.

Example of a MongoDB user entry.
![Users](https://user-images.githubusercontent.com/70892020/198275946-a433216a-2759-4ee4-b2b7-b15675ec9936.png)

## Database access

The Node.js server connects to the database via the `mongoose` module. The module allows us to create objects in the database based on our schemas and query through them. The schemas used by us describe users, user statistics and controller data.

| Data        | UserStat           | User  |
| :-------------: |:-------------:| :-----:|
| nr: <em>Number</em>| username: <em>String</em> | username:  <em>String</em> |
| speed: <em>Number</em>| logins: <em>[Date]</em>|password:  <em>String</em> |
| setpoint: <em>Number</em> | mode: <em>[String]</em>|isTeacher: <em>Boolean</em> |
| pressure: <em>Number</em> | <em>Timestamps</em>||
| auto: <em>Boolean</em> |||
| error: <em>Boolean</em> |||
| co2: <em>Number</em> |||
| rh: <em>Number</em> |||
| temperature: <em>Number</em> |||
| date: <em>Number</em> |||
| <em>Timestamps</em> |||


## Controller connection

We connect to the ventilation system via MQTT. To do this, we need the `mqtt` module. The setup of the connection is hardcoded in the `index.js` file. By default we publish commands to the `Group5/controller/settings` topic and subscribe to `Group5/controller/status` for measurement readings.

## Visual design

![Dashboard](UI%20images/Screenshot%202022-10-31%20001326.jpg )
Dashboard

![Login](UI%20images/Screenshot%202022-10-31%20001417.jpg )
Log in page

![Registration](UI%20images/Screenshot%202022-10-31%20001440.jpg )
Registration page 

![Sensors page](UI%20images/Screenshot%202022-10-31%20001518.jpg )
Sensor's information page

![user info page](UI%20images/Screenshot%202022-10-31%20001655.jpg )
Student's or Teacher's info page

![teacher info page](UI%20images/Screenshot%202022-10-31%20001628.jpg)
Teacher's information page
