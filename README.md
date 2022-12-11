# Garage Internal Makeathon Team 1

## Project - Annoying Clock

## Description
Its hard to wake up every morning. Especially when you turn off your phone alarm and continue sleeping. This clock will make sure you wake up! Solve a math problem to turn off the alarm! If math problem not solved in 3mins, buzzer will play annoying sounds! Wake up or face the consequences!

## Known Issues
* If user cancel's alarm while setting the alarm in menu B, LCD shows Set Alarm: ****** [Fix: Need to get rid of this] <br>
* Cannot key in answer to math question while music is playing [Fix: Use ESP32's multithreading] <br>
* Only way for the user to connect to their own WiFi network is by editing the code [Fix: Need to find a way to let user register WiFi credentials] <br>

## Upgrade Ideas
* Directional speaker with ultrasound (In a room with multiple people... Only one person can hear the sound... This is done so as to not wake up others in the room)... Check out https://www.youtube.com/watch?v=9hD5FPVSsV0&t=17s <br>
* Add some motors to the clock and make it move around... Give the user some morning exercise! (Already have the hardware for this! Just need to slap the clock onto the hardware... Check out https://github.com/devKarthikRaj/Rover-v1 <br>