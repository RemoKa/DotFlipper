# DotFlipper
Driver Board for Flip Dot Matrices using the brand new Infineon TLE94112ES, 12 Channel Half Bridge driver ICs, to minimize the BOM length


## TLE94112ES Library
This basic Library contains a Header File, which defines all the necessary register adresses and Bitmasks, as well as a Message struct,
consiting of a register adress, the data and a read/write/clear bit.
The .c File contains the function 'TLE94112ES_ConstructTXBuffer', which accepts an Array of Messages and Coinstructs the correct byte order for daisy Chain operation of Arbitrary length 
