## Tactical Phising Attacks with ESP8266

Use this script and the portal templates provided to create malicious WiFi AP'S
The logic is to create an AP that mimics industrial free WiFi portals through DNS spoofing and redirect clients to a phising webpage hosted at the ESP8266 itself

|                                                                                                                                |                                                                                                                                |                                                                                                                                |
| ------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------ |
| <img src="https://user-images.githubusercontent.com/29873078/119835325-6bda1f80-bf09-11eb-8c6d-a5c30f2823a8.png" width="280"/> | <img src="https://user-images.githubusercontent.com/29873078/119835349-6f6da680-bf09-11eb-8c79-0130b1bb0c61.png" width="280"/> | <img src="https://user-images.githubusercontent.com/29873078/119835361-71d00080-bf09-11eb-8016-a2963953ab82.png" width="280"/> |

#### Available Templates

-   Facebook
-   Google
-   Instagram
-   Starbucks
-   Twitter

### Usage

-   Install Arduino IDE
-   Install required libraries and depedencies for ESP8266 [https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide "https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide")
-   Install SPIFFS tool for ESP8266 [https://github.com/esp8266/arduino-esp8266fs-plugin](httphttps://github.com/esp8266/arduino-esp8266fs-plugin:// "https://github.com/esp8266/arduino-esp8266fs-plugin")
-   Clone this repo and open it in Arduino IDE
-   Open `esp8266_phising.ino` and change SSID
-   Open folder `portals/` with your file manager
-   Pick your prefered template and copy all files to `data/`
-   Flash SPIFFS
-   Flash script
-   Connect to your network and navigate to `http://172.0.0.1/getinfo` to see the collected passwords
-   Navigate to `http://127.0.0.1/deleteinfo` if you want to clear the passwords

### Big ups to

[https://github.com/125K/ESP8266_WiFi_Captive_Portal](https://github.com/125K/ESP8266_WiFi_Captive_Portal "https://github.com/125K/ESP8266_WiFi_Captive_Portal")
[https://github.com/ojack/ESP8266-captive-portal-webserver/](https://github.com/ojack/ESP8266-captive-portal-webserver/ "https://github.com/ojack/ESP8266-captive-portal-webserver/")
[https://github.com/kleo/evilportals](https://github.com/kleo/evilportals "https://github.com/kleo/evilportals")

<span style="font-size:8px">\*Only for educational purposes</span>
