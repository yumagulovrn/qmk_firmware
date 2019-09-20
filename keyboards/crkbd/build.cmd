set path=C:\SDK\WinAVR-20100110\bin;%path%

cd %~dp0\..\..

set keymap=jorne

bash -c "make crkbd:%keymap%" || exit

timeout 3

avrdude -p atmega32u4 -P COM11 -c avr109  -e -U flash:w:crkbd_rev1_%keymap%.hex
