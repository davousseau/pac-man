; Filename: linux.inc
; Description: Linux's logo shifting file
; Author: David Brousseau

    JSR setLinuxTowardTo
    JMP endLinuxShifting

; Set Linux's logo direction toward to
setLinuxTowardTo:
; Linux toward up
    LDA linuxDirection
    CMP #1
    BNE linuxTowardDown
    JSR shiftLinuxUp
    JMP endLinuxTowardTo

linuxTowardDown:
    LDA linuxDirection
    CMP #2
    BNE linuxTowardLeft
    JSR shiftLinuxDown
    JMP endLinuxTowardTo

linuxTowardLeft:
    LDA linuxDirection
    CMP #3
    BNE linuxTowardRight
    JSR shiftLinuxLeft
    JMP endLinuxTowardTo

linuxTowardRight:
    LDA linuxDirection
    CMP #4
    BNE endLinuxTowardTo
    JSR shiftLinuxRight

endLinuxTowardTo:
    RTS

; Apply shifting toward up to Linux's logo
shiftLinuxUp:
    LDA $220
    SEC
    SBC #1
    STA $220
    LDA $224
    SEC
    SBC #1
    STA $224
    LDA $228
    SEC
    SBC #1
    STA $228
    LDA $22C
    SEC
    SBC #1
    STA $22C
    RTS

; Apply shifting toward down to Linux's logo
shiftLinuxDown:
    LDA $220
    CLC
    ADC #1
    STA $220
    LDA $224
    CLC
    ADC #1
    STA $224
    LDA $228
    CLC
    ADC #1
    STA $228
    LDA $22C
    CLC
    ADC #1
    STA $22C
    RTS

; Apply shifting toward left to Linux's logo
shiftLinuxLeft:
    LDA $223
    SEC
    SBC #1
    STA $223
    LDA $227
    SEC
    SBC #1
    STA $227
    LDA $22B
    SEC
    SBC #1
    STA $22B
    LDA $22F
    SEC
    SBC #1
    STA $22F
    RTS

; Apply shifting toward right to Linux's logo
shiftLinuxRight:
    LDA $223
    CLC
    ADC #1
    STA $223
    LDA $227
    CLC
    ADC #1
    STA $227
    LDA $22B
    CLC
    ADC #1
    STA $22B
    LDA $22F
    CLC
    ADC #1
    STA $22F
    RTS

endLinuxShifting:
