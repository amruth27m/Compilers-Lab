 0
 2056
 0
 0
 0
 0
 0
 0
 MOV SP, 4122
MOV R0, 4096
MOV R1, "Read"
PUSH R1
MOV R1, -1
PUSH R1
PUSH R0
PUSH R0
PUSH R0
CALL 0
MOV R0, 4097
MOV R1, "Read"
PUSH R1
MOV R1, -1
PUSH R1
PUSH R0
PUSH R0
PUSH R0
CALL 0
MOV R0, 4099
MOV R1, "Read"
PUSH R1
MOV R1, -1
PUSH R1
PUSH R0
PUSH R0
PUSH R0
CALL 0
MOV R0, [4096]
MOV R1, 0
GT R0, R1
JZ R0, 2198
MOV R1, [4097]
MOV R2, 0
GT R1, R2
JZ R1, 2188
MOV R2, [4099]
MOV R3, 0
GT R2, R3
JZ R2, 2178
MOV R3, 4098
MOV R4, "Read"
PUSH R4
MOV R4, -1
PUSH R4
PUSH R3
PUSH R0
PUSH R0
CALL 0
MOV R3, [4098]
MOV R4, 0
EQ R3, R4
JZ R3, 2166
JMP 2178
JMP 2176
MOV R4, [4099]
MOV R5, 1
SUB R4, R5
MOV [4099], R4
JMP 2120
JMP 2128
MOV R5, [4097]
MOV R6, 1
SUB R5, R6
MOV [4097], R5
JMP 2120
MOV R6, [4096]
MOV R7, 1
SUB R6, R7
MOV [4096], R6
JMP 2112
MOV R1, "Exit"
PUSH R1
MOV R1, 0
PUSH R1
PUSH R0
PUSH R0
PUSH R0
CALL 0
