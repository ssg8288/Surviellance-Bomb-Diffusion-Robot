<h2> What is Internet Based Navigation and control? </h2>
In the older version of the Crawler we had controled the Rover with Bluetooth but in the New version we have done it using internet, hence now if you want to contolr this rover <br>
by just siting at your home and the rover is at the other End of this eart just is connected with the internet then you can do so.
Refer the top Right 
<p align="center">
<img src="https://github.com/ShubhamPatel33/Surviellance-Bomb-Diffusion-Robot/blob/main/Crawler/Block%20diagram_Surviellance.png?raw=true" alt="Upgraded Diagram_2"/>
</p>
<b><h3>How we had made it possibel?</h3></b>
By using a Electric imp module ,we have connected Arduino and the crawler circuit with the internet so that we don't need to rely on any other module and also the rande dosen't become
and boundries of this Crawler.
<h3>Steps of Controling the rover</h3>
<ul>
   <li>The Rover is controled by a webapp nad hence you can control it with the direction arrows .</li>
   <li>The response from the user's side when he/she clicks a button on the webpage is taken by the Javascript file and then passed to the Electric imp module .</li>
   <li>The Electric IMP module is used to connect the Arduino with the internet and hence first it recieves response and then passes the responses to the next set of pins of Arduino</li>
   <li>Response recieved by the pins (1,2,8,9) of Electric IMP module is passed to the (10,9,12,2) pins of the Arduino </li>
   <li>After recieveing the inputs from the IMP module the Arduino changes the state of Various Motors which creates the movement of the Crawler Circuit.</li>
   
<h3>Hardware Requirements =></h3>
<ul>
    <li>6WD Wild Thumper Arduino Chassis</li>
    <li>4 Motors</li>
    <li>6 Wheels</li>
    <li>Wild Thumper Arduino Controller</li>
    <li>LiPo Battery - 7.2V 5000mah </li>
    <li>Electric Imp</li>
    <li>Electric Imp breakout board</li>
    <li>Jumper cables</li>
</ul>

<h3>Webapp for Controling the Crawler =><h3>
<p align="center">
<img src="https://github.com/ShubhamPatel33/Surviellance-Bomb-Diffusion-Robot/blob/main/Internet%20based%20control/Movement_ss_Crawler.png"/>
</p>
    
