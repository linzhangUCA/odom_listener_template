from time import sleep                                                          
from gpiozero import LED, PhaseEnableRobot                                                 
import serial                                                                   

from geometry_msgs.msg import Twist

# init motor                                                                    
# en_left = LED()                                                               
# en_right = LED()                                                              
# bot = PhaseEnableRobot((, ), (, ))                                                     
                                                                                 
# init serial comm                                                              
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)                            
ser.reset_input_buffer()                                                        
try:                                                                            
#   en_left.on()                                                                
#   en_right.on()                                                               
#   bot.forward(.5)                                                               
#   print("forward")                                                            
  while True:                                                                 
    if ser.in_waiting > 0:                                                  
      line = ser.readline()                                               
      speeds = line.decode('utf-8').rstrip()
      # print(f'speeds: {speeds}')
      """
      Write your code down here.
      """                                                                        
 except KeyboardInterrupt:                                                       
     # bot.stop()                                                                    
     # en_left.off()                                                               
     # en_right.off()                                                              
     print("robot stopped")                                                      

# bot.stop()                                                                        
# en_left.off()                                                                   
# en_right.off()                                                                  
print("robot stopped")
