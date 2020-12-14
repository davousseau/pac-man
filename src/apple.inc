; Filename: apple.inc
; Description: Apple's logo shifting file
; Author: David Brousseau

    JSR setAppleTowardTo
    JMP endAppleShifting

; Set Apple's logo direction toward to
setAppleTowardTo:
; Apple toward up
    LDA appleDirection
    CMP #1
    BNE appleTowardDown
    JSR shiftAppleUp
    JMP endAppleTowardTo

appleTowardDown:
    LDA appleDirection
    CMP #2
    BNE appleTowardLeft
    JSR shiftAppleDown
    JMP endAppleTowardTo

appleTowardLeft:
    LDA appleDirection
    CMP #3
    BNE appleTowardRight
    JSR shiftAppleLeft
    JMP endAppleTowardTo

appleTowardRight:
    LDA appleDirection
    CMP #4
    BNE endAppleTowardTo
    JSR shiftAppleRight

endAppleTowardTo:
    RTS

; Apply shifting toward up to Apple's logo
shiftAppleUp:
    LDA $230
    SEC
    SBC #1
    STA $230
    LDA $234
    SEC
    SBC #1
    STA $234
    LDA $238
    SEC
    SBC #1
    STA $238
    LDA $23C
    SEC
    SBC #1
    STA $23C
    RTS

; Apply shifting toward down to Apple's logo
shiftAppleDown:
    LDA $230
    CLC
    ADC #1
    STA $230
    LDA $234
    CLC
    ADC #1
    STA $234
    LDA $238
    CLC
    ADC #1
    STA $238
    LDA $23C
    CLC
    ADC #1
    STA $23C
    RTS

; Apply shifting toward left to Apple's logo
shiftAppleLeft:
    LDA $233
    SEC
    SBC #1
    STA $233
    LDA $237
    SEC
    SBC #1
    STA $237
    LDA $23B
    SEC
    SBC #1
    STA $23B
    LDA $23F
    SEC
    SBC #1
    STA $23F
    RTS

; Apply shifting toward right to Apple's logo
shiftAppleRight:
    LDA $233
    CLC
    ADC #1
    STA $233
    LDA $237
    CLC
    ADC #1
    STA $237
    LDA $23B
    CLC
    ADC #1
    STA $23B
    LDA $23F
    CLC
    ADC #1
    STA $23F
    RTS

endAppleShifting:
