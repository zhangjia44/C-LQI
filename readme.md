
## The reproduction of WEBee  
  
- Author: Jia Zhang, Haotian Jiang.  
- Contact: thss15_zhangj@163.com, heyust@gmail.com.  
- Description: The code aims to reproduce WEBee and was completed by the author in July 2018. It is reproduced on the basis of gr-ieee802-11 and gr-ieee802-15-4.  
As  a long time has passed, I am sorry that some implementation details may no longer be clearly explained.
- Process:  
- Design the ZigBee content (e.g. 0000...00) to be sent in generate_mac function in gr-ieee802-15-4/lib/mac.cc.  
- Run the transmission link in the gr-ieee802-15-4/example/transceiver_OQPSK.grc to obtain the corresponding ZigBee signal (e.g. zigbee0).  (At this time, some detail of the PHY layer need to be modified: The repeat_interpolation is set to 20, the vector source is set to [0, sin(pi/20), ...] and the delay is set to 10.)  
- The ZigBee signal is used as the input of webee.grc to obtain the corresponding output (e.g. zigbee0_afterwebee), which is further modified by the addzero.cpp to get the WiFi payload (e.g. zigbee0_add).  
- The sender runs the gr-ieee802-11/example/wifi_tx_for_webee.grc and the WiFi payload is used as the input of gr-ieee802-11/example/wifi_tx_for_webee.grc. (At this time, the manual76to7 module in the PHY layer should be disabled.)  
- The receiver runs the receiver link in gr-ieee802-15-4/example/transceiver_OQPSK.grc to decode the transmission signal. (At this time, some detail of the PHY layer need to be modified: The repeat_interpolation is set to 4, the vector source is set to [0, sin(pi/4), ...] and the delay is set to 2.)