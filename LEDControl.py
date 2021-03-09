import serial
import curses
import time

# Get the curses window, turn off echoing of keyboard to screen, turn on
# instant (no waiting) key response, and use special values for cursor keys
screen = curses.initscr()
curses.noecho() 
curses.cbreak()
screen.keypad(True)

# Setup Serial communication
if __name__ == '__main__':
# USB number might be different
# Find out how to know the UART address
    ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1) 
    ser.flush()

try:
        while True:   
            char = screen.getch()
            if char == ord('q'):
                break
            elif char == ord('1'):
                print "Toggle LED 1" # Write in RPi
                ser.write(b"1\n") # Write in Arduino
            elif char == ord('2'):
                print "Toggle LED 2"
                ser.write(b"2\n")
            elif char == ord('3'):
                print "Toggle LED 3"
                ser.write(b"3\n")             
finally:
    #Close down curses properly, inc turn echo back on!
    curses.nocbreak(); screen.keypad(0); curses.echo()
    curses.endwin()
