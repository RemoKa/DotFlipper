# DotFlipper
Driver Board for Flip Dot Matrices using the brand new Infineon TLE94112ES, 12 Channel Half Bridge driver ICs, to minimize the BOM length


## TLE94112ES Library
This basic Library contains a Header File, which defines all the necessary register adresses and Bitmasks, as well as a Message struct,
consiting of a register adress, the data and a read/write/clear bit.
The .c File contains the function `TLE94112ES_ConstructTXBuffer`, which accepts an array of Messages to construct the correct byte order in the TXbuffer for daisy chain operation of arbitrary length 



```
 
                                         ┌────────────┐                    ┌───────────┐
                                         │            │                    │           │
                                         │    NES     │ SPI Unidirectional │           │
                                         │  Gamepad   ├──────────────────► │           │
                                         │            │                    │           │
                                         └────────────┘                    │           │
                                                                           │           │
                                                                           │           │
                         ┌─────┐    ┌─────┐    ┌─────┐                     │           │ 
                         │ TLE │    │ TLE │    │ TLE │  SPI Bidirectional  │           │
                         │     │◄───┤     │◄───┤     │◄────────────────────┤   STM32   │
                         │ C2  │    │ C1  │    │ C0  │    Daisy Chain      │           │
                         └──┬──┘    └─────┘    └─────┘                     │           │
                            │                                              │           │
                            ▼          ┌──────────────────────────────────►│           │
                         ┌─────┐       │                                   │           │
                         │ TLE │       │                                   └───────────┘
                         │     │       │
                         │ R0  │       │
                         └──┬──┘       │
                            │          │
                            │          │
                            ▼          │
                         ┌─────┐       │
                         │ TLE │       │
                         │     ├───────┘
                         │ R0  │
                         └─────┘

```

| BL9326 |        |  | NC | C29 | C28 | C27 | C26 | C25 | C24 |     | C22 | C21 | C20 | C19 | C18 | C17 | C16 |     | C14 | C13 | C12 | C11 | C10 | C9 | C8 |    | C6 | C5 | C4 | C3 | C2 | C1 | C0 |  |        |        |
| ------ | ------ | - | -- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | - | ------ | ------ |
|        |        |  | NC | C29 | C28 | C27 | C26 | C25 | C24 |     | C22 | C21 | C20 | C19 | C18 | C17 | C16 |     | C14 | C13 | C12 | C11 | C10 | C9 | C8 |    | C6 | C5 | C4 | C3 | C2 | C1 | C0 |  |        |        |
| (L-1H) | (L-1L) |  |    |     |     |     |     |     |     | C23 |     |     |     |     |     |     |     | C15 |     |     |     |     |     |    |    | C7 |    |    |    |    |    |    |    |  | (L-1H) | (L-1L) |
| L0H    | L0L    |  |    |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |    |    |    |    |    |    |    |    |    |    |  | L0H    | L0L    |
| L1H    | L1L    |  |    |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |    |    |    |    |    |    |    |    |    |    |  | L1H    | L1L    |
| L2H    | L2L    |  |    |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |    |    |    |    |    |    |    |    |    |    |  | L2H    | L2L    |
| L3H    | L3L    |  |    |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |    |    |    |    |    |    |    |    |    |    |  | L3H    | L3L    |
| L4H    | L4L    |  |    |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |    |    |    |    |    |    |    |    |    |    |  | L4H    | L4L    |
| L5H    | L5L    |  |    |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |    |    |    |    |    |    |    |    |    |    |  | L5H    | L5L    |
|        |        |  |    |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |    |    |    |    |    |    |    |    |    |    |  |        |        |
| L6H    | L6L    |  |    |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |    |    |    |    |    |    |    |    |    |    |  | L6H    | L6L    |
| L7H    | L7L    |  |    |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |    |    |    |    |    |    |    |    |    |    |  | L7H    | L7L    |
| L8H    | L8L    |  |    |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |    |    |    |    |    |    |    |    |    |    |  | L8H    | L8L    |
| L9H    | L9L    |  |    |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |    |    |    |    |    |    |    |    |    |    |  | L9H    | L9L    |
| L10H   | L10L   |  |    |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |    |    |    |    |    |    |    |    |    |    |  | L10H   | L10L   |
| L11H   | L11L   |  |    |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |    |    |    |    |    |    |    |    |    |    |  | L11H   | L11L   |
| (L12H) | (L12L) |  |    |     |     |     |     |     |     | C23 |     |     |     |     |     |     |     | C15 |     |     |     |     |     |    |    | C7 |    |    |    |    |    |    |    |  | (L12H) | (L12L) |
|        |        |  | NC | C29 | C28 | C27 | C26 | C25 | C24 |     | C22 | C21 | C20 | C19 | C18 | C17 | C16 |     | C14 | C13 | C12 | C11 | C10 | C9 | C8 |    | C6 | C5 | C4 | C3 | C2 | C1 | C0 |  |        |        |
|        |        |  | NC | C29 | C28 | C27 | C26 | C25 | C24 |     | C22 | C21 | C20 | C19 | C18 | C17 | C16 |     | C14 | C13 | C12 | C11 | C10 | C9 | C8 |    | C6 | C5 | C4 | C3 | C2 | C1 | C0 |  |        |        |
